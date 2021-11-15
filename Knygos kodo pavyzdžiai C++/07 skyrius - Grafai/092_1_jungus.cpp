bool aplankyta[MAXN];
int sk = 0;            // kiek viršūnių aplankėm

void dfs (int v) {
    aplankyta[v] = true;
    sk++;
    for (int u : adj[v]) // einame per viršūnės v kaimynų sąrašą
        if (!aplankyta[u])
            dfs (u);
}

bool jungus () {
    for (int i = 0; i < n; i++)
        aplankyta[i] = false;
    sk = 0;
    dfs (0);
    return (sk == n);
}
