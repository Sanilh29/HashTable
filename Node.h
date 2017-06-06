#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;

class Node{
 public:
  Node(Student* student);//constructor
  ~Node();//deconstructor
  Node* getNext();//get next node pointer
  Student* getStudent();//get student pointer
  void setNext(Node* newNext);//set the next pointer to the corresponding node pointer
  Student* data();
 private:
  Student* studentpointer;
  Node* next;
};
