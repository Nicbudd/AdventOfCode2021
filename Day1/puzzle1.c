#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE * fp = fopen("input.txt", "r");
  char * line = 0;
  size_t len = 0;
  ssize_t read;

  int prevValue;
  int readInt;
  int sumIncreasing = 0;

  while ((read = getline(&line, &len, fp)) != -1){

    sscanf(line, "%d", &readInt);

    if (prevValue != NULL && prevValue < readInt) {
      sumIncreasing++;
    }

    prevValue = readInt;

  }

  free(line);
  printf("%d\n", sumIncreasing);

}
