const int MAXN = ...;  // maksimalus galimas viršūnių skaičius
                       // dažniausiai galima nustatyti pagal sąlygoje pateiktus ribojimus

int n;                 // viršūnių skaičius
vector<int> adj[MAXN]; // adj[i] yra i-tosios viršūnės kaimynų sarašas

// Pastaba: pascal kalbos kode grafas pateikiamas kaip struktūra,
//  tačiau čia kintamuosius ir kaimynystės sąrašą apsirašome globaliai.
