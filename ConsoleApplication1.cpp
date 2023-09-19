#include <iostream>
#include <vector>

using namespace std;

void FindPrimeFast(int n) {
    vector<bool> isPrime(n + 1, true);  // создаем вектор для хранения простых чисел
    isPrime[0] = isPrime[1] = false;  // 0 и 1 не являются простыми числами

    for (int p = 2; p * p <= n; p++) {  // перебираем числа от 2 до квадратного корня из n
        if (isPrime[p]) {  // если p простое число
            for (int i = p * p; i <= n; i += p) {  // помечаем все кратные p числа как составные
                isPrime[i] = false;
            }
        }
    }

    cout << "Простые числа от 2 до " << n << ":\n";
    for (int i = 2; i <= n; i++) {  // выводим все простые числа
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    setlocale(0,"");
    int n;
    cout << "Введите верхнюю границу диапазона: ";
    cin >> n;
    FindPrimeFast(n);
    return 0;
}