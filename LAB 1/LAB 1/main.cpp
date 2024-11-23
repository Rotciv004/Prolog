#include "list.h"
#include <iostream>

using namespace std;

int main()
{
    List l1 = create();
    cout << "List 1: ";
    print(l1);
    cout << endl;

    cout << "The sum betwen odd - eaven: " << sumEvenSubtractOdd(l1) << endl;

    List l2 = create();
    cout << "List 2: ";
    print(l2);
    cout << endl;

    List diff = difference(l1, l2);
    cout << "Difference (List 1 - List 2): ";
    print(diff);
    cout << endl;

    destroy(l1);
    destroy(l2);
    destroy(diff);

    return 0;
}
