const int BEGALINIS = ...; // kažkoks pakankamai didelis skaičius, pavyzdžiui 1e9
const int MAXN = ...;      // maksimalus viršūnių skaičius

int n;                     // viršūnių skaičius
int svoris[MAXN][MAXN];
int pirmine[MAXN];
vector<int> antrSar[MAXN]; // antrinių viršūnių sąrašas
bool prijungta[MAXN];
int kaina[MAXN];

void primo () {
    // ieškomas medis grąžinamas masyve "pirmine"

    // įrašomos pradinės masyvų reikšmės
    for (int u = 0; u < n; u++) {
        kaina[u] = BEGALINIS;
        pirmine[u] = -1;
        prijungta[u] = false;
    }

    int v = 0;
    kaina[v] = 0; // pradėsime nuo viršūnės su numeriu 0

    while (v != -1) {
        // jei v != -1, tai rasta viršūnė, kurią galima prijungti
        prijungta[v] = true;

        for (int u = 0; u < n; u++) { // nagrinėjamos kaimynės
            if (!prijungta[u] && svoris[v][u] < BEGALINIS && kaina[u] > svoris[v][u]) {
                // viršūnę u verčiau prijungti prie v
                kaina[u] = svoris[v][u];
                pirmine[u] = v;
            }
        }

        // randama tolesnė kandidatė - dar neprijungta viršūnė su mažiausia prijungimo kaina
        v = -1;
        int minKaina = BEGALINIS;
        for (int u = 0; u < n; u++) {
            if (!prijungta[u] && kaina[u] < minKaina) {
                v = u;
                minKaina = kaina[u];
            }
        }

        // jei jokia viršūnė nerasta, tai v = -1 ir ciklas nutraukiamas

    }
}
