#ifndef CASE_H
#define CASE_H
#include <iostream>
using namespace std;
class Case
{
    public:
        Case(int numero, int symbole);
        virtual ~Case();
        friend ostream& operator<<(ostream& o, Case &x);
        int getSymbole();
        void setSymbole(int n);
    protected:
        int numero;
        int symbole;
    private:
};

#endif // CASE_H
