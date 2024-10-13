#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}

char *slice(char *c, int start, int end) {
    char *newc = malloc((end-start+1)*sizeof(char));
    
    for (int i = 0; i < end - start; i++) {
        newc[i] = c[start+i];
    }

    newc[end-start] = '\0';

    return newc; 
}

int length(char *c) {
    int i = 0; 
    while (c[i] != '\0') {
        i++;
    }
    return i; 
}


void buildTree(BTNode** node, char* preO, char* postO)
{
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    *node = (BTNode *)malloc(sizeof(BTNode)); 

    (*node)->id = preO[0];
    (*node)->left = NULL; 
    (*node)->right = NULL; 

    if (preO[1] == '\0'){
        return; 
    }
    
    int ind = 0; 
    while (postO[ind] != '\0') {
        if (postO[ind] == preO[1]) {
            break; 
        }
        ind++; 
    }

    // one node in the left, then rest is on the right subtree
    if (ind == 0) {
        buildTree(&(*node)->left, slice(postO, 0, 1), slice(postO, 0, 1));
        if (ind + 2 != length(preO)) {
            buildTree(&(*node)->right, slice(preO, ind+2, length(preO)), slice(postO, ind+1, length(postO)-1));
        } 
    }
    // no right subtree
    else if (ind + 2 == length(preO)) {
        buildTree(&(*node)->left, slice(preO, 1, ind+2), slice(postO, 0, ind+1));
    }
    // have both
    else {
        buildTree(&(*node)->left, slice(preO, 1, ind+2), slice(postO, 0, ind+1));
        buildTree(&(*node)->right, slice(preO, ind+2, length(preO)), slice(postO, ind+1, length(postO)-1));
    }
    
// Write your code here
}
