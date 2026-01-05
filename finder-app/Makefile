CROSS_COMPILE ?=

CXX = $(CROSS_COMPILE)gcc
writer		: 	writer.o
				$(CXX) -o writer writer.o
writer.o	:	writer.c
				$(CXX) -c writer.c
clean		:
				rm -rf writer.o writer
