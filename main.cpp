#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struktur data pengguna
struct User {
    string role, username, password;
    string nama, npm, kelas;
};

// Struktur data mata kuliah
struct Course {
    string kode, nama;
};

// Struktur data absensi
struct Attendance {
    string npm, kode, status, tanggal;
};

// Array penyimpanan
User users[51];
Course courses[20];
Attendance attendance[1000];

int jumlahUser = 0;
int jumlahCourse = 0;
int jumlahAttendance = 0;

// Login pengguna
int login() {
    string username, password;

    cout << "\n===== LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].username == username &&
            users[i].password == password) {
            return i;
        }
    }

    return -1;
}

// Menu dosen
void menuDosen(int index) {
    cout << "\nSelamat datang, "
         << users[index].nama << "!\n";
    cout << "Menu dosen belum tersedia.\n";
}

// Menu mahasiswa
void menuMahasiswa(int index) {
    cout << "\nSelamat datang, "
         << users[index].nama << "!\n";
    cout << "Menu mahasiswa belum tersedia.\n";
}

// Program utama
int main() {
    int pilih, index;

    // Membuat akun dosen awal jika file belum tersedia
    ifstream cek("users.txt");

    if (!cek.good()) {
        ofstream buat("users.txt");
        buat << "Dosen|dosen|dosen123|Dosen Pengampu||\n";
        buat.close();
    }

    cek.close();

    // Memuat data akun
    ifstream file("users.txt");
    string baris;

    while (getline(file, baris) && jumlahUser < 51) {
        User u;
        int p[5], awal = 0;

        for (int i = 0; i < 5; i++) {
            p[i] = baris.find('|', awal);
            awal = p[i] + 1;
        }

        if (p[4] < 0) continue;

        u.role = baris.substr(0, p[0]);
        u.username = baris.substr(p[0] + 1, p[1] - p[0] - 1);
        u.password = baris.substr(p[1] + 1, p[2] - p[1] - 1);
        u.nama = baris.substr(p[2] + 1, p[3] - p[2] - 1);
        u.npm = baris.substr(p[3] + 1, p[4] - p[3] - 1);
        u.kelas = baris.substr(p[4] + 1);

        users[jumlahUser++] = u;
    }

    file.close();

    do {
        cout << "\n===== APLIKASI ABSENSI =====\n";
        cout << "1. Login\n";
        cout << "2. Registrasi Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            index = login();

            if (index == -1) {
                cout << "Username atau password salah!\n";
            }
            else if (users[index].role == "Dosen") {
                menuDosen(index);
            }
            else {
                menuMahasiswa(index);
            }
        }
        else if (pilih == 2) {
            cout << "Fitur registrasi akan ditambahkan Mitha.\n";
        }
        else if (pilih != 0) {
            cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilih != 0);

    cout << "\nTerima kasih telah menggunakan aplikasi.\n";
    return 0;
}