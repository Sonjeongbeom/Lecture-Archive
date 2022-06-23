# include <stdio.h>
# include <stdlib.h>

typedef struct _Queue {
	int size;
	int *key;
	int front;
	int rear;
} Queue;

Queue* CreateQueue(int X);
void Enqueue(Queue *Q, int item);
int Dequeue(Queue *Q);

typedef struct _Graph {
	int size;
	int *vertex;
	int **edge;
} Graph;

Graph* CreateGraph(int X);
void InsertEdge(Graph *G, int u, int v);
void Topsort(Graph *G);

int main(int argc, char *argv[]) {
	FILE *fi = fopen(argv[1], "r");
	int X, u, v;

	fscanf(fi, "%d", &X);

	Graph *G = CreateGraph(X);

	for (int i = 0; i < X; i++) {
		fscanf(fi, "%d", &G->vertex[i]);
	}
	
	while (fscanf(fi, "%d %d", &u, &v) != EOF) {
		InsertEdge(G, u, v);
	}

	Topsort(G);

	return 0;
}

Queue* CreateQueue(int X) {
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->size = X;
	queue->key = (int*) malloc(sizeof(int*) * queue->size);
	queue->front = 0;
	queue->rear = -1;
	
	return queue;
}

void Enqueue(Queue *Q, int item) {
	if (Q->rear == Q->size-1) {
		printf("Queue is full\n");
	}
	Q->key[++Q->rear] = item;
}

int Dequeue(Queue *Q) {
	if (Q->front > Q->rear) {
		printf("Queue is empty\n");
	}

	return Q->key[Q->front++];
}

Graph* CreateGraph(int X) {
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph->size = X;
	graph->vertex = (int*) malloc(sizeof(int*) * graph->size);
	graph->edge = (int**) malloc(sizeof(int*) * graph->size);

	for (int i = 0; i < graph->size; i++) {
		graph->edge[i] = (int*)  malloc (sizeof(int*) * graph->size);
	}

	return graph;
}

void InsertEdge(Graph *G, int u, int v) {
	int idxu, idxv;
	for (int i = 0; i < G->size; i++) {
		if (u == G->vertex[i]) {
			idxu = i;
		}

		if (v == G->vertex[i]) {
			idxv = i;
		}
	}
	G->edge[idxu][idxv] = 1;	
}

void Topsort(Graph *G) {
	Queue* queue = CreateQueue(G->size);

	int *indegree = (int*) malloc(sizeof(int*) * G->size);

	for (int i = 0; i < G->size; i++) {
		for (int j = 0; j < G->size; j++) {
			indegree[i] += G->edge[j][i];
		}
	}


	for (int i = 0; i < G->size; i++) {
		if (indegree[i] == 0) {
			Enqueue(queue, G->vertex[i]);
		}
	}

	while (!(queue->rear < queue->front)) {
		int node = Dequeue(queue);
		printf("%d ", node);

		int nodeIdx;
		for (int i = 0; i < G->size; i++) {
			if (node == G->vertex[i]) {
				nodeIdx = i;
			}
		}

		for (int i = 0; i < G->size; i++) {
			if (G->edge[nodeIdx][i] != 0) {
				if(--indegree[i] == 0) {
					Enqueue(queue, G->vertex[i]);
				}
			}
		}
	}

	printf("\n");
}





