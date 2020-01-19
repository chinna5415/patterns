#include <stdio.h>

/*
          *
         ***
        *****
       *******
      *********
     ***********
*/

int main() {
  int width;
  printf("enter the width : ");
  scanf("%d",&width);

  for (int i = 0 ; i < width ; i++) {
    int l = 0;
    for (int j = 0 ; j < width+i ; j++) {
      if (width-i-1 > j)
            printf(" ");
        else
            printf("*");
    }
    printf("\n");
  }

  return 0;
}
