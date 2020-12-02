const int MAX = ...;
long long Fmas[MAX+1];

long long F (long long n) {
    Fmas[0] = 0;
    Fmas[1] = 1;
    for (int k = 2; k <= n; k++)
        Fmas[k] = Fmas[k-1] + Fmas[k-2];
    return Fmas[n];
}
