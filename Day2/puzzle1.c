#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE * fp = fopen("input.txt", "r");
  char * line = 0;
  size_t len = 0;
  ssize_t read;


  int x = 0; int y = 0;

  while ((read = getline(&line, &len, fp)) != -1) {

    char * command;
    int value;

    sscanf(line, "%s %d/n", command, &value);

    if (strcmp(command, "forward") == 0){
      x += value;
    } else if (strcmp(command, "up") == 0){
      y -= value;
    } else if (strcmp(command, "down") == 0){
      y += value;
    } else {
      printf("Error: %s not recognized\n", command);
    }

    //printf("x: %d, y: %d\n", x, y);

  }

  int multiply = x * y;
  printf("%d\n", multiply);
}
