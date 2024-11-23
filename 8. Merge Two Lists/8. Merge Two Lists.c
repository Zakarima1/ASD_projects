// by : featas cherif
#include <stdio.h>
#include <stdlib.h>

// Function to sort a list using Bubble Sort
void bubbleSort(int L[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (L[j] > L[j + 1]) {
                // Swap L[j] and L[j + 1]
                int temp = L[j];
                L[j] = L[j + 1];
                L[j + 1] = temp;
            }
        }
    }
}

// Function to merge two lists into a single list
void merge(int L1[], int size1, int L2[], int size2, int merged[]) {
    // Copy elements from L1 into merged
    for (int i = 0; i < size1; i++) {
        merged[i] = L1[i];
    }

    // Copy elements from L2 into merged
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = L2[i];
    }
}

int main() {
    int size1, size2;

    // Input the size and elements of the first list
    printf("Enter the size of the first sorted list (L1): ");
    scanf("%d", &size1);
    int L1[size1];
    printf("Enter the elements of the first sorted list:\n");
    for (int i = 0; i < size1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &L1[i]);
    }

    // Input the size and elements of the second list
    printf("Enter the size of the second sorted list (L2): ");
    scanf("%d", &size2);
    int L2[size2];
    printf("Enter the elements of the second sorted list:\n");
    for (int i = 0; i < size2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &L2[i]);
    }

    // Create a merged list to hold the result
    int merged[size1 + size2];

    // Merge the two lists
    merge(L1, size1, L2, size2, merged);

    // Sort the merged list
    bubbleSort(merged, size1 + size2);

    // Print the merged and sorted list
    printf("Merged and sorted list: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
