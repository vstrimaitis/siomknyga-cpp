const int MAX = ...;
long long Fmas[MAX+1];

long long F (long long n) {
    // dar neapsaičiuotos reikšmės žymimos -1
    if (Fmas[n] != -1)
        return Fmas[n];
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    Fmas[n] = F(n-1) + F(n-2);
    return Fmas[n];
}
