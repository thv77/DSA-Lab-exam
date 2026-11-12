#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *top = NULL, *newnode, *p;
    int ch, v;
    do {
        printf("\n--- Stack Menu ---\n1. Push\n2. Pop\n3. Peek\n4. Display\n"
               "5. Check underflow\n6. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                newnode = (struct Node *)malloc(sizeof(struct Node));
                if (!newnode) {
                    printf("Memory allocation failed.\n");
                    break;
                }
                printf("Enter value: ");
                scanf("%d", &v);
                newnode->data = v;
                newnode->next = top;
                top = newnode;
                printf("%d pushed.\n", v);
                break;
            case 2:
                if (top == NULL) {
                    printf("Stack Underflow!\n");
                    break;
                }
                p = top;
                printf("Popped: %d\n", p->data);
                top = top->next;
                free(p);
                break;
            case 3:
                if (top == NULL) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Top element: %d\n", top->data);
                }
                break;
            case 4:
                if (top == NULL) {
                    printf("Stack is empty.\n");
                    break;
                }
                printf("Stack (top to bottom): ");
                for (p = top; p != NULL; p = p->next) {
                    printf("%d ", p->data);
                }
                printf("\n");
                break;
            case 5:
                if (top == NULL) {
                    printf("Underflow: stack is empty.\n");
                } else {
                    printf("No underflow: stack has elements.\n");
                }
                break;
            case 6:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 6);
    while (top) {
        p = top;
        top = top->next;
        free(p);
    }
    return 0;
}