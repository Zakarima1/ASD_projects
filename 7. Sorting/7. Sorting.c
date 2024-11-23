// by : featas cherif
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
struct Node {
    int data;           // Data part
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node to the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode; // If the list is empty, make this node the head
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the end of the list
    }
    temp->next = newNode; // Link the new node at the end
}

// Function to swap the data of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the linked list using Bubble Sort
void sort(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current;
    struct Node* nextNode;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (current != NULL && current->next != NULL) {
            nextNode = current->next;

            // Compare the current node with the next node
            if (current->data > nextNode->data) {
                swap(current, nextNode);  // Swap the data
                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);  // Continue until no swaps are made
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Sorted Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int size, data;
    struct Node* head = NULL;

    // Input the size of the linked list
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    // Input the elements of the linked list
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data);
        appendNode(&head, data);
    }

    // Sort the linked list
    sort(head);

    // Print the sorted linked list
    printList(head);

    return 0;
}
