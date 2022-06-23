# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct _DisjointSet {
	int size;
	int *ptr_arr; // parent
} DisjointSets;

typedef struct _PrintDisjointSet {
	int size;
	int *ptr_arr; // wall
} PrintDisjointSets;

void init(DisjointSets *sets, PrintDisjointSets *maze, int n);
int find(DisjointSets *sets, int x);
void union_(DisjointSets *sets, int i, int j);
void createMaze(DisjointSets *sets, PrintDisjointSets *maze, int n);
void printMaze(PrintDisjointSets *maze, int n);
void freeMaze(DisjointSets *sets, PrintDisjointSets *maze);

int main(int argc, char* argv[]) {
	int num;
	FILE *fi = fopen(argv[1], "r");
	fscanf(fi, "%d", &num);
	fclose(fi);

	DisjointSets *sets;
	PrintDisjointSets *maze;

	sets = (DisjointSets*)malloc(sizeof(DisjointSets));
	maze = (PrintDisjointSets*)malloc(sizeof(PrintDisjointSets));

	init(sets, maze, num);

	createMaze(sets, maze, num);

	printMaze(maze, num);

	freeMaze(sets, maze);

	return 0;

}

void init(DisjointSets *sets, PrintDisjointSets *maze, int n) {

	int sets_size = n*n;
	int maze_size = 2*n*n;
	sets->ptr_arr = (int*)malloc(sizeof(int)*sets_size);
	maze->ptr_arr = (int*)malloc(sizeof(int)*maze_size);

	for (int i = 1; i <= sets_size; i++) {
		sets->ptr_arr[i] = 0;
	}

	for (int j = 0; j < maze_size; j++) {
		maze->ptr_arr[j] = 1;
	}

}


int find(DisjointSets *sets, int x) {
	if (sets->ptr_arr[x] <= 0) {
		return x;
	}

	else {
		return find(sets, sets->ptr_arr[x]);
	}

}


void union_(DisjointSets *sets, int i, int j) {

	int p1 = find(sets, i);
	int p2 = find(sets, j);

	if (sets->ptr_arr[p2] < sets->ptr_arr[p1]) {
		sets->ptr_arr[p1] = p2;
	}

	else {
		if (sets->ptr_arr[p2] == sets->ptr_arr[p1]) {
			sets->ptr_arr[p1]--;
		}
		sets->ptr_arr[p2] = p1;
	}
}

void createMaze(DisjointSets *sets, PrintDisjointSets *maze, int n) {
	int start = 1; int goal = n*n;
	srand(time(NULL));
	while (find(sets, start) != find(sets, goal)) {
		int p1, p2;
		int edge = rand() % (2*n*n);
		
		if ((edge/n)%2 == 0) { // | shape
			p1 = edge/(2*n)*n + edge%(2*n) + 1;
			p2 = p1 + 1;
		}
		else { // - shape
			p1 = (edge/(2*n)-1)*n + edge%(2*n) + 1;
			p2 = p1 + n;
		}
		
		// check if same set
		if (p1<= goal && p2<= goal && p1 % n != 0) {

			if (find(sets, p1) != find(sets, p2)) {
				union_(sets, p1, p2);
				maze->ptr_arr[edge] = 0;
			}
		}
	}
}


void printMaze(PrintDisjointSets *maze, int n) {
	int maze_size = 2*n*n;

	maze->ptr_arr[maze_size-n-1] = 0;

	for (int i = 0; i < n; i++) {
		printf(" -");
	}
	printf("\n");
	printf("  ");

	for (int i = 0; i < maze_size; i++) {

		if (maze->ptr_arr[i] == 1) { // wall

			if ((i/n)%2 == 1) { // - type
				printf(" -");
				if (i/n != (i+1)/n) {
					printf("\n");
					if (i < maze_size-1) {
						printf("| ");
					}
				}
			}
			else { // | typei

				printf("| ");
				if (i/n != (i+1)/n) {
					printf("\n");
				}
			}
		}
		else { // no wall
			printf("  ");

			if (i == maze_size-n-1) {
				printf("\n");
			}
		}
	}
	printf("\n");
}

void freeMaze(DisjointSets *sets, PrintDisjointSets *maze) {
	free(sets->ptr_arr);
	free(maze->ptr_arr);
}


