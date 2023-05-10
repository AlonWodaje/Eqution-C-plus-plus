#include "Eqution.h"
using namespace std;


    // printer
    ostream& operator<<(std::ostream& os, Eqution& o)
    {
        // os << "hello\n";
        os <<  "a = " << o.get_a() << " ; b = " << o.get_b() << " ; c = " << o.get_c() << "\n";
        return os;
    }

     // Eqution + Eqution
    Eqution Eqution::operator+( const Eqution& o)
    {
        Eqution new_eq;

        new_eq.a = o.a + this->a;
        new_eq.b = o.b + this->b;
        new_eq.c = o.c + this->c;

        return new_eq;
    }

    // Eqution = Eqution
    // copy assignment operator
    Eqution& Eqution::operator=( Eqution& o)
    {        
        if(this == &o)
            return *this;

        if(solutions)
            delete [] solutions;

        solutions = new double[2];
        this->a = o.a;
        this->b = o.b;
        this->c = o.c;
        return *this;
    }
    
    //Eqution = Eqution + Eqution
    // move assignment operator
    Eqution& Eqution::operator=(Eqution&& o) noexcept
    {
		if(this != &o) {
            this->a = o.a;
            this->b = o.b;
            this->c = o.c;
            o.solutions = nullptr;
		}

        return *this;
    }


    void Eqution::solve()
    {
        double size_of_solution;
        size_of_solution = b*b - (4*a*c);

        if( size_of_solution > 0 )
        {
            double numner;
            numner = sqrt(size_of_solution);
            this->solutions[0] = (-b + numner) / (2*a);
            this->solutions[1] = (-b - numner) / (2*a);
            std::cout << "solutions[0] = " << solutions[0];
            std::cout << " ; solutions[1] = " << solutions[1];
        }
        else if( size_of_solution == 0 )
        {
            this->solutions_size = 1;
            delete[] this->solutions;
            this->solutions = new double[ this->solutions_size ];
            this->solutions[0] = -b / (2*a);
            std::cout << "solutions[0] = " << solutions[0];
        }
        else if(size_of_solution < 0)
        {
            delete[] this->solutions;
            std::cout << "dont have solutions" ;
        }
    }