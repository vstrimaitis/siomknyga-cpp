const long long BEGALINIS = 1e18;
const long long PARA = 24*60;
const int MAXM = ...; // maksimalus miestų skaičius
const int MAXR = ...; // maksimalus reisų skaičius

struct reisas {
    int kur, kada, trukme;
};

struct reisaiIsMiesto {
    int k; // miestų skaičius
    reisas reisai[MAXR];
};

int n;                    // miestų skaičius
reisaiIsMiesto mst[MAXM]; // grafas
long long laikas[MAXM];   // atvykimo laikai
bool prijungta[MAXM];

void dijkstra (int pr) { // pr - pradinis miestas
    // įrašomos pradinės masyvų reikšmės
    for (int u = 0; u < n; u++) {
        laikas[u] = BEGALINIS;
        prijungta[u] = false;
    }
    laikas[pr] = 0;

    int v = pr;
    while (v != -1) {
        // prijungiama viršūnė v
        prijungta[v] = true;

        // atnaujinama informacija apie kaimynes
        for (int i = 0; i < mst[v].k; i++) {
            int u = mst[v].reisai[i].kur;
            int t = mst[v].reisai[i].trukme;
            // kiek reikės laukti mieste u?
            int atvyksta = laikas[v] % PARA;
            int isvyksta = mst[v].reisai[i].kada;
            if (atvyksta <= isvyksta) // reisu pavyks išvykti tą pačią dieną
                t += (isvyksta - atvyksta);
            else // teks laukti kitos dienos
                t += (PARA - atvyksta) + isvyksta;

            // ar į u verta vykti per v?
            if (laikas[u] > laikas[v] + t)
                laikas[u] = laikas[v] + t;
        }

        // randama tolesnė kandidatė - dar neprijungta viršūnė su mažiausiu atstumu
        v = -1;
        int minAtstumas = BEGALINIS;
        for (int u = 0; u < n; u++) {
            if (!prijungta[u] && laikas[u] < minAtstumas) {
                v = u;
                minAtstumas = laikas[u];
            }
        }
    }
}

void keliauk (int pr) { // pr - pradinis miestas
    /*
        pradinis miestas keičiamas dviem miestais:
         miestu, kuriame kelionė prasidėjo, ir
         fiktyviu, kuriame kelionė baigėsi
    */
    int pb = n;
    n++;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < mst[i].k; j++)
            if (mst[i].reisai[j].kur == pr)
                mst[i].reisai[j].kut = pb;

    // suskaičiuojama, per kokį mažiausią laiką galima nuvykti į kiekvieną miestą
    dijkstra (pr);

    return laikas[pb];
    // jei maršruto nėra - laikas[pb] yra BEGALINIS
}
