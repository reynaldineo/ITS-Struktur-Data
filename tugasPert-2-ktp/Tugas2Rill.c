#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nama[50], tempatLahir[15], nik[16], pekerjaan[15], alamat[50];
    int agama, tanggalLahir, bulanLahir, tahunLahir, kewarganegaraan, jenisKelamin, status;
} stat;

void tambah() {
    int ulang = 0;
    stat newData;
    FILE *out;
    out = fopen("data.bin", "ab+");

    printf("Masukan Data: \n");
    printf("NIK : ");
    scanf("%s", newData.nik);

    printf("Nama : ");
    scanf("\n%[^\n]%*c", newData.nama);

    printf("Tempat lahir : ");
    scanf("\n%[^\n]%*c", newData.tempatLahir);

    printf("Tanggal Lahir : ");
    scanf("\n%d", &newData.tanggalLahir);

    printf("Bulan Lahir : ");
    scanf("\n%d", &newData.bulanLahir);

    printf("Tahun Lahir : ");
    scanf("\n%d", &newData.tahunLahir);

    printf("Pekerjaan : ");
    scanf("\n%[^\n]%*c", newData.pekerjaan);

    printf("Alamat : ");
    scanf("\n%[^\n]%*c", newData.alamat);

    printf("Agama :\n1.) Isalm\n2.) Kristen\n3.) Katolik\n4.) Hindu\n5.) Budha\n6.) Konghucu\nPilih : ");
    scanf("%d", &newData.agama);

    printf("\nKewarganegaraan :\n1.) WNI\n2.) WNA\nPilih : ");
    scanf("%d", &newData.kewarganegaraan);

    printf("\nStatus :\n1.) Kawin\n2.) Belum Kawin\n3.) Cerai Hidup\n4.) Cerai Mati\nPilih : ");
    scanf("%d", &newData.status);

    printf("\nJenis Kelamin :\n1.) Laki-laki\n2.) Perempuan\nPilih : ");
    scanf("%d", &newData.jenisKelamin);

    fwrite(&newData, sizeof(stat), 1, out);
    fclose(out);

    out = fopen("data.bin", "rb");
    fseek (out, 0, SEEK_END);
    

    printf("Data Berhasil Disimpan\n");
    puts("Apakah Input lagi ? (1) Ya\t(2) Tidak");
    printf("Input :");
    scanf("%d", &ulang);
    if (ulang == 1) {
        tambah();
    }
}

// Cari data
void baca(char NIK[])
{
    FILE *out;
    out = fopen("data.bin", "rb");
    stat myrecord;
    while (fread(&myrecord, sizeof(stat), 1, out) == 1) {
        if (strcmp(myrecord.nik, NIK) == 0) {
            printf("Nama\t\t\t: %s\n", myrecord.nama);
            printf("Tempat, Tanggal Lahir\t: %s, %02d-%02d-%d\n", myrecord.tempatLahir, myrecord.tanggalLahir, myrecord.bulanLahir, myrecord.tahunLahir);
            printf("Pekerjaan\t\t: %s\n", myrecord.pekerjaan);
            printf("Alamat\t\t\t: %s\n", myrecord.alamat);
            switch (myrecord.agama) {
            case 1:
                printf("Agama\t\t\t: Islam");
                break;
            case 2:
                printf("Agama\t\t\t: Kristen");
                break;
            case 3:
                printf("Agama\t\t\t: Katolik");
                break;
            case 4:
                printf("Agama\t\t\t: Budha");
                break;
            case 5:
                printf("Agama\t\t\t: Konghucu");
                break;
            default:
                break;
            }
            puts("");

            switch (myrecord.kewarganegaraan)
            {
            case 1:
                printf("Kewarganegaraan\t\t: WNI");
                break;
            case 2:
                printf("Kewarganegaraan\t\t: WNA");
                break;
            default:
                break;
            }
            puts("");

            switch (myrecord.status)
            {
            case 1:
                printf("Status\t\t\t: Kawin");
                break;
            case 2:
                printf("Status\t\t\t: Belum Kawin");
                break;
            case 3:
                printf("Status\t\t\t: Cerai Hidup");
                break;
            case 4:
                printf("Status\t\t\t: Cerai Mati");
                break;
            default:
                break;
            }
            puts("");

            switch (myrecord.jenisKelamin)
            {
            case 1:
                printf("Jenis Kelamin\t\t: Laki-Laki");
                break;
            case 2:
                printf("Jenis Kelamin\t\t: Perempuan");
                break;
            default:
                break;
            }
            puts("");
        }
    }
    fclose(out);
    puts("");
}

