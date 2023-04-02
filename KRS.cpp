#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

struct mahasiswa{
	string nama, prodi, ipk;
	int nim;
}mhs[10];

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;

void mhsData(){
	system("cls");
	cout<<"------------------------- DATA MAHASISWA -------------------------\n";
	cout<<" No          Nama         NIM            PRODI             NILAI\n";
	cout<<"-------------------------------------------------------------------";
	for(i = 1; i < 4;i++){
		gotoxy(1,i+3);cout<<i;
		gotoxy(5,i+3);cout<<mhs[i].nama<<endl;
		gotoxy(26,i+3);cout<<mhs[i].nim<<endl;
		gotoxy(35,i+3);cout<<mhs[i].prodi<<endl;
		gotoxy(59,i+3);cout<<mhs[i].ipk<<endl;
	}
	getch();
}

void mhsEdit(){
	int nbi;
	bool temu = 0;
	system("cls");
	cout<<"Masukkan NIM Mahasiswa : ";
	cin>>nbi;
	for(int i=1;i<4;i++){
		if(nbi==mhs[i].nim){
			temu = 1;
			cout<<"Nama  : "<<mhs[i].nama<<endl;
			cout<<"NIM   : "<<mhs[i].nim<<endl;
			cout<<"Prodi : "<<mhs[i].prodi<<endl;
			cout<<"Nilai : "<<mhs[i].ipk<<endl;
			
			string newNama, newProdi, newNilai;
			int newNIM;
			int pil;
			while(pil!=5){
				cout<<"1. Edit Nama\n";
				cout<<"2. Edit NIM\n";
				cout<<"3. Edit Prodi\n";
				cout<<"4. Edit Nilai\n";
				cout<<"5. Keluar\n";
				cout<<"Pilih : ";cin>>pil;
				if(pil==1){
					cout<<"Masukkan Nama Baru : ";
					cin>>newNama;
					mhs[i].nama = newNama;
					cout<<"Data Berhasil Diedit\n";
				}
				else if(pil==2){
					cout<<"Masukkan NIM Baru : ";
					cin>>newNIM;
					mhs[i].nim = newNIM;
					cout<<"Data Berhasil Diedit\n";
				}
				else if(pil==3){
					cout<<"Masukkan Prodi Baru : ";
					cin>>newProdi;
					mhs[i].prodi = newProdi;
					cout<<"Data Berhasil Diedit\n";
				}
				else if(pil==4){
					cout<<"Masukkan Nilai Baru : ";
					cin>>newNilai;
					mhs[i].ipk = newNilai;
					cout<<"Data Berhasil Diedit\n";
				}
			}
		}
	}
	if(temu == 0){
		cout<<"Mahasiswa Tidak Ditemukan.";
		getch();
	}
}

void dsnData(){
	int pil;
	while(pil!=3){
	system("cls");
	cout<<"MENU ADMIN\n\n";
		cout<<"1. Lihat Data Mahasiswa\n";
		cout<<"2. Edit Data Mahasiswa\n";
		cout<<"3. Kembali Ke Login\n";
		cout<<"Pilih : ";
		cin>>pil;
		if(pil==1)
		mhsData();
		if(pil==2)
		mhsEdit();
	}
}

void mhsMenu(int a){
			system("cls");
			cout<<"Nama  : "<<mhs[a].nama<<endl;
			cout<<"Nim   : "<<mhs[a].nim<<endl;
			cout<<"Prodi : "<<mhs[a].prodi<<endl;
			cout<<"Ipk   : "<<mhs[a].ipk<<endl;
			cout<<"Dosen Wali : "<<"Elsen Ronando, S.Si., M.Si., M.Sc."<<endl;
			if(a == 1){
			cout<<"|-----------------------------------------------------------------------------------------------------|\n";	
			cout<<"|                                      KRS MAHASISWA INFORMATIKA                                      |\n";
			cout<<"|-----------------------------------------------------------------------------------------------------|\n";
			cout<<"|No|              Matkul            |     Sks      |      Hari     |         Jam         |   Ruangan  |\n";
			gotoxy(0,i+9);cout<<"|1 |\n";
			gotoxy(11,i+9);cout<<"Graf dan Automata        |\n";
			gotoxy(43,i+9);cout<<"3       |\n";
			gotoxy(57,i+9);cout<<"Senin     |\n";
			gotoxy(72,i+9);cout<<"12.00 - 14.30    |\n";
			gotoxy(94,i+9);cout<<"Q303    |\n";
			gotoxy(0,i+10);cout<<"|2 |\n";
			gotoxy(10,i+10);cout<<"Matematika Komputasi      |\n";
			gotoxy(43,i+10);cout<<"4       |\n";
			gotoxy(57,i+10);cout<<"Selasa    |\n";
			gotoxy(72,i+10);cout<<"07.50 - 09.30    |\n";
			gotoxy(94,i+10);cout<<"L709    |\n";
			gotoxy(0,i+11);cout<<"|3 |\n";
			gotoxy(7,i+11);cout<<"Struktur Data dan Algoritma  |\n";
			gotoxy(43,i+11);cout<<"3       |\n";
			gotoxy(57,i+11);cout<<"Rabu      |\n";
			gotoxy(72,i+11);cout<<"12.00 - 14.30    |\n";
			gotoxy(94,i+11);cout<<"Q302    |\n";
			cout<<"-----------------------------------------------------------------------------------------------------|";
		}
	getch();
}

int main(){	
	
	mhs[1].nama  = "Kevin Yauwry";
	mhs[1].ipk   = "4.00";
	mhs[1].prodi = "Teknik Informatika";
	mhs[1].nim   = 164;
	mhs[2].nama  = "M. Faisal Bustomi";
	mhs[2].ipk   = "4.00";
	mhs[2].prodi = "Teknik Informatika";
	mhs[2].nim   = 157;
	mhs[3].nama  = "Febri Tri Harkasa";
	mhs[3].nim   = 154;
	mhs[3].ipk   = "4.00";
	mhs[3].prodi = "Teknik Informatika";
	
	string username,pass;
	while(username!="exit"){
	system("cls");
	cout<<"Masukkan Username : ";
	cin>>username;
	if(username == "Kevin"){
		cout<<"Masukkan Password : ";
		cin>>pass;
		if(pass=="164"){
			mhsMenu(1);
		}
		else{
			cout<<"Password Anda Salah!";
		}
	}
	else if(username == "Faisal"){
		cout<<"Masukkan Password : ";
		cin>>pass;
		if(pass == "157"){
			mhsMenu(2);
		}
		else{
			cout<<"Password Anda Salah!";
		}
	}
	else if(username =="Febri"){
		cout<<"Masukkan Password : ";
		cin>>pass;
		if(pass=="154"){
			mhsMenu(3);
		}
		else{
			cout<<"Password Anda Salah!";
		}
	}
	else if(username =="admin"){
		cout<<"Masukkan Password : ";
		cin>>pass;
		if(pass=="admin"){
			dsnData();
		}
		else{
			cout<<"Password Anda Salah!";
		}
	}
	else if(username=="exit"){
		cout<<"Selamat Berjumpa Kembali.";
	}
	else{
		cout<<"Username Anda Salah!";
	}
}
	getch();
}
