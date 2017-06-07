#include <fstream>
#include <ctime>
#include <cstdlib>
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
  for (int i=0;i < size; i++){
    Node* current = array[i];
    if (current){
      if (current->data()->getId() == id){
	array[i]= current->getNext();
	delete current;
      }
      else{
	Node* previous = current;
	current = current->getNext();
	while (current){
	  if (current->data()->getId()==id){
	    previous->setNext(current->getNext());
	    delete current;
	  }
	  current = current->getNext();
	} 
      }
    }
  }
}

void Hash::addRandom(int number){
  char* first[100];
  char* last[100];
  ifstream firstStream;
  ifstream lastStream;
  firstStream.open("first.txt");
  lastStream.open("last.txt");  
  if (firstStream.is_open() && lastStream.is_open()){
    int i = 0;
    char newInput[30];
    firstStream >> newInput;
    first[i] = strdup(newInput);
    i++;
    while(firstStream.peek() != '\n' && !firstStream.eof()){
      firstStream >> newInput;
      first[i] = strdup(newInput);
      i++;     
    }
    int s = 0;
    lastStream >> newInput;
    last[s] = strdup(newInput);
    s++;
    while(lastStream.peek() != '\n' && !lastStream.eof()){
      lastStream >> newInput;
      last[s] = strdup(newInput);
      s++;
    }
    int id;
    char* firstname;
    char* lastname;
    float gpa;
    for (int j = 0; j < number; j++){
      id = 1000 + rand()%9000;
      firstname = first[rand()%i];
      lastname = last[rand()%s];
      gpa = float(rand()%400)/100;
      add(new Student(id, firstname, lastname, gpa));
    }
  }
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

void Hash::add(Student* student, bool checkExpand){
  int key = getKey(student);
  if (array[key]){
    Node* current= array[key];
    int collision = 1;
    while (current->getNext()){
      collision++;
      current= current->getNext();
    }
    current->setNext(new Node(student));
    if (collision >= 3 && checkExpand == true){
      expand();
    }
  }
  else {
    array[key] = new Node(student);
  }
}

void Hash::expand(){
  Node** old = array;
  array = new Node* [size*2 + 1];
  int oldsize = size;
  size = size*2+1;
  for (int i = 0; i < size; i++){
    Node* current = array[i];
    while (current){
      add(current->data());
      current->getNext();
    }
  }
}

int Hash::getKey(Student* student){
  int key = student->getId();
  return key % size;
}
