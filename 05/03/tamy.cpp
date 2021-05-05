#include <iostream>

using namespace std;
int l[500*1000+7]; // indeks segmentu po lewej stronie 
int p[500*1000+7]; // indeks segmentu po prawej stronie
int w[500*1000+7]; // ilosc wody wplywajacej do segmentu w trakcie 1 sek.
int ls[500*1000+7]; // wysokosc lewej sciany i-teg
int ps[500*1000+7]; // wysokosc prawej sciany i-tego segmentu
int ileW[500*1000+7]; // ile wody aktualnie w segmencie

int main() {
  ios_base::sync_with_stdio(0);
  int n; // ilosc segmentow
  
  cin >> n;
  for(int i =1; i<=n+1; i++)
  {
    // wysokosc sciany
    int s;
    cin >> s;
    
    // jezeli nie jest to pierwsza wczytana sciana
    // to jest to prawa sciana poprzedniego segmentu
    if (i != 1) {
      ps[i-1] = s;
    }
    
    // jezeli nie jest to ostatnia wczytana sciana
    // to jest to lewa sciana i-tego segmentu
    if (i != n+1) {
      ls[i] = s;
    }
    

  }
  for(int i = 1; i<=n; i++)
  {
    cin >> w[i];
    
    l[i] = i == 1? -1 : i-1;
    p[i] = i == n? -1 :i+1; 
  }
  
  int pierwszy = 1;
  
  int t = 1;
  
  for(;; t++) 
  {
    // t to ilosc sekund, ktora uplynela w naszej symulacji
    
    int i = pierwszy; // i to jest numer obslugiwaneho segmentu
    
    while (i != -1) {
      // teraz wpada jakas ilosc wody do segmentu
      ileW[i] +=w[i];
      
      if (ps[i] == ls[i] && ileW[i] > ps[i]) { // woda przelala sie w obie strony
        
        if(ls[i] == -1 or ps[i-1])
        {
          break; // woda wylala sie ze zbiornika
        }
        w[i] = w[ls[i]]+w[ps[i]];
        ls[i]= ls[ls[i]];
        ps[i] = ps[ps[i]];
      }
      else if(ileW[i]> ps[i]) // przelala sie woda w prawa strone
      {
        if (ps[i] == -1) {
          break;
        }
        // usuwamy i+1 segment
        ps[i] = ps[i+1]
        w[i]+=w[i+1];
        ileW[i]+=w[i+1];
        
      }
      else if () // przelala sie woda w prawa strone
      {
        if (ps[i] == -1) {
          break;
        }
        // usuwamy i+1 segment
        ps[i] = ps[i+1]
        w[i]+=w[i+1];
        ileW[i]+=w[i+1];
        
      }
    
      i = ps[i]; // przejdz na kolejny prawy segment
    }
    
  }
 
  cout << t;
  
  return 0; 
}