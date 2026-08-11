#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;
    Node* nodes[n];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
        cin >> nodes[i]->data;
        nodes[i]->next = NULL;

        if (head == NULL)
            head = nodes[i];
        else
            tail->next = nodes[i];

        tail = nodes[i];
    }

    int pos;
    cout << "Enter position of cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos >= 0)
        tail->next = nodes[pos];

    if (hasCycle(head))
        cout << "Cycle exists";
    else
        cout << "No cycle";

    return 0;
}