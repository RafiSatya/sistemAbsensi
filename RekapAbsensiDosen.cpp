#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    string nama[n];
    char status[n];

    for (int i = 0; i < n; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];
        cout << "Status (H/I/S/A): ";
        cin >> status[i];
    }

   //output
    cout << "\n--- REKAP ABSENSI ---\n";
    int hadir = 0;
    
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << nama[i] << " - " << status[i] << endl;
        if (status[i] == 'H' || status[i] == 'h') {
            hadir++;
        }
    }

    cout << "\nTotal yang Hadir: " << hadir << " dari " << n << " mahasiswa." << endl;

    return 0;
}
