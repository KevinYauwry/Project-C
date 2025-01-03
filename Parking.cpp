#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

using namespace std;

// Febry Tri Harkasa (1462200154)
// Kevin Yauwry      (1462200164)

struct parkir{
	string plat, masuk, keluar, ruang, status;
}prk[10];

int i, k, j;

//Void untuk gotoxy
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Void milik Petugas Masuk
void pm(int k){
	string pil1, isiPlat;
	int ketemu0 = 0;
	pil1 = "y";
	while(pil1 == "y" || pil1 == "Y"){
		system("cls");
		cout<<"\n\n\t\t*********************************\n";
		cout<<"\t\t*     SELAMAT DATANG P.RUANG    *\n";
		cout<<"\t\t*********************************\n";
		cout<<"\t\t*      INPUT PLAT NOMOR DAN     *\n";
		cout<<"\t\t*      JAM MASUK KERNDARAAN     *\n";
		cout<<"\t\t*********************************\n\n";
		cout<<" No   Plat Nomor   Jam Masuk   Jam Keluar   Ruangan     Status\n";
		cout<<"----------------------------------------------------------------\n";
		if(k==0){
			gotoxy(21,i+11);cout<<"Data Masih Kosong\n";
		}
		else{
			for(i=0;i<k;i++){
				gotoxy(1,i+11);cout<<i+1<<endl;
				gotoxy(6,i+11);cout<<prk[i].plat<<endl;
				gotoxy(21,i+11);cout<<prk[i].masuk<<endl;
				gotoxy(34,i+11);cout<<prk[i].keluar<<endl;
				gotoxy(46,i+11);cout<<prk[i].ruang<<endl;
				gotoxy(55,i+11);cout<<prk[i].status<<endl;
			}
		}
		cout<<"----------------------------------------------------------------\n";
		cout<<"Masukkan Plat Nomor Kendaraan : ";
		getline(cin,isiPlat);		
		for(i = 0; i < k; i++){
			if(isiPlat == prk[i].plat){
				if(prk[i].status == "Menginap"){
					ketemu0 = 1;
					cout<<"*********************************\n";
					cout<<"Plat Nomor Kendaraan Masih Dalam\nStatus Menginap\n";
				}
			}
		}
		if (ketemu0 == 0){
			prk[i].plat = isiPlat;
			cout<<"Masukkan Jam Masuk Kendaraan  : ";
			getline(cin, prk[i].masuk);
			prk[i].status = "Menginap";
			prk[i].ruang = " ";
			prk[i].keluar = " ";
			cout<<"*********************************\n";
			cout<<"Data Berhasil Ditambahkan\n";
			i ++;
			k = i;
		}
		ketemu0 = 0;
		cout<<"*********************************\n";
		cout<<"Lagi Y/T : ";
		getline(cin, pil1);
		cout<<endl;
	}
}

