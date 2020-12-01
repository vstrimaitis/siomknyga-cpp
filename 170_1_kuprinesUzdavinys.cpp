const int MAXN = ...; // maksimalus eksponatų skaičius
          MAXS = ...; // maksimalus panešamas svoris

int n;
int S;
int svoris[MAXN+1];
int verte[MAXN+1];
int D[MAXN+1][MAXS+1];

void skaiciuok () {
    // užpildomos kraštinės lentelės  reikšmės
    for (int r = 0; r <= S; r++)
        D[0][r] = 0;
    for (int k = 0; k <= n; k++)
        D[k][0] = 0;
    // užpildoma visa likusi lentelės dalis
    for (int r = 1; r <= S; r++) {
        for (int k = 1; k <= n; k++) {
            if (svoris[k] <= r)
                // jei k-asis eksponatas tilptų
                D[k][r] = max (D[k-1][r], verte[k-1] + D[k-1][r-svoris[k]])
            else
                // jei k-asis eksponatas netilptų, jo įtraukti negalima
                D[k][r] = D[k-1][r];
        }
    }
}
