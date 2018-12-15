const int MAXN = 20;
int p[MAXN];
int panaudotas[MAXN+1];

void gen(int nuo, int m, int n, int k) {
    if(m >= k) {
        spausdink(k);
        return;
    }
    for(int i = nuo; i <= n; i++) {
        if(!panaudotas[i]) {
            panaudotas[i] = true;
            p[m] = i;
            gen(i+1, m+1, n, k);
            p[m] = 0;
            panaudotas[i] = false;
        }
    }
}