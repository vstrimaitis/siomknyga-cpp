bool tiltas (int v, int u) {
    if (briaunuSk[v][u] > 1)
        return false;
    
    for (int k = 0; k < n; k++)
        spalva[k] = 0;

    briaunuSk[v][u]--;
    briaunuSk[u][v]--;
    dfs(u);
    briaunuSk[v][u]++;
    briaunuSk[u][v]++;

    return spalva[v] == 0;
}
