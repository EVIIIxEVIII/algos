#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quicksort(int array[], int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot = array[end];
  int p1 = start, p2 = start;

  while (p1 < end) {
    if (array[p1] <= pivot) {
      if (p1 != p2 && array[p2] > pivot) {
        swap(&array[p1], &array[p2]);
      }
      p2++;
    }
    p1++;
  }

  swap(&array[p2], &array[end]);
  quicksort(array, start, p2 - 1);
  quicksort(array, p2 + 1, end);
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[] = {3, 6, 8, 10, 1, 2, 1};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Unsorted array: ");
  printArray(array, size);

  quicksort(array, 0, size - 1);

  printf("Sorted array: ");
  printArray(array, size);

  return 0;
}
