#pragma once
class Polynom
{
private:
    double coeff[1000];
    int degree;
public:
    Polynom();
    Polynom(const Polynom&);
    Polynom(double);
    Polynom(int deg, int val);
    void getPolynom();
    void setPolynom(int);
    double polValue(double);
    void mult(const Polynom&,  const Polynom& );
    void operator=(const Polynom&);
    Polynom operator+(const Polynom&);
    void operator+=(const Polynom&);
    Polynom operator-(const Polynom&);
    void operator-=(const Polynom&);
    Polynom operator*(const Polynom&);
    void operator*=(const Polynom&);
    double& operator[](int);
    friend std::ostream& operator<<(std::ostream&, const Polynom&);//how to do this weird function?
    friend std::istream& operator>>(std::istream&, Polynom&);
};