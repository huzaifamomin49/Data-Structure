//
//  all-operation-linkedlist.cpp
//  linked list
//
//  Created by huzaifa ashpak momin on 2020-06-22.
//  Copyright © 2020 Huzaifa. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    
};
typedef struct node node;

void traverse(struct node *start){
    
    while(start!=NULL){
        cout<<start->data<<"->";
        start=start->next;
    }
}

void insert_begin(struct node **head,int val){
    node *link=(node*)malloc(sizeof(node));
    link->data=val;
    link->next=*head;
    *head=link;
}

void insert_end(node **head,int val){
    node *tmp;
    tmp=*head;
    if(*head==NULL){
        node *link=(node*)malloc(sizeof(node));
        link->data=val;
        link->next=*head;
        *head=link;
        
    }
    else{
        while(tmp->next!=NULL)
            tmp=tmp->next;
    
    node *link=(node*)malloc(sizeof(node));
    tmp->next=link;
    link->data=val;
    link->next=NULL;
    }
    
}

void insert_middle(node **head,int val,int pre){
    if(head==NULL){
        cout<<"Linked List is Empty \n";
        return;
    }
    node *tmp;
    tmp=*head;
    node *new_node=(node*)malloc(sizeof(node));
    while(tmp!=NULL){
        
        if(tmp->data==pre){
            new_node->data=val;
            new_node->next=tmp->next;
            tmp->next=new_node;
            return;
        }
        tmp=tmp->next;
    }
    cout<<"Location not present in LINKED list\n";
    
}

void delete_begin(node **head){
    node *tmp;
    tmp=*head;
    if(tmp==NULL){
        cout<<"List is empty";
        return;
    }
    tmp=tmp->next;
    *head=tmp;
    delete(tmp);
}

void delete_end(node **head){
    node *tmp;
    tmp=*head;
    node *next1;
    next1=tmp->next;
    while(next1->next!=NULL){
        next1=next1->next;
        tmp=tmp->next;
    }
    tmp->next=NULL;
    delete(next1);
    
}

void delete_ele(node **head,int val){
    if(head==NULL){
        cout<<"Linked List is Empty \n";
        return;
    }
    node *tmp,*prev;
    tmp=*head;
    while(tmp!=NULL){
        if(tmp->data==val){
            if(tmp==*head)
                *head=tmp->next;
            else
                prev->next=tmp->next;
            free(tmp);
            return;
        }
        else{
            prev=tmp;
            tmp=tmp->next;
        }
    }
    cout<<"Location not found\n";
    
}

void searching(node **head,int val){
    if(*head==NULL){
        cout<<"Linked List is empty\n";
        return;
    }
    node *tmp;
    tmp=*head;
    int count=1;
    while(tmp!=NULL){
        if(tmp->data==val){
            cout<<val<<" Node is present in Linked list at "<<count<<" position\n";
            return;
        }
        count++;
        tmp=tmp->next;
    }
    cout<<val<<" node is not in Linked List\n";
}

void reverse(node **head){
    node *rev,*tmp,*q;
    q=*head;
    rev=NULL;
    while(q!=NULL){
        tmp=rev;
        rev=q;
        q=q->next;
        rev->next=tmp;
    }
    *head=rev;
    cout<<"Linked List Sucessfully Reversed \n";
}

void sort(node **head){
    node *start,*i,*j,*dummy=(node*)malloc(sizeof(node)),*tmp,*new_node;
    new_node=NULL;
    int count=0;
    for(i=*head;i;count++,i=i->next);
    start=*head;
    while(count){
        for(j=start;j;j=j->next){
            if(j->data>dummy->data)
                dummy=j;
        }
        tmp=start;
        if(start==dummy){
            start=dummy->next;
        }
        else{
            while(tmp->next!=dummy)
                tmp=tmp->next;
            tmp->next=dummy->next;
            dummy->next=NULL;
        }
        dummy->next=new_node;
        new_node=dummy;
        count--;
        dummy=(node*)malloc(sizeof(node));
    }
    *head=new_node;
    delete(dummy);
}

int main() {
    node *head=(node*)malloc(sizeof(node));
    head=NULL;
    cout<<"Welcome To Linked List\n";
    cout<<"1.Insert data at begin \n2.Insert data at end \n3.Insert at middle \n4.Delete node from begin \n5.Delete node from end \n6.Delete perticular node\n7.Search Node in Linked List \n8.Reverse Linked List \n9.Sort Linked List \n10.Display Linked List \n11. Exit \n";
    while(1){
        cout<<"Enter your choice : ";
        int n;
        cin>>n;
        int val;
        switch(n){
            case 1:
                cout<<"Enter number : ";
                cin>>val;
                cout<<endl;
                insert_begin(&head,val);
                break;
            case 2:
                cout<<"Enter number : ";
                cin>>val;
                cout<<endl;
                insert_end(&head,val);
                break;
            case 3:
                int val_before;
                cout<<"Enter number : ";
                cin>>val;
                cout<<"Enter node where we add new node : ";
                cin>>val_before;
                insert_middle(&head, val, val_before);
                break;
            case 4:
                delete_begin(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                cout<<"Enter node which you delete : ";
                cin>>val;
                delete_ele(&head,val);
                break;
            case 7:
                cout<<"Enter node to search : ";
                cin>>val;
                searching(&head,val);
                break;
            case 8:
                reverse(&head);
                break;
            case 9:
                sort(&head);
                break;
            case 10:
                traverse(head);
                cout<<endl;
                break;
            case 11:
                exit(0);
            default:
                exit(0);
            }
    }
    return 0;
}
