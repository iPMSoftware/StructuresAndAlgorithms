CC = gcc
LIB_STATIC = ./lib_static
LIB_SHARED = ./lib_shared

build:
	mkdir -p out
	${CC} -g -c main.c -o out/main.o

	
	${CC} -g -c vector/vector.c -o out/vector.o
	${CC} out/main.o out/vector.o -lcmocka -o out/main.out
clean:
	rm -rfv out
	rm -rfv ${LIB_SHARED}
	rm -rfv ${LIB_STATIC}

lib_static:
	mkdir -p ${LIB_STATIC}
	${CC} -c vector/vector.c -o ${LIB_STATIC}/vector.out
	ar crs ${LIB_STATIC}/libvector.a ${LIB_STATIC}/vector.out
	${CC} -c vector_test.c -o ${LIB_STATIC}/main.o
	${CC} ${LIB_STATIC}/main.o -L./${LIB_STATIC} -lvector -o ${LIB_STATIC}/main.out

lib_shared:
	mkdir -p ${LIB_SHARED}
	${CC} -c vector/vector.c -fPIC -o ${LIB_SHARED}/vector.o
	${CC} -shared ${LIB_SHARED}/vector.o -o ${LIB_SHARED}/libvector.so

	${CC} -c vector_test.c -o ${LIB_SHARED}/main.o
	${CC} ${LIB_SHARED}/main.o -L./${LIB_SHARED} -lvector -o ${LIB_SHARED}/main.out