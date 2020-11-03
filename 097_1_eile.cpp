struct eile {
    int duom[MAXN];
    int pradzia, pabaiga;

    void isvalyk () {
        pradzia = pabaiga = 0;
    }

    bool tuscia () {
        return (pradzia == pabaiga);
    }

    void idek (int x) {
        pabaiga++;
        duom[pabaiga] = x;
    }

    int isimk () {
        pradzia++;
        return duom[pradzia];
    }

};

// Vertėjo pastaba: C++ kalboje jau yra suimplementuota eilė:
//   #include <queue>
//   queue<int> q;
//  Tokia eilė palaiko visas reikiamas operacijas:
//   q.push(x) - įdeda į eilės galą skaičių x
//   q.front() - grąžina eilės priekyje esantį elementą
//   q.pop() - pašalina iš eilės priekinį elementą
