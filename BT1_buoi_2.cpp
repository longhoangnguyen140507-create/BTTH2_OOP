#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

    // Hàm bổ trợ kiểm tra năm nhuận
    bool laNamNhuan(int n) {
        return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
    }

    // Hàm trả về số ngày tối đa trong tháng
    int timSoNgayTrongThang(int t, int n) {
        switch (t) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return laNamNhuan(n) ? 29 : 28;
            default: return 31;
        }
    }

public:
    void Nhap() {
        cout << "Nhap ngay: "; cin >> iNgay;
        cout << "Nhap thang: "; cin >> iThang;
        cout << "Nhap nam: "; cin >> iNam;
    }

    void Xuat() {
        cout << iNgay << "/" << iThang << "/" << iNam << endl;
    }

    void NgayThangNamTiepTheo() {
        int nNgay = iNgay, nThang = iThang, nNam = iNam;
        int soNgayTrongThang = timSoNgayTrongThang(iThang, iNam);

        if (nNgay < soNgayTrongThang) {
            nNgay++;
        } else {
            nNgay = 1;
            if (nThang < 12) {
                nThang++;
            } else {
                nThang = 1;
                nNam++;
            }
        }
        cout << "Ngay tiep theo la: " << nNgay << "/" << nThang << "/" << nNam << endl;
    }
};

int main() {
    NgayThangNam dt;

    cout << "--- Nhap thong tin ngay thang nam ---" << endl;
    dt.Nhap();

    cout << "\nThong tin vua nhap: ";
    dt.Xuat();

    dt.NgayThangNamTiepTheo();
    system("pause");
    return 0;
}