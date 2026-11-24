#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *create(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    return p;
}
void insert(struct node **h, int x) {
    struct node *p = create(x), *t = *h;
if (*h == NULL) {
    *h = p;
return;
}
while (t->next != NULL)
    t = t->next;
    t->next = p;
}
void display(struct node *h) {
    while (h != NULL) {
    printf("%d ", h->data);
    h = h->next;
    }
    printf("\n");
}
void sort(struct node *h) {
    struct node *i, *j;
    int t;
    for (i = h; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
}
struct node *reverse(struct node *h) {
    struct node *p = NULL, *q, *r;
    q = h;
while (q != NULL) {
    r = q->next;
    q->next = p;
    p = q;
    q = r;
}
return p;
}
struct node *concat(struct node *h1, struct node *h2) {
    struct node *t = h1;
    if (h1 == NULL) return h2;
        while (t->next != NULL)
            t = t->next;
            t->next = h2;
        return h1;
}
int main() {
    struct node *a = NULL, *b = NULL;
    int n, x, i;
printf("Enter number of elements in list 1: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
    scanf("%d", &x);
    insert(&a, x);
}
printf("List: ");
display(a);
sort(a);
printf("Sorted: ");
display(a);
a = reverse(a);
printf("Reversed: ");
display(a);
printf("Enter number of elements in list 2: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
    scanf("%d", &x);
    insert(&b, x);
}
a = concat(a, b);
printf("Concatenated: ");
display(a);
return 0;
}

