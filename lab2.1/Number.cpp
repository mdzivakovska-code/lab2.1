// Number.cpp
#include "Number.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

Number::Number()
{
    SetFirst(0);
    SetSecond(0);
}

Number::Number(double f, double s)
{
    SetFirst(f);
    SetSecond(s);
}

Number::Number(const Number& r)
{
    first = r.first;
    second = r.second;
}

Number::~Number()
{
}

void Number::SetFirst(double f)
{
    if (f == trunc(f))
        first = f;
    else
        first = 0;
}

void Number::SetSecond(double s)
{
    if (s >= 0.0 && s < 1.0)
        second = s;
    else
        second = 0;
}

double Number::GetFirst() const
{
    return first;
}

double Number::GetSecond() const
{
    return second;
}

Number& Number::operator = (const Number& r)
{
    first = r.first;
    second = r.second;

    return *this;
}

Number::operator string () const
{
    stringstream ss;
    double fullValue = (first < 0 || signbit(first)) ? (first - second) : (first + second);
    ss << " first = " << first << endl;
    ss << " second = " << second << endl;
    ss << " (число: " << fullValue << ")" << endl;

    return ss.str();
}

Number operator * (const Number& n, double scalar)
{
    double fullValue = (n.first < 0 || signbit(n.first)) ? (n.first - n.second) : (n.first + n.second);
    double result = fullValue * scalar;

    double intPart;
    double fracPart = modf(result, &intPart);

    return Number(intPart, fabs(fracPart));
}

Number operator * (double scalar, const Number& n)
{
    return n * scalar;
}

ostream& operator << (ostream& out, const Number& r)
{
    out << string(r);
    return out;
}

istream& operator >> (istream& in, Number& r)
{
    double f, s;
    cout << " first = "; in >> f;
    cout << " second = "; in >> s;
    cout << endl;

    r.SetFirst(f);
    r.SetSecond(s);

    return in;
}

Number& Number::operator ++()
{
    first++;
    return *this;
}

Number& Number::operator --()
{
    first--;
    return *this;
}

Number Number::operator ++(int)
{
    Number t(*this);
    second += 0.1;
    if (second >= 1.0)
        second -= 1.0;
    return t;
}

Number Number::operator --(int)
{
    Number t(*this);
    second -= 0.1;
    if (second < 0.0)
        second += 1.0;
    return t;
}


Number makeNumber(double x, double y)
{
    if (x != trunc(x) || y < 0.0 || y >= 1.0)
    {
        cout << "wrong argument to Init" << endl;
        exit(1);
    }
    return Number(x, y);
}