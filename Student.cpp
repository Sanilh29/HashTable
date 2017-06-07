#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

//deconstructor
Student::~Student(){
  delete firstName;
  delete lastName;
}
//constructors
Student:: Student(int newId, char* first, char* last, float newGpa){
  id = newId;
  firstName = first;
  lastName = last;
  gpa = newGpa;

}
Student::Student(){
  //lets you build the student right there
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
int Student::getId(){
  return id;
}
float Student::getGpa(){
  return gpa;
}
void Student::print() {
  cout << "Student: " << firstName << " " << lastName << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << gpa << endl;
}
