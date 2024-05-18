#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream in ("input.txt");
  ofstream out ("out.txt");
  char currentChar;
  while(in.get(currentChar)){
    if(!(currentChar == ' ')){
        out.put(currentChar);
    }
  }
  in.close();
  out.close();
}
