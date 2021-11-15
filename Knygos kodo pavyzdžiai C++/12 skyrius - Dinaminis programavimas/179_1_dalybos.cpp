int n;
int A;
int v[MAXN+1];
int G[MAXN*MAXM+1][MAXN+1];
bool Rusnei[MAXN+1];

void dalybos () {
    /*
        rezultatas įrašomas į masyvą "Rusnei":
         Rusnei[k] = true, jei k-ąją dovaną reikia skirti jai
    */

    // suskaičiuojama visų verčių suma
    long long Vsum = 0;
    for (int i = 1; i <= n; i++)
        Vsum += v[i];

    A = Vsum/2;
    destyk();

    // randama artimiausia Vsum/2 reikšmė, kurią galima išdėstyti
    int S = Vsum/2;
    while (!G[n][S]) {
        S--;
    }

    // nustatoma, kurias iš dovanų skirti Rusnei, kad jų bendra vertė būtų lygi S
    for (int i = 1; i <= n; i++)
        Rusnei[i] = false;
    for (int i = n; i > 0; i--) {
        // tikrinama, ar S vertės rinkiniui priklauso i-toji dovana
        if (!G[i-1][S]) {
            Rusnei[i] = true;
            S -= v[i];
        }
    }
}
