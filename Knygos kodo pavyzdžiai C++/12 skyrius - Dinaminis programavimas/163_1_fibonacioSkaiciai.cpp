long long F (long long n) {
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    return F(n-1) + F(n-2);
}
