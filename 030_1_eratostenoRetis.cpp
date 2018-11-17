bool isPrime[MAXN];

void sieve(int n) {
    fill(isPrime+2, isPrime+n+1, true); // isPrime[2] = isPrime[3] = ... = isPrime[n] = true
    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            for(int j = 2*i; j <= n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}