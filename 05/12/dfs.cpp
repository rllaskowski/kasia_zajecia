#include <bits/stdc++.h>
#include <vector>

using namespace std;
bool odw[1000*1000+1];
vector <int> tab[1000*1000+1];
void dfs(int w){
  odw[w] = true;
  for(int i = 0;i<tab[w].size();i++)
  {
    int gdzie = tab[w][i]; 
   if(odw[gdzie] == false)
   {
    dfs(gdzie); 
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
}5