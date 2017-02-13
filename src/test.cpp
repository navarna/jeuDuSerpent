#include <iostream>
#include <vector>
using namespace std ;
vector <int*> v ; 
void test () {
  int la [2]= {1,2} ;
  v.push_back(la) ;
}

int main (int argc , char* argv[]) {
  //vector <int*>v ;
  //int la [2]= {1,2} ;
  //cout << la[0] << endl ;
  //v.push_back(la) ;
  test() ;
  cout << v[0][1] <<endl ;
  return 0 ;
}
