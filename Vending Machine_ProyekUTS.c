#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
 
typedef char * string; /*membuat suatu tipe data baru bernama string dengan basis tipe data char*/
char *p, s[100];	/*membuat parameter array untuk mendeteksi input char*/
string Produk[2][10]= /*Mendeclare elemen Array, dengan dimensi pertama untuk menunjukan kategori Minuman(0) dan Makanan(1) yang masing-masing berjumlah 10*/
{{"Hilo","Good Day","Pocari Sweat","Nu Milk Tea","Teh Botol","Floridina","MYTEA","Milo","Fruit Tea","Aqua"},
{"Beng-Beng","Snicker","Pop Mie","Tobleron","Richeese","Oreo","Sari Roti Sandwich","Cheetos","Taro","Soy Joy"}};/*Membuat array string*/
    //int Stok[2][10]={{9,10,7,10,8,4,10,9,10,6},{10,8,5,10,7,10,8,10,10,6}};
    int Harga[2][10]={{7000,7000,6000,6000,4000,3000,6000,5000,6000,3000},{2000,8000,5000,10000,2000,6000,5000,2000,2000,5000}};

int Stok[2][10];
int i,j;
int uang,saldo,pilihan;

int main(){
	
	FILE *vendingmachine;
    vendingmachine = fopen("vendingmachine.txt", "r");

    //read file kedalam array
 
	
	fscanf(vendingmachine, "%d",&saldo);
    for (i = 0; i < 2; i++)
    {
    	for(j=0;j<10;j++){
        fscanf(vendingmachine, "%d", &Stok[i][j]);
   		}
	}
	menu();
}


