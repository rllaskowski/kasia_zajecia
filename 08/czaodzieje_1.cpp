#include <bits/stdc++.h>
using namespace std;
int p[1000*102];
bool czcz[1000*102];
vector <int> kraw[1000*102];

int kom, kor, ile;

int bfs(int w)
{
  vector<int> odl(kom+1); // odleglosci od wierzcholka w
  vector<bool> odw(kom+1); // czy wierzcholek jest juz odwiedzony
  queue<int> wi;
  
  wi.push(w);
  odl[w]= 0;
  odw[w] = true;
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
       if(czcz[x])
       {
        return odl[x]; 
       }
       odw[x] = true;
       wi.push(x);
       
     }
    }
    
   
      
  }
  // zwracamy duza liczbe oznaczajaca, ze nie da sie rzucic zaklecia do innego czarodzieja
   return 1000*1000*1000; 
}
int main() {
   ios_base::sync_with_stdio(0); 
  cin >> kom >> kor >> ile;
  for(int i = 0; i<ile;i++)
  {
    cin >> p[i];
    czcz[p[i]] = true;
  
  }
  for(int i = 0; i<kor;i++)
  {
    int a,b;
   cin >> a >>b;
  kraw[a].push_back(b);
   kraw[b].push_back(a); 
  }
  // najkrotsza trasa z jednego czarodzieja do drugiego
  // 10^9 oznacza, że nie ma takiej trasy, to znaczy ze zadnych dwoch czarodzieji
  // nie moze zaatakowac sie zakleciem i wywiazac emocjonujacego pojedynku
  int x = 1000*1000*1000;
  for(int i = 0; i<ile;i++)
  {
   x =min(x, bfs(p[i]));
    
  }
  if(x == 1000*1000*1000)
  {
   cout << "-1.0"; 
  }
  else
  {
    if (x%2 == 0)
    {
      cout << x/2<<".0";
    }
    else
    {
     cout << x/2.0; 
    }
  }
  return 0;
}

