SOURCES = $(wildcard src/*.c)

OBJLIB = libtadts.a

default: buildtest

buildlib:
	mkdir build
	gcc -std=c99 -Iinclude -pedantic -g -O -Wall -c $(SOURCES)
	mv *.o build/
	mkdir dist
	ar -cvq dist/$(OBJLIB) build/*.o

buildtest: buildlib
	gcc -std=c99 -Iinclude -o build/TestList test/TestList.c dist/$(OBJLIB)
	gcc -std=c99 -Iinclude -o build/TestDict test/TestDict.c dist/$(OBJLIB)
	gcc -std=c99 -Iinclude -o build/TestGraph test/TestGraph.c dist/$(OBJLIB)

doc:
	doxygen config/aic.dox.cfg

clean:
	rm -rf build/ dist/ doc/
