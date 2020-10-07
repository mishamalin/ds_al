CC=g++
CXXFLAGS=-pipe -O2 -std=c++14
LDFLAGS=
WORK_DIR=./al_toolbox/week1
SOURCES=$(WORK_DIR)/max_pairwise_product.cpp
LIBS=-lm
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS) 

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	./$<

clean:
	rm -rf $(OBJECTS) 
	rm $(EXECUTABLE)
