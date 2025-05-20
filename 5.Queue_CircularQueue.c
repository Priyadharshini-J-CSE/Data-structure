#include <stdio.h>
#include <stdlib.h>

// Structure for Circular Queue
struct CircularQueue {
    int front, rear, size;
    int *arr;  // Dynamic array
};

// Function to initialize the queue
void initialize(struct CircularQueue *q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));  // Dynamic memory allocation
}

// Function to check if the queue is full
int isFull(struct CircularQueue *q) {
    return (q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *q) {
    return q->front == -1;
}

// Function to insert an element into the queue
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) q->front = 0; // First insertion
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
    printf("%d inserted into queue.\n", value);
}

// Function to remove an element from the queue
void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d removed from queue.\n", q->arr[q->front]);
    if (q->front == q->rear) { // Only one element was present
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
}

// Function to get the first element
void getFirst(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("First element: %d\n", q->arr[q->front]);
}

// Function to get the last element
void getLast(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Last element: %d\n", q->arr[q->rear]);
}

// Function to display the queue elements
void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    struct CircularQueue cq;
    int choice, value, size;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    initialize(&cq, size);  // Initializing queue with dynamic memory

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Get First Element\n4. Get Last Element\n5. Display Queue\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 2:
                dequeue(&cq);
                break;
            case 3:
                getFirst(&cq);
                break;
            case 4:
                getLast(&cq);
                break;
            case 5:
                display(&cq);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
