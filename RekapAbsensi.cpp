void rekapAbsensi() {
    cout << "\n===== REKAP ABSENSI =====\n";

    if (jumlahAttendance == 0) {
        cout << "Belum ada data absensi.\n";
        return;
    }

    for (int i = 0; i < jumlahAttendance; i++) {
        string nama = "Tidak ditemukan";

        for (int j = 0; j < jumlahUser; j++) {
            if (users[j].npm == attendance[i].npm) {
                nama = users[j].nama;
                break;
            }
        }

        cout << "\nNama    : " << nama << endl;
        cout << "NPM     : " << attendance[i].npm << endl;
        cout << "Kode MK : " << attendance[i].kode << endl;
        cout << "Tanggal : " << attendance[i].tanggal << endl;
        cout << "Status  : " << attendance[i].status << endl;
        cout << "-------------------------\n";
    }
}
