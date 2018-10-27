int suma = a[0];
int i = 0, j = 0;
while (suma != K && j < n) {
    if (suma < K) {
        j++;
        if (j < n) {
            suma += a[j];
        }
    }
    else if (suma > K) {
        suma -= a[i];
        i++;
    }
}
bool rasta = suma == K;