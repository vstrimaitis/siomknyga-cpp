const int MAXN = ...; // maksimalus eksponatų skaičius
          MAXS = ...; // maksimalus panešamas svoris

int n;
int S;
int svoris[MAXN+1];
int verte[MAXN+1];
int dp[MAXN+1][MAXS+1]; // knygoje šis masyvas žymimas "D", tačiau žymėti "dp" yra labiau įprasta

void skaiciuok () {
    // užpildomos kraštinės lentelės  reikšmės
    for (int r = 0; r <= S; r++)
        dp[0][r] = 0;
    for (int k = 0; k <= n; k++)
        dp[k][0] = 0;
    // užpildoma visa likusi lentelės dalis
    for (int r = 1; r <= S; r++) {
        for (int k = 1; k <= n; k++) {
            if (svoris[k] <= r)
                // jei k-asis eksponatas tilptų
                dp[k][r] = max(
                    dp[k-1][r],                         // k-ojo daikto neimame - svorį r turime gauti iš pirmų k-1 daiktų
                    verte[k-1] + dp[k-1][r-svoris[k]]   // k-ąjį daiktą imame - tuomet pridedama jo vertė ir iš pirmų k-1 daiktų reikia surinkti svorį r-svoris[k]
                );
            else
                // jei k-asis eksponatas netilptų, jo įtraukti negalima
                dp[k][r] = dp[k-1][r];
        }
    }
}
