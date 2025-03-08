import datetime
import glob
import os
import re
from langchain.document_loaders import UnstructuredPDFLoader, UnstructuredPowerPointLoader, UnstructuredURLLoader, csv_loader, UnstructuredHTMLLoader
from langchain.document_loaders.text import TextLoader
from langchain.document_loaders.unstructured import UnstructuredBaseLoader
from langchain.embeddings import OpenAIEmbeddings
from langchain.text_splitter import RecursiveCharacterTextSplitter
from langchain.vectorstores.faiss import FAISS
from transformers import AutoTokenizer
from dotenv import load_dotenv

load_dotenv()
# TODO: 適宜モデル名を変更する
output_model_name = 'new_model'

# 学習させるドキュメントの格納先
DOCS_DIR = 'input'
# CHUNK_SIZE: 1つの文書を分割する際の文字数
CHUNK_SIZE = 800
# CHUNK_OVERLAP: 2つの文書を分割する際の重複する文字数
CHUNK_OVERLAP = 200
URL_PATTERN = 'https?://[\w/:%#\$&\?\(\)~\.=\+\-]+'

tools = []
files = glob.glob(DOCS_DIR + '/*')
embeddings = OpenAIEmbeddings()
text_splitter = RecursiveCharacterTextSplitter(
    chunk_size=CHUNK_SIZE,
    chunk_overlap=CHUNK_OVERLAP,
)

def create_model():
    '''
    モデルを作成する
    '''
    d = load_documents(files)
    documents = text_splitter.split_documents(d)

    model = FAISS.from_documents(documents, embeddings)
    dt_now = datetime.datetime.now(
        datetime.timezone(datetime.timedelta(hours=9))
    )
    dt_str = dt_now.strftime('%Y%m%d%H%M%S')
    # ローカルにモデルを保存する
    model.save_local(f'output/{dt_str}_{output_model_name}')

def load_documents(files):
    l = []
    for f in files:
        ext = f.split('.')[-1]
        if ext == 'pdf':
            loader = UnstructuredPDFLoader(f)
        elif ext == 'csv':
            loader = csv_loader.CSVLoader(f)
        elif ext == 'pptx':
            loader = UnstructuredPowerPointLoader(f)
        elif ext == 'txt':
            loader = TextLoader(f)
        elif ext == 'html':
            loader = UnstructuredHTMLLoader(f)
        else:
            file_name = os.path.splitext(os.path.basename(f))[0]
            if file_name == 'urls':
                file = open(f, 'r')
                lines = file.readlines()
                line_arr = []
                for line in lines:
                    line = line.replace('\n', '')
                    if re.match(URL_PATTERN, line):
                        line_arr.append(line)
                loader = UnstructuredURLLoader(line_arr)
            else:
                continue
        l.extend(loader.load())
    return l

create_model()