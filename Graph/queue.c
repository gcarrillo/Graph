//
//  queue.c
//  Graph
//
//  Created by Gabriel Carrillo on 2/27/16.
//  Copyright © 2016 Gabriel Carrillo. All rights reserved.
//

#include <stdlib.h>
#include <stddef.h>
#include "queue.h"

queue_t *queue_create() {
    queue_t *q;
    
    q = (queue_t *)calloc(1, sizeof(queue_t));
    q->tail = q->head = NULL;
    q->size = 0;
    
    return q;
}

bool queue_is_empty(queue_t *q) {
    return (q->size == 0) ? true : false;
}

void queue_enqueue(queue_t *q, int item) {
    qnode_t *new_node;
    
    new_node = (qnode_t *)calloc(1, sizeof(qnode_t));
    new_node->item = item;
    
    if (q->head == NULL && q->tail == NULL) {
        // empty queue
        q->tail = q->head = new_node;
        // next pointer already null
    } else {
        // queue with one or more nodes
        new_node->next = q->tail->next;
        q->tail->next = new_node;
        q->tail = new_node;
    }
    
    q->size++;
}

int queue_dequeue(queue_t *q) {
    int item;
    qnode_t *tmp;
    
    if (q->head == NULL) {
        item = -1;
    } else {
        tmp = q->head;
        q->head = tmp->next;
        
        // Handle case of only one item in queue.
        if (q->tail == tmp) {
            q->tail = tmp->next;
        }
        
        item = tmp->item;
        free(tmp);
    }
    
    q->size--;
    
    return item;
}

void queue_destroy(queue_t *q) {
    qnode_t *next_node;
    qnode_t *cur_node;
    
    next_node = q->head;
    while (next_node) {
        cur_node = next_node;
        next_node = cur_node->next;
        free(cur_node);
    }
    
    free(q);
}