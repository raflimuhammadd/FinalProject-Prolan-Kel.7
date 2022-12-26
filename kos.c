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
void close();

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
    int x, y, i = 0;
	for(x = min, y = mid + 1, i = min; x <= mid && y <= maxx; i++){
		if(sorts[x].harga < sorts[y].harga){
			sorts2[i] = sorts[x];
			x++;
		}
		else{
			sorts2[i] = sorts[y];
			y++;
		}
	}
	while(x <= mid){
		sorts2[i] = sorts[x];
		x++;
		i++;
	}
	while(y <= maxx){
		sorts2[i] = sorts[y];
		y++;
		i++;
	}
	for(i = min; i <= maxx; i++){
		sorts[i] = sorts2[i];
	}
}

void mergesortharga(int min, int maxx){
    int mid;
    if(min < maxx){
        mid = (min + maxx)/2;
        mergesortharga(min, mid);
        mergesortharga(mid+1, maxx);
        sortingharga(min, mid, maxx);
    }
    else{
        return;
    }
}

void jumpHarga(struct kos *sorts, int total, double cariharga){
    int jump = sqrt(total);
    int jumper = jump;
    int prev = 0, simpan;
    int i, flag = 0;

    if((cariharga < sorts[0].harga) || (cariharga > sorts[total].harga)){
        printf("\n==> Harga tidak ditemukan!");
        return;
    }
    else{
        while((sorts[jumper].harga <= cariharga) && jumper < total){
            prev = jumper;
            jumper += jump;
            
            if(jumper >= total + total){
                printf("Harga Not Found!");
            }
        }

        for(i = prev; i <= jumper; i++){
            if(sorts[i].harga == cariharga){
                flag = 1;
                simpan = i;
            }
        }

        if(flag == 1){
            printf("%d\t%d\t%s\t%d\t%.lf \n", sorts[simpan].id, sorts[simpan].tipe, sorts[simpan].alamat, sorts[simpan].jum_penghuni , sorts[simpan].harga);
        }
        else{
            printf("Hargaa Not Found!");
        }
    }
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
			penyewa:
            system("cls");
            printf("\n ====== JURAGAN KOST ======\n");
            printf("\n[1] Lihat Kos");
            printf("\n[2] Lihat urutan");
            printf("\n[3] Cari kos");
            printf("\n[4] Sewa kos");
            printf("\n[0] Exit");
            printf("\n\n ==> Masukkan Pilihan : ");
            scanf("%d", &pilih);
			if(pilih == 1){
				lihat_kos();
			}
			else if(pilih == 2){
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
                    goto penyewa;
                }
			}
			else if(pilih == 3){
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
                    goto penyewa;
                }
            }
			else if(pilih == 4){
                sewa_kos();
            }
			else if(pilih == 0){
				exit(0);
			}
        }
		else{
			printf("Input Salah!");
			erase_valid:
		    printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
            switch(getch()){
                case '1': 
                    main();
                    break;
                case '0': 
                    close();
                    break;
                default:printf("\nMaaf Kesalahan Input !");
                    getche();
                    goto erase_valid;
            }
		}
}
        

