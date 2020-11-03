void papildykBriauna (int u, int v) {
    /*
        Kadangi grafo kaimynystės matricą saugojomės
        globaliai (žr. ankstesnį kodą), nereikia
        paties grafo paduoti funkcijos parametruose.
    */

    briauna[v][u] = true;
    briauna[u][v] = true;
}
