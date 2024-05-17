#include <iostream>
using namespace std;
#define n 50
class queue
{
    int *arr;
    int rear=0;
    int front=0;

public:
    queue()
    {
        arr = new int[n];
    }
    bool isempty()
    {
        if (front == rear){
            cout<<"YES"<<endl;

        }
        else{
            cout<<" NOT EMPTY";
        }
    }

    bool isfull(){
        if (rear == n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    int enqueue(int x){
        if (rear == n){
            cout<<"THE QUEUE IS FULL"<<endl;
        }
        else{
            arr[rear]=x;
            rear++;
        }
        cout<<"THE ELEMENT "<<x<< " is enqueued";

    }

    int dequeue(){
        if(rear == front){
            cout<<"THE QUEUE IS EMPTY"<<endl;
        }
        else{
            cout<<"THE ELEMENT DEQUEUED IS --"<<endl;
            cout<<arr[front--];
            cout<<front;

        }
    }
    int getfront(){
        if(front==rear){
            return -1;
        }
        else{
            cout<<"THE FRONT ELEMNT IS --"<<endl;
            int a = arr[front];
            cout<<a<<endl;
        }
    }
};
int main(){
    int ch;
    int cont;
    queue q;
    do{
        cout<<"ENTER THE OPERATION YOU WANT TO PERFORM\n 1. IS EMPTY? \n 2. ISFULL/ \n 3.ENQUEUE \n 4. DEQUEUE \n 5. FRONT"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            q.isempty();
            break;
            case 2:
            q.isfull();
            break;
            case 3:
            int data;
            cout<<"ENTER THE DATA";
            cin>>data;
            q.enqueue(data);
            break;
            case 4:
            q.dequeue();
            break;
            case 5:
            q.getfront();
            break;
            


        }
        cout<<"ENTER 0 TO EXIT "<<endl;
        cin>>cont;
        
    }
    while(cont!=0);

}