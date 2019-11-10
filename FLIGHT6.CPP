#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
class book                             //For booking tickets
 {      int sno;
	public:
	int age,accno,pin;
	float no_of_tickets;
	int amount;
	char name[30],flight_name[30],airport[30],state[30];
	char choice,ch1;
	void details();
	void display();
	void display1();
	int getsno()
	{return sno;}
 }obj;

class employee		        	//for employee details
 {      int eno;
	public:
	int hno;
	unsigned long pno;
	char name1[30],post[16],locality[30],state1[30];
	void input();
	void output();
	int geteno()
	{return eno;}
 }obj2;

 void book::details()                   //details for ticket booking
 {
 cout<<"\nEnter any serial no. for ticket :";
 cin>>sno;
 cout<<"\nName of person\n";
 gets(name);
 cout<<"Age of person\n";
 cin>>age;
 cout<<"Place of departure\n";
 gets(state);
 cout<<"Name of airport\n";
 gets(airport);
 cout<<"No of passengers\n";
 cin>>no_of_tickets;
 cout<<"\nEnter your(6 digit) numeric account no.";
  cin>>accno;
  cout<<"\nEnter your numeric PIN code ";
  cin>>pin;
  clrscr();
  cout<<"\nYour payment is recieved. \n ";
 }
 void book::display1()                    //display of details for class book
 {
  cout<<"\nTICKET "<<sno<<" :";
  cout<<"\n\n\nThe flight will depart from :";puts(state);
  cout<<"\nDeparture from airport :";puts(airport);
  cout<<"\nNo. of passangers is :"<<no_of_tickets;
  cout<<"\nTotal amount payable :Rs."<<(15000*no_of_tickets);
  }

  void employee::input()           //input of details for class employee
  {
  cout<<"\n\nEnter employee no.   ";
  cin>>eno;
  cout<<"\nEnter employee name   ";
  gets(name1);
  cout<<"\nEnter his/her post   ";
  gets(post);
  cout<<"\nAddress(enter house no,locality,state)  " ;
  cin>>hno>>locality>>state1;
  cout<<"\nEnter his/her 6-digit phone no.  \n ";
  cin>>pno;
  }
  void employee::output()            //output of details for class employee
  {
  cout<<"\n Employee name: ";puts(name1);
  cout<<" Employee no.: "<<eno;
  cout<<"\n Post: ";puts(post);
  cout<<"\n\n Address \n\n"<<" House no: "<<hno<<"\n Locality: "<<locality<<"\n S"
  "tate: "<<state1;
  cout<<"\n Phone no. : "<<pno;
  }

