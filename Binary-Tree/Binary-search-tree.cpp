#include <iostream>
using namespace std;


struct binary_tree{
    int data;
    struct binary_tree* left;
    struct binary_tree* right;
};

typedef struct binary_tree B;

/*struct binary_tree* newchild(int val){
    struct binary_tree *root1;
    root1=(B *)malloc(sizeof(B));
    root1->left=NULL;
    root1->right=NULL;
    root1->data=val;
    return root1;
}

struct binary_tree* insert(struct binary_tree *root,int data){
    if(root==NULL){
        root=newchild(data);
    }
    else if(root->data>data){
        //root=root->left;
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
*/
void traverse(B *root){
    
    if(root!=NULL){
        traverse(root->left);
        cout<<root->data<<" ";
        traverse(root->right);
    }
}

void insert(B **root,int data){
    
    if(*root==NULL){
        B *root1;
        root1=(B *)malloc(sizeof(B));
        root1->left=NULL;
        root1->right=NULL;
        root1->data=data;
        *root=root1;
        //return root1;
    }
    else{
        B *child;
        child=(B *)malloc(sizeof(B));
        B *tmp,*pr;
        tmp=*root;
        pr=*root;
        while(tmp!=NULL){
            pr=tmp;
            if(data>=tmp->data)
                tmp=tmp->right;
            else
                tmp=tmp->left;
        }
        
        child->left=child->right=NULL;
        child->data=data;
        if(data>pr->data)
            pr->right=child;
        else
            pr->left=child;
        //return pr;
    }
}

void search(B **root, int val){
    if(*root==NULL){
        cout<<"Tree is empty.\n";
        return;
    }
    B *tmp=*root;
    while(tmp!=NULL){
        if(val==tmp->data){
            cout<<val<<" is present in Binary Tree \n";
            return;
        }
        else if(val>tmp->data)
            tmp=tmp->right;
        else
            tmp=tmp->left;
    }
    cout<<val<<" not present in Binary Tree \n";
}

int main() {
    B *root=(B *)malloc(sizeof(B));
    root=NULL;
    
    int n;
    while(1){
        cout<<"1. Inset data \n2. Traverse \n3. Search data \n4. Exit \n";
        cin>>n;
        switch(n){
            case 1:
                int val;
                cout<<"Enter data : ";
                cin>>val;
                insert(&root,val);
                break;
            case 2:
                traverse(root);
                cout<<endl;
                break;
            case 3:
                int num;
                cout<<"Enter Value to search in Tree : ";
                cin>>num;
                cout<<endl;
                search(&root,num);
                cout<<endl;
                break;
            case 4:
                exit(0);
            default:
                cout<<"Enter valid case.\n";
                
        }
    }
    
    
    return 0;
}

