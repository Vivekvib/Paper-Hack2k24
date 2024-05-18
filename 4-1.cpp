#include <iostream>
using namespace std;

void strAddr(string str, int size){
	cout << "Address of each character in the given string: ";
	for(int i=0;i<size;i++){
		cout << &str+i << " ";
	}
}

string concatenateStr(string str1, string str2){
	string str3 = str1 + str2;
	return str3;
}

int compareStr(string str1, string str2){
	int i, len;
	string  minimum;
	int len1 = str1.length(), len2 = str2.length();
	if(len1 <=len2){
		minimum = str1;
		len = len1;
	}
	else{
		minimum = str2;
		len = len2;
	}
	if(str1==str2){
		return 0;
	}
	else{
		for(i=0;i<len;i++){
			if(str1[i] != str2[i]){
				return str1[i] - str2[i];
			}
		}
		return len1-len2;
	}
}

int lenStr(string str){
	int length = 0, i=0;
	while(str[i] != '\0'){
		length++;
		i++;
	}
	return length;
}

string lowerToUpper(string str, int size){
	for(int i=0; i<size;i++){
		if(str[i] <= 123 && str[i] >= 97){
			str[i] -= 32;
		}
		else{
			continue;
		}
	}
	return str;
}

string reverseStr(string str){
	int len = str.length();
	for(int i=0;i<len/2;i++){
		int temp = str[i];
		str[i] = str[len - (i+1)];
		str[len- (i+1)] = temp;
	}
	return str;
}

string insertStr(string mainstr, string newstr, int index){
	string firsthalf, secondhalf;
	secondhalf = &mainstr[index];
	for(int i=0;i<=index-1;i++){
		firsthalf += mainstr[i];
	}
	return firsthalf + newstr + secondhalf;
}
int main() {
	string str1, str2, newstr;
	int index;
	cout << "Enter first string: ";
	getline(cin, str1);
	cout << "Enter second string: ";
	getline(cin, str2);
	int size1 = str1.length();
	int size2 = str2.length();
	strAddr(str1, size1);
	cout << endl;
	cout << "Concatenated string: " << concatenateStr(str1, str2);
	cout << endl;
	cout << "Comparing strings 1 and 2: " << compareStr(str1,str2);
	cout << endl;
	cout << "Length of first string: " << lenStr(str1);
	cout << endl;
	cout << "First string in upper case: " << lowerToUpper(str1, size1);
	cout << endl;
	cout << "Reverse of first string: " << reverseStr(str1);
	cout << endl;
	cout << "Enter string to be inserted in string 1: ";
	getline(cin, newstr);
	cout << "Enter index at which it is to be inserted: ";
	cin >> index;
	cout << "Inserted string: " << insertStr(str1, newstr, index);
	cout << endl;
}
