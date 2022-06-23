# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define max_length 100

typedef struct HashTable {
	int size;
	int *list;
} HashTable;

int hash(int key, int size);
int find(int key, HashTable *H);
void insert(int key, HashTable *H);

int main(int argc, char *argv[]){
	FILE *f;
	f = fopen(argv[1], "r");
	int size, indexnumber;
	int i, tmp;
	char index[max_length];
	char *ptr1, *ptr2, *ptr3;
	char *ptrtmp[3];
	
	fgets(index, 100, f);
	ptr1 = strtok_r(index," ",&ptrtmp[0]);
	size = atoi(ptr1);

	HashTable *table;
	table = malloc(sizeof(HashTable));
	table->size = size;
	table->list = malloc(sizeof(int)*table->size);
	
	for(i = 0; i < table->size; i++){
		table->list[i] = 0;
	}

	fgets(index, 100, f);
	ptr2 = strtok_r(index," ", &ptrtmp[1]);
	
	while(ptr2 != NULL) {
		indexnumber = atoi(ptr2);
		//-------------------------------
		insert(indexnumber, table);
		//-------------------------------
		ptr2 = strtok_r(NULL, " ", &ptrtmp[1]);
	}

	fgets(index, 100, f);
	ptr3 = strtok_r(index," ", &ptrtmp[2]);
	while(ptr3 != NULL) {
		indexnumber = atoi(ptr3);
		//-------------------------------
		tmp = find(indexnumber, table);
		//-------------------------------
		if(tmp == 0)
			printf("%d is not in the table\n",indexnumber);
		else 
			printf("%d is in the table\n",indexnumber);
		
		ptr3 = strtok_r(NULL, " ", &ptrtmp[2]);
	}

	return 0;
}	


int hash(int key, int size) {
	return key % size;
}

int find(int key, HashTable *H) {
	for (int i = 0; i < H->size; i++) {
		if (H->list[i] == key) {
			return key;
		}
	}

	return 0;
}

void insert(int key, HashTable *H) {
	int pos = find(key, H);

	if (pos == 0) { 
		int idx = hash(key, H->size);
		while (H->list[idx] != 0) {
			printf("%d collision has been occurred with %d\n", key, H->list[idx]);
			idx++;
		}
		H->list[idx] = key;
		printf("%d is inserted at address %d\n", key, idx);
	}
}




