#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int a) :data(a), next(NULL) {}
};

class Solution {
public:
    void delThisNode(Node* p) {
        if (p->next == NULL)
            delete p;
        else {
            int data = p->next->data;
            p->data = data;
            Node *del = p->next;
            p->next = p->next->next;
            delete del;
        }
    }
};



int main() {
    Solution solu;
    Node* head = new Node();
    head->next = new Node(1);
    Node* p1 = head->next;
    head->next->next = new Node(2);
    Node* p2 = p1->next;
    solu.delThisNode(head);
    //solu.delThisNode(p2);
    solu.delThisNode(p1);
    return 0;
}