all : lexer parser tree compiler

flex :
	flex spl.l

lexer : lexer-clean flex
	gcc -o lexer.exe -DPRINT -UYY_MAIN lex.yy.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

bison : bison-clean flex
	bison -t -v spl.y -o spl_t.c

parser : parser-clean bison flex
	gcc -o parser.exe -DYYDEBUG -UYY_MAIN spl.c spl_t.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

tree : tree-clean flex bison
	gcc -o tree.exe -DDEBUG -UYY_MAIN spl.c spl_t.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

compiler : compiler-clean flex bison
	gcc -o compiler.exe spl.c spl_t.c -lfl -ansi -D__MINGW_FEATURES -Wno-cpp

test : clean
	./RunCompiler.bat

clean : lexer-clean bison-clean parser-clean tree-clean compiler-clean

lexer-clean :
	rm -f lexer.exe
	rm -f lex.yy.c

bison-clean :
	rm -f spl_t.output

parser-clean :
	rm -f parser.exe
	rm -f spl_t.c

tree-clean :
	rm -f tree.exe

compiler-clean :
	rm -f compiler.exe