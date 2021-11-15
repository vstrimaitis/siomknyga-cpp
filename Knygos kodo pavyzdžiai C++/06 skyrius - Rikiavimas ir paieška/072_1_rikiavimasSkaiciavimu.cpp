const int MAXN = ...; // maksimalus masyvo ilgis
const int MAXS = ...; // maksimali sekos nario reikšmė

int n;
int a[MAXN];
int c[MAXS+1]; // c[i] nurodys, kiek sekoje yra skaičių i

void rikiuok () {
    // suskaičiuojama, kiek kokių elementų yra masyve a
    for (int i = 0; i <= MAXS; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[a[i]]++;

    // visi n masyvo a elementų surašomi iš eilės
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (c[j] == 0) {
            j++;
        }
        c[j]--;
        a[i] = j;
    }
}
