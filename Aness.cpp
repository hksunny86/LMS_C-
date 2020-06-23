#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<process.h>
#include<iomanip>
#include <windows.h>
using namespace std;
int chk;
int nn;
class book_collection
{
	public:
void search_book(char uzer[], int pass);
void advance_search();
void write_book();
void simple_search();
void chack(int);
void show_books();
void modify_book(int);
void delete_book();

};
class book{
	
	public:
	char bname[30];
	char authorn[30];
	double bookid;
	int adution;
	int number;
	char catagory[30];
	
	void set_id()
	{
	bookid=0;
	}

	void getinfo()
	{
		system("cls");
		cout << "\t*********** PLEASE ENTER INFORMATION ABOUT BOOK **************\t" << endl;

	
	cout << "\t\t BOOK ISBN:";

		cin >> bookid;
    int chack(bookid);
    system("cls");
    cout << "\t*********** PLEASE ENTER INFORMATION ABOUT BOOK **************\t" << endl;
    	cout << "\t\t BOOK ISBN:";
    	cin>>bookid;

    	cout << "\t\tBOOK NAME:";
		cin >>bname;
		cout << "\t\t BOOK AUTHOR NAME:";
		cin >>authorn;
		cout << "\t\t CATAGORY OF BOOK:";
		cin >> catagory;
		cout << "\t\t NUMBER OF COPPIES:";
		cin >>number;
	}
	void show_book()
	{


		cout <<bname << "\t\t" << authorn << "\t\t\t" <<bookid << "\t\t\t" << number << "\t\t\t" << catagory << endl;
		cout << "______________________________________________________________________________________________________" << endl;

	}
	void table_form()
	{
		cout <<bname << setw(10) << authorn << setw(5) <<bookid << setw(5) << number << endl;
	}
	void modify_books()
	{
		cout << "ENTER NEW BOOK NAME:" << endl;
		cin >> bname;
		cout << "ENTER NEW BOOK AUTHOR NAME:" << endl;
		cin >> authorn;
		cout << "ENTER NEW ISBN:" << endl;
		cin >> bookid;
		cout << "ENTER NEW NUMBER OF COPPIES:" << endl;
		cin >> number;

	}
		void mod_bn()
	{
		cout << "ENTER NEW BOOK NAME:->" ;
		cin >> bname;

	}
	void mod_ba()
	{
		cout << "ENTER NEW BOOK AUTHOR:->";
		cin >> authorn;

	}
	void mod_bisbn()
	{
		cout << "ENTER NEW BOOK ISB NUMBER: ->";
		cin >> bookid;

	}
	void mod_bcopy()
	{
		cout << "ENTER NEW BOOK NUMBER OF COPPIES: ->" ;
		cin >> number;

	}
	void mod_cata()
	{
		cout << "ENRTER NEW BOOK CATAGORY: ->";
		cin >> catagory;
	}
	void show_catagory()
	{

		cout << bname << "\t\t" << authorn << "\t\t" << catagory;
	}
	
	int retbno(){ return bookid; }
	char* return_bn(){ return bname; }
	char* return_ba(){ return authorn; }
	char* return_cata(){ return catagory; }
	int retbcoppy(){ return number ;
	}

	
};
class admion
{
public:
	book b1;


};
class student{
protected:
	char s_fname[15];
	char s_lname[15];
	int s_idn;
	int stbno;
	int token;
public:
	void get_sinfo()
	{
		cout << "\t\tTO ADD STUDENT ENTER INFORMATION ABOUT STUDENT " << endl;
		cout << "\tFIRST NAME:" << endl;
//  gets(s_fname);
	cin >> s_fname;
		cout << "\tLAST NAME:" << endl;

		cin >> s_lname;
		cout << "\tIDENTIFICATION NUMBER:" << endl;
		cin >> s_idn;
	}
	void show_sinfo()
	{
		cout << s_fname << "\t\t\t\t" << s_lname << "\t\t\t" << s_idn << "\t\t\t" << token << "\t\t";
		if (token = 1)
		{
			cout << stbno<<endl;
		}
	}
	void showstudent_pro()
	{
		system("color 3f");
	
		
		cout << "FIRST NAME" << "\t\t" << "LAST NAME" << "\t\t" << "IDENTIFICATION NUMBER" << "\t" << "NUMBER OF BOOK ISSUE" << "\tBOOK ISBN" << endl<<endl;
		cout<<"_________________________________________________________________________________________________________________"<<endl;
		cout << left << setw(24) << s_fname << setw(24) << s_lname << setw(24) << s_idn << setw(20) << token << "\t";
		if (token = 1)
		{
			cout << stbno;
		}
	}

