Code: Merge Sort
Send Feedback
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 


******************************************
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
#include <bits/stdc++.h>
using namespace std;
Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node *fhead;
    Node *ftail;
    
    if(head1->data<=head2->data){
        fhead=head1;
        ftail=head1;
        head1=head1->next;
    }
    else{
        fhead=head2;
        ftail=head2;
        head2=head2->next;
    }
    
    while(head1 && head2){
        if(head1->data<=head2->data){
            ftail->next=head1;
            head1=head1->next;
            ftail=ftail->next;
        }
        else{
            ftail->next=head2;
            head2=head2->next;
            ftail=ftail->next;
        }
    }
    
    while(head1){
        ftail->next=head1;
        head1=head1->next;
        ftail=ftail->next;
    }
    while(head2){
        ftail->next=head2;
        head2=head2->next;
        ftail=ftail->next;
    }
    return fhead;
    
}
Node* midpoint_linkedlist(Node *head)
{
    // Write your code here
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
    Node* slow =head;
    Node* fast=head->next;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}
Node* mergeSort(Node *head) {
    //write your code here
    if(head==NULL || head->next==NULL)
        return head;
    if(head->next!=NULL){
        Node* mid=midpoint_linkedlist(head);
        Node* mid_1=mid->next;
        mid->next=NULL;
        
        Node* left=mergeSort(head);
        Node* right=mergeSort(mid_1);
        
        Node* ans=mergeTwoLLs(left,right);
        return ans;
    }
    return head;
    
}

********

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}