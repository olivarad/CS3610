
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {

public:
  LinkedList() : head(NULL) {}

  // You need to implement the following functions. 
  
  ~LinkedList(){
    if (head == NULL){ // Empty list
      return;
    }
    else{
      ListNode* tmp; // Create a temporary pointer to prevent memory leaks
      do{
        tmp = head; // Track the List head
        head = head -> next; // Advance head
        delete tmp; // Remove old node
      } while(head != NULL);
    }
  }

  void push_front(const T data){
    if (head == NULL){ // Empty List
      ListNode* newNode = new ListNode(data); // Make a new node with the appropriate data
      newNode -> next = NULL; // Set the end of the list to NULL
      head = newNode; // Set this node as the head
    }
    else{
      ListNode* newNode = new ListNode(data); // Creates a node that will soon become the head
      newNode -> next = head; // Set this as the first node
      head = newNode; // Makes the new node the head
    }
  }

  void pop_front(){
    if (head == NULL){
      cout << "Empty\n";
      return;
    }
    ListNode* tmp = head; // Creates a temporary pointer to protect the list
    head = head -> next; // Protect the list by advancing past the data to be removed
    delete tmp; // Remove old head
  }

  void reverse(){
    if (head == NULL){ // Empty list
      cout << "Empty\n";
      return;
    }
    if (head -> next == NULL){ // One item list
      return;
    }
    ListNode* previous; // A temporary pointer to allow for stitching the list
    ListNode* cursor = head -> next; // A temporary pointer to protect the list
    head -> next = NULL; // Sets the old head as the end of the list
    while (cursor -> next != NULL){
      previous = head; // Advances previous to protect list
      head = cursor; // Advances head closer to the final head
      cursor = cursor -> next; // Advances cursor to protect list
      head -> next = previous; // Stiches list
    }
    previous = head; // Advances previous to protect list
    head = cursor; // Advances head to final position
    head -> next = previous; // Completes stitching the list
  }
  
  void print() const{
    if (head == NULL){
      cout << "Empty\n";
      return;
    }
    else {
      ListNode* cursor = head; // Temporary pointer to iterate through the list
      do{
        cout << cursor -> data << " ";
        cursor = cursor -> next; // advance cursor
      } while(cursor != NULL);
      cout << endl;
    }
  }

private:
  
  struct ListNode {
    ListNode(const T data) : data(data), next(NULL) {}
    
    T data;
    ListNode* next;
  };

  ListNode* head;
};


