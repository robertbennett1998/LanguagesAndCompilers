arithm-64 : arithm-64.o
	gcc -o arith bin64/linux/intimediate/arith.o bin64/linux/intimediate/arith.tab.o -m64 -lfl
	mkdir -p bin64/linux
	mv arith bin64/linux

arithm-64.o : bison
	gcc -c -m64 arith.c arith.tab.c
	rm -rf bin64/linux/intimediate
	mkdir -p bin64/linux/intimediate
	mv *.o bin64/linux/intimediate

arithm-win64 : arithm-win64.o
	x86_64-w64-mingw32-gcc -o arith.exe bin64/windows/intimediate/arith.o bin64/windows/intimediate/arith.tab.o -m64 -static
	rm -rf bin64/windows/intimediate
	mkdir -p bin64/windows/intimediate
	mv arith.exe bin64/windows

arithm-win64.o : bison
	x86_64-w64-mingw32-gcc -c arith.c arith.tab.c -m64
	rm -rf bin64/windows/intimediate
	mkdir -p bin64/windows/intimediate
	mv *.o bin64/windows/intimediate

flex :
	flex arith.l

bison : flex
	bison arith.y

all : arithm-64 arithm-win64 

clean :
	rm -rf intimediate
	rm -rf bin64

rebuild : clean arithm-64

rebuild-all : clean all

