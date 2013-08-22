all:
	gcc -Wall -c *.c
	gcc *.o -o mipsy

clean:
	rm *.o mipsy

