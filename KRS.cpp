#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
using namespace std;

struct kelas{
	string matkul, kelas, jam,  status, ruang, hari;
	int sks;
}kls[10];

struct mahasiswa{
	string nama, prodi, ipk, pass, nim;
	int c;
	kelas kls[10];
}mhs[10];

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i,jumlahMhs;
string pos = "awal";

void mhsTambah(int k){
	string pil;
	if(pos=="awal")
	i = 0;
	
	system("cls");
	cout<<"INPUT DATA MAHASISWA\n\n";
	while(pil!="t"){
		cout<<"Nama Mahasiswa     : ";getline(cin,mhs[i].nama);
		cout<<"NIM Mahasiswa      : ";getline(cin,mhs[i].nim);
		cout<<"Prodi Mahasiswa    : ";getline(cin,mhs[i].prodi);
		cout<<"IPK Mahasiswa      : ";getline(cin,mhs[i].ipk);
		mhs[i].pass = mhs[i].nim;
		pos="akhir";
		i++,jumlahMhs=i;
		cout<<"Tambah Lagi (y/t) : ";getline(cin,pil);
		cout<<endl;
	}
}

void mhsData(int jumlahMhs){
	system("cls");
	cout<<"------------------------- DATA MAHASISWA --------------------------\n";
	cout<<" No          Nama         NIM            PRODI             NILAI\n";
	cout<<"-------------------------------------------------------------------";
	
	if(jumlahMhs==0){
		gotoxy(12,3);cout<<"DATA MASIH KOSONG";
	}
	
	else{
	for(i = 0; i<jumlahMhs;i++){
		gotoxy(1,i+3);cout<<i+1;
		gotoxy(5,i+3);cout<<mhs[i].nama<<endl;
		gotoxy(26,i+3);cout<<mhs[i].nim<<endl;
		gotoxy(35,i+3);cout<<mhs[i].prodi<<endl;
		gotoxy(59,i+3);cout<<mhs[i].ipk<<endl;
	}
	}
	cout<<"-------------------------------------------------------------------";
	getch();
}

void mhsEdit(int jumlahMhs){
	string nbi;
	bool temu = 0;
	system("cls");
	
	if(jumlahMhs==0){
		cout<<"DATA MASIH KOSONG";
	}
	
	else{
	cout<<"Masukkan NIM Mahasiswa : ";
	cin>>nbi;
	for(int i=0;i<3;i++){
		if(nbi==mhs[i].nim){
			temu = 1;
			cout<<"Nama  : "<<mhs[i].nama<<endl;
			cout<<"NIM   : "<<mhs[i].nim<<endl;
			cout<<"Prodi : "<<mhs[i].prodi<<endl;
			cout<<"Nilai : "<<mhs[i].ipk<<endl;
			
			string newNama, newProdi, newNilai, newNIM;
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
					cout<<"Data Berhasil Diedit\n\n";
				}
				else if(pil==2){
					cout<<"Masukkan NIM Baru : ";
					cin>>newNIM;
					mhs[i].nim = newNIM;
					cout<<"Data Berhasil Diedit\n\n";
				}
				else if(pil==3){
					cout<<"Masukkan Prodi Baru : ";
					cin>>newProdi;
					mhs[i].prodi = newProdi;
					cout<<"Data Berhasil Diedit\n\n";
				}
				else if(pil==4){
					cout<<"Masukkan Nilai Baru : ";
					cin>>newNilai;
					mhs[i].ipk = newNilai;
					cout<<"Data Berhasil Diedit\n\n";
				}
			}
		}
	}
	if(temu == 0){
		cout<<"Mahasiswa Tidak Ditemukan.";
	}
	}
	getch();
}

void dsnData(){
	string pil;
	while(pil!="4"){
	system("cls");
	cout<<"MENU ADMIN\n\n";
		cout<<"1. Tambah Mahasiswa\n";
		cout<<"2. Lihat Data Mahasiswa\n";
		cout<<"3. Edit Data Mahasiswa\n";
		cout<<"4. Kembali Ke Login\n";
		cout<<"Pilih : ";
		getline(cin,pil);
		if(pil=="1")
		mhsTambah(i);
		if(pil=="2")
		mhsData(i);
		if(pil=="3")
		mhsEdit(i);
	}
}

void mhsPil(int a){
	int krs;int total;
	string pil;	
	while(pil!="t"){
	system("cls");
	cout<<"|                                              PEMILIHAN KRS MAHASISWA                                             |\n";
	cout<<"|------------------------------------------------------------------------------------------------------------------|\n";
	cout<<"|No|              Matkul            |     Sks      |      Hari     |         Jam         |   Ruangan  |   Status   |\n";
	cout<<"|------------------------------------------------------------------------------------------------------------------|\n";	
	for(int i = 0;i<3;i++){
		gotoxy(1,i+4);cout<<i+1;
		gotoxy(11,i+4);cout<<kls[i].matkul;
		gotoxy(43,i+4);cout<<kls[i].sks;
		gotoxy(57,i+4);cout<<kls[i].hari;
		gotoxy(72,i+4);cout<<kls[i].jam;
		gotoxy(94,i+4);cout<<kls[i].ruang;
		gotoxy(105,i+4);cout<<mhs[a].kls[i].status;
	}
	gotoxy(0,9);
	cout<<"Masukkan Nomor Kelas yang Ingin Diambil : ";
	cin>>krs;
	krs=krs-1;
	
	if(mhs[a].kls[krs].status == "Diambil"){
		cout<<"Mata Kuliah Sudah Diambil\n";
	}
	else if(krs>3){
		cout<<"Mata Kuliah Tidak Ada\n";
	}
	else{
	for(int i=0;i<3;i++){
	total += mhs[a].kls[i].sks;
	}
	if(total>5){
	cout<<"Batas Maksimal SKS sudah tercapai\n";
		}
	else{
		int i = mhs[a].c++;
		mhs[a].kls[i].sks    = kls[krs].sks;
		mhs[a].kls[krs].status = "Diambil";
		mhs[a].kls[i].matkul = kls[krs].matkul;
		mhs[a].kls[i].kelas  = kls[krs].ruang;
		mhs[a].kls[i].hari   = kls[krs].hari;
		mhs[a].kls[i].jam    = kls[krs].jam;
		mhs[a].kls[i].ruang  = kls[krs].ruang;
		cout<<"Mata Kuliah "<<kls[krs].matkul<<" Berhasil Diambil\n";
		}
	}
	cout<<"Pilih Lagi (y/t) : ";
	cin>>pil;
	}
}

