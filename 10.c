#include <stdio.h>

// Bubble Sort Function
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort Function
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort Function
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Merge Function
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1, n2 = right - mid;
    int temp[right - left + 1], i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        temp[k++ - left] = arr[left + i] <= arr[mid + 1 + j] ? arr[left + i++] : arr[mid + 1 + j++];

    while (i < n1)
        temp[k++ - left] = arr[left + i++];
    while (j < n2)
        temp[k++ - left] = arr[mid + 1 + j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i - left];
}
// Merge Sort Function
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Utility function to print the array
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original Array: ");
    printArray(arr1, n);

    // Bubble Sort
    bubbleSort(arr1, n);
    printf("Bubble Sorted: ");
    printArray(arr1, n);

    // Insertion Sort
    insertionSort(arr2, n);
    printf("Insertion Sorted: ");
    printArray(arr2, n);

    // Selection Sort
    selectionSort(arr3, n);
    printf("Selection Sorted: ");
    printArray(arr3, n);

    // Merge Sort
    mergeSort(arr4, 0, n - 1);
    printf("Merge Sorted: ");
    printArray(arr4, n);

    return 0;
}


