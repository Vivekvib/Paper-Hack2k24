#include <iostream>
using namespace std;

void permWR(string str, int idx){
  //base case
  if(idx==str.size()){
    cout << "[ ";
    for(int i=0;i<str.size();i++){
      cout << str[i] << " ";
    }
    cout << "]" << endl;
    return;
  }

  //recursive case
  for(int j=idx;j<str.size();j++){
    swap(str[idx],str[j]);
    permWR(str,idx+1);
    swap(str[idx],str[j]); //backtrack
  }
}

void permWOR(string str, int idx){
  //base case
  if(idx==str.size()){
    cout << "[ ";
    for(int i=0;i<str.size();i++){
      cout << str[i] << " ";
    }
    cout << "]" << endl;
    return;
  }

  //recursive case
  for(int j=idx;j<str.size();j++){
    swap(str[idx],str[j]);
    if(j==idx || str[j] != str[idx]){
      permWOR(str,idx+1);
    }
    swap(str[idx],str[j]); //backtrack
  }
}

int main() {
  string str;
  cout << "Enter word: ";
  getline(cin,str);

  cout << "Permutations with repetitions of " << str << " :-" << endl;
  permWR(str,0);

  cout << endl;

  cout << "Permutations without repetitions of " << str << " :-" << endl;
  permWOR(str,0);

  return 0;
}
