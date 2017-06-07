//Sanil Hattangadi, initlizatios methods and variables
#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;

class Node{
 public:
  //methods
  Node(Student* student);//constructor
  ~Node();//deconstructor
  Node* getNext();//get next node 
  Student* getStudent();//get student 
  void setNext(Node* newNext);//set the next node
  Student* data();//get the data
 private:
  //vartiables
  Student* studentpointer;
  Node* next;
};
