/* Implementation stack using linked list*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node *TopNode;

public:
    Stack() {
        TopNode = nullptr;
    }

    void push(int value) {
        Node *newnode = new Node(value);
        newnode->next = TopNode;
        TopNode = newnode;
    }

    int pop() {
        if (IsEmpty())
            return -1;
        Node *temp = TopNode;
        int poppedValue = temp->data;
        TopNode = TopNode->next;
        delete temp;
        return poppedValue;
    }

    int top() {
        if (IsEmpty())
            return -1;
        return TopNode->data;
    }

    bool IsEmpty() {
        return TopNode == nullptr;
    }

    ~Stack() {
        while (!IsEmpty()) {
            pop();
        }
    }
};

/*
Implementation Of queue using linked list 
*/

//code -> 
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* FrontNode;
    Node* BackNode;

public:
    Queue() {
        FrontNode = BackNode = nullptr;
    }

    int front() {
        return (FrontNode != nullptr) ? FrontNode->data : -1;
    }

    int back() {
        return (BackNode != nullptr) ? BackNode->data : -1;
    }

    void push(int value) {
        Node* newnode = new Node(value);
        if (FrontNode == nullptr && BackNode == nullptr) {
            FrontNode = BackNode = newnode;
        } else {
            BackNode->next = newnode;
            BackNode = newnode;
        }
    }

    int pop() {
        if (IsEmpty())
            return -1;
        Node* temp = FrontNode;
        FrontNode = FrontNode->next;
        if (FrontNode == nullptr)
            BackNode = nullptr;
        int popped_el = temp->data;
        delete temp;
        return popped_el;
    }

    bool IsEmpty() {
        return FrontNode == nullptr;
    }

    ~Queue() {
        while (!IsEmpty()) {
            pop();
        }
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Front after pop: " << q.front() << endl;

    return 0;
}

