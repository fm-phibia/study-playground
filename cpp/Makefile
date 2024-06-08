# コンパイラとフラグ
CC = gcc
CXX = g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g

# 全てのソースファイルを検索
C_SOURCES := $(shell find . -name '*.c')
CPP_SOURCES := $(shell find . -name '*.cpp')

# 各ソースファイルに対応するオブジェクトファイルと実行ファイル
C_OBJS := $(C_SOURCES:.c=.o)
CPP_OBJS := $(CPP_SOURCES:.cpp=.o)
EXE_FILES := $(C_SOURCES:.c=) $(CPP_SOURCES:.cpp=)

# ルール: all - 全てのファイルをコンパイル
all: $(EXE_FILES)

# ルール: target_dir - 指定されたディレクトリのファイルをコンパイル
target_dir:
	@read -p "Enter the target directory path: " DIR; \
	C_SOURCES := $$(find $$DIR -name '*.c'); \
	CPP_SOURCES := $$(find $$DIR -name '*.cpp'); \
	$(MAKE) $$(echo $$(basename $$(echo $$C_SOURCES $$CPP_SOURCES)))

# 個々のCファイルのコンパイルルール
%: %.c
	echo $<
	$(CC) $(CFLAGS) -o $@ $<

# 個々のC++ファイルのコンパイルルール
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# ディレクトリの指定
DIR_PATH =

# ターゲットの実行ファイル名
TARGET = $(notdir $(DIR_PATH))

# ターゲットディレクトリ内のソースファイル
SRC = $(wildcard $(DIR_PATH)/*.c)

# ターゲットディレクトリ内のオブジェクトファイル
OBJ = $(patsubst %.c,%.o,$(SRC))

# 指定されたディレクトリのファイルをコンパイル
target: $(DIR_PATH)/$(TARGET)

# 実行ファイルを生成
$(DIR_PATH)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# .c から .o を生成
$(DIR_PATH)/%.o: $(DIR_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ルール: clean - 生成されたファイルを削除
clean:
	rm -f $(C_OBJS) $(CPP_OBJS) $(EXE_FILES)
