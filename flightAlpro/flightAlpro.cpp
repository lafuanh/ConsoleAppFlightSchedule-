//
//  main.cpp
//  algoproTeam
//
//  Created by naufal adyatma on 06/11/23.
//
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// DATA MASKAPAI
std::string dataMaskapai[][2] = {
    {"Aviastar Mandiri", "MV"},
    {"Airfast Indonesia", "FS"},
    {"Air Asia Indonesia", "QZ"},
    {"Batik Air", "ID"},
    {"Citilink", "QG"},
    {"Xpress Air", "XN"},
    {"Garuda Indonesia", "GA"},
    {"Kal Star Aviation", "KD"},
    {"Lion Air", "JT"},
    {"Sriwijaya Air", "SJ"},
    {"Susi Air", "SI"},
    {"Trans Nusa", "8b"},
    {"Trigana Air", "TN"},
    {"Wings Air", "IW"}
};
int jumlahMaskapai = sizeof(dataMaskapai) / sizeof(dataMaskapai[0]);

struct Pesawat {
    int idPesawat;
    string idMaskapai;
    int tipePesawat; //1 large: 240, 2 medium: 140,3 small: 80 -- 25% are bussnies 50% are economy 10% are first class, 15% are quite zone
};

struct kursi
{
    string jenis;
    int harga;
};

std::string Bandara[][2] = {
    {"Bandara Soekarno-Hatta", "CGK"},
    {"Bandara Ngurah Rai", "DPS"},
    {"Bandara Juanda", "SUB"},
    {"Bandara Sultan Hasanuddin", "UPG"},
    {"Bandara Kuala Namu", "KNO"},
    {"Bandara Adi Soemarmo", "SOC"},
    {"Bandara Minangkabau", "PDG"},
    {"Bandara Adisutjipto", "JOG"},
    {"Bandara Kualanamu", "KNO"},
    {"Bandara Sam Ratulangi", "MDC"}
};
int JumlahBandara = sizeof(Bandara) / sizeof(Bandara[0]);

struct Penerbangan
{
    int nomorPesawat;
    int tanggalPenerbangan;
    string status;
    string id_BandaraTujuan;
    string id_BandaraSekarang;
};

struct dataDiri
{
    string nama;
    int usia;
    string nomorhp;
    void display() {


    }
};

struct Tiket
{
    int idTicket;
    int idPesawat;
    int tanggalBerangkat; // time clock __ day / month / year
    string id_bandaraSaatIni;
    string id_tujuanBerangkat;
    int gate; //random pintu masuk
    //data diri

    void display(){
    //airticket
    //passanger
    // 
    // idCurrent airport to next airport
    // 
    //date depature
    //
    
    }
};

//------------------------------//
std::vector<Pesawat> dataPesawat;

Pesawat createPesawat(int nomorPesawat, string id_maskapai, int tipe) {
    Pesawat pesawat_new;
    pesawat_new.idPesawat= nomorPesawat;
    pesawat_new.idMaskapai = id_maskapai;
    pesawat_new.tipePesawat = tipe;
    return pesawat_new;
}



void generatePesawat() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < JumlahBandara * 25; i++) {
        int randomNumberPesawat = std::rand() % 900 + 100;
        int randomNumberBandara = std::rand() % 14;
        int randomNumberTipe = std::rand() % 3 + 1;
        dataPesawat.push_back(createPesawat(randomNumberPesawat, dataMaskapai[randomNumberBandara][1], randomNumberTipe));
    }
}

void startAplication() {
    generatePesawat();
    //generate penerbangan -- set every day had to be 3 plane each airport to random airport
}













