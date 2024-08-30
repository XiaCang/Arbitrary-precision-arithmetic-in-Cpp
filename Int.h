#ifndef _INT_H_
#define _INT_H_

#include<vector>
#include<iostream>
using namespace std;

class Int{
private:
    vector<char> data;
    bool isNeg;        
    int digit;
public:
    Int();
    Int(const string num);
    Int(const char *num);
    Int(char num);
    Int(unsigned char num);
    Int(short num);
    Int(unsigned short num);
    Int(int num);
    Int(unsigned int num);
    Int(long num);
    Int(unsigned long num);
    Int(long long num);
    Int(unsigned long long num);

    Int& operator+=(const Int &num);
    Int& operator-=(const Int &num);
    Int& operator*=(const Int &num);
    Int& operator/=(const Int &num);
    Int& operator%=(const Int &num);

    Int& operator++();
    Int operator++(int);
    Int& operator--();
    Int operator--(int);

    friend Int operator+(const Int &num1, const Int &num2);
    friend Int operator-(const Int &num1, const Int &num2);
    friend Int operator*(const Int &num1, const Int &num2);
    friend Int operator/(const Int &num1, const Int &num2);
    friend Int operator%(const Int &num1, const Int &num2);

    friend ostream& operator<<(ostream &out, const Int &num);
    friend istream& operator>>(istream &in, Int &num);

    friend bool operator==(const Int &num1, const Int &num2);
    friend bool operator!=(const Int &num1, const Int &num2);
    friend bool operator<(const Int &num1, const Int &num2);
    friend bool operator<=(const Int &num1, const Int &num2);
    friend bool operator>(const Int &num1, const Int &num2);
    friend bool operator>=(const Int &num1, const Int &num2);

    Int operator-() const;

    string ToString() const;
    char* ToCString() const;
    long long ToInt() const;
    string ToBinary() const;

};

Int operator+(const Int &num1, const Int &num2);
Int operator-(const Int &num1, const Int &num2);
Int operator*(const Int &num1, const Int &num2);
Int operator/(const Int &num1, const Int &num2);
Int operator%(const Int &num1, const Int &num2);

ostream& operator<<(ostream &out, const Int &num);
istream& operator>>(istream &in, Int &num);

bool operator==(const Int &num1, const Int &num2);
bool operator!=(const Int &num1, const Int &num2);
bool operator<(const Int &num1, const Int &num2);
bool operator<=(const Int &num1, const Int &num2);
bool operator>(const Int &num1, const Int &num2);
bool operator>=(const Int &num1, const Int &num2);

Int powInt(Int num1,Int num2);
Int sqrtInt(Int num);
#endif