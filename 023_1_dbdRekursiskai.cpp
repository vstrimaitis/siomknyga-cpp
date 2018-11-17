long long DBD(long long a, long long b) {
    return b == 0 ? a : DBD(b, a%b);
}