int main() {
    startAplication();

    string menu_app[6] = {
        "1. Admin",
        "2. Airport Board",
        "3. Costumer",
        "4. Exit"
    };

    string makanan[30], minuman[30];
    float harga_makanan[30], harga_minuman[30];
    int pesanan_makanan[30], pesanan_minuman[30];
    int n_makanan = 3;
    int n_minuman = 3;


    int n_pesan_makanan = 0;
    int n_pesan_minuman = 0;


    //makanan
    makanan[0] = "Sop Buntut";
    makanan[1] = "Nasi Goreng";
    makanan[2] = "Bebek Bakar";

    //minuman
    minuman[0] = "Stroawberry Squash";
    minuman[1] = "Orange Juice";
    minuman[2] = "Lemon Tea";

    //harga makanan
    harga_makanan[0] = 45000;
    harga_makanan[1] = 20000;
    harga_makanan[2] = 40000;

    //harga minuman
    harga_minuman[0] = 7000;
    harga_minuman[1] = 15000;
    harga_minuman[2] = 7000;

   
 
    bool isDone = true;
    int harga = 0;
    std::string tambahanMenu = "";


    bool is_lanjut = true;
    int i, pilih;
    float total_pesanan;
    int inputcode;


    while (is_lanjut) {
        for (i = 0;i < 6;i++) {
            cout << menu_app[i] << endl;
        }
        cout << "Pilih Menu: ";
        cin >> pilih;


        switch (pilih) {
        case 1:
            cout << "-----------------------\n";
            for (i = 0;i < n_makanan;i++) {
                cout << makanan[i] << " (kode: " << i << ")\n";
            }
            cout << "-----------------------\n";
            cout << "Input kode: ";
            cin >> pesanan_makanan[n_pesan_makanan];
            n_pesan_makanan++;
            break;
        case 2:
            cout << "-----------------------\n";
            for (i = 0;i < n_minuman;i++) {
                cout << minuman[i] << " (kode: " << i << ")\n";
            }
            cout << "-----------------------\n";
            cout << "Input kode: ";
            cin >> pesanan_minuman[n_pesan_minuman];
            n_pesan_minuman++;
            break;
        case 3:
            total_pesanan = 0;
            cout << "----------makanan-------------\n";
            for (i = 0;i < n_pesan_makanan;i++) {
                cout << makanan[pesanan_makanan[i]];
                cout << " (harga: ";
                cout << harga_makanan[pesanan_makanan[i]];
                cout << ")\n";
                total_pesanan += harga_makanan[pesanan_makanan[i]];
            }
            cout << "----------minuman-------------\n";
            for (i = 0;i < n_pesan_minuman;i++) {
                cout << minuman[pesanan_minuman[i]];
                cout << " (harga: ";
                cout << harga_minuman[pesanan_minuman[i]];
                cout << ")\n";
                total_pesanan += harga_minuman[pesanan_minuman[i]];
            }
            cout << "-----------total--------------\n";
            cout << "Total: " << total_pesanan << endl;
            cout << "------------------------------\n";
            break;
        case 4:
            isDone = true;
            //  addMenu();
            while (isDone) {
                harga = 0;
                tambahanMenu = "";

                int menu;
                cout << "pilih menu: \n 1. Tambah Menu Makanan \n 2. tambah menu minuman \n 3. Quit \n" << endl;
                cout << "Pilih nomor Menu: ";

                cin >> menu;
                if (menu == 1) {
                    std::cout << "nama menu baru: ";
                    cin.ignore();
                    std::getline(std::cin, tambahanMenu);
                    std::cout << "harga menu baru: ";

                    std::cin >> harga;
                    cout << harga << endl;

                    makanan[n_makanan] = tambahanMenu;
                    harga_makanan[n_makanan] = harga;
                    n_makanan++;
                }
                else if (menu == 2) {
                    std::cout << "nama menu baru: ";
                    cin.ignore();
                    std::getline(std::cin, tambahanMenu);
                    std::cout << "harga menu baru: ";
                    std::cin >> harga;

                    minuman[n_minuman] = tambahanMenu;
                    harga_minuman[n_minuman] = harga;
                    n_minuman++;
                }
                else if (menu == 3) {
                    isDone = false;
                }
            }
            break;
        case 5:
            isDone = true;
            //  addMenu();
            while (isDone) {
                tambahanMenu = "";


                int menu;
                cout << "pilih menu: \n 1. ganti Menu Makanan \n 2. ganti menu minuman \n 3. Quit \n" << endl;
                cout << "Pilih nomor Menu: ";
                cin >> menu;
                if (menu == 1) {

                    for (i = 0;i < n_makanan;i++) {
                        cout << makanan[i] << " (kode: " << i << ")\n";
                    }

                    cout << "-----------------------\n";
                    cout << "Input kode makanan yang akan diedit: ";
                    cin >> inputcode;

                    std::cout << "update nama menu : ";
                    cin.ignore();
                    std::getline(std::cin, tambahanMenu);

                    makanan[inputcode] = tambahanMenu;
                }
                else if (menu == 2) {
                    for (i = 0;i < n_minuman;i++) {
                        cout << minuman[i] << " (kode: " << i << ")\n";
                    }

                    cout << "-----------------------\n";
                    cout << "Input kode minuman yang akan diedit: ";
                    cin >> inputcode;

                    std::cout << "update nama menu : ";
                    cin.ignore();
                    std::getline(std::cin, tambahanMenu);
                    minuman[inputcode] = tambahanMenu;

                }
                else if (menu == 3) {
                    isDone = false;
                }
            }
            break;
        case 6:
            is_lanjut = false;
            break;

        }
    }
}
