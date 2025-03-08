import sys
import os
from langchain.chains.llm import LLMChain
from langchain.callbacks.base import CallbackManager
from langchain.callbacks.streaming_stdout import StreamingStdOutCallbackHandler
from langchain.chains.chat_vector_db.prompts import CONDENSE_QUESTION_PROMPT, QA_PROMPT
from langchain.chains.question_answering import load_qa_chain
from langchain.chains import ConversationalRetrievalChain
from langchain.chat_models import ChatOpenAI
from langchain.embeddings import OpenAIEmbeddings
from langchain.vectorstores.faiss import FAISS
from dotenv import load_dotenv

# TODO: チャットボットの元になるシステム名
sys_name = 'hogehoge'
# TODO:　outputディレクトリ内のモデル名
model = '20230430112711_new_model'

TEMPERATURE = 0
VERBOSE_FLG = True


load_dotenv()
args = sys.argv
if len(args) < 2:
  print("Usage: python use_model.py <question>")
  exit(1)

prompt = args[1]prompt = f'''
あなたは{sys_name}のチャットボットです。
次の質問に120文字以内で日本語で回答してください。

### 質問 ###
{prompt}
'''

embeddings = OpenAIEmbeddings()
v_store = FAISS.load_local('output/' + model, embeddings)
manager = CallbackManager([StreamingStdOutCallbackHandler()])

streaming_llm = ChatOpenAI(
    callback_manager=manager,
    streaming=True,
    temperature=TEMPERATURE,
    verbose=VERBOSE_FLG,
)
question_gen_llm = ChatOpenAI(
    callback_manager=manager,
    temperature=TEMPERATURE,
    verbose=VERBOSE_FLG,
)
question_generator = LLMChain(
    llm=question_gen_llm,
    prompt=CONDENSE_QUESTION_PROMPT,
)
doc_chain = load_qa_chain(
    streaming_llm,
    chain_type='stuff',
    prompt=QA_PROMPT,
)
# 埋め込みモデルからプロンプト生成
qa = ConversationalRetrievalChain(
    combine_docs_chain=doc_chain,
    question_generator=question_generator, r
    etriever=v_store.as_retriever(),
)

qa({'question': prompt, 'chat_history': []})