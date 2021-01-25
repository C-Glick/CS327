CC = gcc
ARGS = -g

all: partc

partc: partCMain.o gensnd.o iosnd.o process.o DLL.o
	$(CC) partCMain.o gensnd.o iosnd.o process.o DLL.o $(ARGS) -lm -o playsong


partCMain.o: partCMain.c 
	$(CC) $(ARGS) -c partCMain.c

iosnd.o: iosnd.c 
	$(CC) $(ARGS) -c iosnd.c

process.o: process.c 
	$(CC) $(ARGS) -c process.c

DLL.o: DLL.c 
	$(CC) $(ARGS) -c DLL.c

#part b ---------------------------------------------------------------------------

partb: dtmf

dtmf: main1b.o gensnd.o
	$(CC) main1b.o gensnd.o $(ARGS) -lm -o dtmf

main1b.o: main1b.c
	$(CC) $(ARGS) -c main1b.c

#common ---------------------------------------------------------------------------

gensnd.o: gensnd.c gensnd.h sound.h
	$(CC) $(ARGS) -c gensnd.c

#forcefully (and silently) remove all generated files
clean:
	rm -f *.o gensine gendial dtmf playsong