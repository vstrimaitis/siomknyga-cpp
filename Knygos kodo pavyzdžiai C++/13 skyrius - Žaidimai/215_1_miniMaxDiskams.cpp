const int M = 13; // šį skaičių pasiekęs ar viršijęs, žaidėjas laimi

struct tPozicija {
    int s, d; // s ir d nusako konkrečią žaidimo poziciją
};

void atlikEjima (bool suktiPirmyn, tPozicija &p) {
    if (suktiPirmyn)
        p.d = (p.d + 4) % 6 + 1;
    else
        p.d = p.d % 6  + 1;
    p.s += p.d;
}

void atsaukEjima (bool suktiPirmyn, tPozicija &p) {
    p.s -= p.d;
    if (suktiPirmyn)
        p.d = p.d % 6 + 1;
    else
        p.d = (p.d + 4) % 6 + 1;
}

bool minIvertis (tPozicija pozicija);

bool maxIvertis (tPozicija pozicija) {
    /*
        randa pozicijos įvertį (ar tai laiminti pirmojo žaidėjo pozicija),
        jei ėjimą iš jos atlieka pirmasis (maksimizuojantis) žaidėjas
    */

    if (pozicija.s >= M) // jei žaidimas baigtas
        return false; // nes paskutinį ėjimą atliko antrasis žaidėjas
    else {
        bool grazinamasIvertis = false;
        bool kryptys[] = {false, true};
        for(bool suktiPirmyn : kryptys) { {
            atlikEjima(suktiPirmyn, pozicija);
            bool ivertis = minIvertis(pozicija);
            if (!grazinamasIvertis && ivertis) // jei grazinamasIvertis < ivertis
                grazinamasIvertis = ivertis;
            atsaukEjima(suktiPirmyn, pozicija);
        }
    }
}

bool minIvertis (tPozicija pozicija) {
    /*
        randa pozicijos įvertį (ar tai laiminti pirmojo žaidėjo pozicija),
        jei ėjimą iš jos atlieka antrasis (minimizuojantis) žaidėjas
    */

    if (pozicija.s >= M) // jei žaidimas baigtas
        return true; // nes paskutinį ėjimą atliko pirmasis žaidėjas
    else {
        bool grazinamasIvertis = true;
        bool kryptys[] = {false, true};
        for(bool suktiPirmyn : kryptys) { {
            atlikEjima(suktiPirmyn, pozicija);
            bool ivertis = maxIvertis(pozicija);
            if (grazinamasIvertis && !ivertis) // jei grazinamasIvertis > ivertis
                grazinamasIvertis = ivertis;
            atsaukEjima(suktiPirmyn, pozicija);
        }
    }
}

bool miniMax (int zaidejas, tPozicija pozicija) {
    /*
        randa pozicijos įvertį ("true", jei tai laiminti
        pirmojo žaidėjo pozicija ir "false" priešingu atveju
    */

    if (zaidejas == 1) // jei ėjimą atliks pirmasis (maksimizuojantis) žaidėjas
        return maxIvertis(pozicija);
    else
        return minIvertis(pozicija);
}
