#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int dlimsize = 6;
const int recordsize = 542;
struct books
{
    char isbn[6];
    char title[256];
    char name[256];
    char price[10];
    char year[6];
    char numofpages[8];
};
istream& operator>>(istream& in, books& b)
{
    in.ignore();
    cout << "Enter Your ISBN: ";
    in.getline(b.isbn, 6);
    cout << "Enter Your Title: ";
    in.getline(b.title, 256);
    cout << "Enter Your Name: ";
    in .getline(b.name, 256) ;
    cout << "Enter Your Price: ";
    in.getline(b.price, 10);
    cout << "Enter Your Year: ";
    in.getline(b.year, 6);
    cout << "Enter Your Pages Number: ";
    in.getline(b.numofpages, 8);
}
ostream& operator<<(ostream& out, books& b)
{
    out << "Isbn : " << b.isbn << endl;
    out << "Title : " << b.title << endl;
    out << "Name : " <<b.name << endl;
    out << "Price : " <<b.price << endl;
    out << "Year : " <<b.year << endl;
    out << "Number of pages : " <<b.numofpages << endl;
    return out;
}

void WriteBooks (fstream& myfile, books& b)
{
    myfile.seekp(0,ios::end);
    cout<<myfile.tellp()<<endl;
    myfile.write(b.isbn, sizeof(b.isbn));
    myfile.put('|');
    myfile.write(b.title, sizeof(b.title));
    myfile.put('|');
    myfile.write(b.name, sizeof(b.name));
    myfile.put('|');
    myfile.write(b.price, sizeof(b.price));
    myfile.put('|');
    myfile.write(b.year, sizeof(b.year));
    myfile.put('|');
    myfile.write(b.numofpages, sizeof(b.numofpages));
    myfile.put('|');
    cout<<myfile.tellp()<<endl;
//    myfile.close();
}
void readbooks (ifstream& myfile, books& b)
{
    myfile.seekg(sizeof(int),ios::beg);
    while(!myfile.eof())
    {
        myfile.read(b.isbn,sizeof(b.isbn));
        if(myfile.eof())
        {

            memset(b.isbn, 0, sizeof(b.isbn));
            return;
        }
        if(b.isbn[0] == '*')
        {
            myfile.seekg(recordsize+dlimsize,ios::cur);
        }
//    if(myfile.tellg() ==-1)
//        return;

        myfile.ignore();
        myfile.read(b.title,sizeof(b.title));
        myfile.ignore();
        myfile.read(b.name,sizeof(b.name));
        myfile.ignore();
        myfile.read(b.price,sizeof(b.price));
        myfile.ignore();
        myfile.read(b.year,sizeof(b.year));
        myfile.ignore();
        myfile.read(b.numofpages,sizeof(b.numofpages));
        myfile.ignore();
        cout<<b;
        cout<<"____________"<<endl;
    }
}
void DeleteBook(fstream &file,int RRN)
{
    int header=0;
    file.read((char*)&header,sizeof(header));
    file.seekp(sizeof(int)+(RRN*(sizeof(books)+dlimsize)),ios::beg);
    char dlim = '*';
    file.write(&dlim,sizeof(dlim));
    file.write((char *)&header,sizeof(header));
    file.seekp(0,ios::beg);
    file.write((char *)&RRN,sizeof(RRN));
    cout<<"the book deleted"<<endl;

}
void menu()
{
    cout<<"1- write books"<<endl;
    cout<<"2- read books"<<endl;
    cout<<"3- delete book"<<endl;
}

int main()
{
//    freopen("in.txt","r",stdin);
    while(true)
    {
        menu();
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            fstream myfile("test.txt",ios::out|ios::in|ios::binary);
            int header = -1;
            myfile.seekp(0,ios::beg);
            cout<<myfile.tellp()<<endl;
            myfile.write((char *)&header,sizeof(int));
            cout<<myfile.tellp()<<endl;
            books c;
            cin >> c;
            WriteBooks(myfile,c);
            break;

        }
        case 2:
        {
            books c;
            ifstream file("test.txt",ios::out|ios::in|ios::binary);
            readbooks(file,c);
            break;
        }
        case 3:
        {
            books c;
            int rrn;
            cout<<"please enter your record number you want delete: ";
            cin>>rrn;
            rrn=rrn-1;
            fstream myfile("test.txt",ios::out|ios::in|ios::binary);
            DeleteBook(myfile,rrn);
            break;

        }

        }

    }



    return 0;
}
