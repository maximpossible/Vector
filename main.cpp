#include <iostream>
#include <time.h>
#include <random>
#include "Funcs.h"

using namespace std;

int main()
{
    Vector <int> arr;
    Vector <int> arb;

    int arr_size, arb_size;

    cout << "Input arr1 size: ";
    cin >> arr_size;
    cout << "Input arr2 size: ";
    cin >> arb_size;

    srand(time(0));
    for (int i = 0; i < arr_size; i++)
    {
        arr.push_back(rand() % 21);
    }
    arr.show();

    for (int i = 0; i < arb_size; i++)
    {
        arb.push_back(rand() % 21 + 20);
    }
    arb.show();

    cout << "==================================================" << endl;

    cout << "Insertion arr2 into arr1 in pos = 2: " << endl << endl;
    arr.insert(arb, 2);
    cout << "arr1: ";
    arr.show();

    cout << "==================================================" << endl;

    cout << "Max element of arr1: " << arr.max() << endl;

    cout << "==================================================" << endl;

    return 0;
}
