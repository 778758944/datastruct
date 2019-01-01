//
//  Queue.c
//  Graph
//
//  Created by Tom Xing on 12/29/18.
//  Copyright © 2018 Tom Xing. All rights reserved.
//
#include <stdlib.h>
#include "Queue.h"

void EnQueue(Queue * q, QueueType data) {
    QueueNode * node = (QueueNode *) malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    if (!q->head) {
        q->head = node;
        q->last = node;
    } else {
        q->last->next = node;
        q->last = node;
    }
}

bool QueueEmpty(Queue * q) {
    return q->head == NULL;
}

void DeQueue(Queue * q, QueueType * t) {
    if (QueueEmpty(q)) return;
    QueueNode * temp = q->head;
    *t = temp->data;
    q->head = temp->next;
    if (q->head == NULL) {
        q->last = NULL;
    }
    free(temp);
}

void initQueue(Queue *q) {
    q->head = NULL;
    q->last = NULL;
}



