#pragma once
#include <vector>
class Polynom
{
private:
    double coeff[1000];
    int degree;
    int x;
public:
    Polynom();
    Polynom(const Polynom&);
    Polynom(double);
    Polynom(int deg, int val, int xe);
    void getPolynom();
    void setPolynom(int);
    double polValue(double);
    double polValue();
    void mult(const Polynom&,  const Polynom& );
    void operator=(const Polynom&);
    Polynom operator+(const Polynom&);
    void operator+=(const Polynom&);
    Polynom operator-(const Polynom&);
    void operator-=(const Polynom&);
    Polynom operator*(const Polynom&);
    void operator*=(const Polynom&);
    friend Polynom operator*(int, Polynom);
    friend Polynom pow(Polynom, Polynom);
    bool operator==(int);
    bool operator<(Polynom);
    Polynom operator*(int);
    double& operator[](int);
    friend std::ostream& operator<<(std::ostream&, const Polynom&);//how to do this weird function?
    friend std::istream& operator>>(std::istream&, Polynom&);
};


    static int xe = 0;
    