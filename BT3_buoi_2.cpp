#include <iostream>
#include <iomanip> 

using namespace std;

class SoPhuc {
private:
    double iThuc, iAo; 

public:
    // Phương thức Nhập số phức
    void Nhap() {
        cout << "Nhap phan thuc: "; 
        cin >> iThuc;
        cout << "Nhap phan ao: "; 
        cin >> iAo;
    }

    // Phương thức Xuất số phức theo định dạng a + bi
    void Xuat() {
        if (iAo >= 0)
            cout << iThuc << " + " << iAo << "i";
        else
            cout << iThuc << " - " << -iAo << "i";
    }

    // Phương thức tính Tổng hai số phức
    SoPhuc Tong(SoPhuc sp) {
        SoPhuc kq;
        kq.iThuc = iThuc + sp.iThuc;
        kq.iAo = iAo + sp.iAo;
        return kq;
    }

    // Phương thức tính Hiệu hai số phức
    SoPhuc Hieu(SoPhuc sp) {
        SoPhuc kq;
        kq.iThuc = iThuc - sp.iThuc;
        kq.iAo = iAo - sp.iAo;
        return kq;
    }

    // Phương thức tính Tích hai số phức
    SoPhuc Tich(SoPhuc sp) {
        SoPhuc kq;
        kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
        kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
        return kq;
    }

    // Phương thức tính Thương hai số phức
    SoPhuc Thuong(SoPhuc sp) {
        SoPhuc kq;
        double mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
        // Kiểm tra chia cho số phức 0
        if (mau == 0) {
            cout << "\nLoi: Mau so bang 0, khong the thuc hien phep chia!";
            kq.iThuc = 0; kq.iAo = 0;
        } else {
            kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
            kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;
        }
        return kq;
    }
};

int main() {
    SoPhuc sp1, sp2;

    cout << "--- Nhap so phuc thu nhat ---\n";
    sp1.Nhap();
    cout << "--- Nhap so phuc thu hai ---\n";
    sp2.Nhap();

    cout << "\nSo phuc 1: "; sp1.Xuat();
    cout << "\nSo phuc 2: "; sp2.Xuat();

    // Thực hiện các phép tính
    SoPhuc tong = sp1.Tong(sp2);
    SoPhuc hieu = sp1.Hieu(sp2);
    SoPhuc tich = sp1.Tich(sp2);
    SoPhuc thuong = sp1.Thuong(sp2);

    cout << "\n\n----------------------------";
    cout << "\nKET QUA CAC PHEP TINH:";
    
    cout << "\nTong: "; tong.Xuat();
    cout << "\nHieu: "; hieu.Xuat();
    cout << "\nTich: "; tich.Xuat();
    
    cout << "\nThuong: "; 
    // Đặt độ chính xác cho phép chia để kết quả đẹp hơn
    cout << fixed << setprecision(2); 
    thuong.Xuat();

    cout << "\n----------------------------\n";
    system("pause");
    return 0;
}