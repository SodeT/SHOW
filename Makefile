CXX = g++
CFLAGS = -g
LDFLAGS = -I headers/

OBJS  := $(wildcard obj/*.o)

link: $(OBJS)
	$(CXX) $^ $(CFLAGS) $(LDFLAGS) -o bin/main.exe

obj/main.o: src/main.cpp
	$(CXX) $^ $(CFLAGS) $(LDFLAGS) -c -o $@

