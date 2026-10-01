#include <iostream>
#include <string>

using namespace std;

// Struct untuk menyimpan data mahasiswa
struct mahasiswa {
    string nim;
    string nama;
    string kehadiran;
};

// Struct untuk elemen list
struct ElmList {
    mahasiswa info;
    ElmList* next;
};

// Struct untuk List
struct List {
    ElmList* first;
};

// Inisialisasi list kosong
void createList(List &L) {
    L.first = nullptr;
}

// Alokasi elemen baru
ElmList* createNewElement(string nim, string nama, string kehadiran) {
    ElmList* P = new ElmList;
    P->info.nim = nim;
    P->info.nama = nama;
    P->info.kehadiran = kehadiran;
    P->next = nullptr;
    return P;
}

// Menambahkan elemen di posisi awal (Insert First)
void insertFirst(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

// Menambahkan elemen di posisi terakhir (Insert Last)
void insertLast(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        ElmList* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// Mencari elemen berdasarkan NIM
ElmList* searchByNim(List L, string nim) {
    ElmList* P = L.first;
    while (P != nullptr) {
        if (P->info.nim == nim) {
            return P; // Ketemu
        }
        P = P->next;
    }
    return nullptr; // Tidak ketemu
}

// Menghapus elemen berdasarkan NIM tertentu
void deleteByNim(List &L, string nim) {
    ElmList* P = searchByNim(L, nim);
    if (P == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }
    
    if (P == L.first) {
        L.first = P->next;
    } else {
        ElmList* Q = L.first;
        while (Q->next != P) {
            Q = Q->next;
        }
        Q->next = P->next;
    }
    delete P;
    cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
}

// Menampilkan isi list
void printList(List L) {
    if (L.first == nullptr) {
        cout << "List kosong.\n";
        return;
    }
    ElmList* P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << "Data ke-" << i << endl;
        cout << "NIM       : " << P->info.nim << endl;
        cout << "Nama      : " << P->info.nama << endl;
        cout << "Kehadiran : " << P->info.kehadiran << endl;
        cout << "-------------------------" << endl;
        P = P->next;
        i++;
    }
}

int main() {
    List L;
    createList(L);

    string nim, nama, kehadiran;

    cout << "Silakan masukkan data 40 mahasiswa (Format: NIM NAMA KEHADIRAN):\n";
    // Input 40 data sesuai permintaan
    for (int i = 0; i < 40; i++) {
        cin >> nim >> nama >> kehadiran;
        ElmList* P = createNewElement(nim, nama, kehadiran);
        insertLast(L, P);
    }

    cout << "\n--- ISI LIST 40 MAHASISWA ---" << endl;
    printList(L);

    // Contoh Uji Coba Fitur Tambahan (Insert & Delete)
    cout << "\n--- CONTOH UJI COBA FITUR TAMBAHAN ---" << endl;
    
    // Contoh Insert First tambahan
    cout << "Menambahkan 1 mahasiswa baru di awal (Insert First)...\n";
    insertFirst(L, createNewElement("9999", "Tester", "Hadir"));
    
    // Contoh Delete berdasarkan NIM
    cout << "Masukkan NIM mahasiswa yang ingin dihapus (contoh dari inputan Anda): ";
    string targetNim;
    cin >> targetNim;
    deleteByNim(L, targetNim);

    cout << "\n--- ISI LIST SETELAH MODIFIKASI ---" << endl;
    printList(L);

    return 0;
}
