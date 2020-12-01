const int MAXN = ...;      // maksimalus knygų skaičius
const int MAXK = ...;      // maksimalus darbuotojų skaičius
const int BEGALINIS = ...; // kažkoks kuo didesnis skaičius, pavyzdžiui, 1e9

int k;
int n;
int p; // puslapių skaičius
int ivertis;
int nuo[MAXN+MAXK+1];

int S (int i, int j) {
    // apskaičiuoja knygų nuo i-tosios iki j-tosios puslapių skaičių sumą
    int suma = 0;
    for (int h = i; h <= j; h++)
        suma += p[h];
    return suma;
}

void paskristyk () {
    int D[MAXK+1][MAXN+1], M[MAXK+1][MAXN+1];

    // užpildomos kraštinęs reikšmės
    for (int i = 1; i <= k; i++)
        M[i][0] = 0;
    for (int j = 1; j <= n; j++) {
        M[1][j] = S(1, j);
        D[1][j] = 1;
    }

    // apskaičiuojama likusi lentelės dalis
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            M[i][j] = BEGALINIS;

            // renkamas minimumas...
            for (int l = 1; l <= j; l++) {
                // ...iš maksimumų
                v = max(S(l, j), M[i-1][l-1]);
                if (v < M[i][j]) {
                    M[i][j] = v;
                    D[i][j] = l;
                }
            }
        }
    }

    // sukonstruojamas optimalus sprendinys
    ivertis = M[k][n];
    int j = n;
    for (int i = k; i > 1; i--) {
        nuo[i] = D[i][j];
        j = D[i][j]-1;
        /*
            jei i-tajam darbuotojui skiriamos knygos nuo D[i][j],
            tai likusiems i-1 darbuotojų reikia paskirti
            D[i][j]-1 knygų
        */
    }
    nuo[1] = 1;
}
