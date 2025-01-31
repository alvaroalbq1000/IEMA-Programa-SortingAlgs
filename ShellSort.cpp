// Autor: Álvaro Gabriel Alves Albuquerque
// Criado em: 2023
// Apenas para exibição e estudo

// Shell Sort in C++
#include <iostream>
#include <vector>
using namespace std;

void gapInsertionSort(vector<int>& alist, int start, int gap) {
    for (int i = start + gap; i < alist.size(); i += gap) {
        int currentvalue = alist[i];
        int position = i;
        while (position >= gap && alist[position - gap] > currentvalue) {
            alist[position] = alist[position - gap];
            position = position - gap;
        }
        alist[position] = currentvalue;
    }
}

void shellSort(vector<int>& alist) {
    int sublistcount = alist.size() / 2;
    while (sublistcount > 0) {
        for (int startposition = 0; startposition < sublistcount; ++startposition) {
            gapInsertionSort(alist, startposition, sublistcount);
        }
        cout << "After increments of size " << sublistcount << " The list is: ";
        for (int element : alist) {
            cout << element << " ";
        }
        cout << endl;
        sublistcount = sublistcount / 2;
    }
}

int main() {
    vector<int> alist = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    shellSort(alist);
    cout << "Sorted list: ";
    for (int element : alist) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}