#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
pair <int,int> tab[1000*1000+9];
int ul,al,s;
pair <int,int> p;
int odl[1001][1001];
bool odw[1001][1001];
queue <pair <int,int>> k;

void ustawOdleglosc(int i, int j, int o) {
   if(odw[i][j] == false && i >= 1 && i <= ul && j >= 1 && j <= al) {
      odl[i][j] = o;
      odw[i][j] = true;
      k.push(make_pair(i, j));
    }
}

void bfs(){
  for(int i = 1;i<=s;i++)
  {
    odl[tab[i].f][tab[i].s] = 0;
    odw[tab[i].f][tab[i].s] = true;
    k.push(tab[i]);
  }
  while(k.size() != 0)
  {
    p = k.front();
    k.pop();
    ustawOdleglosc(p.f-1,p.s,odl[p.f][p.s]+1);
    ustawOdleglosc(p.f+1,p.s,odl[p.f][p.s]+1);
    ustawOdleglosc(p.f,p.s-1,odl[p.f][p.s]+1);
    ustawOdleglosc(p.f,p.s+1,odl[p.f][p.s]+1);
    
  }
  
  
  
}
int main() {
  cin >> ul >> al>>s;
  for(int i = 1; i<=s;i++)
  {
    cin >>tab[i].f >> tab[i].s;    
  }
  bfs();
  for(int i = 1;i<=ul;i++)
  {
   for(int j = 1;j<=al;j++)
   {
    cout <<  odl[i][j]<<" ";
   }
    cout << "\n";
  }

  
  

}