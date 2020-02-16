#include <stdio.h>

/*
     1
    121
   12321
  1234321
*/

int main() {
  int n , i , j , k , l;
  printf("enter the width : ");
  scanf("%d",&n);

  for (i = 0 ; i < n ; i++) {
    for (j = 0 ; j < n-i ; j++)
        printf(" ");
    for (k = 1 ; k < i+1 ; k++)
        printf("%d",k);
    for (l = k ; l >= 1 ; l--)
        printf("%d",l);
    printf("\n");
  }

  return 0;
}
