#include<iostream.h>

#include<fstream.h>

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>

#include<ctype.h>



char seatChart[9][7]={"1ABCDEF","2ABCDEF","3ABCDEF","4ABCDEF","5ABCDEF","6ABCDEF","7ABCDEF","8ABCDEF","9ABCDEF"};

int TNO=1;



struct date

{

      int dd,mm,yyyy;

};



void Output();

void Delete();

void Insert();

void Modify();



class AIR

{

	char name[100], from[50], to[50], dtime[10],t[1],currency[3],

	plane[50],seatno[4],clas[50],day[10]; float price;

	date D;

	int res,counter;

	
	public:
	
	   char ticket[14];
	   void Input();

	   void dateInput();

	   void Reservation();

	   void TickAssn();

	   void PriceAssn(float&);

	   float ConvCur(char[]);

	   void SeatAssn(char str[9][7]);

	   void dayass();

	   int retur(char x[14])

	   {

		if(!strcmp(ticket,x)){
			return 0;
		}else{
			return 1;
		}
	   }

	   void Output();

}A;





void AIR::Input()

{

	int i,j,t,p,q;

	cout<<"Enter Name:-  "<<endl;

	gets(name);

	for(i=0;i<strlen(name);i++)

		if(!isalpha(name[i])&&name[i]!=' ')

		{	cout<<"\nName must contain only alphabets,check it out again,exiting...";

			getch();

			exit(0);

		}

	cout<<"\n Enter your place of departure:-  "<<"\n 1. Delhi \n 2. Paris \n 3. London \t";

	cin>>i;

	if(i==1)

		strcpy(from,"Delhi");

	else if(i==2)

		strcpy(from,"Paris");

	else if (i==3)

		strcpy(from,"London");

	else

	{

		cout<<"\n Invalid Response";

		getch();

		exit(0);



	}

	cout<<"\n Enter your place of arrival:-\n 1. Delhi \n 2. Paris \n 3. London \t";

	cin>>j;

	if(j==1)

		strcpy(to,"Delhi");

	else if(j==2)

		strcpy(to,"Paris");

	else if (j==3)

		strcpy(to,"London");

	else

	{

		 cout<<"\n Invalid Response";

		 getch();

		 exit(0);

	}

	if(!strcmp(from,to))

	{

		cout<<"\n ERROR- Place of arrival and departure cannot be same!";

		getch();

		exit(0);

	}

	cout<<"Enter your preferred time of departure:- \n 1. 10:15 AM \n 2. 2:30 PM \n 3. 4:45 PM \t";



	cin>>t;

	if(t==1)

		strcpy(dtime,"1015");

	else if(t==2)

		strcpy(dtime,"1430");

	else if(t==3)

		strcpy(dtime,"1645");

	else

	{

		cout<<"Invalid Response";

		getch();

		exit(0);

	}

	cout<<"Enter the plane:- \n 1. Spice Jet \n 2. Indigo \n 3. Air India \t";



	cin>>counter;

	if(counter>3||counter<1)

	{

		cout<<"Invalid Response";

		getch();

		exit(0);

	}

	cout<<"Enter date of departure:(valid dates and after 1st january,2019)  ";

	dayass();

	cout<<" Enter class:- \n 1. Economy \n 2. Business \t";

	cin>>p;

	if(p==1)

		strcpy(clas, "Economy");

	else if(p==2)

		strcpy(clas, "Business");

	else

	{

		cout<<"Invalid Response";

		getch();

		exit(0);

	}

	cout<<"Enter currency in which price should be displayed:- \n 1. Indian Rupees \n 2. Euros \n 3. US Dollars \t";



	cin>>q;

	if(q==1)

		strcpy(currency,"INR");

	else if(q==2)

		strcpy(currency,"EUR");

	else if(q==3)

		strcpy(currency,"USD");



	else

	{

		cout<<"Invalid Response";

		getch();

		exit(0);

	}



	Reservation();

	TickAssn();

	PriceAssn(price);



	cout<<endl<<"\nYour total cost is:\t"<<price;



	SeatAssn(seatChart);

	if(counter==1)

		strcpy(plane,"Spice Jet");

	else if(counter==2)

		strcpy(plane,"Indigo");

	else if(counter==3)

		strcpy(plane,"Air India");

	else

	{

		cout<<"Invalid Response";

		getch();

		exit(0);

	}

}

void AIR:: dateInput()

