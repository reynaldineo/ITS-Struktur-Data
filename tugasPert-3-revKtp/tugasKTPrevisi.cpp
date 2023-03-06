#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Tanggal{
    char hari[4];
    char bulan[4];
    char tahun[6];
};

struct Alamat{
    char jalan[100];
    char RT[5];
    char RW[5];
    char kelurahan[30];
    char kecamatan[30];
    char kota[30];
};

struct Kartu{
    long long NIK;
    char nama[100];
    char tempatLahir[30];
    Tanggal tanggalLahir;
    int jenisKelamin;
    int golDarah;
    Alamat alamatRumah;
    int agama;
    int statusPerkawinan;
    char pekerjaan[50];
    int kewarganegaraan;
};

void swap(Kartu *a, Kartu *b){
    Kartu temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Kartu array[], int awal, int akhir){
    long long pivot = array[akhir].NIK;
    int i = awal;
    int j = akhir;
    while(i < j){
        if(array[i].NIK < pivot)
            i++;
        else
        if(array[j].NIK >= pivot)
            j--;
        if(array[i].NIK > pivot && array[j].NIK < pivot){
            swap(&array[i], &array[j]);
        }
    }
    if(array[i].NIK > pivot)
        swap(&array[i], &array[akhir]);
    return i;
}

void quickSort(Kartu array[], int awal, int akhir){
    if(awal < akhir){
        int pi = partition(array, awal, akhir);

        quickSort(array, awal, pi-1);
        quickSort(array, pi+1, akhir);
    }
}

void menu(){
    system("cls");
        printf("Program pengelola data KTP\n");
        printf("==========================\n");
        printf("1. Tambah data\n");
        printf("2. Cari data berdasarkan NIK\n");
        printf("3. Tampilkan data\n");
        printf("4. Hapus data berdasarkan NIK\n");
        printf("0. Keluar\n");
        printf("==========================\n");
        printf("\ninput: ");
}

void tambah(){
    Kartu *k, kTemp;
    FILE *fp;
    int n, totalData;
    system("cls");
    printf("Jumlah penduduk yang hendak ditambahkan : ");
    scanf("%d", &n);

    k = (Kartu*)malloc(n * sizeof(Kartu));
    fp = fopen("dataKTP.bin", "ab");

    for (int i = 0; i < n; i++){
        system("cls");
        printf("CATATAN : ISI SELURUH DATA MENGGUNAKAN CAPSLOCK AGAR LEBIH RAPI)\n");
        printf("NIK : ");
        scanf("%lld", &k[i].NIK);
        printf("Nama : ");
        scanf("\n%[^\n]s", k[i].nama);
        printf("Tempat lahir : ");
        scanf("\n%[^\n]s", k[i].tempatLahir);
        printf("[Tanggal lahir]\n");
        printf("Hari (2 digit) : ");
        scanf("\n%[^\n]s", k[i].tanggalLahir.hari);
        printf("Bulan (2 digit) : ");
        scanf("\n%[^\n]s", k[i].tanggalLahir.bulan);
        printf("Tahun (4 digit) : ");
        scanf("\n%[^\n]s", k[i].tanggalLahir.tahun);
        printf("Jenis kelamin dalam angka (L=1,P=2) : ");
        scanf("%d", &k[i].jenisKelamin);
        printf("Golongan darah dalam angka (O=1,A=2,B=3,AB=4) : ");
        scanf("%d", &k[i].golDarah);
        printf("[Alamat rumah]\n");
        printf("Jalan : ");
        scanf("\n%[^\n]s", k[i].alamatRumah.jalan);
        printf("RT (3 digit) : ");
        scanf("\n%[^\n]s", k[i].alamatRumah.RT);
        printf("RW (3 digit) : ");
        scanf("\n%[^\n]s", k[i].alamatRumah.RW);
        printf("Kelurahan/desa : ");
        scanf("\n%[^\n]s", k[i].alamatRumah.kelurahan);
        printf("Kecamatan : ");
        scanf("\n%[^\n]s", k[i].alamatRumah.kecamatan);
        printf("Kota/kabupaten : ");
        scanf("\n%[^\n]s", k[i].alamatRumah.kota);
        printf("Agama dalam angka (ISLAM=1,KRISTEN=2,KATOLIK=3,BUDHA=4,HINDU=5,KONGHUCHU=6) : ");
        scanf("%d", &k[i].agama);
        printf("Status perkawinan dalam angka (BELUM KAWIN=1,KAWIN=2,CERAI HIDUP=3,CERAI MATI=4) : ");
        scanf("%d", &k[i].statusPerkawinan);
        printf("Pekerjaan : ");
        scanf("\n%[^\n]s", k[i].pekerjaan);
        printf("Kewarganegaraan dalam angka (WNI=1,WNA=2) : ");
        scanf("%d", &k[i].kewarganegaraan);
        
        fwrite(&k[i], sizeof(Kartu), 1, fp);
    }
    fclose(fp);

    fp = fopen("dataKTP.bin", "rb");
    fseek(fp, 0, SEEK_END);
    totalData = ftell(fp)/sizeof(Kartu);
    k = (Kartu*)malloc(totalData * sizeof(Kartu));
    
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < totalData; i++)
        fread(&k[i], sizeof(Kartu), 1, fp);
    fclose(fp);

    quickSort(k, 0, totalData-1);
   
    fp = fopen("dataKTP.bin", "wb");
    for (int i = 0; i < totalData; i++)
        fwrite(&k[i], sizeof(Kartu), 1, fp);
    
    fclose(fp);
}

