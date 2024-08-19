////////////////////////////////////////////////////////////


//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;


void main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

	/////////////////////////////////////////////////////////////////

	//Question 2
    //Write your program code here
	int user_input;
	scanf("%d", &user_input);
	
	while (user_input != -1){
		if (head == NULL){
			head = malloc(sizeof(ListNode));
			p = head; 
		}
		else{
			p->next = malloc(sizeof(ListNode));
			p = p->next;
		}

		p->item = user_input;

		scanf("%d", &user_input);
	}
	p->next= NULL;

	ListNode *t = head; 
	printf("Current list: ");
	while (t != NULL){
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");

   //////////////////////////////////////////////////////////////////
}
