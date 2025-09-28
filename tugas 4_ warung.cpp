#include <iostream>
#include <string>
using namespace std;

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
    
    // Variabel untuk history transaksi 2 pelanggan
    string namaPelanggan1 = "";
    string namaPelanggan2 = "";
    double totalPelanggan1 = 0.0;
    double totalPelanggan2 = 0.0;
    int pelangganKe = 1; // counter pelanggan
    string namaPelangganSaatIni = "";

    int pilihan;

    while (true) {
        // Tampilkan daftar barang
        cout << "=====================================================" << endl;
        cout << "        SELAMAT DATANG DI WARUNG PAK MAMAT" << endl;
        cout << "=====================================================" << endl;

        cout << "No. Nama Barang           Harga          Stok" << endl;
        cout << "-----------------------------------------------------" << endl;

        for (int i = 0; i < jumlahJenisBarang; i++) {
            cout << i + 1 << ".  " << namaBarang[i];
            
            // Print spaces untuk alignment
            int spaces = 20 - namaBarang[i].length();
            for (int j = 0; j < spaces; j++) {
                cout << " ";
            }
            
            cout << "Rp" << (int)harga[i];
            
            // Print spaces untuk alignment harga
            string hargaStr = "Rp" + to_string((int)harga[i]);
            int spacesHarga = 15 - hargaStr.length();
            for (int k = 0; k < spacesHarga; k++) {
                cout << " ";
            }
            
            cout << stok[i] << endl;
        }
        cout << "=====================================================" << endl;

        // Tampilkan menu
        cout << "\nMenu: " << endl;
        cout << "1. Tambah barang ke keranjang" << endl;
        cout << "2. Lihat struk sementara" << endl;
        cout << "3. Checkout" << endl;
        cout << "4. Bandingkan Belanja 2 Pelanggan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Input nama pelanggan jika belum ada
            if (namaPelangganSaatIni == "") {
                cout << "Masukkan nama pelanggan: ";
                cin.ignore();
                getline(cin, namaPelangganSaatIni);
            }

            int nomorPilihan, jumlah;
            cout << "Masukkan nomor barang (1-" << jumlahJenisBarang << "): ";
            cin >> nomorPilihan;

            if (nomorPilihan >= 1 && nomorPilihan <= jumlahJenisBarang) {
                int index = nomorPilihan - 1;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;

                if (jumlah > 0 && jumlah <= stok[index]) {
                    keranjang[index] += jumlah;
                    stok[index] -= jumlah;
                    cout << "\n" << jumlah << " " << namaBarang[index]
                         << " ditambahkan ke keranjang." << endl;
                } else if (jumlah <= 0) {
                    cout << "\nJumlah harus lebih dari 0!" << endl;
                } else {
                    cout << "\nStok tidak cukup. Stok tersedia: "
                         << stok[index] << endl;
                }
            } else {
                cout << "\nNomor barang tidak valid!" << endl;
            }
        }
        else if (pilihan == 2) {
            // tampilkan struk sementara
            cout << "\n=== STRUK SEMENTARA ===" << endl;
            if (namaPelangganSaatIni != "") {
                cout << "Pelanggan: " << namaPelangganSaatIni << endl;
                cout << "-----------------------" << endl;
            }
            
            double totalBelanja = 0.0;
            bool adaBarang = false;
            for (int i = 0; i < jumlahJenisBarang; i++) {
                if (keranjang[i] > 0) {
                    double subTotal = keranjang[i] * harga[i];
                    cout << namaBarang[i] << " x " << keranjang[i]
                         << " = Rp" << (int)subTotal << endl;
                    totalBelanja += subTotal;
                    adaBarang = true;
                }
            }
            
            if (adaBarang) {
                cout << "----------------------------" << endl;
                cout << "Total sementara = Rp" << (int)totalBelanja << endl;
            } else {
                cout << "Keranjang kosong!" << endl;
            }
            cout << "=========================" << endl;
        }
        else if (pilihan == 3) {
            // Input nama pelanggan jika belum ada
            if (namaPelangganSaatIni == "") {
                cout << "Masukkan nama pelanggan: ";
                cin.ignore();
                getline(cin, namaPelangganSaatIni);
            }

            // Cek apakah ada barang di keranjang
            bool adaBarang = false;
            double totalBelanja = 0.0;
            for (int i = 0; i < jumlahJenisBarang; i++) {
                if (keranjang[i] > 0) {
                    adaBarang = true;
                    totalBelanja += keranjang[i] * harga[i];
                }
            }

            if (!adaBarang) {
                cout << "\nKeranjang kosong! Tidak ada yang dibeli." << endl;
            } else {
                // checkout: tampilkan struk akhir
                cout << "\n=======================================" << endl;
                cout << "         === STRUK BELANJA ===" << endl;
                cout << "=======================================" << endl;
                cout << "Pelanggan: " << namaPelangganSaatIni << endl;
                cout << "---------------------------------------" << endl;
                
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

                // Simpan data pelanggan untuk perbandingan
                if (pelangganKe == 1) {
                    namaPelanggan1 = namaPelangganSaatIni;
                    totalPelanggan1 = totalBelanja;
                    pelangganKe = 2;
                } else {
                    namaPelanggan2 = namaPelangganSaatIni;
                    totalPelanggan2 = totalBelanja;
                    pelangganKe = 1; // reset untuk pelanggan berikutnya
                }

                // Reset keranjang dan nama pelanggan untuk transaksi berikutnya
                for (int i = 0; i < jumlahJenisBarang; i++) {
                    keranjang[i] = 0;
                }
                namaPelangganSaatIni = "";
            }
        }
        else if (pilihan == 4) {
            // Menu 4: Perbandingan Belanja 2 Pelanggan (menggunakan operator relasi)
            cout << "\n===== PERBANDINGAN BELANJA DUA PELANGGAN =====" << endl;
            cout << "============= WARUNG PAK MAMAT =============" << endl << endl;

            // Cek apakah sudah ada data pelanggan
            if (namaPelanggan1 == "" || namaPelanggan2 == "") {
                cout << "Belum cukup data pelanggan untuk perbandingan!" << endl;
                cout << "Minimal dibutuhkan 2 pelanggan yang sudah checkout." << endl;
                
                if (namaPelanggan1 == "") {
                    cout << "\n=== INPUT DATA PELANGGAN PERTAMA ===" << endl;
                    cout << "Nama pelanggan: ";
                    cin.ignore();
                    getline(cin, namaPelanggan1);
                    cout << "Total belanja: Rp ";
                    cin >> totalPelanggan1;
                }
                
                if (namaPelanggan2 == "") {
                    cout << "\n=== INPUT DATA PELANGGAN KEDUA ===" << endl;
                    cout << "Nama pelanggan: ";
                    cin.ignore();
                    getline(cin, namaPelanggan2);
                    cout << "Total belanja: Rp ";
                    cin >> totalPelanggan2;
                }
            }

            // Tampilkan data kedua pelanggan
            cout << "\n=== DATA PELANGGAN ===" << endl;
            cout << "Pelanggan 1: " << namaPelanggan1 << " - Rp" << (int)totalPelanggan1 << endl;
            cout << "Pelanggan 2: " << namaPelanggan2 << " - Rp" << (int)totalPelanggan2 << endl;
            cout << "========================" << endl;

            // Menggunakan operator relasi untuk perbandingan (sesuai materi PPT)
            cout << "\n=== HASIL PERBANDINGAN (Operator Relasi) ===" << endl;
            
            // Operator == (sama dengan)
            cout << "Apakah belanja sama? ";
            if (totalPelanggan1 == totalPelanggan2) {
                cout << "YA - Belanja " << namaPelanggan1 << " SAMA DENGAN belanja " << namaPelanggan2 << endl;
            } else {
                cout << "TIDAK - Belanja tidak sama" << endl;
            }
            
            // Operator > (lebih besar)
            cout << "Apakah " << namaPelanggan1 << " belanja lebih besar? ";
            if (totalPelanggan1 > totalPelanggan2) {
                cout << "YA - " << namaPelanggan1 << " belanja LEBIH BESAR dari " << namaPelanggan2 << endl;
            } else {
                cout << "TIDAK" << endl;
            }
            
            // Operator < (lebih kecil)
            cout << "Apakah " << namaPelanggan1 << " belanja lebih kecil? ";
            if (totalPelanggan1 < totalPelanggan2) {
                cout << "YA - " << namaPelanggan1 << " belanja LEBIH KECIL dari " << namaPelanggan2 << endl;
            } else {
                cout << "TIDAK" << endl;
            }
            
            // Operator != (tidak sama dengan)
            cout << "Apakah belanja berbeda? ";
            if (totalPelanggan1 != totalPelanggan2) {
                cout << "YA - Belanja " << namaPelanggan1 << " TIDAK SAMA dengan belanja " << namaPelanggan2 << endl;
            } else {
                cout << "TIDAK - Belanja sama" << endl;
            }

            // Hitung selisih
            if (totalPelanggan1 != totalPelanggan2) {
                double selisih;
                if (totalPelanggan1 > totalPelanggan2) {
                    selisih = totalPelanggan1 - totalPelanggan2;
                } else {
                    selisih = totalPelanggan2 - totalPelanggan1;
                }
                cout << "Selisih belanja: Rp" << (int)selisih << endl;
            }

            // Tampilkan siapa yang belanja lebih banyak
            cout << "\n=== KESIMPULAN ===" << endl;
            if (totalPelanggan1 > totalPelanggan2) {
                cout << namaPelanggan1 << " adalah pelanggan dengan belanja terbanyak!" << endl;
            } else if (totalPelanggan2 > totalPelanggan1) {
                cout << namaPelanggan2 << " adalah pelanggan dengan belanja terbanyak!" << endl;
            } else {
                cout << "Kedua pelanggan berbelanja dengan jumlah yang sama!" << endl;
            }
            cout << "=========================================" << endl;
        }
        else if (pilihan == 0) {
            cout << "\nTerima kasih telah menggunakan program Warung Pak Mamat!" << endl;
            cout << "Sampai jumpa lagi!" << endl;
            break; // Keluar dari loop utama
        }
        else {
            cout << "\nPilihan tidak valid! Silakan pilih 0-4." << endl;
        }

        // Pause untuk memberi waktu user membaca output
        cout << "\nTekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
