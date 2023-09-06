
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
      head = new ListNode(data, NULL); // Creates a new node as the first piece of data
    }
    else{
      ListNode* newNode = new ListNode(data, head); // Creates a node that will soon become the head
      head = newNode; // Makes the new node the head
    }
  }

  void pop_front(){
    ListNode* tmp = head; // Creates a temmporary pointer to protect the list
    head = head -> next; // Protect the list by advancing past the data to be removed
    delete tmp; // Remove old head
  }

  void reverse(){
    if (head == NULL || head -> next == NULL){ // Empty or one item list
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
      return;
    }
    else {
      ListNode* tmp = head; // Temporary pointer to iterate through the list
      do{
        cout << tmp -> data << ", ";
        tmp = tmp -> next; // advance tmp
      } while(tmp != NULL);
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


