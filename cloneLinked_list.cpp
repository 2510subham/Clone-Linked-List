#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *random;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
node *insertthenode(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);
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
    return head;
}
void traverse(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void randomlinkedlist(node *&head)
{
    node *temp = head;
    node *tail = head;
    node *next1 = head->next;
    temp->random = next1->next;
    temp = temp->next;
    temp->random = tail;
    temp = temp->next;
    while (next1->next != NULL)
    {
        next1 = next1->next;
    }
    temp->random = next1;
    temp = temp->next;
    tail = tail->next;
    temp->random = tail;
    temp = temp->next;
    tail = tail->next;
    temp->random = tail;
}

node* clone(node *&head)
{
    node *clonehead = NULL;
    node *clonetail = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        node *clonelinkedlist = insertthenode(clonehead, clonetail, temp->data);
        temp = temp->next;
    }
    temp = head;
    node *temp1 = clonehead;
    while (temp != NULL && temp1 != NULL)
    {
        node *next = head->next;
        node *next2 = clonehead->next;
        temp->next = temp1;
        temp = next;
        temp1->next = temp;
        temp1 = next2;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            if (temp->random != NULL)
            {

                temp->next->random = temp->random->next;
            }
            else{
                temp->next=temp->random;
            }
        }
        temp=temp->next->next;
    }
     temp=head;
    temp1=clonehead;
    while(temp!=NULL && temp1!=NULL)
    {
        temp->next=temp1->next;
        temp=temp->next;
        if(temp!=NULL)
        {
            temp1->next=temp->next;
        }
        temp1=temp1->next;
    }
    return clonehead;
}

/***********       FLATTEN LINKED LIST        ************/
node* middle(node* head)
{
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node* left,node* right)
{
    node* newnode=new node(-1);
    node* temp=newnode;
    while(left!=NULL&&right!=NULL)
    {
        if(left->data<right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;

        }
    }
    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;

    }
    newnode=newnode->next;
    return newnode;
}
 node* mergesort(node* head)
 {
     node* mid=middle(head);
     node* left=head;
     node* right=mid->next;
     mid->next=NULL;
     left=mergesort(left);
     right=mergesort(right);
     node* ans=merge(left,right);


 }
/**************   flattens linked list ************
                           '''''''''''''''
/****************      0-> ' 1->5->6-NULL'
 *                     |   ' |           '     <-we separate this chain 
 *                     1   ' 6           '
 *                     |   '''''''''''''''
 *                     2
 * 
 * after separating then we make the single line of the singly linked list by
 *  merging the separated linked list
 *              */    
  
node* merge(node* down,node* right)
      {
          node* temp=down;
          node* temp1=right;
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }

         temp->next=temp1;
  }
  node* flatten(node* head)
  {
      node* down=head;
      node* right=flatten(down->next);
      down->next=NULL;
      node* ans= merge(down,right);
      return ans;
  }
    
/****end of flattens *****/

int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertthenode(head, tail, 1);
    traverse(head);
    insertthenode(head, tail, 2);
    traverse(head);
    insertthenode(head, tail, 3);
    traverse(head);
    insertthenode(head, tail, 4);
    traverse(head);
    insertthenode(head, tail, 5);
    traverse(head);
    randomlinkedlist(head);
    node* loop=clone(head);
    traverse(loop);
}