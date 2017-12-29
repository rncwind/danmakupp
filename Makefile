SOURCE=*.cpp
LIBS=-lsfml-window -lsfml-system -lsfml-graphics
NAME=danmaku.out
DFLAGS=-Wall -Wpedantic -fsanitize=address -fsanitize=undefined
RFLAGS=-Wall -Wpedantic

all:
	clang++ -std=c++17 $(RFLAGS) $(SOURCE) $(LIBS) -o $(NAME)

debug:
	clang++ -std=c++17 $(DFLAGS) $(SOURCE) $(LIBS) -o $(NAME)

clean:
	rm *.out