void cari(){
    Kartu *k, k1;
    FILE *fp;
    int found = 0, totalData, awal, akhir, pos;
    long long nik;
    double pos1;
    char jk[11], gd[3], agm[11], sp[15], kwn[5];
    system("cls");
    fp = fopen("dataKTP.bin", "rb");

    // proses mencari dan menampilkan data
    printf("NIK data yang hendak dicari: ");
    scanf("%lld", &nik);
    printf("\n");

    fseek(fp, 0, SEEK_END);
    totalData = ftell(fp)/sizeof(Kartu);
    k = (Kartu*)malloc(totalData * sizeof(Kartu));

    awal = 0;
    akhir = totalData-1;
    do
    {
        fseek(fp, awal*sizeof(Kartu), SEEK_SET);
        fread(&k[awal], sizeof(Kartu), 1, fp);

        fseek(fp, akhir*sizeof(Kartu), SEEK_SET);
        fread(&k[akhir], sizeof(Kartu), 1, fp);

        pos1 = ((double)nik-(double)k[awal].NIK)/((double)k[akhir].NIK-(double)k[awal].NIK) * ((double)akhir-(double)awal) + (double)awal;
        pos = (int)pos1;
        
        fseek(fp, pos*sizeof(Kartu), SEEK_SET);
        fread(&k[pos], sizeof(Kartu), 1, fp);

        if(k[pos].NIK == nik){
            found = 1;
            break;
        }
        if (k[pos].NIK > nik){
            akhir = pos-1;
            fseek(fp, akhir*sizeof(Kartu), SEEK_SET);
            fread(&k[akhir], sizeof(Kartu), 1, fp);
        } else
        if (k[pos].NIK < nik){
            awal = pos+1;
            fseek(fp, awal*sizeof(Kartu), SEEK_SET);
            fread(&k[awal], sizeof(Kartu), 1, fp);
        }
    } while (nik >= k[awal].NIK && nik <= k[akhir].NIK);

    if(!found){
        printf("NIK tidak ditemukan.\n\n\n");
    }
    else{
        // translate data int menjadi bentuk stringnya
        switch (k[pos].jenisKelamin){
            case 1:
                strcpy(jk, "LAKI-LAKI");
                break;
            case 2:
                strcpy(jk, "PEREMPUAN");
                break;
            }
            switch (k[pos].golDarah){
            case 1:
                strcpy(gd, "O");
                break;
            case 2:
                strcpy(gd, "A");
                break;
            case 3:
                strcpy(gd, "B");
                break;
            case 4:
                strcpy(gd, "AB");
                break;
            }
            switch(k[pos].agama){
            case 1:
                strcpy(agm, "ISLAM");
                break;
            case 2:
                strcpy(agm, "KRISTEN");
                break;
            case 3:
                strcpy(agm, "KATOLIK");
                break;
            case 4:
                strcpy(agm, "BUDHA");
                break;
            case 5:
                strcpy(agm, "HINDU");
                break;
            case 6:
                strcpy(agm, "KONGHUCHU");
                break;
            }
            switch (k[pos].statusPerkawinan){
            case 1:
                strcpy(sp, "BELUM KAWIN");
                break;
            case 2:
                strcpy(sp, "KAWIN");
                break;
            case 3:
                strcpy(sp, "CERAI HIDUP");
                break;
            case 4:
                strcpy(sp, "CERAI MATI");
                break;
            }
            switch (k[pos].kewarganegaraan){
            case 1:
                strcpy(kwn, "WNI");
                break;
            case 2:
                strcpy(kwn, "WNA");
                break;
            }

            // printing
            printf("NIK              : %016lld\n", k[pos].NIK);
            printf("Nama             : %s\n", k[pos].nama);
            printf("Tempat/Tgl Lahir : %s, %s-%s-%s\n", k[pos].tempatLahir, k[pos].tanggalLahir.hari, k[pos].tanggalLahir.bulan, k[pos].tanggalLahir.tahun);
            printf("Jenis kelamin    : %-24sGol. Darah : %s\n", jk, gd);
            printf("Alamat\n");
            printf("    Jalan/Perum  : %s\n", k[pos].alamatRumah.jalan);
            printf("    RT/RW        : %s/%s\n", k[pos].alamatRumah.RT, k[pos].alamatRumah.RW);
            printf("    Kel/Desa     : %s\n", k[pos].alamatRumah.kelurahan);
            printf("    Kecamatan    : %-24sKOTA/KAB %s\n", k[pos].alamatRumah.kecamatan, k[pos].alamatRumah.kota);
            printf("Agama            : %s\n", agm);
            printf("Status Perkawinan: %s\n", sp);
            printf("Pekerjaan        : %s\n", k[pos].pekerjaan);
            printf("Kewarganegaraan  : %s\n\n\n", kwn);
    }

    fclose(fp);
    system("PAUSE");
}

