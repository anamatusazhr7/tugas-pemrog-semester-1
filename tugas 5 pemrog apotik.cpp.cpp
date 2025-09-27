#include <iostream>
using namespace std;
int main() {
    // Program untuk memeriksa stok obat di apotek
    
    // Meminta input stok obat dari pengguna
    int stok;
    cout << "Masukkan jumlah stok obat: ";
    cin >> stok;
    
    // Memeriksa kondisi stok
    if (stok > 50) {
        cout << "Stok Aman" << endl;
    } else if (20 <= stok && stok <= 50) {
        cout << "Stok Menipis" << endl;
    } else {  // stok < 20
        cout << "Stok Habis, Segera Restok!" << endl;
    }
    
    return 0;
}
