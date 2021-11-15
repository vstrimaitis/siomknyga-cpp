const int MAXN = ...; // maksimalus sekos ilgis
int n, x;
int a[MAXN];

int ieskok () {
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1; // elementas nerastas
}
