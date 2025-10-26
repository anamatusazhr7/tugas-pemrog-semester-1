#include <iostream>
#include <string>

using namespace std;
 
 int main(){
    
    int Obat;
    cout << " Masukkan jumlah obat: ";
    cin >> Obat;
    
    string data [Obat][3];
    
    for (int i = 0; i < Obat; i++){
        cout << "\nObat ke-"<< i +1 << endl;
        cout << "Nama obat   : ";
        cin >> data [i][0];
        cout << "Stok        : ";
        cin >> data [i][1];
        cout << "Harga       : ";
        cin >> data [i][2];
    }
    
    cout << "\nNama Obat\tStok\tHarga\n";
    cout << "-----------------------------\n";
    for (int i = 0; i < Obat; i++){
        cout << "\n" << data [i][0] << "\t\t";
        cout << data [i][1] << "\t";
        cout << data [i][2] << endl;
    }
    return 0;
}
