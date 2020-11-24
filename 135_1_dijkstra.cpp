
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

        // randama tolesnė koordinatė - dar neprijungta viršūnė su mažiausiu atstumu
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