void tampilkan(){
    Kartu k1;
    FILE *fp;
    char jk[11], gd[3], agm[11], sp[15], kwn[5];
    system("cls");
    fp = fopen("dataKTP.bin", "rb");

    // proses menampilkan data
    while(fread(&k1, sizeof(Kartu), 1, fp)){

        // translate data int menjadi bentuk stringnya
        switch (k1.jenisKelamin){
        case 1:
            strcpy(jk, "LAKI-LAKI");
            break;
        case 2:
            strcpy(jk, "PEREMPUAN");
            break;
        }
        switch (k1.golDarah){
        case 1:
            strcpy(gd, "O");
            break;
        case 2:
            strcpy(gd, "A");
            break;
        case 3:
            strcpy(gd, "B");
            break;
        case 4:
            strcpy(gd, "AB");
            break;
        }
        switch(k1.agama){
        case 1:
            strcpy(agm, "ISLAM");
            break;
        case 2:
            strcpy(agm, "KRISTEN");
            break;
        case 3:
            strcpy(agm, "KATOLIK");
            break;
        case 4:
            strcpy(agm, "BUDHA");
            break;
        case 5:
            strcpy(agm, "HINDU");
            break;
        case 6:
            strcpy(agm, "KONGHUCHU");
            break;
        }
        switch (k1.statusPerkawinan){
        case 1:
            strcpy(sp, "BELUM KAWIN");
            break;
        case 2:
            strcpy(sp, "KAWIN");
            break;
        case 3:
            strcpy(sp, "CERAI HIDUP");
            break;
        case 4:
            strcpy(sp, "CERAI MATI");
            break;
        }
        switch (k1.kewarganegaraan){
        case 1:
            strcpy(kwn, "WNI");
            break;
        case 2:
            strcpy(kwn, "WNA");
            break;
        }

        // printing
        printf("NIK              : %016lld\n", k1.NIK);
        printf("Nama             : %s\n", k1.nama);
        printf("Tempat/Tgl Lahir : %s, %s-%s-%s\n", k1.tempatLahir, k1.tanggalLahir.hari, k1.tanggalLahir.bulan, k1.tanggalLahir.tahun);
        printf("Jenis kelamin    : %-24sGol. Darah : %s\n", jk, gd);
        printf("Alamat\n");
        printf("    Jalan/Perum  : %s\n", k1.alamatRumah.jalan);
        printf("    RT/RW        : %s/%s\n", k1.alamatRumah.RT, k1.alamatRumah.RW);
        printf("    Kel/Desa     : %s\n", k1.alamatRumah.kelurahan);
        printf("    Kecamatan    : %-24sKOTA/KAB %s\n", k1.alamatRumah.kecamatan, k1.alamatRumah.kota);
        printf("Agama            : %s\n", agm);
        printf("Status Perkawinan: %s\n", sp);
        printf("Pekerjaan        : %s\n", k1.pekerjaan);
        printf("Kewarganegaraan  : %s\n\n\n", kwn);
    }

    // menghitung jumlah data yang telah tersimpan
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp)/sizeof(Kartu);
    printf("Jumlah data yang tersimpan: %d\n\n\n", n);

    fclose(fp);
    system("PAUSE");
}

