const int MAXN = 20;
int p[MAXN];
bool panaudotas[MAXN+1];

// isspausdina sugeneruota kelini
void spausdink(int n) {
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

// n - elementu kiekis
// k - dabar nagrinejamo elemento indeksas
void gen(int n, int k) {
    if(k >= n) {
        spausdink(n);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!panaudotas[i]) {
            panaudotas[i] = true;
            p[k] = i;
            gen(n, k+1);
            p[k] = 0;
            panaudotas[i] = false;
        }
    }
}

// funkcijos kvietimas:
gen(n, 0);