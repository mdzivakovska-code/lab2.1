
// Number.h
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number
{
    double first;
    double second;

public:
    Number();
    Number(double, double);
    Number(const Number&);
    ~Number();

    void SetFirst(double);
    void SetSecond(double);
    double GetFirst() const;
    double GetSecond() const;

    Number& operator = (const Number&);
    operator string() const;

    friend Number operator * (const Number&, double);
    friend Number operator * (double, const Number&);

    friend ostream& operator << (ostream&, const Number&);
    friend istream& operator >> (istream&, Number&);

    Number& operator ++();
    Number& operator --();
    Number operator ++(int);
    Number operator --(int);
};

Number makeNumber(double, double);