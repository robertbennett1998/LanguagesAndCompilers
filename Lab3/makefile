PREPROCESSOR_DEFINES +=  PRINT
PREPROCESSOR_DEFINES += YYDEBUG
PREPROCESSOR_DEFINES += LVERBOSE
PREPROCESSOR_DEFINES += RUN_ALL_TESTS
INCLUDE_PATHS = intimidiate/

SOURCE_DIR = src
_SOURCE_DIR = ..
INTIMIDIATE_DIR = intimidiate
_INTIMIDIATE_DIR = ..
BIN_DIR_ROOT = bin
_BIN_DIR_ROOT = ..
BIN_DIR_LINUX = $(BIN_DIR_ROOT)/linux
_BIN_DIR_LINUX = $(_BIN_DIR_ROOT)/..
BIN_DIR_WINDOWS = $(BIN_DIR_ROOT)/windows
_BIN_DIR_WINDOWS = $(_BIN_DIR_ROOT)/..
TESTS_DIR = tests/

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.c)
ADDITIONAL_SOURCE_FILES =  $(wildcard $(INTIMIDIATE_DIR)/*.tab.c)
FLEX_FILES = $(wildcard $(SOURCE_DIR)/*.l)
YACC_FILES = $(wildcard $(SOURCE_DIR)/*.y)

all : linux windows

linux : compile-linux
	$(eval obj_files = $(shell find $(INTIMIDIATE_DIR)/ -maxdepth 1 -type f -regex ".*\.o"))
	$(eval obj_files = $(addprefix $(_INTIMIDIATE_DIR)/, $(obj_files)))
	cp -r $(TESTS_DIR) bin/linux/
	cd $(INTIMIDIATE_DIR);\
	gcc -o $(_INTIMIDIATE_DIR)/$(BIN_DIR_LINUX)/spl $(obj_files) -m64 -lfl

compile-linux : bison
	$(eval preprocessor_defs = $(addprefix -D, $(PREPROCESSOR_DEFINES)))
	$(eval include_paths = $(addprefix -I$(_INTIMIDIATE_DIR)/, $(INCLUDE_PATHS)))
	$(eval src = $(shell find $(SOURCE_DIR)/ -maxdepth 1 -type f -regex ".*\.c"))
	$(eval src += $(shell find $(INTIMIDIATE_DIR)/ -maxdepth 1 -type f -regex ".*\.tab.c"))
	$(eval src = $(addprefix $(_INTIMIDIATE_DIR)/, $(src)))
	cd $(INTIMIDIATE_DIR);\
	gcc -c $(src) $(preprocessor_defs) $(include_paths) -m64

windows : compile-windows
	$(eval obj_files = $(shell find $(INTIMIDIATE_DIR)/ -maxdepth 1 -type f -regex ".*\.o"))
	$(eval obj_files = $(addprefix $(_INTIMIDIATE_DIR)/, $(obj_files)))
	cp -r $(TESTS_DIR) bin/linux/
	cd $(INTIMIDIATE_DIR);\
	x86_64-w64-mingw32-gcc -o $(_INTIMIDIATE_DIR)/$(BIN_DIR_WINDOWS)/spl.exe $(obj_files) -m64 -static

compile-windows : bison
	$(eval preprocessor_defs = $(addprefix -D, $(PREPROCESSOR_DEFINES)))
	$(eval include_paths = $(addprefix -I$(_INTIMIDIATE_DIR)/, $(INCLUDE_PATHS)))
	$(eval src = $(shell find $(SOURCE_DIR)/ -maxdepth 1 -type f -regex ".*\.c"))
	$(eval src += $(shell find $(INTIMIDIATE_DIR)/ -maxdepth 1 -type f -regex ".*\.tab.c"))
	$(eval src = $(addprefix $(_INTIMIDIATE_DIR)/, $(src)))
	cd $(INTIMIDIATE_DIR);\
	x86_64-w64-mingw32-gcc -c $(src) $(preprocessor_defs) $(include_paths) -m64

bison : flex
	$(eval yacc_files = $(addprefix $(_INTIMIDIATE_DIR)/, $(YACC_FILES)))\
	cd $(INTIMIDIATE_DIR);\
	bison -d $(yacc_files)

flex : create-directories
	$(eval flex_files = $(addprefix $(_INTIMIDIATE_DIR)/, $(FLEX_FILES)))\
	cd $(INTIMIDIATE_DIR);\
	flex $(flex_files)

create-directories : 
	mkdir -p $(INTIMIDIATE_DIR)
	mkdir -p $(BIN_DIR_LINUX)
	mkdir -p $(BIN_DIR_LINUX)/tests
	mkdir -p $(BIN_DIR_WINDOWS)
	mkdir -p $(BIN_DIR_WINDOWS)/tests


rebuild : clean all
rebuild-linux : clean-linux linux
rebuild-windows : clean-windows windows

clean : clean-intimidiate
	rm -rf $(BIN_DIR_ROOT)
clean-linux : clean-intimidiate
	rm -rf $(BIN_DIR_LINUX)
clean-windows : clean-intimidiate
	rm -rf $(BIN_DIR_LINUX)
clean-intimidiate :
	rm -rf $(INTIMIDIATE_DIR)