{

	cin>>D.dd>>D.mm>>D.yyyy;

	if(D.mm>12||D.mm<1)

	{

		cout<<"Month only lies between 1 to 12";

		getch();

		exit(0);

	}

	if(D.yyyy<2019||D.yyyy>2020)

	{

		cout<<"Bookings available only for 2019 and 2020";

		getch();

		exit(0);

	}

	if(D.dd<1)

	{

		cout<<"This date is not possible";

		getch();

		exit(0);

	}

	switch(D.mm)

	{

		case 1:

		case 3:

		case 5:

		case 7:

		case 8:

		case 10:

		case 12: if(D.dd>31)

			 {	cout<<"This date is not possible";

				getch();

				exit(0);

			 }

			 break;

		case 2:  if((D.dd>28&&D.yyyy==2019)||(D.dd>29&&D.yyyy==2020))

			 {	cout<<"This date is not possible";

				getch();

				exit(0);

			 }

			 break;

		case 4:

		case 6:

		case 9:

		case 11: if(D.dd>31)

			 {	cout<<"This date is not possible";

				getch();

				exit(0);

			 }

			 break;

		default: break;

	}



}

void AIR:: Reservation()

{

	cout<<"\n(This is just for showing prices.When you submit and confirm the flight,along with your other necessaties, you will be also required to verify your identity of reservation!!)\n\n";

	cout<<"Select Type of Reservation:- \n 1. Security Forces \n 2. Handicapped \n 3. National/International Sports participant\n 4. None \n\t";

	cin>>res;

	if(res<1 || res>4)

	{	cout<<"Invalid Response.\n";

		getch();

		exit(0);

	}

}





void AIR:: TickAssn()

{

	
	 switch(counter)

	 {

		case 1:	{

				strcpy(ticket,"SJ");

				break;

			}

		case 2:	{

				strcpy(ticket,"IN");

				break;

			}

		case 3:	{

				strcpy(ticket,"AI");

				break;

			}

		default:	strcpy(ticket,"EL");

	}

	char day[5];
	char month[5];

	itoa(D.dd,day,10);
	itoa(D.mm,month,10);
	strcat(ticket,day);
	strcat(ticket,month);
	strcat(ticket,dtime);
	strcat(ticket,"001");
	cout<<"Your Ticket No:- \t"<<ticket<<endl; 
	TNO++;



}

void AIR:: PriceAssn(float &price)

{

	if(strcmp(plane,"Spice Jet"))

	{

		price=60000;

	}

	else

	if(strcmp(plane,"Indigo"))

	{

		price=90000;

	}

	else

	if(strcmp(plane,"Air India"))

	{

		price=80000;

	}

	if(strcmp(clas,"Business"))

		price+=10000;

	if(res==1)

		price*=0.95;

	else if(res==2)

		price*=0.9;

	else if(res==3)

		price*=0.85;

	price= ConvCur(currency);

}

float AIR:: ConvCur(char cur[])

{

	if(!strcmp(cur,"USD"))

	{

		price/= 67.5;

		return price;

	}

	else if(!strcmp(cur,"EUR"))

	{

		price/= 79.5;

		return price;

	}

	else if(!strcmp(cur,"INR"))

	{

		return price;

	}

	else

	{
		return price;

	}

}



void AIR::SeatAssn(char seatChart[9][7])

{

	int i,j,row,c,flag=0;

	char colum[1];

	do

	{

		cout<<"\n Select a seat from the following chart: \n";

		for(i=0;i<9;i++)

		{

			for(j=0;j<7;j++)

				cout<<seatChart[i][j]<<"\t";

				cout<<endl;

		}

		cout<<"Enter the row number with column (e.g.2A): \n";

		cin>>row>>colum;

		strupr(colum);

		if(row<1||row>9||isalpha(colum[0])==0||colum[0]<'A'||colum[0]>'F')

		{

			cout<<"Invalid seat selection, please try again. \n";

			continue;

		}

		c=int(colum[0])-int('A')+1; //checks if the seat is taken

		if(seatChart[row-1][c]=='X')

		{

			cout<<"Seat is already taken, please try again. \n";

			continue;

		}

		else

		{

			char rowch[3];

			itoa(row,rowch,10);

			strcpy(seatno,rowch);

			strcat(seatno,colum);

			seatChart[row-1][c]='X';

			flag++;

		}

	}while(flag==0);

}

void AIR:: dayass()

{

	char ans;



	dateInput();

	int a,b,c,d,e,f;

	a=D.yyyy-1900;

	b=D.dd;

	c=a/4;

	switch(D.mm)

	{

		case 1:	{

				d=2;

				break;

			}

		case 2:	{

				d=5;

				break;

			}

		case 3:	{

				d=5;

				break;

			}

		case 4:	{

				d=1;

				break;

			}

		case 5:	{

				d=3;

				break;

			}

		case 6:	{

				d=6;

				break;

			}

		case 7:	{

				d=1;

				break;

			}

		case 8:	{

				d=4;

				break;

			}

		case 9:	{

				d=7;

				break;

			}

		case 10:{

				d=2;

				break;

			}

		case 11:{

				d=5;

				break;

			}

		case 12:{

				d=7;

				break;

			}

      }

      e=a+b+c+d;

      f=e%7;

      if(D.mm==2&&D.yyyy%4==0)

	      f--;

      switch(f)

      {

		case 0:	{

				strcpy(day,"Friday");

				break;

			}

		case 1:	{

				strcpy(day,"Saturday");

				break;

			}

		case 2:	{

				strcpy(day,"Sunday");

				break;

			}

		case 3:	{

				strcpy(day,"Monday");

				break;

			}

		case 4:	{

				strcpy(day,"Tuesday");

				break;

			}

		case 5:	{

				strcpy(day,"Wednesday");

				break;

			}

		case 6: {

				strcpy(day,"Thursday");

				break;

			}

      }

      cout<<"\n Day on "<<D.dd<<"/"<<D.mm<<"/"<<D.yyyy<<"is "<<day;

}

