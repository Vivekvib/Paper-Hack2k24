#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void printArray(int arr[], string str, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            cout<<str[i]<<" = "<<arr[i]<< endl;
        }
    }
}

void findAllOccurence(string str1){
    int alpha[26] = {0};
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < str1.length(); i++){
        alpha[str1[i] - 'a']++;
    }
    printArray(alpha, alphabet, 26);
}

int main(int argc, char *argv[]){
    if(argc==2){
    	string  str = argv[1];
	transform(str.begin(), str.end(), str.begin(), ::tolower);
    	findAllOccurence(str);
   }
   else{
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	findAllOccurence(str);
   }
}
