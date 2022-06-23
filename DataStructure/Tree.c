# include <stdio.h>
# include <stdlib.h>

struct TreeStruct{
	int size;
	int numOfNode;
	int* element;
};

typedef struct TreeStruct* Tree;

Tree CreateTree(int size);
void Insert(Tree tree, int value);
void PrintTree(Tree tree);
void PrintPreorder(Tree tree, int index);
void PrintInorder(Tree tree, int index);
void PrintPostorder(Tree tree, int index);
void DeleteTree(Tree tree);

void main(int argc, char* argv[]) {
	FILE *fi;
	Tree tree;
	int treeSize;
	int tmpNum;

	fi = fopen(argv[1], "r");
	fscanf(fi, "%d", &treeSize);
	tree = CreateTree(treeSize);

	while (fscanf(fi, "%d", &tmpNum) == 1) {
		Insert(tree, tmpNum);
	}

	PrintTree(tree);
	DeleteTree(tree);
}


Tree CreateTree(int size) {
	Tree t = (Tree) malloc(sizeof(Tree));	
	t->size = size;
	t->numOfNode = 0;
	t->element = (int*) malloc(sizeof(int)*size);
	return t;
}


void Insert(Tree tree, int value) {
	if (tree->numOfNode >= tree->size) {
		printf("Error! Tree is full.\n");
	}
	else {
		tree->numOfNode++;
		tree->element[tree->numOfNode] = value;
	}

}

void PrintTree(Tree tree) {
	int idx = 1;
	printf("Preorder: ");
	PrintPreorder(tree, idx);
	printf("\n");
	printf("Inorder: ");
	PrintInorder(tree, idx);
	printf("\n");
	printf("Postorder: ");
	PrintPostorder(tree, idx);
	printf("\n");

}

void PrintPreorder(Tree tree, int index) {
	if (index <= tree->size && tree->element[index] > 0) {	
		printf("%d ", tree->element[index]);
		PrintPreorder(tree, (index) * 2);
		PrintPreorder(tree, (index) * 2 + 1);
	}
}

void PrintInorder(Tree tree, int index) {
	if (index <= tree->size && tree->element[index] > 0) {
		PrintInorder(tree, (index) * 2);
		printf("%d ", tree->element[index]);
		PrintInorder(tree, (index) * 2 + 1);
	}
}


void PrintPostorder(Tree tree, int index) {
	if (index <= tree->size && tree->element[index] > 0) {
		PrintPostorder(tree, (index) * 2);
		PrintPostorder(tree, (index) * 2 + 1);
		 printf("%d ", tree->element[index]);
	}
}

void DeleteTree(Tree tree) {
	free(tree->element);
}