void input_pemilik(){
    FILE *fptr, *fptr1;
    int count=0;
    
    fptr=fopen("JURAGANKOS.txt","a");
    system("cls");
    fptr1=fopen("JURAGANKOS.txt","r");
    while (fscanf(fptr1,"%d %d %[^;]; %d %lf",&kst.id,&kst.tipe,kst.alamat,&kst.jum_penghuni,&kst.harga)!=EOF)
		{
			kst.id++;	
		}
		cek.id = kst.id;
		fclose(fptr1);
		printf("\n ======= JURAGAN KOST =======\n");
		printf ("\nMasukan Tipe kos\t\t: ");fflush(stdin);
		scanf ("%d", &kst.tipe);
		printf ("\nMasukan Alamat\t\t\t: ");fflush(stdin);
		gets(kst.alamat);
		printf("\nJumlah Penghuni Kamar\t\t: ");fflush(stdin);
		scanf("%d", &kst.jum_penghuni);
        printf("\nHarga yang akan disewakan\t: ");
		scanf("%lf", &kst.harga);
		fprintf(fptr,"%d %d %s; %d %lf \n",kst.id,kst.tipe,kst.alamat,kst.jum_penghuni,kst.harga);
		fclose(fptr);
		printf("\n\nData Telah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': 
				main();
        		break;
        	case '0': 
				close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}


void lihat_kos(){
	system("cls");
    FILE *view;
	int test=0;
	view=fopen("JURAGANKOS.txt","r");
	printf("\n================ JURAGAN KOST ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga");
	while(fscanf(view,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni, &kst.harga)!=EOF)
		{
			printf("%d\t%d\t%s\t%d\t%.lf \n", kst.id, kst.tipe, kst.alamat, kst.jum_penghuni, kst.harga);
			test++;
		}
	printf("\n");
	printf("\nBanyak kos Yang Tersedia : %d ", test);
	fclose(view);
		if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': main();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}


void update_kos(){
    int pilih,test=0, count = 0, i = 0, j;
	FILE *lama,*baru;
	lama = fopen("JURAGANKOS.txt","r");
	baru = fopen("JURAGANBARU.txt","w");
	system("cls");
	printf("\n ====== JURAGAN KOST ======\n");
	printf ("\nMasukan ID kos Yang Akan Diubah : ");
	scanf ("%d",&cek.id);
	while(fscanf(lama, "%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni ,&kst.harga)!=EOF){
		update[count].tipe = kst.tipe;
		update[count].jum_penghuni = kst.jum_penghuni;
		update[count].id = kst.id;
		update[count].harga = kst.harga;
		strcpy(update[count].alamat ,kst.alamat);
		count++;
	}
	while(i <= count){
		if(update[i].id == cek.id){
			test=1;
			ganti:
				system("cls");
				printf("\n ====== JURAGAN KOST ======\n");
				printf("\nkos DENGAN ID : %d AKAN DIUPDATE!", update[i].id);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1] Tipe");
				printf("\n[2] Alamat");
				printf("\n[3] Jumlah Penghuni Kamar");
                		printf("\n[4] Harga kos");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);

}


void hapus_kos(){
    //... (radit)
}

void sorttipe(){
	//... (radit)
}

void sortalamat(){
	system("cls");
	FILE *alamat;
	int count=0,i,j,test=0,pilih;
	system("cls");
	alamat=fopen("JURAGANKOS.txt","r");
	while(fscanf(alamat,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni , &kst.harga)!=EOF) {
		sorts[count].tipe = kst.tipe;
		sorts[count].jum_penghuni = kst.jum_penghuni;
		sorts[count].id = kst.id;
		sorts[count].harga = kst.harga;
		strcpy(sorts[count].alamat ,kst.alamat);
		count++;
		test=1;
	}	

	for(i = 1; i <= count; i++){
		sorts2[i] = sorts[i];
    	j = i - 1;
        while(j >= 0 && (strcmp(sorts[j].alamat, sorts2[i].alamat) > 0)){
                sorts[j+1] = sorts[j];
                j--;
        }
		sorts[j+1] = sorts2[i];
    }
	printf("\n================ JURAGAN KOST ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga");
	for(i = 1; i <= count; i++){
		printf("%d\t%d\t%s\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].jum_penghuni, sorts[i].harga);
	}

    resetMemory();
	fclose(alamat);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sortalamat();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}

void sortjumkamar(){
	system("cls");
	FILE *sorttidur;
	int count=0,i,j,test=0,pilih;
	system("cls");
	sorttidur=fopen("JURAGANKOS.txt","r");
	while(fscanf(sorttidur,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni , &kst.harga)!=EOF) {
		sorts[count].tipe = kst.tipe;
		sorts[count].jum_penghuni = kst.jum_penghuni;
		sorts[count].id = kst.id;
		sorts[count].harga = kst.harga;
		strcpy(sorts[count].alamat ,kst.alamat);
		count++;
		test=1;
	}	

	for(i = 1; i <= count; i++){
		sorts2[i] = sorts[i];
    	j = i - 1;
        while(j >= 0 && sorts[j].jum_penghuni > sorts2[i].jum_penghuni){
                sorts[j+1] = sorts[j];
                j--;
        }
		sorts[j+1] = sorts2[i];
    }
	printf("\n================ JURAGAN KOST ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga");
	for(i = 1; i <= count; i++){
		printf("%d\t%d\t%s\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].jum_penghuni , sorts[i].harga);
	}

    resetMemory();
	fclose(sorttidur);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sortjumkamar();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void sortharga(){
	//... (radit)
}

void cari_tipe(){
    system("cls");
	FILE *cartip;
	int count=0,i,j = 0,test=0, caritipe, flag = 0;
	system("cls");
	cartip=fopen("JURAGANKOS.txt","r");
	while(fscanf(cartip,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni , &kst.harga)!=EOF) {
		sorts[count].tipe = kst.tipe;
		sorts[count].jum_penghuni = kst.jum_penghuni;
		sorts[count].id = kst.id;
		sorts[count].harga = kst.harga;
		strcpy(sorts[count].alamat ,kst.alamat);
        count++;
		test=1;
	}
    int simpan[count];	
	
	printf("==============   PENCARIAN DATA   =============\n\n");
    printf("\nMasukkan TIPE yang Dicari : ");
    scanf("%d", &caritipe);
	
    for(i = 0; i < count; i++){
        if(sorts[i].tipe == caritipe){
            simpan[j] = i;
            flag = 1;
            j++;
        }
    }
    printf("\n%s\t%s\t%s\t\t%s\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga");
    if(flag == 1){
        for(i = 0; i <= j-1; i++){
            printf("%d\t%d\t%s\t\t%d\t%.lf \n", sorts[simpan[i]].id, sorts[simpan[i]].tipe, sorts[simpan[i]].alamat, sorts[simpan[i]].jum_penghuni , sorts[simpan[i]].harga);
        }
    }
    else{
        printf("Data Tipe Not Found!");
    }
	
    resetMemory();
	fclose(cartip);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					cari_tipe();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama, 2 untuk coba lagi, and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
            case '2':
                cari_tipe();
                break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void cari_alamat(){
    system("cls");
	FILE *alamatt;
	int count=0,i,j,test=0,pilih;
    char carialamat[60];
	system("cls");
	alamatt = fopen("JURAGANKOS.txt","r");
	while(fscanf(alamatt,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni ,&kst.harga)!=EOF) {
		sorts[count].tipe = kst.tipe;
		sorts[count].jum_penghuni = kst.jum_penghuni;
		sorts[count].id = kst.id;
		sorts[count].harga = kst.harga;
		strcpy(sorts[count].alamat ,kst.alamat);
		count++;
		test=1;
	}	

	for(i = 1; i <= count; i++){
		sorts2[i] = sorts[i];
    	j = i - 1;
        while(j >= 0 && (strcmp(sorts[j].alamat, sorts2[i].alamat) > 0)){
                sorts[j+1] = sorts[j];
                j--;
        }
		sorts[j+1] = sorts2[i];
    }
	
    fflush(stdin);
    printf("==============   PENCARIAN DATA   =============\n\n");
    printf("\nMasukkan Alamat yang Dicari : ");
    gets(carialamat);
    int mid, low = 0, flag =0, high = count;
    while(low <= high && flag == 0){
        mid = (low + high)/2;
        if((strcmp(sorts[mid].alamat, carialamat) == 0)){
            flag = 1;
        }
        else if((strcmp(carialamat, sorts[mid].alamat) > 0)){
            high = high;
            low = mid + 1;
        }
        else{
            low = low;
            high = mid - 1;
        }
    }
    printf("\n%s\t%s\t%s\t\t%s\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga");
    if(flag == 1){
        printf("%d\t%d\t%s\t\t%d\t%.lf \n", sorts[mid].id, sorts[mid].tipe, sorts[mid].alamat, sorts[mid].jum_penghuni , sorts[mid].harga);
    }
    else{
        printf("Data Alamat kos Not Found!");
    }

    resetMemory();
	fclose(alamatt);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					cari_alamat();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama, 2 coba lagi, and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
            case '2':
                cari_alamat();
                break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void cari_harga(){
    system("cls");
	double cariharga;
	FILE *hargaaa;
	int count=0,i,j,pilih;
	system("cls");
	hargaaa=fopen("JURAGANKOS.txt","r");
	while(fscanf(hargaaa,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni ,&kst.harga)!=EOF) {
		sorts[count].tipe = kst.tipe;
		sorts[count].jum_penghuni = kst.jum_penghuni;
		sorts[count].id = kst.id;
		sorts[count].harga = kst.harga;
		strcpy(sorts[count].alamat ,kst.alamat);
		count++;
	}	
	mergesortharga(0, count);
    printf("==============   PENCARIAN DATA   =============\n\n");
    printf("\nMasukkan Harga yang Dicari : ");
    scanf("%lf", &cariharga);
    printf("\n%s\t%s\t%s\t\t%s\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga");
	jumpHarga(sorts, count, cariharga);
    resetMemory();
	fclose(hargaaa);
    if(count == 0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					cari_harga();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama, 2 untuk ulang, and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
            case '2':
                cari_harga();
                break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void lihat_kamar_kosong(){
	    system("cls");
    FILE *lihat_kamar_kosong;
	int test=0;
	lihat_kamar_kosong = fopen("JURAGANSEWA.txt","r");
	printf("\n================ JURAGAN KOST ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s \n\n", "ID","Tipe", "Alamat", "J.kamar", "Harga", "Nama", "NIK");
	while(fscanf(lihat_kamar_kosong,"%d %d %[^;]; %d %lf %[^;]; %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni , &kst.harga, kst.nama, &kst.NIK)!=EOF){
            printf("%d\t%d\t%s\t%d\t%.lf\t%s\t%.lf\n", kst.id, kst.tipe, kst.alamat, kst.jum_penghuni ,kst.harga, kst.nama, kst.NIK);
            test++;
		}
	printf("\n");
	printf("\nBanyak kos Yang Terjual : %d ", test);
	fclose(lihat_kamar_kosong);

    memset(&kst, 0, sizeof(kst));
	if(test==0){
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': main();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
    

void sewa_kos(){
    FILE *lama, *baru, *jual;
    int test=0, count = 0;
    lama = fopen("JURAGANKOS.txt","r");
	baru = fopen("JURAGANBARU.txt","w");
    jual = fopen("JURAGANSEWA.txt", "a");
    system("cls");
    printf("=============== SEWA kos ===============\n\n");
    printf("Input No.Id kos yang akan disewakan : ");
    scanf("%d", &hapus.id);
    while(fscanf(lama,"%d %d %[^;]; %d %lf",&kst.id, &kst.tipe, kst.alamat, &kst.jum_penghuni , &kst.harga)!=EOF){
        if(kst.id != hapus.id){
            del[count].id = kst.id;
            del[count].tipe = kst.tipe;
            strcpy(del[count].alamat, kst.alamat);
            del[count].jum_penghuni = kst.jum_penghuni;
            del[count].harga = kst.harga;
            fprintf(baru,"%d %d %s; %d %lf\n",del[count].id, del[count].tipe, del[count].alamat, del[count].jum_penghuni, del[count].harga);
            count++;
        }
        else if(kst.id == hapus.id){
            fflush(stdin);
            printf("\nMasukkan Nama : ");
            gets(del[count].nama);
            printf("\nMasukkan NIK  : ");
            scanf("%lf", &del[count].NIK);
            del[count].id = kst.id;
            del[count].tipe = kst.tipe;
            strcpy(del[count].alamat, kst.alamat);
            del[count].jum_penghuni = kst.jum_penghuni;
            del[count].harga = kst.harga;
            fprintf(jual,"%d %d %s; %d %lf %s; %lf\n",del[count].id, del[count].tipe, del[count].alamat, del[count].jum_penghuni, del[count].harga, del[count].nama, del[count].NIK);
            count++;
            test++;
            printf("kos Telah Dibeli!");
		}
        else{
            test++;
            printf("\nData kos No ID : %d dengan Alamat : %s\n",kst.id,kst.alamat);
			printf("\nBerhasil dihapus dari Daftar !");
            count++;
        }
    }
    memset(&del, 0, sizeof(del));
    fclose(jual);
    fclose(lama);
	fclose(baru);
	remove("JURAGANKOS.txt");
	rename("JURAGANBARU.txt","JURAGANKOS.txt");
	if(test==0){   
		system("cls");
        printf("\nMaaf, Data tidak dapat ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': sewa_kos();
            	break;
            case '1': main();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama, 2 beli lagi, dan 0 untuk keluar :");
        switch(getch()){
        	case '1': main();
        		break;
            case '2': sewa_kos();
                break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}
