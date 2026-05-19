#include <iostream>
using namespace std;

class RekeningBank {
public:
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