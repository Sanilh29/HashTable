//Sanil Hattangadi, June 6
//creates a hash table that stores students inforation
//allows adding, deletion, creating random students, and pritniong
#include <iostream>
#include <cstring>
#include "Hash.h"
#include <cstdlib>

using namespace std;

int main(){
  srand (time(NULL));
  //main program loop
  Hash* table = new Hash();
  char input[128];
  bool running = true;

  while(running){
    cout << "Enter a command: add, remove, random, print, or quit." << endl;
    cin.getline(input, 128);
    if(0==strcmp(input, "add")) {//if user inputs add
      table->add();
    }
    else if(0==strcmp(input, "remove")){//if user imputs remove
      int id;
      cout << "What is the ID of the student you want to remove?" << endl;
      cin >> id;
      table->remove(id);//take in id and use that to remove student
      cin.ignore();
      
    }
    else if(0==strcmp(input, "print")){//if user inputs print
      table->print();
    }
    else if(0==strcmp(input, "random")){//if user inputs random
      int number;
      cout << "How many students do you want?" << endl;
      cin >> number;
      cin.ignore();
      table->addRandom(number);
    }
    else if(input[0] == 'q'){//if uyser inputs quit
      running = false;
    }
    else{
      cout << "I don't understand" << endl;
      cout << "The possible commands are:\nadd\nremove\nprint\nrandom\nquit" << endl;
    }
  }  
}
