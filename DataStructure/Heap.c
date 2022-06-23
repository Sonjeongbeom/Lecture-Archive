# include <stdio.h>
# include <stdlib.h>

typedef struct HeapStruct* Heap;
struct HeapStruct {
	int capacity;
	int size;
	int* elements;
};

Heap CreateHeap(int heapSize);
void Insert(Heap heap, int value);
int Find(Heap heap, int value);
void DeleteMax(Heap heap);
void PrintHeap(Heap heap);
void FreeHeap(Heap heap);

void main(int argc, char* argv[]) {

	FILE *fi = fopen(argv[1], "r");
	char cv;
	Heap maxHeap;
	int value, maxValue;

	while (!feof(fi)) {
		fscanf(fi, "%c", &cv);
		switch(cv) {
			case 'n' :
				fscanf(fi, "%d", &value);
				maxHeap = CreateHeap(value);
				break;
			case 'i' :
				fscanf(fi, "%d", &value);
				Insert(maxHeap, value);
				break;
			case 'd' :
				DeleteMax(maxHeap);
				break;
			case 'f' :
				fscanf(fi, "%d", &value);
				if (Find(maxHeap, value)) {
					printf("%d is in the heap.\n", value);
				}
				else {
					printf("%d is not in the heap.\n", value);
				}
				break;
			case 'p' :
				PrintHeap(maxHeap);
		}
	}
	FreeHeap(maxHeap);
}



Heap CreateHeap(int heapSize) {
	Heap heap = (Heap) malloc(sizeof(Heap));
	heap->capacity = heapSize;
	heap->size = 0;
	heap->elements =(int*) malloc(sizeof(int) * heap->capacity);
	return heap;
}



void Insert(Heap heap, int value) {
	
	if (heap->size == heap->capacity) {
		printf("Insertion Error: Max Heap is full.\n");
	}
	else if (Find(heap, value)) {
		printf("%d is already in the heap.\n", value);
	}

	else {
		int i;
		for (i = ++heap->size; heap->elements[i/2] < value; i/=2) {
			if (i == 1) {
				break;
			}
			else {
				heap->elements[i] = heap->elements[i/2];
			}
		}
		heap->elements[i] = value;
		printf("Insert %d\n", heap->elements[i]);
	}
}


int Find(Heap heap, int value) {
	for (int i = 1; i < heap->size+1; i++) {
		if (heap->elements[i] == value) {
			return 1;
		}
	}
	return 0;
}


void PrintHeap(Heap heap) {
	if (heap->size == 0) {
		printf("Max Heap is empty!\n");
	}

	else {
		for (int i = 1; i < heap->size+1; i++) {
			printf("%d ", heap->elements[i]);
		}
		printf("\n");
	}
}

void DeleteMax(Heap heap) {

	if (heap->size == 0) {
		printf("Deletion Error: Max Heap is empty!\n");
	}

	else {
		int max, last;
		int i, child;

		max = heap->elements[1];
		last = heap->elements[heap->size--];
	
		for (i = 1; i*2 < heap->size+1; i = child) {
			child = i * 2;
			if (child != heap->size && heap->elements[child+1] > heap->elements[child]) {
				child++;
			}
	
			if (last < heap->elements[child]) {
				heap->elements[i] = heap->elements[child];
			}

			else {
				break;
			}
		}

		heap->elements[i] = last;
		printf("Max element(%d) deleted.\n", max);
	}	
}

void FreeHeap(Heap heap) {
	free(heap->elements);
}
