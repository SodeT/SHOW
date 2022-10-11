CXX = g++
CFLAGS = -g
LDFLAGS = #-I headers/

OBJS = $(wildcard obj/*.o)
SRCS = $(wildcard src/*.cpp)
HEDS = $(wildcard headers/*.hpp)

link: $(OBJS)
	@echo === Link ===
	$(CXX) $^ $(CFLAGS) $(LDFLAGS) -o bin/main.exe

compile: $(SRCS) $(HEDS)
	@echo === Compile ===
	$(foreach, target, $(SRCS), $(CXX) $(target) $(CFLAGS) $(LDFLAGS) -c -o $(addprefix obj/, $(addsuffix .o, $(basename $(target)))))

dont:	
	$(CXX) $(target) $(CFLAGS) $(LDFLAGS) -c -o $(addprefix obj/, $(addsuffix .o, $(basename $(target))))