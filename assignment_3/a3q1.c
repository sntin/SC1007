#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queueNode{
	BTNode *data;
	struct _queueNode *next;
}QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode * data);
int dequeue(Queue *qPtr);
BTNode* getFront(Queue q);
int isEmptyQueue(Queue q);

BTNode* createNode(int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

BTNode* findLargestBST (BTNode* root);

int main()
{
    BTNode* root = NULL;
    BTNode* temp = NULL;
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int item;
    int flag=1;
    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
    {
        if(root==NULL)
        {
            if(item!=-1){
                root =createNode(item);
                enqueue(&q,root);
            }
        }
        else{
            while(!isEmptyQueue(q)){
                temp = getFront(q);
                if(flag){
                    if(item != -1){
                        temp->left = createNode(item);
                        enqueue(&q,temp->left);
                    }
                    flag = 0;
                    break;
                }
                else if(temp->right==NULL){
                    if(item!=-1){
                        temp->right = createNode(item);
                        enqueue(&q,temp->right);
                    }
                    dequeue(&q);
                    flag=1;
                    break;
                }
                else  dequeue(&q);
            }
        }
    }
    scanf("%*s");
    printf("The input binary tree:\n");
    printBTNode(root,0,0);
    printf("\n");
    BTNode* BSTnode = findLargestBST (root);
    printf("The largest binary search subtree:\n");
    if(BSTnode)
        printBTNode(BSTnode,0,0);
    else
        printf("No BST\n");
    deleteTree(&root);

    return 0;
}

BTNode* createNode(int item)
{
    BTNode* node = (BTNode*) malloc(sizeof(BTNode));
	node->item = item;
	node->left = node->right = NULL;
	return node;
}

void printBTNode(BTNode *root,int space,int left){
      if (root != NULL)
      {

          int i;
          for (i = 0; i < space-1; i++)
                 printf("|\t");


          if(i<space){
            if(left==1)
              printf("|---");
            else
              printf("|___");
          }

          printf("%d\n", root->item);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

void deleteTree(BTNode **root){
    if (*root != NULL)
	{
		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}
void enqueue(Queue *qPtr, BTNode *data){
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr){
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

BTNode* getFront(Queue q){
    return q.head->data;
}

int isEmptyQueue(Queue q){
    if(q.size==0) return 1;
    else return 0;
}


int minval (BTNode* root){
    if (root->left == NULL && root->right == NULL) {
        return root->item; 
    }
    else if (root->left != NULL && root->right == NULL) {
        if (root->left->item < root->item) {
            return root->left->item; 
        }
        else {
            return root->item; 
        }
    }
    else if (root->left == NULL && root->right != NULL) {
        if (root->right->item < root->item) {
            return root->right->item; 
        }
        else {
            return root->item; 
        }
    }


    int l = minval(root->left); 
    int r = minval(root->right); 
    if (l < r && l < root->item) {
        return l; 
    }
    else if (r < l && r < root->item) {
        return r; 
    }
    else {
        return root->item; 
    }
}

int maxval (BTNode* root){
    if (root->left == NULL && root->right == NULL) {
        return root->item; 
    }
    else if (root->left != NULL && root->right == NULL) {
        if (root->left->item > root->item) {
            return root->left->item; 
        }
        else {
            return root->item; 
        }
    }
    else if (root->left == NULL && root->right != NULL) {
        if (root->right->item > root->item) {
            return root->right->item; 
        }
        else {
            return root->item; 
        }
    }

    int l = maxval(root->left); 
    int r = maxval(root->right); 

    if (l > r && l > root->item) return l; 
    else if (r > l && r > root->item) return r; 
    else return root->item; 

}

int isBST (BTNode* root) {
    if (root->left != NULL && root->right != NULL) {
        if (isBST(root->left) == 0 || isBST(root->right) == 0) return 0; 

        int l_max = maxval(root->left); 
        int r_min = minval(root->right); 

        if (root->item >= l_max && root->item <= r_min) return 1; 
        else return 0; 
    }

    if (root->left != NULL && root->right == NULL) {
        if (isBST(root->left) == 0) return 0; 

        int l_max = maxval(root->left);

        if (root->item >= l_max) return 1; 
        else return 0; 
    }

    if (root->left == NULL && root->right != NULL) {
        if (isBST(root->right) == 0) return 0; 

        int r_min = minval(root->right);

        if (root->item <= r_min) return 1; 
        else return 0; 
    }

    if (root->left == NULL && root->right == NULL) {
        return 1; 
    }
}

int sizeOfBT (BTNode* root) 
{
    if (root == NULL) {
        return 0; 
    }
    else {
        return sizeOfBT(root->left) + sizeOfBT(root->right) + 1; 
    }
}

BTNode* findLargestBST (BTNode* root)
{
// Write your code here
    // printf("%d\n", sizeOfBT(root)); 
    // printf("%d\n", heightOfBT(root)); 
    // printf("%d\n", minval(root)); 
    // printf("%d\n", maxval(root)); 
    // printf("isBST: %d\n", isBST(root->left->right->right));

    // if its a bst, return 
    if (root == NULL) {
        return root; 
    }

    if (isBST(root) == 1){
        return root; 
    }

    // check child
    
    BTNode* leftLargest = findLargestBST(root->left);
    BTNode* rightLargest = findLargestBST(root->right);

    if (sizeOfBT(rightLargest) > sizeOfBT(leftLargest)) return rightLargest;
    else return leftLargest;

}