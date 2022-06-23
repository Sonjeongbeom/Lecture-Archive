# include <stdio.h>
# include <stdlib.h>


# define MAX(a,b) ((a) > (b) ? (a) : (b))

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

struct AVLNode {
	ElementType Element;
	AVLTree Left;
	AVLTree Right;
	int Height;
}AVLNode;

int SetHeight(Position P) {
	if (P == NULL) {
		return -1;
	}
	else {
		return P->Height;
	}
}

AVLTree Insert(ElementType X, AVLTree T);
Position SingleRotateWithLeft(Position Node);
Position SingleRotateWithRight(Position Node);
Position DoubleRotateWithLeft(Position Node);
Position DoubleRotateWithRight(Position Node);


void PrintInorder(AVLTree T);
void DeleteTree(AVLTree T);

void main(int argc, char* argv[]) {
	FILE *fi = fopen(argv[1], "r");
	AVLTree myTree = NULL;
	int key;

	while (fscanf(fi, "%d", &key) != EOF) {
		myTree = Insert(key, myTree);
		PrintInorder(myTree);
		printf("\n");

	}

	DeleteTree(myTree);
}

AVLTree Insert(ElementType X, AVLTree T) {
	if (T == NULL) {
		T = malloc(sizeof(AVLNode));
		if (T == NULL) {
			printf("Fatal Error : Out of space!!!\n");
		}
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (SetHeight(T->Left) - SetHeight(T->Right) == 2) {
			if (X < T->Left->Element) {
				T = SingleRotateWithLeft(T);
			}
			else {
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);
		if (SetHeight(T->Right) - SetHeight(T->Left) == 2) {
			if (X > T->Right->Element) {
				T = SingleRotateWithRight(T);
			}
			else {
				T = DoubleRotateWithRight(T);
			}
		}
	}
	else if (X == T->Element) {
		printf("Insertion Error: %d already in the tree!\n", T->Element);
	}

	T->Height = MAX(SetHeight(T->Left), SetHeight(T->Right)) + 1;
	
	return T;
}



Position SingleRotateWithLeft(Position Node) {
	Position tmp;

	tmp = Node->Left;
	Node->Left = tmp->Right;
	tmp->Right = Node;

	Node->Height = MAX(SetHeight(Node->Left), SetHeight(Node->Right)) + 1;
	tmp->Height = MAX(SetHeight(tmp->Left), SetHeight(Node)) + 1;
	
	return tmp;
}


Position SingleRotateWithRight(Position Node) {
	Position tmp;

	tmp = Node->Right;
	Node->Right = tmp->Left;
	tmp->Left = Node;

	Node->Height = MAX(SetHeight(Node->Left), SetHeight(Node->Right)) + 1;
	tmp->Height = MAX(SetHeight(tmp->Right), SetHeight(Node)) + 1;

	return tmp;
}

Position DoubleRotateWithLeft(Position Node) {
	Node->Left = SingleRotateWithRight(Node->Left);

	return SingleRotateWithLeft(Node);
}


Position DoubleRotateWithRight(Position Node) {
	Node->Right = SingleRotateWithLeft(Node->Right);

	return SingleRotateWithRight(Node);
}




void PrintInorder(AVLTree T) { 
	if (T != NULL) {
		PrintInorder(T->Left);
		printf("%d(%d) ", T->Element, T->Height);
		PrintInorder(T->Right);
	}
}


void DeleteTree(AVLTree T) {
	if (T->Left != NULL)
		DeleteTree(T->Left);
	if (T->Right != NULL)
		DeleteTree(T->Right);
	free(T);
}
