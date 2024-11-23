#include <stdio.h>

// Function to perform sequential search
    int sequentialSearch(int arr[], int size, int key){
        for (int i = 0; i < size; i++){
            if (arr[i] == key){
                return i; // Return the index if key is found
            }
        }
        return -1; // Return -1 if key is not found
    }

    // Function to perform binary search
    int binarySearch(int arr[], int size, int key){
        int low = 0, high = size - 1;
        while (low <= high){
            int mid = low + (high - low) / 2; // Avoids overflow
            if (arr[mid] == key){
                return mid; // Key found
            }
            else if (arr[mid] < key){
                low = mid + 1; // Search in the right half
            }
            else{
                high = mid - 1; // Search in the left half
            }
        }
        return -1; // Key not found
    }

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Array: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Sequential Search
    int seqResult = sequentialSearch(arr, size, key);
    if (seqResult != -1)
        printf("Sequential Search: Key found at index %d.\n", seqResult);

    else
        printf("Sequential Search: Key not found.\n");

    // Binary Search
    int binResult = binarySearch(arr, size, key);
    if (binResult != -1)
        printf("Binary Search: Key found at index %d.\n", binResult);
    else
        printf("Binary Search: Key not found.\n");
    return 0;
}