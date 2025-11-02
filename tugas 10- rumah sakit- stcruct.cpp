#include <iostream>
using namespace std;

struct Pasien {
    string namaPasien;
    string jenisPenyakit;
    string alamatPasien;
    double biayaPerawatan;
};

int main() {
    int jumlahPasien;
    
    cout << "\n=============================================" << endl;
    cout << "  DATA PASIEN RUMAH SAKIT KASIH IBU" << endl;
    cout << "=============================================" << endl;
    
    cout << "\nMasukkan jumlah pasien: ";
    cin >> jumlahPasien;
    
    Pasien dataPasien[jumlahPasien];
    
    for (int i = 0; i < jumlahPasien; i++) {
        cout << "\n--- DATA PASIEN KE-" << (i + 1) << " ---" << endl;
        
        cout << "Nama Pasien    : ";
        cin.ignore();
        getline(cin, dataPasien[i].namaPasien);
        
        cout << "Jenis Penyakit : ";
        getline(cin, dataPasien[i].jenisPenyakit);
        
        cout << "Alamat         : ";
        getline(cin, dataPasien[i].alamatPasien);
        
        cout << "Biaya Perawatan: Rp ";
        cin >> dataPasien[i].biayaPerawatan;
    }
    
    cout << "\n===============================================" << endl;
    cout << "  DAFTAR SELURUH PASIEN RUMAH SAKIT KASIH IBU" << endl;
    cout << "===============================================" << endl;
    
    double totalBiaya = 0;
    
    for (int i = 0; i < jumlahPasien; i++) {
        cout << "\nPasien ke-" << (i + 1) << endl;
        cout << "Nama           : " << dataPasien[i].namaPasien << endl;
        cout << "Jenis Penyakit : " << dataPasien[i].jenisPenyakit << endl;
        cout << "Alamat         : " << dataPasien[i].alamatPasien << endl;
        cout << "Biaya Perawatan: Rp " << dataPasien[i].biayaPerawatan << endl;
        cout << "----------------------------------------" << endl;
        
        totalBiaya += dataPasien[i].biayaPerawatan;
    }
    
    cout << "\n========================================" << endl;
    cout << "Total Biaya Seluruh Pasien: Rp " << totalBiaya << endl;
    cout << "========================================" << endl;
    
    return 0;
}
