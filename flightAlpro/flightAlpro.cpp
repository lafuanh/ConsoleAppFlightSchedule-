//
//  main.cpp
//  algoproTeam
//
//  Created by naufal adyatma on 06/11/23.
//
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS


#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

int hari_now = 18; //ganti hari 15-21 untuk menganti hari program

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
int jumlahMaskapai = sizeof(dataMaskapai) / sizeof(dataMaskapai[0]);


struct Pesawat {
    int idPesawat;
    string idMaskapai;
    int tipePesawat; //1 large: 240, 2 medium: 140,3 small: 80 --
    //25% are bussnies 50% are economy 10% are first class, 15% are quite zone
};

struct kursi
{
    string jenis;
    double harga;
};
vector<kursi> datakursi;


kursi createKursi(string tipe, double harga) {
    kursi kursi_new;
    kursi_new.jenis = tipe;
    kursi_new.harga = harga;
    return kursi_new;
}

void generateKursi() {
    datakursi.push_back(createKursi("Bisnis", 200));
    datakursi.push_back(createKursi("Ekonomi", 50));
    datakursi.push_back(createKursi("First class", 400));
    datakursi.push_back(createKursi("Quiet zone", 100));
}


struct dataDiri
{
    string NIK;
    string nama;
    int usia;
    string nomorhp;
    void display() {
        cout << "NIK :" << NIK << endl;
        cout << "Nama :" << nama << endl;
        cout << "usia :" << usia << endl;
        cout << "Nomor HP :" << nomorhp << endl;
    }
};
dataDiri myData = { "admin", "admin", 0, "admin" };


//------------------------------//
std::vector<Pesawat> dataPesawat;

