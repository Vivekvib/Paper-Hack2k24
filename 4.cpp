#include<iostream>
using namespace std;

void findAllSolution(int arr[], int C, int n, int idx){
    if(n == idx){
        if(C == 0){
            for(int i = 0; i < n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    for(int x = 0; x <= C; x++){
        arr[idx] = x;
        findAllSolution(arr, C-x, n, idx+1);
    }
}

int main(){
    int n, C;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of C(C<=10): ";
    cin>>C;
    int arr[n] = {0};
    if(C<=10){
	    findAllSolution(arr, C, n, 0);
    }
    else{
	    cout << "Invalid number, C should not be greater than 10";
	    cout << "\nEnter value of C again: ";
	    cin >> C;
	    findAllSolution(arr, C, n, 0);
    }
    return 0;
}
