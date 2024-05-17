#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void addFront(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void addEnd(int data)
    {
        Node *temp = new Node(data);
        if (tail == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void deleteElement(int data)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr && curr->data != data)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            cout << "Element not found in the list." << endl;
            return;
        }
        if (prev == nullptr)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            if (curr == tail)
            {
                tail = prev;
            }
            delete curr;
        }
        cout << "Element " << data << " deleted from the list." << endl;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    int choice, data;
    do
    {
        cout << "\n\nLinked List Menu\n";
        cout << "1. Add element to the front\n";
        cout << "2. Add element to the end\n";
        cout << "3. Delete element\n";
        cout << "4. Print list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to add to the front: ";
            cin >> data;
            list.addFront(data);
            break;
        case 2:
            cout << "Enter element to add to the end: ";
            cin >> data;
            list.addEnd(data);
            break;
        case 3:
            cout << "Enter element to delete: ";
            cin >> data;
            list.deleteElement(data);
            break;
        case 4:
            cout << "Linked list: ";
            list.printList();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);
    return 0;
}