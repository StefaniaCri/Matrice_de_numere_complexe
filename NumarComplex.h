#ifndef NUMARCOMPLEX_H_INCLUDED
#define NUMARCOMPLEX_H_INCLUDED
#include <iostream>
class Numar_Complex{
private:
    double real,imaginar;
public:
    Numar_Complex();
    ~Numar_Complex();
    Numar_Complex(int real,int imaginar);
    Numar_Complex(const Numar_Complex &ob);
    double getreal();
    double getimaginar();
    void setreal(double real);
    void setimaginar(double imaginar);
    void afisare();
    double modul();
    Numar_Complex operator+ (const Numar_Complex &ob);
    Numar_Complex operator*(const Numar_Complex &ob);
    Numar_Complex operator/(const Numar_Complex &ob);
    friend std::ostream& operator<<(std::ostream& out, const Numar_Complex& ob);
    friend std::istream& operator>>(std::istream& in, Numar_Complex &ob);
};
#endif
