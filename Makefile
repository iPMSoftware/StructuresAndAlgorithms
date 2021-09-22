build:
	mkdir -p out
	gcc -g -c main.c -o out/main.o

	
	gcc -g -c vector/vector.c -o out/vector.o
	gcc out/main.o out/vector.o -lcmocka -o out/main.out
clean:
	rm -rfv out
	rm -rfv lib_shared
	rm -rfv lib_static

lib_static:
	mkdir -p lib_static
	gcc -c vector/vector.c -o lib_static/vector.out
	ar crs lib_static/libvector.a lib_static/vector.out
	gcc -c vector_test.c -o lib_static/main.o
	gcc lib_static/main.o -L./lib_static -lvector -o lib_static/main.out

lib_shared:
	mkdir -p lib_shared
	gcc -c vector/vector.c -fPIC -o lib_shared/vector.o
	gcc -shared lib_shared/vector.o -o lib_shared/libvector.so

	gcc -c vector_test.c -o lib_shared/main.o
	gcc lib_shared/main.o -L./lib_shared -lvector -o lib_shared/main.out