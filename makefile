all: byteRandom.o
	gcc -o program byteRandom.o

byteRandom.o: byteRandom.c
	gcc -c byteRandom.c

run:
	./program

clean:
	rm *.o
	rm *.exe
	rm output.txt
