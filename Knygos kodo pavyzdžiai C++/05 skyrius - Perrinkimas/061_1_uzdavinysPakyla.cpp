const int MAXH = 100;

int s[2*MAXH+1];
int P, H, V;

// generuoja sekos narį, kurio numeris k
void gen(int k) {
    if (k == 2*H) {
        spausdink(2*H);
    } else if (k == H+1) {
        // (H+1)-osios pakopos viršūnės plotis fiksuotas
        s[k] = s[k-1] + V;
        gen(k + 1);
    } else {
        // nagrinėjamos visos galimos k-ojo nario reikšmės

        int mx;
        if (k <= H)
            mx = P-(2*H-k)-(V-1);
        else
            mx = P-(2*H-k);

        for (int i = s[k-1]+1; i <= mx; i++) {
            s[k] = i;
            gen(k+1);
        }
    }
}


// Funkcija gen() turi būti iškviečiama tokiu būdu:
s[1] = 0
s[2*H] = P;
gen(2);
