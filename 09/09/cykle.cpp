#include <bits/stdc++.h>
using namespace std;
#define f first
#define sec second
vector<pair<int,int>> kr[1000001];
int od[1000001];


/*

5 7
1 2
2 3
2 4
4 5
4 1
3 2
1 5

*/



/*
wi - nr wierzcholka
aks - czas krawedzi, po ktorych mozemy przechodzic
*/
bool dfs(int wi,int aks,int num)
{
  cout << wi << endl;
  od[wi] = num;
  for(pair<int, int> i : kr[wi])
  {
    if(od[i.f]==num)
    {
     return true;
    }
    else if(od[i.f] == 0 && i.sec<= aks)
    {
        if(dfs(i.f,aks,num))
        {
          cout << "ZNALEZLISMY CYKL Z KRAWEDZI OD " << wi << " DO " << i.f << endl;
          return true;
        }
    }

  }
  return false;
}

/*
Czy istnieje cykl w ca³ym grafie, ktory
stworzony jest z krawedzi powsta³ych do momentu aks
*/
bool czyCykl(int aks,int ile) {
  cout << "Zaczynamy przeszukiwac graf dla srodka rownego " << aks << endl;
  for (int i = 1; i <= ile; i++) {
    od[i] = 0;
  }
  for(int i = 1;i<=ile;i++)
  {
      if (od[i] == 0 && dfs(i, aks,i))
      {
        return true;
      }
  }
  return false;
}


int main() {
  int ile,kraw;
  cin >> ile >> kraw;
  for(int i = 0; i<kraw;i++)
  {
    int a,b;
    cin >> a >> b;
    kr[a].push_back(make_pair(b,i+1));
  }
  int p = 1,k = kraw,s;
  while(p<k)
  {
    s =(k+p)/2;
    if(czyCykl(s,ile)) {
      cout << "CYKL JEST PO DODANIU " << s << " KRAWEDZI" << endl;
      k = s;
    }
    else p = s+1;

  }
  if(p>kraw)cout << "NIE";
  else cout <<p;

  return 0;
}
