#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main

/*
Wczytujemy n - ilosc wierzcholkow w drzewie
nastpenie n-1 krawedzi laczacych wierzcholki
potem q - ilosc zapytan
wczyujemy q par liczb czyli zapytan o odleglosc pomiedzy wierzcholkami


PRZYKLADOWE WEJSCIE:

5
1 2 2
1 3 5
3 4 1 
2 5 9
2
1 5
4 5

WYJSCIE:
2
4

6
a b 3
b c 4
c d 2
a e 7
c f 8
2
d e 
a f

wyjscie:
16
15
numery = 2


a: 1
b: 2
c: 3
d: 4
e: 5
f: 6
*/
bool odw[1000001];
int wej[1000001];
int wyj[1000001];
int skok[1000001][18];
int czas = 0;
int gl[1000001];
vector <pair<int, int>> kraw[1000001];

unordered_map<string, int> nrWierzcholka;


/* czy a jest przodkiem b */
bool czy_przodek(int a, int b)
{
  return wej[a] < wej[b] and wyj[a] > wyj[b];
}


/* zwraca nr najnizszego wspolnego przodka wierzcholków a i b */
int lca(int a, int b) 
{
  /*
  skaczemy wierzcholkiem a
  wierzcholek b zostawiamy w miejscu
  jesli skok o 2^s prowadzi do wierzcholka, który jest przodkiem b
  to nie skaczemy tak wysoko, natomiast jesli skok o 2^s nie prowadzi
  do przodka wierzcholka b to przesuwamy wierzcholek a o 2^s w gore
  */
  if(czy_przodek(a,b))
     {
      return  a;
     }
  if(czy_przodek(b,a))
     {
      return  b;
     }
  for(int s = 17;s>=0;s--)
  {
    if(!czy_przodek(skok[a][s],b)) 
      a = skok[a][s];
  }
  return skok[a][0];
  
}


void dfs (int w)
{
  czas++;
  odw[w] = true;
  wej[w]=czas;
  
  for(pair<int,int>i:kraw[w])
  {
    
   if(!odw[i.first])
   {
     gl[i.first] = gl[w]+i.second;
     skok[i.first][0]= w;
    dfs(i.first);
    
   }
  }
  czas++;
  wyj[w]=czas;
  
}
int main() {

    int ostatniNr = 1;
    int n;
    cin >> n;
    for(int i = 0; i<n-1;i++)
    {
        string a,b;
        int c;
        cin >> a >> b >> c;

        if (nrWierzcholka.count(a)==0) {
            nrWierzcholka[a]=ostatniNr++;
        }
        if (nrWierzcholka.count(b)==0) {
            nrWierzcholka[b]=ostatniNr++;
        }

        kraw[nrWierzcholka[a]].push_back(make_pair(nrWierzcholka[b],c));
        kraw[nrWierzcholka[b]].push_back(make_pair(nrWierzcholka[a],c));
    }
    skok[1][0] = 1;
    gl[1] = 0;
    dfs(1);
  /*
  dla kazdego wierzcholka mamy wylliczonego jego ojca
  w tablicy skok
  dla wierzcholka x jego ojciec to skok[x][0]
  */
  for(int i = 0; i<17;i++)
  {
   for(int j = 1; j<n+1;j++)
   {
     // znamy juz zawartosc kolumny i-tej
     // teraz chcemy wyznaczyc skok wierzcholka j o 2^i+1 w gore
     // mozemy to zrobic korzystajac z krotszych skokow - o 2^i w gore
     int b = skok[j][i];
     int c = skok[b][i];
     skok[j][i+1] = c;
   }
  }
  
  int q;
  cin >> q;
  for(int i = 0;i <q;i++)
  {
    string a,b;
    cin >> a >> b;
    int prz = lca(nrWierzcholka[a],nrWierzcholka[b]);
    cout << gl[nrWierzcholka[a]] - gl[prz]+gl[nrWierzcholka[b]]-gl[prz]<< "\n";
    
  }
  return 0;
}