	void welcome()
	{
		system("cls");
		cout << ":::::::::WELCOME:::::::::" << endl;
		cout << s_fname << "\t" << s_lname << endl;
	}
	char*ret_sfname(){ return s_fname; }
	char*ret_slname(){ return s_lname; }
	int ret_sid(){ return s_idn; }
	int ret_stbno(){ return stbno; }
	int ret_token(){ return token; }
	void resettoken(){ token = 0; }
	void addtoken(){ token = 1; }

	//void resettoken(){ token = 0; }


	void getstudent_bo(int aa)
	{
		stbno = aa;
	}


};

fstream f, f1;
admion s1;
student s2;
void book_collection :: chack(int idd)
{
int take;
	f1.open("book.txt",ios::in|ios::out|ios::app );
	while(f1.read(reinterpret_cast<char*>(&s1), sizeof(admion)) &&take==0)
	{
		if(s1.b1.retbno()==idd)
		
		
	{
	
		
		cout<<"\t\t\t\t!!SAME ISBN ALREADY EXIST TRY DIFERENT:"<<endl;
		system("pause");
		break;
			write_book();
}

	
}
f1.close();
}

void write_student()
{
	char ch1;
	f.open("students.txt", ios::out | ios::app);
	do{
		s2.get_sinfo();
		f.write(reinterpret_cast<char*>(&s2), sizeof(student));
		//f.write((char*)&s2, sizeof(student));
		cout << "\n\nDo You Want TO Add More Students....(y/n)";
		cin >> ch1;
	} while (ch1 == 'y' || ch1 == 'Y');
	f.close();
}
void show_students()
{
	system("cls");
	cout<<endl;
	cout << "STUDENT FIRST NAME:\t\tLAST NAME\tIDENTIFICATION NUMBER\tNUMBER OF BOOK ISSUE\tBOOK ISBN" << endl;
	cout << "__________________________________________________________________________________________________________" << endl;
	f.open("students.txt", ios::in);
	while (f.read(reinterpret_cast<char*>(&s2), sizeof(student)))
	{
		s2.show_sinfo();
	}
	system("pause");
	f.close();
}
void book_collection:: write_book()
{
	char ch;
	f.open("book.txt", ios::out | ios::app);

	do{

		s1.b1.getinfo();
		f.write(reinterpret_cast<char*>(&s1), sizeof(admion));  //binary converssion to mange it at th same time or auto mangement 
		//f.write((char*)&s1, sizeof(book));

		cout << "\n\nDo you want to add more books...(y/n?)";
		cin >> ch;
		
	} while (ch == 'y' || ch == 'Y');

	f.close();


}
void book_collection::show_books()
{
	system("cls");

	cout << "BOOK NAME: \t BOOK AUTHOR NAME \t BOOK ISBN \t NUMBER OF COPPIES \t Catagory of Book" << endl;
	cout << "__________________________________________________________________________________________________" << endl;

	f.open("book.txt", ios::in);
	while (f.read(reinterpret_cast<char*>(&s1), sizeof(admion))){


		s1.b1.show_book();
		

	}
	f.close();
	cout << "\n\n\n";
	system("pause");
}

