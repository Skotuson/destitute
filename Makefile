CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic -lpthread -pthread
OUTPUT   = destitute.out

ENTITY_SOURCES = $(wildcard entity/*.cpp)
LEVEL_SOURCES  = $(wildcard level/*.cpp)
UTIL_SOURCES   = $(wildcard utility/*.cpp)


all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): main.o control/Controller.o draw/Draw.o game/RunInstance.o \
		   $(ENTITY_SOURCES:.cpp=.o) $(LEVEL_SOURCES:.cpp=.o) $(UTIL_SOURCES:.cpp=.o)
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o */*.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)