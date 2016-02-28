//
//  queue.h
//  Graph
//
//  Created by Gabriel Carrillo on 2/27/16.
//  Copyright © 2016 Gabriel Carrillo. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>

typedef struct qnode {
    int item;
    struct qnode *next;
} qnode_t;

typedef struct queue {
    qnode_t *head;
    qnode_t *tail;
    int size;
} queue_t;

queue_t *queue_create();
void queue_enqueue(queue_t *q, int item);
bool queue_is_empty(queue_t *q);
int queue_dequeue(queue_t *q);
void queue_destroy(queue_t *q);

#endif /* queue_h */
