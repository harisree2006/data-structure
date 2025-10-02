#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

int isEmpty() {
    return (rear == NULL);
}

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;

    if (rear == NULL) { // Queue is empty
        rear = newNode;
        rear->next = rear;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into the circular queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = rear->next; 
    if (rear->next == rear) { 
        rear = NULL;
    } else {
        rear->next = temp->next;
    }
    printf("Dequeued %d from the circular queue.\n", temp->data);
    free(temp);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element is: %d\n", rear->next->data);
}

void displayQueue() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
        return;
    }
    struct Node* temp = rear->next;
    printf("Circular Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n    Circular Queue using Linked List   \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                displayQueue();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