//Void milik Petugas Ruang
void pr(int k){
	string cPlat1, pil2, isiRuang;
	int ketemu1 = 0, ketemu2 = 0;
	pil2 = "y";
	while(pil2 == "y" || pil2 == "Y"){
		system("cls");
		cout<<"\n\n\t\t*********************************\n";
		cout<<"\t\t*     SELAMAT DATANG P.RUANG    *\n";
		cout<<"\t\t*********************************\n";
		cout<<"\t\t*       INPUT RUANG PARKIR      *\n";
		cout<<"\t\t*********************************\n\n";
		cout<<" No   Plat Nomor   Jam Masuk   Jam Keluar   Ruangan     Status\n";
		cout<<"----------------------------------------------------------------\n";
		if(k==0){
			gotoxy(21,i+10);	cout<<"Data Masih Kosong\n";
		}
		else{
			for(i=0;i<k;i++){
				gotoxy(1,i+10);cout<<i+1<<endl;
				gotoxy(6,i+10);cout<<prk[i].plat<<endl;
				gotoxy(21,i+10);cout<<prk[i].masuk<<endl;
				gotoxy(34,i+10);cout<<prk[i].keluar<<endl;
				gotoxy(46,i+10);cout<<prk[i].ruang<<endl;
				gotoxy(55,i+10);cout<<prk[i].status<<endl;
			}
		}
		cout<<"----------------------------------------------------------------\n";
		cout<<"Keterangan Kode Q1-Q10\n"; 
		cout<<"*********************************\n";
		cout<<"Masukkan Plat Nomor Kendaraan : ";
		getline(cin,cPlat1);
		for(i = 0; i < k; i ++){
			if(cPlat1 == prk[i].plat){
				if(prk[i].status == "Menginap"){
					ketemu1 = 1;
					cout<<"*********************************\n";
					cout<<"Plat Nomor Kendaraan  : "<<prk[i].plat;
					cout<<"\nJam Masuk Kendaraan   : "<<prk[i].masuk;
					cout<<"\nKode Ruangan Parkir   : ";
					getline(cin, isiRuang);
					for(j = 0; j < k; j++){						
						if(isiRuang==prk[j].ruang){
							ketemu2 = 1;
							if(prk[j].status=="Menginap"){
								cout<<"*********************************\n";
								cout<<"Kode Ruang Parkir Sudah Digunakan\n";							
							}
						}
					}
					if(ketemu2==0){
						if(isiRuang=="Q1"||isiRuang=="Q2"||isiRuang=="Q3"||isiRuang=="Q4"||isiRuang=="Q5"||isiRuang=="Q6"||isiRuang=="Q7"||isiRuang=="Q8"||isiRuang=="Q9"||isiRuang=="Q10"){
							prk[i].ruang = isiRuang;
							cout<<"*********************************\n";
							cout<<"Data Kode Ruang Parkir\nBerhasil Dimasukkan\n";
						}
						else{
							cout<<"*********************************\n";
							cout<<"Data Kode Ruang Parkir Tidak Ada\nKeterangan Kode Q1-Q10\n";
						}
					}	
				}
			}
		}
		if(ketemu1 == 0){
			cout<<"*********************************\n";
			cout<<"Plat Nomor Kendaraan Tidak  Ada /\n";
			cout<<"      Tidak Dalam Status Menginap\n";
		}
		cout<<"*********************************\n";
		ketemu1 = 0;
		ketemu2 = 0;
		cout<<"Lagi Y/T : ";
		getline(cin, pil2);
		cout<<endl;
	}
}

//Void milik Petugas Keluar
void pk(int k){
	string cPlat2, pil3, isiJamKeluar;
	int ketemu3 = 0;
	pil3 = "y";
	while(pil3 == "y" || pil3 == "Y"){
		system("cls");
		cout<<"\n\n\t\t*********************************\n";
		cout<<"\t\t*    SELAMAT DATANG P.KELUAR    *\n";
		cout<<"\t\t*********************************\n";
		cout<<"\t\t*        INPUT JAM KELUAR       *\n";
		cout<<"\t\t*********************************\n\n";
		cout<<" No   Plat Nomor   Jam Masuk   Jam Keluar   Ruangan     Status\n";
		cout<<"----------------------------------------------------------------\n";
		if(k==0){
			gotoxy(21, i + 10);cout<<"Data Masih Kosong\n";
		}
		else{
			for(i = 0; i < k; i ++){
				gotoxy(1,i+10);cout<<i+1<<endl;
				gotoxy(6,i+10);cout<<prk[i].plat<<endl;
				gotoxy(21,i+10);cout<<prk[i].masuk<<endl;
				gotoxy(34,i+10);cout<<prk[i].keluar<<endl;
				gotoxy(46,i+10);cout<<prk[i].ruang<<endl;
				gotoxy(55,i+10);cout<<prk[i].status<<endl;
			}
		}
		cout<<"----------------------------------------------------------------\n";
		cout<<"Masukkan Plat Nomor Kendaraan : ";
		getline(cin,cPlat2);
		for(i = 0; i < k; i ++){
			if(cPlat2 == prk[i].plat){
				if(prk[i].status == "Menginap"){
					ketemu3 = 1;
					cout<<"*********************************\n";	
					cout<<"Plat Nomor Kendaraan : "<<prk[i].plat;
					cout<<"\nKode Ruang Parkir    : "<<prk[i].ruang;
					cout<<"\nJam Masuk Kendaraan  : "<<prk[i].masuk;
					cout<<"\nJam Keluar Kendaraan : ";
					getline(cin, isiJamKeluar);
					prk[i].keluar = isiJamKeluar;
					prk[i].status = "Keluar";
					prk[i].ruang = " ";
					cout<<"*********************************\n";
					cout<<"Data Jam Keluar Kendaraan\nBerhasil Dimasukkan\n";
				}
			}
		}
		if(ketemu3 == 0){
			cout<<"*********************************\n";
			cout<<"Plat Nomor Kendaraan Tidak Ada / \n";
			cout<<"      Tidak Dalam Status Menginap\n";
		}
		cout<<"*********************************\n";
		ketemu3 = 0;
		cout<<"Lagi Y/T : ";
		getline(cin, pil3);
		cout<<endl;
	}
}

