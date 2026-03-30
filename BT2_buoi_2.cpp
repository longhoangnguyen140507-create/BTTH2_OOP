#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
private:
    int iTu, iMau; // Thuộc tính: Tử số và Mẫu số 

public:
    // Hàm tìm Ước chung lớn nhất để hỗ trợ rút gọn 
    int timUCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // Phương thức Nhập phân số 
    void Nhap() {
        cout << "Nhap tu so: "; 
        cin >> iTu;
        do {
            cout << "Nhap mau so (khac 0): "; 
            cin >> iMau;
            if (iMau == 0) cout << "Mau so khong hop le. Vui long nhap lai!\n";
        } while (iMau == 0); // Đảm bảo mẫu số luôn khác 0 ]
    }

    // Phương thức Xuất phân số 
    void Xuat() {
        if (iMau == 1) cout << iTu;
        else if (iTu == 0) cout << 0;
        else cout << iTu << "/" << iMau;
    }

    // Phương thức Rút gọn phân số 
    void RutGon() {
        int ucln = timUCLN(iTu, iMau);
        iTu /= ucln;
        iMau /= ucln;
        if (iMau < 0) { // Đưa dấu trừ lên tử số 
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    // Phương thức tính Tổng hai phân số 
    PhanSo Tong(PhanSo ps) {
        PhanSo kq;
        kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
        kq.iMau = iMau * ps.iMau;
        kq.RutGon();
        return kq;
    }

    // Phương thức tính Hiệu hai phân số 
    PhanSo Hieu(PhanSo ps) {
        PhanSo kq;
        kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
        kq.iMau = iMau * ps.iMau;
        kq.RutGon();
        return kq;
    }

    // Phương thức tính Tích hai phân số 
    PhanSo Tich(PhanSo ps) {
        PhanSo kq;
        kq.iTu = iTu * ps.iTu;
        kq.iMau = iMau * ps.iMau;
        kq.RutGon();
        return kq;
    }

    // Phương thức tính Thương hai phân số
    PhanSo Thuong(PhanSo ps) {
        PhanSo kq;
        kq.iTu = iTu * ps.iMau;
        kq.iMau = iMau * ps.iTu;
        // Kiểm tra chia cho phân số có tử bằng 0
        if (kq.iMau == 0) {
            cout << "\nLoi: Khong the chia cho phan so co gia tri bang 0!";
        } else {
            kq.RutGon();
        }
        return kq;
    }

    // Phương thức So sánh hai phân số 
    // Trả về: 1 (A > B), 0 (A = B), -1 (A < B)
    int SoSanh(PhanSo ps) {
        int t1 = iTu * ps.iMau;
        int t2 = ps.iTu * iMau;
        if (t1 > t2) return 1;
        if (t1 < t2) return -1;
        return 0;
    }
};

int main() {
    PhanSo a, b;

    cout << "--- Nhap phan so A ---\n";
    a.Nhap();
    cout << "--- Nhap phan so B ---\n";
    b.Nhap();

    cout << "\nPhan so A: "; a.RutGon(); a.Xuat();
    cout << "\nPhan so B: "; b.RutGon(); b.Xuat();

    // Thực hiện các phép tính 
    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);
    PhanSo thuong = a.Thuong(b);

    cout << "\n\nKET QUA PHEP TINH:";
    cout << "\nTong A + B = "; tong.Xuat();
    cout << "\nHieu A - B = "; hieu.Xuat();
    cout << "\nTich A * B = "; tich.Xuat();
    cout << "\nThuong A / B = "; thuong.Xuat();

    // So sánh
    cout << "\n\nSO SANH:";
    int check = a.SoSanh(b);
    if (check == 1) cout << "\nKet qua: A > B";
    else if (check == -1) cout << "\nKet qua: A < B";
    else cout << "\nKet qua: A = B";

    cout << endl;
    system("pause");
    return 0;
}