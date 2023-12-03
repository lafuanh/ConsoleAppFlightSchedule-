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
#include <chrono>
#include <iomanip>

int hari_now = 3;

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
    int tipePesawat; //1 large: 240, 2 medium: 140,3 small: 80 --
    //25% are bussnies 50% are economy 10% are first class, 15% are quite zone
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


struct dataDiri
{
    string nama;
    int usia;
    string nomorhp;
    void display() {
        cout<< "Nama :" << nama<< endl;
        cout<< "usia :" << usia<< endl;
        cout<< "usia :" << nomorhp<< endl;
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

Penerbangan createPenerbangan(int nomorPesawat,int date,int depature, string codeTujuan, string codeBandaraAwal, string gate) {
    Penerbangan penerbangan_new;
    penerbangan_new.nomorPesawat= nomorPesawat;
    penerbangan_new.tanggalPenerbangan = date;
    penerbangan_new.jamKeberangkatan = depature;
    penerbangan_new.status = "null";
    penerbangan_new.id_BandaraTujuan = codeTujuan;
    penerbangan_new.id_BandaraSekarang = codeBandaraAwal;
    penerbangan_new.id_gate = gate;
    return penerbangan_new;
}

void generatePenerbangan(){
    int countPlane= 0;
    std::srand(static_cast<unsigned int>(std::time(0)));
    string numberGate;
    for(int i = 0; i < JumlahBandara;i++){

        for(int j = 0; j < 7;j++){
            
            for(int k =0; k < 3;k++){
                int randomNumberBandara = std::rand() % 10;
                int depature = 0; //in minutes
                
                if(randomNumberBandara == i && randomNumberBandara != JumlahBandara - 1){
                    randomNumberBandara++;
                }else if(randomNumberBandara == i && randomNumberBandara == JumlahBandara - 1){
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
            
                
                
                dataPenerbangan.push_back(createPenerbangan(dataPesawat[countPlane].idPesawat, j+ 1,depature, Bandara[randomNumberBandara][1],Bandara[i][1],numberGate));

                countPlane++;

            }
        }
    }
    
}


void startAplication() {
    generatePesawat();
    generatePenerbangan();
    //generate penerbangan -- set every day had to be 3 plane each airport to random airport
    
}

//---------- FUNGSI Flight board ---------//
int showActualTime(){
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

void updateStatus(int currentDate){
    int jam = showActualTime();
    for ( auto& penerbangan : dataPenerbangan) {
        if(penerbangan.tanggalPenerbangan == currentDate){
            if(penerbangan.jamKeberangkatan < jam ){
                penerbangan.status = "gate closed";
            }else if(penerbangan.tanggalPenerbangan > jam && penerbangan.tanggalPenerbangan <= jam - 90){
                penerbangan.status = "gate open";
            }else{
                penerbangan.status = "Boarding";

            }
        }else if (penerbangan.tanggalPenerbangan < currentDate){
            penerbangan.status = "experied";
        }else if (penerbangan.tanggalPenerbangan > currentDate){
            penerbangan.status = "scheduled";
        }
    }
}


void DisplayBoard(string airportCode, int date){
    int jam = showActualTime() ;
    
    cout<< "\njam: "<< convertJam(jam) << "\ntanggal: "<< hari_now<< " Desember 2023\n" <<endl;
    cout << std::setw(15) << std::left << "Kode Pesawat"
               << std::setw(20) << "Depature"
               << std::setw(15) << "Remarks"
               <<  std::setw(15) << "Gate"
              <<std::setw(15) << "Tujuan"<< endl;
    
     for (const auto& penerbangan : dataPenerbangan) {
         if (penerbangan.id_BandaraSekarang == airportCode && penerbangan.tanggalPenerbangan == date) {
             
             std::cout << std::setw(15) << convertKodePesawat(penerbangan.nomorPesawat)
                       << std::setw(20) << convertJam(penerbangan.jamKeberangkatan)
                        << std::setw(15) << penerbangan.status
                       << std::setw(15) <<  penerbangan.id_gate
                      << std::setw(15) << penerbangan.id_BandaraTujuan<< "\n"<<std::endl;
         }
     }
}
//---------------------
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
    //data diri

    void display(){
        cout<< "[------ AIR TICKET ------]"<<endl;
        cout<< "asal bandara: " << id_bandaraSaatIni << endl;
        cout<< "     VVV"<<endl;
        cout<< "tujuan: " << id_tujuanBerangkat<<endl;
        
        cout<< "\npesawat: " << convertKodePesawat(idPesawat)<<endl;

        
        cout<< "\nPenumpang: "<< namaPenumpang<<endl;
        cout<< "gate: " << gate<<endl;
        cout << "Depature: "<< convertJam(jamDepature)<<" " <<tanggalBerangkat<<endl;
        
        cout << "\nticket: "<<idTicket<<endl;
        cout<< "[-----------------------]"<<endl;

    }
};

std::vector<Tiket> dataTicket;

Tiket createTiket(int nTiket, int nPesawat, int tanggalPesawat, int timeDepature, string idBandaraNow,string idTujuan,string idGate, string nama) {
    Tiket Ticket_new;
    Ticket_new.idTicket = nTiket;
    Ticket_new.idPesawat = nPesawat;
    Ticket_new.tanggalBerangkat = tanggalPesawat;
    Ticket_new.jamDepature = timeDepature;
    Ticket_new.id_bandaraSaatIni = idBandaraNow;
    Ticket_new.id_tujuanBerangkat = idTujuan;
    Ticket_new.gate = idGate;
    Ticket_new.namaPenumpang = nama;
    return Ticket_new;
}

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
    "1. Tambahkan Penerbangan",
    "2. Edit Penerbangan",
    "3. Kembali"
};


//kursi
//function all button
void menuAdmin(){
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
            break;
        case 2:
            break;
        case 3:
                is_lanjut = false;
            break;
       

        }
    }
}

