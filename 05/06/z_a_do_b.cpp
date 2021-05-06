#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int odl[1000*1000+9];
bool czyodw[1000*1000+9];
vector<int> kraw[1000*1000+9]; // krawedzie  

void bfs(int ws){
  int p;
  czyodw[ws] = true;
  odl[ws] = 0;
  queue<int> kolejka;
  kolejka.push(ws);
  while(kolejka.size() > 0)
  {
    p = kolejka.front();
    kolejka.pop();
    for(int i = 0; i<kraw[p].size();i++)
    {
      int v = kraw[p][i];
      if(czyodw[v] == false)
      {
        czyodw[v] = true;
        odl[v] = odl[p]+1;
        kolejka.push(v);
      }
    } 
  }
  
}

int main() {
  int n,m,a,b,d,e;
  cin >> n >> m >> a >> b;
  for(int i = 0; i<m ;i++)
  {
    cin >> d >> e;
    kraw[d].push_back(e);
  }
  bfs(a);
  if(czyodw[b] == true)
  {
    cout << odl[b];
  }
  else
  {
   cout << "niestety"; 
  }

  return 0; 
}