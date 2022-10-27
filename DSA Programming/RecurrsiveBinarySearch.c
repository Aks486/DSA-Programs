#include <stdio.h>

int BinarySearch(int arr[],int key,int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			return BinarySearch(arr,key,mid+1,r);
		else
			return BinarySearch(arr,key,l,mid-1);
	}
	return -1;
}
int main(){
	int key;
	// printf("Enter the size of array: ");
	// scanf("%d",&n);
	int arr[8]={1,2,3,4,5,6,7,8};
	// printf("Enter n elements into array: ");
	// for(int i=0;i<n;i++){
	// 	scanf("%d",&arr[i]);
	// }
	int n = sizeof(arr)/sizeof(arr[0]);	
	printf("Enter the element u want to find: ");
	scanf("%d",&key);
	int index = BinarySearch(arr,key,0,n-1);
	if(index>=0)	
		printf("Element found: %d",index);
	else	
		printf("Not found");
	return 0;
}