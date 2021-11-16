#include "help.h"

void help() {
    printf("1. MOVE\nCommand ini digunakan untuk berpindah ke lokasi selanjutnya dari lokasi pemain berada. Pemain hanya bisa pindah ke lokasi yang berdekatan berdasarkan matriks adjacency. Setelah berpindah lokasi, waktu akan bertambah 1 unit (dalam kondisi normal).\n\n");
    printf("2. PICK_UP\nCommand ini digunakan untuk mengambil item jika ada pesanan pada lokasi pemain berada. Pemain tidak bisa mengambil item jika tidak ada pesanan pada lokasi pemain berada. Jika ada beberapa pesanan di lokasi pemain berada, maka item yang diambil adalah pesanan yang masuk duluan.\n\n");
    printf("3. DROP_OFF\nCommand ini digunakan untuk mengantarkan item ke lokasi pemain berada jika item di tumpukan teratas tas sesuai dengan pesanan pada lokasi tersebut. Pemain tidak dapat mengantarkan item ke lokasi yang tidak sesuai dengan pesanan.\n\n");
    printf("4. MAP\nCommand ini digunakan untuk memunculkan peta.\n");
    printf(" * Karakter '8' menunjukkan Headquarters tempat Mobita (pemain) memulai/mengakhiri tugasnya, dan membeli gadget.\n * Karakter berwarna kuning menunjukkan posisi Mobita (pemain).\n * Karakter berwarna merah menunjukkan lokasi pick up pesanan.\n * Karakter berwarna biru menunjukkan lokasi drop off item teratas pada tas.\n * Karakter berwarna hijau menunjukkan lokasi atau destinasi yang dapat dicapai oleh Mobita (pemain) (sesuai matriks adjacency).\n * Karakter berwarna hitam adalah lokasi yang tidak masuk kategori lokasi-lokasi di atas (netral).\n\nJika ada lokasi yang memenuhi kategori teratas secara bersamaan, prioritas pewarnaan adalah:\nLokasi Mobita > Lokasi Drop Off > Lokasi Pick Up > Lokasi Destinasi > Lokasi Netral.\n\n");
    printf("5. TO_DO\nCommand ini digunakan untuk menampilkan pesanan yang masuk ke To Do List. Pesanan ditampilkan secara berurutan sesuai dengan pesanan yang masuk duluan.\n\n");
    printf("6. IN_PROGRESS\nCommand ini digunakan untuk menampilkan pesanan yang sedang dikerjakan. Pesanan ditampilkan secara berurutan sesuai dengan pesanan yang terakhir masuk.\n\n");
    printf("7. BUY\nCommand ini hanya dapat dipanggil di Headquarters. Command ini digunakan untuk menampilkan gadget yang dapat dibeli lalu membelinya. Setelah gadget ditampilkan maka pemain dapat melakukan input untuk membeli gadget yang diinginkan. Pemain hanya dapat membeli gadget jika inventori gadget pemain tidak penuh dan pemain memiliki uang yang cukup\n\n");
    printf("8. INVENTORY\nCommand ini digunakan untuk menampilkan isi inventory (berisi gadget pemain). Setelah gadget ditampilkan, pemain dapat melakukan input untuk menggunakan gadget yang diinginkan. Pemain tidak dapat menggunakan gadget apabila gadget tersebut tidak terdapat di inventory. Inventory dapat menampung maksimal 5 gadget.\n\n");
    printf("9. HELP\nCommand ini digunakan untuk menampilkan seluruh command yang dapat digunakan beserta deskripsinya. \n\n");
}