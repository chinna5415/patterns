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
read -p "enter the input " input

				if [ $(echo $input | egrep "^[0-9]+$") ]
				then 
					echo "$input number"
				elif [ $(echo $input | egrep "^[-+]?[0-9]*\.?[0-9]+$") ]
				then 
					echo "$input float"
				else
					echo "$input string"
				fi
