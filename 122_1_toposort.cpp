const int MAXN = ...;  // maksimalus viršūnių skaičius

int n;                 // viršūnių skaičius
vector<int> adj[MAXN]; // adj[i] yra i-tosios viršūnės kaimynų sąrašas
int laipsnis[MAXN];    // įėjimo laipsniai

vector<int> seka;

void toposort () {
    // topologinis išrikiavimas bus įrašomas į vektorių "seka"

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (laipsnis[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        seka.push_back(v); // v įrašomas į seką

        // "ištrinami" iš v išeinantys lankai ir papildoma eilė
        for (int u : adj[v]) {
            // u - viršūnės v kaimynė
            laipsnis[u]--;
            if (laipsnis[u] == 0)
                q.push(u);
        }
    }
}
