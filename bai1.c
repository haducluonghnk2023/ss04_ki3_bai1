#include<stdio.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
// ham tao node
Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
// ham tao ds n ptu
Node* createLinkedList(int n){
	if(n <= 0){
		return NULL;
	}
	Node* head = NULL;
	Node* tail = NULL;
	for(int i = 0; i < n; i++){
		int value;
		printf("vui long nhap gia tri:");
		scanf("%d",&value);
		Node* newNode = createNode(value);
		if(head == NULL){
			head = newNode;
		}else{
			tail->next = newNode;
		}
		tail = newNode;
	}
	return head;
}
// duyet ds
void printLinkedList(Node* head){
	Node* current = head;
	while(current != NULL){
		printf("%d->",current->data);
		current = current->next;
	}
	printf("NULL\n");
}
// ham giai phong bo nho
void freeLinkedList(Node* head){
	Node* current = head;
	while(current != NULL){
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}

int main(){
	int n;
	printf("nhap so luong pt cua dslk:");
	scanf("%d",&n);
	Node* head = createLinkedList(n);
	printLinkedList(head);
	freeLinkedList(head);
	return 0;
}

