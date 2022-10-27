#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int n) {
  for(int i=0;i<n;i++) {
    int min_idx = i;
    for(int j=i+1;j<n;j++) {
      if (array[j] < array[min_idx])
        min_idx = j;
    }
    swap(&array[min_idx],&array[i]);
  }
}

void printArray(int array[], int n) {
  for (int i = 0; i < n; ++i)   printf("%d ", array[i]);
}

int main() {
  int data[] = {20, 12, 10, 15, 2};
  int n = sizeof(data) / sizeof(data[0]);
  selectionSort(data, n);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, n);
}