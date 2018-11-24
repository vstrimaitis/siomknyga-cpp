void kelk(int n, char nuo, char tarp, char ant) {
    if(n == 0) return;
    kelk(n-1, nuo, ant, tarp); //nuo -> tarp
    cout << nuo << " -> " << ant << endl;
    kelk(n-1, tarp, nuo, ant); // tarp -> ant
}