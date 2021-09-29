#include <bits/stdc++.h>

using namespace std;


/*
TABLICA O 40 ELEMENTACH
MA INDEKSY OD 0 DO 39


0 DO 100000000000
*/
int main() {
    unordered_map<string, int> mapa;
    mapa["ccc"] = 1212334;
    mapa["ddd"] = 1231232134;
    mapa["aaa"] = 123;
    mapa["bbb"] = 1234;
    mapa["ccc"] = 1212334;

    if (mapa.count("ccc")) {
        
    }


    for (pair<string, int> cos : mapa) {
        cout << cos.first << " " << cos.second << endl;
    }


    return 0;
}