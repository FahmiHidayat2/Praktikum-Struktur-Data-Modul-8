# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Fahmi Hidayat</p>

## Dasar Teori

### 1. Priority Queue adalah struktur data di mana elemen-elemen memiliki prioritas tertentu, dan elemen dengan prioritas tertinggi dapat diakses atau dihapus terlebih dahulu. Ini adalah abstraksi yang dapat diimplementasikan dengan berbagai cara, seperti menggunakan arrays, linked lists, atau struktur data lainnya. Priority queue tidak mengatur cara elemen-elemen disusun dalam memori. Priority queue banyak digunakan dalam algoritma graf seperti Dijkstra untuk menemukan jalur terpendek untuk menemukan minimum spanning tree [1]. Beberapa cara untuk mengimplementasikan priority queue adalah menggunakan array, linked list, heap, atau binary search tree. untuk materi kali ini kita memakai heap untuk melakukan implementasi pada priority queue.

### 2. Heaps, di sisi lain, adalah salah satu implementasi konkret dari priority queue. Mereka adalah struktur data yang menggunakan representasi pohon biner, yang memiliki properti tertentu: dalam max heap, setiap elemen di bawah (atau sama dengan) induknya memiliki nilai yang lebih kecil daripada induknya, sementara dalam min heap, setiap elemen di bawah (atau sama dengan) induknya memiliki nilai yang lebih besar daripada induknya. Properti ini memastikan bahwa elemen dengan prioritas tertinggi (dalam max heap) atau terendah (dalam min heap) berada di akar pohon, yang memudahkan pengaksesan atau penghapusan elemen dengan prioritas tertinggi. Heaps memberikan implementasi efisien dari priority queue, memungkinkan operasi tambah, hapus, dan akses elemen dengan kompleksitas waktu yang cepat, seperti O(log n) untuk operasi tersebut.

## Guided 

### 1. Guided 1

```C++
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
```
Program tersebut adalah implementasi struktur data heap dalam bahasa C++. Heap diimplementasikan sebagai array, dengan setiap elemen diindeks menggunakan aturan tertentu. Fungsi-fungsi seperti insert, extractMax, changePriority, dan remove digunakan untuk memanipulasi elemen-elemen dalam heap. Fungsi insert digunakan untuk memasukkan elemen baru ke dalam heap dan menjaga properti heap. Fungsi extractMax mengambil elemen dengan prioritas tertinggi dari heap, yaitu elemen pertama, dan memperbarui struktur heap. Fungsi changePriority digunakan untuk mengubah prioritas elemen dalam heap dan memperbaiki struktur heap sesuai dengan perubahan tersebut. Fungsi remove menghapus elemen tertentu dari heap dan memperbaiki struktur heap setelah penghapusan. Program ini menunjukkan contoh penggunaan operasi-operasi heap seperti penambahan, penghapusan, dan perubahan prioritas, serta menampilkan isi heap setiap kali operasi dilakukan.
#### Output:
<img width="464" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-8/assets/161399477/f5fa83a5-8950-4bd2-bfb7-12bc67041318">

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user

```C++
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
```
Program tersebut adalah implementasi struktur data heap dalam bahasa C++ menggunakan vector untuk menyimpan elemen-elemen heap. Fungsi-fungsi seperti insert, extractMax, changePriority, dan remove digunakan untuk memanipulasi elemen-elemen dalam heap. Fungsi-fungsi ini melakukan operasi-operasi standar pada heap seperti penambahan, penghapusan, dan perubahan prioritas, serta menjaga properti heap yang sesuai. Program ini meminta pengguna untuk memasukkan jumlah elemen dan elemen-elemen heap, kemudian melakukan operasi-operasi heap dan menampilkan isi heap setiap kali operasi dilakukan. Program memberikan fleksibilitas dalam mengelola elemen-elemen heap dan memperlihatkan interaksi pengguna dengan struktur data heap yang diimplementasikan.
## Kesimpulan
Dalam praktikum ini, membahas tentang implementasi dan konsep dasar dari struktur data Priority Queue dan Heaps. Melalui dua contoh program C++ yang diberikan, kami belajar bagaimana Priority Queue dan Heaps dapat digunakan untuk mengelola data dengan prioritas tertentu secara efisien. Kami juga memahami bahwa Heaps adalah salah satu implementasi konkret dari Priority Queue, yang menggunakan representasi pohon biner dengan properti tertentu untuk memastikan elemen dengan prioritas tertinggi berada di posisi yang sesuai. Dari hasil praktikum ini, kami dapat menyimpulkan bahwa penggunaan Priority Queue dan Heaps sangat berguna dalam banyak konteks, terutama dalam algoritma-algoritma yang memerlukan pengolahan berdasarkan prioritas seperti algoritma Dijkstra dan algoritma Huffman. Praktikum ini memberikan pemahaman yang baik tentang bagaimana struktur data tersebut dapat diterapkan dalam pemrograman dan komputasi secara umum.
## Referensi
[1] J. Wise, J. Bader, C. Wong, J. Aldrich, É. Tanter, and J. Sunshine, "Gradual verification of recursive heap data structures", Proc. ACM Program. Lang. , vol. 4, no. 228, pp. 1-28, Oct. 2020.
