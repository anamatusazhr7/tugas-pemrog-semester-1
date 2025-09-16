#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaBarang;
    int stock;
    double harga = 0; 

    cout << "=== Daftar Barang di Warung Pak Mamat ===\n";
    cout << "mie goreng      : Rp 4000\n";
    cout << "mie soto        : Rp 4000\n";
    cout << "kopi            : Rp 3000\n";
    cout << "es teh          : Rp 5000\n";
    cout << "roti            : Rp 4000\n";
    cout << "sabun mandi     : Rp 4500\n";
    cout << "sabun cuci      : Rp 12500\n";
    cout << "odol            : Rp 7500\n";
    cout << "sikat gigi      : Rp 6500\n";
    
    cout << "=== Warung Pak Maamat ===\n";
    cout << "Masukkan Nama Barang  : ";
    getline(cin, namaBarang);  

    cout << "Masukkan jumlah stock : ";
    cin >> stock;

    
    if (namaBarang == "mie goreng") {
        harga = 4000;
    } else if (namaBarang == "mie soto") {
        harga = 4000;
    } else if (namaBarang == "kopi") {
        harga = 3000;
    } else if (namaBarang == "es teh") {
        harga = 5000;
    } else if (namaBarang == "roti") {
        harga = 4000;
    } else if (namaBarang == "sabun mandi") {
        harga = 4500;
    } else if (namaBarang == "sabun mandi") {
        harga = 12500;
    } else if (namaBarang == "odol") {
        harga = 7500;
    } else if (namaBarang == "sikat gigi") {
        harga = 6500; 
        
    } else {
        cout << "\n⚠️ Maaf,\"" << namaBarang << "\" tidak ada di warung." << endl;
        return 0;
    }

    double total = stock * harga;

    cout << "\n=== Data Waroeng Kita ===" << endl;
    cout << "Nama Barang   : " << namaBarang << endl;
    cout << "Jumlah Stock  : " << stock << endl;
    cout << "Tarif Per pcs : Rp " << harga << endl;
    cout << "Total         : Rp " << total << endl;

    return 0;
}

