const int MAXN = 20;
int p[MAXN];
bool panaudotas[MAXN+1];

void gen(int m, int n, int k) {
    if(m >= k) {
        spausdink(k);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!panaudotas[i]) {
            panaudotas[i] = true;
            p[m] = i;
            gen(m+1, n, k);
            p[m] = 0;
            panaudotas[i] = false;
        }
    }
}