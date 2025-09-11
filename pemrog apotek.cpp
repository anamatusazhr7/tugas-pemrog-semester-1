#include <iostream>
#include <string>
using namespace std;

int main(){
    string namaObat;
    int stok;
    double harga;
    
    cout << "===Apotik Cinta===" << endl;
    cout << "Masukan Nama Obat: " ;
    getline(cin, namaObat);
    cout << "Masukan Jumlah Stok: ";
    cin >> stok;
    cout << "Tarif Perobat: Rp. ";
    cin >> harga;
    
    double total = stok * harga ;
    
    cout << "\n ===Data Apotek Cinta===" << endl;
    cout << "Nama Obat : "<< namaObat << endl;
    cout << "Jumlah Stok : "<< stok << endl;
    cout << "Tarif Perobat: Rp. " << total << endl;
    

    return 0;
}