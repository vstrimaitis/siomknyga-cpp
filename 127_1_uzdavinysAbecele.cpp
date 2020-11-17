#include <limits.h> 
/*
    šios bibliotekos prireiks, kadangi naudosime konstantas
    CHAR_MIN (mažiausia char tipo kintamojo pasiekiama reikšmė) ir
    CHAR_MAX (didŽiausia char tipo kintamojo pasiekiama reikšmė)
*/

const int MAXZODZIU = ...;

int sk;                             // žodžių skaičius
string z[MAXZODZIU + 1];            // žodžių masyvas
int n;                              // viršūnių skaičius
map<char, bool> virsune;            // ar grafe yra raidę atitinkanti viršūnė
map<pair<char, char>, bool> lankas;
map<char, int> ieinLanku;

void sudarykGrafa () {
    // išvalomos duomenų struktūros
    n = 0;
    virsune.clear();
    lankas.clear();
    ieinLanku.clear();

    // sudaromas grafas
    zodziai[sk] = ""; // pridedame tuščią žodį
    for (int i = 0; i < sk; i++) {
        for (int j = 0; j < (int)z[i].size(); j++) {
            // jei randama naujų raidžių - jos įtraukiamos į grafą
            if (!virsune[z[i][j]]) {
                n++;
                virsune[z[i][j]] = true;
            }
        }

        int m = min((int)z[i].size(), (int)z[i+1].size());
        int j = 0;
        while (j < m && z[i][j] == z[i+1][j]) {
            j++;
            // ieškoma nesutampanti raidė
        }

        if (j < m && !(lankas[{z[i][j], z[i+1][j]}])) {
            // rasta nesutampanti raidė - grafas papildomas lanku
            lankas[{z[i][j], z[i+1][j]}] = true;
            ieinLanku[z[i+1][j]]++;
        }
    }
}

string raskAbecele () {
    string abecele = ""; // atsakymas bus įrašomas į eilutę "abėcėlė"
    sudarykGrafa ();     // topologiškai išrikiuojamas grafas (randama abėcėlė)

    while (n > 0) {
        char c = CHAR_MIN;
        // randama viršūnė be įeinančių lankų
        while (!virsune[c] || ieinLanku[c] > 0) {
            c++;
        }
        abecele += c; // raidė pridedama prie abėcėlės

        // atnaujinami kaimynų laipsniai
        for (char d = CHAR_MIN; d <= CHAR_MAX; d++) {
            if (lankas[{c,d}])
                ieinLanku[d]--;

        // viršūnė ištrinama iš grafo
        virsune[c] = false;
        n--;
    }

    return abecele;
}
