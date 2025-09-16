#include <iostream>
#include <string>
using namespace std;

int main(){
    string namaPemesan;
    int Kilogram;
    double harga;
    
    cout << "===Laundry Cahaya===" << endl;
    cout << "Masukan Nama Pemesan: " ;
    getline(cin, namaPemesan);
    cout << "Masukan Jumlah Berat Cucian (Kilogram): " ;
    cin >> Kilogram;
    cout << "Harga Perkilogram: Rp. ";
    cin >> harga;
    
    double total = Kilogram * harga ;
    
    cout << "\n ===Data Laundry Cahaya===" << endl;
    cout << "Nama Pemesan : "<< namaPemesan << endl;
    cout << "Jumlah Berat Cucian (Perkilogram) : "<< Kilogram << endl;
    cout << "Harga Perkilogram: Rp. " << total << endl;
    

    return 0;
}
