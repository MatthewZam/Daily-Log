#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

void title();
void menu();
void exit();
void write_log();
void read_log();


int main(){
	menu();
	return 0;
}

void title(){
	printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
	printf("||                LOG HARIAN                 ||\n");
	printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
}

struct temp0{
	char tanggal[10000];
	char judul[10000];
	char isi[10000];
}temp[10000];

void write_log(){
	title();
	printf("\n  ^^ Masukkan angka '0' untuk kembali ke menu awal");
	sleep(1);
	printf("\n  ^^ Setelah selesai menulis, tekan ENTER untuk menyimpan log harianmu\n");
	sleep(1);
	printf("\n|| Silakan Menulis! ||\n\n");
    FILE *fp;

    char date[1000];
    char filename[20];
	char entry[10000];
	
    printf("|| Masukkan tanggal yang diinginkan: ");
    gets(date);
    
    if(strcmp(date, "0") != 0){
	    printf("|| Judul: ");
	    gets(filename);
	    
	    printf("|| Apa yang terjadi pada hari itu ?\n");
	    printf("|| ");
		gets(entry);
		
	    fp = fopen("log.txt", "ab+");
		fprintf(fp, "%s#%s#%s\n", date, filename, entry);
		fclose(fp);
		
		printf("\n|| Log telah tersimpan!\n");
		sleep(1);	
	}
    
	printf("|| Kembali ke menu awal dalam beberapa detik...\n");
	sleep(1);
}

void read_log(){
	int a;
	
	title();
	FILE *fp = fopen("log.txt", "r");
	
	int check=1;
	
	int i=0;
	while (!feof(fp)){
		fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", temp[i].tanggal, temp[i].judul, temp[i].isi);
		i++;
	}
	fclose(fp);
	
	if (strcmp (temp[0].tanggal, "")!=0){
		check=0;
	}
	
	if (check==0){
		printf("\n|----------------------------------------------------------------|\n");
		printf("|No. |        Tanggal       |             Judul                  |\n");
		printf("|----------------------------------------------------------------|\n");
		for (int j=0; j<i; j++){
			printf("|%d.  |%-20s|%-36s  |\n", j+1, temp[j].tanggal, temp[j].judul);
		}
		printf("|----------------------------------------------------------------|\n");
		
		int pilihan;
		printf("\n  ^^ Masukkan angka '0' untuk kembali ke menu awal\n");
		sleep(1);
		printf("\n  ^^ Pilih log harian yang ingin dibaca: ");
		scanf("%d", &pilihan);
		getchar();
		
		switch (pilihan){
			case 0:
				printf("  ^^ Kembali ke menu awal dalam beberapa detik...\n");
				sleep(1);
				system("cls");
				menu();
				break;
		}
		
		system("cls");
		
		title();
		printf("\n");
		printf(">> Kamu sedang membaca log no. %d\n", pilihan);
		for (int j=0; j<1; j++){
			printf("   |Tanggal: %s\n   |Judul  : %s\n", temp[pilihan-1].tanggal, temp[pilihan-1].judul);
			printf("   |Isi    : %s\n", temp[pilihan-1].isi);
	}
		sleep(2);
		printf("\n  ^^ Selesai Membaca.\n");
		printf("  ^^ Masukkan ENTER untuk kembali ke menu awal.\n");
	}
	else {
	printf("\n  Belum ada log harian yang tersedia!\n");
	printf("  Masukkan ENTER untuk kembali ke menu awal.\n");
	}
}

void exit(){
	system("cls");
	printf("\n\n-------------------------\n");
	printf("----- SAMPAI JUMPA! -----\n");
	printf("-------------------------\n\n");
}

void menu(){
	int choice;
	
	begin:
	title();
	
	do{
		printf("\n(1) Tulis Log Harian\n");
		printf("(2) Baca Log Harian\n");
		printf("(3) Keluar\n");
		printf("\nPilih: ");
		
		scanf("%d", &choice);
		getchar();
		
		system("cls");
		
		switch (choice){
			case 1:
				write_log();
				sleep(1);
				system("cls");
				goto begin;
				break;
			case 2:
				read_log();
				getchar();
				system("cls");
				goto begin;
				break;
		
			case 3:
				exit();
		}
	} while (choice < 0 || choice > 4);
	}
