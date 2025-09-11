#include <iostream>
#include <string>
using namespace std;

int main(){
    string namaBarang;
    int stok;
    double harga;
    
    cout << "===Warung Berkah===" << endl;
    cout << "Masukan Nama Barang: " ;
    getline(cin, namaBarang);
    cout << "Masukan Jumlah Stok: ";
    cin >> stok;
    cout << "Tarif Perpcs: Rp. ";
    cin >> harga;
    
    double total = stok * harga ;
    
    cout << "\n ===Data Warung Barang===" << endl;
    cout << "Nama Barang : "<< namaBarang << endl;
    cout << "Jumlah Stok : "<< stok << endl;
    cout << "Tarif Perpcs: Rp. " << total << endl;
    

    return 0;
}