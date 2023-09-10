#include <iostream>
#include "linked_list.h"
using namespace std;

int main(int argc, char** argv) {
  LinkedList<int> list;
  char input;
  cin >> input;
  while (input != 'q'){ // Quit on q
    switch (input){
      case 'a': // Add
        cin >> input;
        list.push_front(input - 48);
        break;
      case 'd': // delete
        list.pop_front();
        break;
      case 'r': // reverse
        list.reverse();
        break;
      case 'p': // print
        list.print();
        break;
        default:
          break;
    }
    cin >> input;
  }
}