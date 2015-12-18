#include <stdio.h>
#include <stdlib.h>
#include "hashTable.c"


int main() {
  
  FILE* f;
  f = fopen("input.txt", "r");

  int c;

  hash_table_t* ht = create_hash_table(1000);
  point* origin; //offsetting the origin to get positive numbers
  origin->x = 800;
  origin->y = 800;

  add_point(ht, origin);

  point* current_point = origin; //a shallow copy is OK. We don't need the origin again.
  
  //let's grab characters one at a time;
  while(c != EOF) {
    c = fgetc(f);
    
    if(feof(f)) {
      break;
    }
    
    printf("%c\n", c);

    if(c == '^') {
      current_point->y += 1;
    }
    if(c == 'v') {
      current_point->y -= 1;
    }
    if(c == '>') {
      current_point->x += 1;
    }
    if(c == '<') {
      current_point->x -= 1;
    }
    add_point(ht, current_point);
  }

  int uniqueVisits = ht_n_entries(ht);
  printf("%d unique houses visited", uniqueVisits);
  return 1; 
}
