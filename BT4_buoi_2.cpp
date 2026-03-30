#include <iostream>
#include <iomanip>

using namespace std;

class GioPhutGiay {
private:
    int iGio, iPhut, iGiay;

public:
    // Phương thức nhập dữ liệu
    void Nhap() {
        do {
            cout << "Nhap gio (0-23): "; cin >> iGio;
            cout << "Nhap phut (0-59): "; cin >> iPhut;
            cout << "Nhap giay (0-59): "; cin >> iGiay;
            if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
                cout << "Du lieu khong hop le! Vui long nhap lai.\n";
            }
        } while (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59);
    }

    // Phương thức xuất dữ liệu định dạng hh:mm:ss
    void Xuat() {
        cout << setfill('0') << setw(2) << iGio << ":"
             << setfill('0') << setw(2) << iPhut << ":"
             << setfill('0') << setw(2) << iGiay << endl;
    }

    // Phương thức tính cộng thêm một giây
    void TinhCongThemMotGiay() {
        iGiay++;
        if (iGiay >= 60) {
            iGiay = 0;
            iPhut++;
            if (iPhut >= 60) {
                iPhut = 0;
                iGio++;
                if (iGio >= 24) {
                    iGio = 0;
                }
            }
        }
    }
};

int main() {
    GioPhutGiay tg;

    cout << "--- Nhap thoi gian ---\n";
    tg.Nhap();

    cout << "\nThoi gian vua nhap: ";
    tg.Xuat();

    tg.TinhCongThemMotGiay();
    cout << "Thoi gian sau khi cong 1 giay: ";
    tg.Xuat();
    system("pause");
    return 0;
}