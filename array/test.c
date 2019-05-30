#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>

bool
comparator_func(int * players, int* villians ,int len) {
	int iter = 0;
	for(;iter < len;iter++) {
		if(players[iter] < villians[iter])
		   return false;
	} 
	return true;
}

int
helper_func(int * arr, int low, int high) {
	int swap = 0;
	int j = low;
	int i = low+1 ;
	int pivot = arr[low];
    for(i = low+1; i <= high;i++) {
		if(arr[i] < pivot) {
			swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
			j++;
		}
	}
	swap = arr[j-1];
	arr[j-1] = arr[low];
	arr[low] = swap;
	return j-1;
}

void
quick_sort(int * arr, int low , int high) {
	if(low<high) {
		int partition = helper_func(arr, low, high);
		quick_sort(arr,low,partition-1);
		quick_sort(arr,partition+1,high);
	}
}

int main(int argc, char *a[])
{
	//Write code here
	int test_cases = 0;
	int i = 0;
	int j = 0;

	scanf("%d",&test_cases);

	bool status[test_cases];
	int * players[test_cases];
	int * villians[test_cases];
	int sizeof_arr[test_cases];

	for(j=0 ; j < test_cases; j++) {
		scanf("%d",&sizeof_arr[j]);

		players[j] = malloc(sizeof(int)*sizeof_arr[j]);
		
		if(players[j] == NULL)
		   return -1;
		
		villians[j] = malloc(sizeof(int)*sizeof_arr[j]);
		
		if(villians[j] == NULL){
		   free(players[j]);   
		   return -1;
		}
		
		for(i = 0; i < sizeof_arr[j];i++){
			scanf("%d", (players[j] + i));
			printf("%d ",players[j][i]);
		}	
		i=0;

		for (i = 0;i < sizeof_arr[j];i++) {
		     scanf("%d", (villians[j] + i));
		     printf("%d ",villians[j][i]);
		}	 
	}	
	for(j = 0 ;j < test_cases;j++ ) {
		quick_sort(players[j],0,sizeof_arr[j]-1);
		quick_sort(villians[j],0,sizeof_arr[j]-1);
		status[j] = comparator_func(players[j],villians[j],sizeof_arr[j]);
		printf("%s\n",status[j] == true?"WIN":"LOSE");
		free(players[j]);
		free(villians[j]);
	}
}
