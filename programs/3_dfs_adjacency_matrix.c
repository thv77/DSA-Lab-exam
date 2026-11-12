#include <stdio.h>
#define MAX 20

/* Iterative DFS (explicit stack) so no function / recursion is needed */
int main() {
    int adj[MAX][MAX], visited[MAX], seq[MAX], stack[MAX], nxt[MAX];
    int n = 0, start = -1, cnt = 0, top, v, i, j, ch, haveMatrix = 0;
    do {
        printf("\n--- DFS Menu ---\n1. Read number of vertices\n2. Read adjacency matrix\n"
               "3. Read starting vertex\n4. Display DFS sequence\n5. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Number of vertices (max %d): ", MAX);
                scanf("%d", &n);
                if (n < 1 || n > MAX) {
                    printf("Invalid.\n");
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
                printf("Starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                break;
            case 4:
                if (!n || !haveMatrix || start < 0 || start >= n) {
                    printf("Provide vertices, matrix and a valid start vertex first.\n");
                    break;
                }
                for (i = 0; i < n; i++) {
                    visited[i] = 0;
                    nxt[i] = 0;
                }
                cnt = 0;
                visited[start] = 1;
                seq[cnt++] = start;
                top = 0;
                stack[0] = start;
                while (top >= 0) {
                    v = stack[top];
                    i = nxt[v];
                    while (i < n && !(adj[v][i] && !visited[i])) {
                        i++;
                    }
                    nxt[v] = i + 1;
                    if (i < n) {
                        visited[i] = 1;
                        seq[cnt++] = i;
                        stack[++top] = i;
                    } else {
                        top--;
                    }
                }
                printf("DFS sequence: ");
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