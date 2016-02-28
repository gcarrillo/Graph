//
//  graph.h
//  Graph
//
//  Created by Gabriel Carrillo on 2/27/16.
//  Copyright © 2016 Gabriel Carrillo. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES    1000

typedef struct edgenode {
    int y;  // vertex value
    int weight; // edge weight
    struct edgenode *next;
} edgenode_t;

typedef struct graph {
    edgenode_t *edges[MAX_VERTICES + 1];    // indexing not zero based, so plus one
    int degree[MAX_VERTICES + 1];
    int vertex_count;
    int edge_count;
    bool directed;
} graph_t;

graph_t *graph_create(bool directed);
void graph_read(graph_t *g, bool directed);
void graph_insert_edge(graph_t *g, int x, int y, bool directed);
void graph_print(graph_t *g);
void graph_bfs(graph_t *g, int start);

#endif /* graph_h */
