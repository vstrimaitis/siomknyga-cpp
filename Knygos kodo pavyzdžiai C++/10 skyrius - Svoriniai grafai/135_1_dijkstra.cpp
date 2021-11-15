/*
    Pastaba: pirmiau pateikiamas c++ kodas, analogiškas knygos kodui.
    Žemiau jo galite rasti efektyvią Dijkstros algoritmo realizaciją,
    kuri naudoja duomenų struktūrą priority_queue
*/

int atstumas[MAXN];
int pirmine[MAXN];
bool prijungta[MAXN];

void dijkstra (int p) {
    // įrašomos pradinės masyvų reikšmės
    for (int u = 0; u < n; u++) {
        atstumas[u] = BEGALINIS;
        pirmine[u] = -1;
        prijungta[u] = false;
    }

    atstumas[p] = 0;
    int v = p;
    while (v != -1) {
        // jei v != -1, tai rasta viršūnė, kurią galima prijungti
        prijungta[v] = true;
        for (int u = 0; u < n; u++) {
            if (svoris[v][u] < BEGALINIS && atstumas[u] > atstumas[v] + svoris[v][u]) {
                // į viršūnę u verčiau eiti per v
                atstumas[u] = atstumas[v] + svoris[v][u];
                pirmine[u] = v;
            }
        }

        // randama tolesnė viršūnė - dar neprijungta viršūnė su mažiausiu atstumu
        v = -1;
        int minAtstumas = BEGALINIS;
        for (int u = 0; u < n; u++) {
            if (!prijungta[u] && atstumas[u] < minAtstumas) {
                v = u;
                minAtstumas = atstumas[u];
            }
        }
        // jei tokia viršūnė nerasta, tai v = -1 ir ciklas nutraukiamas
    }
}



// Dijkstros algoritmo realizacija su priority_queue

vector<pair<int, int>> adj[MAXN];
/*
    adj[i] yra i-tosios viršūnės kaimynų sąrašas, kur
     adj[i][j].first yra j-tosios kaimynės numeris
     adj[i][j].second yra briaunos, jungiančios i-tąją viršūnę su jos j-tąja kaimyne, svoris
*/

void dijkstra (int p) {
    // įrašomos pradinės masyvų reikšmės
    for (int u = 0; u < n; u++) {
        atstumas[u] = BEGALINIS;
        pirmine[u] = -1;
        prijungta[u] = false;
    }

    atstumas[p] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // priority_queue, kurios top() elementas visad yra mažiausias
    q.push({atstumas[p], p}); // į q visados dedam poras {atstumas[i], i}, nes tada q.top() elementas visad būs mažiausio atstumo

    while (!q.empty()) {
        int v = q.top().second;
        if (!prijungta[v]) {
            prijungta[v] = true;
            for (auto p : adj[v]) { // einame per viršūnės v kaimynus
                int u = p.first;  // kaimynės numeris
                int w = p.second; // briaunos tarp v ir u svoris
                if (atstumas[u] > atstumas[v] + w) {
                    // verčiau į u eiti per v
                    atstumas[u] = atstumas[v] + w;
                    pirmine[u] = v;
                    q.push ({atstumas[u], u});
                }
            }
        }
    }
}
