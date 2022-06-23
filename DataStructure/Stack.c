# include <stdio.h>
# include <stdlib.h>

typedef struct Stack {
	int* key;
	int top;
	int max_stack_size;
} Stack;

Stack* CreateStack(int max);
void Push(Stack* s, int x);
int Pop(Stack* s);
int Top(Stack* s);
void DeleteStack(Stack* s);
int IsEmpty(Stack *s);
int IsFull(Stack *s);
void Postfix(Stack* s, char input_str);


void main(int argc, char* argv[]) {
	
	FILE* fi = fopen(argv[1], "r");

	Stack* stack = CreateStack(10);

	char c;
	printf("Top numbers: ");
	while (1) {
		fscanf(fi, "%c", &c);
		if (c == '#') {
			break;
		}

		Postfix(stack, c);
		printf("%d ", Top(stack));
	}

	printf("\n");
	printf("evaluation results: %d\n", Pop(stack));

	fclose(fi);
	DeleteStack(stack);
	
}


Stack* CreateStack(int max) {
	Stack* S;
	S = malloc(sizeof(struct Stack));

	if (S == NULL) {
		printf("Out of space!!!");
	}

	S->key = malloc(sizeof(int)* max);
	if (S-> key == NULL) {
		printf("Out of space!!!");
	}

	S->max_stack_size = max;
	S->top = -1;

	return S;
}


int IsEmpty(Stack *s) {
	if (s->top == -1) {
		return 1;
	}
	return 0;
}

int IsFull(Stack *s) {
	if (s->top >= s->max_stack_size - 1) {
		return 1;
	}

	return 0;
}


void Push(Stack* s, int x) {
	if (IsFull(s)) {
		printf("Full stack");
		exit(0);
	}
	else {
		s->top++;
		s->key[s->top] = x;
	}
}

int Pop(Stack* s) {
	if (IsEmpty(s)) {
		printf("Empty stack");
		exit(0);
	}
	else {
		int tmp = s->key[s->top];
		s->top--;
		return tmp;	
	}
}

int Top(Stack* s) {
	if (!IsEmpty(s)) {
		return s->key[s->top];
	}
	else {
		printf("Empty stack");
		exit(0);
	}
}

void DeleteStack(Stack* s) {
	if (IsEmpty(s)) {
		printf("No stack exists");
	}
	else {
		while (!IsEmpty(s)) {
			Pop(s);
		}
	}
}

void Postfix(Stack* s, char input_str) {
	
	int val, val1, val2;
	if (input_str >= '0' && input_str <= '9') {
		val = input_str - '0';
		Push(s, val);
	}
	else {
		int tmp;
		val1 = Pop(s);
		val2 = Pop(s);
		tmp = val1;
		val1 = val2;
		val2 = tmp;

		switch (input_str) {
			case '+' : Push(s, val1 + val2); break;
			case '-' : Push(s, val1 - val2); break;
			case '*' : Push(s, val1 * val2); break;
			case '/' : Push(s, val1 / val2); break;
			case '%' : Push(s, val1 % val2); break;
		}
	}

}

	

