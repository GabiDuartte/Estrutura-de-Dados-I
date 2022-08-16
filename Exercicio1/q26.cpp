#include <iostream>
using namespace std;

main(){
       
      float p, t, c, a;
      int n;
      
      cout << "\n Anos fumando: ";
      cin >> a;
      cout <<"\n Quantidade de cigarros fumados em carteiras: ";
      cin >> n;
      cout <<"\n Preço de uma carteira: ";
      cin >> p;
      c = n*365;
      t = p*c*a;
      cout << "\n A quantidade de dinheiro gasta ao total e: " << t;
      }
