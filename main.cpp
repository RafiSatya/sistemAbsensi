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
    string kode, nama, namaDosen, npmDosen;
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

bool sesiAktif = false;
string sesiKode = "";
string sesiTanggal = "";

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
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 0f27a5188ac1e078c9af939e00b2bce08e122e3b
>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
void registrasiMahasiswa() {
    if (jumlahUser >= 51) {
        cout << "Kapasitas pengguna penuh!\n";
        return;
    }

    User baru;
    baru.role = "Mahasiswa";

    cin.ignore();

    cout << "\n===== REGISTRASI MAHASISWA =====\n";
    cout << "Nama     : ";
    getline(cin, baru.nama);

    cout << "NPM      : ";
    getline(cin, baru.npm);

    cout << "Kelas    : ";
    getline(cin, baru.kelas);

    cout << "Username : ";
    getline(cin, baru.username);

    cout << "Password : ";
    getline(cin, baru.password);

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].npm == baru.npm ||
            users[i].username == baru.username) {
            cout << "NPM atau username sudah digunakan!\n";
            return;
        }
    }

    ofstream file("users.txt", ios::app);

    if (!file.is_open()) {
        cout << "Gagal menyimpan data!\n";
        return;
    }

    file << baru.role << "|" << baru.username << "|"
         << baru.password << "|" << baru.nama << "|"
         << baru.npm << "|" << baru.kelas << endl;

    file.close();

    users[jumlahUser++] = baru;

    cout << "\nRegistrasi berhasil!\n";
}

// Menampilkan daftar mahasiswa
void daftarMahasiswa() {
    cout << "\n===== DAFTAR MAHASISWA =====\n";

    int nomor = 1;

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].role == "Mahasiswa") {
            cout << nomor++ << ". "
                 << users[i].nama << " | "
                 << users[i].npm << " | "
                 << users[i].kelas << endl;
        }
    }

    if (nomor == 1)
        cout << "Belum ada mahasiswa terdaftar.\n";
}

 // Menambahkan mata kuliah milik dosen yang sedang login
