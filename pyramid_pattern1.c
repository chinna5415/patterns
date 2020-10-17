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
read -p "enter the n (range {1..n})" limit
  sum=0
                i=1

                while ((i <= limit))
                do
                        sum=$((sum + i))
                        i=$((i+1))
                done

                echo "avg : "
                echo "$sum / $limit" | bc -l
