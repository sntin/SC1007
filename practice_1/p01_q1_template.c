////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

void insert(char *s,int n);
void removes(char *s, int n);

//////////////////////////////////////////////////////////
void main ()
{
	int n;
    char *s;
	int choice;


	printf("How many characters do you want to input: ");
	scanf("%d", &n);

	s=(char *)malloc((n+1)*sizeof(char));

    if (s==NULL)
	{
		printf("can't allocate the memory!");
		return;
	}

	printf("Input the string: ");
	scanf("%s",s);

	do
	{
		printf("Do you want to 1-insert or 2-remove or 3-quit?:");
		scanf("%d",&choice);
		// getchar(); //to clear the return carriage in the buffer

		if (choice==1)
			insert(s,n);
		else if (choice==2)
			removes(s,n);
	}while (choice!=3);

	free(s);

}

//////////////////////////////////////////
void removes(char *s, int n)
{
	// write your code here
	fflush(stdin);
	// no char left
	if (*s == '\0'){
		printf("Cannot remove!\n");
		return;
	}

	// shift all char to the left once
	int i = 0;
	while (i < n){
		*(s+i) = *(s+i+1);
		i++;
	}

	printf("Resulting string: %s \n", s);

}

//////////////////////////////////////////
void insert(char *s, int n)
{
	// write your code here
	fflush(stdin);
	char inchar;

	printf("What is the character you want to insert: ");
	scanf("%c", &inchar);

	char temp = *s;
	*s = inchar;

	int i = 1;
	while (i < n){
		char temp2 = temp;
		temp = *(s+i);
		*(s+i) = temp2;
		i++;
	}

	printf("Resulting string: %s\n", s);
}
