#include <iostream>

using namespace std;
int tab[1000*1000+9];
int ost[1000*1000+9];
int pie[1000*1000+9];
// dyn[i] to maksymalna ilosc rodzin, ktore mozemy wziac tylko z rodzin konczacych sie przed lub na i 
int dyn[1000*1000+9]; 
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  
  cin >> n;
  for(int i =1; i<=n; i++)
  {
    cin >> tab[i];
    if (pie[tab[i]] == 0) {
      pie[tab[i]] = i;
  
    }
    ost[tab[i]]= i;
  }
  for(int i = 1; i<=n;i++)
  {
      if(i == ost[tab[i]])
      {
         dyn[i] = max(dyn[pie[tab[i]]-1]+1,dyn[i-1]);
      }
      else
      {
        dyn[i] = dyn[i-1];
      }
  }
  cout << dyn[n];
  return 0; 
}e