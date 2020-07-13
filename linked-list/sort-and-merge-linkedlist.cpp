//
//  main.cpp
//  merge linked list
//
//  Created by huzaifa ashpak momin on 2020-06-23.
//  Copyright © 2020 Huzaifa. All rights reserved.
//

#include <iostream>
using namespace std;
#define newnode (struct node*)malloc(sizeof(struct node))
struct node{
    int data;
    struct node *next;
};
typedef struct node node;

void insert(node **head,int val){
    node *link=newnode;
    link->data=val;
    link->next=*head;
    *head=link;
}

void traverse(node *head){
    if(head==NULL){
        cout<<"List is Empty";
        return;
    }
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void sort(node **head){
    node *n;
    n=*head;
    if (n==NULL) {
        return;
    }
    node *i,*j,*dummy=newnode,*start,*tmp,*newn;
    newn=NULL;
    int count=0;
    start=*head;
    for(j=*head;j;j=j->next,count++);
    while(count){
        for(i=start;i;i=i->next){
            if (i->data>dummy->data)
                dummy=i;
            }
            tmp=start;
            if(start==dummy){
                start=dummy->next;
            }
            else{
                while (tmp->next!=dummy)
                    tmp=tmp->next;
                tmp->next=dummy->next;
                dummy->next=NULL;
            }
        dummy->next=newn;
        newn=dummy;
        count--;
        dummy=newnode;
        
    }
    *head=newn;
    delete(dummy);
}

void merge(node *head1,node *head2,node **s){
    node *z;
    z=NULL;
    if(head1==NULL and head2==NULL)
        return;
    while(head1!=NULL and head2!=NULL){
        if(*s==NULL){
            *s=newnode;
            z=*s;
        }
        else{
            z->next=newnode;
            z=z->next;
        }
        if(head1->data<head2->data){
            z->data=head1->data;
            head1=head1->next;
        }
        else{
            if(head2->data<head1->data){
                z->data=head2->data;
                head2=head2->next;
            }
            else{
                if(head1->data==head2->data){
                    z->data=head2->data;
                    head1=head1->next;
                    head2=head2->next;
                }
            }
        }
    }
    while(head1!=NULL){
        z->next=newnode;
        z=z->next;
        z->data=head1->data;
        head1=head1->next;
    }
    while(head2!=NULL){
        z->next=newnode;
        z=z->next;
        z->data=head2->data;
        head2=head2->next;
    }
    z->next=NULL;
    
}
int main(int argc, const char * argv[]) {
    cout<<"Merging of two Linked List\n";
    int flag=0;
    node *head1=newnode;
    node *head2=newnode;
    head1=NULL;
    head2=NULL;
    insert(&head1,98);
    insert(&head1,33);
    insert(&head1,38);
    insert(&head1,40);
    insert(&head1,42);
    insert(&head1,617);
    
    insert(&head2,18);
    insert(&head2,1000);
    insert(&head2,33);
    insert(&head2,617);
    insert(&head2,900);
    insert(&head2,990);
    
    cout<<"List 1 : ";
    traverse(head1);
    cout<<endl;
    cout<<"List 2 : ";
    traverse(head2);
    cout<<endl;
    sort(&head1);
    sort(&head2);
    cout<<"Press 1 to merge linked list. \n";
    cin>>flag;
    node *merged_list=newnode;
    merged_list=NULL;
    if(flag==1){
        merge(head1,head2,&merged_list);
        traverse(merged_list);
    }
    return 0;
}
