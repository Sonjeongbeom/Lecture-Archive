# include <stdio.h>
# include <stdlib.h>

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node {
	ElementType element;
	Position next;
};

List MakeEmptyList();
int isLast(Position p, List l);
void Delete(ElementType x, List l);
Position FindPrevious(ElementType x, List l);
Position Find(ElementType x, List l);
void Insert(ElementType X, Position p, List l);
void DeleteList(List l);
void PrintList(List l);

int main(int argc, char* argv[]) {

	char command;
	int key1, key2;
	FILE *input, *output;
	Position header = NULL, tmp = NULL;


	if (argc <= 1) {
		printf("Please enter an input file.\n");
		return 0;
	}
	else {
		input = fopen(argv[1], "r");
	}
	
	header = MakeEmptyList();
	while (1) {
		command = fgetc(input);
		if (feof(input)) break;

		switch (command) {
			case 'i' :
				fscanf(input, "%d %d", &key1, &key2);
				tmp = Find(key2, header);
				Insert(key1, tmp, header);
				break;

			case 'd' :
				fscanf(input, "%d", &key1);
				Delete(key1, header);
				break;
			case 'f' :
				fscanf(input, "%d", &key1);
				tmp = FindPrevious(key1, header);
				if (isLast(tmp, header)) {
					printf("Could not find %d in the list.\n", key1);
				}
				else if (tmp->element > 0) {
					printf("Key of the previous node of %d is %d.\n", key1, tmp->element);
				}
				else {
					printf("Key of the previous node of %d is header.\n", key1);
				}
				break;
			case 'p' :
				PrintList(header);
				break;
			// default :
			//	printf("Invalid command line\n");
			}
	}

	DeleteList(header);
	fclose(input);

	return 0;

}

List MakeEmptyList() {
	List l = (List)malloc(sizeof(struct Node));
	l->element = -999;
	l->next = NULL;
	return l;
}

int isLast(Position p, List l) {
	Position current = l;
	while (current->next != NULL) {
		current = current->next;
	}
	return p == current;
}


Position FindPrevious(ElementType x, List l) {
	Position p;
	p = l;
	while (p->next != NULL && p->next->element != x) {
		p = p->next;
	}

	return p;
}


Position Find(ElementType x, List l) {
	Position p;
	if (x == -1) {
		return l;
	}
	p = l->next;
	while (p != NULL && p->element != x) {
		p = p->next;
	}
	return p;
}


void Insert(ElementType x, Position p, List l) {
	Position tmpCell;
	tmpCell = malloc(sizeof(struct Node));

	if (tmpCell == NULL){
		printf("Out of space");
	}
	

	if (p == NULL) {
		printf("Insertion(%d) Failed: cannot find the location to be inserted.\n", x);	
	}
	
	else {
		tmpCell->element = x;
		tmpCell->next = p->next;
		p->next = tmpCell;
//		printf("now insert value is %d\n", p->next->element);
	}
}


void Delete(ElementType x, List l) {
	Position p, tmpCell;
	p = FindPrevious(x, l);

	if (!isLast(p,l)) {
		tmpCell = p->next;
		p->next = tmpCell->next;
		free(tmpCell);
	}

//	if (p->next == NULL) {
//		printf("Deletion failed: element %d is not in the list.\n", x);
//	}
	else {
		printf("Deletion failed: element %d is not in the list.\n", x);
	}
}





void PrintList(List l) {
	PtrToNode tmp = NULL;
	tmp = l->next;
	if (tmp == NULL) {
		printf("list is empty!\n");
		return;
	}
	while (tmp != NULL) {
		printf("key: %d\t", tmp->element);
		tmp = tmp->next;
	}
	printf("\n");
}

void DeleteList(List l) {
	Position p = NULL, tmp = NULL;
	p = l->next;
	l->next = NULL;
	while (p != NULL) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}
