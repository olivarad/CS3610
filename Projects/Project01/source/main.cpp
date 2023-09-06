#include <iostream>
#include "linked_list.h"
using namespace std;

void menu();

int main(int argc, char** argv) {
  LinkedList<int> list;

}

void menu(){
  string user_input;
  cout << "Please provide user input\n";
  cout << "a i: Add the integer i to the front of the list\n";
  cout << "d:   Delete the first element of the list\n";
  cout << "r:   Reverse the list\n";
  cout << "p:   Print the data value of each node in the list\n";
  cout << "q:   Quit the program\n";
}