SOURCE=*.cpp
LIBS=-lsfml-window -lsfml-system -lsfml-graphics
NAME=danmaku.out

all:
	clang++ -std=c++17 $(SOURCE) $(LIBS) -o $(NAME)

clean:
	rm *.out