void menuAirportBoard(){
    bool loop=true;
    while (loop){
        int choiceAirport;
        int choiceday;
        cout<< "\n\n[ Pilih Bandara ]"<< endl;
        for (int i = 0;i < JumlahBandara;i++) {
            cout << i+1<<". "<<Bandara[i][0] << endl;
        }
        cout << "Pilih Menu: ";
        cin >> choiceAirport;
        
        cout << "Pilih tanggal 1-7 : ";
        cin >> choiceday;
        
        cout << "\n*membuka flight tracker "<< Bandara[choiceAirport-1][0]<< " untuk tanggal " << choiceday<<"\nwaktu sekarang:";
        
        DisplayBoard(Bandara[choiceAirport-1][1], choiceday);
        char isExit;
        cout << "kembali ke menu utama (Y/N) : ";
        cin >> isExit;
        if(isExit == 'Y'||isExit =='y'){
            loop = false;
        }
    }

}

void menuCostumer(){
    bool is_lanjut = true;
    int pilih;
    
    while (is_lanjut) {
        for (int i = 0;i < 4;i++) {
            cout << menu_constumer[i] << endl;
        }
        
        cout << "Pilih Menu: ";
        cin >> pilih;
        switch (pilih) {
        case 1:
                //ke menu data diri
             //   buat sama edit sama aja
            break;
        case 2:
                //menu pemesanan
            break;
        case 3:
                //show all ticket display
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
    DisplayBoard("SOC", 3);

    dataDiri myData = {"admin", 0, "admin"};
    bool is_lanjut = true;
    int i, pilih;

    int jam = showActualTime() ;
    cout << "[+++++ Program Flight Tracker & pemesanan tiket +++++]"<< endl;

    cout<< "\njam: "<< convertJam(jam) << "\ntanggal: "<< hari_now<< " Desember 2023\n" <<endl;

    while (is_lanjut) {
        cout << "\n[+++++ Menu Utama +++++]"<< endl;

        for (i = 0;i < 6;i++) {
            cout << menu_app[i] << endl;
        }
        
        cout << "Pilih Menu: ";
        cin >> pilih;
        switch (pilih) {
        case 1:
                //check admin if not return messages
                if(myData.nama == "admin" && myData.nomorhp == "admin"){
                    menuAdmin();
                    //belum lesai
                }else{
                    cout<< "\nanda bukan admin!\n"<< endl;
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
