# CC=gcc
# CFLAGS=-g -Wall
# OBJS=helper.o
# EXE=write.elf read.elf

# all: $(EXE)

# %.elf: %.o $(OBJS)
# 	$(CC) $(CFLAGS) $< $(OBJS) -o $@

# %.o: %.c %.h
# 	$(CC) $(CFLAGS) $< -o $@

# %.o: %.c
# 	$(CC) $(CFLAGS) $< -o $@

# clean:
# 	rm -rf *.dSYM *.o $(EXE)
CC = gcc
CFLAGS = -g -Wall
EXE = write read

all: $(EXE)

write: write.o helper.o
	$(CC) $(CFLAGS) write.o helper.o -o write
read: read.o helper.o
	$(CC) $(CFLAGS) read.o helper.o -o read
read.o:
	$(CC) $(CFLAGS) -c read.c helper.h
write.o: write.c helper.h
	$(CC) $(CFLAGS) -c write.c helper.h
helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c helper.h

clean:
	rm -rf *.dSYM *.o $(EXE) *.h.gch