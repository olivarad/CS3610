#include <iostream>
#include "linked_list.h"
using namespace std;

int main(int argc, char** argv) {
  LinkedList<int> list;
  int i = 1; // Ignore first argument being the program location
  while (*argv[i] != 'q'){ // Quit on q
    switch (*argv[i]){
      case 'a': // Add
        i++; // Requires next argument
        list.push_front(*argv[i] - 48);
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
    }
    i++;
  }
}