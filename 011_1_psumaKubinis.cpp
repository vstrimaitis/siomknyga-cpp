bool rasta = false;
int atsPr, atsPab;
for(int i = 0; i < n && !rasta; i++) {
    for(int j = i; j < n && !rasta; j++) {
        int suma = 0;
        for(int k = i; k <= j; k++) {
            suma += a[k];
        }
        if (suma == K) {
            atsPr = i;
            atsPab = j;
            rasta = true;
        }
    }
}