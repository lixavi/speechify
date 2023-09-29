//HOTEL MANAGEMENT

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
// #include<dos.h>
#include<string.h>
#include <curses.h>
// #include <windows.h>
using namespace std;



//START OF CLASS


// void gotoxy(int x, int y);
class hotel
{

int room_no;
char name[30];
char address[50];
char phone[10];

public:

void main_menu();		//to dispay the main menu
void add();			//to book a room
void display(); 		//to display the customer record
void rooms();			//to display alloted rooms
void edit();			//to edit the customer record
int check(int);			//to check room status
void modify(int);		//to modify the record
void delete_rec(int);		//to delete the record
void bill(int);                 //for the bill of a record
     };
    //END OF CLASS



//FOR DISPLAYING MAIN MENU



void hotel::main_menu() {
    int choice;
    system("color 0B");
    
    while(choice!=5) {
        system("cls");
        // gotoxy(65, 5);
        for(int i=0; i<40; i++)
            cout << "\xB2"; 
        cout << endl; 
        // gotoxy(73, 7);
        cout << "\tHotel Management System\n";	
        // gotoxy(65, 9);
        for(int i=0; i<40; i++)
            cout << "\xB2"; 
        cout << endl;
        cout << endl;
        //  gotoxy(50, 13);
        cout<<"1. Book A Room\n"; 
        // gotoxy(50, 14); 
        cout<<"2. Customer Records\n";  
        // gotoxy(50, 15);
        cout<<"3. Rooms Allotted\n";  
        // gotoxy(50, 16);
        cout<<"4. Edit Record\n"; 
        // gotoxy(50, 17);
        cout<<"5. Exit"; 
        // gotoxy(50, 20);
        cout<<"\n\nEnter Your Choice: ";
        cin>>choice;
        switch(choice) {
            case 1:	add(); break;
            case 2: display(); break;
            case 3: rooms(); break;
            case 4:	edit(); break;
            case 5: {
                // gotoxy(45, 26);
                cout << "Thanks for using our Service, hope this helps you in your daily life\n\n\n";
                exit(0);break;
            }
            default: {
                cout<<"\n\n\t\t\tWrong choice.....!!!";
                cout<<"\n\t\t\tPress any key to continue....!!";
                 getch();
            }

        }
    }
}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM


void hotel::add() {
    system("cls");
    int r,flag;
    ofstream fout("Record.dat",ios::app);
    // gotoxy(65, 1); 
    cout << "\xB2\xB2 Please enter the details \xB2\xB2\n\n";
    // gotoxy(55, 6);
    cout<<"Total no. of Rooms - 50\n"; 
    // gotoxy(55, 7);
    cout<<"Ordinary Rooms from 1 - 30\n"; 
    // gotoxy(55, 8);
    cout<<"Luxuary Rooms from 31 - 45\n"; 
    // gotoxy(55, 9);
    cout<<"Royal Rooms from 46 - 50\n"; 
    // gotoxy(55, 15);
    cout <<"Enter the room no. you want to stay in : ";
    cin>>r;
    flag=check(r);
    if(flag)
        cout<<"\n Sorry..!!!Room is already booked";
    else {
        room_no=r;
        cout<<" Name: ";
        cin>>name;
        cout<<" Address: ";
        cin>>address;
        cout<<" Phone No: ";
        cin>>phone;
        fout.write((char*)this,sizeof(hotel));
        cout<<"\n Room is booked...!!!";
    }
    cout<<"\n Press any key to continue.....!!";
     getch();
    fout.close();
}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD


void hotel::display() {
    system("cls");
    ifstream fin("Record.dat",ios::in);
    int r,flag;
    cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
    cin>>r;
    while(!fin.eof()) {
        fin.read((char*)this,sizeof(hotel));
        if(room_no==r) {
            system("cls");
            cout<<"\n Cusromer Details";
            cout<<"\n ----------------";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone;
            flag=1;
            break;
        }
    }

    if(flag==0)
    cout<<"\n Sorry Room no. not found or vacant....!!";
    cout<<"\n\n Press any key to continue....!!";
     getch();
    fin.close();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms() {
    system("cls");
    ifstream fin("Record.dat",ios::in);
    cout<<"\n\t\t\t    List Of Rooms Allotted";
    cout<<"\n\t\t\t    ----------------------";
    cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";
    while(!fin.eof()) {
        fin.read((char*)this,sizeof(hotel));
        cout<<"\n\n "<<room_no<<"\t\t"<<name;
        cout<<"\t\t"<<address<<"\t\t"<<phone;
    }
    cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
     getch();
    fin.close();
}



//FUNCTION FOR EDITING RECORDS AND FOR BILL


void hotel::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3. Bill Of Customer";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{

case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;

case 3: bill(r);
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

 getch();
}


int hotel::check(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify(int r)
{
system("color D");
long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void hotel::delete_rec(int r)
{
system("color 4");
int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}


//END OF DELETE FUNCTION


//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill(int r)
{
system("color 0A");
hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {

  if(h1.room_no>=1&&h1.room_no<=30)
  cout<<"your bill = 2000";

  else if (h1.room_no>=35&&h1.room_no<=45)
  cout<<"your bill = 5000" ;

  else
  cout<<"your bill = 7000";

  }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
   getch();

}

//END OF BILLING FUNCTION

//START OF MAIN PROGARM


int main()
{

hotel h;

system("cls");
system("color 0D");
// gotoxy(65, 5);
	for(int i=0; i<25; i++)
		cout << "\xD2"; 
	cout << endl;	
    // gotoxy(70, 7);
cout << "\tAuthentication\n";	
// gotoxy(65, 9);
for(int i=0; i<25; i++)
		cout << "\xD2";

char id[5],pass[7]; 
// gotoxy(50, 15);
cout<<"\n\n\xB2\xB2 Username of Hotel Management system => ";
cin>>id;  
// gotoxy(50, 17);
cout<<"\n\xB2\xB2 Enter Password => ";
cin>>pass;


h.main_menu();
return 0;
}

//END OF MAIN PROGRAM

// MOVING CURSOR POSITION
// void gotoxy(int x, int y) {
//     COORD coord;
//     coord.X = x; coord.Y = y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }