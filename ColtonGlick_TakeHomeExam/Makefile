CC = g++
ARGS = -g

candy: Main.o Candy.o HardCandy.o JellyCandy.o CaramelCandy.o ChocolateCandy.o
	$(CC) Main.o Candy.o HardCandy.o JellyCandy.o CaramelCandy.o ChocolateCandy.o $(ARGS) -o candy

Main.o: Main.cpp
	$(CC) $(ARGS) -c Main.cpp

Candy.o: Candy.cpp Candy.h
	$(CC) $(ARGS) -c Candy.cpp

HardCandy.o: HardCandy.cpp HardCandy.h
	$(CC) $(ARGS) -c HardCandy.cpp

JellyCandy.o: JellyCandy.cpp JellyCandy.h
	$(CC) $(ARGS) -c JellyCandy.cpp

CaramelCandy.o: CaramelCandy.cpp CaramelCandy.h
	$(CC) $(ARGS) -c CaramelCandy.cpp

ChocolateCandy.o: ChocolateCandy.cpp ChocolateCandy.h
	$(CC) $(ARGS) -c ChocolateCandy.cpp

#forcefully (and silently) remove all generated files
clean:
	rm -f *.o candy