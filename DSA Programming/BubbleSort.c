#include <stdio.h>

void swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void BubbleSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
	}
}

int main(){
	int arr[5]={2,3,4,5,1};int n=5;
	printf("Before sorting: \n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	BubbleSort(arr,n);
	printf("\nAfter sorting: \n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}