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
read -p "enter the number " number

				if ((number <= 0))
				then
					echo "enter the numbe above 0"
				elif ((number == 1))
				then
					echo "1 is neither prime nor composite"
				elif ((number == 2))
				then
					echo "2 is a prime"
				else
					flag=1
					i=2

					while ((i < number))
					do
                        if ((number%i == 0))
                        then
                                flag=0
                                break
                        fi

                        i=$((i+1))
                    done

					if ((flag == 1))
					then
                        echo "$number is prime"
					else
                        echo "$number is composite"

					fi
				fi
			
