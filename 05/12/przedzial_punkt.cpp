#include <iostream>


using namespace std;


const int L = 1 << 17;
int tab[2*L];

int zapytaj(int gdzie) {
  // zmienna gdzie oznacza indeks w ciagu liczb
  // z tego indeksu musimy wyliczec nr opowiadajecemu mu liscia
  int w = gdzie+L;
  
  int wynik = 0;
  while(w != 0)
  {
   wynik+=tab[w];
    w/=2;
  }
  return wynik;
}

void dodaj(int a, int b, int x) {
  a+=L;
  b+=L;
  tab[a]+=x;
  if(a!=b)
  {
    tab[b]+=x;    
  }
  while(a/2 != b/2)
  {
    if(a%2 == 0)
    {
      tab[a+1] +=x; 
    }
    if(b%2 == 1)
    {
      tab[b-1]+=x;
    }
    a/=2;
    b/=2;
  }
}


int main() {
  int ile;
  cin >> ile;
  
  dodaj(4, 10, 7);
  dodaj(3, 5, 2);
  
  cout << zapytaj(3);
  
  return 0; 
}5