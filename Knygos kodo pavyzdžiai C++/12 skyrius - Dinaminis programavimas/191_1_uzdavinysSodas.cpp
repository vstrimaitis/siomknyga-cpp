const int MAXM = ...; // maksimalus sodo dydis

int m;                      // sodo dydis
bool medis[MAXM+1][MAXM+1]; // medis[x][y] = true, jei (x, y) auga medis
int Hp[MAXM+1][MAXM+1];
int K[MAXM+1][MAXM+1];
int D[MAXM+1][MAXM+1];

int maxSodas () {
    // apskaičiuojame Hp reikšmes
    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= m; x++) {
            if (y == 1)
                Hp[x][y] = 1;
            else if (medis[x-1][y-1])
                Hp[x][y] = 1;
            else
                Hp[x][y] = Hp[x][y-1] + 1;
        }
    }

    // apskaičiuojame K ir D reikšmes kiekvienam stačiakampiui T
    // šių procedūrų tekstas bus pateiktas vėliau
    skaiciuokK();
    skaiciuokD();

    // belieka peržiūrėti visus stačiakampius ir išrinkti didžiausią
    int maxPlotas = 0;
    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= m; x++) {
            int plotas = Hp[x][y] * (D[x][y] - K[x][y]);
            if (plotas > maxPlotas)
                maxPlotas = plotas;
        }
    }
    return maxPlotas;
}
