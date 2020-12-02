int n;
int S;
int svoris[MAXN+1];
int D[MAXN+1][MAXS+1];
bool imti[MAXN+1];

void sudarykRinkini () {
    // pagal masyvų "D" ir "svoris" reikšmes nustatoma, kuriuos eksponatus verta imti
    for (int k = 1; k <= n; k++)
        imti[k] = false;

    int k = n, r = S;
    while (k > 0 && r > 0) {
        if (D[k][r] > D[k-1][r]) {
            // vadinasi, vertė D[k][r] gauta įtraukus k-ąjį eksponatą
            imti[k] = true;
            r -= svoris[k];
        }
        k--;
    }
}
