#include <fstream>
#include <ctime>
#include <iostream>
#include "Hash.h"

using namespace std;

Hash::Hash(){
  array = new Node*[100];
  size = 100;
}

void Hash::add(){
  add(new Student());
}

void Hash::remove(int id){

}

void Hash::addRandom(int number){

}

void Hash::print(){
  for (int i = 0; i < size; i++){
    Node* current = array[i];
    while (current){
      current->data()->print();
      current = current->getNext();
    }
  }
}

void Hash::add(Student* student){
  int key = getKey(student);
  if (array[key]){
    Node* current= array[key];
    int collision = 1;
    while (current->getNext()){
      collision++;
      current= current->getNext();
    }
    current->setNext(new Node(student));
    if (collision >= 3){
      expand();
    }
  }
  else {
    array[key] = new Node(student);
  }
}

void Hash::expand(){

}

int Hash::getKey(Student* student){
  int key = student->getId();
  return key % size;
}
