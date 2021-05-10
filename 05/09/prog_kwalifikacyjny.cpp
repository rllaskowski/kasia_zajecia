#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tab[200*1009];
long long pr[200*1009];
int ile;
int b(long long n){
  int p = 1;
  int k = ile;
  int wyn;

  while(p<=k)
  {
    int s = (p+k)/2;
   if(pr[s]>=n)
   {
     wyn = s;
     k = s-1; 
   }
    else
    {
     p =s+1;
    }
    
  }
  return wyn;
  
}
int main() {
  int p;
  long long k;
  cin >> ile;
  for(int i = 1; i<=ile; i++)
  {
    cin >> tab[i];
  }
  sort(tab+1, tab+ile+1);
  reverse(tab+1,tab+ile+1);
  for(int i = 1; i<=ile;i++)
  {
   pr[i] = pr[i-1]+tab[i]; 
  }
  cin >> p;
  for(int i = 0; i<p; i++)
  {
    cin >> k;
    cout << b(k)<<"\n";
  }
  
  
  return 0; 
}