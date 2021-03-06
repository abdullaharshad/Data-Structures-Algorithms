#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    Node* next;
};

void Insert(Node** headref, int x)
{
    Node* temp = new Node; //Dynamic Memory allocated
    temp->data=x;
    temp->next=*headref;
    *headref=temp;
    return;
}

void Print(Node** headref)
{
    printf("\n\nLINKEDLIST : ");
    struct Node* temp = *headref;
    while(temp->next!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n\n");
}

void split(Node* head, Node** left, Node** right)
{
    if(head == NULL || head->next == NULL)
    {
        *left = head;
        *right = NULL;
        return;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

Node* merge(Node* left, Node* right)
{
    if(left == NULL && right == NULL) return NULL;
    if(left == NULL) return right;
    if(right == NULL) return left;
    if(left->data < right->data)
    {
        left->next = merge(left->next,right);
        return left;
    }
    else{
        right->next = merge(left, right->next);
        return right;
    }
}

void mergeSort(Node** headref)
{
    Node* head = *headref;
    if(head == NULL || head->next == NULL)
        return;
    Node *left, *right;
    split(head,&left,&right);
    mergeSort(&left);
    mergeSort(&right);
    *headref = merge(left,right);
}

int main()
{
    int choice,x;
    Node* head = NULL;
    printf("\t\t\t\tMergeSort in LinkedList\n\n");
    while(1)
    {
        printf("Press 1 for insertion\nPress 2 for sort\nPress 3 for display\nPress 4 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node\n");
                    scanf("%d",&x);
                    Insert(&head,x);
                    break;
            case 2: mergeSort(&head);
                    break;
            case 3: Print(&head);
                    break;
            case 4: exit(0);
            default : printf("Wrong Choice!\n");
                      break;
        }
    }
    return 0;
}
