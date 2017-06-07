//Sanil Hattangadi, creates methods and variables
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string.h>

class Student{
 public:
  //methods 
  Student();
  Student(int newId, char* first, char* last, float newGpa);
  ~Student();
  void print();
  int getId();
  float getGpa();
 private:
  //variables
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};

#endif
