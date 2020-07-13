//
//  main.cpp
//  binary tree using array
//
//  Created by huzaifa ashpak momin on 2020-06-24.
//  Copyright © 2020 Huzaifa. All rights reserved.
//

#include <iostream>
using namespace std;

struct binary_tree{
    int data;
    int k;   // for indexing
};

void initialize(struct binary_tree T[], int maxlength){
    
    for (int i=0; i<maxlength; i++) {
        T[i].data=-1;
        T[i].k=0;
    }
}

void insert(struct binary_tree T[],int val,int max){
    int i;
    if(T[0].data==-1){
        T[0].data=val;
        T[0].k=1;
    }
    else{
        i=T[0].k;
        while(T[i-1].data!=-1 and i<=max){
            if(val>T[i-1].data){
                i=2*T[i-1].k+1;
            }
            else{
                i=2*T[i-1].k;
            }
        }
        T[i-1].data=val;
        T[i-1].k=i;
    }
    
}

void search(struct binary_tree T[],int num , int max){
    int i;
    if (T[0].data==num) {
        cout<<"Number is present.\n";
        
    }
    else{
        i=T[0].k;
        while(T[i-1].data!=-1 and i<=max){
            if(num==T[i-1].data){
                cout<<"Number is present.\n";
                return;
            }
            if(num<T[i-1].data){
                i=2*T[i-1].k;
            }
            else{
                i=2*T[i-1].k+1;
            }
        }
        
    }
    cout<<"Number is not present.\n";
}

void print(struct binary_tree T[], int max){
    if(T[0].data==-1){
        cout<<"binary tree is empty\n";
        return;
    }
    for(int i=0;i<max;i++){
        cout<<T[i].data<<" ";
    }
    cout<<endl;
}

int main() {
    binary_tree T[100];
    int max,n;
    cout<<"\n\nImplement Binary Tree using array. \n\n\n";
    cout<<"Enter the size of Binary Tree : ";
    cin>>max;
    cout<<"\n1. Initialize Binary Tree\n";
    cout<<"2. Insert into Binary Tree\n";
    cout<<"3. Print Binary Tree\n";
    cout<<"4. Search into Binary Tree\n";
    cout<<"5. Exit\n";
    while(1){
        cout<<"\nEnter Your choice : ";
        cin>>n;
        switch(n){
            case 1:
                initialize(T,max);
                break;
                
            case 2:
                int val;
                cout<<"Enter value : ";
                cin>>val;
                insert(T,val,max);
                break;
                
            case 3:
                print(T,max);
                break;
                
            case 4:
                int num;
                cout<<"Enter number to Search : ";
                cin>>num;
                search(T,num,max);
                break;
                
            case 5:
                exit(0);
                
            default:
                cout<<"invalid Choice";
                break;
        }
    }
    return 0;
}
