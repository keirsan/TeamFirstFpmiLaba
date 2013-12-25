#include "BigInt.h"

BigInt::BigInt(string& input)
{
    if (input.size() == 0)
    {
        this->sign = false;
        return;
    }

    int current = 0;
    if (input[0] == '-')
    {
        this->sign = true;
        current++;
    }
    else
        this->sign = false;


    for (int i = input.size() - 1; i >= current; i -= 9)
    {
        int temp = 0;
        int base = 1;
        for (int j = i; j >= current && j > i - 9; j--)
        {
            temp += base * (input[j] - '0');
            base *= 10;
        }
        this->digits.push_back(temp);
    }

    removeLeadingZeros();

}


BigInt::BigInt(int input)
{
    input >= 0 ? sign = false : sign = true;
    input = abs(input);
    while (input > 0)
    {
        digits.push_back(input%1000000000);
        input /= 1000000000;
    }
}

BigInt::BigInt(long long input)
{
    input >= 0 ? sign = false : sign = true;
    input = abs(input);
    while (input > 0)
    {
        digits.push_back(input%1000000000);
        input /= 1000000000;
    }
}

BigInt::BigInt()
{
    sign = false;
}

BigInt::BigInt(BigInt & number)
{
    this->sign = number.sign;
    this->digits.resize(number.digits.size());
    for (int i = 0; i < number.digits.size(); i++)
        this->digits[i] = number.digits[i];
    //return *this;
}

void BigInt::removeLeadingZeros()
{
    while(this->digits.size() && digits.back() == 0)
        this->digits.pop_back();

    if (!this->digits.size())
        this->sign = false;
}

int max(int x, int y)
{
    if (x > y) return x;
    else return y;
}

BigInt BigInt::operator=(const BigInt & equal)
{
    this->sign = equal.sign;
    this->digits.resize(equal.digits.size());
    for (int i = 0; i < equal.digits.size(); i++)
        this->digits[i] = equal.digits[i];
    return *this;
}

BigInt operator+(BigInt summand1, BigInt summand2)
{
    summand1 += summand2;
    return summand1;
}

BigInt BigInt::operator+=(BigInt summand)
{
    if (this->sign != summand.sign){
        BigInt subtrahend = summand;
        subtrahend.sign = !subtrahend.sign;
        *this -= subtrahend;
        return *this;
    }

    BigInt sum;
    sum.sign = this->sign;
    int size = max(this->digits.size(), summand.digits.size());

    int memory = 0;
    for (int i = 0; i < size; i++){
        int curr = memory + (i<this->digits.size() ? this->digits[i] : 0) + (i < summand.digits.size() ? summand.digits[i] : 0);
        memory = curr/1000000000;
        curr %= 1000000000;
        sum.digits.push_back(curr);
    }
    if (memory>0)
        sum.digits.push_back(memory);
    *this = sum;
    return sum;
}

BigInt BigInt::operator-=(BigInt subtrahend)
{
    if (this->sign != subtrahend.sign){
        BigInt summand = subtrahend;
        summand.sign = !summand.sign;
        *this += summand;
        return *this;
    }

    if (!this->sign && subtrahend > (*this))
    {
        BigInt answer = subtrahend - (*this);
        answer.sign = true;
        *this = answer;
        return answer;
    }

    if (this->sign && (*this) > subtrahend)
    {
        BigInt answer = subtrahend - (*this);
        answer.sign = false;
        *this = answer;
        return answer;
    }

    BigInt diff;
    diff.sign = this->sign;
    bool memory = 0;
    for (int i = 0; i < this->digits.size(); i++){
        int curr = this->digits[i] - (i<subtrahend.digits.size() ? subtrahend.digits[i] : 0) - memory;
        memory = 0;
        if (curr < 0)
        {
            curr += 1000000000;
            memory = 1;
        }
        diff.digits.push_back(curr);
    }

    diff.removeLeadingZeros();

    *this = diff;
    return diff;
}

BigInt operator-(BigInt minuend, BigInt subtrahend)
{
    minuend -= subtrahend;
    return minuend;
}

