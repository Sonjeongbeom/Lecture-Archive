# include <stdio.h>
# include <stdlib.h>

typedef struct BinarySearchTree* Tree;
struct BinarySearchTree {
	int value;
	Tree left;
	Tree right;
};

Tree insertNode(Tree root, int key);
Tree deleteNode(Tree root, int key);
Tree getMaxValueInTree(Tree root);
void findNode(Tree root, int key);
void printInorder(Tree root);
void printPreorder(Tree root);
void printPostorder(Tree root);

void main(int argc, char* argv[]) {
	FILE *fi = fopen(argv[1], "r");
	char cmd;
	int key;

	Tree root = NULL;

	while (!feof(fi)) {
		fscanf(fi, "%c", &cmd);
		
		switch (cmd) {
			case 'i' :
				fscanf(fi, "%d", &key);
				root = insertNode(root, key);
				break;
			case 'd' :
				fscanf(fi, "%d", &key);
				root = deleteNode(root, key);
				break;
			case 'p' :
				fscanf(fi, "%c", &cmd);
				if (cmd == 'i') {
					printInorder(root);
				}
				else if (cmd == 'r') {
					printPreorder(root);
				}
				else if (cmd == 'o') {
					printPostorder(root);
				}
				printf("\n");
				break;
			case 'f' :
				fscanf(fi, "%d", &key);
				findNode(root, key);
				break;
			default :
				break;
		}
	}
}

Tree insertNode(Tree root, int key) {
	if (root == NULL) {
		root = malloc(sizeof( Tree));
		if (root == NULL) {
			printf("Out of space!!!\n");
		}
		else {
			root->value = key;
			root->left = NULL;
			root->right = NULL;
			printf("Insert %d\n", root->value);
		}
	}
	else if (key < root->value) {
		root->left = insertNode(root->left, key);
	}

	else if (key > root->value) {
		root->right = insertNode(root->right, key);
	}
	else {
		printf("Insertion Error: There is already %d in the tree.\n", key);
	}

	return root;
}

Tree deleteNode(Tree root, int key) {
	Tree tmp;
	
	if (root == NULL) {
		printf("Deletion Error: %d is not in the tree.\n", key);
	}
	else if (key < root->value) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->value) {
		root->right = deleteNode(root->right, key);
	}
	// num of child node is 2
	else if (key == root->value && root->left != NULL && root->right != NULL) {
		tmp = getMaxValueInTree(root->left);
		root->value = tmp->value;
		tmp->value = key;
		root->left = deleteNode(root->left, tmp->value);
	}
	// num of child node is 0 or 1
	else {
		tmp = root;
		if (root->left == NULL) {
			root = root->right;
		}
		else if (root->right == NULL) {
			root = root->left;
		}
		printf("Delete %d\n", tmp->value);
		free(tmp);
	}
	return root;
}

Tree getMaxValueInTree(Tree root) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->right == NULL) {
		return root;
	}
	else {
		return getMaxValueInTree(root->right);
	}
}

void findNode(Tree root, int key) {
	if (root != NULL) {
		if (key == root->value) {
			printf("%d is in the tree.\n", root->value);
		}	
		else if (key < root->value) {
			findNode(root->left, key);
		}
		else if (key > root->value) {
			findNode(root->right, key);
		}
	}
	else {
		printf("%d is not in the tree.\n", key);
	}
}

void printInorder(Tree root) {
	if (root != NULL) {
		printInorder(root->left);
		printf("%d ", root->value);
		printInorder(root->right);
	}
}

void printPreorder(Tree root) {
	if (root != NULL) {
		printf("%d ", root->value);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printPostorder(Tree root) {
	if (root != NULL) {
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d ", root->value);
	}
}

