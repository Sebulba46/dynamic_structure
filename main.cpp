#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
struct Node
{
    T x;
    Node *Next;
};

template<typename T>
class List
{
    Node<T> *Head = nullptr;
    Node<T> *Tail = nullptr;
public:
        List() = default;
        ~List();
        void Add(T x);
        void Show();
        void del();
        void find(T s);
        void find_ind(int index);

};

template<typename T>
List<T>::~List()
{
    Node<T> *temp = Head;
    while (temp != nullptr)

    {
        temp = Head -> Next;

        delete Head;

        Head = temp;

    }
}



template<typename T>
void List<T>::Add(T x)
{
    auto *temp = new Node<T>;
    temp->x = x;
    temp->Next = nullptr;

    if (Head != nullptr)
    {
        Tail->Next = temp;
        Tail = temp;
    }     else Head = Tail = temp;
}

template<typename T>
void List<T>::Show()
{
    Node<T> *temp = Head;
    while (temp != nullptr)
    {
        cout << temp->x << " ";
        temp = temp->Next;
    }
    cout << endl;
}

template<typename T>
void List<T>::find(T s)
{
    Node<T> *temp = Head;
    int count = 0;
    while (temp != nullptr)
    {
        if (temp->x == s) {
            cout << "Element " << temp->x << " has index: " << count << endl;
        }
        count ++;
        temp = temp->Next;
    }
}

template<typename T>
void List<T>::find_ind(int index)
{
    Node<T> *temp = Head;
    int count = 0;
    while (temp != nullptr)
    {
        if (count == index) {
            cout << "Element List[" << index << "] = " << temp->x << endl;
        }
        count ++;
        temp = temp->Next;
    }
}

template<typename T>
void List<T>::del()
{
    if (Head != nullptr)
    {
        Node<T> *temp = Head;
        cout << "Elem " << Head->x << " del" << endl;
        Head = Head->Next;
        delete temp;
    }
}



int main()
{
    List<int> lst;
    system("CLS");
    lst.Add(100);
    lst.Add(200);
    lst.Add(300);
    lst.Show();
    lst.del();
    cout << endl;

    lst.find(200);
    lst.find_ind(1);

    lst.Add(111);
    lst.Add(222);
    lst.Show();
    cout << endl;

    lst.Show();

    system("PAUSE");
    return 0;
}