
lcc := ${LCC}
gcc := ${GCC}
SOURCECODEDIR := lib
OBJECTCODEDIR := build
TESTDIR := test

sources := $(wildcard $(SOURCECODEDIR)/*.c) $(wildcard $(SOURCECODEDIR)/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*.c)\
					$(wildcard $(SOURCECODEDIR)/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*.c)\
					$(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*/*/*/*/*/*.c)

tests := $(wildcard $(TESTDIR)/*_test.c) $(wildcard $(TESTDIR)/*/*_test.c) $(wildcard $(TESTDIR)/*/*/*_test.c)\
					$(wildcard $(TESTDIR)/*/*/*/*_test.c) $(wildcard $(TESTDIR)/*/*/*/*/*_test.c) $(wildcard $(TESTDIR)/*/*/*/*/*/*_test.c)\
					$(wildcard $(TESTDIR)/*/*/*/*/*/*/*_test.c) $(wildcard $(TESTDIR)/*/*/*/*/*/*/*/*_test.c) $(wildcard $(TESTDIR)/*/*/*/*/*/*/*/*/*/*/*_test.c)

build/game.gb : clean build test
	${lcc} ${sources} -o build/game.gb

build :
	mkdir build

test : ${tests}

build/test : build
	mkdir build/test

$(tests) : build/test
	$(gcc) $@ -o ./build/$(subst .c,,$@)
	./build/$(subst .c,,$@)

clean :
	if [ -d "./build" ]; then rm -r build; fi


