/*3. Consider two liked list A of size N. Write a program to Split the linked list two parts i.e.
B and C each of size N/2.*/
#include "header.h"


int main(void)
{
        int n;
        printf("Enter how many values you want to insert: ");
        scanf("%d",&n);
        int a[n];
        printf("Enter the values: ");
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        node* head=insert(a,n);
        //display(head);
        node *sechalf=split(head);
        printf("\nFirst Half: \n");
        display(head);
        printf("Second Half: \n");
        display(sechalf);
        return 0;
}