/*
*
*  Program: arrays.cc
*  Name: Zachary Knoblauch
*  Date: 2/April/2019
*  Description: Program opens input and output file
*               Program reads input file one character at a time
*               If the character is a lowercase letter, change to uppercase
*               If the character is a digit, change it to an asterisk
*               Otherwise, print as normal
*
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

  ifstream read;//input
  ofstream write;//output
  read.open("Text.txt");//opens input file
    if (read.fail()) {//checks to make sure it opened
      exit(1);//exit program
    }
  write.open("output.txt");//opens output file
    if (write.fail()) {//checks to make sure it opened
      exit(1);//exit program
    }

  char input;//input
  char output;//output

  read.get(input);//get first character
  while (!read.eof()) {//while not at end of file
    output = input;//if input is not lowercase or a digit
    if (islower(input)) {//if input is a lowercase letter
      output = toupper(input);//change to uppercase
    }
    if (input >= 48 && input <= 57) {//if input is a digit
      output = '*';//change to asterisk
    }
    write.put(output);//write to output file
    read.get(input);//read next character
  }

  read.close();//closes file
  write.close();//closes file

  return 0;
}