void book_collection::modify_book(int iddd)
{
	int mod;

	int flag = 0;
	f.open("book.txt", ios::in | ios::out);
	while (f.read(reinterpret_cast<char*>(&s1), sizeof(admion)))
	{

		if (s1.b1.retbno() == iddd)
		{
			system("cls");

            cout<<"\n\n\n\n\n\n\n\n\n";
			cout << "BOOK NAME: \t BOOK AUTHOR NAME \t BOOK ISBN \t NUMBER OF COPPIES\t\tCATAGORY" << endl;
			cout << "____________________________________________________________________________________________________" << endl;

			s1.b1.show_book();
			cout<<"\n\n\n";
			cout << "\t\t\t\tENTER YOUR CHOICE:\n" << endl;
			Sleep(150);
			cout << "\t\t\t1- MODIFY NAME:\n" << endl;
			Sleep(150);
			cout << "\t\t\t2- MODIFY AUTHOR:\n" << endl;
			Sleep(150);
			cout << "\t\t\t3- MODIFY ISBN:\n" << endl;
			Sleep(150);
			cout << "\t\t\t4- MODIFY NUMBER OF COPPIES:\n" << endl;
			Sleep(150);
			cout << "\t\t\t5- MODIFY CATAGORY:\n" << endl;
			Sleep(150);
			cout<<"\t\t\t6- MODIFY ALL DATA:\n"<<endl;
			Sleep(150);
			mod = _getch() - 48;
			if (mod == 1)
			{
				s1.b1.mod_bn();
				int pos = 0;
				pos = (-1) * static_cast<int>(sizeof(admion));
				f.seekp(pos, ios::cur);
				f.write(reinterpret_cast<char*>(&s1), sizeof(s1));
				cout << "NEW RECORD HAS UPDATE SUCCESSFULLY";
				_getch();
				flag = 1;
				break;
			}
			else if (mod == 2)
			{
				s1.b1.mod_ba();
				int pos = 0;
				pos = (-1) * static_cast<int>(sizeof(admion));
				f.seekp(pos, ios::cur);
				f.write(reinterpret_cast<char*>(&s1), sizeof(s1));
				cout << "NEW RECORD HAS UPDATE SUCCESSFULLY";
				_getch();
				flag = 1;
				break;

			}
			else if (mod == 3)
			{
				s1.b1.mod_bisbn();
				int pos = 0;
				pos = (-1) * static_cast<int>(sizeof(admion));
				f.seekp(pos, ios::cur);
				f.write(reinterpret_cast<char*>(&s1), sizeof(s1));
				cout << "NEW RECORD HAS UPDATE SUCCESSFULLY";
				_getch();
				flag = 1;
				break;
			}
			else if (mod == 4)
			{
				s1.b1.mod_bcopy();
				int pos = 0;
				pos = (-1) * static_cast<int>(sizeof(admion));
				f.seekp(pos, ios::cur);
				f.write(reinterpret_cast<char*>(&s1), sizeof(s1));
				cout << "NEW RECORD HAS UPDATE SUCCESSFULLY";
				_getch();
				flag = 1;
				break;
			}
			else if (mod == 5)
			{
				s1.b1.mod_cata();
				int pos = 0;
					pos = (-1) * static_cast<int>(sizeof(admion));
				f.seekp(pos, ios::cur);
				f.write(reinterpret_cast<char*>(&s1), sizeof(s1));
				cout << "NEW RECORD HAS UPDATE SUCCESSFULLY";
				_getch();
				flag = 1;
				break;
			}
			else if(mod==6)
			{
						cout << "PLEASE ENTER NEW DATA OF THIS BOOK:" << endl;
			s1.b1.modify_books();
			int pos = 0;
			pos = (-1) * static_cast<int>(sizeof(admion));
			f.seekp(pos, ios::cur);
			f.write(reinterpret_cast<char*>(&s1), sizeof(s1));
				//f.write((char*)&s1, sizeof(s1));
			cout << "NEW RECORD HAS UPDATE SUCCESSFULLY";
			_getch();
			flag = 1;
			break;
			}

		}



	}
	f.close();
	
	if (flag == 0)
		cout << ":NO RECORD FOUND:"<<endl;
		system("pause");

}
void book_collection:: delete_book()
{
	int flag = 0;
	int no;
	cout << "Please enter book isbn which you want to delete:" << endl;
	cin >> no;
	f.open("book.txt", ios::in | ios::out);
	fstream f2;
	f2.open("temp.txt", ios::out | ios::app);
	f.seekg(0, ios::beg);
	while (f.read(reinterpret_cast<char*>(&s1), sizeof(admion)))
	{
		if (s1.b1.retbno() != no)
			f2.write((char*)&s1, sizeof(admion));
		else flag = 1;
	}
	f2.close();
	f.close();
	remove("book.txt");
	rename("temp.txt", "book.txt");
	if (flag == 1) cout << "\n\n\tRecord Deleted .."<<endl;

	else
	 
	 cout << "\n\n\t\t\t\t\tRecord not found"<<endl;
	 
	//_getch();
		system("pause");

}
class admin
{
	public:
		book_collection b1;
		void log_in(char user[], int pps);
};
void admin:: log_in(char user[], int pps)
{
	int take = 0;

	f.open("students.txt", ios::in);
	while (f.read((char*)&s2, sizeof(student))){
		if (strcmp(s2.ret_sfname(), user) == 0 && s2.ret_sid() == pps)
		{
			s2.welcome();
			
			//system("pause");

			take = 1;
		}
	}
	f.close();
	if (take == 1)
	{
		b1.search_book(user,pps);
	}

	if (take == 0)
	system("cls");
	system("color 1f");
			Sleep(250);
	system("color f1");
			Sleep(250);
	system("color 0c");
			Sleep(250);
		cout<<"\n\n\t\t\t\t\t****************";
		cout << "\n\n\t\t\t\t\t!! NO USER EXIST:"<<endl;
		cout<<"\n\n\t\t\t\t\t****************\n";
		system("pause");

}



