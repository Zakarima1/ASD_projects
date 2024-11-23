// by : featas cherif6
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node structure
struct Node {
    int value;
    struct Node* next;
};

// Function to insert a new node in descending order to keep track of the largest k elements
void insert_sorted(struct Node** head, int value, int k) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    // Special case: If the list is empty or the new node should be the first
    if (*head == NULL || (*head)->value < value) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the right position
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->value >= value) {
        temp = temp->next;
    }

    // Insert the new node after temp
    new_node->next = temp->next;
    temp->next = new_node;

    // If the list has more than 'k' elements, remove the smallest one (end of list)
    temp = *head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (count > k) {
        // Remove the last node (smallest element)
        struct Node* to_delete = *head;
        while (to_delete->next != NULL && to_delete->next->next != NULL) {
            to_delete = to_delete->next;
        }
        // Now to_delete points to the second-to-last node
        struct Node* last_node = to_delete->next;
        to_delete->next = NULL;
        free(last_node);
    }
}

// Function to find the k-th largest element
int kth_largest(int L[], int size, int k) {
    struct Node* head = NULL;

    // Process each element in the list
    for (int i = 0; i < size; i++) {
        insert_sorted(&head, L[i], k);
    }

    // Traverse the linked list to find the k-th largest element
    struct Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        return temp->value;
    } else {
        return -1;  // Return -1 if k is invalid (e.g., larger than the list size)
    }
}

// Main function to test the kth_largest function
int main() {
    int size, k;

    // Input the size of the list and the value of k
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int L[size];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &L[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Find and print the k-th largest element
    int result = kth_largest(L, size, k);
    if (result != -1) {
        printf("The %d-th largest element is: %d\n", k, result);
    } else {
        printf("Invalid value of k.\n");
    }

    return 0;
}
