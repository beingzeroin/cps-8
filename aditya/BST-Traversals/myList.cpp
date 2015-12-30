#include "mylist.h"
#include <cstdio>

node* createNode(dataType data){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void traverse(node *root){
    while(root!=NULL){
        printf("%d ",root->data->data);
        root = root->next;
    }
}
node* insertInBeginning(node *root,dataType data){
    node *ptr = createNode(data);
    ptr->next = root;
    return ptr;
}
node* insertInEnding(node *root,dataType data){
    if(root == NULL){
        root = createNode(data);
    }
    else{
        node *temp = root;
        while(temp->next != NULL)
            temp = temp->next;
        node *ptr = createNode(data);
        temp->next = ptr;
    }
    return root;
}
node* searchNode(node *root,dataType data){
    while(root!=NULL){
        if(root->data == data)
            break;
        root = root->next;
    }
    return root;
}
node* deleteInBeginning(node *root){
    if(root == NULL)
        printf("Deletion not possible. Empty list");
    else{
        node *temp = root;
        root = root->next;
        free(temp);
    }
    return root;
}
node* deleteInEnding(node *root){
    if(root == NULL)
        printf("Deletion not possible. Empty list");
    else if(root->next == NULL){
        node *temp = root;
        free(temp);
        root = NULL;
    }
    else{
        node *prev = root;
        node *temp = root->next;
        while(temp->next!=NULL){
            temp = temp->next;
            prev = prev->next;
        }
        prev->next = NULL;
        free(temp);
    }
    return root;
}
int countNodes(node *root){
    int count = 0;
    while(root!=NULL){
        root = root->next;
        count++;
    }
    return count;
}
/*node* createRandomList(int size){
    srand(time(NULL));
    int n = size;
    node *root = NULL;
    while(n!=0){
        root = insertInEnding(root,(rand()%size) + 1);
        n--;
    }
    return root;
}*/
node* getLastNode(node *root){
    if(root == NULL)
        return NULL;
    while(root->next != NULL){
        root = root->next;
    }
    return root;
}
void printMiddleElement(node *root){
    // naive approach
    /*int count = countNodes(root);
    if(count == 0)
        return;
    count/=2;
    while(count!=0){
        root = root->next;
        count--;
    }
    printf("%d",root->data);*/
    // Speed pointer :
    if(root == NULL)
        return;
    node *ptr = root;
    node *speed_ptr = root;
    while(speed_ptr && speed_ptr->next){
        speed_ptr = (speed_ptr->next)->next;
        ptr = ptr->next;
    }
    if(ptr)
        printf("%d",ptr->data);
}
node* getKthLastElement(node *root,int k){
    //naive approach
    /*if(root == NULL)
        return NULL;
    int count = countNodes(root);
    int distance = count - k;
    while(distance!=0){
        root = root->next;
        distance--;
    }
    return root;*/
    node *ptr1 = root;
    node *ptr2 = root;
    while(k!=0 && ptr1!=NULL){
        k--;
        ptr1 = ptr1->next;
    }
    while(ptr1!=NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}
node* recursiveReverseList(node *root, node *prev){
    // good approach
    if(root == NULL || root->next == NULL){ // order important
        if(root != NULL){
            root->next = prev;
        }
        return root;
    }
    node *temp = root->next;
    root->next = prev;
    prev = root;
    return recursiveReverseList(temp,prev);
    //waste approach
    /*if(root == NULL)
        return root;
    if(root->next == NULL)
        return root;
    node *temp = root;
    root = root->next;
    root = recursiveReverseList(root);
    root = insertInEnding(root,temp->data);
    return root;*/
}
node* iterativeReverseList(node *root){
    if(root == NULL)
        return root;
    if(root->next == NULL)
        return root;
    node *prev = NULL;
    node *current = root;
    node *after = current->next;
    while(after!=NULL){
        current->next = prev;
        prev =current;
        current = after;
        after = after->next;
    }
    current->next = prev; // important
    return current;
}
/*node* createRandomCircularList(int size, int position){
    node *head = createRandomList(size);
    node *lastNode = getLastNode(head);
    node *ptr = head;
    position--;
    while(position){
        ptr = ptr->next;
        position--;
    }
    lastNode->next = ptr;
    return head;
}*/
node* getCircularNode(node *root){
    node *ptr = root;
    node *speed_ptr = root;
    if(!ptr->next)
        return NULL;
    if(!(speed_ptr->next)->next)
        return NULL;
    do{
        if(ptr->next)
            ptr = ptr->next;
        else
            return NULL;
        if((speed_ptr->next)->next)
            speed_ptr = (speed_ptr->next)->next;
        else
            return NULL;
    }while(ptr!=speed_ptr);
    while(root!=ptr){
        root = root->next;
        ptr = ptr->next;
    }
    return ptr;
}
void printCircularList(node *head){
    node *ptr = getCircularNode(head);
    if(head == ptr){
        printf("Circular list is : ");
        printf("%d ",head->data);
        head = head->next;
        while(head!=ptr){
            printf("%d ",head->data);
            head = head->next;
        }
    }
    else{
        printf("Straight part is : ");
        while(head != ptr){
            printf("%d ",head->data);
            head = head->next;
        }
        printf("\nCircular list is : ");
        printf("%d ",head->data);
        head = head->next;
        while(head!=ptr){
            printf("%d ",head->data);
            head = head->next;
        }
    }
}
void printReverseList(node *root){
    if(root == NULL)
        return;
    printReverseList(root->next);
    printf("%d ",root->data->data);
}
node* deleteElementRecursively(node *root, dataType element){
    if(root == NULL)
        return NULL;
    if(root->data == element){
        node *temp = root->next;
        free(root);
        return temp;
    }
    else{
        root = deleteElementRecursively(root->next,element);
    }
    return root;
    //return deleteTheElement(root,root,NULL,element);
}
node* deleteTheElement(node *head, node *root, node *prev, dataType element){
    if(root == NULL)
        return head;
    if(prev == NULL && root->data == element){
        node *temp = root->next;
        free(root);
        return temp;
    }
    if(prev != NULL && root->data == element){
        node *temp = root;
        prev->next = root->next;
        free(temp);
        return head;
    }
    return deleteTheElement(head,root->next,root,element);
}
node* mergeTwoSortedLists(node *h1, node *h2){
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    node *temp = NULL;
    if(h1->data < h2->data){
        temp = insertInEnding(temp,h1->data);
        temp->next = mergeTwoSortedLists(h1->next,h2);
    }
    else{
        temp = insertInEnding(temp,h2->data);
        temp->next = mergeTwoSortedLists(h1,h2->next);
    }
    return temp;
}
node* alternateMergeLists(node *h1,node *h2){
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    node *h1Next = h1->next;
    h1->next = alternateMergeLists(h2,h1Next);
    return h1;
}


