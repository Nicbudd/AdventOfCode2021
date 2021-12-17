#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE * fp = fopen("input.txt", "r");
  char * line = 0;
  size_t len = 0;
  ssize_t read;

  int gamma_rate = 0;
  int epsilon_rate = 0;

  const int INPUTSIZE = 12;

  int perColumnSum[INPUTSIZE];
  for (int i = 0; i < INPUTSIZE; i++){
      perColumnSum[i] = 0;
  }

  int lineCount = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    for (int ch = 0; ch < INPUTSIZE; ch++){
        perColumnSum[ch] += (line[ch] - '0');
    }
    lineCount++;
  }

  free(line);
  free(fp);

  for (int i = 0; i < INPUTSIZE; i++){
      int overUnder = perColumnSum[i] > (lineCount / 2) ? 1 : 0; // if there are more 1s then make it a 1, otherwise make it a 0.
      gamma_rate += overUnder << ((INPUTSIZE - 1) - i); // shift bit into correct place and add it to number

  }

  epsilon_rate = gamma_rate ^ ((1 << INPUTSIZE) - 1); // xor gamma_rate with all 1s

  printf("%d\n", gamma_rate);
  printf("%d\n", epsilon_rate);

  printf("%d\n", gamma_rate * epsilon_rate);

}
