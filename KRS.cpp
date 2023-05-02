#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
using namespace std;

struct kelas{
	string matkul, kelas, jam,  status, ruang, hari;
	int sks, kode;
}kls[16];

struct mahasiswa{
	string nama, prodi, ipk, pass, nim, jKelamin, fklts, tLahir;
	int c;
	kelas kls[16];
}mhs[10];

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int i,jumlahMhs;
string pos = "awal";

void mhsTambah(int k){
	string pil;
	if(pos=="awal")
	i = 0;
	pil="y";
	system("cls");
	cout<<"INPUT DATA MAHASISWA\n\n";
	while(pil=="y"){
		cout<<"Nama Mahasiswa           : ";getline(cin,mhs[i].nama);
		cout<<"NIM Mahasiswa            : ";getline(cin,mhs[i].nim);
		cout<<"Fakultas Mahasiswa       : ";getline(cin,mhs[i].fklts);
		cout<<"Prodi Mahasiswa          : ";getline(cin,mhs[i].prodi);
		cout<<"Jenis Kelamin            : ";getline(cin,mhs[i].jKelamin);
		cout<<"Tanggal Lahir Mahasiswa  : ";getline(cin,mhs[i].tLahir);
		cout<<"IPK Mahasiswa            : ";getline(cin,mhs[i].ipk);
		mhs[i].pass = mhs[i].nim;
		pos="akhir";
		i++,jumlahMhs=i;
		cout<<"Tambah Lagi (y/t)  : ";getline(cin,pil);
		cout<<endl;
	}
}

