bool pirminis(long long n) {
    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;

    for(int d = 3; d*d <= n; d+=2) {
        if(n%d == 0) return false;
    }
    return true;
}