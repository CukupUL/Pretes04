/*
Program		: Sorting Singly Linked List
Nama		: Nurul Ma'arif
NPM	/ Kelas	: 140810180040
Deskripsi	: Program ini berfungsi untuk mengurutkan list berdasarkan nama.
Tanggal		: 2019/03/27
*/
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct ElemtList{
	char npm[14];
	char nama[40];
	float ipk;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
	First=NULL;
}
void createElmt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"Nama\t: ";cin.getline(pBaru->nama,40);
	cout<<"NPM\t: ";cin.getline(pBaru->npm,14);
	cout<<"Nilai\t: ";cin>>pBaru->ipk;
	pBaru->next=NULL;
}
void insertSortNama(List& First, pointer pBaru){
	pointer pBantu;
	if(First==NULL){
		First=pBaru;
	}else{
		pBantu=First;
		while(strcmp(pBantu->nama,pBaru->nama)<1){
			pBantu=pBantu->next;
		};
		if(pBantu==First){
			pBaru->next=First;
			First=pBaru;
		}
	}
}
void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
		cout<<setfill('=')<<setw(70)<<"\n"
		<<setfill(' ')<<"No"<<setw(5)<<"NPM"<<setw(15)
		<<"Nama"<<setw(40)<<"IPK"<<setw(6)<<"\n"
		<<setfill('-')<<setw(70)<<"\n";
		do{
			cout<<setfill(' ')<<i<<setw(5)<<setw(15)<<pBantu->npm
			<<setw(40)<<pBantu->nama<<setw(6)<<pBantu->ipk<<"\n";
			pBantu=pBantu->next;
			i++;
		}while(pBantu!=NULL);
		cout<<setfill('=')<<setw(70)<<"\n";
	}
	cout<<endl;
}

int main(){
	pointer p;
	List mahasiswa;
	createElmt(p);
	insertSortNama(mahasiswa,p);
	traversal(mahasiswa);
}
