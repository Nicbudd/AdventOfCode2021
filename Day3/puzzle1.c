#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE * fp = fopen("test.txt", "r");
  char * line = 0;
  size_t len = 0;
  ssize_t read;

  int stringLen = 5;

  int gamma_rate[stringLen];
  int epsilon_rate[stringLen];

  for (int i = 0; i < stringLen; i++){
    gamma_rate[i] = 0;
  }

  int lCount = 0;

  while ((read = getline(&line, &len, fp)) != -1) {

    char bin[stringLen];

    sscanf(line, "%s/n", bin);

    for (int ch = 0; ch < stringLen; ch++){
      int digitVal = (int) bin[ch] - 48;
      //printf("%d\n", digitVal);
      gamma_rate[ch] += digitVal;
    }

    lCount++;
  }

  printf("\n");

  for (int ch = 0; ch < stringLen; ch++){
    gamma_rate[ch] = (gamma_rate[ch] * 2) / lCount;
    epsilon_rate[ch] = (gamma_rate[ch] * -1) + 1;
    printf("%d", epsilon_rate[ch]);
  }

  int num = (int) strtol(gamma_rate, NULL, 2);

  printf("%d\n", num);

  free(line);
}
