#include <iostream>

struct Boo {
    int x;
};

using namespace std;

int main() {

    int size;

    cout << "Enter size of Boo:";
    cin >> size;

    Boo* pointer = nullptr;

    pointer = new Boo[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter next value:";
        cin >> pointer[i].x;
    }


    for (int i = 0; i < size; i++)
        cout << pointer[i].x << endl;

    int el_del;
    cout << "Enter element to delete:";
    cin >> el_del;

    for (int i = 0 ; i < 5 ; i++) {
        if (pointer[i].x == el_del) // check for equality
        {
            for (int j = i; j + 1 < el_del; j++)  //shift over elements in new array
            {
                pointer[j] = pointer[j+1];
            }
        }
    }

    for (int i = 0; i < size - 1; i++)
        cout << pointer[i].x << endl;

    int elem_find;
    cout << "Enter element you want to find";
    cin >> elem_find;

    for (int i = 0 ; i < 5 ; i++) {
        if (pointer[i].x == elem_find) // check for equality
        {
            cout << "Element Boo[" << i << "] = " << elem_find << endl;
        }
    }

    int index_find;
    cout << "Enter index you want to find";
    cin >> index_find;
    cout << "Element Boo[" << index_find << "] = " << pointer[index_find].x << endl;

    delete[] pointer;

    cin.ignore();
    cin.get();
}
