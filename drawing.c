/**
   @file drawing.c
   @author Louis Warner (elwarner)
   This program reads a script of 2D drawing commands, performs 
   each command in a grayscale image, then saves the result to
   a simple, plain-text image file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "image.h"

/**
   Main method
 */
int main( int argc, char *argv[] ){
  //Check for correct amount of arguments
  if(argc != 3){
    fprintf(stderr, "usage: drawing <script_file> <image_file>\n");
  }
  
  //Open input and output files
  FILE *input = fopen(argv[1], "r");
  if( !input ){
    fprintf(stderr, "Can't open file: %s\nusage: drawing <script_file> <image_file>\n", argv[1]);
    exit (1);
  }
  FILE *output = fopen(argv[2], "w");
  if( !output ){
    fprintf(stderr, "Can't open file: %s\nusage: drawing <script_file> <image_file>\n", argv[2]);
    exit (1);
  }
  
  unsigned char image[WIDTH][HEIGHT] = {{0}};
  char ch;
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  int cx = 0;
  int cy = 0;
  int radius = 0;
  int checker;
  
  //Set original color to white and initialize
  unsigned char color = MAXCOLOR;
  clearImage(image, color);
 
  fscanf(input, " %c", &ch);
  while(!feof(input)){
    if(ch == 'l'){
      fscanf(input, "%d", &x1);
      fscanf(input, "%d", &y1);
      fscanf(input, "%d", &x2);
      fscanf(input, "%d", &y2);
      fscanf(input, "%d", &checker);
      if(checker >= 0 && checker <= MAXCOLOR){
        color = checker;
      } else {
        fprintf(stderr, "Invalid script file\n");
      exit (1);
      }
      drawLine(image, x1, y1, x2, y2, color);
    } else if(ch == 'c'){
      fscanf(input, "%d", &cx);
      fscanf(input, "%d", &cy);
      fscanf(input, "%d", &radius);
      fscanf(input, "%d", &checker);
      if(checker >= 0 && checker <= MAXCOLOR){
        color = checker;
      } else {
       fprintf(stderr, "Invalid script file\n");
      exit (1);
      }
      drawCircle(image, cx, cy, radius, color ); 
    } else {
      fprintf(stderr, "Invalid script file\n");
      exit (1);
    }
    fscanf(input, " %c", &ch);
  }

  saveImage(image, output);
  
  fclose(input);
  fclose(output);
  
  exit(0);
}
  

  