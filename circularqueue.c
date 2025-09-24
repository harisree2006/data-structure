#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int que[MAXSIZE];
int front = -1, rear = -1;

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (front==0&&rear == MAXSIZE - 1||rear==front-1)
        return 1;
    else
        return 0;
}

int peek()
{
          if (isEmpty())
                    return -999;
          else
                    return que[front];
}


void Enqueue(int item) {  
    if (isFull()) {
        printf("Queue is full. Can't insert.\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear=(rear+1)%MAXSIZE;
    que[rear] = item;
    printf("Inserted item: %d\n", item);
}

void Dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Can't delete.\n");
        return;
    }
    int item = que[front];
    if (front == rear)
        front = rear = -1;
    else
        front=(front+1)%MAXSIZE;
    printf("Deleted item: %d\n", item);
}

void Display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i=front;
    while(1)
    {
          printf("%d ",que[i]);
          if(i==rear)
                    break;
          i = (i+1)%MAXSIZE;
    }
    printf("\n");
}

int main() {
    int choice, item;

    do {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n7. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                Enqueue(item);  
                break;

            case 2:
                Dequeue();
                break;

            case 3 :
                item=peek();
                if(item==-999)
                    printf("Queue is empty. No front element is found");
                else
                    printf("Front element is %d\n ",item);
            
            case 4:
                Display();
                break;

            case 5:
                if (isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 6:
                if (isFull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