void mhsData(int jumlahMhs){
	system("cls");
	cout<<"----------------------------------------------- DATA MAHASISWA -------------------------------------------------------------|\n";
	cout<<"| No|             Nama          |         NIM          |     Fakultas    |        Prodi         |   Jenis Kelamin   |  IPK  |\n";
	cout<<"----------------------------------------------------------------------------------------------------------------------------|\n";	
	if(jumlahMhs==0){
		gotoxy(12,3);cout<<"DATA MASIH KOSONG";
	}
	else{
	for(i = 0; i<jumlahMhs;i++){
		gotoxy(1,i+3);cout<<i+1;
		gotoxy(11,i+3);cout<<mhs[i].nama;
		gotoxy(38,i+3);cout<<mhs[i].nim;
		gotoxy(62,i+3);cout<<mhs[i].fklts;
		gotoxy(79,i+3);cout<<mhs[i].prodi;
		gotoxy(103,i+3);cout<<mhs[i].jKelamin;
		gotoxy(120,i+3);cout<<mhs[i].ipk;
	}
	}
	cout<<"\n----------------------------------------------------------------------------------------------------------------------------|\n";
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
	for(int i=0;i<jumlahMhs;i++){
		if(nbi==mhs[i].nim){
			temu = 1;
			cout<<"Nama          : "<<mhs[i].nama<<endl;
			cout<<"NIM           : "<<mhs[i].nim<<endl;
			cout<<"Fakultas      : "<<mhs[i].fklts<<endl;
			cout<<"Prodi         : "<<mhs[i].prodi<<endl;
			cout<<"Tanggal Lahir : "<<mhs[i].tLahir<<endl;
			cout<<"IPK           : "<<mhs[i].ipk<<endl;
			
			string newNama, newProdi, newNilai, newNIM, newFklts, newTgl;
			int pil;
			while(pil!=7){
				cout<<"1. Edit Nama\n";
				cout<<"2. Edit NIM\n";
				cout<<"3. Edit Fakultas\n";
				cout<<"4. Edit Prodi\n";
				cout<<"5. Edit Tanggal Lahir\n";
				cout<<"6. Edit IPK\n";
				cout<<"7. Keluar\n";
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
					cout<<"Masukkan Fakutas Baru : ";
					cin>>newFklts;
					mhs[i].fklts = newFklts;
					cout<<"Data Berhasil Diedit\n\n";
				}
				else if(pil==4){
					cout<<"Masukkan Prodi Baru : ";
					cin>>newProdi;
					mhs[i].prodi = newProdi;
					cout<<"Data Berhasil Diedit\n\n";
				}
				else if(pil==5){
					cout<<"Masukkan Tanggal Lahir Baru : ";
					cin>>newTgl;
					mhs[i].tLahir = newTgl;
					cout<<"Data Berhasil Diedit\n\n";
				}
				else if(pil==6){
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
	cout<<"|                                                                PEMILIHAN KRS MAHASISWA                                                                 |\n";
	cout<<"|--------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
	cout<<"|No|  Kode Matkul  |                       Matkul                     | Kelas |    SKS    |     Hari     |         Jam         |   Ruangan  |   Status   |\n";
	cout<<"|--------------------------------------------------------------------------------------------------------------------------------------------------------|\n";	
	for(int i = 0;i<16;i++){
		gotoxy(1,i+4);cout<<i+1;
		gotoxy(6,i+4);cout<<kls[i].kode;
		gotoxy(27,i+4);cout<<kls[i].matkul;
		gotoxy(74,i+4);cout<<kls[i].kelas;
		gotoxy(84,i+4);cout<<kls[i].sks;
		gotoxy(96,i+4);cout<<kls[i].hari;
		gotoxy(110,i+4);cout<<kls[i].jam;
		gotoxy(132,i+4);cout<<kls[i].ruang;
		gotoxy(145,i+4);cout<<mhs[a].kls[i].status;
	}
	gotoxy(0,21);
	cout<<"Masukkan Nomor Kelas yang Ingin Diambil : ";
	cin>>krs;
	krs=krs-1;
	
	if(mhs[a].kls[krs].status == "Diambil"){
		cout<<"Mata Kuliah Sudah Diambil\n";
	}
	else if(krs>16){
		cout<<"Mata Kuliah Tidak Ada\n";
	}
	else{
		for(int i=0;i<16;i++){
			total += mhs[a].kls[i].sks;
		}
	if(total>16){
	cout<<"Batas Maksimal SKS sudah tercapai\n";
		}
	else{
		int i = mhs[a].c++;
		mhs[a].kls[i].sks    = kls[krs].sks;
		mhs[a].kls[krs].status = "Diambil";
		mhs[a].kls[i].matkul = kls[krs].matkul;
		mhs[a].kls[i].kode   = kls[krs].kode;
		mhs[a].kls[i].kelas  = kls[krs].kelas;
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
			cout<<"Nama          : "<<mhs[a].nama<<endl;
			cout<<"Nim           : "<<mhs[a].nim<<endl;
			cout<<"Fakultas      : "<<mhs[a].fklts<<endl;
			cout<<"Prodi         : "<<mhs[a].prodi<<endl;
			cout<<"Jenis Kelamin : "<<mhs[a].jKelamin<<endl;
			cout<<"Tanggal Lahir : "<<mhs[a].tLahir<<endl;
			cout<<"Ipk           : "<<mhs[a].ipk<<endl;
			cout<<"Dosen Wali    : "<<"Elsen Ronando, S.Si., M.Si., M.Sc."<<endl<<endl;
			cout<<"|------------------------------------------------------------------------------------------------------------------------------------|\n";	
			cout<<"|                                                        KRS MAHASISWA INFORMATIKA                                                   |\n";
			cout<<"|------------------------------------------------------------------------------------------------------------------------------------|\n";
			cout<<"|No| Kode Matkul |                   Matkul                     | Kelas |   SKS   |      Hari     |         Jam         |   Ruangan  |\n";
			cout<<"|------------------------------------------------------------------------------------------------------------------------------------|\n";
			if(mhs[a].c == 0){
			gotoxy(45,14);cout<<"DATA MASIH KOSONG"<<endl;			
			}
			else{
				for(i=0;i<mhs[a].c;i++){
				gotoxy(1,i+14);cout<<i+1;
			gotoxy(6,i+14);cout<<mhs[a].kls[i].kode;
			gotoxy(24,i+14);cout<<mhs[a].kls[i].matkul;
			gotoxy(68,i+14);cout<<mhs[a].kls[i].kelas;
			gotoxy(77,i+14);cout<<mhs[a].kls[i].sks;
			gotoxy(88,i+14);cout<<mhs[a].kls[i].hari;
			gotoxy(104,i+14);cout<<mhs[a].kls[i].jam;
			gotoxy(126,i+14);cout<<mhs[a].kls[i].ruang<<endl;
			}
		}
			cout<<"|------------------------------------------------------------------------------------------------------------------------------------|\n";
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

	kls[0].matkul = "GRAF DAN OTOMATA";
	kls[0].kode   = 14620063;
	kls[0].kelas  = "A";
	kls[0].sks    = 3;
	kls[0].hari   = "SENIN";
	kls[0].jam    = "12.00 - 14.30";
	kls[0].ruang  = "Q303";
	
	kls[1].matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
	kls[1].kode   = 14620083;
	kls[1].kelas  = "A";
	kls[1].sks    = 3;
	kls[1].hari   = "SENIN";
	kls[1].jam    = "09.30 - 12.00";
	kls[1].ruang  = "L602";
	
	kls[2].matkul = "MATEMATIKA KOMPUTASI";
	kls[2].kode   = 14620094;
	kls[2].kelas  = "A";
	kls[2].sks    =  2;
	kls[2].hari   = "SELASA";
	kls[2].jam    = "07.50 - 09.30";
	kls[2].ruang  = "L709";
	
	kls[3].matkul = "PEMROGRAMAN BERORIENTASI OBJEK FUNGSIONAL";
	kls[3].kode   = 14620074;
	kls[3].kelas  = "A";
	kls[3].sks    =  2;
	kls[3].hari   = "SELASA";
	kls[3].jam    = "09.30 - 11.10";
	kls[3].ruang  = "L801";
	
	kls[4].matkul = "GRAF DAN OTOMATA";
	kls[4].kode   = 14620063;
	kls[4].kelas  = "B";
	kls[4].sks    = 3;
	kls[4].hari   = "SENIN";
	kls[4].jam    = "07.50 - 09.30";
	kls[4].ruang  = "Q303";
	
	kls[5].matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
	kls[5].kode   = 14620083;
	kls[5].kelas  = "B";
	kls[5].sks    = 3;
	kls[5].hari   = "SELASA";
	kls[5].jam    = "09.30 - 12.00";
	kls[5].ruang  = "L602";
	
	kls[6].matkul = "MATEMATIKA KOMPUTASI";
	kls[6].kode   = 14620094;
	kls[6].kelas  = "B";
	kls[6].sks    =  2;
	kls[6].hari   = "RABU";
	kls[6].jam    = "07.50 - 09.30";
	kls[6].ruang  = "L709";
	
	kls[7].matkul = "PEMROGRAMAN BERORIENTASI OBJEK FUNGSIONAL";
	kls[7].kode   = 14620074;
	kls[7].kelas  = "B";
	kls[7].sks    =  2;
	kls[7].hari   = "RABU";
	kls[7].jam    = "09.30 - 11.10";
	kls[7].ruang  = "L801";
	
	kls[8].matkul = "GRAF DAN OTOMATA";
	kls[8].kode   = 14620063;
	kls[8].kelas  = "C";
	kls[8].sks    = 3;
	kls[8].hari   = "KAMIS";
	kls[8].jam    = "12.00 - 14.30";
	kls[8].ruang  = "Q303";
	
	kls[9].matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
	kls[9].kode   = 14620083;
	kls[9].kelas  = "C";
	kls[9].sks    = 3;
	kls[9].hari   = "KAMIS";
	kls[9].jam    = "09.30 - 12.00";
	kls[9].ruang  = "L602";
	
	kls[10].matkul = "MATEMATIKA KOMPUTASI";
	kls[10].kode   = 14620094;
	kls[10].kelas  = "C";
	kls[10].sks    =  2;
	kls[10].hari   = "SENIN";
	kls[10].jam    = "07.50 - 09.30";
	kls[10].ruang  = "L709";
	
	kls[11].matkul = "PEMROGRAMAN BERORIENTASI OBJEK FUNGSIONAL";
	kls[11].kode   = 14620074;
	kls[11].kelas  = "C";
	kls[11].sks    =  2;
	kls[11].hari   = "SENIN";
	kls[11].jam    = "09.30 - 11.10";
	kls[11].ruang  = "L801";
	
	kls[12].matkul = "GRAF DAN OTOMATA";
	kls[12].kode   = 14620063;
	kls[12].kelas  = "D";
	kls[12].sks    = 3;
	kls[12].hari   = "RABU";
	kls[12].jam    = "07.50 - 09.30";
	kls[12].ruang  = "Q303";
	
	kls[13].matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
	kls[13].kode   = 14620083;
	kls[13].kelas  = "D";
	kls[13].sks    = 3;
	kls[13].hari   = "RABU";
	kls[13].jam    = "09.30 - 12.00";
	kls[13].ruang  = "L602";
	
	kls[14].matkul = "MATEMATIKA KOMPUTASI";
	kls[14].kode   = 14620094;
	kls[14].kelas  = "D";
	kls[14].sks    =  2;
	kls[14].hari   = "KAMIS";
	kls[14].jam    = "07.50 - 09.30";
	kls[14].ruang  = "L709";
	
	kls[15].matkul = "PEMROGRAMAN BERORIENTASI OBJEK FUNGSIONAL";
	kls[15].kode   = 14620074;
	kls[15].kelas  = "D";
	kls[15].sks    =  2;
	kls[15].hari   = "KAMIS";
	kls[15].jam    = "09.30 - 11.10";
	kls[15].ruang  = "L801";
	
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
		if(username == mhs[i].nim && pass==mhs[i].tLahir ){
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