void book_collection::search_book(char uzer[],int pass)
{

	int c;

	do{
		system("CLS");

		cout << "\n\n\t1 - Advance Search." << endl;
		cout << "\t2 - Simple Or Catagory Search." << endl;
		cout << "\t3 - View Profiles." << endl;
		cout << "\t4 - Log Out.";
		 c=_getch()-48;
		 cout << endl << endl << endl;
		if (c == 1)
		{
			system("CLS");
			cout << "\n\n";
		advance_search();
			cout << "\n\n\n";
			system("pause");
		}
		else if (c == 2)
		{
			system("CLS");
			cout << "\n\n";
			simple_search();
			cout << "\n\n\n";
			system("pause");
		}
		else if (c == 3)
		{
			system("CLS");
			cout << "\n\n";
			f.open("students.txt", ios::in);
	while (f.read((char*)&s2, sizeof(student))){
		if(strcmp(s2.ret_sfname(), uzer) == 0 && s2.ret_sid() == pass)
		{
		
			s2.showstudent_pro();
			cout << "\n\n\n";
	}
		}
		f.close();
			system("pause");
	}
	} while (c != 4);
	

}
void book_collection::advance_search()
{
	int t = 0;
	char sbn[30];
	char san[30];


	//cout << "\t\tWELCOME IN ADVANCE SEARCHING:" << endl;
	cout << "PLEASE ENTER  FOLLOWING THINGS RELATED TO BOOK:" << endl;
	cout << "\tBOOK NAME:\t"; cin >> sbn;
	cout << "\tAUTHOR NAME:\t"; cin >> san;

	f.open("book.txt", ios::in | ios::out | ios::app);
	while (f.read(reinterpret_cast<char*>(&s1), sizeof(admion)))
	{
		if (strcmp(s1.b1.return_bn(), sbn) == 0)
		{
			t = 1;
	     cout<<"BOOK NAME\tAUTHOR NAME\tCATAGORY"<<endl;
			s1.b1.show_book();
		}

	}
	f.close();
	if (t == 0)
	{

		cout << "!! NO BOOK FOUND:" << endl;

	}




}
void book_collection::simple_search()
{
	int ts = 0;
	char sb[30];
	//cout << "\t\t WELCOME IN SIMPLE SEARCHING:" << endl;
	cout << "\t\t PLEASE ENTER CATAGORY OF BOOK TO VIEW RELATED BOOKS OF IT:" << endl;
	cin >> sb;
	f.open("book.txt", ios::in | ios::out | ios::app);
	while (f.read(reinterpret_cast<char*>(&s1), sizeof(admion)))
	{
		if (strcmp(s1.b1.return_cata(), sb) == 0)
		{
			ts = 1;
			cout<<"BOOK NAME\tAUTHOR NAME\tCATAGORY"<<endl;
			//cout << "BOOK NAME \t \t  BOOK ATHER NAME \t\t BOOK CATAGORY";
			s1.b1.show_catagory();
		}

	}

	f.close();
	if (ts == 0)
	{

		cout << "!!!NO BOOK FOUND RELATED THIS CATAGORY:" << endl;
	}



}
void issue_book()
{
	system("cls");
	int sid;
	int bid;
	int found = 0;
	int flag = 0;
	cout<<"\n\n\n\n\n\n\n";
	cout << "\t\t\tISSUING BOOK:" << endl;
	cout << "\t\t\tPlease enter student identification number:" << endl;
	cin >> sid;
	f.open("students.txt", ios::in | ios::out);
	f1.open("book.txt", ios::in | ios::out);
	while (f.read(reinterpret_cast<char*>(&s2), sizeof(student)) && found == 0)
	{
		if (s2.ret_sid() == sid)
		{
			found = 1;
			if (s2.ret_token() == 0)
			{
				cout << "\t\tPlease Enter Book ISB number:" << endl;
				cin >> bid;
				while (f1.read(reinterpret_cast<char*>(&s1), sizeof(admion)) && flag == 0)
				{
					if (s1.b1.retbno() == bid)
					{
						s1.b1.show_book();
						flag = 1;
						s2.addtoken();
						s2.getstudent_bo(s1.b1.retbno());
						int	pos = -1 * static_cast<int>(sizeof(s2));
						f.seekp(pos, ios::cur);
						f.write(reinterpret_cast<char*>(&s2), sizeof(student));
						//f.write((char*)&s2, sizeof(student));
						cout << "\t\tBOOK ISSUE SUCCESSFULY:" << endl;
						cout<<"\t\tNOTE ISSUING DATE FINE WILL BE CHARGED AFTER 15 DAYS:";
						Beep(3000,1000);
					}
				}
				if (flag == 0)
					cout << "\t\tNO BOOK EXIST:" << endl;
			}

			else
				cout << "\t\tYOU DID NOT RETURN YOUR LAST BOOK:" << endl;
		}

	}
	if (found == 0)
		cout << "\t\tSTUDENT RECORD NOT EXIST:" << endl;
	
	f.close();
	f1.close();
	system("pause");





}
void returning_book()
{
	int sn;
	int bn;
	 int found = 0, flag = 0, day, fine;
	 system("cls");
	 cout<<"\n\nBOOK DEPOSIT ...";
	  cout<<"\n\n\tEnter Student’s Identification number : ";
	  cin>>sn;
	      f.open("students.txt", ios::in|ios::out);
    f1.open("book.txt", ios::in|ios::out);
    	while (f.read(reinterpret_cast<char*>(&s2), sizeof(student)) && found == 0){
    		if(s2.ret_sid()==sn)
    		{
    			found=1;
    			if(s2.ret_token()==1)
    			{
    				while (f1.read(reinterpret_cast<char*>(&s1), sizeof(admion)) && flag == 0)
    				{
    					if(s1.b1.retbno()==s2.ret_stbno())
    					{
    						cout<<"BOOK NAME\tBOOK AUTHOR NAME\tISBN\t\tNUMBER OF COPPY\t\tCATAGORY OF BOOK"<<endl;
    						s1.b1.show_book();
    						flag = 1;
                        cout<<"\n\nBook deposited in no. of days : ";
                        cin>>day;
                        if(day > 15){
                            fine = (day-15) * 1;
                            cout<<"\n\nFine to deposited is Rs. "<<fine;
						}
						s2.resettoken();
							int	pos = -1 * static_cast<int>(sizeof(s2));
						   //int pos = -1 * sizeof(s);
                        f.seekp(pos,ios::cur);
                        f.write(reinterpret_cast<char*>(&s2), sizeof(student));
                        //f.write((char*)&s, sizeof(student));
                        cout<<"\n\n\t Book deposited successfully";
                        Beep(3000,1000);
					}
				}
				 if(flag==0)cout<<"Book no does not exist";
			}
    		else cout<<"No book is issued..please check!!";
    		
		}
    
}
  if(found==0) cout<<"Student record not exist...";
    getch();
    f.close();
    f1.close();
}
void t(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\t";
	}
}
int main()

