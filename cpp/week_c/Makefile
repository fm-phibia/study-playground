# Makefile

# ターゲットディレクトリを指定（デフォルトはカレントディレクトリ）
TARGET_DIR ?= ./*

# ターゲットディレクトリ内のmain.cをターゲットに設定
TARGET = $(TARGET_DIR)/main.c

# ターゲットディレクトリ内の*.cファイル（main.c以外も含む）
SOURCES = $(wildcard $(TARGET_DIR)/*.c)

# すべての*.cファイルをオブジェクトファイルに変換
OBJS = $(SOURCES:.c=.o)

# コンパイラとフラグ
CC = gcc
CFLAGS = -Wall -I$(TARGET_DIR)

# デフォルトのビルドルール
all: $(TARGET_DIR)/main

# オブジェクトファイルを生成
$(TARGET_DIR)/%.o: $(TARGET_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 実行ファイルを生成
$(TARGET_DIR)/main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# クリーンアップ
clean:
	rm -f $(TARGET_DIR)/*.o $(TARGET_DIR)/main

.PHONY: all clean
