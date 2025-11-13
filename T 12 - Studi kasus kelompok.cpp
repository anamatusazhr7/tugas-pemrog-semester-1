#include <iostream>
using namespace std;

// Struct untuk barang
struct Barang
{
	string nama;
	int harga;
};

// Fungsi menghitung total harga
int hitungTotal(int harga, int jumlah)
{
	return harga * jumlah;
}

int main()
{
	Barang daftar[6] = {{"Ayam Geprek", 8000}, {"Teh Manis", 4000}, {"Nasi", 3000},
		{"Tahu pedas", 1500}, {"Cireng", 2500}, {"Mie Ayam", 10000}
	};
	int totalKeseluruhan = 0;
	int totalBayar = 0;
	int totalDiskon = 0;
	char lanjut;
	int pilih, jumlah;

	cout << "===================" << endl;
	cout << "    Warung Anton   " << endl;
	cout << "===================" << endl;
	do
	{
		// Tampilkan menu
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ". " << daftar[i].nama << " - Rp." << daftar[i].harga << endl;
		}
		cout << "-------------------" << endl;
		cout << "Pilih menu (1-6): ";
		cin >> pilih;
		cout << "Jumlah: ";
		cin >> jumlah;

		int total = hitungTotal(daftar[pilih - 1].harga, jumlah);
		totalBayar += total;

		cout << "Total " << daftar[pilih - 1].nama << " = Rp." << total << endl;

		cout << "Pesan lagi? (y/n): ";
		cin >> lanjut;
		cout << "==================" << endl;

	} while (lanjut == 'y' || lanjut == 'Y');

	// diskon
	totalDiskon = 0;

	if (totalBayar < 20000) {
        totalDiskon = totalBayar * 0.10;
    } else if (totalBayar == 35000) {
        totalDiskon = totalBayar * 0.25;
    } else if (totalBayar > 50000) {
        totalDiskon = totalBayar * 0.35;
    } else {
        totalDiskon = 0;
    }

	totalKeseluruhan = totalBayar - totalDiskon;

	// Message
     if (totalKeseluruhan <= 25000) {
        cout << "Terimakasih bang" << endl;
    } else if (totalKeseluruhan >= 50000) {
        cout << "Terimakasih banget bang" << endl;
    }

	cout << "\nTotal keseluruhan: Rp." << totalKeseluruhan << endl;
	return 0;
}
