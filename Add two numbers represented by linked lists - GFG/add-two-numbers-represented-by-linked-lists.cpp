// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head){
        Node* prev=NULL;
        while(head){
            Node* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* l1=reverse(first);
        Node* l2=reverse(second);
        Node* dummy=new Node(-1);
        Node* ans=dummy;
        int carry=0;
        while(l1 || l2 || carry){
            int val1=0;
            int val2=0;
            if(l1){
                val1=l1->data;
                l1=l1->next;
            }
            if(l2){
                val2=l2->data;
                l2=l2->next;
            }
            int sum=val1+val2+carry;
            if(sum<10){
                carry=0;
            }
            else{
                carry=sum/10;
                sum%=10;
            }
            Node* h=new Node(sum);
            ans->next=h;
            ans=ans->next;
        }
        return reverse(dummy->next);
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends