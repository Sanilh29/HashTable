//Sanil Hattangadi, header file that creates methods and variables
#include <iostream>
#include "Node.h"

class Hash{
 public:
  //methods that i need
  Hash();
  void add();
  void remove(int id);
  void addRandom(int number);
  void print();
 private:
  //variables and methods that i dont call from here
  void add(Student* student, bool checkExpand = false);
  void expand();
  int getKey(Student* student);
  Node** array;
  int size;
};
