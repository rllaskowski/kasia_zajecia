#include <iostream>
using namespace std;


// odl[a][b] - długosc najkrotszej trasy a ~> b
int odl[101][101];

// stała liczbowa - nieskończoność
const int INF = 1000*1000*1000;

int main() {
    ios_base::sync_with_stdio(0);
  
    int n, m, k;
    int a, b, c;

    cin >> n >> k >> m;
  
    // zanim wczytamy krawędzie wypełniamy poczatkowe wartosci 
    // naszej odllicy
    for(int i =1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
             odl[i][j] = INF;
        }
        odl[i][i] = 0;
    }

    for (int i = 0; i < k; i++) {    
        cin >> a >> b >> c; 
        odl[a][b] = min(c, odl[a][b]);
        odl[b][a] = min(c, odl[b][a]);
    }
  
    for (int u = 1; u <= n; u++) {
        // u jest wierzcholkiem, ktorym bedziemy chcieli poprawiac
        // drogi pomiedzy wszystkimi parami wierzcholkow
        for( int x = 1; x <=n; x++) {
            for(int y = 1; y<=n; y++) {
                // teraz chcemy poprawic trase pomiedzy wierzhcolkami x ~> y
                // sprawdzamy czy trasa x~>u + u~>y jest lepsza niz trasa x~>y
                odl[x][y]= min(odl[x][u]+odl[u][y],odl[x][y]);
            }
        }
    }
  
  // teraz mamy obliczone wszystkie najkrotsze drogi pomiedzy kazda para wierzcholkow
  // na poczatkowym grafie, bez dodanych krawdzi
    for(int i =0; i<m; i++) {
        cin >> a >> b >> c; // nowa krawwedz
        
        int nowaTrasa = min(odl[1][a]+c+odl[b][n],odl[1][b]+c+odl[a][n] );
        
        if(odl[1][n] > nowaTrasa) {
            // to oznacza, ze chcemy wybudowac te droge; musimy poprawic wartosci
            // w naszej odllicy odl
            for( int x = 1; x <=n; x++) {
                for(int y = 1; y<=n; y++) {
                    // teraz chcemy poprawic trase pomiedzy wierzhcolkami x ~> y
                    // sprawdzamy czy trasa x~>a + b~>y lub x~>b + a~>yjest lepsza niz trasa x~>y
                
                    nowaTrasa = min(odl[x][a]+odl[b][y]+c,odl[x][b]+odl[a][y]+c);
                    odl[x][y] = min(odl[x][y], nowaTrasa);
                }
            }
            cout << 1<< "\n";
        } else {
            cout << 0<< "\n";     
        }
    }

    return 0;
}
