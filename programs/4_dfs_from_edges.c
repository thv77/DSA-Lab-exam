#include <stdio.h>
#define MAX 20

/* Iterative DFS (explicit stack) so no function / recursion is needed */
int main() {
    int adj[MAX][MAX], visited[MAX], seq[MAX], stack[MAX], nxt[MAX];
    int edges[MAX * MAX][2];
    int n = 0, e = 0, cnt = 0, built = 0, performed = 0;
    int start, top, v, u, i, j, ch;
    do {
        printf(
            "\n--- Graph DFS Menu ---\n1. Read vertices and edges\n2. Construct adjacency matrix\n"
            "3. Perform DFS\n4. Display traversal sequence\n5. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Number of vertices (max %d): ", MAX);
                scanf("%d", &n);
                if (n < 1 || n > MAX) {
                    printf("Invalid.\n");
                    n = 0;
                    break;
                }
                printf("Number of edges: ");
                scanf("%d", &e);
                if (e < 0 || e > MAX * MAX) {
                    printf("Invalid.\n");
                    e = 0;
                    break;
                }
                printf("Enter each edge as 'u v' (vertices 0 to %d):\n", n - 1);
                for (i = 0; i < e; i++) {
                    scanf("%d %d", &edges[i][0], &edges[i][1]);
                }
                built = performed = 0;
                break;
            case 2:
                if (!n) {
                    printf("Read vertices and edges first.\n");
                    break;
                }
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        adj[i][j] = 0;
                    }
                }
                for (i = 0; i < e; i++) {
                    u = edges[i][0];
                    v = edges[i][1];
                    if (u < 0 || u >= n || v < 0 || v >= n) {
                        printf("Skipping invalid edge %d-%d\n", u, v);
                        continue;
                    }
                    adj[u][v] = adj[v][u] = 1; /* undirected graph */
                }
                built = 1;
                printf("Adjacency matrix:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("%d ", adj[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                if (!built) {
                    printf("Construct the adjacency matrix first.\n");
                    break;
                }
                printf("Starting vertex: ");
                scanf("%d", &start);
                if (start < 0 || start >= n) {
                    printf("Invalid vertex.\n");
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
                performed = 1;
                printf("DFS completed.\n");
                break;
            case 4:
                if (!performed) {
                    printf("Perform DFS first.\n");
                    break;
                }
                printf("Traversal sequence: ");
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