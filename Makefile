CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic -lpthread -pthread -fsanitize=address
OUTPUT   = destitute.out

ENTITY_SOURCES = $(wildcard entity/*.cpp)
LEVEL_SOURCES  = $(wildcard level/*.cpp)
UTIL_SOURCES   = $(wildcard utility/*.cpp)

SOURCES = $(wildcard *.cpp */*.cpp)
OBJS    = $(SOURCES:.cpp=.o)


all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o */*.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)