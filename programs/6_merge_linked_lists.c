#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head[2] = {NULL, NULL};
    struct Node *newnode, *p, *a, *b, *tail, *merged;
    struct Node dummy;
    int w, i, n, v;

    /* Read both lists; each is kept in ascending order while inserting */
    for (w = 0; w < 2; w++) {
        printf("Number of nodes in list %d: ", w + 1);
        scanf("%d", &n);
        printf("Enter %d values: ", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &v);
            newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->data = v;
            newnode->next = NULL;
            if (head[w] == NULL || v < head[w]->data) {
                newnode->next = head[w];
                head[w] = newnode;
            } else {
                p = head[w];
                while (p->next != NULL && p->next->data <= v) {
                    p = p->next;
                }
                newnode->next = p->next;
                p->next = newnode;
            }
        }
    }

    for (w = 0; w < 2; w++) {
        printf("List %d (sorted): ", w + 1);
        if (!head[w]) {
            printf("(empty)");
        }
        for (p = head[w]; p != NULL; p = p->next) {
            printf("%d%s", p->data, p->next ? " -> " : "");
        }
        printf("\n");
    }

    /* Merge the two sorted lists by relinking nodes */
    a = head[0];
    b = head[1];
    tail = &dummy;
    dummy.next = NULL;
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != NULL) ? a : b;
    merged = dummy.next;

    printf("Merged list:     ");
    if (!merged) {
        printf("(empty)");
    }
    for (p = merged; p != NULL; p = p->next) {
        printf("%d%s", p->data, p->next ? " -> " : "");
    }
    printf("\n");

    while (merged) {
        p = merged;
        merged = merged->next;
        free(p);
    }
    return 0;
}