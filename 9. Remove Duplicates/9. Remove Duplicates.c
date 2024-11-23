// by : featas cherif
#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
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

// Function to remove duplicate elements from the linked list
void remove_duplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        struct Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Duplicate found, remove it
                struct Node* duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int size, data;
    struct Node* head = NULL;

    // Input the size of the linked list
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    // Input the elements of the linked list
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data);
        appendNode(&head, data);
    }

    // Remove duplicates from the linked list
    remove_duplicates(head);

    // Print the updated linked list
    printf("list after removing duplicates:\n");
    printList(head);

    return 0;
}

