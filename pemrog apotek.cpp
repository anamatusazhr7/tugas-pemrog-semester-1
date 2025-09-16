#include <iostream>
using namespace std;

int main(){
    //variabel penting
    string namaObat;
    int jumlahStok;
    double tarif;

    //input dari user
    cout << "===Apotik Cinta===" << endl;
    cout << "Masukan Nama Obat: " ;
    getline(cin, namaObat);
    cout << "Masukan Jumlah Stok: ";
    cin >> jumlahStok;
    cout << "Tarif Perobat: Rp. ";
    cin >> tarif ;

    //hitung total biaya
    double total = jumlahStok * tarif ;
    
    //tampilan data awal
    cout << "\n ===Data Apotek Cinta===" << endl;
    cout << "Nama Obat : "<< namaObat << endl;
    cout << "Jumlah Stok : "<< jumlahStok << endl;
    cout << "Tarif perobat : "<< tarif << endl;
    cout << "Total biaya : Rp. " << total << endl;
    

    return 0;
}
