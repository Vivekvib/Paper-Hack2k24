#include <iostream>
using namespace std;

void mergeArray(int arr1[], int arr2[], int size1, int size2){
	int totalSize = size1 + size2;
	int i;
	int *mergedArr= new int[totalSize];
	int cur1 = 0, cur2 = 0;
	for(i=0;i<totalSize;i++){
		if(arr1[cur1] <= arr2[cur2]){
			mergedArr[i] = arr1[cur1];
			cur1++;
			if(cur1==size1)
				break;
		}
		else{
			mergedArr[i] = arr2[cur2];
			cur2++;
			if(cur2 == size2)
				break;
		}
	}
	if(cur1==size1) {
		for(int k=cur2; k<size2; k++){
			mergedArr[i+1] = arr2[k];
			i++;
		}
	}
	else{
		for(int k=cur1;k<size1;k++){
			mergedArr[i] = arr1[k];
			i++;
		}
	}

	cout << endl<< "Merged Array: ";

	for(int j = 0; j<totalSize; j++){
		cout << mergedArr[j]<< " ";
	}
}




int main() {
	int size1, size2;
	cout << "Enter size of first array: ";
	cin >> size1;
	int *arr1 = new int[size1];
	cout << "Enter values for first array: " << endl;
	for(int i=0;i<size1;i++){
		cin >> arr1[i];
	}
	cout << "Enter size of second array: ";
	cin >> size2;
	int *arr2 = new int[size2];
	cout << "Enter values for second array: " << endl;
	for(int j=0;j<size2;j++){
		cin >> arr2[j];
	}
	cout << "Array1: ";
	for(int i=0;i<size1;i++){
		cout << arr1[i] << " ";
	}
	cout << endl << "Array2: ";
	for(int j=0;j<size2;j++){
		cout << arr2[j] << " ";
	}
	mergeArray(arr1, arr2, size1, size2);
	return 0;
}
