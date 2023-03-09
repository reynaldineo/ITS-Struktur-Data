#include <stdio.h>
#include <stdlib.h>

// Struktur data untuk merepresentasikan node dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Struktur data untuk merepresentasikan queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Fungsi untuk inisialisasi queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Fungsi untuk memeriksa apakah queue kosong
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Fungsi untuk menambahkan elemen ke queue
void enqueue(struct Queue* q, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
    }
    else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

// Fungsi untuk menghapus elemen dari queue
int dequeue(struct Queue* q) {
    struct Node* temp;
    int item;
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    temp = q->front;
    item = temp->data;
    q->front = temp->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return item;
}

// Fungsi untuk mendapatkan elemen pada posisi depan queue
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

// Fungsi utama
int main() {
    struct Queue q;
    int item;

    initQueue(&q);

    // Menambahkan elemen ke queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Menghapus elemen dari queue
    item = dequeue(&q);
    printf("Dequeued item: %d\n", item);

    // Menambahkan elemen baru ke queue
    enqueue(&q, 40);

    // Mendapatkan elemen pada posisi depan queue
    item = front(&q);
    printf("Front item: %d\n", item);

    return 0;
}