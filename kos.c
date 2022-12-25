/*
Final Project Pemrograman Lanjut E081
Kelompok 7
Nama Anggota:
	21081010254 Shafira Zahrah Hidayat
	21081010255 Ahmad Wahyu Adi Putra
	21081010258 Satria Farras Athallansyah
	21081010259 Raditya Lungguk Satya Putra
	21081010262 Muhammad Rafli Pratama
	21081010266 Achmad Sirajul Fahmi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

//inisialisasi
void input_pemilik();
void update_kos();
void hapus_kos();
void lihat_kos();
void sorttipe();
void sortalamat();
void sortjumkamar();
void sortharga();
void cari_tipe();
void cari_alamat();
void cari_harga();
void lihat_kamar_kosong();
void sewa_kos();

struct kos{
    int id,tipe;
    char alamat[65];
    int jum_penghuni;
    double harga;
	char nama[30];
    double NIK;
}kst, cek, hapus, update[100], del[100], sorts[100], sorts2[100], jual[100], temp;
int min;

void resetMemory(){
    memset(&sorts, 0, sizeof(sorts));
    memset(&sorts2, 0, sizeof(sorts2));
}

void sortingharga(int min, int mid, int maxx){
	//... (fahmi)
}

void mergesortharga(int min, int maxx){
    //...(fahmi)
}

void jumpHarga(struct kos *sorts, int total, double cariharga){
    //...(fahmi)
}

int main(){
    int pilih;
    menu:

    system("cls");
        printf("\n\n\t\t\t\t +==========================================+\n");
        printf("\t\t\t\t |-------------- JURAGAN KOST --------------|\n");
        printf("\t\t\t\t +==========================================+\n");
        printf("\t\t\t\t | [1] Pemilik                              |\n");
        printf("\t\t\t\t | [2] Penyewa                              |\n");
        printf("\t\t\t\t +==========================================+\n");
        printf("\t\t\t\t ==> MASUKKAN PILIHAN SEBAGAI  :               ");
        scanf("%d", &pilih);
        if(pilih == 1){
            pemilik:
            system("cls");
            printf("\n ====== JURAGAN KOST ======\n");
            printf("\n[1] Input kos");
            printf("\n[2] Lihat kos");
            printf("\n[3] Update kos");
            printf("\n[4] Hapus kos");
            printf("\n[5] Lihat urutan");
            printf("\n[6] Cari kos");
            printf("\n[7] Lihat kos Tersewa");
            printf("\n[0] Exit");
            printf("\n\n ==> Masukkan Pilihan : ");
            scanf("%d", &pilih);
            if(pilih == 1){
                input_pemilik();
                goto menu;
            }
            else if(pilih == 2){
                lihat_kos();
            }
            else if(pilih == 3){
                update_kos();
            }
            else if(pilih == 4){
                hapus_kos();
            }
            else if(pilih == 5){
                system("cls");
                printf("\n ====== JURAGAN KOST ======\n");
                printf("\n[1] Urutan berdasarkan Tipe");
                printf("\n[2] Urutan berdasarkan Alamat");
                printf("\n[3] Urutan berdasarkan Jumlah Penghuni Kamar");
                printf("\n[4] Urutan berdasarkan Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    sorttipe();
                }
				else if(pilih == 2){
					sortalamat();
				}
				else if(pilih == 3){
					sortjumkamar();
				}
				else if(pilih == 4){
					sortharga();
				}
                else{
                    goto pemilik;
                }
            }
			else if(pilih == 5){
				system("cls");
                printf("\n ====== JURAGAN KOST ======\n");
                printf("\n[1] Cari Tipe");
                printf("\n[2] Cari Alamat");
                printf("\n[3] Cari Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    cari_tipe();
                }
                else if(pilih == 2){
                    cari_alamat();
                }
                else if(pilih == 3){
                    cari_harga();
                }
                else if(pilih == 0){
                    exit(0);
                }
                else{
                    goto pemilik;
                }
			}
            else if(pilih == 7){
                lihat_kamar_kosong();
            }
            else if(pilih == 0){
                exit(0);
            }
            
        }
        else if(pilih == 2){
            //....(fahmi)
        }
        
        else if(pilih == 3){
            //....(fahmi)
        }
        

void input_pemilik(){
    //... (farras)
}

void lihat_kos(){
	//... (farras)
}


void update_kos(){
    //... (zahrah)
}

void hapus_kos(){
    //... (farras)
}

void sorttipe(){
	//... (radit)
}

void sortalamat(){
	//... (farras)
}

void sortjumkamar(){
	//.. (zahrah)
}

void sortharga(){
	//... (radit)
}

void cari_tipe(){
    //... (rafli)
}

void cari_alamat(){
    //... (rafli)
}

void cari_harga(){
    //... (fahmi)
}

void lihat_kamar_kosong(){
    //... (fahmi)
}

void sewa_kos(){
    //... (fahmi)
}