void AIR:: Output()

{

	cout<<"\n YOUR TICKET DETAILS \n";

	cout<<"\n Flight boarding airport:-\t"<<from;

	cout<<"\n Your destination:-\t"<<to;

	cout<<"\n Ticket price:-\t"<<price;

	cout<<"\n Time of departure:-\t"<<dtime;

	cout<<"\n Date of boarding:-\t"<<D.dd<<" "<<D.mm<<" "<<D.yyyy;

	cout<<"\n Your ticket no.:-\t"<<ticket;

	cout<<"\n Plane:-\t"<<plane;

	cout<<"\n Your seat no.:-\t"<<seatno;

	cout<<"\n Your travelling class:-\t"<<clas;

	cout<<"\n Your booking currency:-\t"<<currency;

}



void Output()

{

	ifstream a1;

	char tc[14]; int flag=0;

	cout<<"Enter your ticket no:- \t"<<endl;

	cin>>tc;

	
	a1.open("AIR.DAT",ios::binary);

	while(!a1.eof())

	{

		a1.read((char*)&A,sizeof(A));
		if(!A.retur(tc))

		{

			flag++;

			A.Output();

		}

	}

	if(!flag)

		cout<<"Record Not Found. \n";

	a1.close();



}

void  Delete()

{

	ifstream file1;

	ofstream file2;

	int flag=0;

	char tc[14];

	int tn;



	file1.open("AIR.DAT", ios::binary);

	file2.open("temp.dat",ios::binary);

	cout<<"Enter Ticket No:-\t";

	cin>>tc;
	

	while(!file1.eof())

       {

		file1.read((char*)&A,sizeof(A));
		
		if(!A.retur(tc))

			flag++;

		else

			file2.write((char*)&A,sizeof(A));

	}

	if(!flag)

		cout<<"Record not found.";

	else

		cout<<"Record deleted\n";

	file1.close();

	file2.close();

	remove("AIR.DAT");

	rename("temp.dat","AIR.DAT");

}

void  Insert()

{

	ofstream file;

	A.Input();
	
	cout<<A.ticket<<endl;
	
	file.open("AIR.DAT", ios::binary|ios::ate);
	
	file.write((char*)&A,sizeof(A));

	file.close();

}

void Modify()

{

	fstream file1;

	int flag=0;

	file1.open("AIR.DAT",ios::binary|ios::in|ios::out);

	char tc[14];

	cout<<"Enter Ticket No:- \n";

	cin>>tc;

	while(!file1.eof())

	{

		file1.read((char*)&A,sizeof(A));

		if(!A.retur(tc))

		{

			flag++;

			A.Input();

			file1.seekp(-sizeof(A), ios::cur);

			file1.write((char*)&A,sizeof(A));

			break;

		}

	}

	if(!flag)

		cout<<"Record not found.\n";

	file1.close();



}

void main()

{

	clrscr();

	int ch1; char ch2;

	do

	{

		clrscr();

		cout<<"********************************************************************************";

		cout<<"********************************************************************************";

		cout<<"*********************     FLIGHT    TICKET     BOOKING     *********************";

		cout<<"********************************************************************************";

		cout<<"********************************************************************************";

		cout<<"\n\n\n Computer Science Project";

		cout<<"\n-By Ananya Lohani, Arjit Mudgal, Sumit Kumar \nCRPF Public School (2018-2019)";

		cout<<"\n\nEnter an operation from the list below: \n 1.Insert a Record  \n 2.Modify a Record \n 3.Delete a Record \n 4.View a Record \n 5.Exit\n";

		cin>>ch1;

		switch(ch1)

		{

			case 1: {

					Insert();

					break;

				}

			case 2: {

					Modify();

					break;

				}

			case 3: {

					Delete();

					break;

				}

			case 4: {

					Output();

					break;

				}

			case 5:	{

					exit(0);

				}

			default:{

					cout<<"Invalid Response";

					break;

				 }

		}

		cout<<"Do you want to continue? (Y/N)";

		cin>>ch2;

	}while(ch2=='y'||ch2=='Y');

	getch();

}

