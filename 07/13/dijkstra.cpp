#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

long long int odl[500*1010];
vector<pair<int,int>> kraw[500*1010];
int wi;

const long long INF = (long long)1000*1000*1000*1010; 
void dijkstra(int s) {
 // s to wierzcholek startowy
  pair<long long, int>a;
  int w;
  for(int i = 1; i<=wi;i++)
  {
   odl[i] = INF;
  }
  odl[s] = 0;
  set<pair<long long, int>> kolejka;
  kolejka.insert(make_pair(0,s));
  while(!kolejka.empty())
  {
    a = (*kolejka.begin());
    kolejka.erase(kolejka.begin());
    w = a.s;

    for(int i = 0; i<kraw[w].size();i++) {

      int x = kraw[w][i].f; // x to nr sasiada
      int c = kraw[w][i].s; // c to dlugosc krawedzi

      if(odl[x]> odl[w]+c)
      {
        kolejka.erase(make_pair(odl[x], x));
        odl[x] = odl[w]+c;
        kolejka.insert(make_pair(odl[x], x));
      }
    
    }
  }
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int kr,a,b,c;
  cin >> wi >> kr;
  for(int i = 0; i<kr;i++)
  {
   cin >> a>> b >> c; 
    kraw[a].push_back(make_pair(b,c));
    kraw[b].push_back(make_pair(a,c));
  }
  
  dijkstra(1);
  for(int i = 1;i<=wi;i++)
  {
   if(odl[i] == INF)
   {
    cout << -1<< "\n";
   }
  else
  {
   cout << odl[i]<< "\n"; 
  }
  }
  return 0;
}
