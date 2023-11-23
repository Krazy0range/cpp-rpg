all:
	g++ -o out src/cpp-rpg.cpp -std=c++17 -Wextra \
	-I ./include -L ./lib \
	-I ./src/model -I ./src/view -I ./src/controller \
	src/model/*.cpp src/view/*.cpp src/controller/*.cpp \
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image