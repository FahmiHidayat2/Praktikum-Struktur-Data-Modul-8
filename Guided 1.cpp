#include <iostream>
#include <algorithm>

int H[50]; // Array untuk menyimpan elemen heap
int heapSize =-1; // Ukuran heap saat ini

// Fungsi untuk mendapatkan indeks parent dari node saat ini
int parent(int i) {
        return (i-1) / 2;
}

// Fungsi untuk mendapatkan indeks anak kiri dari node saat ini
int leftChild(int i) {
        return ((2 * i) + 1);
}

// Fungsi untuk mendapatkan indeks anak kanan dari node saat ini
int rightChild(int i) {
        return ((2 * i) + 2);
}

// Fungsi untuk memperbaiki posisi node ke atas heap jika diperlukan
void shiftUp(int i) {
        while (i > 0 && H[parent(i)] < H[i]) {
            std::swap(H[parent(i)], H[i]);
            i = parent(i);
        }
}

// Fungsi untuk memperbaiki posisi node ke bawah heap jika diperlukan
void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Fungsi untuk memasukkan elemen baru ke dalam heap
void insert(int p) {
        heapSize = heapSize + 1;
        H[heapSize] = p;
        shiftUp(heapSize);
}

// Fungsi untuk mengambil elemen maksimum dari heap dan memperbaiki struktur heap
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// Fungsi untuk mengubah prioritas elemen di heap dan memperbaiki struktur heap
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// Fungsi untuk mendapatkan elemen maksimum dari heap tanpa menghapusnya
int getMax() {
    return H[0];
}

// Fungsi untuk menghapus elemen dari heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

// Fungsi utama untuk menjalankan operasi heap
int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
