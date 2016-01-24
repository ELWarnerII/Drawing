/**
   @file image.c
   @author Louis Warner (elwarner)
   This program contains helper methods for drawing.c.
   It does the work of clearing the image array, drawing lines,
   drawing circles, and saving the array to a .pgm file.
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
  void clearImage( unsigned char image[ WIDTH ][ HEIGHT ], unsigned char color ){
    for( int i = 0; i < WIDTH; i++){
      for( int j = 0; j < HEIGHT; j++){    
        image[i][j] = color;
      }
    }
  }

/**
   Given an image and an output file that's been opened for writing,
   this function will write the image to the output file in PGM format.
   @param image - a 2D unsigned char array
   @param outputFile - pointer to the file to be written to
  */
  void saveImage( unsigned char image[ WIDTH ][ HEIGHT ], FILE *outputFile ){
    fprintf(outputFile, "P2\n");
    fprintf(outputFile, "%d %d\n", WIDTH, HEIGHT);
    fprintf(outputFile, "%d\n", MAXCOLOR);
    for( int j = 0; j < HEIGHT; j++){
      for( int i = 0; i < WIDTH; i++){
        if (i ==0){
          fprintf(outputFile, "%3d", image[i][j]);
        } else{
          fprintf(outputFile, "%4d", image[i][j]);
        }
      }
      fprintf(outputFile, "\n");
    }
  }

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
  void drawLine( unsigned char image[ WIDTH ][ HEIGHT ], int x1, int y1, int x2, int y2, unsigned char color ){
    int dx = x2 - x1;
    int dy = y2 - y1;
    int switcher;
    int pixels;

    if (abs(dx) > abs(dy)){
      pixels = abs(dx);
      if (x2 < x1){
        switcher = x1;
        x1 = x2;
        x2 = switcher;
        switcher = y1;
        y1 = y2;
        y2 = switcher;
      }
    } else {
      pixels = abs(dy);
      if(y2 < y1){
        switcher = y1;
        y1 = y2;
        y2 = switcher;
        switcher = x1;
        x1 = x2;
        x2 = switcher;      
      }
    }
    
    int tempx = x1;
    int tempy = y1;

    if(x2 - x1 == 0){
      for(int i = 0; i <= pixels; i++){
        if(tempx >= 0 && tempx < WIDTH && tempy >=0 && tempy < HEIGHT){
          image[tempx][tempy] = color;
        }
        tempy++;
      }
    } else if (y2 - y1 == 0){
      for(int i = 0; i <= pixels; i++){
        if(tempx >= 0 && tempx < WIDTH && tempy >=0 && tempy < HEIGHT){
          image[tempx][tempy] = color;
        }
        tempx++;
      }
    } else {
      double slope =  ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
      double b = (double)y1 - (slope * (double)x1);
      
      for(int i = 0; i <= pixels; i++){
        if(tempx >= 0 && tempx < WIDTH && tempy >=0 && tempy < HEIGHT){
          image[tempx][tempy] = color;
        }
        if(abs(dx) > abs(dy)){
          tempx++;
          tempy = round((slope * tempx) + b);
        } else {
          tempy++;
          tempx = round((tempy - b)/slope);
        }
      }
    }
  }

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
  void drawCircle( unsigned char image[ WIDTH ][ HEIGHT ], int cx, int cy, int radius, unsigned char color ){
    double distance;
    int beginx = cx - radius;
    int beginy = cy - radius;
    int endx = cx + radius;
    int endy = cy + radius;
    for(int i = beginx; i <= endx; i++){
      for(int j = beginy; j <= endy; j++){
        distance = sqrt(((double)i - (double)cx) * ((double)i - (double)cx)+((double)j - (double)cy) * ((double)j - (double)cy));
        if(distance < radius && i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT){
          image[i][j] = color;
        }
      }
    }
  }