
lcc := ${LCC}
SOURCECODEDIR := lib
OBJECTCODEDIR := build

sources := $(wildcard $(SOURCECODEDIR)/*.c) $(wildcard $(SOURCECODEDIR)/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*.c)\
					$(wildcard $(SOURCECODEDIR)/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*.c)\
					$(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*/*/*.c) $(wildcard $(SOURCECODEDIR)/*/*/*/*/*/*/*/*/*/*/*.c)

build/game.gb : build
	${lcc} ${sources} -o build/game.gb

build :
	mkdir build

clean :
	rm -r build


