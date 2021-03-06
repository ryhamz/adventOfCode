#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN( a, b ) ( ( a > b) ? b : a )

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  
}

int ribbon(int length, int width, int height) {
  int min = length; //smallest side of the box
  int middle = width; //2nd smallest side of the box.
  int max = height;
  if (min > middle) swap(&min, &middle);
  if (middle > max) swap(&middle, &max);
  if (min > middle) swap(&min, &middle);

  int volume = length * width * height;
  int res = (2*min) + (2*middle) + (volume);
  //  printf("l = %d w = %d h = %d ribbon = %d\n", length, width, height, res);
  return res;
}


//calculates wrapping paper required for a box with dimensions length, width, height.
int wrapping_paper(int length, int width, int height) {
  int side1 = length * width;
  int side2 = width * height;
  int side3 = length * height;
  
  int smallest = MIN(MIN(side1,side2), side3); 
  //  printf("side1 = %d, side2: %d, side3: %d smallest: %d\n", side1, side2, side3, smallest);

  //each box needs 2*l*w + 2*w*h + 2*h*l +  area of smallest side square ft of paper
  return 2*side1 + 2*side2 + 2*side3 + smallest;
  
}
int main() {
  int totalPaperArea = 0;
  int totalRibbon = 0;
  int length, width, height;
  int c;

  FILE *f = fopen("input.txt", "r");

  if(f) {
    do { //read file lines
      c = fscanf(f, "%dx%dx%dx\n", &length, &width, &height);
      if(c == 3) {
	//add one boxes wrapping paper to the total;
	totalPaperArea += wrapping_paper(length, width, height);
	totalRibbon += ribbon(length, width, height);
      }
      //      printf("%d\n", c);
    } while(c == 3);
    fclose(f);
  }
  printf("Total wrapping paper required: %d square feet.\nTotal ribbon: %d feet\n", totalPaperArea, totalRibbon);
  return 1;
}
