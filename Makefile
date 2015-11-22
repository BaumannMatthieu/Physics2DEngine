CC=g++
CFLAGS=
LDFLAGS= -lGL -lGLU -lSDL2main -lSDL2
OBJ_NAME = physics2DEngine
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(OBJ_NAME)

$(OBJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o $(OBJ_NAME)
