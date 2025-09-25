#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global head and tail pointers
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertAtFront(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the front.\n");
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a node after a specific node
void insertAfterNode(int afterValue, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", afterValue);
        return;
    }

    if (temp == tail) {
        insertAtEnd(value);
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printf("Node inserted after %d.\n", afterValue);
}

// Function to delete the first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // The list is now empty
    }
    free(temp);
    printf("First node deleted.\n");
}

// Function to delete the last node
void deleteLast() {
    if (tail == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; // The list is now empty
    }
    free(temp);
    printf("Last node deleted.\n");
}

// Function to delete a specific node
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", value);
        return;
    }

    if (temp == head) {
        deleteFirst();
        return;
    }
    if (temp == tail) {
        deleteLast();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Node with data %d deleted.\n", value);
}

// Function to search for a node
void searchNode(int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
        position++;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", value);
    } else {
        printf("Node with data %d found at position %d.\n", value, position);
    }
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, afterValue;

    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete a specific Node\n");
        printf("7. Search for a Node\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value after which to insert: ");
                scanf("%d", &afterValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfterNode(afterValue, value);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
