#include <stdio.h>
#include <stdlib.h>

typedef struct Points {
  int x;
  int y;
} point;

//checks if points are the same
int equal(point* a, point*b) {
  if ((a->x == b->x) && (a->y == b->y))
    return 1;
  else
    return 0;
}

//checks if point a is "greater than" point b
int greater(point* a, point* b) {
  //TODO
  return 1;
}
