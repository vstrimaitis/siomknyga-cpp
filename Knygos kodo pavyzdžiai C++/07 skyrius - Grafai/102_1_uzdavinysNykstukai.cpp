const int MAXN = ...,  // maksimalus kambarių (grafo viršūnių) skaičius
          MAXK = ...;  // maksimalus nykštukų skaičius
                       // tiek MAXN, tiek MAXK galima sužinoti iš pateiktų sąlygoje ribojimų

int n;                 // viršūnių (kambarių) skaičius
vector<int> adj[MAXN]; // kaimynystęs sąrašas, kur adj[i] yra i-tosios viršūnės kaimynų sąrašas

int nykSk;             // nykštukų skaičius
int kamb[MAXN];        // kamb[i] - i-tojo nykštuko kambario numeris
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
