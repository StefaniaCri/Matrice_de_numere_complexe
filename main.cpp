#include <iostream>
#include <cmath>
#include "NumarComplex.h"
#include "MatriceComplexa.h"
using namespace std;

int main()
{
    int k=1;
   while(k==1){

    cout<<"\nApasa 1 pentru a construi o matrice cu un singur element Numar complex, citit din consola, si a o afiseaza\n";
    cout<<"\nApasa 2 pentru a citi o matrice\n";
    cout<<"\nApasa 3 pentru a aduna doua matrice\n";
    cout<<"\nApasa 4 pentru a inmulti doua matrice\n";
    cout<<"\nApasa 5 pentru a citi n matrice si a le afisa\n";
    cout<<"\nApasa 10 pentru....STOP\n";

    int comanda;
    cin>>comanda;

    switch(comanda){

    case 1:{
        Numar_Complex C1;
        double real,imaginar;
        int linii,coloane;
        cout<<"Partea reala:";
        cin>>real;
        C1.setreal(real);
        cout<<"Partea imaginara";
        cin>>imaginar;
        C1.setimaginar(imaginar);
        cout<<"Numarul de linii:";
        cin>>linii;
        cout<<"Numarul de coloane:";
        cin>>coloane;
       Matrice_Complexa med1(C1,linii,coloane);
       cout<<med1;
       break;
    }
    case 2:{
      Matrice_Complexa med2;
     cin>>med2;
     for(int i=0;i<med2.getlinii();i++){
        for(int j=0;j<med2.getcoloane();j++)
            cout<<*(*(med2.getmatrice()+i)+j);
     cout<<endl;
     }
      break;
    }
    case 3:{
    Matrice_Complexa med1;
    cin>>med1;
    Matrice_Complexa med2;
    cin>>med2;
    cout<<med1+med2;
    break;
    }
     case 4:{
    Matrice_Complexa med1;
    cin>>med1;
    Matrice_Complexa med2;
    cin>>med2;
    cout<<med1*med2;
    break;
     }
     case 5:{
     int n;
     cout<<"N=";
     cin>>n;
     Matrice_Complexa a;
     a.citire(n);
     break;
     }
     case 10:
        k=0;
        break;
    default:{

        cout<<"\n\t\t COMADNA INCORECTA\t\t\n";
        break;

    }

    }
    }

    return 0;
}
