#include <iostream>
using namespace std;

int searchEl(int arr[], int size, int el){
	int i;
	for(i=0;i<size;i++){
		if(arr[i] == el){
			cout << "Index of the chosen element: ";
			return i;
		}
	}
	if(i==size){
		return -1;
	}
}

int main() {
	int x, i, y;
	cout << "Enter size of set: ";
	cin >> x;
	int set[x];
	cout << "Elements of the set: " << endl;
	for(i=0;i<x;i++){
		cin >> set[i];
	}
	cout << "Enter which element to be searched for: ";
	cin >> y;
	cout << searchEl(set, x, y);
}
