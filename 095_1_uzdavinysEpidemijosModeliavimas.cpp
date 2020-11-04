bool mazejimo (int a, int b) { // funkcija rikiavimui mažėjimo tvarka
    return a > b;

}

const int MAXN = ...;  // maksimalus grafo viršūnių skaičius
                       // jį galima sužinoti iš sąlygoje pateiktų ribojimų

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
    int iki;

    if (m > (int)kompDydis.size()) // užsikrėtusių paukščių gali būti daugiau nei jungumo komponentų
        iki = (int)kompDydis;
    else
        iki = m;

    for (int i = 0; i < iki; i++)
        ats += kompDydis[i];

    return ats;
}
