#include <iostream>
#include <string>
using namespace std;

void printSpaces(int count) {
    for (int i = 0; i < count; i++) cout << " ";
}

int main() {
    const int jumlahJenisBarang = 10;
    
    string namaBarang[jumlahJenisBarang] = {
        "Kopi Luwak", "Kopi Hitam", "Teh Pucuk", "Gula Putih 1kg",
        "Sabun", "Odol", "Sikat Gigi", "Telor 1kg",
        "Minyak Goreng 1L", "Tepung Terigu",
    };

    int stok[jumlahJenisBarang] = {
        200, 390, 200, 100, 
        100, 90, 400, 520,
        390, 400,
    };
    
    double harga[jumlahJenisBarang] = {
        3500.00, 3000.00, 4000.00, 10000.00,
        3000.00, 7000.00, 5000.00, 30000.00,
        18000.00, 12000.00
    };
    
    int keranjang[jumlahJenisBarang] = {0};
    double totalBelanja = 0.0;

    // --- 1. TAMPILKAN DAFTAR BARANG ---
    cout << "=====================================================" << endl;
    cout << "        SELAMAT DATANG DI WARUNG PAK MAMAT" << endl;
    cout << "=====================================================" << endl;
    
    const int LEBAR_NOMOR = 4;
    const int LEBAR_NAMA = 22;
    const int LEBAR_HARGA = 15;

    cout << "No.";
    printSpaces(LEBAR_NOMOR - 3);
    cout << "Nama Barang";
    printSpaces(LEBAR_NAMA - 11);
    cout << "Harga";
    printSpaces(LEBAR_HARGA - 5);
    cout << "Stok" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < jumlahJenisBarang; i++) {
        string nomorStr = to_string(i + 1) + ".";
        string hargaStr = "Rp" + to_string((int)harga[i]);

        cout << nomorStr;
        printSpaces(LEBAR_NOMOR - nomorStr.length());
        
        cout << namaBarang[i];
        printSpaces(LEBAR_NAMA - namaBarang[i].length());
        
        cout << hargaStr;
        printSpaces(LEBAR_HARGA - hargaStr.length());
        
        cout << stok[i] << endl;
    }
    cout << "=====================================================" << endl;

    // --- 2. INPUT PILIHAN BARANG + MENU ---
    while (true) {
        cout << "\nMenu: \n";
        cout << "1. Tambah barang ke keranjang\n";
        cout << "2. Lihat struk sementara\n";
        cout << "3. Checkout\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            int nomorPilihan, jumlah;
            cout << "Masukkan nomor barang: ";
            cin >> nomorPilihan;

            if (nomorPilihan > 0 && nomorPilihan <= jumlahJenisBarang) {
                int index = nomorPilihan - 1;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;

                if (jumlah <= stok[index]) {
                    keranjang[index] += jumlah;
                    stok[index] -= jumlah;
                    cout << jumlah << " " << namaBarang[index] 
                         << " ditambahkan ke keranjang." << endl;
                } else {
                    cout << "[!] Stok tidak cukup. Stok tersedia: " 
                         << stok[index] << endl;
                }
            } else {
                cout << "[!] Nomor barang tidak valid." << endl;
            }
        } 
        else if (pilihan == 2) {
            // tampilkan struk sementara
            cout << "\n=== Struk Sementara ===" << endl;
            totalBelanja = 0.0;
            for (int i = 0; i < jumlahJenisBarang; i++) {
                if (keranjang[i] > 0) {
                    double subTotal = keranjang[i] * harga[i];
                    cout << namaBarang[i] << " x " << keranjang[i] 
                         << " = Rp" << (int)subTotal << endl;
                    totalBelanja += subTotal;
                }
            }
            cout << "----------------------------" << endl;
            cout << "Total sementara = Rp" << (int)totalBelanja << endl;
        }
        else if (pilihan == 3) {
            // checkout: tampilkan struk akhir
            cout << "\n\n=======================================" << endl;
            cout << "         === Struk Belanja ===" << endl;
            cout << "=======================================" << endl;
            totalBelanja = 0.0;
            for (int i = 0; i < jumlahJenisBarang; i++) {
                if (keranjang[i] > 0) {
                    double subTotal = keranjang[i] * harga[i];
                    cout << namaBarang[i] << " x " << keranjang[i] 
                         << " = Rp" << (int)subTotal << endl;
                    totalBelanja += subTotal;
                }
            }
            cout << "---------------------------------------" << endl;
            cout << "Total Belanja = Rp" << (int)totalBelanja << endl;
            cout << "=======================================" << endl;
            cout << "            Terima kasih!" << endl;
            break; // selesai
        }
        else {
            cout << "[!] Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
