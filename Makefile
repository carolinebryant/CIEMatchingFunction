# Change the following values to suit your system.

CFLAGS=`sdl-config --cflags` -g -W -Wall -Weffc++ -Wextra -pedantic -O0
SDL_LIB=`sdl-config --libs` -lSDL_ttf -lSDL_image
CCC=g++

OBJECTS = cieMatching.o colors.o vector.o matrix.o

run: main.o $(OBJECTS)
	$(CCC) $(CFLAGS) main.cpp -o run $(OBJECTS) $(SDL_LIB)

main.o: main.cpp cieMatching.h
	$(CCC) $(CFLAGS) -c main.cpp

cieMatching.o: cieMatching.cpp cieMatching.h
	$(CCC) $(CFLAGS) -c cieMatching.cpp

colors.o: colors.cpp colors.h
	$(CCC) $(CFLAGS) -c colors.cpp

vector.o: vector.cpp vector.h
	$(CCC) $(CFLAGS) -c vector.cpp
	
matrix.o: matrix.cpp matrix.h
	$(CCC) $(CFLAGS) -c matrix.cpp	

clean:
	rm -f run *.o
	rm -f *~
	rm -f frames/*.bmp
