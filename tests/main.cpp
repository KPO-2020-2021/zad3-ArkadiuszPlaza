#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("test wektora kostruktor"){
    Vector a;
    
    CHECK(a[0]== 0);
    CHECK(a[1]== 0);
}

TEST_CASE("test wektora kostruktor parametycznego"){
    double wek[]={2,3};
    Vector a(wek);
    
    CHECK(a[0]== 2);
    CHECK(a[1]== 3);
}

TEST_CASE("test wektora +"){
 
    
       double wek[]={2,3};
    Vector a(wek);
    Vector b(wek);
    b=b+a;
    CHECK(b[0]== 4);
    CHECK(b[1]== 6);
}

TEST_CASE("sprawdzenie []") {
       double wek[]={2,3};
    Vector a(wek);

   WARN_THROWS(a[10]);
}


TEST_CASE("wektor - wyswietlanie standard") {
       double wek[]={2,3};
    Vector a(wek);
    std::ostringstream out;

    out  <<a;

    CHECK( "2\t3\t" == out.str() );
}


TEST_CASE("wektor - wczytywanie standard") {
   Vector a;
    std::istringstream in("3 4");
    in >> a;
    std::ostringstream out;
    out  <<a; // lub strcmp? ew. == dla LZesp
    CHECK( "3\t4\t" == out.str() );
}

TEST_CASE("test wektora ==") { 
    Vector a,b; 
  
 CHECK( a==b);

 }

///// macierz
 TEST_CASE("test macierzy kostruktor"){
    Matrix a;
    
    for(int i=0; i<2; i++)
     for(int j=0; j<2; j++)
    CHECK(a(i,j)== 0);

}

TEST_CASE("test macierzy kostruktor parametycznego"){
    double m[2][2]={{1,1},{1,1}};
    Matrix a(m);
    
    for(int i=0; i<2; i++)
     for(int j=0; j<2; j++)
    CHECK(a(i,j)== 1);
}

TEST_CASE("test wektora *"){
 
    Matrix a;
       double wek[]={2,3};
   
    Vector b(wek);
    b=a*b;
    CHECK(b[0]== 0);
    CHECK(b[1]== 0);
}

TEST_CASE("sprawdzenie ()") {
  
    Matrix a;

   WARN_THROWS(a(12,31));
}

//prostokat
TEST_CASE("test prostokata kostruktor parametycznego"){
         double wek[]={0,0};
    Rectangle a(Vector(wek),10,10);

    CHECK(a[0][0]== 0);
     CHECK(a[0][1]== 0);
}


TEST_CASE("prostokata - wyswietlanie standard") {
         double wek[]={0,0};
    Rectangle a(Vector(wek),10,10);
    std::ostringstream out;

    out  <<a;

    CHECK( "0\t0\t\n10\t0\t\n10\t10\t\n0\t10\t\n0\t0\t\n" == out.str() );
}


TEST_CASE("test prostokata kostruktor parametycznego"){
         double wek[]={0,0};
    Rectangle a(Vector(wek),10,10);
     double wek2[]={10,10};
   a.translate(Vector(wek2));
    CHECK(a[0][0]== 10);
     CHECK(a[0][1]== 10);
}

TEST_CASE("test prostokata kostruktor parametycznego"){
       Matrix tmpM3;
        tmpM3.calculate(90);
    
          
         double wek[]={0,0};
    Rectangle a(Vector(wek),10,10);
  tmpM3.rotation(a);
  
    CHECK(a[0][0]== 0);
     CHECK(a[0][1]== 0);
}