void hapus(char NIK[])
{
    FILE *out;
    FILE *out_tmp;
    int found = 0;
    stat myrecord;
    out = fopen("data.bin", "rb");
    out_tmp = fopen("tmp.bin", "wb+");
    while (fread(&myrecord, sizeof(stat), 1, out) == 1) {
        if (strcmp(NIK, myrecord.nik) == 0) {
            printf("Data ditemukan dan dihapus.\n\n");
            found = 1;
        } else {
            fwrite(&myrecord, sizeof(stat), 1, out_tmp);
        }
    }

    if (!found) {
        printf("Data tidak ditemukan: %s\n\n", NIK);
    }

    fclose(out);
    fclose(out_tmp);

    remove("data.bin");
    rename("tmp.bin", "data.bin");
    puts("");
}

void tampilkan_semua() {
    FILE *out;
    out = fopen("data.bin", "rb");
    stat myrecord;
    while (fread(&myrecord, sizeof(stat), 1, out) == 1) {
        printf("Nama\t\t\t: %s\n", myrecord.nama);
        printf("Tempat, Tanggal Lahir\t: %s, %02d-%02d-%d\n", myrecord.tempatLahir, myrecord.tanggalLahir, myrecord.bulanLahir, myrecord.tahunLahir);
        printf("Pekerjaan\t\t: %s\n", myrecord.pekerjaan);
        printf("Alamat\t\t\t: %s\n", myrecord.alamat);
        switch (myrecord.agama) {
        case 1:
            printf("Agama\t\t\t: Islam");
            break;
        case 2:
            printf("Agama\t\t\t: Kristen");
            break;
        case 3:
            printf("Agama\t\t\t: Katolik");
            break;
        case 4:
            printf("Agama\t\t\t: Budha");
            break;
        case 5:
            printf("Agama\t\t\t: Konghucu");
            break;
        default:
            break;
        }
        puts("");
        switch (myrecord.kewarganegaraan)
        {
        case 1:
            printf("Kewarganegaraan\t\t: WNI");
            break;
        case 2:
            printf("Kewarganegaraan\t\t: WNA");
            break;
        default:
            break;
        }
        puts("");
        switch (myrecord.status)
        {
        case 1:
            printf("Status\t\t\t: Kawin");
            break;
        case 2:
            printf("Status\t\t\t: Belum Kawin");
            break;
        case 3:
            printf("Status\t\t\t: Cerai Hidup");
            break;
        case 4:
            printf("Status\t\t\t: Cerai Mati");
            break;
        default:
            break;
        }
        puts("");
        switch (myrecord.jenisKelamin) {
        case 1:
            printf("Jenis Kelamin\t\t: Laki-Laki");
            break;
        case 2:
            printf("Jenis Kelamin\t\t: Perempuan");
            break;
        default:
            break;
        }
        puts("");
    }
    fclose(out);
    puts("");
}

int main() {
    while (1) {
        int opr;
        printf("Selamat Datang\n\nPilih Menu\n1. Entri Data KTP\n2. Cari Data KTP\n3. Hapus Data\n4. Tampilkan Semua Data\n5. Keluar\n\nMasukan : ");
        scanf("%d", &opr);
        if (opr == 1) {
            tambah();
        }
        if (opr == 2) {
            char NIK[20];
            printf("\nCari NIK : ");
            scanf("%s", NIK);
            baca(NIK);
        }
        if (opr == 3) {
            char NIK[20];
            printf("\n NIK : ");
            scanf("%s", NIK);
            hapus(NIK);
        }
        if (opr == 4) {
            tampilkan_semua();
        }
        if (opr == 5) {
            break;
        }
    }
}