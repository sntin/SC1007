//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);
int minval(BTNode *p); 
int maxval(BTNode *p); 

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);
	printf("\n");

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{	
	// write your code here
	if (*node == NULL) {
		BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
		newNode->item = value; 
		newNode->left = NULL; 
		newNode->right = NULL;
		*node = newNode; 
		return; 
	}

	if (value < (*node)->item) {
		if ((*node)->left == NULL) {
			BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
			newNode->item = value; 
			newNode->left = NULL; 
			newNode->right = NULL; 
			(*node)->left = newNode; 
		} 
		else {
			insertBSTNode(&((*node)->left), value);
		}
	} 
	else if (value > (*node)->item) {
		if ((*node)->right == NULL) {
			BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
			newNode->item = value; 
			newNode->left = NULL; 
			newNode->right = NULL; 
			(*node)->right = newNode; 
		} 
		else {
			insertBSTNode(&((*node)->right), value);
		} 
	}
	else {
		printf("Cannot insert");
	}
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here
	if (node == NULL) return; 

	printBSTInOrder(node->left);
	printf("%d ", node->item); 
	printBSTInOrder(node->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here
	if (node->left != NULL && node->right != NULL) {
		min = maxval(node->left); 
		max = minval(node->right); 
		if (node->item > min && node->item < max) {
			if (isBST(node->left, min, max) == 0) return 0;
			if (isBST(node->right, min, max) == 0) return 0;
		}
		else {
			return 0; 
		}
	}

	if (node->left != NULL && node->right == NULL) {
		min = maxval(node->left); 
		
		if (node->item > min) {
			if (isBST(node->left, min, max) == 0) return 0;
		}
		else {
			return 0; 
		}
	}

	if (node->right != NULL && node->left == NULL) {
		max = minval(node->right); 
		if (node->item < max) {
			if (isBST(node->right, min, max) == 0) return 0; 
		}
		else {
			return 0; 
		}
	}

	return 1; 

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{	
	BTNode *removeleft; 
	BTNode *removeright; 
	// write your code here
	if (node == NULL) {
		return NULL; 
	}

	if (node->item == value) {
		if (node->left == NULL && node->right == NULL){
			free(node); 
			node = NULL;
		}
		else if (node->left == NULL && node->right != NULL) {
			node = node->right; 
		}
		else if (node->left != NULL && node->right == NULL) {
			node = node->left; 
		}
		else {
			BTNode *successor = findMin(node->right); 
			int num = successor->item; 
			successor->item = node->item; 
			node->item = num; 
			node->right = removeBSTNode(successor, value); 
		}
	}
	else if (value < node->item) {
		removeleft = removeBSTNode(node->left, value); 
		node->left = removeleft; 
	}
	else {
		removeright = removeBSTNode(node->right, value);
		node->right = removeright; 
	}

	return node; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
	if(p->left == NULL) {
		return p; 
	}
	findMin(p->left); 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int minval(BTNode *p) {
	int l, r; 
	l = r = p->item; 

	if (p->left != NULL) {
		l = minval(p->left); 
	}
	if (p->right != NULL) {
		r = minval(p->right); 
	}

	if (l < p->item && l < r) {
		return l; 
	}
	else if (r < p->item && r < l) {
		return r; 
	}
	else {
		return p->item; 
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int maxval(BTNode *p) {
	int l, r; 
	l = r = p->item; 

	if (p->left != NULL) {
		l = maxval(p->left); 
	}
	if (p->right != NULL) {
		r = maxval(p->right); 
	}

	if (l > p->item && l > r) {
		return l; 
	}
	else if (r > p->item && r > l) {
		return r; 
	}
	else {
		return p->item; 
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////