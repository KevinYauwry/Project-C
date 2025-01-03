#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

struct nsbh
{
	string rek, nama;
	string pin, status;
	int saldo = 100000;
	float transfer, tt, ts;
	
}nasabah[10];

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int i,k=-1,n;
string SW="awal";

void input(int k)
{
	string ulang;
	ulang="y";
	if(SW=="awal")
	i=0;
	system("cls");
	cout<<"--- Pendaftaran Nasabah Baru ---"<<endl;
	while (ulang=="y"){	
		cout<<endl;
		cout<<"Nomor Rekening	: ";
		getline(cin,nasabah[i].rek);
		cout<<"Nama		: ";
		getline(cin,nasabah[i].nama);
		cout<<"Pin		: ";
		getline(cin,nasabah[i].pin);
		nasabah[i].status="Aktif";
		cout<<endl;
		SW="akhir";
		cout<<"Lagi y/t = ";getline(cin,ulang);
		i++;k=i;
}
	}
	
	
void lihat(int k)
{
	system("cls");
	if(k==0)
	{
		cout<<"Data Masih Kosong"<<endl;
		cout<<"Tekan ENTER untuk kembali";
		getch();
		}
	else
	{
		cout<<"---------- DATA NASABAH -------------"<<endl<<endl;
		cout<<" No	Nama       	No Rekening	   PIN	Saldo         Status"<<endl;
		cout<<"----------------------------------------------------------------------------";
		for(i=0;i<k;i++){
			gotoxy(1,i+4);cout<<i+1;
			gotoxy(9,i+4);cout<<nasabah[i].nama;
			gotoxy(27,i+4);cout<<nasabah[i].rek;
			gotoxy(43,i+4);cout<<nasabah[i].pin;
			gotoxy(49,i+4);cout<<"Rp. "<<nasabah[i].saldo;
			gotoxy(62,i+4);cout<<nasabah[i].status;
	}
}getch();
}

void edit(int k)
	{	
	string newdata;
	system("cls");
	if(k==0){
		cout<<"DATA MASIH KOSONG"<<endl;
		cout<<"Tekan ENTER untuk kembali";
		getch();
	}
	else {
	editawal:
	system("cls");
	cout<<"Masukkan No Rekening yang akan di edit	:";
	getline(cin,newdata);
	for(i=0;i<k;i++)
	{
	if(newdata==nasabah[i].rek){
	cout<<" No   Nama                 No Rekening	 Pin	 Saldo         Status"<<endl;
		cout<<"----------------------------------------------------------------"<<endl;
		gotoxy(2,4);cout<<i+1;
		gotoxy(6,4);cout<<nasabah[i].nama;
		gotoxy(25,4);cout<<nasabah[i].rek;
		gotoxy(41,4);cout<<nasabah[i].pin;
		gotoxy(49,i+4);cout<<"Rp. "<<nasabah[i].saldo;
		gotoxy(62,i+4);cout<<nasabah[i].status;
		cout<<endl;
		cout<<endl;
		string pilihan;
		while(pilihan!="4")
		{
		cout<<"1. Untuk Nama"<<endl;
		cout<<"2. Untuk No Rekening"<<endl;
		cout<<"3. Untuk PIN"<<endl;
		cout<<"4. Untuk Kembali"<<endl;
		cout<<"Pilih data yang akan diedit	: ";getline(cin,pilihan);
	string namabaru;
	string rekbaru;
	string pinbaru;

	if(pilihan=="1"){
	cout<<"Ubah Data"<<endl;
	cout<<"Nama	:";
	getline(cin,namabaru);
	nasabah[i].nama = namabaru;
	cout<<"Data telah di edit"<<endl<<endl;
	}
	if(pilihan=="2"){
	cout<<"Ubah Data"<<endl;
	cout<<"No Rekening	:";
	getline(cin,rekbaru);
	nasabah[i].rek = rekbaru;
	cout<<"Data telah di edit"<<endl<<endl;
	}
	if(pilihan=="3"){
	cout<<"Ubah Data"<<endl;	
	cout<<"Pin	:";
	getline(cin,pinbaru);
	nasabah[i].pin = pinbaru;
	cout<<"Data telah di edit"<<endl<<endl;
	}
	break;
	}
	}	
	else if(newdata!=nasabah[i].rek)
	{
	cout<<"Data Tidak Ditemukan"<<endl;
	}
	}
	
}
getch();
}

