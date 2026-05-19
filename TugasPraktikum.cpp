#include <iostream>
using namespace std;

class RekeningBank {
public:
    virtual ~RekeningBank() {}
    virtual void potongAdmin() = 0;
};

class RekeningSyariah : public RekeningBank {
private:
    double saldo;
public:
    RekeningSyariah(double saldo) : saldo(saldo) {}
    void potongAdmin() {
        cout << "Rekening Syariah: tidak ada potongan, saldo tetap Rp " << saldo << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
private:
    double saldo;
public:
    RekeningKonvensional(double saldo) : saldo(saldo) {}
    void potongAdmin() {
        saldo -= 15000;
        cout << "Rekening Konvensional: saldo setelah potongan Rp " << saldo << endl;
    }
};

class RekeningPremium : public RekeningBank {
private:
    double saldo;
public:
    RekeningPremium(double saldo) : saldo(saldo) {}
    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Rekening Premium: saldo di atas 10jt, bebas admin. Saldo Rp " << saldo << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium: saldo dipotong Rp 50.000, saldo Rp " << saldo << endl;
        }
    }
};

int main() {
    RekeningBank* rekening[3];

    rekening[0] = new RekeningSyariah(500000);
    rekening[1] = new RekeningKonvensional(500000);
    rekening[2] = new RekeningPremium(15000000);

    cout << "--- Proses Otomatisasi Akhir Bulan ---" << endl;
    for (int i = 0; i < 3; i++) {
        rekening[i]->potongAdmin();
    }

    for (int i = 0; i < 3; i++) {
        delete rekening[i];
    }

    return 0;
}