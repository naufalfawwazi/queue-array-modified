#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

/*
UTS Praktikum Struktur Data
Naufal Fawwazi
A11.2020.12764
A11.43UG
*/

struct queue {
	char nama[10];
	int umur, x, y;
};

int head=1, tail=1, maxqueue=8, count=0;
queue warteg[8];

gotoxy(int x, int y) {
  COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

set_coor(int index) {
	switch(index) {
		case 0: warteg[index].x = 27; warteg[index].y = 2; break;
		case 1: warteg[index].x = 27; warteg[index].y = 8; break;
		case 2: warteg[index].x = 27; warteg[index].y = 14; break;
		case 3: warteg[index].x = 14; warteg[index].y = 14; break;
		case 4: warteg[index].x = 1; warteg[index].y = 14; break;
		case 5: warteg[index].x = 1; warteg[index].y = 8; break;
		case 6: warteg[index].x = 1; warteg[index].y = 2; break;
		default: warteg[index].x = 14; warteg[index].y = 2;
	}
}

delay() {
	for(int i=0; i<=500000; i++) cout<<"";
}

printQ() {
	for(int i=0; i<maxqueue; i++) {
		if(warteg[i].umur != 0) {
			gotoxy(warteg[i].x,warteg[i].y);  cout<<warteg[i].nama;
			gotoxy(warteg[i].x,warteg[i].y+1);cout<<warteg[i].umur;
		}
	}
}

in(queue Q) {
	for(int x=63; x>=Q.x; x--) {
		gotoxy(x,15); cout<<Q.nama; gotoxy(x,16); cout<<Q.umur;
		delay();
		gotoxy(x,15); cout<<"          "; gotoxy(x,16); cout<<"     ";
	}
	for(int y=15; y>=Q.y; y--) {
		gotoxy(Q.x,y); cout<<Q.nama; gotoxy(Q.x,y+1); cout<<Q.umur;
		delay();
		gotoxy(Q.x,y); cout<<"          "; gotoxy(Q.x,y+1); cout<<"     ";
	} printQ();
}

quit(queue Q) {
	for(int y=Q.y; y<=15; y++) {
		gotoxy(Q.x,y); cout<<Q.nama; gotoxy(Q.x,y+1); cout<<Q.umur;
		delay();
		gotoxy(Q.x,y); cout<<"          "; gotoxy(Q.x,y+1); cout<<"     ";
	}
	for(int x=Q.x; x<=65; x++) {
		gotoxy(x,15); cout<<Q.nama; gotoxy(x,16); cout<<Q.umur;
		delay();
		gotoxy(x,15); cout<<"          "; gotoxy(x,16); cout<<"     ";
	} warteg[head-1].umur = 0; printQ();
}

enqueue(int x) { //x = tail
	if(head == tail && count == maxqueue) {
		gotoxy(41,10); cout<<"Gagal Enqueue, Antrian penuh!"; getch();
	} else {
		gotoxy(55,13); cout<<"Proses Enqueue";
		gotoxy(55,15); cout<<"Nama : "; cin>>warteg[x-1].nama;
		do {
			gotoxy(55,16); cout<<"          ";
			gotoxy(55,16); cout<<"Umur : "; cin>>warteg[x-1].umur;
		} while(warteg[x-1].umur < 1);
		set_coor(x-1); in(warteg[x-1]);
		tail = (tail >= maxqueue) ? 1 : tail + 1;
		count++;
	}
}

dequeue(int x) { //x = head
	if(head == tail && count == 0) {
		gotoxy(41,10); cout<<"Gagal Dequeue, Antrian kosong!"; getch();
	} else {
		quit(warteg[x-1]);
		head = (head >= maxqueue) ? 1 : head + 1;
		count--;
	}
}

display() {
	gotoxy(50,9); cout<<"DISPLAY DATA ANTRIAN";
	for(int i=0; i<maxqueue; i++) {
		if(warteg[i].umur != 0) {
			gotoxy(50,i+10); cout<<i+1<<". "<<warteg[i].nama<<" "<<warteg[i].umur;
		} else {
			gotoxy(50,i+10); cout<<i+1<<".";
		}
	} getch();
}

kotak(int x1, int y1, int x2, int y2) {
	int x;
	for(x=x1;x<x2;x++) {
    gotoxy(x,y1);printf("%c",196);
    gotoxy(x,y2);printf("%c",196);
	}
	for(x=y1;x<y2;x++) {
    gotoxy(x1,x);printf("%c",179);
    gotoxy(x2,x);printf("%c",179);
  }
	gotoxy(x1,y1);printf("%c",218);
	gotoxy(x2,y1);printf("%c",191);	
	gotoxy(x2,y2);printf("%c",217);	
	gotoxy(x1,y2);printf("%c",192);	
}

clear() {
	for(int y=7; y<=17; y++) {
		gotoxy(40,y); cout<<"                                         ";
	}
}

show() {
	for(int x=0; x<=26; x+=13) {
		for(int y=0; y<=12; y+=6) kotak(x,y,x+11,y+5);
	}
	gotoxy(14,7); cout<<"UTS S.DATA";
	gotoxy(14,8); cout<<"NAUFAL";
	gotoxy(17,9); cout<<"FAWWAZI";
	gotoxy(14,10); cout<<"12764-43UG";
	kotak(40,0,70,5); kotak(40,6,70,8);
	kotak(40,12,42,17); kotak(43,12,45,17);
	gotoxy(41,13); cout<<"Q"; gotoxy(44,14); cout<<"I";
	gotoxy(41,14); cout<<"U"; gotoxy(44,15); cout<<"N";
	gotoxy(41,15); cout<<"I"; gotoxy(41,16); cout<<"T";
	gotoxy(27,1); cout<<" 1"; gotoxy(27,7); cout<<" 2"; gotoxy(27,13); cout<<" 3";
	gotoxy(14,1); cout<<" 8"; gotoxy(14,13); cout<<" 4";
	gotoxy(1,1); cout<<" 7"; gotoxy(1,7); cout<<" 6"; gotoxy(1,13); cout<<" 5";
}

int main() {
	int pilih;
	do {
		clear();
		show();
		gotoxy(47,0);cout<<"MENU UTAMA ANTRIAN";
		gotoxy(41,1);cout<<"1. Enqueue";
		gotoxy(41,2);cout<<"2. Dequeue";
		gotoxy(41,3);cout<<"3. Display Data";
		gotoxy(41,4);cout<<"4. Exit";
		gotoxy(41,7);cout<<"Inputkan Pilihan Anda : ";cin>>pilih;
		if(pilih==1) enqueue(tail);
		if(pilih==2) dequeue(head);
		if(pilih==3) display();
	} while(pilih != 4); gotoxy(80,20);
	
	return 0;
}
