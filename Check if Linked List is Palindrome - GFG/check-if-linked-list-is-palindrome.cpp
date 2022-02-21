// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
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
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* slow=head;
        Node* fast=head;
        Node* temp=head;
        int k=0;
        while(head){
            head=head->next;
            k++;
        }
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<slow->data;
        if(k%2!=0){
            slow=slow->next;
        }
        slow=reverse(slow);
        while(temp && slow){
            if(slow->data!=temp->data)
                return false;
                    
            slow=slow->next;
            temp=temp->next;
        }
        
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends