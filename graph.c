#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int no_vertices;

void readgraph(struct node *ad[]);
void printgraph(struct node *ad[]);
void bfs(struct node *ad[], int start, int visited[]);
void dfs(struct node *ad[], int start, int visited[]);
void freeGraph(struct node *ad[]);

int main() {
    int i, ch, start;
    printf("Enter the total number of vertices: ");
    scanf("%d", &no_vertices);

    int visited[no_vertices];
    struct node *adj[no_vertices];
    for (i = 0; i < no_vertices; i++) {
        adj[i] = NULL;
    }
    readgraph(adj);

    do {
        printf("\nEnter 1 for BFS\nEnter 2 for DFS\nEnter 3 to Print the adjacency list\nEnter 4 to Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the starting vertex: ");
                scanf("%d", &start);
                if (start < 0 || start >= no_vertices) {
                    printf("Invalid vertex. Please try again.\n");
                    break;
                }
                for (int k = 0; k < no_vertices; k++)
                    visited[k] = 0;
                printf("BFS: ");
                bfs(adj, start, visited);
                break;

            case 2:
                printf("Enter the starting vertex: ");
                scanf("%d", &start);
                if (start < 0 || start >= no_vertices) {
                    printf("Invalid vertex. Please try again.\n");
                    break;
                }
                for (int k = 0; k < no_vertices; k++)
                    visited[k] = 0;
                printf("DFS: ");
                dfs(adj, start, visited);
                break;

            case 3:
                printgraph(adj);
                break;

            case 4:
                freeGraph(adj);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 4);

    return 0;
}

void readgraph(struct node *ad[]) {
    struct node *newnode;
    int i, j, k, data;

    for (i = 0; i < no_vertices; i++) {
        struct node *last = NULL;
        printf("\nEnter the number of neighbours of %d: ", i);
        scanf("%d", &k);

        for (j = 0; j < k; j++) {
            printf("Enter the value of neighbour %d of %d: ", j, i);
            scanf("%d", &data);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = NULL;
            if (ad[i] == NULL) {
                ad[i] = newnode;
            } else {
                last->next = newnode;
            }
            last = newnode;
        }
    }
}

void printgraph(struct node *ad[]) {
    struct node *ptr;
    for (int i = 0; i < no_vertices; i++) {
        ptr = ad[i];
        printf("\nThe neighbours of %d are: ", i);
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

void bfs(struct node *ad[], int start, int visited[]) {
    int queue[no_vertices], front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;
    printf("%d\t", start);

    while (front < rear) {
        struct node *ptr = ad[queue[++front]];
        while (ptr != NULL) {
            if (!visited[ptr->data]) {
                queue[++rear] = ptr->data;
                visited[ptr->data] = 1;
                printf("%d\t", ptr->data);
            }
            ptr = ptr->next;
        }
    }
}

void dfs(struct node *ad[], int start, int visited[]) {
    visited[start] = 1;
    printf("%d\t", start);
    struct node *ptr = ad[start];
    while (ptr != NULL) {
        if (!visited[ptr->data]) {
            dfs(ad, ptr->data, visited);
        }
        ptr = ptr->next;
    }
}

void freeGraph(struct node *ad[]) {
    for (int i = 0; i < no_vertices; i++) {
        struct node *current = ad[i];
        while (current != NULL) {
            struct node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}
