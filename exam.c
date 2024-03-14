#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        (*comparisons)++;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }
        arr[j + 1] = key;
    }
}
void printArrayToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}
void readFileToArray(const char *filename, int arr[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file) {
        *n = 0;
        while (fscanf(file, "%d", &arr[*n]) != EOF) {
            (*n)++;
        }
        fclose(file);
    }
}
int main() {
    int option;
    int arr[500];
    int n = 0;
    int comparisons = 0;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            readFileToArray("inAsce.dat", arr, &n);
            break;
        case 2:
            readFileToArray("inDesc.dat", arr, &n);
            break;
        case 3:
            readFileToArray("inRand.dat", arr, &n);
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    insertionSort(arr, n, &comparisons);
    printArrayToFile(arr, n, "outInsSorted.dat");

    printf("Before Sorting: Content of the input file\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("After Sorting: Content of the output file\n");
    printf("%d %d\n", comparisons, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (comparisons == (n - 1) * n / 2) {
        printf("Scenario: Worst-case\n");
    } else if (comparisons == n - 1) {
        printf("Scenario: Best-case\n");
    } else {
        printf("Scenario: Neither best nor worst-case\n");
    }

    return 0;
}