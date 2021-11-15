const int MAXN = ...; // maksimalus dėmenų skaičius
const int MAXM = ...; // maksimali dėmens vertė

int n;
int A;
int v[MAXN+1];
bool G[MAXN*MAXM+1][MAXN+1];

void destyk () {
    // išvalomos masyvo reikšmės
    for (int k = 0; k <= n; k++)
        for (int S = 0; S <= A; S++)
            g[k][s] = false;

    // išdėstomos sumos
    G[0][0] = true; // inicializuojama kraštinė reikšmė
    for (int k = 1; k <= n; k++) {
        for (int S = 0; S <= A; S++) {
            if (G[k-1][S])
                G[k][S] = true;
            else if (v[k] <= S) {
                if (G[k-1][S-v[k]])
                    G[k][S] = true;
            }
        }
    }
}
