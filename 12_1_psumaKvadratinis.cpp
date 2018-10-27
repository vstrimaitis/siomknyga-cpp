bool rasta = false;
int atsPr, atsPab;
for(int i = 0; i < n && !rasta; i++) {
    int suma = 0;
    for(int j = i; j < n && !rasta; j++) {
        suma += a[j];
        if (suma == K) {
            atsPr = i;
            atsPab = j;
            rasta = true;
        }
    }
}