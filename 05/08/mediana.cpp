#include <iostream>

using namespace std;
int tab[509][509];
int zebrane[509][509];

int n;

bool czyWiekszaRowna(int k) {
  // zwraca true jesli da sie zrobic mediane >= k
  // lub false w przeciwnym przypadku
  for(int i = 1; i<=n;i++)
  {
   for(int j = 1; j<=n; j++)
   {
     zebrane[i][j] = max(zebrane[i-1][j],zebrane[i][j-1]);
    if(tab[i][j]>=k)
    {
     zebrane[i][j] +=1; 
    }
   }
  }
  if(zebrane[n][n] >=n)
  {
    return true;
  }
  else
  {
   return false; 
  }
  
}

int main() {
  
  cin >> n;
  for(int i = 1; i<=n;i++)
  {
   for(int j = 1; j<=n; j++)
   {
    cin>>tab[i][j];
   }
  }
  
  
  int p = 1;
  int k = 1000*1000*1000;
  int wyn;
  int s = 0;
  while(p<=k)
  {
    s = (p+k)/2;
   if(czyWiekszaRowna(s) == false)
   {
     k=s-1;
   }
  else
  {
    wyn = s;
   p = s+1; 
  }
  }
  cout << wyn;
  
  
  return 0;
}