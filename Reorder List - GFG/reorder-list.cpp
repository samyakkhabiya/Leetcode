// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node* reverse(Node* head){
    if(!head or !head->next)
        return head;
        
    Node* next, *itr=head, *prev=nullptr;
    while(head){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}

void reorderList(Node* head) {
    // Your code here
    if(!head or !head->next)
        return;
    Node* slow=head, *fast=head , *itr=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node * newhead=slow->next;
    slow->next=nullptr;
    
    Node* itr2=reverse(newhead);
    // while(newhead){
    //     cout<<newhead->data<<endl;
    //     newhead=newhead->next;
    // }
    
    int i=0;
    Node* dummy=new Node(-1);
    Node* ans=dummy;
    while(itr and itr2){
        if(i%2==0){
            ans->next=itr;
            itr=itr->next;
        }
        else{
            ans->next=itr2;
            itr2=itr2->next;
        }
        ans=ans->next;
        i++;
    }
    if(itr)
        ans->next=itr;
    else
        ans->next=itr2;
    head=dummy->next;
    
}