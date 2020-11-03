bool mazejimo (int a, int b) { // funkcija rikiavimui mažėjimo tvarka
    a > b;
}

int n;                 // viršūnių skaičius
vector<int> adj[MAXN]; // kaimynystės sąrašas
bool aplankyta[MAXN];
vector<int> kompDydis; // komponentų dydžių sąrašas

int sk = 0;            // kiek viršūnių aplankėm

void dfs (int v) {
    aplankyta[v] = true;
    sk++;
    for (int u : adj[v]) // einame per viršūnės v kaimynų sąrašą
        if (!aplankyta[u])
            dfs (u);
}

int uzsikres (int m) { // m - jau užsikrėtusių paukščių skaičius (duodamas įvestyje)
    for (int i = 0; i < n; i++)
        aplankyta[i] = false;

    for (int i = 0; i < n; i++) {
        if (!aplankyta[i]) {
            sk = 0;
            dfs (i);
            kompDydis.push_back (sk);
        }
    }

    sort (kompDydis.begin(), kompDydis.end(), mazejimo);    // surikiuojam dydžius mažėjimo tvarka

    int ats = 0;
    m = min (m, (int)kompDydis.size()); // Jei m yra daugiau nei yra komponentų,
                                        //  tai visi komponentai ir bus užkrėsti,
                                        //  o tai yra tas pats, jei m būtų lygu komponentų skaičiui.
    for (int i = 0; i < m; i++)
        ats += kompDydis[i];

    return ats;
}
