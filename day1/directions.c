#include <stdio.h>
#include <string.h>

int main(int argc, char* argv) {
  char buff[8024]; //read input file into this.
  FILE *f = fopen("input.txt", "r");
  fgets(buff, 8024, f);
  int l = strlen(buff);

  int floor = 0; //this is what we are calculating. add 1 for '('; subtract 1 for ')'
  int i;
  for (i = 0; i < l-1; i++) {
    //the current character is either ( or ), so
    //we only need to perform one check.
    if (buff[i] == '(') {
      floor++;
    }
    else {
      floor--;
    }
  }
  fclose(f);
  printf("Santa should go to floor %d.\n", floor);
  return 1;
}
