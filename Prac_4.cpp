#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int sum, term;
    cout<<"Enter the Sum : ";
    cin>>sum;
    cout<<"Enter the term : ";
    cin>>term;
    int a,b,c;
    int sum1;
    for (int  j = 0; j <= sum; j++){
        a=j;
        sum1=sum-a;
        for (int i =0;i<sum1+1;i++)
        {b=i;
        c=sum1-b;
        cout<<"x1 = "<<a<<endl;
        cout<<"x2 = "<<b<<endl;
        cout<<"x3 = "<<c<<endl;
        }
    }
    return 0;
}