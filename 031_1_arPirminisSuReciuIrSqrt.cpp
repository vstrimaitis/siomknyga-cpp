vector<int> primes; // visi pirminiai skaiciai iki sqrt(n)
bool pirminis(long long n) {
    for(int i = 0; primes[i]*primes[i] <= n; i++) {
        if(n%primes[i] == 0) return false;
    }
    return true;
}