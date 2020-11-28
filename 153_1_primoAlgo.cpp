/*
    Pastaba: pirmiau pateikiamas Primo algoritmo kodas, analogiškas knygos kodui,
    o žemiau - efektyvus, naudojantis duomenų struktūrą priority_queue (kaip ir efektyvioje
    Dijkstros algoritmo realizacijoje).
    Taip pat verta paminėti, kad olimpiadose patogiausia naudoti Kruskalio algoritmą MJM rasti,
    kurio realizacijoje naudojama duomenų struktūra "nesikertančių aibių sąjunga" (trumpinama, DSU).
    Apie Kruskalio algoritmą galite pasiskaityti čia: https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html
*/

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



// Primo algoritmo realizacija, naudojanti priority_queue

vector<pair<int, int>> adj[MAXN];
/*
    adj[i] yra i-tosios viršūnės kaimynų sąrašas, kur
     adj[i][j].first yra j-tosios kaimynės numeris
     adj[i][j].second yra briaunos, jungiančios i-tąją viršūnę su jos j-tąja kaimyne, svoris
*/

void primo () {
    // įrašomos pradinės masyvų reikšmės
    for (int u = 0; u < n; u++) {
        kaina[u] = BEGALINIS;
        pirmine[u] = -1;
        prijungta[u] = false;
    }

    kaina[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // priority_queue, kurios top() elementas visad yra mažiausias
    q.push({kaina[p], p}); // į q visados dedam poras {kaina[i], i}, nes tada q.top() elementas visad būs mažiausios kainos

    while (!q.empty()) {
        int v = q.top().second;
        if (!prijungta[v]) {
            prijungta[v] = true;
            for (auto p : adj[v]) { // einame per viršūnės v kaimynus
                int u = p.first;  // kaimynės numeris
                int w = p.second; // briaunos tarp v ir u svoris
                if (kaina[u] > w) {
                    // verčiau į u eiti per v
                    kaina[u] = w;
                    pirmine[u] = v;
                    q.push ({kaina[u], u});
                }
            }
        }
    }
}
