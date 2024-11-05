#pragma once
#include <iostream>
using namespace std;

//Functions for part a
template <typename temp>
class Queue {
private:
    struct Node {
        temp data;
        Node* next;
        Node(temp val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    void push(const temp& value) {
        Node* newNode = new Node(value);
        if (rearNode) {
            rearNode->next = newNode;
        }

        else {
            frontNode = newNode;
        }
        rearNode = newNode;
        count++;
    }

    void pop() {
        if (empty()) {
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (!frontNode) {
            rearNode = nullptr;
        }

        delete temp;
        count--;
    }

    temp front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return frontNode->data;
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    void move_to_rear() {
        if (empty() || count == 1) {
            return;
        }
        temp frontElement = front();
        pop();
        push(frontElement);
    }

    void display() {
        int n = size();
        for (int i = 0; i < n; ++i) {
            temp frontElement = front();
            cout << frontElement << " ";
            move_to_rear();
        }
        cout << endl;
    }
};



//This function is made for part b
int recursiveLinearSearch(const vector<int>& V, int tar, int index) {
    if (index < 0) {
        return -1;
    }
    if (V[index] == tar) {
        return index;
    }


    return recursiveLinearSearch(V, tar, index - 1);
}



//This functions is made for part C
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

void sortedInsert(ListNode*& headL, ListNode* newNode) {
    if (!headL || headL->data >= newNode->data) {
        newNode->next = headL;
        headL = newNode;
    }
    else {
        ListNode* curr = headL;
        while (curr->next && curr->next->data < newNode->data) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void insertionSort(ListNode*& headL) {
    ListNode* sorted = nullptr;
    ListNode* curr = headL;
    while (curr) {
        ListNode* next = curr->next;
        sortedInsert(sorted, curr);
        curr = next;
    }
    headL = sorted;
}

void displayList(ListNode* headL) {
    while (headL) {
        cout << headL->data << " ";
        headL = headL->next;
    }
    cout << endl;
}