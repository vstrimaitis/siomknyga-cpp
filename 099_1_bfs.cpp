int atstumas[MAXN];    // saugomi atstumai nuo pradinės iki visų kitų viršūnių
int pirmine[MAXN];
int spalva[MAXN];      // 0, jei balta,
                       // 1, jei pilka,
                       // 2, jei juoda

void bfs (int p) {     // p - pradinė viršūnė
    queue<int> q;
    for (int i = 0; i < n; i++)
        atstumas[i] = -1;

    // į eilę įtraukiama pirma viršūnė
    spalva[p] = 1; // nuspalvinama pilkai
    atstumas[p] = 0;
    pirmine[p] = -1;
    q.push(p);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) { // einame per viršūnės v kaimynų sąrašą
            // dar neaplankytos (baltos) v kaimynės įtraukiamos į eilę
            if (spalva[u] == 0) {
                spalva[u] = 1; // viršūnė u nuspalvinama pilkai
                pirmine[u] = v;
                atstumas[u] = atstumas[v] + 1;
                q.push(u);
            }
        }
        spalva[v] = 2; // viršūnė v nuspalvinama juodai
    }
}
