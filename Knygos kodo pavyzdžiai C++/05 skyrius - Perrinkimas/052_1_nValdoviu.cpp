const int MAXN = 12;
bool eil[MAXN];
bool istr1[2*MAXN];
bool istr2[2*MAXN];
long long sprendiniuSk;

// padeda karaliene langelyje (r, c)
// r - eilutes numeris
// c - stulpelio numeris
// reiksme - true, jei padedame karaliene; false, jei nuimame
void padeti(int n, int r, int c, bool reiksme) {
    eil[r] = reiksme;
    istr1[r+c] = reiksme;
    istr2[r-c+n-1] = reiksme; // pridedam n-1, kad numeracija pasidarytu nuo 0, o ne nuo neigiamu skaiciu
}

// ar langelis (r, c) nera kertamas jokios karalienes?
// r - eilutes numeris
// c - stulpelio numeris
bool arLaisvas(int n, int r, int c) {
    return !eil[r] && !istr1[r+c] && !istr2[r-c+n-1];
}

// n - kiek is viso valdoviu
// c - kuriame stulpelyje dabar statome valdove
void statyk(int n, int c) {
    if(c >= n) {
        sprendiniuSk++;
        return;
    }
    for(int r = 0; r < n; r++) {
        if(arLaisvas(n, r, c)) {
            padeti(n, r, c, true);
            statyk(n, c+1);
            padeti(n, r, c, false);
        }
    }
}


// funkcijos kvietimas main'e:
statyk(n, 0);