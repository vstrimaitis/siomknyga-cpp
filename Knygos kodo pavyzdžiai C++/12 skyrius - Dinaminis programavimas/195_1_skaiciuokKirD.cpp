void skaiciuokD () {
    int deklas[MAXM+1];
    int sk = 0; // elementų skaičius dėkle
    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= m; x++) {
            if (sk > 0) {
                int s = deklas[sk];
                while (sk > 0 && Hp[x][y] < Hp[s][y]) {
                    // rastas dešinysis T(s, y) kraštas (x-1)
                    D[s][y] = x-1;
                    sk--;
                    if (sk > 0) s = deklas[sk];
                }
            }

            // koordinatė x dedama į dėklą
            sk++;
            deklas[sk] = x;
        }

        // jei dėkle likus koordinatė x, tai T(x, y) tęsiasi iki pat dešiniojo sodo krašto
        while (sk > 0) {
            s = deklas[sk];
            D[s][y] = m;
            sk--;
        }
    }
}

void skaiciuokK () {
    int deklas[MAXM+1];
    int sk = 0; // elementų skaičius dėkle
    for (int y = 1; y <= m; y++) {
        for (int x = m; x > 0; x--) {
            if (sk > 0) {
                int s = deklas[sk];
                while (sk > 0 && Hp[x][y] < Hp[s][y]) {
                    // rastas kairysis T(s, y) kraštas (x-1)
                    K[s][y] = x-1;
                    sk--;
                    if (sk > 0) s = deklas[sk];
                }
            }

            // koordinatė x dedama į dėklą
            sk++;
            deklas[sk] = x;
        }

        // jei dėkle likus koordinatė x, tai T(x, y) tęsiasi iki pat kairiojo sodo krašto
        while (sk > 0) {
            s = deklas[sk];
            K[s][y] = 0;
            sk--;
        }
    }
}

