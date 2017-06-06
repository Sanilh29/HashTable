#include <iostream>
#include "Node.h"

class Hash{
 public:
  Hash();
  void add();
  void remove(int id);
  void addRandom(int number);
  void print();
 private:
  void add(Student* student);
  void expand();
  int getKey(Student* student);
  Node** array;
  int size;
};
