#include "Case.hpp"

Case::Case(int numero, int symbole): numero(numero), symbole(symbole)
{
    //ctor
}

ostream& operator<<(ostream& o, Case &x){
    if(x.numero+1>9){
    o << x.numero+1 << '-' << x.symbole ;
    }
    else{
    o <<"0"<< x.numero+1 << '-' << x.symbole ;

    }
    return o;
}

int Case::getSymbole(){
    return symbole;
}

void Case::setSymbole(int n){
    symbole=n;
}


Case::~Case()
{
    //dtor
}
