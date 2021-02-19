/* TIC TAC TOE GAME
	Contributor :
	- Mochammad Daffa Faqiha Fawwaz Hanjowo - 201524051
	- Temmy Mahesa Ridwan - 201524062
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define HIGHSCORE_FILENAME "scorehistory.dat"

/* Modul Menu*/
void pilihGrid();
void pilihMode();
void pilihLevel();
void jumlahRonde();
void playTicTacToe();
void namaPermainan();
void scoreHistory();

/*Modul Grid tic tac toe*/
void grid3();
void grid5();
void grid7();

void persiapanGrid();
void tampilkanGrid();

/*Modul apabila melawan komputer*/
void gridCOM3();
void gridCOM5();
void gridCOM7();

void computer(int x, int y);
void mudah(int x, int y);
void sedang();
void sulit();

/*Modul apabila melawan player*/

void gridVS3();
void gridVS5();
void gridVS7();

void pemain1(int *i, int *j);
void pemain2(int i, int j);

/*Modul proses ronde*/
void giliran1();
void giliran2();
void giliran3();

/*Modul cek kolom, baris, diagonal agar computer tidak memiliki bug seperti menempatkan tanda ditempat yang sama*/
void barKos(int *i, int *j);
void kolKos(int *i, int *j);
void diagKanan(int *i, int *j);
void diagKiri(int *i, int *j);

bool cekGrid(int i, int j);
bool cekPenuh();

/*cek kolom, baris, diagonal untuk computer*/
bool cekBarisX();
bool cekKolomX();
bool cekKanan();
bool cekKiri();


/*untuk mengecek apakah sudah ada 1 deret baris atau  kolom atau diagonal di grid 3 x 3*/
bool deretBaris1();
bool deretKolom1();
bool deretDiag1();

/*untuk mengecek apakah sudah ada 1 deret baris atau  kolom atau diagonal di grid 5 x 5*/
bool deretBaris2();
bool deretKolom2();
bool deretDiag2();

/*untuk mengecek apakah sudah ada 1 deret baris atau  kolom atau diagonal di grid 7 x 7*/
bool deretBaris3();
bool deretKolom3();
bool deretDiag3();

/*modul game over*/
void tampilkanMenang1();
void tampilkanMenang2();
void tampilkanKalah();

/*data highscore*/
int GetData();
void writeData();

/*timer
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo*/
int starttime();
int endtime();

typedef struct {
	char namaGame[21];
	int rondePlayer1;
	int rondePlayer2;
	char gridPermainan[8];
} HighscoreData;