Pesawat createPesawat(int nomorPesawat, string id_maskapai, int tipe) {
    Pesawat pesawat_new;
    pesawat_new.idPesawat = nomorPesawat;
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

//-----//
struct Penerbangan
{
    int nomorPesawat;
    int tanggalPenerbangan;
    int jamKeberangkatan;

    string status;
    string id_BandaraTujuan;
    string id_BandaraSekarang;
    string id_gate;

};

std::vector<Penerbangan> dataPenerbangan;

Penerbangan createPenerbangan(int nomorPesawat, int date, int depature, string codeTujuan, string codeBandaraAwal, string gate) {
    Penerbangan penerbangan_new;
    penerbangan_new.nomorPesawat = nomorPesawat;
    penerbangan_new.tanggalPenerbangan = date;
    penerbangan_new.jamKeberangkatan = depature;
    penerbangan_new.status = "null";
    penerbangan_new.id_BandaraTujuan = codeTujuan;
    penerbangan_new.id_BandaraSekarang = codeBandaraAwal;
    penerbangan_new.id_gate = gate;
    return penerbangan_new;
}

void generatePenerbangan() {
    int countPlane = 0;
    std::srand(static_cast<unsigned int>(std::time(0)));
    string numberGate;
    for (int i = 0; i < JumlahBandara;i++) {

        for (int j = 0; j < 7;j++) {

            for (int k = 0; k < 3;k++) {
                int randomNumberBandara = std::rand() % 10;
                int depature = 0; //in minutes

                if (randomNumberBandara == i && randomNumberBandara != JumlahBandara - 1) {
                    randomNumberBandara++;
                }
                else if (randomNumberBandara == i && randomNumberBandara == JumlahBandara - 1) {
                    randomNumberBandara--;
                }

                switch (k) {
                case 0:
                    depature = std::rand() % 481;
                    numberGate = "A-1";
                    break;
                case 1:
                    depature = std::rand() % 481;
                    numberGate = "A-2";

                    break;
                case 2:
                    depature = std::rand() % 481 + 960;
                    numberGate = "B-1";

                    break;
                default:
                    break;
                }



                dataPenerbangan.push_back(createPenerbangan(dataPesawat[countPlane].idPesawat, j + 15, depature, Bandara[randomNumberBandara][1], Bandara[i][1], numberGate));

                countPlane++;

            }
        }
    }

}


void startAplication() {
    generatePesawat();
    generatePenerbangan();
    generateKursi();

}

//---------- FUNGSI Flight board ---------//
int showActualTime() {
    auto currentTime = std::chrono::system_clock::now();
    auto timeNow = std::chrono::system_clock::to_time_t(currentTime);
    auto localTime = std::localtime(&timeNow);

    int jam = localTime->tm_hour;
    int menit = localTime->tm_min;

    return jam * 60 + menit;

}

string convertJam(int minutes) {
    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;

    std::string hoursStr = std::to_string(hours);
    std::string minutesStr = std::to_string(remainingMinutes);

    if (hours < 10) {
        hoursStr = "0" + hoursStr;
    }
    if (remainingMinutes < 10) {
        minutesStr = "0" + minutesStr;
    }
    return hoursStr + ":" + minutesStr;
}

string convertKodePesawat(int nomorPesawat) {
    string kodeMaskapai;
    string kodeAkhir = std::to_string(nomorPesawat);
    for (const auto& pesawat : dataPesawat) {
        if (pesawat.idPesawat == nomorPesawat) {
            kodeMaskapai = pesawat.idMaskapai;
        }
    }
    return kodeMaskapai + " " + kodeAkhir;
}

void updateStatus(int currentDate) {
    int jam = showActualTime();
    for (auto& penerbangan : dataPenerbangan) {
        if (penerbangan.tanggalPenerbangan == currentDate) {
            if (penerbangan.jamKeberangkatan < jam) {
                penerbangan.status = "gate closed";
            }
            else if (penerbangan.tanggalPenerbangan > jam && penerbangan.tanggalPenerbangan <= jam - 90) {
                penerbangan.status = "gate open";
            }
            else {
                penerbangan.status = "Boarding";

            }
        }
        else if (penerbangan.tanggalPenerbangan < currentDate) {
            penerbangan.status = "experied";
        }
        else if (penerbangan.tanggalPenerbangan > currentDate) {
            penerbangan.status = "scheduled";
        }
    }
}
//-----------------------------------------------//


void DisplayBoard(string airportCode, int date) {
    int jam = showActualTime();

    cout << "\njam: " << convertJam(jam) << "\ntanggal: " << hari_now << " Desember 2023\n" << endl;
    cout << std::setw(15) << std::left << "Kode Pesawat"
        << std::setw(20) << "Depature"
        << std::setw(15) << "Remarks"
        << std::setw(15) << "Gate"
        << std::setw(15) << "Tujuan" << endl;

    for (const auto& penerbangan : dataPenerbangan) {
        if (penerbangan.id_BandaraSekarang == airportCode && penerbangan.tanggalPenerbangan == date) {

            std::cout << std::setw(15) << convertKodePesawat(penerbangan.nomorPesawat)
                << std::setw(20) << convertJam(penerbangan.jamKeberangkatan)
                << std::setw(15) << penerbangan.status
                << std::setw(15) << penerbangan.id_gate
                << std::setw(15) << penerbangan.id_BandaraTujuan << "\n" << std::endl;
        }
    }
}
//---------------------//
struct Tiket
{
    int idTicket;
    int idPesawat;
    int tanggalBerangkat; // time clock __ day / month / year
    string id_bandaraSaatIni;
    string id_tujuanBerangkat;
    int jamDepature;

    string gate; //random pintu masuk
    string namaPenumpang;
    string tipe;

    //data diri

    void display() {
        cout << "[------ AIR TICKET ------]" << endl;
        cout << "asal bandara: " << id_bandaraSaatIni << endl;
        cout << "     VVV" << endl;
        cout << "tujuan: " << id_tujuanBerangkat << endl;

        cout << "\npesawat: " << convertKodePesawat(idPesawat) << endl;


        cout << "Penumpang: " << namaPenumpang << endl;
        cout << "\nseat: " << tipe << endl;

        cout << "gate: " << gate << endl;
        cout << "Depature: " << convertJam(jamDepature) << " " << tanggalBerangkat << " desember 2023" << endl;

        cout << "\nNo ticket: " << idTicket << endl;
        cout << "[-----------------------]" << endl;

    }
};

std::vector<Tiket> dataTicket;

Tiket createTiket(int nTiket, int nPesawat, int tanggalPesawat, int timeDepature, string idBandaraNow, string idTujuan, string idGate, string nama, string tipeKursi) {
    Tiket Ticket_new;
    Ticket_new.idTicket = nTiket;
    Ticket_new.idPesawat = nPesawat;
    Ticket_new.tanggalBerangkat = tanggalPesawat;
    Ticket_new.jamDepature = timeDepature;
    Ticket_new.id_bandaraSaatIni = idBandaraNow;
    Ticket_new.id_tujuanBerangkat = idTujuan;
    Ticket_new.gate = idGate;
    Ticket_new.namaPenumpang = nama;
    Ticket_new.tipe = tipeKursi;

    return Ticket_new;
}

//----------------Array menu Aplikasi ----------------//
string menu_app[6] = {
    "1. Admin",
    "2. Airport Board",
    "3. Costumer",
    "4. Exit"
};

string menu_constumer[6] = {
    "1. Data Diri",
    "2. Pesan Penerbangan",
    "3. Daftar Tiket",
    "4. Kembali"
};

string menu_admin[3] = { //data diri harus admin untuk masuk menu ini
    "1. Edit Penerbangan",
    "2. kembali",
};

string menu_dataDiri[2] = { //data diri harus admin untuk masuk menu ini
    "1. perbarui Data Diri",
    //"2. Edit data diri",
    "2. kembali",
};
string menu_pembelian[3] = { //data diri harus admin untuk masuk menu ini
    "1. Beli Sekarang",
    //"2. Edit data diri",
    "2. kembali",
};


//-------------------------------------------------//


void menu_editPenerbangan() {
    vector<Penerbangan> dataPenerbanganBandara;

    int pilihPenerbangan;
    int choiceAirport;
    int pilihEntity;

    cout << "[-- Tambah Penerbangan --]" << endl;
    cout << "\n\n[ Pilih Bandara ]" << endl;
    for (int i = 0;i < JumlahBandara;i++) {
        cout << i + 1 << ". " << Bandara[i][0] << "(" << Bandara[i][1] << ")" << endl;
    }
    cout << "Pilih bandara: ";
    cin >> choiceAirport;


    cout << "\n\n[ Pilih Pesawat ]" << endl;
    int index = 1;

    for (auto& penerbangan : dataPenerbangan) {
        int selectedId = 0;

        if (penerbangan.id_BandaraSekarang == Bandara[selectedId][1] ) {
            std::cout << index << ". ";
            std::cout << "No Pesawat : " << convertKodePesawat(penerbangan.nomorPesawat) << " ";
            std::cout << "depature date: " << penerbangan.tanggalPenerbangan << " desember 2023" << " ";
            std::cout << "depature time: " << convertJam(penerbangan.jamKeberangkatan) << " ";
            std::cout << "Status: " << penerbangan.status << " ";
            std::cout << "Tujuan: " << penerbangan.id_BandaraTujuan << " ";
            std::cout << "Asal: " << penerbangan.id_BandaraSekarang << " ";
            std::cout << "Gate: " << penerbangan.id_gate << "\n";
            std::cout << "------------------------\n";
            dataPenerbanganBandara.push_back(penerbangan);
            index++;
        }
        selectedId++;

    }
    cout << "Pilih Penerbangan: ";
    cin >> pilihPenerbangan;
    pilihPenerbangan -= 1;
    std::cout << "----------- data penerbangan -------------\n";
    std::cout << "1. No Pesawat : " << dataPenerbangan[pilihPenerbangan].nomorPesawat << "\n";
    std::cout << "2. depature date: " << dataPenerbangan[pilihPenerbangan].tanggalPenerbangan << " desember 2023" << "\n";
    std::cout << "3. depature time: " << convertJam(dataPenerbangan[pilihPenerbangan].jamKeberangkatan) << "\n";
    std::cout << "4. Status: " << dataPenerbangan[pilihPenerbangan].status << "\n";
    std::cout << "5. Tujuan: " << dataPenerbangan[pilihPenerbangan].id_BandaraTujuan << "\n";
    std::cout << "6. Asal: " << dataPenerbangan[pilihPenerbangan].id_BandaraSekarang << "\n";
    std::cout << "7. Gate: " << dataPenerbangan[pilihPenerbangan].id_gate << "\n";
    std::cout << "------------------------\n";
    cout << "Pilih entity yang ingin diedit : ";
    cin >> pilihEntity;
    switch (pilihEntity) {
    case 1:
        int nomor;
        cout << "edit dengan (number): ";
        cin >> nomor;
        dataPenerbangan[pilihPenerbangan].nomorPesawat = nomor;
        break;
    case 2:
        int date;
        cin >> date;
        cout << "edit dengan hari( 15-21 ): ";
        dataPenerbangan[pilihPenerbangan].tanggalPenerbangan = date;
        break;
    case 3:
        int jam;
        int menit;
        cout << "edit dengan (jam): ";
        cin >> jam;
        cout << "edit dengan (menit): ";
        cin >> menit;
        menit = jam * 60 + menit;

        dataPenerbangan[pilihPenerbangan].jamKeberangkatan = menit;
        break;
    case 4: {
        string stats;
        cout << "edit dengan (status): ";
        cin >> stats;

        dataPenerbangan[pilihPenerbangan].status = stats;
        break;
    }
    case 5: {
        string tujuanB;
        for (int i = 0;i < JumlahBandara;i++) {
            cout << Bandara[i][0] << " : " << Bandara[i][1] << endl;
        }

        cout << "edit dengan (kode bandara): ";
        cin >> tujuanB;

        dataPenerbangan[pilihPenerbangan].id_BandaraTujuan = tujuanB;
        break;
    }
    case 6: {
        string asalB;
        for (int i = 0;i < JumlahBandara;i++) {
            cout << Bandara[i][0] << " : " << Bandara[i][1] << endl;
        }

        cout << "edit dengan (kode bandara): ";
        cin >> asalB;

        dataPenerbangan[pilihPenerbangan].id_BandaraSekarang = asalB;
        break;

    }
    case 7: {
        string gateB;

        cout << "edit dengan (gate ex: C-5): ";
        cin >> gateB;

        dataPenerbangan[pilihPenerbangan].id_BandaraSekarang = gateB;
        break;

    }
    }

    std::cout << "----------- data penerbangan baru -------------\n";
    std::cout << "1. No Pesawat : " << dataPenerbangan[pilihPenerbangan].nomorPesawat << "\n";
    std::cout << "2. depature date: " << dataPenerbangan[pilihPenerbangan].tanggalPenerbangan << " desember 2023" << "\n";
    std::cout << "3. depature time: " << convertJam(dataPenerbangan[pilihPenerbangan].jamKeberangkatan) << "\n";
    std::cout << "4. Status: " << dataPenerbangan[pilihPenerbangan].status << "\n";
    std::cout << "5. Tujuan: " << dataPenerbangan[pilihPenerbangan].id_BandaraTujuan << "\n";
    std::cout << "6. Asal: " << dataPenerbangan[pilihPenerbangan].id_BandaraSekarang << "\n";
    std::cout << "7. Gate: " << dataPenerbangan[pilihPenerbangan].id_gate << "\n";
    std::cout << "------------------------\n";
}



void menuAdmin() {
    bool is_lanjut = true;
    int pilih;
    while (is_lanjut) {
        for (int i = 0;i < 3;i++) {
            cout << menu_admin[i] << endl;
        }

        cout << "Pilih Menu: ";
        cin >> pilih;
        switch (pilih) {
        case 1:
            menu_editPenerbangan();
            break;

        case 2:
            is_lanjut = false;
            break;


        }
    }
}

void menuAirportBoard() {
    bool loop = true;
    while (loop) {
        int choiceAirport;
        int choiceday;
        cout << "\n\n[ Pilih Bandara ]" << endl;
        for (int i = 0;i < JumlahBandara;i++) {
            cout << i + 1 << ". " << Bandara[i][0] << endl;
        }
        cout << "Pilih Menu: ";
        cin >> choiceAirport;

        cout << "Pilih tanggal 15-21 : ";
        cin >> choiceday;

        cout << "\n*membuka flight tracker " << Bandara[choiceAirport - 1][0] << " untuk tanggal " << choiceday << "\nwaktu sekarang:";

        DisplayBoard(Bandara[choiceAirport - 1][1], choiceday);
        char isExit;
        cout << "kembali ke menu utama (Y/N) : ";
        cin >> isExit;
        if (isExit == 'Y' || isExit == 'y') {
            loop = false;
        }
    }

}

void menuDatadiri() {
    bool is_lanjut = true;
    int pilih;

    string nama;
    string nomor;
    int usiaB;
    string NIK;
    while (is_lanjut) {
        cout << "\n[---- Data Diri ----]\n";
        cout << "NIK : " << myData.NIK << endl;
        cout << "nama : " << myData.nama << endl;
        cout << "usia : " << myData.usia << endl;
        cout << "nomor HP : " << myData.nomorhp << endl;



        cout << "\n---------Menu---------\n";
        for (int i = 0;i < 2;i++) {
            cout << menu_dataDiri[i] << endl;
        }
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "masukan data Diri Anda: \n";
            cout << "nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "usia: ";
            cin >> usiaB;
            cout << "nomor HP: ";
            cin >> nomor;
            cout << "NIK: ";
            cin >> NIK;

            myData = { NIK,nama, usiaB, nomor };
            break;
        case 2:
            is_lanjut = false;
            break;
        default:
            break;
        }

    }

}

