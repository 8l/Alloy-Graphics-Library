SRC := $(wildcard src/core/*.cpp,src/core/*.c)
OBJS := $(patsubst %.cpp,%.o,$(wildcard src/core/*.cpp)) $(patsubst %.c,%.o,$(wildcard src/core/*.c))
DS := $(patsubst %.cpp,%.d,$(wildcard src/core/*.cpp src/example/*.cpp))
EXOBJS := $(patsubst %.cpp,%.o,$(wildcard src/example/*.cpp))
CXX = g++
CC = gcc
INC = -Iinclude/core/ -Iinclude/example/ -I/usr/local/include/ -I/usr/include/
CXXFLAGS:= -std=c++0x -DGL_GLEXT_PROTOTYPES=1 -O3 -Wall -c -fmessage-length=0 -MMD -MP -fopenmp $(INC)
CFLAGS:= -DGL_GLEXT_PROTOTYPES=1 -O3 -Wall -c -fmessage-length=0 -MMD -MP -fopenmp $(INC)
LDLIBS =-L./ -L/usr/lib/ -L/usr/local/lib/ -L/usr/lib/x86_64-linux-gnu/
LIBS =-lalloy -lstdc++ -lglfw -lgomp -lGL -lXext -lGLU -lGLEW -lXi -lXrandr -lX11 -lXxf86vm -lXinerama -lXcursor -lXdamage -lpthread -lm -ldl
RM=rm -f

alloy : $(OBJS)
	ar ru liballoy.a $(OBJS)
	ranlib liballoy.a

examples : $(EXOBJS)
	$(CXX) $(LDLIBS) -o examples $(EXOBJS) $(LIBS)
		
clean :
	clear
	$(RM) $(OBJS) $(EXOBJS) $(DS)
	$(RM) liballoy.a
	$(RM) $(EXAMPLES) examples
	
all : 
	clear
	make -j8 alloy
	make -j8 examples
default : all
