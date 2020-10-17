#include <stdio.h>

/*
    *******
     ******
      *****
       ****
        ***
         **
          *
*/

int main() {
  int width;
  printf("enter the width : ");
  scanf("%d",&width);

  for (int i = 0 ; i < width ; i++) {
    for (int j = 0 ; j < width ; j++)
        if (i > j)
           printf(" ");
        else
            printf("*");   
    printf("\n");
  }

  return 0;
}

!/usr/bin/env bash
number=11
if (( number%2 == 0))
then
	echo "$number is even"
else
	echo "$number is odd"
fi
