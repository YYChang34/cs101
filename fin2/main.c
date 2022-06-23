#include<stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
	char val;
	struct LinkedList* next;
} LinkedList;

LinkedList* allocNode(char val) {
	LinkedList* new_node = (LinkedList*)calloc(1, sizeof(LinkedList));
	new_node->val = val;
	new_node->next = NULL;
	return new_node;
}

LinkedList* appendList(LinkedList* head, char val) {
	if (head == NULL) {
		return allocNode(val);
	}

	LinkedList* list = head;
	//find tail
	while (list->next != NULL) {
		list = list->next;
	}
	list->next = allocNode(val);

	return head;
}

void showList(LinkedList* head) {
	while(head != NULL) {
		printf("[%c]->", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

LinkedList* reverseList(LinkedList* head) {
	if (head == NULL) {
		return head;
	}

    LinkedList *prev = NULL;
   	LinkedList *curr, *next;

    curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(int argc, char const *argv[])
{
	LinkedList* head = NULL;
	head = appendList(head, 'A');
	head = appendList(head, 'B');
	head = appendList(head, 'C');
	head = appendList(head, 'D');
	head = appendList(head, 'E');
	showList(head);
	head = reverseList(head);
	showList(head);
	return 0;
}