void tambahMataKuliah(int index) {
    if (jumlahCourse >= 20) {
        cout << "Kapasitas mata kuliah penuh!\n";
        return;
    }

    // Akun dosen bawaan belum memiliki NPM, jadi lengkapi saat pertama digunakan.
    if (users[index].npm.empty()) {
        cout << "Nama dosen: ";
        cin.ignore();
        getline(cin, users[index].nama);
        cout << "NPM dosen: ";
        getline(cin, users[index].npm);

        ofstream update("users.txt");
        for (int i = 0; i < jumlahUser; i++) {
            update << users[i].role << "|" << users[i].username << "|"
                   << users[i].password << "|" << users[i].nama << "|"
                   << users[i].npm << "|" << users[i].kelas << "\n";
        }
        update.close();
    }

    Course baru;
    cout << "\n===== TAMBAH MATA KULIAH =====\n";
    cout << "Kode mata kuliah: ";
    cin >> baru.kode;

    for (int i = 0; i < jumlahCourse; i++) {
        if (courses[i].kode == baru.kode) {
            cout << "Kode mata kuliah sudah digunakan!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Nama mata kuliah: ";
    getline(cin, baru.nama);

    baru.namaDosen = users[index].nama;
    baru.npmDosen = users[index].npm;

    ofstream file("courses.txt", ios::app);
    if (!file.is_open()) {
        cout << "Gagal menyimpan mata kuliah!\n";
        return;
    }

    file << baru.kode << "|" << baru.nama << "|"
         << baru.namaDosen << "|" << baru.npmDosen << "\n";
    file.close();

    courses[jumlahCourse++] = baru;
    cout << "Mata kuliah berhasil ditambahkan!\n";
}

// Menampilkan seluruh mata kuliah beserta dosen pengampu
void daftarMataKuliah() {
    cout << "\n===== DAFTAR MATA KULIAH =====\n";
    if (jumlahCourse == 0) {
        cout << "Belum ada mata kuliah.\n";
        return;
    }

    for (int i = 0; i < jumlahCourse; i++) {
        cout << "\n" << i + 1 << ". " << courses[i].kode
             << " - " << courses[i].nama
             << "\nDosen     : " << courses[i].namaDosen
             << "\nNPM Dosen : " << courses[i].npmDosen << "\n";
    }
}
<<<<<<< HEAD
// Memeriksa apakah mahasiswa sudah absen
// Memuat data mata kuliah
void muatCourse() {
    ifstream file("courses.txt");
    string baris;

    while (getline(file, baris) && jumlahCourse < 20) {
        size_t p = baris.find('|');

        if (p == string::npos)
            continue;

        courses[jumlahCourse].kode = baris.substr(0, p);
        courses[jumlahCourse].nama = baris.substr(p + 1);

        jumlahCourse++;
    }

    file.close();
}

// Menyimpan seluruh data absensi
void simpanAttendance() {
    ofstream file("attendance.txt");

    for (int i = 0; i < jumlahAttendance; i++) {
        file << attendance[i].npm << "|"
             << attendance[i].kode << "|"
             << attendance[i].status << "|"
             << attendance[i].tanggal << endl;
    }

    file.close();
}

// Memuat data absensi
void muatAttendance() {
    ifstream file("attendance.txt");
    string baris;

    while (getline(file, baris) && jumlahAttendance < 1000) {
        size_t p1 = baris.find('|');
        size_t p2 = baris.find('|', p1 + 1);
        size_t p3 = baris.find('|', p2 + 1);

        if (p1 == string::npos ||
            p2 == string::npos ||
            p3 == string::npos)
            continue;

        Attendance a;

        a.npm = baris.substr(0, p1);
        a.kode = baris.substr(p1 + 1, p2 - p1 - 1);
        a.status = baris.substr(p2 + 1, p3 - p2 - 1);
        a.tanggal = baris.substr(p3 + 1);

        attendance[jumlahAttendance++] = a;
    }

    file.close();
}

=======

// Memuat mata kuliah beserta identitas dosen pengampu
void muatCourse() {
    ifstream file("courses.txt");
    string baris;

    while (getline(file, baris) && jumlahCourse < 20) {
        size_t p1 = baris.find('|');
        size_t p2 = (p1 == string::npos) ? string::npos : baris.find('|', p1 + 1);
        size_t p3 = (p2 == string::npos) ? string::npos : baris.find('|', p2 + 1);

        // Format baru: kode|nama|namaDosen|npmDosen
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
            continue;

        Course c;
        c.kode = baris.substr(0, p1);
        c.nama = baris.substr(p1 + 1, p2 - p1 - 1);
        c.namaDosen = baris.substr(p2 + 1, p3 - p2 - 1);
        c.npmDosen = baris.substr(p3 + 1);
        courses[jumlahCourse++] = c;
    }
    file.close();
}

// Menyimpan seluruh data absensi
void simpanAttendance() {
    ofstream file("attendance.txt");

    for (int i = 0; i < jumlahAttendance; i++) {
        file << attendance[i].npm << "|"
             << attendance[i].kode << "|"
             << attendance[i].status << "|"
             << attendance[i].tanggal << endl;
    }

    file.close();
}

// Memuat data absensi
void muatAttendance() {
    ifstream file("attendance.txt");
    string baris;

    while (getline(file, baris) && jumlahAttendance < 1000) {
        size_t p1 = baris.find('|');
        size_t p2 = baris.find('|', p1 + 1);
        size_t p3 = baris.find('|', p2 + 1);

        if (p1 == string::npos ||
            p2 == string::npos ||
            p3 == string::npos)
            continue;

        Attendance a;

        a.npm = baris.substr(0, p1);
        a.kode = baris.substr(p1 + 1, p2 - p1 - 1);
        a.status = baris.substr(p2 + 1, p3 - p2 - 1);
        a.tanggal = baris.substr(p3 + 1);

        attendance[jumlahAttendance++] = a;
    }

    file.close();
}

// Memeriksa apakah mahasiswa sudah absen
>>>>>>> 0f27a5188ac1e078c9af939e00b2bce08e122e3b
bool sudahAbsen(string npm) {
    for (int i = 0; i < jumlahAttendance; i++) {
        if (attendance[i].npm == npm &&
            attendance[i].kode == sesiKode &&
            attendance[i].tanggal == sesiTanggal) {
            return true;
        }
    }

    return false;
}

// Membuka sesi hanya untuk mata kuliah milik dosen yang login
void bukaSesi(int index) {
    if (sesiAktif) {
        cout << "Sesi absensi masih aktif!\n";
        return;
    }
    if (jumlahCourse == 0) {
        cout << "Belum ada mata kuliah!\n";
        return;
    }

    daftarMataKuliah();
    string kode;
    cout << "Kode mata kuliah: ";
    cin >> kode;

    int posisi = -1;
    for (int i = 0; i < jumlahCourse; i++) {
        if (courses[i].kode == kode) {
            posisi = i;
            break;
        }
    }

    if (posisi == -1) {
        cout << "Mata kuliah tidak ditemukan!\n";
        return;
    }
    if (courses[posisi].npmDosen != users[index].npm) {
        cout << "Anda bukan dosen pengampu mata kuliah ini!\n";
        return;
    }

    sesiKode = kode;
    cout << "Tanggal (DD-MM-YYYY): ";
    cin >> sesiTanggal;
    sesiAktif = true;
    cout << "Sesi absensi berhasil dibuka!\n";
}

// Menutup sesi absensi
void tutupSesi(int index) {
    if (!sesiAktif) {
        cout << "Tidak ada sesi yang aktif!\n";
        return;
    }

    bool pemilik = false;
    for (int i = 0; i < jumlahCourse; i++) {
        if (courses[i].kode == sesiKode &&
            courses[i].npmDosen == users[index].npm)
            pemilik = true;
    }
    if (!pemilik) {
        cout << "Hanya dosen pengampu yang dapat menutup sesi ini!\n";
        return;
    }

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].role == "Mahasiswa" &&
            !sudahAbsen(users[i].npm) &&
            jumlahAttendance < 1000) {

            Attendance baru;
            baru.npm = users[i].npm;
            baru.kode = sesiKode;
            baru.tanggal = sesiTanggal;
            baru.status = "Alpha";

            attendance[jumlahAttendance++] = baru;
        }
    }