int menu(){
		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||||||                           VENDING MACHINE Minuman & Makanan                      |||||||\n");
	printf("|||||||                                   Teuku & Guna Corp.                             |||||||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("Silahkan pilih menu yang diinginkan (tekan tombol sesuai huruf pada menu yang diinginkan) :\n\n");
	
		printf("|Kode|   Minuman     | Harga | Stok |    |Kode|      Makanan       | Harga | Stok\n");
        for(i=0;i<10;i++){ /*Print keseluruhan menu*/
        	printf("[%2d ]%14s  (%5d) %5d        [%2d] %18s  (%5d) %5d\n",i+1,Produk[0][i],Harga[0][i],Stok[0][i],i+1,Produk[1][i],Harga[1][i],Stok[1][i]);	
		}
printf("Saldo Anda : Rp %d",saldo);
printf("\n\na. Masukkan uang\nb. Beli Minuman\nc. Beli Makanan\nd. Petunjuk dan Informasi\n\n");
	
FILE *out=fopen("vendingmachine.txt","w");
	fprintf(out,"%d\n",saldo);
    for (i = 0; i < 2; i++)
    {
    	for(j=0;j<10;j++){
        fprintf(out,"%d\n",Stok[i][j]);
   		}
   }
 fclose(out);

switch(getch()){
	case 'a':
		masukanuang();
		break;
	case 'b':
		beli1();
		break;
	case 'c':
		beli2();
		break;
	case 'd':
		help();
		break;
	default :
		system("cls");
		return menu();
}		
}


void beli1(){/*fungsi untuk membeli dalam kategori minuman*/
	printf("\nSilahkan pilih minuman yang ingin dibeli.\n");
	printf("(Masukan angka 0 untuk kembali ke menu utama.)\n");
	
	    while (fgets(s, sizeof(s), stdin)) {
        pilihan = strtol(s, &p, 10);
        if (p == s ) {
            printf("Maaf input invalid, mohon masukan kode menu berupa integer. (Masukan angka 0 untuk kembali ke menu utama)\n");
        } 
		else{
		break;}
    }
			if(pilihan == 0){/*pilihan kembali ke menu utama*/
				system("cls");
				menu();
			}
			else if(pilihan>0 && pilihan<11){/*pilihan minuman tersedia dalam menu*/
				if(Stok[0][pilihan -1]<1){
				printf("maaf stok %s habis\n",Produk[0][pilihan - 1]);
				}			
				else if (saldo >= Harga[0][pilihan -1])
				{Stok[0][pilihan -1] = Stok[0][pilihan -1] - 1;
				saldo -= Harga[0][pilihan -1];
				printf("%s terbeli\n",Produk[0][pilihan -1]);
				}
				else{
				printf("Maaf saldo anda tidak cukup untuk %s(%d)\n",Produk[0][pilihan -1],Harga[0][pilihan -1]);
				}
			}
			else {
				printf("Maaf input invalid,mohon masukan kode menu yang tersedia\n");
			}
			
			printf("Uang anda: %d \n", saldo);		
		system("pause");
	return beli1();
}

void beli2(){/*fungsi untuk membeli dalam kategori makanan*/
	printf("\nSilahkan pilih makanan yang ingin dibeli. \n");
	printf("(Masukan angka 0 untuk kembali ke menu utama.)\n");
	
	    while (fgets(s, sizeof(s), stdin)) {
        pilihan = strtol(s, &p, 10);
        if (p == s) {
            printf("Maaf input invalid, mohon masukan kode menu berupa integer. (Masukan angka 0 untuk kembali ke menu utama.)\n");
        } 
		else{
		break;}
    }
	
			if(pilihan == 0){/*pilihan kembali ke menu utama*/
				system("cls");
				menu();
			}
			else if(pilihan>0 && pilihan<11){/*pilihan makanan tersedia dalam menu*/
				if(Stok[1][pilihan -1]<1){
				printf("Maaf stok %s habis\n",Produk[1][pilihan - 1]);
				}			
				else if (saldo >= Harga[1][pilihan -1])
				{Stok[1][pilihan -1] = Stok[1][pilihan -1] - 1;
				saldo -= Harga[1][pilihan -1];
				printf("%s terbeli\n",Produk[1][pilihan -1]);
				}
				else{
				printf("Maaf saldo anda tidak cukup untuk %s(%d)\n",Produk[1][pilihan -1],Harga[1][pilihan -1]);
				}
			}
			else {
				printf("Maaf input invalid, mohon masukan kode menu yang tersedia\n");
			}
			
			printf("Uang anda: %d \n", saldo);		
	system("pause");
	return beli2();
	
}

help(){
	printf("|||Petunjuk dan Informasi: |||\n");
	printf("Petunujuk Penggunaan: \n 1.Pilih menu Masukan Uang untuk menambah Saldo dengan menekan tombol a pada menu.\n");
	printf(" 2.Masukan jumlah uang dalam pecahan 2.000,5.000,10.000,20.000,50.000, atau 100.000, lalu tekan Enter (program ini tidak menerima pecahan lain)\n");
	printf(" 3.Pilih kategori Makanan atau Minuman\n");
	printf(" 4.Masukan kode angka Makanan atau Minuman sesuai menu, lalu tekan Enter. Masukan 0 apabila ingin kembali ke menu utama.\n");
	printf(" 5.Apabila saldo habis, silakan mengisi saldo kembali pada menu Masukan Uang.\n\n");
	printf("|||Informasi Program: |||\n");
	printf(" Program 'Vending Machine' bertujuan sebagai program simulasi mesin penjual Minuman & Makanan otomatis \n dengan berbagai menu dan fitur yang menyerupai vending machine sesungguhnya.\n");
	printf(" Program ini dikembangkan oleh Teuku Salman Farizi (NPM: 1706043216) dan Guna Suryo Aji (NPM: 1706043222) pada bulan oktober 2018 \n dalam rangka penyelesaian Proyek 1 matakuliah Pemrograman Lanjut Teknik Komputer, Departemen Teknik Elektro, Fakultas Teknik Universitas Indonesia.\n");
	
	system("pause");
	system("cls");
	return menu();
}

masukanuang(){	
	printf("\n Masukan uang anda (Masukan 0 untuk batal) :\n");
	
    while (fgets(s, sizeof(s), stdin)) {
        uang = strtol(s, &p, 10);
        if (p == s) {
            printf("Maaf input invalid, mohon masukan jumlah uang berupa integer. (Masukan angka 0 untuk kembali ke menu utama.)\n");
        } 
		else{
		break;}
    }
if(uang==0 ||uang==1000||uang==2000||uang==5000||uang==10000||uang==20000||uang==50000||uang==100000){
	saldo += uang;
	printf("Anda memasukkan %d Rupiah\n",uang);
	uang=0;
	system("pause");
}else{printf("Maaf, uang yang anda masukkan tidak valid.\nSilahkan masukkan uang Rupiah 1.000,2.000,5.000,10.000,20.000,50.000, atau 100.000.\n (Masukan 0 untuk kembali ke menu utama.)\n");
switch(getch()){
	case '0':
		system("cls");
		menu();
		break;
	default :
	masukanuang();
		break;
}
masukanuang();
}
	system("cls");
	menu();
}


