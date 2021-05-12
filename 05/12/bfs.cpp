#include <bits/stdc++.h>
#include <vector>

using namespace std;
bool odw[1000*1000+1];
int odl[1000*1000+1];
vector <int> tab[1000*1000+1];

void bfs(int s){
  queue <int> k;
  
  // wrzucamy wierzcholek startowy na kolejke i 
  // ustawiajy mu odleglsoc 0 i wartosc true w tablicy odw
  odl[s] = 0;
  odw[s] = true;
  k.push(s);
  while(k.size()!=0)
  {
    int p = k.front();
    k.pop();
    for(int i = 0; i<tab[p].size();i++)
    {
      int gdzie = tab[p][i];
     if(odw[gdzie] == false)
     {
       odl[gdzie] = odl[p]+1;
       k.push(gdzie);
       odw[gdzie] = true;
     }
    }
  }
}

int main() {
  int ile, n,a,b;
  cin >> n >> ile;
  
  for(int i = 0; i<ile;i++)
  {
    cin >> a >> b;
    tab[a].push_back(b);
    tab[b].push_back(a); // tylko jesli graf jest nieskierowany
    // czyli krawedzie sa w obie strony
  }
  
 
  return 0; 
}