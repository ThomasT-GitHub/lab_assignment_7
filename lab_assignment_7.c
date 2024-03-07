#include <stdio.h>

void bubbleSort(int *a, int*b, int n);
void selectionSort(int *a, int *b, int n);
void clearSwaps(int *a, int n);

int main() {
    
    // Creates the arrays to test 
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    // Keeps track of swaps
    int swaps[100];

    printf("BUBBLE SORT: ARRAY 1\n");
    bubbleSort(array1, swaps, 9);
    for (int i = 0 ; i < 9; i++) printf("%d: %d\n", array1[i], swaps[array1[i]]);
    
    printf("\nBUBBLE SORT: ARRAY 2\n");
    clearSwaps(swaps, 100);
    bubbleSort(array2, swaps, 9);
    for (int i = 0 ; i < 9; i++) printf("%d: %d\n", array2[i], swaps[array2[i]]);

    // Resets the arrays to be tested again (unsorts them)
    int array1_2[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2_2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    printf("\nSELECTION SORT: ARRAY 1\n");
    clearSwaps(swaps, 100);
    selectionSort(array1_2, swaps, 9);
    for (int i = 0 ; i < 9; i++) printf("%d: %d\n", array1_2[i], swaps[array1_2[i]]);

    
    printf("\nSELECTION SORT: ARRAY 2\n");
    clearSwaps(swaps, 100);
    selectionSort(array2_2, swaps, 9);
    for (int i = 0 ; i < 9; i++) printf("%d: %d\n", array2_2[i], swaps[array2_2[i]]);

    return 0;
}

void bubbleSort(int *a, int *b, int n) {
    // Stores the total swaps
    int totalSwaps = 0;

    // Loops through all the values of a
    for (int i = 0; i < n - 1; i++) {
        // Compares every value righthand value
        for (int j = 0; j < n - 1- i; j++) {
            // If first value is smaller than right value, swap and increase num of swaps
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                
                // Keeps track of the swaps
                b[a[j]]++;
                b[a[j + 1]]++;
                totalSwaps++;
            }
        }
    }
    
    // Prints the total swaps
    printf("Total Swaps: %d\n", totalSwaps);
}

void selectionSort(int *a, int *b, int n) {
    // Creates our minIndex, temp and totalSwaps
    int minIndex;
    int temp;
    int totalSwaps = 0;
    
    // Loops through every value of a
    for (int i = 0; i < n - 1; i++) {
        // Creates the counter to keep track of num swaps; creates numTracked to hold the num tracked
        int c = 0;
        int numTracked = a[i];
        
        // Sets minIndex
        minIndex = i;
        
        // Finds the min value and its index excluding the mins we have found
        for (int j = i + 1; j < n; j++) {
            // If a smaller number is located, set its index to minIndex
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swaps the min value and the current value we're on
        if (a[i] != a[minIndex]) {
            // Keeps track of the swaps
            b[a[i]]++;
            b[a[minIndex]]++;
            totalSwaps++;
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
    
    // Prints the total swaps
    printf("Total Swaps: %d\n", totalSwaps);
}

void clearSwaps(int *a, int n) {
    // Sets all values of a to 0
    for (int i = 0 ; i < n; i++) {
        a[i] = 0;
    }
}

