#include <iostream>
#include <algorithm>
using namespace std;

int calculateGCD(int num1, int num2){
	int gcd,half;
	int minimum= min(num1,num2);
	int maximum= max(num1,num2);
	if(minimum==0){
		gcd= maximum;
	}
	else if(maximum%minimum==0){
		gcd= minimum;
	}
	else{
		half = int(minimum/2);
		while(half>=1){
			if (num1%half==0 && num2%half==0){
				gcd = half;
				break;
			}
			else{
				half--;
			}
		}
	}
	return gcd;
}

int main() {
	int a,b;
	cout << "Enter any 2 numbers: " << endl;
	cin  >> a >> b;
	int res = calculateGCD(a,b);
	cout << "Greatest Common Divisor of  " << a << " & " << b << " = " << res << endl;
}
