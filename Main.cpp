#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;

int main() {
    cout << "PART A" << endl;
    //This creates a queue that simply adds values 1-10
    Queue<int> q;
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    //function output
    cout << "Queue elements: ";
    q.display();

    q.move_to_rear();
    cout << "After moving front to rear: ";
    q.display();



    cout << endl << endl << "PART B" << endl;
    //creates a vector with some random numbers
    vector<int> Vec = { 5, 3, 7, 3, 8, 3, 2 };
    int tar = 3;
    int lastIndex = recursiveLinearSearch(Vec, tar, Vec.size() - 1);

    //as long as the element is found, the value is output
    if (lastIndex != -1) {
        cout << "THe last occurrence of " << tar << " is at index " << lastIndex << endl;
    }
    else {
        cout << "This Element is not found" << endl;
    }


    //Creates a ListNode function that adds the values 4 as the head, and then 3, 1, 5, and 2
    cout << endl << endl << "PART C" << endl;
    ListNode* headL = new ListNode(4);
    headL->next = new ListNode(3);
    headL->next->next = new ListNode(1);
    headL->next->next->next = new ListNode(5);
    headL->next->next->next->next = new ListNode(2);

    //outputs
    cout << "Original list: ";
    displayList(headL);
    insertionSort(headL);
    cout << "The sorted list: ";
    displayList(headL);

    return 0;
}