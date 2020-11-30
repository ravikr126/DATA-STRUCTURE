Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
****************************************
//head is head of your linked list, i and j are indexes to be swapped
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



Node *swapNodes(Node *head, int i, int j)
{
    Node*temp=head;
    Node*temp1=head;
   int a=1;
    int b=1;
    while(a<=i)
    {
        temp=temp->next;
        a++;
    }
    while(b<=j)
    {
        temp1=temp1->next;
        b++;
    }
    int q=temp->data;
    temp->data=temp1->data;
    temp1->data=q;
    return head;
}


//2nd method
Node* swapNodes(Node*head,int i,int j)
{
    //write your code here
    if(i>j){
        i=i+j;
        j=i-j;
        i=i-j;
    }
    //Find nodes
    if(i==0){
        if(j==1){
            Node*cur=head->next;
            head->next=cur->next;
            cur->next=head;
            return cur;
        }
        Node*pt=head;
        for(int c=1;c<j;c++)
            pt=pt->next;
        
        Node*temp=head->next;
        Node*cur=pt->next;
        
        head->next=cur->next;
        pt->next=head;
        cur->next=temp;
        return cur;
        
    }
    if(j-i==1){
        Node* pt=head;
        for(int c=1;c<i;c++)
            pt=pt->next;
        
        Node* cur=pt->next;
        Node* cur1=cur->next;
        
        cur->next=cur1->next;
        pt->next=cur1;
        cur1->next=cur;
        return head;
        
    }
    Node* pt1=head;
    Node*pt2=head;
    
    for(int c=1;c<i;c++)
        pt1=pt1->next;
    
    for(int c=1;c<j;c++)
        pt2=pt2->next;
    
    Node*cur1=pt1->next;
    Node*cur2=pt2->next;
    
    Node*temp=cur1->next;
    
    cur1->next=cur2->next;
    pt2->next=cur1;
    pt1->next=cur2;
    cur2->next=temp;
    
    return head;

}

****************
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}