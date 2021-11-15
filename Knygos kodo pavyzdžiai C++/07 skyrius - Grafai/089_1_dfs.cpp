int spalva[MAXN];      // spalva[i] yra 0, jei i-tosios viršūnės spalva yra balta,
                       //               1 - jei pilka,
                       //               2 - jei juoda
                       // pradinės reikšmės - 0
int pirmine[MAXN];     // prieš kviečiant DFS reiktų nustatyti pradines reikšmes į -1

void dfs (int v) {
    spalva[v] = 1;            // nuspalvinam viršūnę v pilkai
    for (int u : adj[v]) {    // einame per kaimynų sąrašą
        if (spalva[u] == 0) { // kaimyninė viršūnė u yra dar neaplankyta
            pirmine[u] = v;
            dfs (u);
        }
    }
    spalva[v] = 2;            // nuspalvinam viršūnę v juodai
}
