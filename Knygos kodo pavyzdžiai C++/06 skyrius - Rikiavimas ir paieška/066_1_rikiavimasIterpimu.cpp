/*
    Pastaba: kintamasis n ir masyvas a aprašytas globaliai
    praeitame kodo pavyzdyje.
*/

void rikiuok () {
    for (int k = 0; k < n-1; k++) {
        int t = a[k+1];
        // Skaičių t terprsime į išrikiuotą masyvo dalį [1..k]
        int i = k;
        while (i > 0 && a[i] > t) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = t;
    }
}
