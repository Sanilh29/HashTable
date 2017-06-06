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

    cin.getline(input, 128);
    
    if(input[0] == 'a') {
      table->add();
    }
    else if(input[0] == 'd'){
      int id;
      cout << "What is the ID of the student you want to remove?" << endl;
      cin >> id;
      table->remove(id);
      cin.ignore();
      
    }
    else if(input[0] == 'p'){
      table->print();
    }
    else if(input[0] == 'r'){
      int number;
      cout << "How many students do you want?" << endl;
      cin >> number;
      cin.ignore();
      table->addRandom(number);
    }
    else if(input[0] == 'q'){
      running = false;
    }
    else{
      cout << "I don't understand" << endl;
      cout << "The possible commands are:\nAdd\nDelete\nPrint\nRandom\nQuit" << endl;
    }
  }  
}
