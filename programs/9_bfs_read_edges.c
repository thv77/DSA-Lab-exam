#include <stdio.h>
#define MAX 20

int main() {
    int adj[MAX][MAX], visited[MAX], queue[MAX], seq[MAX];
    int edges[MAX * MAX][2];
    int n = 0, e = 0, cnt = 0, built = 0, performed = 0;
    int start, front, rear, v, u, i, j, ch;

    do {
        printf("\n--- BFS Menu ---\n"
               "1. Read vertices and edges\n"
               "2. Construct adjacency matrix\n"
               "3. Perform BFS\n"
               "4. Display the traversal sequence\n"
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
                break;
            }
            printf("Number of edges: ");
            scanf("%d", &e);
            if (e < 0 || e > MAX * MAX) {
                printf("Invalid number of edges.\n");
                e = 0;
                break;
            }
            printf("Enter each edge as 'u v' (vertices 0 to %d):\n", n - 1);
            for (i = 0; i < e; i++) {
                scanf("%d %d", &edges[i][0], &edges[i][1]);
            }
            built = 0;
            performed = 0;
            break;

        case 2:
            if (n == 0) {
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
                adj[u][v] = 1;
                adj[v][u] = 1; /* undirected graph */
            }
            built = 1;
            performed = 0;
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
            printf("Starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);
            if (start < 0 || start >= n) {
                printf("Invalid vertex.\n");
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
            performed = 1;
            printf("BFS completed.\n");
            break;

        case 4:
            if (!performed) {
                printf("Perform BFS first.\n");
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
