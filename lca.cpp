#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
Node* LCA(Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);
    if(leftLCA != NULL && rightLCA != NULL)
        return root;
    if(leftLCA != NULL)
        return leftLCA;
    return rightLCA;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int n1, n2;
    cin >> n1 >> n2;
    Node* result = LCA(root, n1, n2);
    if(result != NULL)
        cout << "LCA: " << result->data;
    else
        cout << "LCA not found";
    return 0;
}