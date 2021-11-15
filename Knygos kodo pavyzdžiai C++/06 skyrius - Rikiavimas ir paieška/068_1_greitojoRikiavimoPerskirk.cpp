/*
    Pastaba: masyvas a aprašytas globaliai
    viename iš praeitų kodo pavyzdžių.
*/

int perskirk (int k, int d) {
    int x = a[k]; // dalijamoji reikšmė
    int i = k-1;
    int j = d+1;
    int rez = 0; // grąžinamas rezultatas
    while (rez == 0) {
        do { // praleidžiami elementai, mažesni už x
            i++;
        } while (a[i] >= x);

        do { // praleidžiami elementai, didesni už x
            j--;
        } while (a[i] <= x);

        if (i < j)
            swap(a[i], a[j]);
        else
            rez = j;
    }

    return rez;
}