/*variable global*/
int g, m, l, r, size;
char nama[21];
int	player1, player2;
int papan[8][8];
HighscoreData data;

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo dan Temmy Mahesa Ridwan
Deskripsi : badan program dimana awal - awal program di mulai
I.S : program belum berjalan
F.S : Program berhenti
versi : 
*/
int main(){
	int pilihmenu;
menu :
		system("cls");
		printf("========TIC TAC TOE========\n");
		printf("1. Start Game!\n");
		printf("2. Score History\n");
		printf("3. Bantuan Singkat\n");
		printf("4. Credit\n");
		printf("5. Keluar !!\n");
		printf("Masukan Menu :");
		scanf("%d", &pilihmenu);
		
//		system("cls");
		switch(pilihmenu){
			case 1:
				namaPermainan();
				break;
			case 2:
				scoreHistory();
				break;
			case 3:
				system("cls");
				printf("1. untuk memulai permainan \n");
				printf("2. untuk melihat data permainan yang terakhir di mainkan \n");
				printf("3. halaman ini yang sedang kau baca \n");
				printf("4. membuka halaman credit \n");
				printf("5. gtfo \n");
				system("pause");
				goto menu;
				break;
			case 4:
				system("cls");
				printf("Temmy Mahesa Ridwan - 201524062\n");
				printf("Mochammad Daffa Faqiha Fawwaz Hanjowo - 201524051\n");
				printf("D4 - Teknik Informatika\n");
				printf("JTK 2020/2021");
				system("pause");
				goto menu;
				break;
			case 5:
				printf("Yaah.. mau keluar permainan ya :(");
				printf("yaudah deh, Bye Bye !");
				break;
			default :
				system("cls");
				printf("tidak ada \n");
			
				system("pause");
				goto menu;
		}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : memberi nama Permainan untuk di salin ke score history
I.S : variabel nama masih null / belum di kasih nama
output: variable nama sudah di isi
*/
void namaPermainan(){
	system("cls");
	printf("(Maksimal 21 Karakter)\n");
	printf("Masukan Nama Permainan : \n");
	scanf("%s", &nama);
	pilihGrid();
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : untuk memilih grid yang akan di pakai
I.S : variable grid belum di tentukan
F.S : variable grid sudah di tentukan
*/
void pilihGrid(){
	system("cls");
	printf("========TIC TAC TOE========\n");
	printf("Pilih Papan Grid :\n");
	printf("1. 3 x 3\n");
	printf("2. 5 x 5\n");
	printf("3. 7 x 7\n");
	scanf("%d", &g);
	
	if(g > 3){
		printf("Mohon maaf, grid tidak ada :'(\n");
		system("pause");
		pilihGrid();
//		getch();
	}else{
		pilihMode();
	}
	
	
}
/*
Author : Temmy Mahesa Ridwan
Deskripsi : memilih lawan, apakah bermain dengan komputer atau player 
I.S : lawan belum di pilih
F.S : lawan sudah di pilih
*/
void pilihMode(){
	system("cls");
	printf("========TIC TAC TOE========\n");
	printf("Mau bermain dengan Siapa ??\n");
	printf("1. vs Komputer\n");
	printf("2. vs Player\n");
	printf("3. Kembali ke halaman sebelumnya\n");;
	scanf("%d", &m);
	
	if(m == 1){
		printf("Semoga Beruntung untuk melawan Komputer! ;)\n");
		system("pause");
		pilihLevel();
		
	}else if(m == 2){
		printf("Semoga menyenangkan! melawan Player :D\n");
		system("pause");
		jumlahRonde();
		
	}else if(m==3){
		pilihGrid();
	}
	else{
		printf("Mau lawan siapa lagi kalo bukan Komputer atau player ?\n");
		system("pause");
		pilihMode();
//		getch();
	}

}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : bila melawan computer maka akan di tampilkan pilihan tingkatan level
I.S : level computer belum di pilih
F.S : level computer sudah di pilih
*/
void pilihLevel(){
	system("cls");
	printf("==============TIC TAC TOE================\n");
	printf("Pilih level komputer yang akan anda lawan\n");
	printf("1. Mudah\n");
	printf("2. Sedang\n");
	printf("3. Sulit\n");
	printf("4. Kembali ke halaman sebelumnya\n");
	scanf("%d", &l);
	switch(l){
		case 1:
			printf("Meskipun lawan mudah yang penting menang :VVV\n");
			system("pause");
			jumlahRonde();
			break;
		case 2:
			printf("Wow! anda lumayan menantang ya, lawan level Sedang\n");
			system("pause");
			jumlahRonde();
			break;
		case 3:
			printf("Waah... Berani sekali anda melawan level Sulit, Semoga beruntung\n");
			system("pause");
			jumlahRonde();
			break;
		case 4:
			pilihMode();
			break;
		default:
			printf("Wo wo wo woow tahan.... tidak ada level lain selain 3 di atas\n");
			system("pause");
			pilihLevel();
	}
}
/*
Author : Temmy Mahesa Ridwan
Deskripsi : memilih jumlah ronde yang akan di mainkan
I.S : jumlah ronde belum di tentukan
F.S : jumlah ronde sudah di tentukan
*/
void jumlahRonde(){
	system("cls");
	printf("========TIC TAC TOE========\n");
	printf("Mau bermain berapa ronde untuk di menangi ??\n");
	printf("1. 3\n");
	printf("2. 4\n");
	printf("3. 5\n");
	printf("4. Kembali ke halaman sebelumnya\n");
	scanf("%d", &r);
	
	if(r>4){
		printf("5 aja sudah banyak ;)");
		system("pause");
		jumlahRonde();
	}else if(r == 4){
		pilihLevel();
	}else{
		playTicTacToe();
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : memulai memilah mengambil inputan dari pilihGrid
I.S :  belum bermain
F.S : bermain sesuai grid
*/
void playTicTacToe(){
	if(g == 1){
		grid3();
	}else if(g == 2){
		grid5();
	}else if(g == 3){
		grid7();
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : pengeksekusian apakah bermain dengan computer atau player sesuai dengan inputan di pilih mode
I.S : lawan belum di tentukan
F.S : lawan sudah di tentukan
*/
void grid3(){
	switch(m){
		case 1:
			gridCOM3();
			break;
		case 2:
			gridVS3();
			break;
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : mempersiapkan grid lalu bermain
I.S : grid belum siap, dan giliran belum di bagikan
F.S : grid sudah siap tampil, giliran sudah di bagikan
*/
void gridCOM3(){
	size = 4;
	persiapanGrid();
	giliran1();
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : untuk mempersiapkan grid yang akan di pakai
I.S : grid belum di siapkan
F.S : grid sudah di siapkan
*/
void persiapanGrid(){
	int i, j;
	system("cls");
	char papBar = '0';
	char papKol = '1';
	printf("~| Score player 1 : %d     -=-=-     %d : Score player 2 |~\n", player1, player2);
	for (i = 0; i< size;i++){
		for(j=0; j< size; j++){
			if(i==0){
				papan[i][j]= papBar;
				papBar++;
			}else if(j==0){
				papan[i][j]= papKol;
				papKol++;
			}
			else{
				papan[i][j]='#';
            }
        printf("%c | ", papan[i][j]);
		}
    printf("\n");
	}
}


/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kolom
I.S : kolom belum di check
F.S : kolom sudah di check
output : false apabila 1 deret kolom terisi, dan true apa bila belum terisi
*/
bool deretKolom1(){
	int i;
	for (i = 1; i < size; i++){
		if (papan[1][i]== 'X'&& papan[2][i]=='X'&& papan[3][i]=='X'){
			return false;
		}else if (papan[1][i]== 'O'&& papan[2][i]=='O'&& papan[3][i]=='O'){
			return false;
		}
	}
	return true;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck baris
I.S : baris belum di check
F.S : baris sudah di check
output : false apabila 1 deret baris terisi, dan true apa bila belum terisi
*/
bool deretBaris1(){
	int i;
	for (i = 1; i < size; i++){
		if (papan[i][1]== 'X'&& papan[i][2]=='X'&& papan[i][3]=='X'){
			return false;
		}else if (papan[i][1]== 'O'&& papan[i][2]=='O'&& papan[i][3]=='O'){
			return false;
		}
    }
    return true;
}
/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck diagonal
I.S : diagonal belum di check
F.S : diagonal sudah di check
output : false apabila 1 deret diagonal terisi, dan true apa bila belum terisi
*/
bool deretDiag1(){
	if ((papan[1][1]== 'X'&& papan[2][2]=='X'&& papan[3][3]=='X')||(papan[3][1]== 'X'&& papan[2][2]=='X'&& papan[1][3]=='X') ){
		return false;
	}else if ((papan[1][1]== 'O'&& papan[2][2]=='O'&& papan[3][3]=='O')||(papan[3][1]== 'O'&& papan[2][2]=='O'&& papan[1][3]=='O')){
		return false;
	}
	return true;
}
/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengechec apakah kolom sudah di isi apa belum
I.S : isi kolom belum di chekc
F.S : isi kolom sudah di check
output : akan di return false apabila angka == 9 sebalk nya false apabila != 9
*/
bool cekPenuh(){
	int i, j, angka = 0;
	bool penuh = true;
	for(i = 1; i < size; i++){
		for(j = 1; j < size; j++){
			if(papan[i][j] !='#'){
				angka ++;
			}
		}
	}
	if (angka == 9){
		return false;
	}else{
		return true;
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : proses pengeksekusian permainan untuk bermain, dan menentukan siapa yang menang dan kalah
I.S : player1 dan player2( computer ) belum memasukan inputan, belum ada 1 deret di baris/kolom/diagonal, 
	dan pemenang belum di tentukan
F.S : player1, dan player2(computer) sudaj memasukan inputan, sudah ada salah 1 deret di baris/kolom/diagonal,
	dan pemenang sudah ditentukan oleh banyak nya ronde permainan 
*/
void giliran1(){
	int x=0, y=0;
	player1=0; player2=0;
	bool pemenang = true;
	while(player1 != r+2 && player2 != r+2){
		while(deretKolom1() && deretBaris1() && deretDiag1() && cekPenuh()){
        	pemain1(&x, &y);
        	tampilkanGrid();
        	pemenang = (deretKolom1() && deretBaris1() && deretDiag1() && cekPenuh());
			if (!pemenang){
        		player1++;
        		system("cls");
        		break;
    		}
        	system("cls");
        	tampilkanGrid();
        	if(m == 1){
        		computer(x, y);
			}else if(m == 2){
				pemain2(x, y);
			}
        	tampilkanGrid();
        	pemenang = (deretKolom1() && deretBaris1() && deretDiag1() && cekPenuh());
    		if (!pemenang){
        		player2 ++;
        		system("cls");
        		break ;
    		}
        	system("cls");
        	tampilkanGrid();
    	}
    	persiapanGrid();

	if (player1 == r+2){
        tampilkanMenang1();
        system ("pause");
    }else if(player2 == r+2){ 
		if (m == 1){
			tampilkanKalah();
			system("pause");
		}else if (m == 2){
			tampilkanMenang2();
			system("pause");
		}
    	
	}else{
		printf("jangan Senang dulu masih ada ronde berikutnya !\n");
		system("pause");
	}
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : mempersiapkan grid lalu bermain
I.S : grid belum siap, dan giliran belum di bagikan
F.S : grid sudah siap tampil, giliran sudah di bagikan
*/
void gridVS3(){
	size=4;
	persiapanGrid();
	giliran1();
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : pengeksekusian apakah bermain dengan computer atau player sesuai dengan inputan di pilih mode
I.S : lawan belum di tentukan
F.S : lawan sudah di tentukan
*/
void grid5(){
	switch(m){
		case 1:
			gridCOM5();
			break;
		case 2:
			gridVS5();
			break;
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : mempersiapkan grid lalu bermain
I.S : grid belum siap, dan giliran belum di bagikan
F.S : grid sudah siap tampil, giliran sudah di bagikan
*/
void gridCOM5(){
	size=6;
	persiapanGrid();
	giliran2();
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : mempersiapkan grid lalu bermain
I.S : grid belum siap, dan giliran belum di bagikan
F.S : grid sudah siap tampil, giliran sudah di bagikan
*/
void gridVS5(){
	size=6;
	persiapanGrid();
	giliran2();
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck baris
I.S : baris belum di check
F.S : baris sudah di check
output : false apabila 1 deret baris terisi, dan true apa bila belum terisi
*/
bool deretBaris2(){
	int i;
	for (i = 1; i < size; i++){
		if (papan[i][1]== 'X'&& papan[i][2]=='X'&& papan[i][3]=='X' && papan[i][4]=='X'){
			return false;
		}else if (papan[i][1]== 'O'&& papan[i][2]=='O'&& papan[i][3]=='O' && papan[i][4]=='O'){
			return false;
		}
	}
	return true;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kolom
I.S : kolom belum di check
F.S : kolom sudah di check
output : false apabila 1 deret kolom terisi, dan true apa bila belum terisi
*/
bool deretKolom2(){
	int i;
	for (i = 1; i < size; i++){
		if (papan[1][i]== 'X'&& papan[2][i]=='X'&& papan[3][i]=='X'&& papan[4][i]=='X'){
			return false;
		}else if (papan[1][i]== 'O'&& papan[2][i]=='O'&& papan[3][i]=='O'&& papan[4][i]=='O'){
			return false;
		}
	}
	return true;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck diagonal
I.S : diagonal belum di check
F.S : diagonal sudah di check
output : false apabila 1 deret diagonal terisi, dan true apa bila belum terisi
*/
bool deretDiag2(){
	if ((papan[1][1]== 'X'&& papan[2][2]=='X'&& papan[3][3]=='X'&&papan[4][4]=='X')||(papan[4][1]=='X'&&papan[3][2]== 'X'&& papan[2][3]=='X'&&papan[1][4]=='X')){
		return false;
	}else if ((papan[1][1]== 'O'&& papan[2][2]=='O'&& papan[3][3]=='O'&&papan[4][4]=='O')||(papan[4][1]=='O'&&papan[3][2]== 'O'&& papan[2][3]=='O'&&papan[1][4]=='O')){
		return false;
	}
	return true;
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : proses pengeksekusian permainan untuk bermain, dan menentukan siapa yang menang dan kalah
I.S : player1 dan player2( computer ) belum memasukan inputan, belum ada 1 deret di baris/kolom/diagonal, 
	dan pemenang belum di tentukan
F.S : player1, dan player2(computer) sudaj memasukan inputan, sudah ada salah 1 deret di baris/kolom/diagonal,
	dan pemenang sudah ditentukan oleh banyak nya ronde permainan 
*/
void giliran2(){
	int x=0, y=0;
	player1=0; player2=0;
	bool pemenang = true;
	while(player1 != r+2 && player2 != r+2){
		while(deretKolom2() && deretBaris2() && deretDiag2() && cekPenuh()){
        	pemain1(&x, &y);
        	tampilkanGrid();
        	pemenang = (deretKolom2() && deretBaris2() && deretDiag2() && cekPenuh());
			if (!pemenang){
        		player1++;
        		system("cls");
        		break;
    		}
        	system("cls");
        	tampilkanGrid();
        	if(m == 1){
        		computer(x, y);
			}else if(m == 2){
				pemain2(x, y);
			}
        	tampilkanGrid();
        	pemenang = (deretKolom2() && deretBaris2() && deretDiag2() && cekPenuh());
    		if (!pemenang){
        		player2 ++;
        		system("cls");
        		break ;
    		}
        	system("cls");
        	tampilkanGrid();
    	}
		persiapanGrid();

	if (player1 == r+2){
        tampilkanMenang1();
        system ("pause");
    }else if(player2 == r+2){ 
		if (m == 1){
			tampilkanKalah();
			system("pause");
		}else if (m == 2){
			tampilkanMenang2();
			system("pause");
		}
    	
	}else{
		printf("jangan Senang dulu masih ada ronde berikutnya !\n");
		system("pause");
	}
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : pengeksekusian apakah bermain dengan computer atau player sesuai dengan inputan di pilih mode
I.S : lawan belum di tentukan
F.S : lawan sudah di tentukan
*/
void grid7(){
	switch(m){
		case 1:
			gridCOM7();
			break;
		case 2:
			gridVS7();
			break;
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : mempersiapkan grid lalu bermain
I.S : grid belum siap, dan giliran belum di bagikan
F.S : grid sudah siap tampil, giliran sudah di bagikan
*/
void gridCOM7(){
	size=8;
	persiapanGrid();
	giliran3();
}
/*
Author : Temmy Mahesa Ridwan
Deskripsi : mempersiapkan grid lalu bermain
I.S : grid belum siap, dan giliran belum di bagikan
F.S : grid sudah siap tampil, giliran sudah di bagikan
*/
void gridVS7(){
	size=8;
	persiapanGrid();
	giliran3();
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kolom
I.S : kolom belum di check
F.S : kolom sudah di check
output : false apabila 1 deret kolom terisi, dan true apa bila belum terisi
*/
bool deretKolom3(){
	int i;
	for(i = 1; i<size; i++){
		if(papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X' && papan[4][i] == 'X' && papan[5][i] == 'X' ){
			return false;
		}else if(papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O' && papan[4][i] == 'O' && papan[5][i] == 'O' ){
			return false;
		}
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck baris
I.S : baris belum di check
F.S : baris sudah di check
output : false apabila 1 deret baris terisi, dan true apa bila belum terisi
*/
bool deretBaris3(){
	int i;
	for(i = 1; i < size; i++){
		if(papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X' && papan[i][4] == 'X' && papan[i][5] == 'X'){
			return false;
		}else if(papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O' && papan[i][4] == 'O' && papan[i][5] == 'O'){
			return false;
		}
	}
	return true;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck diagonal
I.S : diagonal belum di check
F.S : diagonal sudah di check
output : false apabila 1 deret diagonal terisi, dan true apa bila belum terisi
*/
bool deretDiag3(){
	if ((papan[1][1]== 'X'&& papan[2][2]=='X'&& papan[3][3]=='X'&&papan[4][4]=='X'&&papan[5][5]=='X')||(papan[5][1]== 'X'&& papan[4][2]=='X'&& papan[3][3]=='X'&& papan[2][4]=='X'&& papan[1][5]=='X')){
		return false;
	}else if ((papan[5][1]== 'O'&& papan[4][2]=='O'&& papan[3][3]=='O'&& papan[2][4]=='O'&& papan[1][5]=='O')||(papan[1][1]== 'O'&& papan[2][2]=='O'&& papan[3][3]=='O'&&papan[4][4]=='O'&&papan[5][5]=='O')){
		return false;
	}
	return true;
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : proses pengeksekusian permainan untuk bermain, dan menentukan siapa yang menang dan kalah
I.S : player1 dan player2( computer ) belum memasukan inputan, belum ada 1 deret di baris/kolom/diagonal, 
	dan pemenang belum di tentukan
F.S : player1, dan player2(computer) sudaj memasukan inputan, sudah ada salah 1 deret di baris/kolom/diagonal,
	dan pemenang sudah ditentukan oleh banyak nya ronde permainan 
*/
void giliran3(){
	int x=0, y=0;
	player1=0; player2=0;
	bool pemenang = true;
	while(player1 != r+2 && player2 != r+2){
		while(deretKolom3() && deretBaris3() && deretDiag3() && cekPenuh()){
        	pemain1(&x, &y);
        	tampilkanGrid();
        	pemenang = (deretKolom3() && deretBaris3() && deretDiag3() && cekPenuh());
			if (!pemenang){
        		player1++;
        		system("cls");
        		break;
    		}
        	system("cls");
        	tampilkanGrid();
        	if(m == 1){
        		computer(x, y);
			}else if(m == 2){
				pemain2(x, y);
			}
        	tampilkanGrid();
        	pemenang = (deretKolom3() && deretBaris3() && deretDiag3() && cekPenuh());
    		if (!pemenang){
        		player2 ++;
        		system("cls");
        		break ;
    		}
        	system("cls");
        	tampilkanGrid();
    	}
    persiapanGrid();

	if (player1 == r+2){
        tampilkanMenang1();
        system ("pause");
    }else if(player2 == r+2){ 
		if (m == 1){
			tampilkanKalah();
			system("pause");
		}else if (m == 2){
			tampilkanMenang2();
			system("pause");
		}
    	
	}else{
		printf("jangan Senang dulu masih ada ronde berikutnya !\n");
		system("pause");
	}
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : untuk menampilkan grid dilayar setelah dan sebelum di inputkan dari player 1 dan 2
I.S : grid belum di tampilkan
F.S : grid sudah di tampilkan
*/
void tampilkanGrid(){
	int i, j;
	printf("~| Score player 1 : %d     -=-=-     %d : Score player 2 |~\n", player1, player2);
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%c | ", papan[i][j]);
		}
		printf("\n");
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : untuk mengecheck kekosongan pada kolom tertentu
I.S : belum di check
F.S : sudah di check
input : mendapatkan input dari modul pemain1,pemain2
output : true apabila kosong, dan false apa bila sudah di isi
*/
bool cekGrid(int i, int j){
	if (papan[i][j]=='#'){
		return true;
	}else{
		return false;
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : proses pengeksekusian inputan dari player 1
I.S : inputan player 1 belum di masukan 
F.S : apabila inputan player 1 sudah di pilih dalam waktu kurang dari 10 detik maka bisa terisi 
	dan apabila memilih lebih dari 10 detik giliran di lempar ke player 2(lawan)
*/
void pemain1(int *i, int *j){
	int x, y, timer;
	double setTimer;
	
	timer = starttime();
	printf("\n Kolom mana yang akan anda pilih ?");
	printf("\n Player 1 : ");
	scanf("%d %d", &x, &y);
	*i = x;
	*j = y;
	timer = endtime() - timer;
	setTimer = ((double)timer)	/CLOCKS_PER_SEC;
	
	if(cekGrid(x,y) && setTimer <= 10){
		papan[x][y]='X';
	}else if(setTimer > 10){
		printf("\n WAKTU HABIS !! jangan berpikir serius ini hanya game :D \n");
		system("pause");
	}else{
		printf("\n Mohon maaf kolom yang di maksud mungkin sudah terisi atau tidak ada :'(");
		pemain1(&x, &y);
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : proses pengeksekusian inputan dari player 2
I.S : inputan player 2 belum di masukan 
F.S : apabila inputan player 2 sudah di pilih dalam waktu kurang dari 10 detik maka bisa terisi 
	dan apabila memilih lebih dari 10 detik giliran di lempar ke player 1(lawan)
*/
void pemain2(int i, int j){
	int x, y, timer;
	double setTimer;
	
	timer = starttime();
	printf("\n Kolom mana yang akan anda pilih ?");
	printf("\n Player 2 : ");
	scanf("%d %d", &x, &y);
	i = x;
	y = y;
	timer = endtime() - timer;
	setTimer = ((double)timer)	/CLOCKS_PER_SEC;
	
	if(cekGrid(x,y) && setTimer <= 10){
		papan[x][y]='O';
	}else if(setTimer > 10){
		printf("\n WAKTU HABIS !! jangan berpikir serius ini hanya game :D \n");
		system("pause");
	}else{
		printf("\n Mohon maaf kolom yang di maksud mungkin sudah terisi atau tidak ada :'(");
		pemain2(x, y);
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo dan Temmy Mahesa Ridwan
Deskripsi : menentukan level computer yang akan di lawan
I.S : level computer belum di tentukan
F.S : level computer sudah di tentukan
*/
void computer(int x, int y){
	int a = x;
	int b = y;
	
	switch(l){
		case 1:
			mudah(a, b);
			break;
		case 2:
			sedang();
			break;
		case 3:
			sulit();
			break;
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : cara kerja computer level mudah 
I.S : computer belum mengisi kolom
F.S : computer sudah mengisi kolom di kanan atau di bawah atau di kiri atau di atas tanda player 1 (X)
	apabila sudah terisi semua maka akan di random
*/
void mudah(int x, int y){
	int i, j;
	
	if(papan[x][y+1] == '#'){
		papan[x][y+1] = 'O';
	}else if(papan[x+1][y] == '#'){
		papan[x+1][y] = 'O';
	}else if(papan[x][y-1] == '#'){
		papan[x][y-1] = 'O';
	}else if(papan[x-1][y] == '#'){
		papan[x-1][y] = 'O';
	}else{
		i = rand()%size+1;
		j = rand()%size+1;
		
		if(cekGrid(i, j)){
			papan[i][j]='O';
		}else{
			mudah(x, y);
		}
	}
}
/*
Author : Temmy Mahesa Ridwan
Deskripsi : cara kerja computer level sedang
I.S : computer belum mengisi kolom
F.S : computer sudah menigisi kolom secara acak
*/
void sedang(){
	int i, j;
	i = rand()%size+1;
	j = rand()%size+1;
		
	if(cekGrid(i, j)){
		papan[i][j]='O';
	}else{
		sedang();
	}
}
/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : cara kerja computer level sulit
I.S : computer belum mengisi kolom
F.S : computer sudah mengisi kolom di tengah atau mengecheck ke semua kolom, baris, dan diagonal, 
	apa bila belum ada yang true maka akan di acak
*/
void sulit(){
	int i=size/2;
	int j=size/2;
	
	if(papan[i][j] == '#'){
		papan[i][j] = 'O';
	}else{
		if(cekBarisX()){
			barKos(&i, &j);
			if(papan[i][j] == '#'){
				papan[i][j] = 'O';
				goto akhir;
			}
		}
		if(cekKolomX()){
			kolKos(&i, &j);
			if(papan[i][j] == '#'){
				papan[i][j] = 'O';
				goto akhir;
			}
		}
		if(cekKanan()){
			diagKanan(&i, &j);
			if(cekGrid(i, j)){
				papan[i][j] = 'O';
				goto akhir;
			}
		}
		if(cekKiri()){
			diagKiri(&i, &j);
			if(cekGrid(i, j)){
				papan[i][j] = 'O';
				goto akhir;
			}
		}
		if(i == size/2 && j == size/2){
			random :
				srand(time(0));
				i = rand() % size + 1;
				j = rand() % size + 1;
				if(cekGrid(i, j)){
					papan[i][j] ='O';
				}else{
					goto random;
				}
		}
	}
	akhir :
		i = 0;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : untuk mengecheck baris 
I.S : semua baris belum ada yang di check
F.S : semua baris sudah di check
output : true bila count == size -2, apabila tidak maka nilainya false
*/
bool cekBarisX(){
	int i, j, count=0;
	bool barPenuh = true;
	for(i=1; i < size; i++){
		count=0;
    	for(j=1; j < size; j++){
			if(papan[i][j]=='X' ){
            count++;
			}
		}
		if(count == size - 2){
	    return true;
    	}
	}
	return false;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : untuk mengecheck kolom
I.S : semua kolom belum ada yang di check
F.S : semua kolom  sudah di check
output : true bila count == size -2, apabila tidak maka nilainya false
*/
bool cekKolomX(){
	int i, j, count=0;
	for(i=1; i < size; i++){
		count=0;
        for(j=1; j < size; j++){
			if(papan[j][i]=='X'){
			count++;
			}
		}
		if(count == size - 2){
        return true;
		}
	}
	return false;
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : untuk mengecheck diagonal dari arah kanan
I.S : diagonal dari arah kanan belum ada yang di check
F.S : diagobal dari arah kanan sudah di check
output : true bila count == size -2, apabila tidak maka nilainya false
*/
bool cekKanan(){
	int i, j, count=0;
	for (i=1; i < size; i++){
		//count=0;
		for (j=1; j < size; j++){
			if(i+j==size && papan [i][j]=='X'){
			count++;
			}
		}
	}
	if (count == size - 2){
		return true;
	}else{
		return false;
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : untuk mengecheck diagonal dari arah kiri
I.S : diagonal dari arah kiri belum ada yang di check
F.S : diagobal dari arah kiri sudah di check
output : true bila count == size -2, apabila tidak maka nilainya false
*/
bool cekKiri(){
	int i, j, count=0;
	for (i=1; i < size; i++){
	// count=0;
		for (j=1; j < size; j++){
			if(i==j && papan[i][j]=='X'){
				count++;
			}
		}
	}
	if(count == size -  2){
		return true;
	}else{
		return false;
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kekosongan di deret baris
I.S : baris belum di check
F.S : baris sudah di check
*/
void barKos(int *i, int *j){
	int x, y;
	bool terisi = true;
	
	for(x = 1; (y < size) && terisi ;x++){
		for(y = 1; (y < size) && terisi ; y++){
			if(papan[x][y] == '#' || papan [x][y] == 'O'){
				*i = x;
				*j = y;
				terisi = false;
			}
		}
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kekosongan di deret kolom
I.S : kolom belum di check
F.S : kolom sudah di check
*/
void kolKos(int *i, int *j){
	int x, y;
	bool terisi = true;
	
	for(x = 1; (y < size) && terisi ;x++){
		for(y = 1; (y < size) && terisi ; y++){
			if(papan[y][x] == '#'){
				*i = y;
				*j = x;
				terisi = false;
			}
		}
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kekosongan di deret diagonal arah kanan
I.S : diagonal dari kanan belum di check
F.S : diagonal dari kanan sudah di check
*/
void diagKanan(int *i, int *j){
	int x, y, count = 0;
	bool terisi = true;
	for(x = 1; (x < size) && terisi; x++){
		count = 0;
		for(y = 1; (y <size) && terisi; y++){
			if(x + y == size && papan[x][y] == '#'){
				*i = x;
				*j = y;
				terisi = false;
			}
		}
	}
}

/*
Author : Mochammad Daffa Faqiha Fawwaz Hanjowo 
Deskripsi : mengecheck kekosongan di deret diagonal arah kiri
I.S : diagonal dari kiri belum di check
F.S : diagonal dari kiri sudah di check
*/
void diagKiri(int *i, int *j){
	int x,y;
	bool terisi = true;
	for(x = 1; (x < size) && terisi; x++){
		for(y = 1; (y <size) && terisi; y++){
			if(x == y && papan[x][y] == '#'){
				*i = x;
				*j = y;
				terisi = false;
			}
		}
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : menampilkan pemenang apabila player 1 menang
I.S : layar belum ada apa apa 
F.S : layar terdapat pengucapat selamat kepada player 1 
	dan memberi kesempatan untuk memainkan permainannya lagi atau keluar dari program
*/

void tampilkanMenang1(){
	system("cls");
	printf(" SELAMAT PLAYER 1 ANDA MEMENANGKAN PERMAINAN !!\n");
	printf(" jangan sombong dulu ya ! \n");
	printf("\n");
	printf(" Mau main lagi ga ??\n");
	printf(" 1. Mau dong :DD\n");
	printf(" 2. Keluar\n");
	int i;
	scanf("%d", &i);
	if(i == 1){
		pilihGrid();
		system("pause");
	}else{
		printf(" Bye bye!\n");
		system("pause");
	}
	
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : menampilkan pemenang apabila player 2 menang
I.S : layar belum ada apa apa 
F.S : layar terdapat pengucapat selamat kepada player 2 
	dan memberi kesempatan untuk memainkan permainannya lagi atau keluar dari program
*/
void tampilkanMenang2(){
	system("cls");
	printf(" SELAMAT PLAYER 2 ANDA MEMENANGKAN PERMAINAN !!\n");
	printf(" jangan sombong dulu ya ! \n");
	printf("\n");
	printf(" Mau main lagi ga ??\n");
	printf(" 1. Mau dong :DD\n");
	printf(" 2. Keluar\n");
	int i;
	scanf("%d", &i);
	if(i == 1){
		pilihGrid();
		system("pause");
	}else{
		printf(" Bye bye!\n");
		system("pause");
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : menampilkan kalah apabila computer menang
I.S : layar belum ada apa apa 
F.S : layar terdapat sebuah kata kata yang membuat player untuk tidak menyerah
	dan memberi kesempatan untuk memainkan permainannya lagi atau keluar dari program
*/
void tampilkanKalah(){
	system("cls");
	printf("WA HA HA HA SAYANG SEKALI ANDA KALAH !\n");
	printf("jangan menyerah, ayo tantang lagi !\n");
	printf("\n");
	printf(" Mau main lagi ga ??\n");
	printf(" 1. Mau dong :DD\n");
	printf(" 2. Keluar\n");
	int i;
	scanf("%d", &i);
	if(i == 1){
		pilihGrid();
		system("pause");
	}else{
		printf(" Bye bye!\n");
		system("pause");
	}
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : untuk menampilkan score history 
I.S : score history belum di tampilkan
F.S : score history sudah di tampilkan
*/
void scoreHistory (){

	int i,N;

	N = GetData();
		printf("Nama Pemain\tSkor Player1\tSkor Player2\tGrid");printf("\n");
		for ( i = 0 ; i < N ; i++ ){
			printf("%-20s ",data.namaGame);
			printf("\t");
			printf("%d",data.rondePlayer1);
			printf("\t\t");
			printf("%d",data.rondePlayer2);
			printf("\t\t");
			printf("%s", data.gridPermainan);
			}
	
	system("pause");
}
/*
Author : Temmy Mahesa Ridwan
Deskripsi : untuk mengambil data yang ada di dalam file 
I.S : data belum di ambil dari file 
F.S : data sudah di ambil dari file
*/
int GetData(){
	int N = 0;
	FILE *fp = fopen(HIGHSCORE_FILENAME, "rb");
	while ( fread(&data, sizeof(HighscoreData), 1, fp ) == 1 ) N++;
	fclose(fp);
	return N;
}

/*
Author : Temmy Mahesa Ridwan
Deskripsi : untuk menulis data permainan ke dalam file 
I.S : file belum di salin dan di tulis ke file
F.S : file sudah di salin dan di tulis ke file
*/
void writeData(){

	strcpy(data.namaGame,nama);
	data.rondePlayer1 = player1 ;
	data.rondePlayer2 = player2 ;
	if(g == 1){
		strcpy(data.gridPermainan, "3 x 3");
	}else if(g == 2){
		strcpy(data.gridPermainan, "5 x 5");
	}else if(g == 3){
		strcpy(data.gridPermainan, "7 x 7");
	}
	


	FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
	fwrite(&data, sizeof(HighscoreData), 1, fp);
	fclose(fp);
}

int starttime(){
    clock_t t;
    t = clock();
    return t;
}

int endtime(){
    clock_t t;
    t = clock();
    return t;
}
