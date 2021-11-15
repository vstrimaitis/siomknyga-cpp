/*
    Pastaba: kintamasis n ir masyvas a aprašytas globaliai
    viename iš praeitų kodo pavyzdžių.
*/

void rikiuok (int k, int d) {
    if (k < d) {
        int v = perskirk(k, d);
        // rekursyviai išrikiuojamos kairioji ir dešinioji masyvo dalys
        rikiuok (k, v);
        rikiuok (v+1, d);
    }
}

// Norint surikiuoti n elementų seką a, kviečiama funkcija:
rikiuok (0, n-1);
