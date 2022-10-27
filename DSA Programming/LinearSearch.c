#include <stdio.h>

void linearSearch(int arr[],int key){
	int flag=0;
	for(int i=0;i<8;i++){
		if(arr[i]==key){
			printf("\nElement found at index : %d",i);
			flag=1;
		}
	}
	if(!flag)
		printf("Not found");
}

int main(){
	int key;
	int arr[8];
	printf("Enter 8 elements into array: ");
	for(int i=0;i<8;i++){
		scanf("%d",&arr[i]);
	}	
	printf("Enter the element u want to find: ");
	scanf("%d",&key);
	linearSearch(arr,key);
	return 0;
}