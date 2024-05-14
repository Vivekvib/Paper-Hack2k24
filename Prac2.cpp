#include <iostream>
#include<math.h>
using namespace std;
int main(){
    int n,c,res=0;
    string va;
    cout<<"Enter the variable : ";
    cin>>va;
    cout<<"Enter the Degree of the polynomial : ";
    cin>>n;
    int d;
    cout<<"Enter the value of "<<va<<" : ";
    cin>>d;
    int Sa[n+1];
    for (int i=0;i<=n;i++){
        cout<<"Enter the coeffiecient of Degree "<<i<<" of variable "<<va<<" : ";
        cin>>c;
        res+=c*pow(d,i);
    }
    cout<<res;
    return 0;
}