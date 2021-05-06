//program for simple execution of iterative insertion and DFS traversals on BST
#include<iostream>
using namespace std;

class node{  //node class
public:
    int data;
    node* right;
    node* left;

node(int n){  //paramerterized constructor
    data=n;
    right=nullptr;
    left=nullptr;
}

node(){  //default constructor
    data=0;
    right=nullptr;
    left=nullptr;
}

node *insertn(node *root,int h){  //iterative function to insert an element
    node* temp=new node(h);    //creating a new node
    node *parent=nullptr,*curr=root;  //parent pointer to hold the parent and curr to traverse through tree to find suitable place
    while(curr!=nullptr){  //while tree doesn't end
        parent=curr;  //update parent to hold parent of curr
        if(curr->data==h){  //if current node->data is equal to what is to be inserted
            cout<<"Already exists!"<<endl;
            return root;
        }
        else if(curr->data>h)  //if data  is in left subtree
            curr=curr->left;
        else if(curr->data<h)   //if data is in right subtree
            curr=curr->right;
    }
    if(parent==nullptr)  //if tree is empty
        return temp;

    if(parent->data<h)  //if data to be inserted in right subtree
        parent->right=temp;
    if(parent->data>h)  //if data has to go in leftsubtree
        parent->left=temp;
    return root;  //return root


}

void inorder(node* root){  //recursive function to traverse tree in inorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){   //recursive function to traverse tree in preorder fashion
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root){    //recursive function to traverse tree in postorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

};

int main(){
    cout<<"Make selection: "<<endl;
    node* root=nullptr;
    cout<<"1. Insert a node"<<endl;
    cout<<"2. Display inorder"<<endl;
    cout<<"3. Display preorder"<<endl;
    cout<<"4. Display postorder"<<endl;

    int n;
    while(cin>>n){
        switch(n){
        case 1:
            cout<<"Enter value to be inserted: ";
            int h;
            cin>>h;
            root=root->insertn(root,h);
            break;
        case 2:
            if(root==nullptr)
                cout<<"Empty!";
            else root->inorder(root);
            cout<<endl;
            break;
        case 3:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->preorder(root);
            cout<<endl;
            break;
        case 4:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->postorder(root);
            cout<<endl;
            break;

        }
    }

}
