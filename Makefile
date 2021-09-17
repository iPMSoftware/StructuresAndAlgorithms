build:
	mkdir -p out
	gcc -g -c main.c -o out/main.o

	
	gcc -g -c vector/vector.c -o out/vector.o
	gcc out/main.o out/vector.o -lcmocka -o out/main.out
clean:
	rm -rfv out