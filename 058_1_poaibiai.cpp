const int MAXN = 20;

bool parinktas[MAXN];

void spausdink(int m) {
    cout << "{";
    for(int i = 0; i < m; i++) {
        if(parinktas[i]) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
}

void gen(int k, int n) {
    if(k >= n) {
        spausdink(n);
        return;
    }
    for(int log = 0; log <= 1; log++) {
        parinktas[k] = log;
        gen(k+1, n);
    }
}