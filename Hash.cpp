//Sanil Hattangadi, hash.cpp that creates algorithms for methods
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Hash.h"

using namespace std;

Hash::Hash(){//constructs the table
  array = new Node*[100];
  size = 100;
}

void Hash::add(){
  add(new Student());
}

void Hash::remove(int id){//removes a student given an id
  for (int i=0;i < size; i++){//walk through array
    Node* current = array[i];
    if (current){//if theres a link list
      if (current->data()->getId() == id){//if deleted id is first in list
	array[i]= current->getNext();
	delete current;
      }
      else{//if its farther in list
	Node* previous = current;
	current = current->getNext();//walk through list
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

void Hash::addRandom(int number){//adding random students with id and gpa
  char* first[100];
  char* last[100];
  ifstream firstStream;
  ifstream lastStream;
  firstStream.open("first.txt");
  lastStream.open("last.txt");  
  //accessing the file
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
    for (int j = 0; j < number; j++){//gives the student its information
      id = 1000 + rand()%9000;
      firstname = first[rand()%i];
      lastname = last[rand()%s];
      gpa = float(rand()%400)/100;
      add(new Student(id, firstname, lastname, gpa));
    }
  }
}

void Hash::print(){//printing out the list of students
  for (int i = 0; i < size; i++){//walk through array
    Node* current = array[i];
    while (current){//walk through linked list
      current->data()->print();
      current = current->getNext();
    }
  }
}

void Hash::add(Student* student, bool checkExpand){//adding a student
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

void Hash::expand(){//expands the table after it has three collisions
  Node** old = array;
  array = new Node* [size*2 + 1];//double the size of the array
  int oldsize = size;
  size = size*2+1;
  for (int i = 0; i < size; i++){//go through array
    Node* current = array[i];
    while (current){
      add(current->data());
      current->getNext();
    }
  }
}

int Hash::getKey(Student* student){//get the key where the student's are located
  int key = student->getId();
  return key % size;
}