BigInt BigInt::operator*=(BigInt multiplier)
{
    BigInt product;
    product.sign = (this->sign != multiplier.sign);
    product.digits.resize(this->digits.size() + multiplier.digits.size(), 0);

    int memory = 0;
    for (int i = 0; i<this->digits.size(); i++)
    {
        for (int j = 0; j<multiplier.digits.size(); j++)
        {
            long long temp = 1ll*this->digits[i] * multiplier.digits[j] + product.digits[i+j] + memory;
            memory = temp / 1000000000;
            product.digits[i + j] = temp % 1000000000;
        }
        if (memory>0)
        {
            product.digits[i+multiplier.digits.size()] = memory;
            memory = 0;
        }

    }
    product.removeLeadingZeros();
    *this = product;
    return product;
}

BigInt operator*(BigInt multiplier1, BigInt multiplier2)
{
    multiplier1 *= multiplier2;
    return multiplier1;
}

BigInt BigInt::operator^(int degree)
{
    BigInt curr(1);
    BigInt base(*this);
    while (degree)
    {
        if (degree&1)
        {
            curr *= base;
            degree--;
        }
        else
        {
            base *= base;
            degree >>= 1;
        }
    }
    return curr;
}

bool operator>(BigInt number1, BigInt number2)
{
    if (number1.sign && !number2.sign)
        return false;
    if (!number1.sign && number2.sign)
        return true;
    if (number1.digits.size() > number2.digits.size())
        return !number1.sign;
    if (number1.digits.size() < number2.digits.size())
        return number1.sign;
    for (int i = number1.digits.size() - 1; i>=0; i--)
    {
        if (number1.digits[i] > number2.digits[i])
            return !number1.sign;
        if (number1.digits[i] < number2.digits[i])
            return number1.sign;
    }
    return false;
}

bool operator<(BigInt number1, BigInt number2)
{
    return (number2 > number1);
}

bool operator<=(BigInt number1, BigInt number2)
{
    if (number1.sign && !number2.sign)
        return true;
    if (!number1.sign && number2.sign)
        return false;
    if (number1.digits.size() > number2.digits.size())
        return number1.sign;
    if (number1.digits.size() < number2.digits.size())
        return !number1.sign;
    for (int i = number1.digits.size() - 1; i>=0; i--)
    {
        if (number1.digits[i] > number2.digits[i])
            return number1.sign;
        if (number1.digits[i] < number2.digits[i])
            return !number1.sign;
    }
    return true;
}

BigInt BigInt::BigIntAbs()
{
    BigInt abs = *this;
    abs.sign = false;
    return abs;
}

long long BigInt::getLongLong()
{
    long long answer = (digits.size() ? digits[0]:0) + (digits.size()>1 ? digits[1]:0)*1000000000;
    if (digits.size()>2 && digits[2]<5)
        answer += 1000000000000000000*digits[2];
    if (sign)
        answer *= -1;
    //if (digits.size()>3 || (digits.size()==3  && digits[2] > 4))
    // ERROR!!!!!!!
    return answer;
}

int BigInt::getInt()
{
    int answer = (digits.size() ? digits[0]:0);
    if (digits.size()>1 && digits[1]<3)
        answer += 1000000000*digits[1];
    if (sign)
        answer *= -1;
    //if (digits.size()>2 || (digits.size()==2  && digits[1] > 2))
    // ERROR!!!!!!!
    return answer;
}

ostream & operator<<(ostream&  out, BigInt & number)
{
    if (!number.digits.size())
    {
        out << 0;
        return out;
    }
    if (number.sign)
        out << '-';
    out << number.digits[number.digits.size() - 1];
    for (int i = number.digits.size() - 2; i >= 0; i--)
    {
        int curr = number.digits[i];
        int temp = curr;
        int digits = 0;
        while (temp)
        {
            digits++;
            temp /= 10;
        }
        for (int j = 0; j < 9 - digits; j++)
            out << '0';
        if (curr)
            out << curr;
    }
    return out;
}

istream & operator>>(std::istream & is, BigInt & number)
{
    string input;
    cin >> input;
    number = (string)input;
    return is;
}