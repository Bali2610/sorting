#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

int delete_heap(int arr[], int *n) {
    if (*n == 0)
        return -1; // Heap is empty
    
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    
    return root;
}

void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Perform heap sort
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int ne;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &ne);

    int arr[ne];
    printf("Enter %d elements:\n", ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}