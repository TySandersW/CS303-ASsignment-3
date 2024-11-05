#pragma once
#include <iostream>
using namespace std;

//Functions for part a
//creates a template temp that can take in any data type
template <typename temp>
class Queue {
private:
    //creating node struct and variables
    struct Node {
        temp data;
        Node* next;
        Node(temp val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    //creates queue function that defines a front node and rear node as null, and an initial count of 0
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    //uses any temp data type to push into the queue and also increases the count
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

    //function to remove the last index value and turn it to a nullptr
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

    //Functino to return the front node as long as the queoe isnt empty
    temp front() const {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return frontNode->data;
    }

    //returns size of queue
    int size() const {
        return count;
    }

    //returns bool if queoe is empty or not
    bool empty() const {
        return count == 0;
    }

    //function that moves front element to the back of the list
    void move_to_rear() {
        if (empty() || count == 1) {
            return;
        }
        temp frontElement = front();
        pop();
        push(frontElement);
    }

    //function that displays all items in queue
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
//Creates a recursive Linear Search that finds the last occurance of a value
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
//Struct that defines a listnode funciton
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

//Function that sorts the list
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

//function that changes the list into a sorted list using the insertion method
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

//function that displays the list currently
void displayList(ListNode* headL) {
    while (headL) {
        cout << headL->data << " ";
        headL = headL->next;
    }
    cout << endl;
}