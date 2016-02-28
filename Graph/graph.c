//
//  graph.c
//  Graph
//
//  Created by Gabriel Carrillo on 2/27/16.
//  Copyright © 2016 Gabriel Carrillo. All rights reserved.
//

#include <stdlib.h>
#include <stddef.h>
#include "graph.h"
#include "queue.h"

graph_t *graph_create(bool directed) {
    graph_t *g;
    int i;
    
    g = (graph_t *)calloc(1, sizeof(graph_t));
    g->vertex_count = 0;
    g->edge_count = 0;
    g->directed = directed;
    
    for (i = 1; i <= MAX_VERTICES; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
    
    return g;
}

void graph_read(graph_t *g, bool directed) {
    int i;
    int m;
    int x, y;
    
    scanf("%d %d", &(g->vertex_count), &m);
    
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        graph_insert_edge(g, x, y, directed);
    }
}

void graph_insert_edge(graph_t *g, int x, int y, bool directed) {
    edgenode_t *p;
    
    p = (edgenode_t *)calloc(1, sizeof(edgenode_t));
    p->weight = -1;
    p->y = y;
    
    // Insert at head of list.
    p->next = g->edges[x];
    
    g->edges[x] = p;
    g->degree[x]++;
    
    if (directed == false) {
        // Recursively add other direction for undirected graphs.
        graph_insert_edge(g, y, x, true);
    } else {
        g->edge_count++;
    }
}

// Perform a breadth-first traversal of a graph, starting at node "start".
void graph_bfs(graph_t *g, int start) {
    queue_t *q;
    int v;          // current vertex
    int y;          // successor vertex
    edgenode_t *p;  // temporary pointer
    int i;
    bool processed[MAX_VERTICES + 1];
    bool discovered[MAX_VERTICES + 1];
    int parent[MAX_VERTICES + 1];
    
    // Initialize the search.
    for (i = 1; i <= g->vertex_count; i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
    
    q = queue_create();
    queue_enqueue(q, start);
    discovered[start] = true;
    
    while (!queue_is_empty(q)) {
        v = queue_dequeue(q);
        // process_vertex_early(v);
        printf("processed vertex %d\n", v);
        processed[v] = true;
        p = g->edges[v];
        
        while (p != NULL) {
            y = p->y;
            
            if (!discovered[y]) {
                queue_enqueue(q, y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        // process_vertex_late(v);
    }
    
    queue_destroy(q);
}

void graph_print(graph_t *g) {
    int i;
    edgenode_t *p;
    
    for (i = 1; i <= g->vertex_count; i++) {
        printf("%d: ", i);
        p = g->edges[i];
        while (p) {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }
}