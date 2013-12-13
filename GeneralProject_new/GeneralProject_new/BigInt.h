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
    static const int v=5;
    BigInt(string& input);
    BigInt(int input);
    BigInt(long long input);
    BigInt();
    BigInt(BigInt & number);
    
    friend ostream & operator<<(std::ostream & os, BigInt & number);
    friend istream & operator>>(std::istream & is, BigInt & number);
    BigInt BigIntAbs();
    BigInt operator=(BigInt equal);
    friend BigInt operator+(BigInt summand1, BigInt summand2);
    BigInt operator+=(BigInt summand);
    friend BigInt operator-(BigInt minuend, BigInt subtrahend);
    BigInt operator-=(BigInt subtrahend);
    friend BigInt operator*(BigInt multiplier1, BigInt multiplier2);
    BigInt operator*=(BigInt multiplier);
    friend BigInt operator/(BigInt dividend, BigInt divider);
    BigInt operator/=(BigInt divider);
    friend BigInt operator%(BigInt number, BigInt modulo);
    BigInt operator%=(BigInt modulo);
    friend bool operator>(BigInt number1, BigInt number2);
    friend bool operator<=(BigInt number1, BigInt number2);
};
