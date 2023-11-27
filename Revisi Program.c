#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void main() {
    //Tipe Data program
    char kode[100][100];
    char nama[100][100];
    int totalBarang[100];
    char tanggalMasuk[100][100];
    char tanggalKeluar[100][100];
    int n = 0;
    int pilihan;

    //Profil Program
        printf("\t\t\t==============================================\n");
        printf("\t\t\t|                  SISTEM                    |\n");
        printf("\t\t\t|        PENGADAAN BARANG PADA BENGKEL       |\n");
        printf("\t\t\t|                                            |\n");
        printf("\t\t\t|           PT.SOLUSI CIPTA KARYA            |\n");
        printf("\t\t\t|     Jl. Kwini No.1, RT.5/RW.1, Senen,      |\n");
        printf("\t\t\t|    Daerah Khusus Ibukota Jakarta 10410     |\n");
        printf("\t\t\t==============================================\n");

    do { //Menu opsi utama
        printf("\n\t\t\t SILAKAN PILIHAN MENU OPSI: \n");
        printf("\t\t\t 1. MASUK BARANG\n");
        printf("\t\t\t 2. BARANG KELUAR\n");
        printf("\t\t\t 3. INFORMASI STOCK BARANG\n");
        printf("\t\t\t 4. KELUAR\n\n");

        printf("\t\t\t MASUKAN OPSI: ");
        scanf("%d", &pilihan);

        switch (pilihan) { //Input Opsi Barang
            case 1:
                printf("\t\t\t MASUKKAN KODE BARANG: ");
                scanf("%s", kode[n]);

                printf("\t\t\t MASUKKAN NAMA BARANG: ");
                scanf(" %[^\n]s", nama[n]);

                printf("\t\t\t MASUKKAN TOTAL BARANG: ");
                scanf("%d", &totalBarang[n]);

                printf("\t\t\t MASUKKAN TANGGAL MASUK (DD/MM/YYYY): ");
                scanf("%s", tanggalMasuk[n]);fflush(stdin);

                printf("\n\t\t\t======================================================\n");
                n++;
                break;

            case 2:
                printf("\t\t\t MASUKKAN KODE BARANG KELUAR: "); //Output Opsi Barang
                char kodeKeluar[100];
                scanf("%s", kodeKeluar);

                int i, j;
                for (i = 0; i < n; i++) {
                    if (strcmp(kodeKeluar, kode[i]) == 0) {
                        printf("\t\t\t MASUKKAN JUMLAH BARANG KELUAR: ");
                        int barangKeluar;
                        scanf("%d", &barangKeluar);

                        if (barangKeluar > totalBarang[i]) {
                            printf("\t\t\t MAAF JUMLAH BARANG MELEBIHI STOCK YANG ADA\n");
                        } else {
                            totalBarang[i] -= barangKeluar;
                            printf("\t\t\t MASUKKAN TANGGAL KELUAR (DD/MM/YYYY): ");
                            scanf("%s", tanggalKeluar[i]);
                            printf("\t\t\t BARANG BERHASIL DIKELUARKAN \n");
                        }
                        printf("\n\t\t\t======================================================\n");

                        break;
                    }
                }

                if (i == n) {
                    printf("\t\t\t KODE BARANG TIDAK DITEMUKAN\n");
                }

                break;

            case 3:
                printf("\t\t\t DATA BARANG SAAT INI:\n"); //Data barang Program
                printf("\t\t\t -----------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t | %-10s | %-20s | %-15s | %-20s | %-20s |\n", "KODE", "NAMA", "TOTAL BARANG", "TANGGAL MASUK", "TANGGAL KELUAR");
                printf("\t\t\t -----------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("\t\t\t | %-10s | %-20s | %-15d | %-20s | %-20s |\n", kode[i], nama[i], totalBarang[i], tanggalMasuk[i], tanggalKeluar[i]);
                }
                printf("\t\t\t -----------------------------------------------------------------------------------------------------\n\n");
                break;

            case 4:
                 printf("\t\t\t==============================================\n");
                 printf("\t\t\t|                                            |\n");
                 printf("\t\t\t|                TERIMA KASIH                |\n");
                 printf("\t\t\t|            SISTEM AKAN TERTUTUP            |\n");
                 printf("\t\t\t|                                            |\n");
                 printf("\t\t\t==============================================\n");
                break;

            default: //Opsi barang tidak ada
                printf("\t\t\t Pilihan tidak valid\n");
        }
       getchar();
    } while (pilihan != 4);

}
