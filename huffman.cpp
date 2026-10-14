#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> q;

    cout << "Enter characters and their frequencies:\n";

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        q.push(new Node(ch, freq));
    }

    while (q.size() > 1) {
        Node* left = q.top();
        q.pop();

        Node* right = q.top();
        q.pop();

        Node* parent = new Node('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        q.push(parent);
    }

    Node* root = q.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
