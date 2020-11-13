const int MAXN = ...;

int seka[MAXN];
bool aplankyta[MAXN];

void ieskok (int k, int v) {
    /*
        k - kiek viršūnių apeita,
        v - kurioje viršūnėje sustota
    */

    seka[k] = v;
    // aplankytomis žymimos konstruojamame kelyje esančios viršūnės
    aplankyta[v] = true;
    if (k == n) {
        // jei apeitos visos viršūnės - tai rastas Hamiltono kelias
        spausdink(n);
    } else {
        // bandoma toliau eiti į visas neaplankytas v kaimynes
        for (int u : adj[v])
            if (!aplankyta[u])
                ieskok (k+1, u);
    }
    aplankyta[v] = false;
}
