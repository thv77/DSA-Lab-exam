#include <stdio.h>
#define MAX 20

int main() {
    int adj[MAX][MAX], visited[MAX], queue[MAX], seq[MAX];
    int n = 0, start = -1, haveMatrix = 0;
    int front, rear, cnt, v, i, j, ch;

    do {
        printf("\n--- BFS Menu ---\n"
               "1. Read number of vertices\n"
               "2. Read adjacency matrix\n"
               "3. Read starting vertex\n"
               "4. Display the BFS sequence\n"
               "5. Exit\n"
               "Choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Number of vertices (max %d): ", MAX);
            scanf("%d", &n);
            if (n < 1 || n > MAX) {
                printf("Invalid number of vertices.\n");
                n = 0;
            }
            haveMatrix = 0;
            break;

        case 2:
            if (n == 0) {
                printf("Read vertices first.\n");
                break;
            }
            printf("Enter %dx%d adjacency matrix:\n", n, n);
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    scanf("%d", &adj[i][j]);
                }
            }
            haveMatrix = 1;
            break;

        case 3:
            if (n == 0) {
                printf("Read vertices first.\n");
                break;
            }
            printf("Starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);
            break;

        case 4:
            if (n == 0 || !haveMatrix || start < 0 || start >= n) {
                printf("Provide vertices, matrix and a valid start vertex first.\n");
                break;
            }
            for (i = 0; i < n; i++) {
                visited[i] = 0;
            }
            front = 0;
            rear = 0;
            cnt = 0;

            visited[start] = 1;
            queue[rear] = start;
            rear++;

            while (front < rear) {
                v = queue[front];
                front++;
                seq[cnt] = v;
                cnt++;
                for (i = 0; i < n; i++) {
                    if (adj[v][i] == 1 && !visited[i]) {
                        visited[i] = 1;
                        queue[rear] = i;
                        rear++;
                    }
                }
            }

            printf("BFS sequence: ");
            for (i = 0; i < cnt; i++) {
                printf("%d ", seq[i]);
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
