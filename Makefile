SOURCE = callbacks.cpp \
         display.cpp \
         event.cpp \
         init.cpp \
		 	energy.cpp \
         keyboard.cpp \
         location.cpp \
         main.cpp \
         mouse.cpp \
         reshape.cpp \
         util.cpp \
         imageio.cpp \
         lodepng.cpp \
         graphics.cpp \
         alloc2d.cpp \
         canvas.cpp \
		 seam.cpp 

#SOURCE = alloc2d.cpp \
		 energy.cpp \
		 canvas.cpp \
		 graphics.cpp \
		 test.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -std=c++11
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lglut -lGL -lGLU -lpthread

.PHONY: clean

# Targets include all, clean, debug, tar

all : main

main: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core main

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

tar: clean
	tar zcvf main.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

