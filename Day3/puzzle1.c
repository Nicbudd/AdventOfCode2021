#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE * fp = fopen("input.txt", "r");
  char * line = 0;
  size_t len = 0;
  ssize_t read;

  char gamma_rate[12];
  for (int i = 0; i < 12; i++){
    gamma_rate[i] = 0;
  }

  while ((read = getline(&line, &len, fp)) != -1) {

    char bin[12];

    for (int ch = 0; ch < 12; ch++){
      gamma_rate[ch] += (int) strtol(&bin[ch], NULL, 2);
    }

    sscanf(line, "%s/n", bin);

    int value = (int) strtol(bin, NULL, 2);

    printf("%s\n", );



  }

  free(line);
}
