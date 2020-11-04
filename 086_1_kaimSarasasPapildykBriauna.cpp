void papildykBriauna (int u, int v) {
    /*
        Kadangi grafo kaimynystės sąrašą saugojomės
        globaliai (žr. ankstesnį kodą), nereikia
        paties grafo paduoti funkcijos parametruose.
    */

    adj[u].push_back (v);
    if (u != v) { // jei tai ne kilpa
        adj[v].push_back (u);
    }
}
