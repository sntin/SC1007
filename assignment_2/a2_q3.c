#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int  item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist{
   int size;
   CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i,cases;
    int numP;
    scanf("%d",&cases);
    for(i=0; i<cases; i++)
    {
        while(scanf("%d",&item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n",numP);

        deleteList(&himalayas);
    }
    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value){
      //create a new node
      CDblListNode* newNode;
      newNode = (CDblListNode *) malloc(sizeof(CDblListNode));
      newNode->item = value;

      if(ptrCDLL->size==0) //first node
      {
          newNode->next = newNode;
          newNode->pre = newNode;
          ptrCDLL->head = newNode;
      }
      else{
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; //update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
      }
      ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL){

    if(CDLL.head==NULL) return;

    CDblListNode* temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head){
        printf("%d ", temp->item);
        temp = temp->next;

    }
    printf("%d\n",temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL){
    if(ptrCDLL->head==NULL) return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next!= ptrCDLL->head) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }

    free(cur);
    ptrCDLL->head =NULL;
    ptrCDLL->size =0;

}



int numMountainPairs(CDblLinkedList CDLL)
{
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

    int size = CDLL.size;
    
    // base case for 2 or less
    if (size < 3) {
        return size - 1; 
    }

    // number of adjacents
    int pairs = size; 
    
    // check all the combinations, excluding adjacents
    CDblListNode *starthead = CDLL.head; 
    for (int i = 0; i < size - 2; i++) {
        CDblListNode *endhead = starthead->next->next; 
        for (int j = 0; j < size - 2 - i; j++) {

            // skip when head is at beginning and endhead is at the end
            if (endhead->next == starthead) {
                continue; 
            }

            CDblListNode *cur = endhead->next;
            int isPair = 1; 
            int hmin;

            // find hmin
            if (endhead->item > starthead->item) {
                hmin = starthead->item; 
            }
            else {
                hmin = endhead->item; 
            }
            
            // check next direction
            while (cur != starthead) {
                if (cur->item > hmin) {
                    isPair = 0; 
                    break;
                }
                cur = cur->next; 
            }

            // if its a pair continue to next endhead
            if (isPair) {
                pairs += isPair;
                endhead = endhead->next; 
                continue; 
            }

            // return back to the intial state
            isPair = 1; 


            // check pre direction
            cur = endhead->pre; 
            while (cur != starthead) {
                if (cur->item > hmin) {
                    isPair = 0; 
                    break;
                }
                cur = cur->pre; 
            }

            pairs += isPair;
            endhead = endhead->next; 
        }
        starthead = starthead->next; 
    }

    return pairs; 
// Write your code here
}