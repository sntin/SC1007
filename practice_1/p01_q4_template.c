////////////////////////////////////////////////////////////

//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////

int searchList(ListNode *head, int value);

//////////////////////////////////////////////////////

void main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

 ////////////////////////////////////////////////////////////////////

 // Question 2
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
//////////////////////////////////////////////////////////////////////

//search for a value in the list. Q3

	printf("Enter value to search for:");
	scanf("%d", &n);
	searchList(head,n);

/////////////////////////////////////////////////////////

    //free up memory for question 4
	//this part is wrong. It will cause problems.
/*	p = head;
	while (p!= NULL) {
		free(p);
		p=p->next;
	}
*/


    // Question 4
	//rewrite the free up using temporary pointer temp.
	p = head; 
	while (p != NULL){
		temp = p;
		p = p->next; 
		free(temp);
	}
/////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////

int searchList(ListNode *head, int value)
{

////////////////////////////////////////////////////////////////////

 // Question 3
 //Write your program code here
	int i = 0, index = -1; 
	ListNode *t = head; 
	while (t != NULL){
		if (t->item == value){
			index = i; 
			break; 
		}

		i++;
		t = t->next;
	}

	if (index == -1){
		printf("Value %d not found", value); 
	}
	else{
		printf("Value %d found at index %d", value, index);
	}
//////////////////////////////////////////////////////////////////////
}
