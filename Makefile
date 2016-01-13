CC = g++
LD = g++
CPPFLAGS = -std=c++0x -g -Wall -pedantic
LDFLAGS =

# Add any extra .cpp files to this line to
# have them compiled automatically.
SRCS = mtictactoe.cpp mboard.cpp

OBJS = $(SRCS:.cpp=.o)

all: mtictactoe

mtictactoe: $(OBJS)
	g++ -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

clean :
	rm -f mtictactoe *.o
