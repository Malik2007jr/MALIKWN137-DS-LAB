#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL, *front = NULL, *rear = NULL;
void push(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = top;
    top = p;
}
void pop() {
    if (top == NULL)
        printf("Stack empty\n");
    else {
        printf("Popped: %d\n", top->data);
    top = top->next;
    }
}
void displayStack() {
    struct node *t = top;
    while (t != NULL) {
        printf("%d ", t->data);
    t = t->next;
    }
printf("\n");
}
void enqueue(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if (rear == NULL)
        front = rear = p;
    else {
        rear->next = p;
        rear = p;
    }
}
void dequeue() {
    if (front == NULL)
        printf("Queue empty\n");
    else {
        printf("Deleted: %d\n", front->data);
        front = front->next;
    if (front == NULL)
        rear = NULL;
    }
}
void displayQueue() {
    struct node *t = front;
    while (t != NULL) {
        printf("%d ", t->data);
    t = t->next;
    }
printf("\n");
}
int main() {
int ch, x;
while (1) {
    printf("\n1.Push 2.Pop 3.Display Stack");
    printf("\n4.Enqueue 5.Dequeue 6.Display Queue");
    printf("\n7.Exit\nChoice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
        scanf("%d", &x);
        push(x);
        break;
        case 2:
        pop();
        break;
        case 3:
        displayStack();
        break;
        case 4:
        scanf("%d", &x);
        enqueue(x);
        break;
        case 5:
        dequeue();
        break;
        case 6:
        displayQueue();
        break;
        case 7:
        return 0;
        default:
        printf("Invalid choice\n");
        }
    }
}

