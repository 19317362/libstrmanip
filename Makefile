CC=g++ -g3 -ansi -Wall
OBJ=utils.o

all: lib


lib: $(OBJ)
	ar rs libstrmanip++.a $(OBJ)

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f *~

mrproper: clean
	rm libstrmanip++.a

install: lib
	install -D -m 666 *.a /usr/local/lib
	install -D -m 666 utils.h /usr/local/include/libstrmanip++/utils.h

