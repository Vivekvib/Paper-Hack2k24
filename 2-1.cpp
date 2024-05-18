#include<iostream>
#include<algorithm>
using namespace std;

void findDuplicate(int arr[], int size) {

    sort(arr, arr + size);
    int idx = 0;

    for (int i = 0; i < size; i++) {
        if (arr[idx] != arr[i]){
           arr[++idx] = arr[i];
        }
    }
    cout<<"Array without any duplicates: ";
    for (int i = 0; i <= idx; i++)
    {
        cout<<arr[i]<<" ";
    }
     cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size] = {0};

    cout<<"Enter inputs of the array: "<<endl;
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    findDuplicate(arr, size);

    return 0;
}
