#include<iostream>
#include<conio.h>
using namespace std;

struct mahasiswa{
	string nama, prodi, ipk;
	int nim;
}mhs[10];

struct dosen{
	string nama;
	int nidn;
}dsn[10];

int i;

void mhsData(){
	mhs[0].nama = "Kevin Yauwry";
	mhs[0].ipk = "4.00";
	mhs[0].prodi = "Teknik Informatika";
	mhs[0].nim = 1462200164;
	i++;
}

void mhsCari(){
	string cariNim;
	system("cls");
	cout<<"CARI DATA MAHASISWA"<<endl;
	cout<<"Masukkan Nim : ";
	cin>>CariNim;
	for(int i = 0;i<10;i++){
		if(cariNim==mhs[i].nim){			
			cout<<mhs[i].nama<<endl;
			cout<<mhs[i].nim<<endl;
			cout<<mhs[i].prodi<<endl;
			cout<<mhs[i].prodi<<endl;
		}
	}
}

int main(){
	int pil;
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
