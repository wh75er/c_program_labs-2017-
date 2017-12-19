#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50


typedef struct linked_list list;

struct linked_list
{
	char name[MAX_LEN];
	char phone[MAX_LEN];
	char adress[MAX_LEN];
};


void push(list **head, char *n, char* p, char* a);
{
	list* tmp = (list*)malloc(sizeof(list));
	if(tmp == NULL){
		exit(0);
	}

	strcpy(tmp->name, n);
	strcpy(tmp->phone, p);
	strcpy(tmp->adress, a);
	tmp->next = NULL;


	if(!(*head)) {
		*head = tmp;
	}
	else {
		list* tmp_move = *head;
		while(tmp_move->next)
			tmp_move = tmp_move->next;
		tmp_move->next = tmp;
	}
}

void pop(list** head, list* node) //remove node with adress node;
{
	if(!*head)
		return;
	if(*head == *node) {
		*head = (*head)->next;
		free(node);
	} else {
		list* tmp = *head;
		while(tmp->next && tmp->next != node) {
			if(tmp->next == node) {
				tmp->next = tmp->next->next;
				free(node);
			}
			tmp = tmp->next
		}
	}
}

list* search(list **head, char* p)
{
	if(!*head)
		return NULL;
	
	list* res = NULL;
	list* tmp = *head;
	while(!res && tmp) {
		if(!strcmp(tmp->phone, p)) {
			res = tmp;
		}
		tmp = tmp->next;
	}
	
	return res;
}
