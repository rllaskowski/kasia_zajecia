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
int skok[1000001][18];
int czas = 0;
int odl[1000001];
int ostatniNr = 1;
int gle[1000001];
vector <pair<int, int>> kraw[1000001];

unordered_map<string, int> nrWierzcholka;


/* zwraca nr najnizszego wspolnego przodka wierzcholków a i b */
int lca(int a, int b) 
{
  /*
  chcemy sprowadzic oba wierzchilki na ta samą glębokość
  Wynieramy nizej polozony wierzchilek i skaczemy nim o odpowiednia ilosc w gore
  */
  if(gle[a]>gle[b])
  {
    swap(a, b);
  }
  /* teraz a jest wyzej polozonym wierzcholkiem niz b*/
  int ile = gle[b]-gle[a];
  int pot = 1 << 17;
  for(int i = 17;i>=0;i--)
  {
    // i jest wykladnikiem potegi dwojki o ktora chcemy skoczyc
    // chcemy poznac 2^i
    if (pot <= ile) {
      b=skok[b][i];
      ile -= pot;
    }
    pot /= 2;
  }
  /* teraz a i b sa na tej samej glebokosci */
  if(a==b)
  {
    return a;
  }
  for(int i = 17;i>=0;i--)
  {
    /* chcemy skoczyc wierzcholkami a i b w gore ale tylko jesli 
    skok o 2^i w gore nie prowadzi do tego samego wierzcholka */
    if(skok[a][i]!=skok[b][i])
    {
      // skok z a o 2^i i z b o 2^i w gore nie prowadzi do tego samego wierzcholka
      a= skok[a][i];
      b = skok[b][i];
    }  
  }
  return skok[a][0];
}


 void init(string nazwa)
 {
    nrWierzcholka[nazwa]=ostatniNr++;
    int nr = nrWierzcholka[nazwa];
    skok[nr][0] = nr;
 }
void nowa_osada(string nowa, string stara, int dlugosc)
{

    nrWierzcholka[nowa]=ostatniNr++;
    int nrNowa = nrWierzcholka[nowa];
    int nrStara = nrWierzcholka[stara];

    kraw[nrNowa].push_back(make_pair(nrStara,dlugosc));
    kraw[nrStara].push_back(make_pair(nrNowa,dlugosc));
    skok[nrNowa][0] = nrStara;
    for(int i = 1;i<18;i++)
    {
        // chcemy wyliczyc skok o 2^i w gore z wierzcholka nrNowa
        // ale znam juz skok o 2^i-1 w gore
        // zalozlmy ze jest tam wierzcholek b
        int b = skok[nrNowa][i-1];
        skok[nrNowa][i] = skok[b][i-1];
    }
    odl[nrNowa]=odl[nrStara]+dlugosc;
    gle[nrNowa]=gle[nrStara]+1;
}


int odleglosc(string pierwsza, string druga)
{
    int prz = lca(nrWierzcholka[pierwsza],nrWierzcholka[druga]);
    return odl[nrWierzcholka[pierwsza]] - odl[prz]+odl[nrWierzcholka[druga]]-odl[prz];
}
