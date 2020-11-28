const int BEGALINIS = ...; // kažkoks pakankamai didelis skaičius, pavyzdžiui 1e9
const int MAXM = ...;      // maksimalus komutatorių skaičius
const int MAXK = ...;      // maksimalus kompiuterių skaičius

int k;                                 // kompiuterių skaičius
int m;                                 // komutatorių skaičius
pair<int, int> jungimai[MAXM + MAXK];  // masyvas, kuriame bus pateikiamas atsakymas
int kaina[MAXM + MAXK][MAXM + MAXK];   // įrenginių jungimo kainų masyvas
int jungSk;
int jungKaina;

void junk (int a, int b) {
    // įrenginys a sujungiamas su įrenginiu b
    jungimai[jungSk].first = a;
    jungimai[jungSk].second = b;
    junkSk++;
    jungKaina += kaina[a][b];
}

void raskJungimus () {
    jungSk = 0;
    jungKaina = 0;

    /*
        prijungiame kiekvieną kompiuterį prie "artimiausio" komutatoriaus
        (kompiuteriai sunumeruoti nuo m iki m+k-1, komutatoriai - nuo 0 iki m-1
    */

    for (int i = m; i < m+k; i++) {
        int t = 0;
        for (int j = 0; j < m; j++)
            if (kaina[i][t] > kaina[j][t])
                t = j;
        junk(i, t);
    }

    // komutatorių jungimui sudarome grafą ir randame minimalų jungiamąjį medį
    n = m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (i != j)
                svoris[i][j] = (i != j ? kaina[i][j] : BEGALINIS);
    // pagal Primo algoritmą randamas MJM
    Primo ();

    // medžio briaunos yra (i, pirmine[i]), visoms i, išskyrus 0
    for (int i = 1; i < n; i++)
        junk (i, pirmine[i]);
}
