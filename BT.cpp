#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

void levelOrder(Node*root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"Level Order:";
    levelOrder(root);
    return 0;
}
