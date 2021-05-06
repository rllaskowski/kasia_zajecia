#include <iostream>

using namespace std;
bool tab[502][502];
bool t[502][502]; // czy wierxcholekk odwiedzony
int n, m, k;
char p;

void dfs(int x, int y){
  t[x][y] = true;
     
  if(t[x-1][y] == false and tab[x-1][y] == true)
  {
    dfs(x-1,y);
  }
  if(t[x][y-1] == false and tab[x][y-1] == true)
  {
    dfs(x,y-1);
  }
  if(t[x+1][y] == false and tab[x+1][y] == true)
  {
    dfs(x+1,y);
  }
  if(t[x][y+1] == false and tab[x][y+1] == true)
  {
    dfs(x,y+1);
  }
  if(k >0){
  tab[x][y] = false;
  k-=1;
  }
  
}
int main() {
  int pp = 0 , pd = 0;
  cin >> n >> m >> k;
  for(int i = 1; i<=n;i++)
  {
   for( int j = 1; j<=m; j++)
   {
     cin >> p ;
     if(p == '.')
     {
       tab[i][j] = true;
       pp = i;
       pd = j;
     }
     else
     {
       tab[i][j] = false;
     }
   }
  }

  dfs(pp,pd);
  for(int i = 1; i<=n;i++)
  {
   for( int j = 1; j<=m; j++)
   {
     
     if (tab[i][j] == true)
     {
       cout << ".";
     }
     else
     {
       cout << "X";
     }
     
   }
    cout << "\n";
  }
  return 0; 
}