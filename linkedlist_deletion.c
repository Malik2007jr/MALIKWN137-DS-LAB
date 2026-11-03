#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void create(int x) {
    struct node *n = malloc(sizeof(struct node));
    struct node *t = head;
    n->data = x;
    n->next = NULL;
    if (head == NULL) {
        head = n;
        return;
    }
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}
void deleteFirst() {
    struct node *t;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    t = head;
    head = head->next;
    free(t);
}
void deleteElement(int x) {
    struct node *t = head, *p = NULL;
    while (t != NULL && t->data != x) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        printf("Element not found\n");
        return;
    }
    if (p == NULL)
        head = t->next;
    else
        p->next = t->next;

    free(t);
}
void deleteLast() {
    struct node *t = head, *p = NULL;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    while (t->next != NULL) {
        p = t;
        t = t->next;
    }
    if (p == NULL)
        head = NULL;
    else
        p->next = NULL;
    free(t);
}
void display() {
    struct node *t = head;
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}
int main() {
    int ch, x;
    do {
        printf("\n1.Create Node\n2.Delete First");
        printf("\n3.Delete Element\n4.Delete Last");
        printf("\n5.Display\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                scanf("%d", &x);
                create(x);
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                scanf("%d", &x);
                deleteElement(x);
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
        }
    }
    while (ch != 6);
    return 0;
}
