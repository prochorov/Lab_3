#include <iostream>

using namespace std;

void minmax(double G[], int B) {
    int maxmayachok, minmayachok;
    double min, max;
    maxmayachok = 1;
    minmayachok = 1;

    for (int i = 0; i < B; i++) {

        if (minmayachok == 1) {
            min = G[i];
            minmayachok = 0;
        }
        if (maxmayachok == 1) {
            max = G[i];
            maxmayachok = 0;
        }

        if (G[i] < min)
            min = G[i];

        if (G[i] > max)
            max = G[i];

    }
    for (int i = 0; i < B; i++) {
        G[i] = (G[i] - min) / (max - min);
        cout << G[i] << endl;
    }
}

int main() {
    int N;
    cout << "Введите кол-во элементов в массиве: ";
    cin >> N;
    double k[N];
    for (int i = 0; i < N; i++) {
        cout << "Введите " << i + 1 << " член массива:";
        cin >> k[i];
    }
    minmax(k, N);
    return 0;
}