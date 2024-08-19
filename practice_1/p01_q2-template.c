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
	scanf("%d", &n);
	
	while (n != -1){
		if (head == NULL){
			head = malloc(sizeof(ListNode));
			p = head; 
		}
		else{
			p->next = malloc(sizeof(ListNode));
			p = p->next;
		}

		p->item = n;

		scanf("%d", &n);
	}
	p->next = NULL;

	temp = head; 
	printf("Current list: ");
	while (temp != NULL){
		printf("%d ", temp -> item);
		temp = temp->next;
	}

   //////////////////////////////////////////////////////////////////
}
