//
//  Queue.h
//  Graph
//
//  Created by Tom Xing on 12/29/18.
//  Copyright © 2018 Tom Xing. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <stdbool.h>

typedef int QueueType;

typedef struct QueueNode {
    QueueType data;
    struct QueueNode * next;
} QueueNode;


typedef struct {
    QueueNode * head;
    QueueNode * last;
} Queue;

void EnQueue(Queue * q, QueueType data);
bool QueueEmpty(Queue * q);
void DeQueue(Queue * q, QueueType * t);
void initQueue(Queue *q);

#endif /* Queue_h */
