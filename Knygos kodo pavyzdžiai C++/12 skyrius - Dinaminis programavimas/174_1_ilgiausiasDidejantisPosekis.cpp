const int MAX = ...; // maksimalus sekos ilgis

int n;
int a[MAX+1];
int posekis[MAX+1];
int ilgis;

void ilgPosekis () {
    int L[MAX+1];
    int p[MAX+1];

    // optimalaus sprendinio vertė skaičiuojama iš apačios į viršų
    int kmax = 1;
    for (int m = 1; m <= n; m++) {
        for (int k = 1; k < m; k++) {
            if (a[k] < a[m] && L[k] > L[m]) {
                L[m] = L[k];
                // pažymimas priešpaskutinis šio posekio elementas
                p[m] = k;
            }
        }

        // priskaičiuojamas ir m-asis elementas
        L[m]++;
        if (L[kmax] < L[m])
            // tai ilgiausias kol kas rastas posekis
            kmax = m;
    }

    // sukonstruojamas optimalus sprendinys
    ilgis = L[kmax];
    for (int k = ilgis; k > 0; k--) {
        posekis[k] = a[kmax];
        kmax = p[kmax];
    }
}
