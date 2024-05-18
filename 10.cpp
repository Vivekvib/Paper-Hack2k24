#include <iostream>
#include <math.h>
using namespace std;

class Triangle{
	int side1, side2, side3;
	float input();
	public:
		Triangle(): side1(1), side2(1), side3(1) {}
		Triangle(int s1, int s2, int s3): side1(s1), side2(s2), side3(s3) {}
		float area();
		float area(int, int);
		float areaCheck();
};

float Triangle::area(){
	float s = (float)(side1+side2+side3)/2;
	float area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
	return area;
}

float Triangle::area(int s1, int s2){
	side1 = s1;
	side2 = s2;
	float area = 0.5*s1*s2;
	return area;
}

float Triangle::input(){
	cout << "Invalid inputs, try again:-" << endl;
	cout << "Enter side1: ";
	cin >> side1;
	cout << "Enter side2: ";
	cin >> side2;
	cout << "Enter side3: ";
	cin >> side3;
	return areaCheck();
}

float Triangle::areaCheck(){
	if(pow(side1,2) == (pow(side2,2)+pow(side3,2))){
		cout << "Area of triangle with sides " << side1 << ", " << side2 << " & " << side3 << " = ";
		return area(side2, side3);
	}
	else if(pow(side2,2) == (pow(side1,2)+pow(side3,2))){
	        cout << "Area of triangle with sides " << side1 << ", " << side2 << " & " << side3 << " = ";
		return area(side1, side3);
	}
	else if(pow(side3,2) == (pow(side1,2)+pow(side2,2))){
	        cout << "Area of triangle with sides " << side1 << ", " << side2 << " & " << side3 << " = ";
		return area(side1, side2);
	}
	else{
		if(side1+side2>side3 && side2+side3>side1 && side1+side3>side2 && side1!=0 && side2!=0 && side3!=0){
		        cout << "Area of triangle with sides " << side1 << ", " << side2 << " & " << side3 << " = ";
			return area();
		}
		else{
			return input();
		}
	}
}

int main() {
	int x, y, z;
	cout << "Enter sides of the triangle:-" << endl;
	cout << "Enter side1: ";
	cin >> x;
	cout << "Enter side2: ";
	cin >> y;
	cout << "Enter side3: ";
	cin >> z;
	Triangle obj;
	if(x==0 && y==0 && z==0){
		x=y=z=1;
	}
	cout << obj.areaCheck() << endl;
	Triangle obj1(x,y,z);
	cout << obj1.areaCheck() << endl;
}
