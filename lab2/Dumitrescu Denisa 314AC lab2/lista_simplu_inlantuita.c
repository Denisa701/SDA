#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList(){
    struct node *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while(ptr != NULL){
        printf("(%d,%d) ", ptr->key,ptr->data);
        ptr=ptr->next;
    }
    printf(" ]");
    printf("\n");
}

// void printList(struct Node* ptr)
// {
//     printf("\n[ ");
//     while (ptr != NULL)
//     {
//         printf("%d %d", ptr->data, ptr->key);
//         ptr = ptr->next;
//     }
//     printf(" ]");
//     printf("\n");
// }

void insertFirst(int key, int data){
    //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    //point it to old first node 
    link->next = head;

    // point first to new first node
    head=link;
}

struct node* delete(int key){
    //start from the first link
    struct node* current = head;
    struct node* previous = NULL;
    //if list is empty
    if(head == NULL){
        return NULL;
    }
    // navigate through list
    while(current->key != key){
        //if it is last node
        if(current->next == NULL){
            previous->next = NULL;
            return NULL;
        } else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }
    //found a match, update the link
    if(current == head){
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }
    
    return current;
}

void compareNdelete( int n)
{
    struct node* current = head;
    struct node* compare = head;

    while(current != NULL)
    {
        compare = head;
        
        while(compare != NULL)
        {
            if(compare->key != current->key)
            {
                printf("%d %d\n",compare->key, current->key);
                if(current->data == compare->data)
                    delete(compare->key);
            } 
            compare = compare->next;
        }
        
        current = current->next;
    }
}

void reverse(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL){
        next = current->next;
        current->next=prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int palindrom()
{
    struct node *fast = head;
    struct node *slow = head;
    struct node *mid = NULL;
    struct node *pre = NULL;
    struct node *second = NULL;
    int ok = 1;
    if (head != NULL && head->next != NULL)
    {
        
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
          
        }
        
        if(fast != NULL)
        {
            mid = slow;
            slow = slow->next;
        }
       
        second = slow;
        pre->next = NULL;
        
        reverse(&second);
        current = head;
        
        while(second !=NULL && ok != 0)
        {
            if(second->data == current->data)
            {
                ok = 1;
                second = second->next;
                current = current->next;
            }
            else
            {
                ok = 0; 
            }
        }
    }  
    return ok; 
}

int main()
{
    struct node* revrt;
    int key, data, n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        key = i;
        scanf("%d", &data);
        insertFirst(key, data);
    }
     
    printList();
     
    //printf("%d\n", palindrom());
    //printList(head);

    compareNdelete(n);
    printList();


    
}