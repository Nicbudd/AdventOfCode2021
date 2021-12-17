#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INPUTWIDTH = 12;
int lineCount = 1010;

int main(){
  FILE * fp = fopen("input.txt", "r");
  char * line = 0;
  size_t len = 0;
  ssize_t read;

  int gamma_rate = 0;
  int epsilon_rate = 0;

  long nums[lineCount];

  int perColumnSum[INPUTWIDTH];
  for (int i = 0; i < INPUTWIDTH; i++){
      perColumnSum[i] = 0;
  }

  int lineNum = 0;

  while ((read = getline(&line, &len, fp)) != -1) {

    nums[lineNum] = strtol(line, NULL, 2);

    lineNum++;
  }
  free(line);
  free(fp);

  lineCount = lineNum;

  int ratings[] = {-1, -1};

  for (int mode = 0; mode <= 1; mode++){ // oxygen generator = 0, CO2 scrubber = 1

      long numList[lineCount];
      memcpy(numList, nums, sizeof(numList));
      int remaining = 0;
      int depth = 0;
      while (depth < INPUTWIDTH){

          remaining = 0;

          // count the ones
          int onesCounter = 0;

          for (int i = 0; i < lineCount; i++){
              if (numList[i] != -1){
                  remaining++;
                  onesCounter += (numList[i] >> (INPUTWIDTH - 1 - depth)) % 2;
              }
          }

          // check which number is more common
          //printf("remaining: %d\n", remaining);
          int thresh = (remaining / 2);
          //printf("thresh: %d\n", thresh);
          //printf("onesCounter: %d\n", onesCounter);
          int mostCommon;

          if (onesCounter < thresh){
              mostCommon = 0;
          } else if (onesCounter > thresh){
              mostCommon = 1;
          } else if (remaining % 2){ // if remaining is odd and the threshold is equal to the ones counter (integer division edge case)
              mostCommon = 0;
          } else { // if it's truely tied
              mostCommon = 1; // chose 1 as default for oxygen mode
          }

          if (mode){
              mostCommon = !mostCommon;
          }


          //printf("mostCommon: %d\n", mostCommon);

          // eliminate nums that don't meet our criteria
          int lastNum;
          remaining = 0;
          for (int i = 0; i < lineCount; i++){
               if (numList[i] != -1){
                    int digit = (numList[i] >> (INPUTWIDTH - 1 - depth)) % 2;

                    if (digit != mostCommon){
                        numList[i] = -1;
                    } else {
                        //printf("n: %ld\n", numList[i]);
                        lastNum = numList[i];
                        remaining++;
                    }
               }
          }

          if (remaining <= 1){
              ratings[mode] = lastNum;
              //printf("lastnum: %d\n", lastNum);
              break;
          }

         depth++;
      }

  }

  printf("%d\n", ratings[0] * ratings[1]);

}
