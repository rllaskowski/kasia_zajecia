#include <iostream>

using namespace std;
int w[4001][4001];

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  

  for(int i = 1; i<=s1.size();i++) 
  {
    // i to dluosc prefiksu pierwszego slowa
   for(int j = 1; j<=s2.size(); j++)
   { // j to dlugosc prefiksu drugiego slowa
     w[i][j] = max(w[i-1][j],w[i][j-1]);
     if(s1[i-1] == s2[j-1])
     {
      w[i][j] = w[i-1][j-1]+1;
     }
   }
  }
  cout << w[s1.size()][s2.size()];
  return 0; 
}