void menuPesanTiket() {
    bool is_lanjut = true;
    int pilih;


    while (is_lanjut) {
        cout << "\n--------- Menu Pembelian Tiket ---------\n";
        for (int i = 0;i < datakursi.size();i++) {
            cout << datakursi[i].jenis << " : " << datakursi[i].harga << "$" << endl;
        }
        cout << "\n";
        for (int i = 0;i < 4;i++) {
            cout << menu_pembelian[i] << endl;
        }
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1: {
            cout << "\n--------- Membeli tiket ---------\n";
            int pilihTujuan, pilihAsal, pilihPesawat, pilihKursi;
            vector<Penerbangan> listPenerbangantersedia;


            cout << "\n\n[ Pilih Bandara Asal]" << endl;
            for (int i = 0;i < JumlahBandara;i++) {
                cout << i + 1 << ". " << Bandara[i][0] << "(" << Bandara[i][1] << ")" << endl;
            }
            cout << "pilih bandara asal (nomor): ";
            cin >> pilihAsal;
            pilihAsal -= 1;

            cout << "\n\n[ Pilih Bandara tujuan]" << endl;
            for (int i = 0;i < JumlahBandara;i++) {
                cout << i + 1 << ". " << Bandara[i][0] << "(" << Bandara[i][1] << ")" << endl;
            }
            cout << "pilih bandara asal (nomor): ";
            cin >> pilihTujuan;
            pilihTujuan -= 1;

            cout << "\n\n[ Pilih Pesawat ]" << endl;
            int index = 1;

            for (auto& penerbangan : dataPenerbangan) {
                int selectedId = 0;

                if (penerbangan.id_BandaraSekarang == Bandara[pilihAsal][1] && penerbangan.id_BandaraTujuan == Bandara[pilihTujuan][1] && penerbangan.tanggalPenerbangan >= hari_now) {
                    std::cout << index << ". ";
                    std::cout << "No Pesawat : " << convertKodePesawat(penerbangan.nomorPesawat) << " | ";
                    std::cout << "depature date: " << penerbangan.tanggalPenerbangan << " desember 2023" << " | ";
                    std::cout << "depature time: " << convertJam(penerbangan.jamKeberangkatan) << " | ";
                    std::cout << "Status: " << penerbangan.status << " | ";
                    std::cout << "Tujuan: " << penerbangan.id_BandaraTujuan << " | ";
                    std::cout << "Asal: " << penerbangan.id_BandaraSekarang << " | ";
                    std::cout << "Gate: " << penerbangan.id_gate << "\n";
                    listPenerbangantersedia.push_back(penerbangan);
                    std::cout << "------------------------\n";
                    index++;
                }
                selectedId++;
            }

            if (listPenerbangantersedia.size() == 0) {
                cout << "penerbangan tidak ditemukan" << endl;
                break;
            }
            cout << "pilih pesawat (nomor): ";
            cin >> pilihPesawat;
            pilihPesawat -= 1;

            std::cout << "----------- data penerbangan -------------\n";
            std::cout << "No Pesawat : " << listPenerbangantersedia[pilihPesawat].nomorPesawat << "\n";
            std::cout << "depature date: " << listPenerbangantersedia[pilihPesawat].tanggalPenerbangan << " desember 2023" << "\n";
            std::cout << "depature time: " << convertJam(listPenerbangantersedia[pilihPesawat].jamKeberangkatan) << "\n";
            std::cout << "Status: " << listPenerbangantersedia[pilihPesawat].status << "\n";
            std::cout << "Tujuan: " << listPenerbangantersedia[pilihPesawat].id_BandaraTujuan << "\n";
            std::cout << "Asal: " << listPenerbangantersedia[pilihPesawat].id_BandaraSekarang << "\n";
            std::cout << "Gate: " << listPenerbangantersedia[pilihPesawat].id_gate << "\n";
            std::cout << "------------------------\n";

            cout << "[ Pilih kursi ]" << endl;
            for (int i = 0;i < datakursi.size();i++) {
                cout << i + 1 << ". " << datakursi[i].jenis << " : " << datakursi[i].harga << "$" << endl;
            }
            cout << "pilih kursi (tipe): ";
            cin >> pilihKursi;
            pilihKursi -= 1;

            cout << "\n\n[ checkout ]" << endl;
            std::cout << "Tujuan: " << listPenerbangantersedia[pilihPesawat].id_BandaraTujuan << "\n";
            std::cout << "Asal: " << listPenerbangantersedia[pilihPesawat].id_BandaraSekarang << "\n";
            std::cout << "depature : " << convertJam(listPenerbangantersedia[pilihPesawat].jamKeberangkatan) << " " << listPenerbangantersedia[pilihPesawat].tanggalPenerbangan << " desember 2023" << "\n";
            std::cout << "No Pesawat : " << listPenerbangantersedia[pilihPesawat].nomorPesawat << "\n";
            cout << "kursi: " << datakursi[pilihKursi].jenis;
            std::cout << "\n\n--------------------\n";

            cout << "Total Harga: " << datakursi[pilihKursi].harga << "$" << endl;



            char isDeal;
            cout << "beli Tiket ini? (Y/N) : ";
            cin >> isDeal;
            if (isDeal == 'Y' || isDeal == 'y') {
                dataTicket.push_back(createTiket(pilihAsal * 2023 + pilihKursi + pilihPesawat * 12 * 12000 + listPenerbangantersedia[pilihPesawat].jamKeberangkatan, listPenerbangantersedia[pilihPesawat].nomorPesawat, listPenerbangantersedia[pilihPesawat].tanggalPenerbangan, listPenerbangantersedia[pilihPesawat].jamKeberangkatan, listPenerbangantersedia[pilihPesawat].id_BandaraSekarang, listPenerbangantersedia[pilihPesawat].id_BandaraTujuan, listPenerbangantersedia[pilihPesawat].id_gate, myData.nama, datakursi[pilihKursi].jenis));
                cout << "\n++TIKET anda beli telah Masuk ke Inventory anda" << endl;
            }



            //beri pilihan nomor kursi

        }

              break;
        case 2: {
            is_lanjut = false;

        }

              break;


        default:

            break;
        }

    }
}

