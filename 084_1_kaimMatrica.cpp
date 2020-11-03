const int MAXN = ...;  // maksimalus viršūnių skaičius
                       // dažniausiai galima nustatyti pagal sąlygoje pateiktus ribojimus

int n;                    // viršūnių skaičius
bool briauna[MAXN][MAXN]; // jei briauna[i][j] == true, tai grafe yra briauna tarp viršūnių i ir j

// Pastaba: originaliame pavyzdyje grafas pateikiamas kaip struktūra,
//  tačiau čia kintamuosius ir bool masyvą apsirašome globaliai.
