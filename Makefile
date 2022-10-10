CXX = g++
CFLAGS = -g
LDFLAGS = -I headers/

OBJS = $(wildcard obj/*.o)
SRCS = $(wildcard src/*.cpp)
HEDS = $(wildcard headers/*.hpp)

link: $(OBJS)
	@echo === Link ===
	$(CXX) $^ $(CFLAGS) $(LDFLAGS) -o bin/main.exe

obj/main.o: $(SRCS) $(HEDS)
	@echo === Compile ===
	$(CXX) $^ $(CFLAGS) $(LDFLAGS) -c -o $@
