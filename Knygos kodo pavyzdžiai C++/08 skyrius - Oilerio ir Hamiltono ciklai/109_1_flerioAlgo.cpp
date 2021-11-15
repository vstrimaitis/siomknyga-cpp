const int MAXB = ...; // maksimalus briaunų skaičius

int kelioIlgis;
int kelias[MAXB];

void flerio () {
    /*
        jei Oilerio ciklas/kelias grafe neegzistuoja, tai "kelioIlgis"
        reikšmė bus lygi nuliui, kitu atveju Oilerio ciklas/kelias
        įrašomas į masyvą "kelias"
    */

    int nelyg = 0;
    // suskaičiuojama, kiek yra nelyginio laipsnio viršūnių, ir pradinė viršūnė (v)
    int v = 0;
    for (int k = 0; k < n; k++) {
        if (laipsnis[k] % 2 == 1) {
            nelyg++;
            v = k;
        }
    }

    kelioIlgis = 0;

    if (nelyg == 0 || nelyg == 2) {
        /*
            jei tenkinamos būtinos Oilerio ciklo/kelio sąlygos,
            vykdomas Flerio algoritmas
        */
        while (v > -1) {
            kelioIlgis++;
            kelias[kelioIlgis] = v;
            int p = v; // paskutinė pereita viršūnė
            v = -1;
            // pagal Flerio algoritmą pasirenkama kita viršūnė
            for (int u = 0; u < n; u++)
                if (briaunuSk[p][u] > 0 && (v == -1 || !tiltas(p, u)))
                    v = u;
            if (v > -1) {
                // ištrinama briauna
                briaunuSk[p][v]--;
                briaunuSk[v][p]--;
            }
        }
    }

}
