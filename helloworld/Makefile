CC = gcc

BINDIR = bin
SRCDIR = src

# wildcard関数で SRCDIR以下のcファイルをリスト
SRCS = $(wildcard $(SRCDIR)/*.c)
# SRCSの拡張子を置き換える
OBJS = $(SRCS:%.c=%.o)


TARGET = $(BINDIR)/helloworld1
TARGET2 = $(BINDIR)/calc_magicnumber

all: $(TARGET) $(TARGET2)

$(TARGET): $(SRCDIR)/helloworld1.c
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(TARGET2): $(SRCDIR)/calc_magicnumber.c
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~ *~
clean: tmpclean
	rm -f $(TARGET) $(TARGET2) $(OBJS)