<<<<<<< HEAD
    simpanAttendance();

=======
<<<<<<< HEAD
    simpanAttendance();

=======
>>>>>>> 0f27a5188ac1e078c9af939e00b2bce08e122e3b
>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
    sesiAktif = false;

    cout << "Sesi ditutup. Mahasiswa yang belum absen tercatat Alpha.\n";
}

// Pengisian kehadiran mahasiswa
void isiKehadiran(int index) {
    if (!sesiAktif) {
        cout << "Belum ada sesi absensi yang dibuka!\n";
        return;
    }

    if (sudahAbsen(users[index].npm)) {
        cout << "Kamu sudah mengisi absensi!\n";
        return;
    }

    if (jumlahAttendance >= 1000) {
        cout << "Data absensi penuh!\n";
        return;
    }

    int pilih;

    cout << "\n===== ABSENSI MAHASISWA =====\n";
    cout << "1. Hadir\n";
    cout << "2. Izin\n";
    cout << "3. Sakit\n";
    cout << "Pilih status: ";
    cin >> pilih;

    Attendance baru;
    baru.npm = users[index].npm;
    baru.kode = sesiKode;
    baru.tanggal = sesiTanggal;

    switch (pilih) {
        case 1:
            baru.status = "Hadir";
            break;
        case 2:
            baru.status = "Izin";
            break;
        case 3:
            baru.status = "Sakit";
            break;
        default:
            cout << "Pilihan tidak tersedia!\n";
            return;
    }

    attendance[jumlahAttendance++] = baru;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
    simpanAttendance();

    cout << "Absensi berhasil disimpan!\n";
}

