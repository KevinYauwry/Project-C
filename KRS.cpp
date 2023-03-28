#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

struct mahasiswa{
	string nama, prodi, ipk;
	int nim;
}mhs[10];

struct dosen{
	string nama;
	int nidn;
}dsn[10];

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;

void mhsData(){
	for(i = 1; i < 3;i++){
		cout<<"Nama  : "<<mhs[i].nama<<endl;
		cout<<"Nim   : "<<mhs[i].nim<<endl;
		cout<<"Prodi : "<<mhs[i].prodi<<endl;
		cout<<"Ipk   : "<<mhs[i].ipk<<endl;
		cout<<"-------------------\n";
	}
	getch();
}

void mhsCari(){
	int cariNim, ketemu = 0;
	system("cls");
	cout<<"CARI DATA MAHASISWA"<<endl;
	cout<<"Masukkan Nim : ";
	cin>>cariNim;
	for(int i = 1; i < 3;i++){
		if(cariNim == mhs[i].nim){	
			ketemu =1;		
			cout<<"Nama  : "<<mhs[i].nama<<endl;
			cout<<"Nim   : "<<mhs[i].nim<<endl;
			cout<<"Prodi : "<<mhs[i].prodi<<endl;
			cout<<"Ipk   : "<<mhs[i].ipk<<endl;
			cout<<"|------------------------------------------------------------------------------|\n";	
			cout<<"|                                      Krs                                     |\n";
			cout<<"|------------------------------------------------------------------------------|\n";
			cout<<"|No|         Matkul       |     Sks      |      Hari     |         Jam         |\n";
			gotoxy(1,10);cout<<"1\n";
			gotoxy(6,10);cout<<"Graf dan Automata\n";
			gotoxy(33,10);cout<<"3\n";
			gotoxy(47,10);cout<<"Senin\n";
			gotoxy(62,10);cout<<"12.00 - 14.30\n";
			gotoxy(0,10);cout<<"|\n";
			gotoxy(3,10);cout<<"|\n";
			gotoxy(26,10);cout<<"|\n";
			gotoxy(41,10);cout<<"|\n";
			gotoxy(57,10);cout<<"|\n";
			gotoxy(79,10);cout<<"|\n";
		}
	}
	if(ketemu == 0){
		cout<<"Nim Mahasiswa tidak ditemukan\n";
	}
	getch();
}

int main(){
	int pil;
	
	mhs[1].nama  = "Kevin Yauwry";
	mhs[1].ipk   = "4.00";
	mhs[1].prodi = "Teknik Informatika";
	mhs[1].nim   = 164;
	mhs[2].nama  = " M. Faisal Bustomi";
	mhs[2].ipk   = "4.00";
	mhs[2].prodi = "Teknik Informatika";
	mhs[2].nim   = 157;
		
	while(pil!=5){
		cout<<"MENU KRS"<<endl;
		cout<<"1. Lihat Data Mahasiswa"<<endl;
		cout<<"2. Cari Mahasiswa"<<endl;
		cout<<"3. Lihat Data Dosen"<<endl;
		cout<<"4. Cari Dosen"<<endl;
		cout<<"5. Keluar"<<endl;
		cout<<"Pilih : ";cin>>pil;
		if(pil==1)
		mhsData();
		if(pil==2)
		mhsCari();
	}
}