//Void milik Admin
void admin(int k){
	system("cls");
	cout<<"\n\n\t\t*********************************\n";
	cout<<"\t\t*      SELAMAT DATANG ADMIN     *\n";
	cout<<"\t\t*********************************\n";
	cout<<"\t\t*      DATA PENGGUNA PARKIR     *\n";
	cout<<"\t\t*********************************\n\n";
	cout<<" No   Plat Nomor   Jam Masuk   Jam Keluar   Ruangan     Status\n";
	cout<<"----------------------------------------------------------------\n";
	if(k == 0){
		gotoxy(21,i+10);cout<<" Data Masih Kosong\n";
	}
	else{
		for(i = 0; i < k; i ++){
			gotoxy(1,i+10);cout<<i+1<<endl;
			gotoxy(6,i+10);cout<<prk[i].plat<<endl;
			gotoxy(21,i+10);cout<<prk[i].masuk<<endl;
			gotoxy(34,i+10);cout<<prk[i].keluar<<endl;
			gotoxy(46,i+10);cout<<prk[i].ruang<<endl;
			gotoxy(55,i+10);cout<<prk[i].status<<endl;
		}
	}
	cout<<"----------------------------------------------------------------\n";
	cout<<"Tekan Enter Untuk Kembali";
	getch();
}

//Halaman login	
int main(){
	string username, pass, ulang;
	while(ulang != "3"){
		system("cls");
		cout<<"\n\n\t\t*********************************\n";
		cout<<"\t\t*  HALAMAN LOGIN SISTEM PARKIR  *\n";
		cout<<"\t\t*********************************\n";
		cout<<"\t\t*                               *\n";
		cout<<"\t\t*    Username :                 *\n";
		cout<<"\t\t*    Password :                 *\n";
		cout<<"\t\t*                               *\n";
		cout<<"\t\t*********************************\n";
		gotoxy(12,10);cout<<"Username : exit / EXIT Untuk Keluar Program";
		gotoxy(33,6);getline(cin, username);
		gotoxy(33,7);getline(cin, pass);
		//Username dan password Admin
		if(username=="admin" && pass == "admin"){
			admin(i);
		}
		//Username dan password Petugas Masuk
		else if(username == "masuk" && pass == "123"){
			pm(i);
		}
		//Username dan password Petugas Ruang
		else if(username == "ruang" && pass == "456"){
			pr(i);
		}
		//Username dan password Petugas Keluar
		else if(username == "keluar" && pass == "789"){
			pk(i);	
		}
		//Username untuk keluar program
		else if(username == "exit"||username == "EXIT"){
			cout<<"\n\n\n";
			return 0;
		}
		//Username atau password ketika salah
		else{
			gotoxy(18,8);cout<<"Username /Password Anda Salah";
			getch();
		}
	}	
}

