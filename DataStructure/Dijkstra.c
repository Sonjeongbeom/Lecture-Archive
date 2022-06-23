# include <stdio.h>
# include <stdlib.h>

const int INF = (int) 2e9;

typedef struct Node {
	int vertex;
	int dist;
	int prev;
} Node;

typedef struct Graph {
	int size;
	Node* nodes;
	int** matrix;
} Graph;

Graph* createGraph(int X);
Graph* findShortestPath(Graph* G, int s);
void printShortestPath(Graph* G);

typedef struct Heap {
	int capacity;
	int size;
	Node* elements;
} Heap;

Heap* createHeap(int X);
void insert(Heap* H, Node N);
Node deleteMin(Heap* H);
void decreaseKey(Heap* H, Node N);


int main(int argc, char* argv[]) {
	FILE *fi = fopen(argv[1], "r");
	int size;

	fscanf(fi, "%d", &size);

	Graph* G = createGraph(size);

	int node_s, node_d, weight;
	
	while (fscanf(fi, "%d %d %d", &node_s, &node_d, &weight) != EOF) {
		G->matrix[node_s][node_d] = weight;
	}

	G = findShortestPath(G, 1);

	printShortestPath(G);

	return 0;
}


Graph* createGraph(int X) {
	
	Graph* graph = (Graph*) malloc(sizeof(Graph*));
	graph->size = X+1;
	graph->nodes = (Node*) malloc(sizeof(Node)*graph->size);
	graph->matrix = (int**) malloc(sizeof(int*)*graph->size);

	for (int i = 1; i < graph->size; i++) {
		graph->matrix[i] = (int*) malloc(sizeof(int*)*graph->size);

		graph->nodes[i].vertex = i;
		graph->nodes[i].dist = INF;
		graph->nodes[i].prev = 0; // null
	}

	return graph;
}

Heap* createHeap(int X) {
	Heap* heap = (Heap*) malloc(sizeof(Heap*));
	heap->capacity = X+1;
	heap->size = 0;	
	heap->elements = (Node*) malloc(sizeof(Node)*heap->capacity);
	return heap;
}

void insert(Heap* heap, Node N) {
	if (heap->size == heap->capacity) {
		printf("Insertion Error: Max Heap is full.\n");
	}
	else {
		int i;
		for (i = ++heap->size; heap->elements[i/2].vertex > N.vertex; i/=2) {
			heap->elements[i] = heap->elements[i/2];
		}
		heap->elements[i] = N;
	}
}

Node deleteMin(Heap* H) {
	int i, child;
	Node min, last;

	min = H->elements[1];
	last = H->elements[H->size--];

	for (i = 1; i*2 <= H->size; i = child){
		child = i * 2;
		if (child != H->size && H->elements[child+1].vertex < H->elements[child].vertex) {
			child++;
		}

		if (last.vertex > H->elements[child].vertex) {
			H->elements[i] = H->elements[child];
		}

		else {
			break;
		}
	}

	H->elements[i] = last;
	return min;
}

Graph* findShortestPath(Graph* G, int s) {
	G->nodes[s].dist = 0; // s = 1
	G->nodes[s].prev = s;

	for (int i = 1; i < G->size; i++) {
		if (G->matrix[s][i] != 0) {
			G->nodes[i].dist = G->matrix[s][i];
			G->nodes[i].prev = s;
		}
	}

	Heap* H = createHeap(G->size-1);

	// add each node to priority queue;
	for (int i = 1; i < G->size; i++) {
		insert(H, G->nodes[i]);
	}
	
	while (H->size != 0) {
		Node min = deleteMin(H);
		for (int i = 1; i < G->size; i++) {
			if (G->matrix[min.vertex][i] != 0) {
				if (G->nodes[min.vertex].dist + G->matrix[min.vertex][i] < G->nodes[i].dist) {
					G->nodes[i].dist = G->nodes[min.vertex].dist + G->matrix[min.vertex][i];
					G->nodes[i].prev = G->nodes[min.vertex].vertex;
					decreaseKey(H, G->nodes[i]);
				}
			}
		}
	}

	return G;
}

void decreaseKey(Heap* H, Node N) {
	int i = N.vertex;
	Node tmp;
	while (H->elements[i].vertex < H->elements[i/2].vertex) {
		tmp = H->elements[i];
		H->elements[i] = H->elements[i/2];
		H->elements[i/2] = tmp;
		i /= 2;
	}
}

void printShortestPath(Graph* G) {
	for (int i = 1; i < G->size; i++) {
		if (i != 1) {
			printf("%d", G->nodes[i].vertex);
			int j = i;
			while (1) {
				if (G->nodes[i].dist == INF) {
					printf(" cannot be reached.\n");
					break;
				}

				printf("<-%d", G->nodes[j].prev);
				j = G->nodes[j].prev;

				if (j == 1) {
					printf(" cost: %d\n", G->nodes[i].dist);
					break;
				}
			}
		}
	}
}
