#include <stdio.h>  
#include <stdlib.h>  
  
#define MAXN 100  
#define MAXM 1000  
  
int n, m;  
int graph[MAXN][MAXN];  
  
int dfs(int u, int visited[]) {  
    if (u == n) {  
        return 1;  
    }  
    visited[u] = 1;  
    for (int v = 1; v <= n; v++) {  
        if (graph[u][v] && !visited[v]) {  
            if (dfs(v, visited)) {  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
  
int main() {  
    scanf("%d %d", &n, &m);  
    for (int i = 0; i < m; i++) {  
        int u, v;  
        scanf("%d %d", &u, &v);  
        graph[u][v] = graph[v][u] = 1;  
    }  
    int visited[MAXN];  
    for (int i = 1; i <= n; i++) {  
        visited[i] = 0;  
    }  
    if (dfs(1, visited)) {  
        printf("YES\n");  
        int path[MAXN];  
        dfs(1, visited);  
        path[0] = 1;  
        int k = 1;  
        for (int i = 1; i < n; i++) {  
            if (visited[i]) {  
                continue;  
            }  
            for (int j = 1; j <= n; j++) {  
                if (graph[i][j] && !visited[j]) {  
                    path[k++] = j;  
                    visited[j] = 1;  
                    break;  
                }  
            }  
        }  
        for (int i = 0; i < k; i++) {  
            printf("%d ", path[i]);  
        }  
        printf("\n");  
    } else {  
        printf("NO\n");  
    }  
    return 0;  
}