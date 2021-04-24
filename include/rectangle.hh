#pragma once
#include "vector.hh"


class Rectangle {
  Vector punkt[4];
  public:
  Rectangle(){};
  Rectangle( Vector punkt_s, double szerokosc, double wysokosc); //konstruktor tworzacy Rectangle
   const Vector operator [](int i)const // get
      {
        return punkt[i];
      }
      Vector &operator [](int i)//set
            {
        return punkt[i];
      }    
      Rectangle operator+(Vector &wek);/// sumowanie wwektora przesuniecia do wszystkich punktow Rectanglea

void translate( Vector wek)
{
    *this=*this+wek;
}
void side_lenght();

};
void Rectangle::side_lenght()
{
    double L_b1=sqrt(pow(punkt[0][0]-punkt[1][0],2)+pow(punkt[0][1]-punkt[1][1],2));
    double L_b2=sqrt(pow(punkt[2][0]-punkt[3][0],2)+pow(punkt[2][1]-punkt[3][1],2));
        double S_b1=sqrt(pow(punkt[0][0]-punkt[1][0],2)+pow(punkt[3][1]-punkt[3][1],2));
    double S_b2=sqrt(pow(punkt[2][0]-punkt[3][0],2)+pow(punkt[1][1]-punkt[1][1],2));
    if(L_b1==L_b2)
    {
        std::cout<<"rowne"<<std::endl;
         std::cout<<L_b1<<std::endl;
          std::cout<<L_b2<<std::endl;
    }
    else
    {
          std::cout<<"nie rowne"<<std::endl;
         std::cout<<L_b1<<std::endl;
          std::cout<<L_b2<<std::endl;
    }
        if(S_b1==S_b2)
    {
        std::cout<<"rowne"<<std::endl;
         std::cout<<S_b1<<std::endl;
          std::cout<<S_b2<<std::endl;
    }
    else
    {
          std::cout<<"nie rowne"<<std::endl;
         std::cout<<S_b1<<std::endl;
          std::cout<<S_b2<<std::endl;
    }
}

Rectangle::Rectangle( Vector punkt_s, double szerokosc, double wysokosc)
{
for(int i=0; i<4; i++)
punkt[i]=punkt_s;

punkt[1][0]+=szerokosc;
punkt[2][0]+=szerokosc;
punkt[2][1]+=wysokosc;
punkt[3][1]+=wysokosc;
}

std::ostream& operator << ( std::ostream       &Strm, const Rectangle    &Pr)
{
    for(int i=0; i<4; i++)
        Strm<<Pr[i]<<std::endl;
Strm<<Pr[0]<<std::endl;
    return Strm;
}
Rectangle Rectangle::operator+(Vector &wek)
{
    Rectangle Wynik;
 for(int i=0; i<4; i++)
        Wynik[i]=punkt[i]+wek;
    return Wynik;
}