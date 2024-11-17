# コンパイル先のディレクトリ
BUILD_DIR=build

# ソースファイルのパターン（カレントディレクトリ内のすべてのJavaファイル）
SOURCES=$(wildcard *.java)

# コンパイル先のクラスファイルのパスを生成
CLASSES=$(patsubst %.java, $(BUILD_DIR)/%.class, $(SOURCES))

# デフォルトターゲット
all: $(BUILD_DIR) $(CLASSES) run

# $(BUILD_DIR)ディレクトリが存在しない場合は作成
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Javaファイルを$(BUILD_DIR)内にコンパイル
$(BUILD_DIR)/%.class: %.java
	javac -d $(BUILD_DIR) $<

# コンパイル後にMainクラスを実行
run:
	java -cp $(BUILD_DIR) Main

# クリーンターゲット
clean:
	rm -rf $(BUILD_DIR)/*.class