void mhsKrs(int a){
			system("cls");
			cout<<"Nama  : "<<mhs[a].nama<<endl;
			cout<<"Nim   : "<<mhs[a].nim<<endl;
			cout<<"Prodi : "<<mhs[a].prodi<<endl;
			cout<<"Ipk   : "<<mhs[a].ipk<<endl;
			cout<<"Dosen Wali : "<<"Elsen Ronando, S.Si., M.Si., M.Sc."<<endl<<endl;
			cout<<"|-----------------------------------------------------------------------------------------------------|\n";	
			cout<<"|                                      KRS MAHASISWA INFORMATIKA                                      |\n";
			cout<<"|-----------------------------------------------------------------------------------------------------|\n";
			cout<<"|No|              Matkul            |     Sks      |      Hari     |         Jam         |   Ruangan  |\n";
			cout<<"|-----------------------------------------------------------------------------------------------------|\n";
			if(mhs[a].c == 0){
			gotoxy(45,11);cout<<"DATA MASIH KOSONG"<<endl;			
			}
			else{
				for(i=0;i<mhs[a].c;i++){
			gotoxy(1,i+11);cout<<i+1;
			gotoxy(11,i+11);cout<<mhs[a].kls[i].matkul;
			gotoxy(43,i+11);cout<<mhs[a].kls[i].sks;
			gotoxy(57,i+11);cout<<mhs[a].kls[i].hari;
			gotoxy(72,i+11);cout<<mhs[a].kls[i].jam;
			gotoxy(94,i+11);cout<<mhs[a].kls[i].ruang<<endl;
			}
		}
			cout<<"|-----------------------------------------------------------------------------------------------------|";
	getch();
}

void mhsPass(int a){
	system("cls");
	string pass, newPass;
	cout<<"Masukkan Password Anda : ";
	cin>>pass;
	if(pass==mhs[a].pass){
		cout<<"Masukkan Password Baru : ";
		cin>>newPass;
		mhs[a].pass = newPass;
		cout<<"Password Anda Berhasil Diganti.";
	}
	else{
		cout<<"Password Anda Salah.";
	}
	getch();
}

void mhsMenu(int a){
	int pil;
	while(pil!=4){
		system("cls");
		cout<<"        MENU MAHASISWA\n";
		cout<<"Selamat Datang "<<mhs[a].nama<<endl<<endl;
		cout<<"1. Pilih KRS\n";
		cout<<"2. Tampil KRS\n";
		cout<<"3. Ubah Password\n";
		cout<<"4. Keluar\n";
		cout<<"Pilih : ";cin>>pil;
		if(pil==1)
		mhsPil(a);
		if(pil==2)
		mhsKrs(a);
		if(pil==3)
		mhsPass(a);
	}
}

int main(){	

	kls[0].matkul = "Graf & Automata";
	kls[0].kelas  = "A";
	kls[0].sks    = 3;
	kls[0].hari   = "Senin";
	kls[0].jam    = "12.00 - 14.30";
	kls[0].ruang  = "Q303";
	kls[1].matkul = "Arsitektur Komputer";
	kls[1].kelas  = "C";
	kls[1].sks    = 3;
	kls[1].hari   = "Selasa";
	kls[1].jam    = "09.30 - 12.00";
	kls[1].ruang  = "L602";
	kls[2].matkul = "Matematika Komputasi";
	kls[2].kelas  = "A";
	kls[2].sks    =  4;
	kls[2].hari   = "Kamis";
	kls[2].jam    = "07.50 - 9.30";
	kls[2].ruang  = "L709";
	
	string username,pass;
	while(username!="exit"){
	bool err = 0;
	system("cls");
		cout<<"\n\n\t\t*********************************\n";
		cout<<"\t\t*  HALAMAN LOGIN KRS MAHASISWA  *\n";
		cout<<"\t\t*********************************\n";
		cout<<"\t\t*                               *\n";
		cout<<"\t\t*    Username :                 *\n";
		cout<<"\t\t*    Password :                 *\n";
		cout<<"\t\t*                               *\n";
		cout<<"\t\t*********************************\n";
		gotoxy(12,10);cout<<"Username & Password : exit / EXIT Untuk Keluar Program";
		gotoxy(33,6);cin>>username;
		gotoxy(33,7);cin>>pass;
	
	if(username =="admin" && pass=="admin"){
		err=1;
			dsnData();
		}
	else if(username == "exit" || username == "EXIT"){
		err=1;
		cout<<"Selamat Berjumpa Kembali.";
	}
	else{
	for(int i=0;i<jumlahMhs;i++){
		if(username == mhs[i].nim && pass==mhs[i].pass ){
			mhsMenu(i);
		}
		if(err==0){
		gotoxy(17,8);cout<<"Username / Password Anda Salah";
		}
		}
	}
	getch();
}
	return 0;
}
