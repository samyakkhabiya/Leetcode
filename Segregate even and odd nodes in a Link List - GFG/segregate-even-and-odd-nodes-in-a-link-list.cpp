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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
       if(head == NULL || head->next == NULL)
           return head;
           
       Node *evenHead = new Node(2), *oddHead = new Node(1);
       Node *even = evenHead, *odd = oddHead, *itr = head;
       
       while(itr != NULL){
           if(itr->data % 2 == 0){
               even->next = itr;
               even = even->next;
           }
           else{
               odd->next = itr;
               odd = odd->next;
           }
           itr = itr->next;
       }
       even->next = oddHead->next;
       odd->next = NULL;
       head = evenHead->next;
       delete evenHead;
       delete oddHead;
       return head;
   }


};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends