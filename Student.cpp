//Sanil Hattangadi, creates the algorithms for the methods
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::~Student(){//deconstructor
  delete firstName;
  delete lastName;
}

Student:: Student(int newId, char* first, char* last, float newGpa){///constructor
  id = newId;
  firstName = first;
  lastName = last;
  gpa = newGpa;

}
Student::Student(){ //sets the data to the student and taking it in
  lastName = new char[30];
  firstName = new char[30];
  cout << "What's the student's ID?" << endl;
  cin >> id;
  cin.ignore();
  cout << "What's their first name?" << endl;
  cin.get(firstName,30);
  cin.ignore();
  cout << "What's their last name?" << endl;
  cin.get(lastName,30);
  cin.ignore();
  cout << "What's their GPA?" << endl;
  cin >> gpa;
  cin.ignore();
  cout << "Added student with info" << endl;
  cout << "Name: " << firstName << " " << lastName << endl;
  cout <<"ID: " << id << endl;
  cout <<"GPA: " << setprecision(2) <<fixed << gpa << endl;
}

int Student::getId(){//get the id
  return id;
}

float Student::getGpa(){//get the gpa
  return gpa;
}

void Student::print() {//print the students info
  cout << "Student: " << firstName << " " << lastName << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << gpa << endl;
}
