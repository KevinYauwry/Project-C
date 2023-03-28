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

int i, k, j = 0, awal = 0, l;

void mhsData(int k){
	for(i = 1; i < k;i++){
		cout<<mhs[i].nama<<endl;
		cout<<mhs[i].nim<<endl;
		cout<<mhs[i].prodi<<endl;
		cout<<mhs[i].ipk<<endl;
	}
	getch();
}

void mhsCari(int k){
	int cariNim;
	int ketemu = 0;
	system("cls");
	cout<<"CARI DATA MAHASISWA"<<endl;
	cout<<"Masukkan Nim : ";
	cin>>cariNim;
	for(int i = 1; i < k;i++){
		if(cariNim == mhs[i].nim){
			ketemu = 1;
			cout<<mhs[i].nama<<endl;
			cout<<mhs[i].nim<<endl;
			cout<<mhs[i].prodi<<endl;
			cout<<mhs[i].ipk<<endl;
		}
	}
	if(ketemu == 0){
		cout<<"Data Mahasiswa tidak ditemukan"<<endl;
	}
	getch();
}

int main(){
	int pil;
	if (awal == 0){
		j =1;
		mhs[j].nama  = "Kevin Yauwry";
		mhs[j].ipk   = "4.00";
		mhs[j].prodi = "Teknik Informatika";
		mhs[j].nim   = 164;
		awal++;
		i=2;
	}
	while(pil!=5){
		cout<<"MENU KRS"<<endl;
		cout<<"1. Lihat Data Mahasiswa"<<endl;
		cout<<"2. Cari Mahasiswa"<<endl;
		cout<<"3. Lihat Data Dosen"<<endl;
		cout<<"4. Cari Dosen"<<endl;
		cout<<"5. Keluar"<<endl;
		cout<<"Pilih : ";cin>>pil;
		if(pil==1)
		mhsData(i);
		if(pil==2)
		mhsCari(i);
	}
}
