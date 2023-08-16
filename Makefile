CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic -lpthread -pthread
OUTPUT   = destitute.out

all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): main.o control/Controller.o draw/Draw.o level/LevelView.o level/Level.o level/Tile.o level/WallTile.o utility/Utility.o \
		   level/TileFactory.o game/RunInstance.o entity/Entity.o utility/Point.o
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o */*.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)