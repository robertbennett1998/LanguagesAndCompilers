all : lexer parser tree compiler

flex :
	flex -o ./src/lex.yy.c ./src/spl.l

lexer : lexer-clean flex
	gcc -o ./bin/lexer.exe -DPRINT -UYY_MAIN ./src/lex.yy.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

bison : bison-clean flex
	bison -v ./src/spl.y -o ./src/spl_t.c

parser : parser-clean bison flex
	gcc -o ./bin/parser.exe -DYYDEBUG -UYY_MAIN ./src/spl.c ./src/spl_t.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

tree : tree-clean flex bison
	gcc -o ./bin/tree.exe -DDEBUG -UYY_MAIN ./src/spl.c ./src/spl_t.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

compiler : compiler-clean flex bison
	gcc -o ./bin/compiler.exe ./src/spl.c ./src/spl_t.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

compiler-pedantic : compiler-clean flex bison
	gcc -o ./bin/compiler.exe ./src/spl.c ./src/spl_t.c -lfl -Wall -Wextra -Wpedantic -ansi -D__MINGW_FEATURES -Wno-cpp

test : clean
	./RunCompiler.bat

clean : lexer-clean bison-clean parser-clean tree-clean compiler-clean

lexer-clean :
	rm -f ./bin/lexer.exe
	rm -f ./src/lex.yy.c

bison-clean :
	rm -f ./src/spl_t.output

parser-clean :
	rm -f ./bin/parser.exe
	rm -f ./src/spl_t.c

tree-clean :
	rm -f ./bin/tree.exe

compiler-clean :
	rm -f ./bin/compiler.exe