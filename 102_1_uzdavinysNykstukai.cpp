const int MAXN = 100000, // maksimalus kambarių (grafo viršūnių) skaičius
          MAXK = 100000; // maksimalus nykštukų skaičius
                         // tiek MAXN, tiek MAXK galima sužinoti iš pateiktų sąlygoje ribojimų

int n;                 // viršūnių (kambarių) skaičius
vector<int> adj[MAXN]; // kaimynystęs sąrašas, kur adj[i] yra i-tosios viršūnės kaimynų sąrašas

int nykSk;       // nykštukų skaičius
int kamb[MAXN];  // kamb[i] - i-tojo nykštuko kambario numeris
int isejimas, t;
bool spes[MAXN];

int atstumas[MAXN];

void bfs (int p) { // p - pradinė viršūnė
    queue<int> q;
    for (int i = 0; i < n; i++)
        atstumas[i] = -1;

    // į eilę įtraukiama pradinė viršūnė
    atstumas[p] = 0;
    q.push (p);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) { // pereinama per viršūnės v kaimynų sąrašą
            // visos neaplankytos (pažymėtos atstumu -1) v kaimynės įtraukiamos į eilę
            if (atstumas[u] == -1) {
                atstumas[u] = atstumas[v] + 1;
                q.push(u);
            }
        }
    }
}

void kasSpes () {
    bfs (isejimas);
    for (int i = 0; i < nykSk; i++)
        spes[i] = atstumas[kamb[i]] <= t;
}














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
