#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
} Node;

typedef struct HeapAr{
	Node* Hnode;
	int size;
} HeapAr; 

void heapify(HeapAr* h , int index);
void swap(HeapAr* h , int val1 , int val2);
void insert(HeapAr* h, int key);

int is_empty(HeapAr* h){
	return h->size == 0;
}

int size(HeapAr* h){
	return h->size;
}

void look(HeapAr* h, int* val){
	if(h->size > 0){
		int value = h->Hnode[0].key;
		*val = value; 
	} else{
		printf("HeapError\n");
	}
}


/*swap based off index into the heap array*/
void swap(HeapAr* h , int val1 , int val2){
	int temp = h->Hnode[val1].key;
	h->Hnode[val1].key = h->Hnode[val2].key;
	h->Hnode[val2].key = temp; 
}


void insert(HeapAr* h, int key){
	/* if there are items in heap[] reallocate memory*/
	//printf("Size is : %d" , h->size);
	if(h->size){
		h->Hnode = realloc(h->Hnode, (h->size + 1) * sizeof(Node) );
	} else {
		/*else just grab enoguh for 1 Node*/
		h->Hnode = malloc(sizeof(Node));
	}
	Node node;
	node.key = key;
	h->size++; //increase the size
	h->Hnode[h->size - 1] =  node; 
	int lastElement = h->size - 1;								  //parent element
	while(lastElement  >=0 && h->Hnode[lastElement].key < h->Hnode[(lastElement-1)/2].key){
		swap(h,lastElement , (lastElement -1)/2);
		lastElement = (lastElement - 1) /2;
	}
}

void remove_element(HeapAr* h , int* val){
	if(!h->size){
		printf("HeapError");
	} else {
		/*keep the first element value and store*/
		int value = h->Hnode[0].key;
		*val = value; 
		//swap first and last elements before del
		//swag indexex
		swap(h, 0 , h->size - 1);
		h->size--;
		/*free the memory maybe*/
		h->Hnode = realloc(h->Hnode, (h->size) * sizeof(Node));

		heapify(h, 0);
	}
}

void heapify(HeapAr* h , int index){
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int parent = (index - 1) / 2;

	int smallest = index;

	if (left < h->size && h->Hnode[left].key < h->Hnode[index].key){
		smallest = left;
	} 
	if (right < h->size && h->Hnode[right].key < h->Hnode[smallest].key){
		smallest = right;
	}
	if (smallest != index){
		swap(h, index , smallest);
		heapify(h , smallest);
	}
}

void to_string(HeapAr* h){
	int strsize = h->size + 1;
	char* returnStr[strsize];
	/*set null term char*/
	returnStr[h->size] = '\0';
	int i;
	for (i=0 ; i < h->size; i++){
		printf("%d ",h->Hnode[i].key );
		//returnStr[i] = atoi(h->Hnode[i].key);
	}
	printf("\n");
	//printf("%s\n",returnStr);
	//return returnStr;
}

void deallocate_memory(HeapAr* h){
	int size = h->size;
	int i;
	for(i=0; i < size; i++){
		free(h->Hnode);
	}
}



int main(int argc , char** argv){

	HeapAr h;
	h.size = 0; /*initialize size of heap to 0 */

	insert(&h, 3);
	insert(&h , 2);
	insert(&h , 1);
	int s = size(&h);
	printf("Size after 3 inserts : %d\n" , s);
	to_string(&h);
	int element = 0;
	remove_element(&h, &element);
	printf("removed element is %d\n", element);
	to_string(&h);
	look(&h, &element);
	printf("looked element is %d\n", element);
	to_string(&h);


	deallocate_memory(&h);
}