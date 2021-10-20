#include <bits/stdc++.h>

using namespace std;


pair <char,int> rozegrajGema(string zapisGry, int ilePunktow, int odkad) {
    int pa = 0, pb = 0;
    for (int i = odkad; i < zapisGry.size(); i++) {
        if(zapisGry[i]== 'A')
        {
            pa++;
        }
        else
        {
            pb++;
        }

        if(pa >= 4 and pb<= pa-2)
        {
            return make_pair('A',i);
        }
        else if(pb >= 4 and pa<= pb-2)
        {
            return make_pair('B',i);
        }
    }
}

pair<char,int> rozegrajSeta(string zapisGry, int odkad) {
    int ga = 0, gb =0;
    int i = odkad;

    while (true) {
        pair<char, int> wynikGema = rozegrajGema(zapisGry, 4, i+1);
        i = wynikGema.second;
        char gracz = wynikGema.first;
        if (gracz == 'A') {
            ga++;
        } else {
            gb++;
        }

        if (ga >= 6 && ga-2 >= gb) {
            make_pair('A', i);
        } else if (gb >= 6 && gb-2 >= ga) {
            make_pair('A', i);
        }

        if (ga == gb && ga == 6) {
            pair<char, int> wynikGema = rozegrajGema(zapisGry, 7, i+1);
            char gracz = wynikGema.first;
            i = wynikGema.second;
            return make_pair(gracz, i);
        }
    }

}




int main()
{
    string a;
    cin >> a;
    

}