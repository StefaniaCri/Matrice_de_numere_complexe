#include "NumarComplex.h"
#include <cmath>
//constructor de initializare fara parametrii:
Numar_Complex::Numar_Complex(){
    this->real=0;
    this->imaginar=0;
}

//destructor
Numar_Complex::~Numar_Complex(){
   this->real=0;
   this->imaginar=0;
}
//constructor de initializare cu parametrii
Numar_Complex::Numar_Complex(int real,int imaginar){
    this->real=real;
    this->imaginar=imaginar;
}
//constructor de copiere
Numar_Complex::Numar_Complex(const Numar_Complex &ob){
  this->real=ob.real;
  this->imaginar=ob.imaginar;
}
//geter pentru partea reala
double Numar_Complex::getreal(){
  return real;
}
//geter pentru partea imaginara
double Numar_Complex::getimaginar(){
return imaginar;
}
//seter pentru partea reala
void Numar_Complex::setreal(double real){
    this->real=real;
}
//seter pentru partea imaginare
void Numar_Complex::setimaginar(double imaginar){
    this->imaginar=imaginar;
}
//afisare (sub forma "a", "i*a","-i*a","a+i*b","a-i*b"
void Numar_Complex::afisare(){
    if (this->imaginar>0)
    std::cout<<this->real<<" + i*"<<this->imaginar<<std::endl;
     if (this->imaginar<0)
    std::cout<<this->real<<" - i*"<<std::abs(this->imaginar)<<std::endl;

    if (this->imaginar==0)
    std::cout<<this->real<<std::endl;

    if (this->real==0&&this->imaginar>0)
    std::cout<<"i*"<<this->imaginar<<std::endl;
    if (this->real==0 && this->imaginar<0)
    std::cout<<"-i*"<<std::abs(this->imaginar)<<std::endl;
}
//metoda pentru furnizarea modulului unui numar complex
double Numar_Complex::modul(){
return sqrt(pow(this->real,2)+pow(this->imaginar,2));
}
//supranincarcarea operatorului +
Numar_Complex Numar_Complex::operator+ (const Numar_Complex &ob){
Numar_Complex rezultat;
rezultat.real=this->real+ob.real;
rezultat.imaginar=this->imaginar+ob.imaginar;
return rezultat;
}
//supraincarcarea operatorului *
Numar_Complex Numar_Complex::operator*(const Numar_Complex &ob){
Numar_Complex rezultat;
rezultat.real=(this->real*ob.real)-(this->imaginar*ob.imaginar);
rezultat.imaginar=(this->real*ob.imaginar)+(this->imaginar*ob.real);
return rezultat;

}
//supraincarcarea operatorului /
Numar_Complex Numar_Complex::operator/(const Numar_Complex &ob){
Numar_Complex rezultat;
double exponent=(pow(ob.real,2)+pow(ob.imaginar,2));
rezultat.real=((this->real*ob.real)+(this->imaginar*ob.imaginar))/exponent;
rezultat.imaginar=((ob.real*this->imaginar)-(this->real*ob.imaginar))/exponent;
return rezultat;
}
//supraincarcarea operatorului <<
std::ostream& operator<<(std::ostream &out,const Numar_Complex &ob){
    out<<ob.real<<"+("<<ob.imaginar<<")*i"<<" ";
    return out;
}
//supraincarcarea operatorului >>
std::istream& operator>>(std::istream& in, Numar_Complex &ob){
    in>>ob.real>>ob.imaginar;
    return in;
}

