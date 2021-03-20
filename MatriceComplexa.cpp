#include "MatriceComplexa.h"
#include "NumarComplex.h"
//constructor de initializare fara parametrii
Matrice_Complexa::Matrice_Complexa(){
     this->linii=100;
     this->coloane=100;
     this->matrice=new Numar_Complex*[linii];
     for(int i=0;i<linii;i++)
        this->matrice[i]=new Numar_Complex[coloane];
     Numar_Complex val(0,0);
     for(int i=0;i<linii;i++)
        for(int j=0;j<coloane;j++)
            matrice[i][j]=val;
}
//destructor
Matrice_Complexa::~Matrice_Complexa(){
    for(int i=0;i<linii;i++)
        delete []matrice[i];
    delete []matrice;
}
//constructor de intializare cu parametrii
Matrice_Complexa::Matrice_Complexa(int linii,int coloane){
     this->linii=linii;
     this->coloane=coloane;
     this->matrice= new Numar_Complex*[linii];
     for(int i=0;i<linii;i++)
        this->matrice[i]=new Numar_Complex[coloane];
     Numar_Complex val(0,0);
     for(int i=0;i<this->linii;i++)
        for(int j=0;j<this->coloane;j++)
            this->matrice[i][j]=val;
}
//construirea unei matrice cu un singur element
Matrice_Complexa::Matrice_Complexa(Numar_Complex elem,int linii,int coloane){
 this->linii=linii;
     this->coloane=coloane;
     this->matrice= new Numar_Complex*[linii];
     for(int i=0;i<linii;i++)
        this->matrice[i]=new Numar_Complex[coloane];
     for(int i=0;i<this->linii;i++)
        for(int j=0;j<this->coloane;j++)
            this->matrice[i][j]=elem;
}
//constructorul de copiere
Matrice_Complexa::Matrice_Complexa(const Matrice_Complexa &ob){
    this->linii=ob.linii;
     this->coloane=ob.coloane;
     this->matrice= new Numar_Complex*[linii];
     for(int i=0;i<linii;i++)
        this->matrice[i]=new Numar_Complex[coloane];
     for(int i=0;i<this->linii;i++)
        for(int j=0;j<this->coloane;j++)
            this->matrice[i][j]=ob.matrice[i][j];
}
//supraincarcarea operatorului <<
std::ostream& operator<<(std::ostream &out,const Matrice_Complexa &ob){
    out<<"Matricea complexa:"<<'\n';
    for(int i=0;i<ob.linii;i++){
        for(int j=0;j<ob.coloane;j++)
            out<<ob.matrice[i][j]<<"  ";
    out<<'\n';
    }
    return out;
}
//supraicarcarea operatorului >>
std::istream& operator>>(std::istream& in, Matrice_Complexa &ob){
   std::cout<<"Numar linii:";
   in>> ob.linii;
   std::cout<<"Numar coloane:";
   in>>ob.coloane;
   if (ob.matrice!=NULL){
    for(int i=0;i<ob.linii;i++)
        delete []ob.matrice[i];
    delete []ob.matrice;
   }
    ob.matrice=new Numar_Complex*[ob.linii];
     for(int i=0;i<ob.linii;i++)
        ob.matrice[i]=new Numar_Complex[ob.coloane];
     for(int i=0;i<ob.linii;i++)
        for(int j=0;j<ob.coloane;j++)
            in>>ob.matrice[i][j];
    return in;

}
//supraincarcarea operatorului +
//daca dimesiunea matricelor nu este buna rezultatul generat va fi:
// -1+0i -1+0i
// -1+0i -1+0i
Matrice_Complexa Matrice_Complexa::operator+(const Matrice_Complexa &ob){
if(this->coloane!=ob.coloane && this->linii!=ob.linii){
    std::cout<<"Matricele nu au dimensiunea corecta\n";
    Numar_Complex c(-1,0);
    Matrice_Complexa c1(c,2,2);
    return c1;
}
else{
Numar_Complex c0;
Matrice_Complexa rezultat(c0,this->linii,this->coloane);
for(int i=0;i<rezultat.linii;i++)
    for(int j=0;j<rezultat.coloane;j++)
       rezultat.matrice[i][j]=this->matrice[i][j]+ob.matrice[i][j];
return rezultat;
}
}
//supraincarecarea operatorului *
//daca dimesiunea matricelor nu este buna rezultatul generat va fi:
// -1+0i -1+0i
// -1+0i -1+0i
Matrice_Complexa Matrice_Complexa::operator*(const Matrice_Complexa &ob){
if (this->coloane!=ob.linii){
    std::cout<<"Matricele nu au dimensiunea corecta: Pentru a inmulti doua matrice nr coloanelor primei matrice trebuie sa fie egala cu numarul linilor celei de-a doua matrice \n";
     Numar_Complex c(-1,0);
    Matrice_Complexa c1(c,2,2);
    return c1;
}
else{
Numar_Complex c1(0,0);
Matrice_Complexa rezultat(c1,this->linii,ob.coloane);
for(int i=0;i<rezultat.linii;i++)
    for(int j=0;j<rezultat.coloane;j++)
       for(int k=0;k<this->coloane;k++){
             rezultat.matrice[i][j]=rezultat.matrice[i][j]+this->matrice[i][k]*ob.matrice[k][j];

       }
return rezultat;
}
}
//geter pentru linii
int Matrice_Complexa::getlinii(){
    return this->linii;
}
//geter pentru coloane
int Matrice_Complexa::getcoloane(){
    return this->coloane;
}
//geter pentru matrice
Numar_Complex** Matrice_Complexa::getmatrice(){
    return this->matrice;
}
//seter pentru linii
void Matrice_Complexa::setlinii(int linii){
   this->linii=linii;
}
//seter pentru coloane
void Matrice_Complexa::setcoloane(int coloane){
  this->coloane=coloane;
}
//metoda pentru setat o noua matrice
void Matrice_Complexa::setmatrice(Numar_Complex **matrice,int linii, int coloane){
  if(this->matrice!=NULL){
      for(int i=0;i<this->linii;i++)
        delete []matrice[i];
    delete []matrice;
  }
  this->coloane=coloane;
  this->linii=linii;
   this->matrice= new Numar_Complex*[linii];
     for(int i=0;i<linii;i++)
        this->matrice[i]=new Numar_Complex[coloane];
     Numar_Complex val(0,0);
     for(int i=0;i<this->linii;i++)
        for(int j=0;j<this->coloane;j++)
            this->matrice[i][j]=val;
}
//metoda publica petru citirea si afisarea a n matrice
void Matrice_Complexa::citire(int n)
{
    Matrice_Complexa *a;
    a=new Matrice_Complexa[n];
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        std::cout<<a[i];
        std::cout<<"\n";
    }
    delete []a;
}
