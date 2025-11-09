#include <stdio.h>
#define MAX 5   

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int order) {
    if (rear == MAX - 1) {
        printf("\n?? Queue Overflow! No more orders can be taken.\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = order;
    printf("? Order %d added to the queue.\n", order);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\n?? Queue Underflow! No pending orders.\n");
        return;
    }
    printf("?? Order %d served and removed from queue.\n", queue[front]);
    front++;
    if (front > rear)  
        front = rear = -1;
}
void display() {
    if (front == -1) {
        printf("\nNo pending pizza orders.\n");
        return;
    }
    printf("\n?? Current Pizza Orders:\n");
    for (int i = front; i <= rear; i++)
        printf("Order %d\n", queue[i]);
}

int main() {
    int choice, orderNo;

    do {
        printf("\n=== ?? Pizza Parlor Job Queue ===\n");
        printf("1. Add New Order\n");
        printf("2. Serve (Remove) Order\n");
        printf("3. Display Pending Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Order Number: ");
                scanf("%d", &orderNo);
                enqueue(orderNo);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting... ???\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0;
}

