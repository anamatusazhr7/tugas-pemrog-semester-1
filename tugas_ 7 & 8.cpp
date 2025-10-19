#include <iostream>
using namespace std;

int main() {
    int tambah, kurang, menu;
    int total = 0; // Inisialisasi total stok
    
    cout << "======================================"<< endl;
    cout << " Halo! Selamat Datang di Apotek Cinta " << endl; 
    cout << "======================================" << endl;
    
    do {
        // Menampilkan menu
        cout << "\n========== MENU UTAMA ==========" << endl;
        cout << "1. Menambah total stok obat" << endl;
        cout << "2. Mengurangi total stok obat" << endl;
        cout << "3. Menampilkan total stok obat" << endl;
        cout << "4. Keluar" << endl;
        cout << "================================" << endl;
        cout << "Silahkan pilih menu (1-4): ";
        cin >> menu;
        cout << endl;
        
        // Switch case untuk memproses pilihan menu
        switch (menu) {
            case 1:
                cout << "Masukkan jumlah stok yang ingin ditambah: ";
                cin >> tambah;
                
                if (tambah < 0) {
                    cout << "ERROR: Jumlah tidak boleh negatif!" << endl;
                } else {
                    total = total + tambah;
                    cout << "Stok berhasil ditambah sebanyak " << tambah << " unit" << endl;
                    cout << "Total stok sekarang: " << total << " unit" << endl;
                }
                break;
            
            case 2:
                cout << "Masukkan jumlah stok yang ingin dikurangi: ";
                cin >> kurang;
                
                if (kurang < 0) {
                    cout << "ERROR: Jumlah tidak boleh negatif!" << endl;
                } else if (kurang > total) {
                    cout << "ERROR: Stok tidak mencukupi!" << endl;
                    cout << "Stok tersedia: " << total << " unit" << endl;
                } else {
                    total = total - kurang;
                    cout << "Stok berhasil dikurangi sebanyak " << kurang << " unit" << endl;
                    cout << "Total stok sekarang: " << total << " unit" << endl;
                }
                break;
            
            case 3:
                cout << "========== INFORMASI STOK ==========" << endl;
                cout << "Total stok obat saat ini: " << total << " unit" << endl;
                cout << "====================================" << endl;
                break;
            
            case 4:
                cout << "======================================"<< endl;
                cout << "   Terima kasih telah menggunakan" << endl;
                cout << "      Sistem Apotek Cinta!" << endl;
                cout << "======================================"<< endl;
                break;
            
            default:
                cout << "ERROR: Pilihan tidak valid!" << endl;
                cout << "Silahkan pilih menu 1-4" << endl;
                break;
        }
        
        cout << endl;
        
    } while (menu != 4); // Loop akan terus berjalan sampai user pilih menu 4
    
    return 0;
}