{for(int i=0;i<18;i++)
	{
		system("CLS");
	    system("color 0A");
//	    if(i<23)
	    {
	    	for(int  j=1;j<i;j++)
	    	{
	    		cout<<"\n";
			}
		}
	    cout<<                 "\t--------------------------------------------------------------------";
	    cout<<                 "\n\t||***********************LIBRARY MANGEMENT SYSTEM******************||";
	    cout<<                 "\n\t--------------------------------------------------------------------"<<endl;
	    	cout<<"                             --------------------------"<<endl;
	cout<<"                             ||*****ROLL NUMBERS*****||"<<endl;
	cout<<"                             --------------------------"<<endl;
	cout<<"                          ---------------------------------"<<endl;
	cout<<"                          |Anees Rehman      || 16201519-104|"<<endl;
	cout<<"                          |Uswa Irshad  || 16201519-029|"<<endl;
	cout<<"                           ---------------------------------"<<endl;
	cout<<"                           ||*****Submitted to*****||"<<endl;
	cout<<"                            ||*****Mam'm Anbreen Kausar'*****||"<<endl;
	    Sleep(25);
	}
	Beep(3000,500);
	Sleep(10);
	Beep(2000,1000);
	//cout<<"\n\t\tPress ENTER";
	//cout<<"\n";
	_getch();
	system("cls");

	

	admion s1;
	student s2;
	admin adm;	
	book_collection b1;
	int cho;
	int bookn;


	system("CLS");
	system("color 3f");
top:
	{for(int i=0;i<15;i++)
	{
		system("CLS");
	    system("color 3f");
//	    if(i<23)
	    {
	    	for(int  j=1;j<i;j++)
	    	{
	    		cout<<"\n";
			}
		}
	  
	cout<<"                       **********************************"<<endl;
	cout<<"                      |1-> ADMIN SERVICES               |"<<endl;
	cout<<"                      |2-> STUDENT SERVICES             |"<<endl;
	cout<<"                       **********************************"<<endl;
	    Sleep(25);
	}
	Beep(3000,200);
	//cout<<"\n\t\tPress ENTER";
	//cout<<"\n";


	cho=_getch()-48;
	switch (cho)
	{
	case 1:
//bottom :
		if(cho=1)
		{
		system("cls");
		string adm;
		int pas;
		Beep(2000,200);
		cout<<"\n\n\n\n\n\n\t\t\t\t............Login First............"<<endl;
		cout<<"\t\t\tUSERNAME ->";
		cin>>adm;
		Beep(2000,200);
		cout<<"\t\t\tPASSWORD ->";
		cin>>pas;
		Beep(2000,200);
		if((adm=="admin"||adm=="ADMIN")&& pas==1234) 
		{
			Beep(1000,200);
		 Sleep(25);	cout<<">> Admin Succesfully Login*****"<<endl;
			system("pause");
		}
		else{
			Beep(5000,200);
			system("cls");
			system("color 1f");
			Sleep(250);
			system("color f1");
			Sleep(250);
			system("color 0c");
			Sleep(250);
			cout<<"\n\n\t\t\t\t\t****************";
			cout<<"\n\n\t\t\t\t\t INVALID ENTRY!"<<endl;
			cout<<"\n\n\t\t\t\t\t****************\n";
			system("pause");
			goto top;
		}
	}
		bottom: 	
		int choice;
	   
	
	
	
		   cout << endl;
		   
		   system("CLS");
   	system("cls");
		   cout<<"\n\n\t\t\t\t\tADMIN MENU";
		   cout << "\n\n\t\t\t 1- ADD BOOK :\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 2- VIEW RECORD OF BOOK:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 3- MODIFY BOOK:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 4- DELETE BOOK:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 5- ADD STUDENT:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 6- VIEW LIST OF STUDENT:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 7- ISSUE BOOK:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 8- RETURN BOOK:\n" << endl;
		    Sleep(150);
		   cout << "\t\t\t 9- Log Out:\n";
		   Sleep(150);
		   cin>>choice;
		   if(choice>9){
			Beep(5000,200);
			system("cls");
			system("color 1f");
			Sleep(250);
			system("color f1");
			Sleep(250);
			system("color 0c");
			Sleep(250);
			cout<<"\n\n\t\t\t\t\t****************";
			cout<<"\n\n\t\t\t\t\t INVALID ENTRY!"<<endl;
			cout<<"\n\n\t\t\t\t\t****************\n";
			system("pause");
		   goto bottom;
		   }


		   switch (choice)
		   {
		   case 1:
		   	Beep(3000,200);
			   cout << "enter book number:" << endl;

			   b1.write_book();
			   break;
		   case 2:
		   	Beep(3000,200);
			   b1.show_books();
			   break;
		   case 3:
		   	Beep(3000,200);
			   int bidn;

			   cout << "please enter book isbn which you want to modify:" << endl;
			   cin >> bidn;
			   b1.modify_book(bidn);
			   break;
		   case 4:
		   	Beep(3000,200);
			   b1.delete_book();
			   break;
		   case 5:
		   	Beep(3000,200);
			   write_student();
			   break;
		   case 6:
		   	Beep(3000,200);
			   show_students();
			   break;
		   case 7:
		   	Beep(3000,200);
			   issue_book();
			   break;
			   case 8:
			   	Beep(3000,200);
			   	returning_book();
			   	break;
			   	
		   case 9:
		   	Beep(3000,200);
			   goto top;
			   break;
		   }
	
		   goto bottom;
		   break;
	
	case 2:
		char name[15];
		int pas;
		system("CLS");
		cout << "\n\n\t--------------------\n\t|       LOGIN      |\n\t--------------------\n\t FIRST NAME > ";
		cin >> name;
		cout << "\t Password > ";
		cin >> pas;
		adm.log_in(name, pas);
	goto top;
		break;
	}

	goto top;
	_getch();
}
}
