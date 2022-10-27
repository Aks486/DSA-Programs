#include <stdio.h>

void Heapify(int arr[],int n,int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;

	if(left<n && arr[left]>arr[largest])
		largest = left;
	if(right<n && arr[right]>arr[largest])
		largest = right;

	if(largest!=i){
		int temp = arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		Heapify(arr,n,largest);
	}	
}

void HeapSort(int arr[],int n){
	for(int i =n/2-1;i>=0;i--)
		Heapify(arr,n,i);
	for(int i=n-1;i>=0;i--){
		int temp = arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		Heapify(arr,i,0);
	}
	
}
void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}  
int main()  
{  
    int a[] = {48, 10, 23, 43, 28, 26, 1};  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    HeapSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}  