void main()
{
clrscr();
int yo,ch2,sel,confirm1,sno;
part1:
cout<<"	     \n	              ___  IITian HOLIDAYS  ___\n"
"  	      	          fun never ends.... \n"
"\t\t _____________________________________\n\n\n"             //main menu
"Enter your choice:\n\n1> EMPLOYEE\n2> BOOKING\n3> EXIT\n";
cin>>yo;
float no_of_tickets,amount;
char ch,y,Y;


 if(yo==1)
 {
  clrscr();			//DATA INSERTION
 part5:
	   cout<<"\n\nEMPLOYEE\n\nEnter your choice:\n\n1>Employee details\n"
	   "2>Deletion\n3>Modify\n4>Search\n5>Back\n6>Exit\n";
	   cin>>ch2;
	   if(ch2==1)
	   {    clrscr();
		obj2.input();
		ofstream fout("EM.dat",ios::app);
		fout.write((char*)&obj2,sizeof(obj2));
		clrscr();
		cout<<"\n\nData inserted succesfully\n\n";
		cout<<"\n";
		system("pause");
		ifstream fit("EM.dat");
		fout.close();
		clrscr();
		goto part5;
	   }

	   if(ch2==2)                      //DELETE
	   {

		ifstream fin("EM.dat",ios::in);
		ofstream fout("temp.dat",ios::out);
		int emno;  char found='f',confirm='n';
		clrscr();
		cout<<"\n\n\nEnter employee no to be deleted  \n";
		cin>>emno;
		while(!fin.eof())
		{
		fin.read((char*)&obj2,sizeof(obj2));
		if(obj2.geteno()==emno)
		{  obj2.output();
		found='t';
		cout<<"\n\nAre you sure,you want to delete this record?(y/n)...\n\n";
		cin>>confirm;
		if (confirm=='n')
		fout.write((char*)&obj2,sizeof(obj2));
		}
		else
		fout.write((char*)&obj2,sizeof(obj2));
		}
		if(found=='f')
		cout<<"Record not found!!\n";
		fin.close();
		fout.close();
		remove("EM.dat");
		rename("temp.dat","EM.dat");
		fin.open("EM.dat",ios::in);
		if(confirm=='y')
		{cout<<"\nfile deleted succesfully\n";}
		fin.close();
		getch();
		clrscr();
		goto part5;
	  }
		if(ch2==3)
	  {                                      //MODIFY
		int no,f=0;
		clrscr();
		cout<<"\nMODIFY\n\n";
		cout<<"\n\nEnter Employee Number to be modified : ";
		cin>>no;
		ifstream fin("EM.dat");
		ofstream fout("tmp.dat");
		while(fin.read((char*)&obj2,sizeof(obj2)))
		{
		if(no==obj2.geteno())
		{
		clrscr();
		obj2.output();
		cout<<"\n\nEnter new Details : \n\n";
		obj2.input();
		f=1;
		}
		fout.write((char*)&obj2,sizeof(obj2));
		}
		if(f!=1)
		{
		cout<<"\nRecord not found";
		getch();
		}
		fin.close();
		fout.close();
		remove("EM.dat");
		rename("tmp.dat","EM.dat");
		cout<<"\n\nData modified\n";
		clrscr();
		goto part5;
	      }
		if(ch2==4)
		{                                //SEARCHING
		clrscr();
		int no,f=0;
		cout<<"\nSEARCH\n\n";
		cout<<"\n\nEnter Employee Number to be searched for : ";
		cin>>no;
		ifstream fin("EM.dat");
		while(fin.read((char*)&obj2,sizeof(obj2)))
		{
		if(no==obj2.geteno())
		{
		clrscr();
		obj2.output();
		getch();
		f=1;
		}
		}
		if(f!=1)
		{
		cout<<"\nRecord not found";
		getch();
		}
		fin.close();
		cout<<"\n\n";
		clrscr();
		goto part5;

       }
       if(ch2==5)
       { clrscr();
       goto part1;
       }
       if(ch2==6)
       exit(0);
       else
       {cout<<"\nWrong choice!!\n";
       goto part5;}
    }//if else of ch2 closed

  if(yo==2)
  part6:                                    //BOOKING
{ ifstream fis("EM.dat");
  while(fis.read((char*)&obj,sizeof(obj)))
  {
  clrscr();
  int ssno,accno;
  cout<<"\n\nTICKET BOOKING WINDOW\n\nEnter your choice:\n\n1- New booking\n"
  "2- Cancellation of existing ticket\n3- back\n4- Exit\n";
  cin>>sel;
  switch(sel)
  {case 2:                               //cancellation
  {    	ifstream fis("EM.dat",ios::in);
		ofstream fous("temp.dat",ios::out);
		int sno;  char found='f',confirm1='n';
		clrscr();
		cout<<"\n\n\TICKET CANCELLATIION\n\n\nEnter serial"
		" no. of ticket to be cancelled\n";
		cin>>ssno;
		while(!fis.eof())
		{
		fis.read((char*)&obj,sizeof(obj));
		if(obj.getsno()==ssno)
		{  obj.display1();
		found='t';
		cout<<"\n\nAre you sure,you want to cancel this ticket?(y/n)...\n\n";
		cin>>confirm1;
		if (confirm1=='n')
		{fous.write((char*)&obj,sizeof(obj));
		clrscr();
		cout<<"\n\n\nTicket not cancelled....Redirecting.....\n";}
		}
		else
		fous.write((char*)&obj,sizeof(obj));
		}
		if(found=='f')
		cout<<"ticket not found!!\n";
		fis.close();
		fous.close();
		remove("EM.dat");
		rename("temp.dat","EM.dat");
		fis.open("EM.dat",ios::in);
		if(confirm1=='y')
		{clrscr();
		 cout<<"\n\n\nYour ticket has been cancelled.\nHalf of your"
		 " money i.e. "<<(1500*(obj.no_of_tickets))<<"has\n been"
		 " refunded to your account no. :"<<accno<<"\n\n\n\n\nFor any"
		 " complaints or suggestions contact us: \nwww.IITianholidays.com :) \n\n";
		}
		fis.close();
		getch();
		goto part6;

      }
case 1:   {     clrscr();
		cout<<"\n\nNEW BOOKING\n\n ";            //new booking
		obj.details();
		ofstream fous("EM.dat",ios::app);
		fous.write((char*)&obj,sizeof(obj));
		clrscr();
		cout<<"\n\n\nData inserted succesfully\n\n";
		cout<<"\n\n";
		system("pause");
		ifstream fis("EM.dat");
		fous.close();
		goto part6;
	}


case 3:{      clrscr();
	goto part1;              //back
           }
case 4:       exit(0);
default:{
	cout<<"\nWrong choice!!";
	goto part6;
              }
}
}
if(yo==3)                        //EXIT
exit(0);

}
getch();
}
