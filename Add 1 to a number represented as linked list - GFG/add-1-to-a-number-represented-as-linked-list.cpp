// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

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
   Node* cur=head,*prev=NULL;
   while(cur!=NULL){
       Node* temp=cur->next;
       cur->next=prev;
       prev=cur;
       cur=temp;
   }
   return prev;
}
class Solution
{   
   public:
   Node* addOne(Node *head) 
   {
       head = reverse(head);
       Node*rev=head;
       if((head->data+1)<=9){
           head->data=head->data+1;
           head=reverse(head);
           return head;
       }
       while(head->data+1>9 and head!=NULL){
           if(head->data+1>9 and head->next==NULL){
               break;
           }
           head->data=0;
           head=head->next;
       }
       head->data+=1;
       head=reverse(rev);
       return head;
   }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends