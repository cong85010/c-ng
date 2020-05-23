#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#define file_book "book.txt"

const char KiTu1 = 178;
const char KiTu2 = 175;

using namespace std;
int Sach_Thu = 0;
struct Book {
	string ten_Book;
	string hoTen_tg;
	string namSinh_tg;
	string theLoai;
};
   
void menu();
void Selection(Book bk[]);
void AddBooks(Book bk[]);
void CatPhan();
void LayThongTin(Book bk[]);
int Question();
void clearScreen();
void DeleteBooks(Book bk[]);

int main()
{
	//Khai bao book kieu Book
	struct Book book[20];
	do {
		Sach_Thu = 0;
		LayThongTin(book);
		menu();
		Selection(book);


		if (!Question())
			exit(0);
		clearScreen();
	} while (1);
}

int Question()
{
	int x;
	cout << "\n\n\n\n\t\t\t\t\t";
	cout << "Ban co muon thuc hien tiep khong :";
x1:	cout << "\n\t\t\t\t\t\t";
	cout << "1. Co \t 2. Khong";
	cout << "\n\t\t\t\t\tBan chon : ";

	cin >> x;
	if (x == 1 || x == 2)
	{
		if (x == 1)
			return 1;
		return 0;
	}
	else
	{
		cout << "\n\t\t\t\t\t";
		cout << "Nhap Sai;";
		goto x1;
	}
}

void clearScreen()
{
	for (int i = 0; i < 10; i++)
		cout << "\n\n\n\n\n\n\n";
}
void LayThongTin(Book bk[])
{
	fstream thongTin;
	thongTin.open(file_book, ios::in);

	if (thongTin.fail())
	{
		cout << "Khong tim thay FILE !!!";
		exit(0);
	}

	for (int i = 0; !thongTin.eof(); i++)
	{
		getline(thongTin, bk[i].ten_Book);
		getline(thongTin, bk[i].hoTen_tg);
		getline(thongTin, bk[i].namSinh_tg);
		getline(thongTin, bk[i].theLoai);
		Sach_Thu++;
	}
	thongTin.close();	
}

void menu()
{

	cout << "\n\n\n\n\t\t\t\t\t";

	for (int i = 0; i < 32; i++)
	{
		cout << KiTu1;
		if (i == 15)
			cout << " MAIN MENU ";
	}


	cout << "\n\n\t\t\t\t\t" << KiTu2;
	cout << " 1. Add Books\n";
	//AddBooks()

	cout << "\n\t\t\t\t\t" << KiTu2;
	cout << " 2. Delete Books\n";
	//DeleteBooks()


	cout << "\n\t\t\t\t\t" << KiTu2;
	cout << " 3. Search Books\n";
	//Search_Books()



	cout << "\n\t\t\t\t\t" << KiTu2;
	cout << " 4. Issue Books\n";
	// Issue_Books()

	cout << "\n\t\t\t\t\t" << KiTu2;
	cout << " 5. View Book List\n";
	//View_Book_List()

	cout << "\n\t\t\t\t\t" << KiTu2;
	cout << " 6. Edit Book's Record\n";
	//Edit_Book's_Record()

	cout << "\n\t\t\t\t\t" << KiTu2;
	cout << " 7. Close Application\n";
	//Close_Applicatio()

	cout << "\n\t\t\t\t\t";

	for (int i = 0; i < 44; i++)
		cout << KiTu1;
}

void Selection(Book bk[])
{
	int chon;
	cout << "\n\n\t\t\t\t\t";
	cout << "You want to select : ";
	cin >> chon;
	switch (chon)
	{
	case 1: AddBooks(bk); break;
	case 2:	DeleteBooks(bk); break;
	case 3:	//Search_Books()
	case 4: // Issue_Books()
	case 5: //View_Book_List()
	case 6: //Edit_Book's_Record()
	case 7:	//Close_Applicatio()
		;
	}
}

void CatPhan()
{
	cout << "\n\t\t\t\t\t";

	for (int i = 0; i < 44; i++)
		cout << "-";
}

void AddBooks(Book bk[])
{	
	CatPhan();
	CatPhan();

	fstream    file_in;
	file_in.open(file_book, ios::app);

	cout << "\n\t\t\t\t\t";
	cout << KiTu2 << " Sach thu " << Sach_Thu;
	cin.ignore();

	cout << "\n\t\t\t\t\t";
	cout << "Nhap ten cua sach : ";
	getline(cin, bk[Sach_Thu - 1].ten_Book);
	file_in << bk[Sach_Thu - 1].ten_Book << endl;


	cout << "\n\t\t\t\t\t";
	cout << "Nhap ho ten tac gia : ";
	getline(cin, bk[Sach_Thu - 1].hoTen_tg);
	file_in << bk[Sach_Thu - 1].hoTen_tg << endl;


	cout << "\n\t\t\t\t\t";
	cout << "Nhap nam sinh : ";
	getline(cin, bk[Sach_Thu - 1].namSinh_tg);
	file_in << bk[Sach_Thu - 1].namSinh_tg << endl;


	cout << "\n\t\t\t\t\t";
	cout << "Nhap the loai cua sach : ";
	getline(cin, bk[Sach_Thu - 1].theLoai);
	file_in << bk[Sach_Thu - 1].theLoai << endl;

	file_in.close();
}
void DeleteBooks(Book bk[])
{
	clearScreen();
	cout << endl << endl;
	cout << setw(65) << right << "TAT CA SACH" << endl;

	cout << setfill('-');
	cout << setw(70) << left << "-" << endl;

	cout << setfill(' ');
	cout << setw(20) << right << "Ten Sach";
	cout << setw(40) << right << "Ten Tac Gia" << endl;

	for (int i = 0; i < Sach_Thu; i++)
	{
		cout << setw(10) << left << bk[i].ten_Book;
		//	<< "\t" << bk[i].hoTen_tg;
	}
}

