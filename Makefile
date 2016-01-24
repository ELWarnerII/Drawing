# Extra options for the default compile rule to use.
CC = gcc
CFLAGS = -Wall -std=c99 
LDLIBS = -lm

# Drawing depends on this object.
drawing: image.o

# Object file dependencies
drawing.o: image.h
image.o: image.h