<<<<<<< HEAD
// Rekap hanya menampilkan mata kuliah milik dosen yang login
void rekapAbsensi(int index) {
    cout << "\n===== REKAP ABSENSI =====\n";
    bool ada = false;

    for (int i = 0; i < jumlahAttendance; i++) {
        bool milikDosen = false;
        for (int j = 0; j < jumlahCourse; j++) {
            if (courses[j].kode == attendance[i].kode &&
                courses[j].npmDosen == users[index].npm)
                milikDosen = true;
        }
        if (!milikDosen) continue;

        ada = true;
        string nama = "Tidak ditemukan";
=======
// Rekapitulasi absensi mahasiswa
void rekapAbsensi() {
    cout << "\n===== REKAP ABSENSI =====\n";

    if (jumlahAttendance == 0) {
        cout << "Belum ada data absensi.\n";
        return;
    }

    for (int i = 0; i < jumlahAttendance; i++) {
        string nama = "Tidak ditemukan";

>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
        for (int j = 0; j < jumlahUser; j++) {
            if (users[j].npm == attendance[i].npm) {
                nama = users[j].nama;
                break;
            }
        }

<<<<<<< HEAD
        cout << "\nNama    : " << nama
             << "\nNPM     : " << attendance[i].npm
             << "\nKode MK : " << attendance[i].kode
             << "\nTanggal : " << attendance[i].tanggal
             << "\nStatus  : " << attendance[i].status
             << "\n-------------------------\n";
    }

    if (!ada) cout << "Belum ada rekap untuk mata kuliah Anda.\n";
}

=======
        cout << "\nNama    : " << nama << endl;
        cout << "NPM     : " << attendance[i].npm << endl;
        cout << "Kode MK : " << attendance[i].kode << endl;
        cout << "Tanggal : " << attendance[i].tanggal << endl;
        cout << "Status  : " << attendance[i].status << endl;
        cout << "-------------------------\n";
    }
}

=======
    cout << "Absensi berhasil disimpan!\n";
}

>>>>>>> 0f27a5188ac1e078c9af939e00b2bce08e122e3b
>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
void menuDosen(int index) {
    int pilih;

    do {
        cout << "\n===== MENU DOSEN =====\n";
        cout << "1. Daftar Mahasiswa\n";
        cout << "2. Tambah Mata Kuliah\n";
        cout << "3. Daftar Mata Kuliah\n";
        cout << "4. Buka Sesi Absensi\n";
        cout << "5. Tutup Sesi Absensi\n";
<<<<<<< HEAD
        cout << "6. Rekap Absensi\n";
=======
<<<<<<< HEAD
        cout << "6. Rekap Absensi\n";
=======
>>>>>>> 0f27a5188ac1e078c9af939e00b2bce08e122e3b
>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: daftarMahasiswa(); break;
            case 2: tambahMataKuliah(index); break;
            case 3: daftarMataKuliah(); break;
<<<<<<< HEAD
            case 4: bukaSesi(index); break;
            case 5: tutupSesi(index); break;
            case 6: rekapAbsensi(index); break;
=======
            case 4: bukaSesi(); break;
            case 5: tutupSesi(); break;
<<<<<<< HEAD
            case 6: rekapAbsensi(); break;
=======
>>>>>>> 0f27a5188ac1e078c9af939e00b2bce08e122e3b
>>>>>>> e829e3cfb59278650badceef93572786d40e78c7
            case 0: cout << "Logout berhasil!\n"; break;
            default: cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilih != 0);
}

// Menu mahasiswa
void menuMahasiswa(int index) {
    int pilih;

    do {
        cout << "\n===== MENU MAHASISWA =====\n";
        cout << "1. Lihat Mata Kuliah\n";
        cout << "2. Isi Absensi\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                daftarMataKuliah();
                break;
            case 2:
                isiKehadiran(index);
                break;
            case 0:
                cout << "Logout berhasil!\n";
                break;
            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilih != 0);
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

    // Memuat data mata kuliah dan absensi
    muatCourse();
    muatAttendance();

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
            registrasiMahasiswa();
        }
        else if (pilih != 0) {
            cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilih != 0);

    cout << "\nTerima kasih telah menggunakan aplikasi.\n";
    return 0;
}