void cari(int k)
{
	string carirek;
	system("cls");
	if(k==0)
	{
	cout<<"Data Masih Kosong"<<endl;
	cout<<"Tekan ENTER untuk kembali";
	getch();
	}
	else{
	system("cls");
	string ulang;
	ulang="y";
	if(SW=="awal")
	i=0;
	
	while (ulang=="y"){
	system("cls");
	cout<<"Masukkan No Rekening Nasabah	:";
	getline(cin,carirek);
	for(i=0;i<k;i++){
			if (carirek==nasabah[i].rek)
			{
			
		cout<<endl;
		cout<<" No   Nama                 No Rekening	 Pin	Saldo         Status"<<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		gotoxy(2,4);cout<<i+1;
		gotoxy(6,4);cout<<nasabah[i].nama;
		gotoxy(25,4);cout<<nasabah[i].rek;
		gotoxy(41,4);cout<<nasabah[i].pin;
		gotoxy(49,i+4);cout<<"Rp. "<<nasabah[i].saldo;
		gotoxy(62,i+4);cout<<nasabah[i].status;
		 cout<<endl;
		 }else { 
		 	cout<<"Tidak Ada Data"<<endl;
	    	}
		 
		 }
	SW="akhir";
	cout<<"Lagi y/t = ";getline(cin,ulang);
}
}
}

void hapus(int k)
{
		if(k==0){
		cout<<"Belum Ada Data";
		cout<<endl;
	}

	else {
	string hps;
	string konfirm;
	cout<<"Masukkan No Rekening yang ingin di hapus	: ";
	getline(cin,hps);

	for(i=0;i<k;i++){
		if(hps==nasabah[i].rek){
			cout<<"Nama	: "<<nasabah[i].nama<<endl;
			cout<<"NIM	: "<<nasabah[i].rek<<endl;
			cout<<"Alamat	: "<<nasabah[i].pin<<endl;
		cout<<"Apakah anda yakin ingin menghapus data? "<<endl;
		cout<<"y/t	: ";
		getline(cin,konfirm);
		if(konfirm=="y"){
			nasabah[i].status="Tidak Aktif";
			cout<<"Data Telah dihapus";
			}
			}
		}
	}
	getch();
}

void nasbh(int k)
{
	string nasrek;
	string naspin;
	string pilih;
	
	menu:
	system("cls");
	cout<<"Masukkan No Rekening anda : ";
		cin>>nasrek;
	for(i=0;i<k;i++)
	{	
		if(nasrek==nasabah[i].rek)
		{
			if(nasabah[i].status=="Tidak Aktif"){
				cout<<"Rekening Anda Tidak Aktif";
				getch();
				goto menu;
			}
			else{
			cout<<"Masukan PIN anda          : ";
			cin>>naspin;
			if(naspin==nasabah[i].pin)
			{
				
			while(pilih!="7")
			{
				atas:
			system("cls");
			cout<<"__________________________________"<<endl;
			cout<<"SELAMAT DATANG DI BANK UNTAG SBY"<<endl;
			cout<<"              MENU"<<endl;
			cout<<"__________________________________"<<endl;
			cout<<"1. Cek Saldo"<<endl;
			cout<<"2. Tarik Tunai"<<endl;
			cout<<"3. Setor Tunai"<<endl;
			cout<<"4. Ubah Pin"<<endl;
			cout<<"5. Transfer"<<endl;
			cout<<"6. Login Nasabah Lain"<<endl;
			cout<<"7. Keluar"<<endl;
			cout<<"Pilih Menu : ";
			cin>>pilih;
			
			if (pilih=="1")
			{
				system("cls");
				cout<<"Saldo anda adalah : Rp."<<nasabah[i].saldo;
				getch();	
			}
			if (pilih=="2")
			{
				int keluar;
				system("cls");
				cout<<"Masukkan nominal yang ingin di tarik = Rp. ";
				cin>>keluar;
	
				if(keluar > nasabah[i].saldo)
				{
					cout<<"Saldo anda tidak cukup.";
				}
				else
				{		
				nasabah[i].saldo = nasabah[i].saldo - keluar;	
				cout<<"Transaksi Berhasil"<<endl;
				cout<<"Saldo anda saat ini = Rp. "<<nasabah[i].saldo;
				}
				getch();
			}
			if (pilih=="3")
			{
				system("cls");
				int masuk;
				cout<<"Masukan nominal yang akan di setor : Rp. ";
				cin >> masuk;
				nasabah[i].saldo = nasabah[i].saldo + masuk;
				cout<<"Transaksi telah berhasil"<<endl;
				cout<<"Saldo anda sekarang = Rp. "<<nasabah[i].saldo;
				getch();	
			}
			if (pilih=="4")
			{
				string pinsebelum;
				string pinbaru;
				pin:
				system("cls");
				cout<<"Masukkan PIN awal anda : ";
				cin>>pinsebelum;
				if(pinsebelum==nasabah[i].pin)
				{
				cout<<"Masukan PIN baru anda : ";
				cin>>pinbaru;
				nasabah[i].pin=pinbaru;
				cout<<"PIN anda berhasil diubah.";
				}
				else{
				if(pinsebelum!=nasabah[i].pin)
				{
				cout<<"PIN yang anda masukan salah";
				getch();
				goto pin;
				}
				
			}getch();
			}
			if(pilih=="5")
			{
				string input;
				string jawab;
                        mn4:
                        	system("cls");
                        cout<<"\nMasukan Nomor Rekening Tujuan : ";cin>>input;
                        for (n=0;n<=k;n++){
                            if (input==nasabah[n].rek){
                                cout<<"___________________________________________________________"<<endl;
                                cout<<"Nomor Rekening : "<<nasabah[n].rek<<endl;
                                cout<<"Nama Lengkap   : "<<nasabah[n].nama<<endl;
                                cout<<"\nMasukan jumlah Transfer : Rp.";cin>>nasabah[n].transfer;
                                tanya5:
                                cout<<"\nData Sudah Benar ?";
                                cout<<"\nProses Transfer ? (y/t) : ";cin>>jawab;
                                if (jawab=="y" || jawab=="Y"){
                                    if (nasabah[i].saldo-nasabah[n].transfer<20000){
                                        system("cls");
                                        cout<<"___________________________________________________________"<<endl;
                                        cout<<"Maaf Saldo Anda Tidak Mencukupi\n";
                                        cout<<"Sisa Saldo Minimal Rp.20.000\n";
                                    }else{
                                        nasabah[i].saldo=nasabah[i].saldo-nasabah[n].transfer;
                                        nasabah[n].saldo=nasabah[n].transfer+nasabah[n].saldo;
                                        nasabah[n].tt=nasabah[n].transfer+nasabah[n].tt;
                                        nasabah[i].ts=nasabah[n].transfer+nasabah[i].ts;
                                        system("cls");
                                        cout<<"___________________________________________________________"<<endl;
                                        cout<<"Transfer Berhasil Diperoses\n";
                                        cout<<"Terima Kasih\n";
                                        cout<<"___________________________________________________________"<<endl;
                                        cout<<"\n Sisa Saldo : "<<nasabah[i].saldo<<endl;
                                    }
									tanya7:
              cout<<"___________________________________________________________"<<endl;
              cout<<"Kembali ke Menu Nasabah ? (y/t) : ";cin>>jawab;
              if (jawab=="y"||jawab=="Y")
               {
                goto atas;
               }
              else if (jawab=="t"||jawab=="t")
               {
                goto mn4;
               }
              else
               {
                cout<<"Input Salah !!!\n";
                goto tanya7;
               }
             }
             else if (jawab=="t"||jawab=="T")
             {
              goto mn4;
             }
             else
             {
              cout<<"Input Salah !!!\n";
              goto tanya7;
             }
            }
          }
         cout<<"tNomor Rekening tidak terdaftar !!!\n";
         tanya6:
         cout<<"Kembali Ke Menu ? (y/t) : ";cin>>jawab;
         if (jawab=="y"||jawab=="Y")
          {
           goto atas;
          }
         else if (jawab=="t"||jawab=="T")
          {
           goto mn4;
          }
         else
          {
           cout<<"Input Salah !!!\n";
           goto tanya6;
          }
         getch();
			}
			
			if(pilih=="6")
			{
				goto menu;
			}
			}exit(0);
			}
			else if(naspin!=nasabah[i].pin)
			{
			cout<<"PIN anda salah.";
			getch();
			goto menu;
			}
		}
	}
	}getch();
	if(nasrek!=nasabah[i].pin)
		{
			cout<<"No Rekening Salah.";
			getch();
			goto menu;
		}
		getch();
		
}

