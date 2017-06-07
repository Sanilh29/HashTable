//Sanil Hattangadi, creates algorithms for the methods
#include <iostream>
#include <string.h>
#include "Node.h"

Node::Node(Student* student){//node constructor
  studentpointer = student;
  next = NULL;
}

Node::~Node(){//node deconstructor
  delete studentpointer;
}

Node* Node::getNext(){//get the next node
  return next;
}

Student* Node::data(){//get the data of the student
  return studentpointer;
}

void Node::setNext(Node* newNext){//se tthe next node
  next = newNext;
}
