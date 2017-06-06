#include <iostream>
#include <string.h>
#include "Node.h"

Node::Node(Student* student){
  studentpointer = student;
  next = NULL;
}

Node::~Node(){
  delete studentpointer;
}

Node* Node::getNext(){
  return next;
}

Student* Node::data(){
  return studentpointer;
}

void Node::setNext(Node* newNext){
  next = newNext;
}
