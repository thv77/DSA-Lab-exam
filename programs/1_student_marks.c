#include <stdio.h>
#define MAX 100

int main() {
    int marks[MAX], n = 0, ch, i, j, min, t, key, found;
    do {
        printf("\n--- Student Marks Menu ---\n1. Read marks\n2. Selection sort\n"
               "3. Linear search\n4. Display marks\n5. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number of students (max %d): ", MAX);
                scanf("%d", &n);
                if (n < 1 || n > MAX) {
                    printf("Invalid n.\n");
                    n = 0;
                    break;
                }
                for (i = 0; i < n; i++) {
                    printf("Mark of student %d: ", i + 1);
                    scanf("%d", &marks[i]);
                }
                break;
            case 2:
                if (n == 0) {
                    printf("Read marks first.\n");
                    break;
                }
                for (i = 0; i < n - 1; i++) {
                    min = i;
                    for (j = i + 1; j < n; j++) {
                        if (marks[j] < marks[min]) {
                            min = j;
                        }
                    }
                    t = marks[i];
                    marks[i] = marks[min];
                    marks[min] = t;
                }
                printf("Marks sorted.\n");
                break;
            case 3:
                if (n == 0) {
                    printf("Read marks first.\n");
                    break;
                }
                printf("Enter mark to search: ");
                scanf("%d", &key);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (marks[i] == key) {
                        printf("Found at position %d\n", i + 1);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Mark %d not found.\n", key);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("No marks to display.\n");
                    break;
                }
                printf("Marks: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", marks[i]);
                }
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);
    return 0;
}