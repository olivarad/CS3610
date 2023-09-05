
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {

public:
  LinkedList() : head(NULL) {}

  // You need to implement the following functions. 
  
  ~LinkedList(){
    if (head == nullptr){ // Empty list
      return;
    }
    else{
      ListNode* tmp; // Create a temporary pointer to prevent memory leaks
      do{
        tmp = head; // Track the List head
        head = head -> next; // Advance head
        delete tmp; // Remove old node
      } while(head != nullptr);
    }
  }

  void push_front(const T data){
    if (head == nullptr){ // Empty List
      head = new ListNode(data, nullptr); // Creates a new node as the first piece of data
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

  // void reverse();
  
  void print() const{
    if (head == nullptr){
      return;
    }
    else {
      ListNode* tmp = head; // Temporary pointer to iterate through the list
      do{
        cout << tmp -> data << ", ";
        tmp = tmp -> next; // advance tmp
      } while(tmp != nullptr);
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


