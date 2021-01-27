CC = g++
ARGS = -g

all: partA partB

#part A ---------------------------------------------------------------------------

partA: main.o soundio.o SoundSamples.o wave.o SineWave.o SquareWave.o TriangleWave.o SawtoothWave.o
	$(CC) main.o soundio.o SoundSamples.o wave.o SineWave.o SquareWave.o TriangleWave.o SawtoothWave.o $(ARGS) -lm -o partA

main.o: main.cpp
	$(CC) $(ARGS) -c main.cpp

#part B------------------------------------------------------------------------
partB: TestMain.o soundio.o SoundSamples.o wave.o SineWave.o SquareWave.o TriangleWave.o SawtoothWave.o
	$(CC) TestMain.o soundio.o SoundSamples.o wave.o SineWave.o SquareWave.o TriangleWave.o SawtoothWave.o $(ARGS) -lm -o partB

TestMain.o: TestMain.cpp
	$(CC) $(ARGS) -c TestMain.cpp
#common ---------------------------------------------------------------------------

SoundSamples.o: SoundSamples.cpp
	$(CC) $(ARGS) -c SoundSamples.cpp

wave.o: wave.cpp
	$(CC) $(ARGS) -c wave.cpp

SineWave.o: SineWave.cpp
	$(CC) $(ARGS) -c SineWave.cpp

SquareWave.o: SquareWave.cpp
	$(CC) $(ARGS) -c SquareWave.cpp

TriangleWave.o: TriangleWave.cpp
	$(CC) $(ARGS) -c TriangleWave.cpp

SawtoothWave.o: SawtoothWave.cpp
	$(CC) $(ARGS) -c SawtoothWave.cpp

soundio.o: soundio.cpp
	$(CC) $(ARGS) -c soundio.cpp

#forcefully (and silently) remove all generated files
clean:
	rm -f *.o partA partB
