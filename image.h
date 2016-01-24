/**
   @file image.h
   @author Louis Warner (elwarner)
   This is the header file for image.c.
 */
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #define WIDTH 255
 #define HEIGHT 255
 #define MAXCOLOR 255
 
/**
   Given an image and a color value in the range 0 to 255, this
   function will set all the pixels of the image to the given color.
   @param image - a 2D unsigned char array
   @param color - an unsigned char
  */
  void clearImage( unsigned char image[ WIDTH ][ HEIGHT ], unsigned char color );

/**
   Given an image and an output file that's been opened for writing,
   this function will write the image to the output file in PGM format.
   @param image - a 2D unsigned char array
   @param outputFile - pointer to the file to be written to
  */
  void saveImage( unsigned char image[ WIDTH ][ HEIGHT ], FILE *outputFile );

/**
   Given an image, the endpoints of a line and a drawing color, this function
   will draw the given line into the image as described in the requirements section.
   @param image - a 2D unsigned char array
   @param x1 - x coordinate for beginning of line
   @param y1 - y coordinate for beginning of line
   @param x2 - x coordinate for end of line
   @param y2 - y coordinate for end of line
   @param color - an unsigned char
  */   
  void drawLine( unsigned char image[ WIDTH ][ HEIGHT ], int x1, int y1, int x2, int y2, unsigned char color );

/**
   Given an image, the center location of a circle, the circle's radius and a
   drawing color, this function will draw a filled circle into the image as described
   in the requirements section.
   @param image - a 2D unsigned char array
   @param cx - x coordinate for center of circle
   @param cy - y coordinate for center of circle
   @param radius - length of radius
   @param color - an unsigned char
  */
  void drawCircle( unsigned char image[ WIDTH ][ HEIGHT ], int cx, int cy, int radius, unsigned char color );