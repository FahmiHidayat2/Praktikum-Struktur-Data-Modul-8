#include <iostream>
#include <algorithm>
#include <vector>

// Mendeklarasikan vector untuk menyimpan elemen heap
std::vector<int> H;
// Mendeklarasikan variabel untuk menyimpan ukuran heap saat ini
int heapSize = -1;

// Fungsi untuk mendapatkan indeks parent dari node saat ini
int parent(int i) {
    return (i - 1) / 2;
}

// Fungsi untuk mendapatkan indeks anak kiri dari node saat ini
int leftChild(int i) {
    return (2 * i) + 1;
}

// Fungsi untuk mendapatkan indeks anak kanan dari node saat ini
int rightChild(int i) {
    return (2 * i) + 2;
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
    if (static_cast<size_t>(heapSize + 1) >= H.size()) {
        H.push_back(p); // Memastikan ada ruang di vector sebelum menambahkan elemen
    } else {
        H[heapSize + 1] = p;
    }
    heapSize++;
    shiftUp(heapSize);
}

// Fungsi untuk mengambil elemen maksimum dari heap dan memperbaiki struktur heap
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize--;
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
    int numElements, element;
    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> numElements;
    std::cout << "Masukkan elemen-elemen heap: ";
    for (int i = 0; i < numElements; ++i) {
        std::cin >> element;
        insert(element);
    }

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority: " << extractMax() << "\n";
    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int indexToChange, newPriority;
    std::cout << "Enter index to change priority and new priority: ";
    std::cin >> indexToChange >> newPriority;
    changePriority(indexToChange, newPriority);
    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int indexToRemove;
    std::cout << "Enter index to remove: ";
    std::cin >> indexToRemove;
    remove(indexToRemove);
    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
