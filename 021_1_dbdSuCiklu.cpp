long long DBD(long long a, long long b) {
    long long c;
    while (b > 0) {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}