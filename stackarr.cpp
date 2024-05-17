#include <iostream>
using namespace std;
#define n 50
class stack
{
    int top;

public:
    int arr[n];
    stack()
    {
        top = 0;
    }
    void push()
    {
        if (top == n)
        {
            cout << "STACK OVERFLOW ";
        }
        else
        {
            int x;
            cout << "ENTER THE NUMBER YOU WANT TO ADD = ";
            cin >> x;
            arr[top++] = x;
            cout<<"THE NUMBER "<<x<<" IS ADDED "<<endl;
        }
    }
    void pop()
    {
        if (top == 0)
        {
            cout << "STACK UNDERFLOW";
        }
        else
        {
            int a = arr[--top];
            cout << "THE POPPED ELEMENT IS " << a<<endl;
        }
    }

    void peek()
    {
        if (top == 0)
        {
            cout << "NO ELEMENTS IN THE STACK ";
        }
        else
        {
            int a = arr[top];
            cout << "THE PEEK ELEMENT " <<a<<endl ;
        }
    }

    void display()
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    stack st;
    int ch;
    int cont;
    
    do
    {
        cout << "THE OPERATIONS TO PERFORM ON THE STACK\n1. PUSH\n 2. PEEK\n 3. POP\n 4. DISPLAY\n";
        cout << "ENTER THE NUMBER ACC TO THE OPERATION = ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            st.push();
            break;
        case 2:
            st.peek();
            break;
        case 3:
            st.pop();
            break;
        case 4:
            st.display();
            break;
        default:
            cout << "WRONG INPUT "<<endl;
        }

        
       
        cout<<"ENTER 0 TO EXIT:--";
        cin >> cont;

    } 
    while (cont != 0);
}