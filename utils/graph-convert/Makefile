CXX = icpc
CXXFLAGS = -g -w2 -std=c++14
TARGETS = edgelist2binary binary2edgelist

.PHONY: all clean

all: $(TARGETS)

edgelist2binary: edgelist2binary.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

binary2edgelist: binary2edgelist.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(TARGETS)
