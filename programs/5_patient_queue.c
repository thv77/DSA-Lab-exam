#include <stdio.h>
#include <stdlib.h>

struct Patient {
    int id;
    struct Patient *next;
};

int main() {
    struct Patient *front = NULL, *rear = NULL, *p;
    int ch;
    do {
        printf("\n--- Patient Queue Menu ---\n1. Add patient ID\n2. Delete patient ID\n"
               "3. Display patient at front\n4. Display all patients\n5. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                p = (struct Patient *)malloc(sizeof(struct Patient));
                if (!p) {
                    printf("Memory allocation failed.\n");
                    break;
                }
                printf("Enter patient ID: ");
                scanf("%d", &p->id);
                p->next = NULL;
                if (rear == NULL) {
                    front = rear = p;
                } else {
                    rear->next = p;
                    rear = p;
                }
                printf("Patient %d added.\n", p->id);
                break;
            case 2:
                if (front == NULL) {
                    printf("Queue is empty. No patient to delete.\n");
                    break;
                }
                p = front;
                printf("Patient %d removed.\n", p->id);
                front = front->next;
                if (front == NULL) {
                    rear = NULL;
                }
                free(p);
                break;
            case 3:
                if (front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Patient at front: %d\n", front->id);
                }
                break;
            case 4:
                if (front == NULL) {
                    printf("Queue is empty.\n");
                    break;
                }
                printf("Patients in queue (front to rear): ");
                for (p = front; p != NULL; p = p->next) {
                    printf("%d ", p->id);
                }
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);
    while (front) {
        p = front;
        front = front->next;
        free(p);
    }
    return 0;
}