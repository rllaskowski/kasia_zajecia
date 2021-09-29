#include <bits/stdc++.h>
using namespace std;
int p[1000*102];
bool czcz[1000*102];
int odl[1000*102];
bool odw[1000*102];
int kol[1000*102];
queue<int> wi;
vector <int> kraw[1000*102];


int kom, kor, ile;

int bfs()
{
  while(!wi.empty())
  {
    int h = wi.front();
    wi.pop();
    for(int i = 0; i<kraw[h].size();i++)
    {
      int x = kraw[h][i];
     if(!odw[x])
     {
       odl[x] = odl[h]+1;
       odw[x] = true;
       kol[x] = kol[h];
       wi.push(x);
       
     }
      else if(kol[x] != kol[h])
      {
        return odl[x]+odl[h]+1;
      }
    }
          
  }

   return -1; 
}
int main() {
   ios_base::sync_with_stdio(0); 
  cin >> kom >> kor >> ile;
  for(int i = 1; i<=ile;i++)
  {
    cin >> p[i];
    // wrzucamy wszystkie wierzchilki na ktorych sa czarodzieje jako wierzcholki startowe
    // w bfsie
    wi.push(p[i]); 
    odw[p[i]] = true;
    kol[p[i]] = i; // zaznaczamy kolor tego wierzcholka
  }
  for(int i = 0; i<kor;i++)
  {
    int a,b;
   cin >> a >>b;
  kraw[a].push_back(b);
   kraw[b].push_back(a); 
  }
  int x = bfs();
  if(x == -1)
  {
   cout << "-1.0";
  } 
  else
  {
   if(x%2 == 0)
   {
    cout << x/2 << ".0"; 
   }
    else
    {
     cout << x/2.0; 
    }
  }
  return 0;
}

