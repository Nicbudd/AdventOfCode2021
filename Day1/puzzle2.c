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
  int readings[3];

  while ((read = getline(&line, &len, fp)) != -1){

    sscanf(line, "%d", &readInt);

    readings[0] = readings[1];
    readings[1] = readings[2];
    readings[2] = readInt;

    int sum;

    if (readings[0] != NULL) {
      sum = readings[0] + readings[1] + readings[2];
    }

    if (sum != NULL && prevValue != NULL && prevValue < sum){
      sumIncreasing++;
    }

    prevValue = sum;
  }

  free(line);
  printf("%d\n", sumIncreasing);

}
