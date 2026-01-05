CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
all			:
				writer
writer		: 	writer.o
				$(CC) -o writer writer.o
writer.o	:	writer.c
				$(CC) -c writer.c
clean		:
				rm -rf writer.o writer