int main()
{
	string pilihadmin;
	string pin;
	string admin;
	string pinawal;
	awal:
	system("cls");
	cout<<"Masukkan Nomor Rekening : ";
	getline(cin,admin);
	
	if(admin=="admin")
	{
		cout<<"Masukan PIN             : ";
		getline(cin,pin);
		if(pin=="pin")
		{
			while(pilihadmin!="7")
			{
				system("cls");
			cout<<"__________________________________"<<endl;
			cout<<"SELAMAT DATANG DI BANK UNTAG SBY"<<endl;
			cout<<"              ADMIN"<<endl;
			cout<<"__________________________________"<<endl<<endl;
			cout<<"MENU ADMIN"<<endl<<endl;
			cout<<"1. Tambah Nasabah"<<endl;
			cout<<"2. Lihat Data Nasabah"<<endl;
			cout<<"3. Edit Data Nasabah"<<endl;
			cout<<"4. Cari Nasabah"<<endl;
			cout<<"5. Hapus Nasabah"<<endl;
			cout<<"6. Menu Nasabah"<<endl;
			cout<<"7. Keluar"<<endl;
			cout<<"Pilih Menu : ";
			getline(cin,pilihadmin);
			if(pilihadmin=="1")
			input(i);
			if(pilihadmin=="2")
			lihat(i);
			if(pilihadmin=="3")
			edit(i);
			if(pilihadmin=="4")
			cari(i);
			if(pilihadmin=="5")
			hapus(i);
			if(pilihadmin=="6")
			nasbh(i);
			}
		}
		if (pin!="pin")
		{
			cout<<"Pin Anda Salah";
			getch();
			goto awal;
		}
	}
	if(admin!="admin")
	{
		cout<<"Rekening Anda Salah"<<endl;
		getch();
		goto awal;
	}
	getch();
	return 0;
	}
