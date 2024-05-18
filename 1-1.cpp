#include <iostream>
#include <math.h>
#include <string>
using namespace std;

float sumSeries(int terms){
        float sum = 0;
        for(int i = 1;i <= terms;i++){
                sum += pow(-1,i-1)/pow(i,i);
        }
        return sum;
}


int main(int argc, char* argv[]) {
	float res;
	int n, i, count=argc,x;
	if(argc == 1) {
		cout << "Enter no. of terms: ";
		cin >> n;
		res = sumSeries(n);
		cout << "Sum of the series with  " << n << " terms: " << res;
	}
	else{
		cout << "Sum of the series:- " << endl;
		while(count > 1){
			i = (argc-count) + 1;
			x = stoi(argv[i]);
			res = sumSeries(x);
			cout << "With " << x << " terms: " << res << endl;
			count --;

		}
	}
}
