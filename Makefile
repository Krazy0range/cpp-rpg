all:
	g++ -I ./include -L ./lib -o main src/main.cpp -I ./src/model src/model/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image