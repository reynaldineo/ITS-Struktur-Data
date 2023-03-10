#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tnode_t
{
    int id, priority;
    struct tnode_t *next;
}pQueueNode;

typedef struct priorQueue
{
    pQueueNode *top;
}PriorityQueue;

void init(PriorityQueue *ipq)
{
    ipq->top = 0;
}

bool pq_isEmpty(PriorityQueue *ipq)
{
    return(ipq->top == 0);
}

void pq_push(PriorityQueue *ipq, int id, int prior)
{
    pQueueNode *temp = ipq->top;
    pQueueNode *newNode = (pQueueNode*)malloc(sizeof(pQueueNode));
    newNode->id = id;
    newNode->priority = prior;
    newNode->next = NULL;
    
    if(pq_isEmpty(ipq))
    {
        ipq->top = newNode;
    }
    else
    {
        if(prior > ipq->top->priority)
        {
            newNode->next = ipq->top;
            ipq->top = newNode;
        }
        else
        {
            while(temp->next != NULL && prior < temp->next->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void pq_pop(PriorityQueue *ipq)
{
    if(!pq_isEmpty(ipq))
    {
        pQueueNode *temp = ipq->top;
        ipq->top = ipq->top->next;
        free(temp);
    }
}

void pq_layani(PriorityQueue *ipq)
{
    if(pq_isEmpty(ipq))
        puts("HORE");
    else
    {
        printf("%d\n", ipq->top->id);
        pq_pop(ipq);
    }
}

int main()
{
    PriorityQueue pq;
    init(&pq);
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a,b;
        char order[10];
        scanf("%s", order);
        if(!strcmp(order, "MASUK"))
        {
            scanf("%d %d", &a, &b);
            pq_push(&pq, a, b);
        }
        else if(!strcmp(order, "LAYANI"))
            pq_layani(&pq);
    }
}