#Program name
PROGRAM := FSM

#Compiler and Flags
CXX := g++
CXXFLAGS := -Wall -g

#Locates all cpp/object files inside folder
srcfiles := $(shell find . -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(PROGRAM)

#Compiles all the oject files
$(PROGRAM): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(PROGRAM) $(objects) $(LDLIBS)

depend: .depend

#Handles dependencies
.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

#Clean up all object files
clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend