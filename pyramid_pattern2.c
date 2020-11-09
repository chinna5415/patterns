#include <stdio.h>

/*
          *
         **
        ***
       ****
      *****
     ******
*/

int main() {
  int width;
  printf("enter the width : ");
  scanf("%d",&width);

  for (int i = 0 ; i < width ; i++) {
    for (int j = 0 ; j < width ; j++)
        if (width-i-1 > j)
            printf(" ");
        else
            printf("*");    
    printf("\n");
  }

  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void FCFS();
void swap(int *, int *);
void swap_p(char *, char *);

int main() {
	FCFS();
	return 0;
}

void FCFS() {
	char process[5];
	int Arival_time[6],Bust_time[6];
	int complete_time[5], Trun_around_time[5], waiting_time[5], time = 0;
	float sum_tat = 0, sum_wt = 0;

	FILE *processFile = fopen("process.txt","r");
	if (processFile == NULL) {
		printf("File doesn't exists");
		exit(0);
	}

	for (int i = 0; i < 5; i++)
		fscanf(processFile, "%c", &process[i]);
	fclose(processFile);

	FILE *bustFile = fopen("bust.txt","r");
	if (bustFile == NULL) {
		printf("File doesn't exists");
		exit(0);
	}

	for (int i = 0; i < 5; i++)
		fscanf(bustFile, "%1d", &Bust_time[i]);
	fclose(bustFile);

	FILE *arivalFile = fopen("arival.txt","r");
	if (processFile == NULL) {
		printf("File doesn't exists");
		exit(0);
	}

	for (int i = 0; i < 5; i++)
		fscanf(arivalFile, "%1d", &Arival_time[i]);
	fclose(arivalFile);

	for (int i = 0; i < 5; i++) {
		int min_time = i;
		for (int j = i+1; j < 5; j++)
			if (Arival_time[i] > Arival_time[j])
				min_time = j;

		swap_p(&process[min_time], &process[i]);
		swap(&Arival_time[min_time], &Arival_time[i]);
		swap(&Bust_time[min_time], &Bust_time[i]);		
	}

	for (int i = 0; i < 5; ) {
		if (time >= Arival_time[i]) {
			time += Bust_time[i];
			complete_time[i] = time;

			Trun_around_time[i] = complete_time[i] - Arival_time[i];
			sum_tat += Trun_around_time[i];

			waiting_time[i] = Trun_around_time[i] - Bust_time[i];
			sum_wt += waiting_time[i];

			i++;
		} else {
			time += abs(time - Bust_time[i]);
		}
	}

	printf("\nOrder of exectution : \n");
	for (int i = 0; i < 5; i++)
		printf("%c  ",process[i]);
	printf("\nAverage Trun Around Time : %.2f",(sum_tat/5));
	printf("\nAverage waiting Time : %.2f", (sum_wt/5));
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap_p(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
