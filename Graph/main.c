//
//  main.c
//  Graph
//
//  Created by Gabriel Carrillo on 2/27/16.
//  Copyright © 2016 Gabriel Carrillo. All rights reserved.
//

/*
 Sample input:
 
 5 7
 1 2
 1 5
 2 5
 2 4
 2 3
 3 4
 4 5
 */

#include <stdio.h>
#include "queue.h"
#include "graph.h"

void test_queue() {
    int test;
    
    queue_t *myqueue = queue_create();
    
    queue_enqueue(myqueue, 1);
    queue_enqueue(myqueue, 2);
    queue_enqueue(myqueue, 3);
    queue_enqueue(myqueue, 4);
    queue_enqueue(myqueue, 5);
    
    while (!queue_is_empty(myqueue)) {
        test = queue_dequeue(myqueue);
        printf("test = %d\n", test);
    }
    
    queue_destroy(myqueue);
}

int main(int argc, const char * argv[]) {
    bool directed = false;
    
    printf("Please input data for graph:\n");
    
    //test_queue();
    
    graph_t *g = graph_create(directed);
    graph_read(g, directed);
    graph_print(g);
    graph_bfs(g, 1);
    
    return 0;
}
