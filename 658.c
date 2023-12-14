#include <stdio.h>  
  
#define MAXN 100  
#define MAXM 1000  
  
int n, m;  
int graph[MAXN][MAXN];  
  
int dfs(int u, int visited[], int path[], int *path_len) {    
    visited[u] = 1;  
    path[*path_len] = u; 
    (*path_len)++;

    if (u == n) {  
        return 1;  
    } 
      
    for (int v = 1; v <= n; v++) {  
        if (graph[u][v] && !visited[v]) {  
            if (dfs(v, visited, path, path_len)){
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

    int path[MAXN];  
    int path_len = 0;  
    if (dfs(1, visited, path, &path_len)) {  
        printf("YES\n");  
        for (int i = 0; i < path_len; i++) {  
            printf("%d ", path[i]);  
        }    
    } else {  
        printf("NO");  
    }  
    return 0;  
}

