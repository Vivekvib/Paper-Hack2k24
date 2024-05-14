#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int degree, res=0, var;
	int coeff[degree+1];
	cout << "Enter degree of the polynomial: ";
	cin >> degree;
	for(int i=0;i<=degree;i++){
		cout << "Enter coefficient of degree " << i << " term: ";
		cin >> coeff[i];
	}
	cout << "Given equation: ";
	for(int i=degree;i>=1;i--){
		cout << coeff[i] << "n^" << i << " + ";
	}
	cout << coeff[0];
	cout << endl << "Enter the value of n: ";
	cin >> var;
	for(int i=degree;i>=0;i--){
		res += coeff[i] * pow(var, i);
	}
	cout << "Answer of the given equation with value of n as " << var << " = " << res;
}