void menuCostumer() {
    bool is_lanjut = true;
    int pilih;

    while (is_lanjut) {
        cout << "\n[--- Menu Costumer ---]\n";
        for (int i = 0;i < 4;i++) {
            cout << menu_constumer[i] << endl;
        }

        cout << "Pilih Menu: ";
        cin >> pilih;
        switch (pilih) {
        case 1:
            menuDatadiri();
            //ke menu data diri
         //   buat sama edit sama aja
            break;
        case 2:
                if(myData.nama == "admin" ){
                    cout<<"ANDA ADALAH ADMIN!! \n";
                }else{
                    menuPesanTiket();

                }
            //menu pemesanan
            break;
        case 3:
            cout << "\n\n\n\n\n\n\n\n[ --- daftar ticket ---]\n";
            if (dataTicket.size() != 0) {
                for (int i = 0;i < dataTicket.size();i++) {
                    dataTicket[i].display();

                }
                cout<<"\n\n";

            }
            else {
                cout << "kamu tidak mempunyai tiket\n";
            }

            break;
        case 4:
            is_lanjut = false;
            break;


        }
    }
}
int main() {

    startAplication();
    updateStatus(hari_now);
    //    DisplayBoard("SOC", 3);

    bool is_lanjut = true;
    int i, pilih;

    int jam = showActualTime();
    cout << "[+++++ Program Flight Tracker & pemesanan tiket +++++]" << endl;

    cout << "\njam: " << convertJam(jam) << "\ntanggal: " << hari_now << " Desember 2023\n" << endl;

    while (is_lanjut) {
        cout << "\n[+++++ Menu Utama +++++]" << endl;

        for (i = 0;i < 6;i++) {
            cout << menu_app[i] << endl;
        }

        cout << "Pilih Menu: ";
        cin >> pilih;
        switch (pilih) {
        case 1:
            //check admin if not return messages
            if (myData.nama == "admin" && myData.nomorhp == "admin") {
                menuAdmin();
                //belum lesai
            }
            else {
                cout << "\n anda bukan admin!\n" << endl;
            }
            break;
        case 2:
            menuAirportBoard();
            break;
        case 3:
            menuCostumer();
            break;
        case 4:
            is_lanjut = false;
            break;

        }
    }
}
