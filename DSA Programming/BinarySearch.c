#include <stdio.h>

int BinarySearch(int arr[],int key,int l,int r){
	while(l<r){
		int mid=(l+r)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}
int main(){
	int key,n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter n elements into array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}	
	printf("Enter the element u want to find: ");
	scanf("%d",&key);
	int index = BinarySearch(arr,key,0,n-1);
	if(index>=0)	printf("Element found: %d",index);
	else	printf("Not found");
	return 0;
}