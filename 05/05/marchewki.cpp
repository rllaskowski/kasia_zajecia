#include <iostream>

using namespace std;
int p[2001][2001]; // najwiekszy kwadrat jaki mozemy polozyc w danym polu
int og[2001][2001]; // najblizszy kwiatek w góre(odleg≤osc) lub odleglosc do sciany
int od[2001][2001]; // najblizszy kwiatek w góre(odleg≤osc) lub odleglosc do sciany

int main() {
  int n, m,b, najw = 0, ileNajw = 0;
  char a;
  cin >> n >> m;
  
  for(int i = 1; i<=n; i++)
  {
   for(int j = 1; j<=m; j++)
   {
        cin >> a;
       if (a == 'x') {

          p[i][j] = 0;
          og[i][j] = 0;
         od[i][j] = 0;
       } 
     else
       {
       og[i][j] = og[i-1][j]+1;
       od[i][j] = od[i][j-1];
       b = min(og[i][j],od[i][j]);
       p[i][j] = min(p[i-1][j-1]+1,b);
       if(najw<p[i][j])
       {
         ileNajw=1;
         najw = p[i][j];
       }
       else if(najw == p[i][j])
       {
        ileNajw+=1;
       }
       
       }
     
   }
  
  }
  
  cout << najw << " " << ileNajw << endl;
   
  
  return 0; 
}  