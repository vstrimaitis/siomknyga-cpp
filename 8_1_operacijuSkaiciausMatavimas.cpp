#include <chrono>
#include <iostream>
using namespace std;

// Gauna laiką, praėjusį nuo 1970 m. sausio 1 d. milisekundėmis
long long dabartinisLaikas() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

int main() {
    int veiksmuSk = 0;
    long long pradzia = dabartinisLaikas();
    while (dabartinisLaikas() - pradzia < 1000) {
        veiksmuSk++;
    }
    cout << veiksmuSk << endl;
    return 0;
}