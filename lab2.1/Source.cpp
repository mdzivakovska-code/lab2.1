// Source.cpp
#include <iostream>
#include <windows.h>
#include "Number.h"

using namespace std;

#pragma pack(push, 1)
class PackedNumber
{
    double first;
    double second;
};
#pragma pack(pop)

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " Створення та інкремент/декремент" << endl;
    Number a(10, 0.5);
    cout << "a++:" << endl << a++ << endl;
    cout << "a після a++:" << endl << a << endl;
    cout << "++a:" << endl << ++a << endl;
    cout << "a після ++a:" << endl << a << endl;

    cout << " Введення об'єкта " << endl;
    Number x;
    cout << "Input number ->" << endl;
    cin >> x;
    cout << "x:" << endl << x;

    cout << "Множення " << endl;
    Number y;
    y = x * 2.5;
    cout << "Result: y = x * 2.5 =" << endl;
    cout << y;

    cout << "Масив об'єктів " << endl;
    Number arr[2] = { Number(1, 0.2), Number(3, 0.4) };
    for (int i = 0; i < 2; i++)
    {
        cout << "arr[" << i << "]:" << endl << arr[i];
    }

    cout << "Розміри класів " << endl;
    cout << "sizeof(Number) = " << sizeof(Number) << " bytes" << endl;
    cout << "sizeof(PackedNumber) = " << sizeof(PackedNumber) << " bytes" << endl;

    return 0;
}
