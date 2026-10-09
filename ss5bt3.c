
#include <stdio.h>

#define MAX 100
#define PHI_GOC 150000
#define PHI_BHYT 30000

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bao_hiem[MAX];
    int phi_kham[MAX];

    int n, i, k;
    int tong_doanh_thu;
    int so_ca_uu_tien;

    // Nhap so luong benh nhan
    do {
        printf("Nhap so luong benh nhan (0-%d): ", MAX);

        if (scanf("%d", &n) != 1) {
            printf("Du lieu khong hop le!\n");
            return 1;
        }

        if (n < 0 || n > MAX) {
            printf("So luong phai tu 0 den %d!\n", MAX);
        }
    } while (n < 0 || n > MAX);

    // Nhap thong tin benh nhan
    for (i = 0; i < n; i++) {
        ma_so[i] = 1001 + i;

        printf("\nBenh nhan %d\n", i + 1);
        printf("Ma so thu tu: %d\n", ma_so[i]);

        // Kiem tra tuoi
        do {
            printf("Nhap tuoi (1-120): ");

            if (scanf("%d", &tuoi[i]) != 1) {
                printf("Du lieu khong hop le!\n");
                return 1;
            }

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi phai tu 1 den 120!\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        // Kiem tra trang thai BHYT
        do {
            printf("Nhap BHYT (1: Co, 0: Khong): ");

            if (scanf("%d", &bao_hiem[i]) != 1) {
                printf("Du lieu khong hop le!\n");
                return 1;
            }

            if (bao_hiem[i] != 0 && bao_hiem[i] != 1) {
                printf("BHYT chi nhan 0 hoac 1!\n");
            }
        } while (bao_hiem[i] != 0 && bao_hiem[i] != 1);

        // Tinh phi kham
        if (bao_hiem[i] == 1) {
            phi_kham[i] = PHI_BHYT;
        } else {
            phi_kham[i] = PHI_GOC;
        }
    }

    // In danh sach va thong ke ban dau
    printf("\n========== HANG CHO BAN DAU ==========\n");

    tong_doanh_thu = 0;
    so_ca_uu_tien = 0;

    if (n == 0) {
        printf("Hang cho dang rong.\n");
    }

    for (i = 0; i < n; i++) {
        printf("Index: %d | Ma so: %d | Tuoi: %d",
               i, ma_so[i], tuoi[i]);

        printf(" | BHYT: %d | Phi: %d VNĐ",
               bao_hiem[i], phi_kham[i]);

        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
            so_ca_uu_tien++;
        } else {
            printf(" | THUONG\n");
        }

        tong_doanh_thu += phi_kham[i];
    }

    printf("Tong doanh thu: %d VNĐ\n", tong_doanh_thu);
    printf("So ca uu tien: %d\n", so_ca_uu_tien);

    // Nhap vi tri can huy
    printf("\nNhap index benh nhan can huy: ");

    if (scanf("%d", &k) != 1) {
        printf("Index khong hop le!\n");
        return 1;
    }

    // Kiem tra vi tri huy
    if (n == 0 || k < 0 || k >= n) {
        printf("Khong the huy! Index khong hop le");
        printf(" hoac hang cho dang rong.\n");
    } else {
        printf("Da huy benh nhan ma so %d.\n", ma_so[k]);

        // Don dich cac mang sang trai
        for (i = k; i < n - 1; i++) {
            ma_so[i] = ma_so[i + 1];
            tuoi[i] = tuoi[i + 1];
            bao_hiem[i] = bao_hiem[i + 1];
            phi_kham[i] = phi_kham[i + 1];
        }

 
        n--;
    }

    // Cap nhat va in danh sach sau khi huy
    printf("\n========== HANG CHO SAU KHI HUY ==========\n");

    tong_doanh_thu = 0;
    so_ca_uu_tien = 0;

    if (n == 0) {
        printf("Hang cho dang rong.\n");
    }

    for (i = 0; i < n; i++) {
        printf("Index: %d | Ma so: %d | Tuoi: %d",
               i, ma_so[i], tuoi[i]);

        printf(" | BHYT: %d | Phi: %d VNĐ",
               bao_hiem[i], phi_kham[i]);

        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
            so_ca_uu_tien++;
        } else {
            printf(" | THUONG\n");
        }

        tong_doanh_thu += phi_kham[i];
    }

    printf("Tong doanh thu sau cap nhat: %d VNĐ\n",
           tong_doanh_thu);
    printf("So ca uu tien sau cap nhat: %d\n",
           so_ca_uu_tien);

    printf("\nKet thuc chuong trinh.\n");

    return 0;
}
