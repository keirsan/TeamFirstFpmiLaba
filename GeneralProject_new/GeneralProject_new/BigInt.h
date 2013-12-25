#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class BigInt
{
private:
    vector<int> digits;//9 digits in one int
    bool sign;//0-plus,1-minus
    void removeLeadingZeros();
public:
    BigInt(string& input);
    BigInt(int input);
    BigInt(long long input);
    BigInt();
    BigInt(BigInt & number);
    BigInt(double lol)
    {
        ;
    }
    friend ostream & operator<<(std::ostream & os, BigInt & number);
    friend istream & operator>>(std::istream & is, BigInt & number);
    BigInt BigIntAbs();
    BigInt operator=(const BigInt & equal);
    BigInt operator+=(BigInt summand);
    BigInt operator-=(BigInt subtrahend);
    BigInt operator*=(BigInt multiplier);
    BigInt operator^(int degree);
    friend bool operator>(BigInt number1, BigInt number2);
    friend bool operator<(BigInt number1, BigInt number2);
    friend bool operator<=(BigInt number1, BigInt number2);
    long long getLongLong();
    int getInt();
};
BigInt operator+(BigInt summand1, BigInt summand2);
BigInt operator-(BigInt minuend, BigInt subtrahend);
BigInt operator*(BigInt multiplier1, BigInt multiplier2);
