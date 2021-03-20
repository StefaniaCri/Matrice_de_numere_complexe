#ifndef MATRICECOMPLEXA_H_INCLUDED
#define MATRICECOMPLEXA_H_INCLUDED
#include "NumarComplex.h"
class Matrice_Complexa{
private:
    int linii,coloane;
    Numar_Complex **matrice;
public:
    Matrice_Complexa();
    Matrice_Complexa(int linii,int coloane);
    ~Matrice_Complexa();
    Matrice_Complexa(Numar_Complex elem,int linii,int coloane);
    Matrice_Complexa(const Matrice_Complexa &ob);
    friend std::ostream& operator<<(std::ostream& out, const Matrice_Complexa& ob);
    friend std::istream& operator>>(std::istream& in, Matrice_Complexa &ob);
    Matrice_Complexa operator+(const Matrice_Complexa &ob);
    Matrice_Complexa operator*(const Matrice_Complexa &ob);
    int getlinii();
    int getcoloane();
    Numar_Complex** getmatrice();
    void setlinii(int linii);
    void setcoloane(int coloane);
    void setmatrice(Numar_Complex ** matrice, int linii, int coloane);
    void citire(int n);
};

#endif
