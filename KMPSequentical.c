#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#define MILLION 1000000L

int* kmptable(char* pattern);
void* kmp(char* target, char* pattern, int* table);


int main(int argc, char** argv){
	
	/*Declaration Part*/
	int i,j;
 	struct timespec start1, end1;
	double diff;

 	char target[] = "aaaaaaaaaaasasaasdaadadddddddddddd";
 	char pattern[] = "sasa";	
	/*------------------*/

	printf("----- This is sequential results using KMP Algo. -----\n");
	
	/*Constructing KMP table*/
	int* table = kmptable2(pattern);
	/*-----------------*/

	clock_gettime(CLOCK_MONOTONIC, &start1); 				//start time after constructing table
	kmp(target, pattern, table);							
	clock_gettime(CLOCK_MONOTONIC, &end1);
	diff =(end1.tv_sec - start1.tv_sec)*MILLION + (end1.tv_nsec - start1.tv_nsec);
	printf("When the target length is %d, pattern length is %d, the elapsed time is %0.3f ms.\n", n, m, diff); 
	free(table);
	printf("\n");
	return 0;
}
void* kmp(char* target, char* pattern, int* table){
	int n = strlen(target);
	int m = strlen(pattern);
	int j=0;
	int i=0;
	while(i<n){
		if(pattern[j]== target[i])
		{
			j++;
			i++;
		}
		if(j == m){
			printf("Find a matching substring starting at: %d.\n", i-j);
			j = table[j-1];

		}else if(i < n && pattern[j] != target[i]){
			if(j!=0)
				j = table[j-1];
			else
				i++;
		}

	}
}


int* kmptable(char* pattern){
	int len = 4;
	int* table = (int*)malloc(len * sizeof(int));
	int j = 0;
	int i;
	for (i = 1; i < len; i++) {
	    while (j > 0 && pattern[j] != pattern[i])
	        j = table[j-1];

	    if (pattern[j] == pattern[i])
	        j++;
	    table[i] = j;
	}
	int k = 0;
	for(k =0;k<len;k++){
		printf("%d ",table[k]);
	}   
	return table;	    
}