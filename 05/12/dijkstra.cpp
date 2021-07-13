#include <bits/stdc++.h>
#include <vector>

using namespace std;
bool odw[1000*1000+1];
int odl[1000*1000+1];
vector <pair<int,int>> tab[1000*1000+1];

void dijkstra(int s){
  priority_queue<pair<int, int>> k;
  // pierwszy element pary to odleglosc do wierzcholka a drugi to nr wierzcholka
  
  // wrzucamy wierzcholek startowy na kolejke i 
  // ustawiajy mu odleglsoc 0 i wartosc true w tablicy odw
  odl[s] = 0;

  k.push(make_pair(0, s));
  
  while(k.size()!=0)
  {
    pair<int, int> p = k.top();
    k.pop();
    
    int w = p.second;
    
    if (-p.first == odl[w]) {
      for(int i = 0; i<tab[w].size();i++)
      {
        int gdzie = tab[w][i].first;
        int waga = tab[w][i].second;

        if (odl[gdzie]<odl[w]+waga) {
          // to oznbacza ze poprawiamy odleglosc i znow wrzucamy na kolejke
          odl[gdzie]=odl[w]+waga;
          k.push(make_pair(-odl[gdzie],gdzie));
        }
      }  
    }
    
  }
}

int main() {
  int ile, n,a,b, c;
  cin >> n >> ile;
  
  for(int i = 0; i<ile;i++)
  {
    cin >> a >> b >> c;
    // istnieje krawedz z a do b ktorej waga jest c
    tab[a].push_back(make_pair(b,c));
    tab[b].push_back(make_pair(a,c)); // tylko jesli graf jest nieskierowany
    // czyli krawedzie sa w obie strony
  }
  
 
  return 0; 
}5