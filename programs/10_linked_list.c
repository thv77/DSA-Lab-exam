#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newnode, *p, *prev, *next;
    int ch, value, pos, count, i, found;

    do {
        printf("\n--- Singly Linked List Menu ---\n"
               "1. Insert at beginning\n"
               "2. Insert at end\n"
               "3. Insert at position\n"
               "4. Delete from beginning\n"
               "5. Delete from end\n"
               "6. Delete at position\n"
               "7. Search\n"
               "8. Display\n"
               "9. Reverse\n"
               "10. Exit\n"
               "Choice: ");
        scanf("%d", &ch);

        /* count the nodes currently in the list */
        count = 0;
        for (p = head; p != NULL; p = p->next) {
            count++;
        }

        switch (ch) {
        case 1:
            newnode = (struct Node *)malloc(sizeof(struct Node));
            if (newnode == NULL) {
                printf("Memory allocation failed.\n");
                break;
            }
            printf("Enter value: ");
            scanf("%d", &value);
            newnode->data = value;
            newnode->next = head;
            head = newnode;
            printf("%d inserted at beginning.\n", value);
            break;

        case 2:
            newnode = (struct Node *)malloc(sizeof(struct Node));
            if (newnode == NULL) {
                printf("Memory allocation failed.\n");
                break;
            }
            printf("Enter value: ");
            scanf("%d", &value);
            newnode->data = value;
            newnode->next = NULL;
            if (head == NULL) {
                head = newnode;
            } else {
                p = head;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = newnode;
            }
            printf("%d inserted at end.\n", value);
            break;

        case 3:
            printf("Enter position (1 to %d): ", count + 1);
            scanf("%d", &pos);
            if (pos < 1 || pos > count + 1) {
                printf("Invalid position.\n");
                break;
            }
            newnode = (struct Node *)malloc(sizeof(struct Node));
            if (newnode == NULL) {
                printf("Memory allocation failed.\n");
                break;
            }
            printf("Enter value: ");
            scanf("%d", &value);
            newnode->data = value;
            if (pos == 1) {
                newnode->next = head;
                head = newnode;
            } else {
                p = head;
                for (i = 1; i < pos - 1; i++) {
                    p = p->next;
                }
                newnode->next = p->next;
                p->next = newnode;
            }
            printf("%d inserted at position %d.\n", value, pos);
            break;

        case 4:
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            p = head;
            printf("Deleted %d from beginning.\n", p->data);
            head = head->next;
            free(p);
            break;

        case 5:
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            if (head->next == NULL) {
                printf("Deleted %d from end.\n", head->data);
                free(head);
                head = NULL;
                break;
            }
            p = head;
            while (p->next->next != NULL) {
                p = p->next;
            }
            printf("Deleted %d from end.\n", p->next->data);
            free(p->next);
            p->next = NULL;
            break;

        case 6:
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            printf("Enter position (1 to %d): ", count);
            scanf("%d", &pos);
            if (pos < 1 || pos > count) {
                printf("Invalid position.\n");
                break;
            }
            if (pos == 1) {
                p = head;
                head = head->next;
            } else {
                prev = head;
                for (i = 1; i < pos - 1; i++) {
                    prev = prev->next;
                }
                p = prev->next;
                prev->next = p->next;
            }
            printf("Deleted %d from position %d.\n", p->data, pos);
            free(p);
            break;

        case 7:
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            printf("Enter value to search: ");
            scanf("%d", &value);
            found = 0;
            pos = 1;
            for (p = head; p != NULL; p = p->next) {
                if (p->data == value) {
                    printf("%d found at position %d.\n", value, pos);
                    found = 1;
                }
                pos++;
            }
            if (!found) {
                printf("%d not found.\n", value);
            }
            break;

        case 8:
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            printf("List (%d nodes): ", count);
            for (p = head; p != NULL; p = p->next) {
                printf("%d", p->data);
                if (p->next != NULL) {
                    printf(" -> ");
                }
            }
            printf("\n");
            break;

        case 9:
            if (head == NULL) {
                printf("List is empty.\n");
                break;
            }
            prev = NULL;
            p = head;
            while (p != NULL) {
                next = p->next;
                p->next = prev;
                prev = p;
                p = next;
            }
            head = prev;
            printf("List reversed.\n");
            break;

        case 10:
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (ch != 10);

    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
    return 0;
}
