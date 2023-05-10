#include "Eqution.h"
// #include "Eqution.h"
using namespace std;

int main(){
    Eqution q1(5,5,5);
    std::cout << "q1 : " << q1 ;

    Eqution q2(q1);
    std::cout << "q2 : " << q2 ;

    Eqution q3;
    q3 = q2; //Copy assignment operator
    std::cout << "q3 = q2 : " << q3;

    Eqution q4;
    q4 = q1 + q2; //move assignment operator
    std::cout << "q4 = q1 + q2 : " << q4;

    Eqution q5;
    q5 = 30 + q4; 
    std::cout << "q5 = 30 + q4 : " << q5;

    Eqution q7(2,4,2), q8(10,10,10), q9(1,2,0);
    std::cout << "\n";
    std::cout << q7;
    q7.solve();
    std::cout << "\n";
    std::cout << "\n" << q8;
    q8.solve();
    std::cout << "\n";
    std::cout<< "\n"  << q9;
    q9.solve();
    std::cout << "\n\n";

}

