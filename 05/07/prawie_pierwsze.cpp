#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool czyZlozona[1000001]; // czy liczba jest zlozona
vector<long long> prawiePierwsze;

void sito() {
  for(int i = 2; i<=1000*1000; i++)
  {
    if(czyZlozona[i] == false) {
      // to oznacza ze liczba jest pierwsza
      // wygeneryjmu nowa liczbe prawie pierwsza do naszej listy
      prawiePierwsze.push_back(i*(long long)i);
      for(int j = i*2; j<=1000*1000;j +=i)
      {
        czyZlozona[j] = true;
      }
    }
  }
}

int main() {
  int ile;
  long long p;
  cin >> ile;
  
  sito();
  
  
  for(int i = 0; i< ile; i++)
  {
   cin >> p;
    if(binary_search(prawiePierwsze.begin(), prawiePierwsze.end(), p) == true)
    {
      cout << "TAK" << endl;
    }
    else
    {
      cout << "NIE" << endl;
    }
  }
  return 0; 
}