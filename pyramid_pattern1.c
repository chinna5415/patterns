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
if (( $1 >= $2 && $1 >= $3))
then
	echo "$1 is greater"
elif (($2 >= $1 && $2 >= $3))
then
	echo "$2 is greater"
else
       	echo "$3 is greater"
fi