void hapus(){
    Kartu k1;
    FILE *fp, *fpTemp;
    int found = 0;
    long long nik;
    system("cls");
    fp = fopen("dataKTP.bin", "rb");
    fpTemp = fopen("temp.bin", "wb");

    // menghitung jumlah data yang telah tersimpan
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp)/sizeof(Kartu);
    printf("Jumlah data yang tersimpan: %d\n\n\n", n);

    // reset fp
    fclose(fp);
    fp = fopen("dataKTP.bin", "rb");

    printf("NIK data yang hendak dihapus: ");
    scanf("%lld", &nik);
    printf("\n");
    while(fread(&k1, sizeof(Kartu), 1, fp)){
        // strcmp() bernilai 0 jika sama, 1 jika berbeda
        if(k1.NIK == nik){
            found = 1;
        }
        else{
            fwrite(&k1, sizeof(Kartu), 1, fpTemp);
        }
    }

    fclose(fp);
    fclose(fpTemp);
    
    if(found){
        fpTemp = fopen("temp.bin", "rb");
        fp = fopen("dataKTP.bin", "wb");
        while (fread(&k1, sizeof(Kartu), 1, fpTemp)){
            fwrite(&k1, sizeof(Kartu), 1, fp);
        }
        
        printf("Data telah berhasil dihapus.\n\n\n");
    }
    else{
        printf("NIK tidak ditemukan.\n\n\n");
    }

    fclose(fp);
    fclose(fpTemp);
    remove("temp.bin");
    system("PAUSE");
}


int main(){
    int ch;
    do{
        menu();
        scanf("%d", &ch);

        switch(ch){
        case 1:
            tambah();
            break;
        case 2:
            cari();
            break;
        case 3:
            tampilkan();
            break;
        case 4:
            hapus();
            break;
        case 0:
            break;
        default:
            printf("input salah.\n");
            system("PAUSE");
            break;
        }
    } while (ch!=0);
    
    return 0;
}