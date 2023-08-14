CXX      = g++
LD       = g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic
OUTPUT   = destitute.out

all: $(OUTPUT)

compile: $(OUTPUT)

$(OUTPUT): main.o
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(OUTPUT)
 
run: $(OUTPUT)
	./$(OUTPUT)