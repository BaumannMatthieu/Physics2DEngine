#OBJS specifies which files to compile as part of the project 
OBJS = main.cpp Vector2.h Matrix22.h PhysicObject.cpp PhysicObject.h Point.h Polygon2D.h Polygon2D.cpp Rectangle2D.h Rectangle2D.cpp PhysicCollision.cpp PhysicCollision.h PhysicRectCollision.h PhysicRectCollision.cpp

#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using # -w suppresses all warnings 
COMPILER_FLAGS = 

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lGL -lGLU -lglut 

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = physics2DEngine 

#This is the target that compiles our executable 

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
