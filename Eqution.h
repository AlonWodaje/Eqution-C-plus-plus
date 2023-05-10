#include <iostream>
#include <string.h>
#include <iterator>
#include <ostream>
#include<fstream>
#include <math.h>
using namespace std;

class Eqution
{

private:
    double a;
    double b;
    double c;
    double *solutions;
    size_t solutions_size;

public:

    Eqution(double A=0, double B=0, double C=0): solutions(new double[2]{})
    {
        a=A;
        b=B;
        c=C;
    }
    ~Eqution(){/*delete [] solutions;*/};

    Eqution(Eqution const &other)
    {
        a=other.a;
        b=other.b;
        c=other.c;
    }

    Eqution(Eqution const &&other)
    {
    
        a=other.a;
        b=other.b;
        c=other.c;
        solutions_size = other.solutions_size;
        solutions = other.solutions;
        delete [] other.solutions; 
    }

    void set_a(double A) {a=A;}
    void set_b(double B) {b=B;}
    void set_c(double C) {c=C;}
    
    double get_a() {return a;}
    double get_b() {return b;}
    double get_c() {return c;}
    size_t get_solutions_size() {return solutions_size;}
    double const * const get_solutions(){return solutions;}

    void show() {std::cout<< "a = " << a << " , b = " << b << " , c = " << c << "\n";}

    friend ostream& operator<<(std::ostream& os, Eqution& o);

    Eqution operator+( const Eqution& o);

    Eqution& operator=( Eqution& o);

    Eqution& operator=(Eqution&& o) noexcept;

    //fuonction ( Eqution + int  ):
    friend Eqution operator+(const Eqution& o, const int num ){
        Eqution new_Eqution;
        new_Eqution.c += num;
        return new_Eqution; 
    }

    //fuonction ( int + Eqution ):
    friend Eqution operator+(const int num, const Eqution& o ){
        Eqution new_Eqution;
        new_Eqution.c += num;
        return new_Eqution; 
    }

    void solve();

};

