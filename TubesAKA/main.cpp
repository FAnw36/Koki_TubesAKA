#include <iostream>

using namespace std;

void tampilkanPenjelasanMatriks(int baris, int kolom, string tipe) {
    cout << "\n=== Penjelasan Matriks " << tipe << " ===" << endl;
    if(tipe == "Kemampuan Koki") {
        cout << "Ukuran matriks: " << baris << " x " << kolom << endl;
        cout << "- Baris mewakili: setiap koki yang berbeda" << endl;
        cout << "- Kolom mewakili: setiap jenis bahan yang digunakan" << endl;
        cout << "- Nilai dalam matriks: kemampuan koki dalam mengolah bahan (kg/jam)" << endl;
        cout << "Contoh pembacaan: nilai pada baris 1 kolom 2 adalah kemampuan koki 1 mengolah bahan 2" << endl;
    }
    else if(tipe == "Resep Masakan") {
        cout << "Ukuran matriks: " << baris << " x " << kolom << endl;
        cout << "- Baris mewakili: setiap jenis bahan" << endl;
        cout << "- Kolom mewakili: setiap resep masakan" << endl;
        cout << "- Nilai dalam matriks: jumlah bahan yang dibutuhkan untuk setiap resep (kg)" << endl;
        cout << "Contoh pembacaan: nilai pada baris 1 kolom 2 adalah jumlah bahan 1 yang dibutuhkan untuk resep 2" << endl;
    }
}

void tampilkanMatriks(int matriks[][10], int baris, int kolom, string nama) {
    cout << "\nMatriks " << nama << ":" << endl;
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Menambahkan penjelasan per baris
    if(nama == "Kemampuan Koki") {
        for(int i = 0; i < baris; i++) {
            cout << "Baris " << i+1 << ": Koki " << i+1 << " dapat mengolah ";
            for(int j = 0; j < kolom; j++) {
                cout << "bahan" << j+1 << " " << matriks[i][j] << "kg/jam";
                if(j < kolom-1) cout << ", ";
            }
            cout << endl;
        }
    }
    else if(nama == "Resep Masakan") {
        for(int i = 0; i < baris; i++) {
            cout << "Baris " << i+1 << ": Bahan " << i+1 << " dibutuhkan ";
            for(int j = 0; j < kolom; j++) {
                cout << matriks[i][j] << "kg untuk resep" << j+1;
                if(j < kolom-1) cout << ", ";
            }
            cout << endl;
        }
    }
}

/*
void  inputMatriks(int kemampuanKoki[][10], int resepMasakan[][10], int &bahan, int &koki, int &resep){
    //Input matriks secara manual
    cout << "\nMasukkan jumlah koki: ";
    cin >> koki;
    cout << "Masukkan jumlah resep: ";
    cin >> resep;
    cout << "Masukkan jumlah bahan: ";
    cin >> bahan;

    // Menampilkan penjelasan matriks kemampuan koki
    tampilkanPenjelasanMatriks(koki, bahan, "Kemampuan Koki");

    // Matriks kemampuan koki (koki x bahan)

    cout << "\nMasukkan kemampuan koki mengolah bahan (matriks " << koki << "x" << bahan << ")" << endl;
    cout << "Masukkan nilai untuk:" << endl;

    for(int i = 0; i < koki; i++) {
        cout << "Baris " << i+1 << endl;
        for(int j = 0; j < bahan; j++) {
            cout << "Kolom " << j+1 << ": ";
            cin >> kemampuanKoki[i][j];
        }
    }

    // Menampilkan penjelasan matriks resep masakan
    tampilkanPenjelasanMatriks(bahan, resep, "Resep Masakan");

    // Matriks resep (bahan x resep)

    cout << "\nMasukkan jumlah bahan per resep (matriks " << bahan << "x" << resep << ")" << endl;
    cout << "Masukkan nilai untuk:" << endl;

    for(int i = 0; i < bahan; i++) {
        cout << "Baris " << i+1 << endl;
        for(int j = 0; j < resep; j++) {
            cout << "Kolom " << j+1 << ": ";
            cin >> resepMasakan[i][j];
        }
    }

    // Menampilkan matriks yang akan dihitung
    cout << "\n=== Matriks yang akan dihitung ===" << endl;
    tampilkanMatriks(kemampuanKoki, koki, bahan, "Kemampuan Koki");
    tampilkanMatriks(resepMasakan, bahan, resep, "Resep Masakan");

}*/

void hitungIteratif(int kemampuanKoki[][10], int resepMasakan[][10], int hasil[][10], int koki, int resep, int bahan) {
    // Perhitungan iteratif
    for(int i = 0; i < koki; i++) {
        for(int j = 0; j < resep; j++) {
            for(int k = 0; k < bahan; k++) {
                hasil[i][j] += kemampuanKoki[i][k] * resepMasakan[k][j];
            }
        }
    }
}

void prosesRekursif(int kemampuanKoki[][10], int resepMasakan[][10], int hasil[][10], int i, int j, int k, int koki, int resep, int bahan) {
    if (i >= koki){
        return;
    }
    if (j >= bahan) {
        prosesRekursif(kemampuanKoki, resepMasakan, hasil, i + 1, 0, k, koki, resep, bahan);
        return;
    }else{
        if (k >= resep){
            prosesRekursif(kemampuanKoki, resepMasakan, hasil, i, j + 1, 0, koki, resep, bahan);
            return;
        }else{
            hasil[i][j] += kemampuanKoki[i][k] * resepMasakan[k][j];
            prosesRekursif(kemampuanKoki, resepMasakan, hasil, i, j, k + 1, koki, resep, bahan);
        }
    }
}

void printMatriks(int hasil[][10], int koki, int resep){
    int i, j;
    cout << "\nHasil perhitungan (jumlah masakan yang bisa dibuat):" << endl;
    tampilkanMatriks(hasil, koki, resep, "Hasil");
    cout << endl;
    for(i = 0; i < koki; i++) {
        for(j = 0; j < resep; j++) {
            cout << hasil[i][j] << " ";
        }
        cout << endl;
        // Menambahkan penjelasan hasil per koki
        cout << "Koki " << i+1 << " dapat membuat: ";
        for(int j = 0; j < resep; j++) {
            cout << hasil[i][j] << " porsi resep" << j+1;
            if(j < resep-1) cout << ", ";
        }
        cout << endl;
    }

}

int main() {
    int kemampuanKoki[][10] = {{1,2,3},{4,5,6},{7,8,9}};
    int resepMasakan[][10] = {{1,2,3},{4,5,6},{7,8,9}};
    int hasil1[10][10] = {0};
    int hasil2[10][10] = {0};
    int  koki = 3, resep = 3, bahan = 3, i, j, k;

    //inputMatriks(kemampuanKoki, resepMasakan, bahan, koki, resep); //Input secara manual

    cout << "=========== Iteratif ===========" << endl;
        hitungIteratif(kemampuanKoki, resepMasakan, hasil1, bahan, koki, resep);
        printMatriks(hasil1, koki, resep);
        cout << endl;

    cout << "=========== Rekursif ===========" << endl;
        prosesRekursif(kemampuanKoki, resepMasakan, hasil2, 0, 0, 0, koki, resep, bahan);
        printMatriks(hasil2, koki, resep);
    cout << endl;

    return 0;
}

