#include <iostream>
#include <math.h>
using namespace std;

bool isMember(int A[], int n){
	cout << "Is " << n << " an element of the chosen set: "; 
	if(A[n] == 1){
		return true;
	}
	else{
		return false;
	}
}

void subset(int A[], int B[]){
	int count = 0;
	for(int i = 0;i<=9;i++){
		if(A[i] == 1 && B[i] == 0){
			cout << "Set 'A' is not a subset of set 'B'.";
			break;
		}
		else{
			count += 1;
		}

		if(count==10){
			cout << "Set 'A' is a subset of set 'B'.";
		}
	}
}

void complement(int A[]){
	cout << "Complement of given set: ";
	for(int i=0;i<=9;i++){
		if(A[i] == 0){
			A[i] = 1;
		}
		else{
			A[i] = 0;
		}
	}
	for(int j=0;j<=9;j++){
		cout << A[j];
	}
}

void unionSet(int A[],int B[]){
	int unionAB[10] = {0};
	for(int i=0;i<=9;i++){
		if(A[i] == 1 ||B[i] == 1){
			unionAB[i] = 1;
		}
	}
	cout << endl << "Union of sets A and B: ";
	for(int j=0;j<= 9;j++){
		cout << unionAB[j];
	}
}

void intersectionSet(int A[], int B[]){
	int interAB[10] = {0};
	for(int i=0;i<=9;i++){
		if(A[i] == 1 && B[i] == 1){
			interAB[i] = 1;
		}
	}
	cout << endl << "Intersection of sets A and B: ";
	for(int j=0;j<=9;j++){
		cout << interAB[j];
	}
}

void setdiff(int A[], int B[]){
	int setAB[10] = {0};
	for(int i=0;i<=9;i++){
		if(A[i] == 1 && B[i] != 1){
			setAB[i] = 1;
		}
	}
	cout << endl << "Set difference of set A and B: ";
	for(int j=0;j<=9;j++){
		cout << setAB[j];
	}
}

void symdiff(int A[], int B[]){
      int setAB[10] = {0};
	for(int i=0;i<=9;i++){
		if(A[i] == 1 && B[i] == 0){
			setAB[i] = 1;
		}
		else if(A[i] == 0 && B[i] == 1){
		        setAB[i] = 1;
		}
	}
	cout << endl << "Symmetric difference of set A and B: ";
	for(int j=0;j<=9;j++){
		cout << setAB[j];
	}
}

void cartesian(int A[], int B[]){
	cout << "Cartesian product of sets A X B: ";
	cout << "{";
	for(int i=0;i<10;i++){
		if(A[i] == 1){
			for(int j=0;j<10;j++){
				if(B[j] == 1){
					cout << " " << "(" << i << "," << j << ")" << " ";
				}
			}
		}
	}
	cout << "}";
}

void powerSet(int A[]){
  int count = 0, idx=0;
  for(int i=0;i<10;i++){
    if(A[i] == 1){
      count++;
    }
  }

  int temp[count] = {0};
  for(int j=0;j<10;j++){
    if(A[j] == 1){
      temp[idx] = j;
      idx++;
    }
  }
  int total = pow(2,count);
  cout << "[";
  for(int i=0;i<total;i++){
    cout << "{ ";
    for(int j=0;j<count;j++){
      if((i>>j)&1){
        cout << " " << temp[j] << " ";
      }
    }
    cout << "} ";
  }
  cout << "]";
}

int main() {
	int setA[10]={0},setB[10] = {0};
	int k,l,setselect,setelem,comple;
	cout << "Enter inputs for set A(0-9,-1 to terminate):- " << endl;
	for(int x=0;x<=9;x++){
		cin>>k;
		if(k != -1){
			setA[k] = 1;
		}
		else{
			break;
		}
	}
	cout << "Enter inputs for set B(0-9,-1 to terminate):- " << endl;
	for(int y=0;y<=9;y++){
		cin>>l;
		if(l!=-1){
			setB[l] = 1;
		}
		else{
			break;
		}
	}
	cout << endl << "Set A is: ";
	for(int a = 0;a<=9;a++) {
		cout << setA[a];
	}
	cout << endl << "Set B is: ";
	for(int b = 0; b <= 9;b++) {
		cout << setB[b];
	}
	cout << endl;
  cout << "Power set of A:- ";
  powerSet(setA);
  cout << endl;
	cartesian(setA,setB);
	unionSet(setA,setB);
	intersectionSet(setA,setB);
	setdiff(setA, setB);
	symdiff(setA, setB);
	cout << endl;
	subset(setA,setB);
	cout << endl << "Select the set for member check(1=>A,2=>B): ";
	cin >> setselect;
	cout << "Enter the element to be checked(0-9): ";
	cin >> setelem;
	if(setselect == 1){
		if(isMember(setA,setelem)==1){
			cout << "True";
		}
		else{
			cout << "False";
		}
	}
	else{
		if(isMember(setB, setelem)==1){
			cout << "True";
		}
		else{
			cout << "False";
		}
	}
	cout<< endl<< "Complement of which set is to be calculated(1=>A,2=>B): ";
	cin >> comple;
	if(comple == 1){
		complement(setA);
	}
	else{
		complement(setB);
	}
  cout << endl;
	return 0;
}
