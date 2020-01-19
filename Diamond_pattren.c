#include <stdio.h>

/*    
          *   
         ***
        *****
       *******
      *********
     ***********
      *********
       *******
        *****
         ***
          *
*/

int main() {
  int width;
  printf("enter the width : ");
  scanf("%d",&width);

  for (int i = 0 ; i < width-1 ; i++) {
    for (int j = 0 ; j < width+i ; j++) {
      if (width-i-1 > j)
            printf(" ");
        else
            printf("*");
    }
    printf("\n");
  }

  for (int i = 0 ; i < width ; i++) {
    for (int j = 0; j < width ; j++) {
      if (i > j)
          printf(" ");
      else
          printf("*");
      if (i < j)
         printf("*");
    }
    printf("\n");
  }

  return 0;
}
