#include<iostream>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<process.h>
#include<iomanip>
using namespace std;

bool is_empty(std::ifstream& pFile){
    return pFile.peek() == std::ifstream::traits_type::eof();
}

COORD coord = {0,0};
void gotoxy(int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( GetStdHandle (STD_OUTPUT_HANDLE), coord );
}
void time(){
	gotoxy(1,10);
		time_t now;
	time (&now);
	cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);;
}
void loading(){
	gotoxy(26,28);
	int i;
	for (i=1; i<=5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl;
	gotoxy(26,28);
}

void mainEntrance(){
	gotoxy(1,2);
	cout<<  "\t    лл      лл ллллллл лл      ллллллл ллллллл лллл лллл ллллллл";
    cout<<"\n\t    лл      лл лл      лл      лл      лл   лл лл ллл лл лл     ";
    cout<<"\n\t    лл  лл  лл ллллл   лл      лл      лл   лл лл  л  лл ллллл  ";
    cout<<"\n\t    лл  лл  лл лл      лл      лл      лл   лл лл     лл лл     ";
    cout<<"\n\t    лллллллллл ллллллл ллллллл ллллллл ллллллл лл     лл ллллллл";
	gotoxy(6,9);
	cout << "     **************************************************************" << endl;
	gotoxy(6,10);
	cout << "                       STUDENT MANAGEMENT SYSTEM                   " << endl;
	gotoxy(6,11);
	cout << "     **************************************************************" << endl;
}

void login(){
	string pass1, pass2;
	system("cls");
	ifstream file;
    file.open("Password.txt");
	if (is_empty(file))
	{
		mainEntrance();
		cout<<"Looks like you are new to this Application Press Enter to continue:";
		getch();
		system("cls");
		ofstream outf1;
        outf1.open("Password.txt");
       	if (outf1.is_open())
        {
        gotoxy(10,10);
        cout<<"Enter your new password :-";
		cin>>pass1;
		gotoxy(10,12);
    	cout<<"Confirm your password :-";
        cin>>pass2;
        	if(pass1==pass2)
        	{
        	outf1<<pass1;
        	gotoxy(10,14);
        	cout<<"password added succesfully"<<endl;
        	}
        	else
       		{
       		gotoxy(10,14);
      	  	cout<<"please enter valid password"<<endl;
        	}
        }
    	gotoxy(12,16);
    cout<<"press enter to Continue"<<endl;
    getch();
    }
    
	system("cls");
	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	mainEntrance();
	time();
	gotoxy(55,10);
	cout << "(LOGIN)";
	gotoxy(20,15);
	cout << "Enter Username: \n\t\t    Enter Password: ";
	gotoxy(36,15);
	ch2=getch();
	while(ch2 != 13){

		if(ch2 == '\b')
		{
			if(username.size() > 0 )
			{
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else
		{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}

	gotoxy(36,16);
	ch=getch();
	while(ch != 13){

		if(ch == '\b')
		{
			if(password.size() > 0)
			{
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else
		{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*";
				ch = getch();
				i++;
			}
			else
			{
				ch = getch();
			}
		}
	}
		string line;
		ifstream outf2;
        outf2.open("Password.txt");
        if (outf2.is_open()){
    	while(!outf2.eof()){
        outf2>>line;
	if (username == "admin" && password == line)
	{
		gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}
	else
	{
		system("cls");
		system("color F4");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				system("color F1");
				login();
			}
			else
			{
				exit(0);
			}
		}
	}
	}
}
class student{
			char id[15];
			char name[30];
			char lastname[30];
			char fullname[40];
			char address[50];
            char fname[30];
            char faculty[30];
            char phoneNumber[11];
            char email[30];
            char program[40];
            char d[11];
            int age;
            int sem;
            int S01;
            int S02;
            int	S03;
            int	S04;
            int	S05;
            int S11;
            int S12;
            int	S13;
            int	S14;
            int	S15;
            int S21;
            int S22;
            int	S23;
            int	S24;
            int	S25;
            int	total0;
            char gradeS05[3];
            char gradeS04[3];
            char gradeS03[3];
            char gradeS02[3];
            char gradeS01[3];
            float per0;
            char grade0[3];
            int	total1;
            char gradeS15[3];
            char gradeS14[3];
            char gradeS13[3];
            char gradeS12[3];
            char gradeS11[3];
            float per1;
            char grade1[3];
            int	total2;
            char gradeS25[3];
            char gradeS24[3];
            char gradeS23[3];
            char gradeS22[3];
            char gradeS21[3];
            float per2;
            char grade2[3];
            //char examType[11];
	public:
		void displaytime(){
		gotoxy(80,2);
		time_t now;
	time (&now);
	cout<<ctime(&now);;
}
void getStudentData(char tid[]){
			S01=0;
        	S02=0;
       		S03=0;
       		S04=0;
       		S05=0;
       	 	S11=0;
        	S12=0;
    		S13=0;
        	S14=0;
    		S15=0;
        	S21=0;
        	S22=0;
        	S23=0;
        	S24=0;
        	S25=0;
        	strcpy(id,tid);
			system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,3);
			cout<<"Enter the details of student:";
			gotoxy(20,2);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,28);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,6);
			cout<<"Student id:"<<id;
			gotoxy(25,8);
			cout<<"First Name:";
			cin>>name;
			gotoxy(25,10);
			cout<<"Second Name:";
			cin>>lastname;
			gotoxy(25,12);
			cout<<"Address:";
			cin>>address;
			gotoxy(25,14);
			cout<<"Father's Name:";
			cin>>fname;
			gotoxy(25,16);
			cout<<"Date Of Birth(mm/dd/yyyy):";
			cin>>d;
			gotoxy(25,18);
			cout<<"Phone Number:";
			cin>>phoneNumber;
			gotoxy(25,20);
			cout<<"Email:";
			cin>>email;
			gotoxy(25,22);
			cout<<"Faculty:";
			cin>>faculty;
			gotoxy(25,24);
			cout<<"Program:";
			cin>>program;
			gotoxy(25,26);
			cout<<"Semester:";
			cin>>sem;
			marksCalculate();
			strcpy(fullname,name);
			strcat(fullname," ");
			strcat(fullname,lastname);
			strcpy(program,strupr(program));
}
void getmodifyStudentData(){
			S01=0;
        	S02=0;
       		S03=0;
       		S04=0;
       		S05=0;
       	 	S11=0;
        	S12=0;
    		S13=0;
        	S14=0;
    		S15=0;
        	S21=0;
        	S22=0;
        	S23=0;
        	S24=0;
        	S25=0;
			//system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,5);
			cout<<"Enter the details of student:"<<endl;
			gotoxy(20,5);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,28);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,8);
			cout<<"Student id:";
			cin>>id;
			gotoxy(25,10);
			cout<<"First Name:";
			cin>>name;
			gotoxy(25,12);
			cout<<"Second Name:";
			cin>>lastname;
			gotoxy(25,14);
			cout<<"Address:";
			cin>>address;
			gotoxy(25,16);
			cout<<"Father's Name:";
			cin>>fname;
			gotoxy(25,18);
			cout<<"Date Of Birth(mm/dd/yyyy):";
			cin>>d;
			gotoxy(25,20);
			cout<<"Phone Number:";
			cin>>phoneNumber;
			gotoxy(25,22);
			cout<<"Email:";
			cin>>email;
			gotoxy(25,24);
			cout<<"Faculty:";
			cin>>faculty;
			gotoxy(25,26);
			cout<<"Program:";
			cin>>program;
			gotoxy(25,28);
			cout<<"Semester:";
			cin>>sem;
			marksCalculate();
			strcpy(fullname,name);
			strcat(fullname," ");
			strcat(fullname,lastname);
}
void displayData(){
			system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,3);
			cout<<"Student Details:"<<endl;
			gotoxy(20,2);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,6);
			cout<<"STUDENT ID        :"<<id<<endl;
			gotoxy(25,8);
			cout<<"First NAME        :"<<name<<endl;
			gotoxy(25,10);
			cout<<"ADDRESS           :"<<address<<endl;
			gotoxy(25,12);
			cout<<"AGE               :"<<age<<endl;
			gotoxy(25,14);
			cout<<"FATHER'S NAME     :"<<fname<<endl;
			gotoxy(25,16);
			cout<<"PHONE NUMBER      :"<<phoneNumber<<endl;
			gotoxy(25,18);
			cout<<"Email             :"<<email<<endl;
			gotoxy(25,20);
			cout<<"FACULTY           :"<<faculty<<endl;
			gotoxy(25,22);
			cout<<"PROGRAM           :"<<program<<endl;
			gotoxy(25,24);
			cout<<"SEMESTER          :"<<sem<<endl;
			gotoxy(25,26);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
		}
int addRecord(){
	
	int c = getchar();
	while(c != 27) {
	ifstream fin;
    fin.open("Student.dat");
    char tid[15];
    int flag=0;
    system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,3);
			cout<<"Enter the details of student:"<<endl;
			gotoxy(20,2);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,28);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(85,5);
			cout<<"last Student ID:"<<lastid();
				gotoxy(25,6);
			cout<<"Student id:";
			cin>>tid;
    while(fin.read((char*)this,sizeof(student)))
    {
        if(strcmp(tid,id)==0)
         {
         	system("color F4");
         	gotoxy(50,10);
            cout<<"Student ID already exist";
            getch();
            system("color F1");
            return 0;
            
          }
          else continue;
    }
    fin.close();
		//----------------------------------------------
			fstream fout;
   			fout.open("Student.dat",ios::app);
   			getStudentData(tid);
   			fout.write((char*)this, sizeof(student));
  			fout.close();
  			gotoxy(25,27);
  			cout<<"Student infromation has been added!"<<endl;
  			gotoxy(25,28);
  			cout<<"press any key to return main menu"<<endl;
  			getch();
  			mainmenu();
  			c = getchar();
  		}
  		 
  		 
  		 return 0;
	}
void delRecord(){
    ifstream fin;
    ofstream fout;
    char tid[15];
    char conf;
    int flag =0;
    system("cls");
    cout<<"\n Enter admno to delete :";
    cin>>tid;
    fin.open("Student.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(student)))
    {
        if(strcmp(tid,id)==0){
            displayData();
        	Sleep(1000);
            flag=1;
        }
        else
            fout.write((char*)this,sizeof(student));
  }
    fin.close();
    fout.close();
		if(flag==1){
    		cout<<"Press 'Y'or'y' to delete Data & Press 'N' or 'n' to skip";
    		cin>>conf;
    			if(conf=='Y'||conf=='y'){
    				remove("Student.dat");
    				rename("temp.dat","Student.dat");
    				cout<<"\n\n Record Sucessfully removed "<<endl;
				}	
				else{
					mainmenu();
				}
		}
		else{
        	cout<<"\n Admission No :"<<tid <<" does not exist......"<<endl;
        	cout<<"Enter any key to return main menu";
		}
    getch();
}
void modifyRecord(){
	ifstream fin;
    ofstream fout;
    char tid[15];
    int flag =0;
    system("cls");
    cout<<"\n Enter Student ID to Modify :";
    cin>>tid;
    fin.open("Student.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(student)))
    {
        if(strcmp(tid,id)==0)
        {
        	system("cls");
        	cout<<setw(12)<<"ID"<<setw(15)<<"NAME"<<setw(17)<<"ADDRESS"<<setw(14)<<"AGE"<<setw(20)<<"PHONE NUMBER"<<setw(35)<<"EMAIL"<<setw(17)<<"FACULTY"<<endl;
        	age=getage(d);
        	cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<setw(12)<<id<<setw(15)<<fullname<<setw(17)<<address<<setw(14)<<age<<setw(20)<<phoneNumber<<setw(35)<<email<<setw(17)<<faculty<<endl;
            getmodifyStudentData();
            flag=1;
        }
       
    fout.write((char*)this,sizeof(student));
  }
    fin.close();
    fout.close();
    remove("Student.dat");
    rename("temp.dat","Student.dat");
    if(flag==1)
        cout<<"\n\n Record Sucessfully modified ";
    else
	cout<<"id not found"<<endl;
    cout<<"enter any key to return main menu";
    getch();
    
}
void searchRecord(){
	int choice;
	while(true){
		system("cls");
		displaytime();
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\tлл\t  _________________________SEARCH MENU_________________________ \tлл";
		cout << "\n\n\t\t\tлл\t 1: ID SEARCH                                                   \tлл";
		cout << "\n\n\t\t\tлл\t 2: NAME SEARCH                                                 \tлл";
		cout << "\n\n\t\t\tлл\t 3: BACK                                                        \tлл";
		cout << "\n\n\t\t\tлл\t 4: EXIT                                                        \tлл";
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin>>choice;
		switch(choice){
            case 1:
			    //system("cls");
				//cout<<"STILL IN PROGRESS";
				//getch();
				idSearch();		  
				break;
            case 2:
				//system("cls");
				//cout<<"STILL IN PROGRESS";
				//getch();
				nameSearch();		  
				break;
            case 3: 
            	mainmenu();
            	break;
            case 4:
            	exit(0);
		
		}
	}
}
void nameSearch(){
	system("cls");
    char tname[40];
    int row =6;
    int no =0;
    ifstream  fin;
    fin.open("Student.dat");
    cout<<"\n Enter Name :";
    cin>>tname;
    system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(44,3);
	cout<<"Student Record"<<endl;
	gotoxy(10,5);
	cout<<""<<endl;
	gotoxy(45,5);
	cout<<""<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<setw(12)<<"ID"<<setw(15)<<"NAME"<<setw(17)<<"ADDRESS"<<setw(14)<<"AGE"<<setw(20)<<"PHONE NUMBER"<<setw(35)<<"EMAIL"<<setw(17)<<"FACULTY"<<endl;
     while(fin.read((char*)this, sizeof(student)))
    {
      if(strcmpi(tname,name)==0||strcmp(tname,fullname)==0||strcmp(tname,lastname)==0)
       {
         row= row+1;
         no++;
         if(row>=30)
          {
                cout<<"\n\n  Press any key to continue ................";
                getch();
                system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	/*gotoxy(0,7);
	cout<<"лл"<<endl;*/
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(44,3);
	cout<<"Student Record"<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<setw(12)<<"ID"<<setw(15)<<"NAME"<<setw(17)<<"ADDRESS"<<setw(14)<<"AGE"<<setw(20)<<"PHONE NUMBER"<<setw(25)<<"EMAIL"<<setw(17)<<"FACULTY"<<endl;
                row =6;
           }
           age=getage(d);
            cout<<setw(12)<<id<<setw(15)<<fullname<<setw(17)<<address<<setw(14)<<age<<setw(20)<<phoneNumber<<setw(35)<<email<<setw(17)<<faculty<<endl;
         }
    }
    fin.close();
    getch();
    return;
}
void idSearch(){
	ifstream fin;
    fin.open("Student.dat");
    char tid[15];
    int flag=0;
    cout<<"\n Enter Admission Number to search : ";
    cin>>tid;
    while(fin.read((char*)this,sizeof(student)))
    {
        if(strcmp(tid,id)==0)
         {
              //cout<<"\n Student Information ";
              //cout<<"\n--------------------------------------------------------"<<endl;
              age=getage(d);
              displayData();
              flag = 1;
          }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\n Admission No : "<<tid <<" does not exist.... Try again";
        getch();
    
}
void recordMenu(){
	system("cls");
    int tsem;
    char tprogram[40];
    int row =6;
    int no =0;
    ifstream  fin;
    fin.open("Student.dat");
    cout<<"\n Enter Program :";
    cin>>tprogram;
    cout<<"\n Enter semester :";
    cin>>tsem;
    system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(44,3);
	cout<<"Student Record"<<endl;
	gotoxy(10,5);
	cout<<"PROGRAM: "<<tprogram<<endl;
	gotoxy(45,5);
	cout<<"SEMESTER:"<<tsem<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<setw(12)<<"ID"<<setw(15)<<"NAME"<<setw(17)<<"ADDRESS"<<setw(14)<<"AGE"<<setw(20)<<"PHONE NUMBER"<<setw(35)<<"EMAIL"<<setw(17)<<"FACULTY"<<endl;
     while(fin.read((char*)this, sizeof(student)))
    {
      if(strcmp(tprogram,program)==0&&tsem==sem)
       {
         row= row+1;
         no++;
         if(row>=30)
          {
                cout<<"\n\n  Press any key to continue ................";
                getch();
                system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	/*gotoxy(0,7);
	cout<<"лл"<<endl;*/
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(44,3);
	cout<<"Student Record"<<endl;
	gotoxy(10,5);
	cout<<"PROGRAM: "<<tprogram<<endl;
	gotoxy(45,5);
	cout<<"SEMESTER:"<<tsem<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<setw(12)<<"ID"<<setw(15)<<"NAME"<<setw(17)<<"ADDRESS"<<setw(14)<<"AGE"<<setw(20)<<"PHONE NUMBER"<<setw(25)<<"EMAIL"<<setw(17)<<"FACULTY"<<endl;
                row =6;
           }
           	age=getage(d);
            cout<<setw(12)<<id<<setw(15)<<fullname<<setw(17)<<address<<setw(14)<<age<<setw(20)<<phoneNumber<<setw(35)<<email<<setw(17)<<faculty<<endl;
         }
    }
    fin.close();
    cout<<"-----------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n Total Student : "<<no<<endl;
    getch();
    return;
}
int isLeapYear(int year, int mon) {
    int flag = 0;
    if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (mon == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (mon == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}
 
int getage(char date[]){
	int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
	int days,month,year;
	char dob[100];
    time_t ts;
    struct tm *ct;

	if(strlen(date) == 10)
		{
		char m[3], d[3], y[5];
		int i,j;
		for( i = 0; i<2; i++)
		m[i]=date[i];     
			for(i = 3, j=0; i<5; i++,j++){
				d[j]=date[i];
				}
			for(i = 6, j=0; i<10; i++, j++)
			y[j]=date[i];
			
		month = atoi(m);
		days=atoi(d);
		year = atoi(y);
}

		ts = time(NULL);
	    ct = localtime(&ts);
	     days = DaysInMon[month - 1] - days + 1;
	    if (isLeapYear(year, month)) 
    	{
            days = days + 1;
    	}
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;
    	if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1))) 
    	{
            if (days >= (DaysInMon[ct->tm_mon] + 1)) 
            {
                    days = days - (DaysInMon[ct->tm_mon] + 1);
                    month = month + 1;
            }
    	} 
    	else if (days >= DaysInMon[ct->tm_mon]) 
   		 {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    	}
    	if (month >= 12) 
    	{
            year = year + 1;
            month = month - 12;
    	}
    	return (year);
}
void marksMenu(){
	int choice;
	while(true){
		system("cls");
		displaytime();
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\tлл\t  _________________________MARKS MENU_________________________  \tлл";
		cout << "\n\n\t\t\tлл\t 1: INSERT MARKS                                                \tлл";
		cout << "\n\n\t\t\tлл\t 2: REPORT CARD                                                 \tлл";
		cout << "\n\n\t\t\tлл\t 3: BACK                                                        \tлл";
		cout << "\n\n\t\t\tлл\t 4: EXIT                                                        \tлл";
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin>>choice;
		switch(choice){
            case 1:
			   insertMarksMenu();
				break;
            case 2:
				putMarks();
				break;
            case 3:
            	mainmenu();
            	break;
            case 4:
            	exit(0);
            	//print_ranks();
            	default : 
			  cout<<"\n Wrong Choice.... Try again";
            }
            
		
		}
	}
void insertMarksMenu(){
	int choice;
	while(true){
		system("cls");
		displaytime();
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\tлл\t  _________________________MARKS MENU_________________________  \tлл";
		cout << "\n\n\t\t\tлл\t 1: FIRST TERM                                                  \tлл";
		cout << "\n\n\t\t\tлл\t 2: SECOND TERM                                                 \tлл";
		cout << "\n\n\t\t\tлл\t 3: SEMESTER MAIN                                               \tлл";
		cout << "\n\n\t\t\tлл\t 4: BACK                                                        \tлл";
		cout << "\n\n\t\t\tлл\t 5: EXIT                                                        \tлл";
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin>>choice;
		switch(choice){
            case 1:
			    /*system("cls");
				cout<<"STILL IN PROGRESS";
				getch();*/
				add1stMarks();
				break;
            case 2:
				/*system("cls");
				cout<<"STILL IN PROGRESS";
				getch();*/
				add2ndMarks();
				break;
            case 3:
			 /*system("cls");
				cout<<"STILL IN PROGRESS";
				getch(); */
				add3rdMarks();
            	break;
            case 4:
            	marksMenu();
            	break;
            case 5:
            	exit(0);
            	default : 
			  cout<<"\n Wrong Choice.... Try again";
            }
		}
	}
void add1stMarks(){
	ifstream fin;
    ofstream fout;
    char tid[15];
    int flag =0;
    system("cls");
    cout<<"\n Enter Student ID:";
    cin>>tid;
    fin.open("Student.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(student)))
    {
        if(strcmp(tid,id)==0)
        {
            getStudent1stMarks();
            flag=1;
        }
    fout.write((char*)this,sizeof(student));
  }
    fin.close();
    fout.close();
    remove("Student.dat");
    rename("temp.dat","Student.dat");
    if(flag==1)
        cout<<"\n\n marks Sucessfully added ";
    else{
    	cout<<"id not found"<<endl;
	}
    cout<<"enter any key to return main menu";
    getch();	
}
void add2ndMarks(){
	ifstream fin;
    ofstream fout;
    char tid[15];
    int flag =0;
    system("cls");
    cout<<"\n Enter Student ID:";
    cin>>tid;
    fin.open("Student.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(student)))
    {
        if(strcmp(tid,id)==0)
        {
            getStudent2ndMarks();
            flag=1;
        }
    fout.write((char*)this,sizeof(student));
  }
    fin.close();
    fout.close();
    remove("Student.dat");
    rename("temp.dat","Student.dat");
    if(flag==1)
        cout<<"\n\n Marks Sucessfully added ";
    else{
    	cout<<"id not found"<<endl;
	}
    cout<<"enter any key to return main menu";
    getch();	
}
void add3rdMarks(){
	ifstream fin;
    ofstream fout;
    char tid[15];
    int flag =0;
    system("cls");
    cout<<"\n Enter Student ID:";
    cin>>tid;
    fin.open("Student.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(student)))
    {
        if(strcmp(tid,id)==0)
        {
            getStudent3rdMarks();
            flag=1;
        }
    fout.write((char*)this,sizeof(student));
  }
    fin.close();
    fout.close();
    remove("Student.dat");
    rename("temp.dat","Student.dat");
    if(flag==1)
        cout<<"\n\n Marks Sucessfully added. ";
    else{
    	cout<<"id not found"<<endl;
	}
    cout<<"enter any key to return main menu";
    getch();	
}
void marksCalculate(){
//++++++++++++++++++++++++++++++++++++++++++START+++++++++++++++++++++++++++++++++
//First term marks calculation
//Subject 1 Grade calculation
	if(S01<=0)
	strcpy(gradeS01,"I");
	else if(S01>=90)
		strcpy(gradeS01,"A+");
	else if(S01>=80)
		strcpy(gradeS01,"A");
	else if(S01>=70)
		strcpy(gradeS01,"B+");
	else if(S01>=60)
		strcpy(gradeS01,"B");
	else if(S01>=50)
		strcpy(gradeS01,"C+");
	else if(S01>=40)
		strcpy(gradeS01,"C");
	else if(S01>=30)
		strcpy(gradeS01,"D+");
		else
		strcpy(gradeS01,"D");
//End of subject 1 Grade calculation
//subject 2 Grade calculation
if(S02<=0)
	strcpy(gradeS02,"I");
else if(S02>=90)
		strcpy(gradeS02,"A+");
	else if(S02>=80)
		strcpy(gradeS02,"A");
	else if(S02>=70)
		strcpy(gradeS02,"B+");
	else if(S02>=60)
		strcpy(gradeS02,"B");
	else if(S02>=50)
		strcpy(gradeS02,"C+");
	else if(S02>=40)
		strcpy(gradeS02,"C");
	else if(S02>=30)
		strcpy(gradeS02,"D+");
	else
		strcpy(gradeS02,"D");
//End of subject 2 Grade calculation 
//subject 3 Grade calculation
if(S03<=0)
	strcpy(gradeS03,"I");
else if(S03>=90)
		strcpy(gradeS03,"A+");
	else if(S03>=80)
		strcpy(gradeS03,"A");
	else if(S03>=70)
		strcpy(gradeS03,"B+");
	else if(S03>=60)
		strcpy(gradeS03,"B");
	else if(S03>=50)
		strcpy(gradeS03,"C+");
	else if(S03>=40)
		strcpy(gradeS03,"C");
	else if(S03>=30)
		strcpy(gradeS03,"D+");
	else
		strcpy(gradeS03,"D");
//End of subject 3 Grade calculation 
//subject 4 Grade calculation
	if(S04<=0)
	strcpy(gradeS04,"I");
else if(S04>=90)
		strcpy(gradeS04,"A+");
	else if(S04>=80)
		strcpy(gradeS04,"A");
	else if(S04>=70)
		strcpy(gradeS04,"B+");
	else if(S04>=60)
		strcpy(gradeS04,"B");
	else if(S04>=50)
		strcpy(gradeS04,"C+");
	else if(S04>=40)
		strcpy(gradeS04,"C");
	else if(S04>=30)
		strcpy(gradeS04,"D+");
	else
		strcpy(gradeS04,"D");
//End of subject 4 Grade calculation 
//subject 5 Grade calculation
if(S05<=0)
	strcpy(gradeS05,"I");
else if(S05>=90)
		strcpy(gradeS05,"A+");
	else if(S05>=80)
		strcpy(gradeS05,"A");
	else if(S05>=70)
		strcpy(gradeS05,"B+");
	else if(S05>=60)
		strcpy(gradeS05,"B");
	else if(S05>=50)
		strcpy(gradeS05,"C+");
	else if(S05>=40)
		strcpy(gradeS05,"C");
	else if(S05>=30)
		strcpy(gradeS05,"D+");
	else
		strcpy(gradeS05,"D");
//End of subject 5 Grade calculation 
total0 = S01+S02+S03+S04+S05;
  per0 = total0/5.0;
  if(per0<=0)
  strcpy(grade0,"I");
  else if(per0>=90)
             strcpy(grade0,"A+");
 else if(per0>=80)
             strcpy(grade0,"A");
 else if(per0>=70)
             strcpy(grade0,"B+");
 else if(per0>=60)
             strcpy(grade0,"B");
 else if(per0>=50)
             strcpy(grade0,"C+");
 else if(per0>=40)
             strcpy(grade0,"C");
 else if(per0>=30)
 			strcpy(grade0,"D+");
 else 
 			strcpy(grade0,"D");
//End of First term marks calculation
//++++++++++++++++++++++++++++++++++++++++++END+++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++START+++++++++++++++++++++++++++++++++
//Second term marks calculation
//Subject 1 Grade calculation
	if(S11<=0)
	strcpy(gradeS11,"I");
	else if(S11>=90)
		strcpy(gradeS11,"A+");
	else if(S11>=80)
		strcpy(gradeS11,"A");
	else if(S11>=70)
		strcpy(gradeS11,"B+");
	else if(S11>=60)
		strcpy(gradeS11,"B");
	else if(S11>=50)
		strcpy(gradeS11,"C+");
	else if(S11>=40)
		strcpy(gradeS11,"C");
	else if(S11>=30)
		strcpy(gradeS11,"D+");
	else
		strcpy(gradeS11,"D");
//End of subject 1 Grade calculation

//subject 2 Grade calculation
	if(S12<=0)
	strcpy(gradeS12,"I");
else if(S12>=90)
		strcpy(gradeS12,"A+");
	else if(S12>=80)
		strcpy(gradeS12,"A");
	else if(S12>=70)
		strcpy(gradeS12,"B+");
	else if(S12>=60)
		strcpy(gradeS12,"B");
	else if(S12>=50)
		strcpy(gradeS12,"C+");
	else if(S12>=40)
		strcpy(gradeS12,"C");
	else if(S12>=30)
		strcpy(gradeS12,"D+");
	else
		strcpy(gradeS12,"D");
//End of subject 2 Grade calculation 
//subject 3 Grade calculation
	if(S13<=0)
	strcpy(gradeS13,"I");
	
else if(S13>=90)
		strcpy(gradeS13,"A+");
	else if(S13>=80)
		strcpy(gradeS13,"A");
	else if(S13>=70)
		strcpy(gradeS13,"B+");
	else if(S13>=60)
		strcpy(gradeS13,"B");
	else if(S13>=50)
		strcpy(gradeS13,"C+");
	else if(S13>=40)
		strcpy(gradeS13,"C");
	else if(S13>=30)
		strcpy(gradeS13,"D+");
	else
		strcpy(gradeS13,"D");
//End of subject 3 Grade calculation 
//subject 4 Grade calculation
	if(S14<=0)
	strcpy(gradeS14,"I");
else if(S14>=90)
		strcpy(gradeS14,"A+");
	else if(S14>=80)
		strcpy(gradeS14,"A");
	else if(S14>=70)
		strcpy(gradeS14,"B+");
	else if(S14>=60)
		strcpy(gradeS14,"B");
	else if(S14>=50)
		strcpy(gradeS14,"C+");
	else if(S14>=40)
		strcpy(gradeS14,"C");
	else if(S14>=30)
		strcpy(gradeS14,"D+");
	else
		strcpy(gradeS14,"D");
//End of subject 4 Grade calculation 
//subject 5 Grade calculation
	if(S15<=0)
	strcpy(gradeS15,"I");
else if(S15>=90)
		strcpy(gradeS15,"A+");
	else if(S15>=80)
		strcpy(gradeS15,"A");
	else if(S15>=70)
		strcpy(gradeS15,"B+");
	else if(S15>=60)
		strcpy(gradeS15,"B");
	else if(S15>=50)
		strcpy(gradeS15,"C+");
	else if(S15>=40)
		strcpy(gradeS15,"C");
	else if(S15>=30)
		strcpy(gradeS15,"D+");
	else
		strcpy(gradeS15,"D");
//End of subject 5 Grade calculation 
total1 = S11+S12+S13+S14+S15;
  per1 = total1/5.0;
  if(per1<=0)
	strcpy(grade1,"I");
  else if(per1>=90)
             strcpy(grade1,"A+");
 else if(per1>=80)
             strcpy(grade1,"A");
 else if(per1>=70)
             strcpy(grade1,"B+");
 else if(per1>=60)
             strcpy(grade1,"B");
 else if(per1>=50)
             strcpy(grade1,"C+");
 else if(per1>=40)
             strcpy(grade1,"C");
 else if(per1>=30)
 			strcpy(grade1,"D+");
 else 
 			strcpy(grade1,"D");
//End of Second term marks calculation
//++++++++++++++++++++++++++++++++++++++++++END+++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++START++++++++++++++++++++++++++++++
//SEMESTER MAIN marks calculation
//Subject 1 Grade calculation
	if(S21<=0)
	strcpy(gradeS21,"I");
	else if(S21>=90)
		strcpy(gradeS21,"A+");
	else if(S21>=80)
		strcpy(gradeS21,"A");
	else if(S21>=70)
		strcpy(gradeS21,"B+");
	else if(S21>=60)
		strcpy(gradeS21,"B");
	else if(S21>=50)
		strcpy(gradeS21,"C+");
	else if(S21>=40)
		strcpy(gradeS21,"C");
	else if(S21>=30)
		strcpy(gradeS21,"D+");
	else
		strcpy(gradeS21,"D");
//End of subject 1 Grade calculation
//subject 2 Grade calculation
if(S22<=0)
	strcpy(gradeS22,"I");
else if(S22>=90)
		strcpy(gradeS22,"A+");
	else if(S22>=80)
		strcpy(gradeS22,"A");
	else if(S22>=70)
		strcpy(gradeS22,"B+");
	else if(S22>=60)
		strcpy(gradeS22,"B");
	else if(S22>=50)
		strcpy(gradeS22,"C+");
	else if(S22>=40)
		strcpy(gradeS22,"C");
	else if(S22>=30)
		strcpy(gradeS22,"D+");
	else
		strcpy(gradeS22,"D");
//End of subject 2 Grade calculation 
//subject 3 Grade calculation
if(S23<=0)
	strcpy(gradeS23,"I");
else if(S23>=90)
		strcpy(gradeS23,"A+");
	else if(S23>=80)
		strcpy(gradeS23,"A");
	else if(S23>=70)
		strcpy(gradeS23,"B+");
	else if(S23>=60)
		strcpy(gradeS23,"B");
	else if(S23>=50)
		strcpy(gradeS23,"C+");
	else if(S23>=40)
		strcpy(gradeS23,"C");
	else if(S23>=30)
		strcpy(gradeS23,"D+");
	else
		strcpy(gradeS23,"D");
//End of subject 3 Grade calculation 
//subject 4 Grade calculation
if(S24<=0)
	strcpy(gradeS24,"I");
else if(S24>=90)
		strcpy(gradeS24,"A+");
	else if(S24>=80)
		strcpy(gradeS24,"A");
	else if(S24>=70)
		strcpy(gradeS24,"B+");
	else if(S24>=60)
		strcpy(gradeS24,"B");
	else if(S24>=50)
		strcpy(gradeS24,"C+");
	else if(S24>=40)
		strcpy(gradeS24,"C");
	else if(S24>=30)
		strcpy(gradeS24,"D+");
	else
		strcpy(gradeS24,"D");
//End of subject 4 Grade calculation 
//subject 5 Grade calculation
if(S25<=0)
	strcpy(gradeS25,"I");
else if(S25>=90)
		strcpy(gradeS25,"A+");
	else if(S25>=80)
		strcpy(gradeS25,"A");
	else if(S25>=70)
		strcpy(gradeS25,"B+");
	else if(S25>=60)
		strcpy(gradeS25,"B");
	else if(S25>=50)
		strcpy(gradeS25,"C+");
	else if(S25>=40)
		strcpy(gradeS25,"C");
	else if(S25>=30)
		strcpy(gradeS25,"D+");
	else
		strcpy(gradeS25,"D");
//End of subject 5 Grade calculation 
total2 = S21+S22+S23+S24+S25;
  per2 = total2/5.0;
  if (per2<=0)
   strcpy(grade2,"I");
  else if(per2>=90)
             strcpy(grade2,"A+");
 else if(per2>=80)
             strcpy(grade2,"A");
 else if(per2>=70)
             strcpy(grade2,"B+");
 else if(per2>=60)
             strcpy(grade2,"B");
 else if(per2>=50)
             strcpy(grade2,"C+");
 else if(per2>=40)
             strcpy(grade2,"C");
 else if(per2>=30)
 			strcpy(grade2,"D+");
 else 
 			strcpy(grade2,"D");
//End of SEMESTER MAIN marks calculation
//++++++++++++++++++++++++++++++++++++++++++END+++++++++++++++++++++++++++++++++
}
void getStudent1stMarks(){
		system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,3);
			cout<<"Enter the Marks of student:"<<endl;
			gotoxy(20,2);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,14);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,6);
			cout<<"Subject 1:";
			cin>>S01;
			gotoxy(25,8);
			cout<<"Subject 2:";
			cin>>S02;
			gotoxy(25,10);
			cout<<"Subject 3:";
			cin>>S03;
			gotoxy(25,12);
			cout<<"Subject 4:";
			cin>>S04;
			gotoxy(25,14);
			cout<<"Subject 5:";
			cin>>S05;
			marksCalculate();
}
void getStudent2ndMarks(){
	system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,3);
			cout<<"Enter the Marks of student:"<<endl;
			gotoxy(20,2);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,14);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,6);
			cout<<"Subject 1:";
			cin>>S11;
			gotoxy(25,8);
			cout<<"Subject 2:";
			cin>>S12;
			gotoxy(25,10);
			cout<<"Subject 3:";
			cin>>S13;
			gotoxy(25,12);
			cout<<"Subject 4:";
			cin>>S14;
			gotoxy(25,14);
			cout<<"Subject 5:";
			cin>>S15;
			marksCalculate();
}
void getStudent3rdMarks(){
		system("cls");
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(50,3);
			cout<<"Enter the Marks of student:"<<endl;
			gotoxy(20,2);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,14);
			cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
			gotoxy(25,6);
			cout<<"Subject 1:";
			cin>>S21;
			gotoxy(25,8);
			cout<<"Subject 2:";
			cin>>S22;
			gotoxy(25,10);
			cout<<"Subject 3:";
			cin>>S23;
			gotoxy(25,12);
			cout<<"Subject 4:";
			cin>>S24;
			gotoxy(25,14);
			cout<<"Subject 5:";
			cin>>S25;
			marksCalculate();
}
void putMarks(){
	int choice;
	while(true){
		system("cls");
		displaytime();
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\tлл\t  _________________________MARKS MENU_________________________  \tлл";
		cout << "\n\n\t\t\tлл\t 1: FIRST TERM                                                  \tлл";
		cout << "\n\n\t\t\tлл\t 2: SECOND TERM                                                 \tлл";
		cout << "\n\n\t\t\tлл\t 3: SEMESTER MAIN                                               \tлл";
		cout << "\n\n\t\t\tлл\t 4: BACK                                                        \tлл";
		cout << "\n\n\t\t\tлл\t 5: EXIT                                                        \tлл";
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		cin>>choice;
		switch(choice){
            case 1:
				display1result();
				break;
            case 2:
				display2result();
				break;
            case 3:
					display3result();
            	break;
            case 4:
            	marksMenu();
            	break;
            case 5:
            	exit(0);
            	default : 
			  cout<<"\n Wrong Choice.... Try again";
            }
		}
	}
void view1Result(){
	system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	gotoxy(0,7);
	cout<<"лл"<<endl;
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(105,7);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(42,3);
	cout<<"Result Of First Term"<<endl;
	gotoxy(10,5);
	cout<<"PROGRAM: "<<program<<endl;
	gotoxy(45,5);
	cout<<"SEMESTER:"<<sem<<endl;
	gotoxy(80,5);
	cout<<"ID:"<<id<<endl;
	gotoxy(10,7);
	cout<<"NAME:"<<name<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT"<<setw(22)<<"TOTAL MARKS"<<setw(24)<<"MARKS OBTAINED"<<setw(15)<<"GRADE"<<"\t\t|"<<endl;
	//cout<<"\t"<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT1"<<setw(22)<<100<<setw(24)<<S01<<setw(15)<<gradeS01<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT2"<<setw(22)<<100<<setw(24)<<S02<<setw(15)<<gradeS02<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT3"<<setw(22)<<100<<setw(24)<<S03<<setw(15)<<gradeS03<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT4"<<setw(22)<<100<<setw(24)<<S04<<setw(15)<<gradeS04<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT5"<<setw(22)<<100<<setw(24)<<S05<<setw(15)<<gradeS05<<"\t\t|"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"TOTAL"<<setw(22)<<500<<setw(24)<<total0<<setw(15)<<grade0<<"\t\t|"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<setw(16)<<"PERCENTAGE:"<<per0<<endl;
	getch();
}
void view2Result(){
	system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	gotoxy(0,7);
	cout<<"лл"<<endl;
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(105,7);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(42,3);
	cout<<"Result Of Second Term"<<endl;
	gotoxy(10,5);
	cout<<"PROGRAM: "<<program<<endl;
	gotoxy(45,5);
	cout<<"SEMESTER:"<<sem<<endl;
	gotoxy(80,5);
	cout<<"ID:"<<id<<endl;
	gotoxy(10,7);
	cout<<"NAME:"<<name<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT"<<setw(22)<<"TOTAL MARKS"<<setw(24)<<"MARKS OBTAINED"<<setw(15)<<"GRADE"<<"\t\t|"<<endl;
	//cout<<"\t"<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT1"<<setw(22)<<100<<setw(24)<<S11<<setw(15)<<gradeS11<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT2"<<setw(22)<<100<<setw(24)<<S12<<setw(15)<<gradeS12<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT3"<<setw(22)<<100<<setw(24)<<S13<<setw(15)<<gradeS13<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT4"<<setw(22)<<100<<setw(24)<<S14<<setw(15)<<gradeS14<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT5"<<setw(22)<<100<<setw(24)<<S15<<setw(15)<<gradeS15<<"\t\t|"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"TOTAL"<<setw(22)<<500<<setw(24)<<total1<<setw(15)<<grade1<<"\t\t|"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<setw(16)<<"PERCENTAGE:"<<per1<<endl;
	getch();
}
void view3Result(){
	system("cls");
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	gotoxy(0,1);
	cout<<"лл"<<endl;
	gotoxy(0,2);
	cout<<"лл"<<endl;
	gotoxy(0,3);
	cout<<"лл"<<endl;
	gotoxy(0,4);
	cout<<"лл"<<endl;
	gotoxy(0,5);
	cout<<"лл"<<endl;
	gotoxy(0,6);
	cout<<"лл"<<endl;
	gotoxy(0,7);
	cout<<"лл"<<endl;
	gotoxy(105,1);
	cout<<"лл"<<endl;
	gotoxy(105,2);
	cout<<"лл"<<endl;
	gotoxy(105,3);
	cout<<"лл"<<endl;
	gotoxy(105,4);
	cout<<"лл"<<endl;
	gotoxy(105,5);
	cout<<"лл"<<endl;
	gotoxy(105,6);
	cout<<"лл"<<endl;
	gotoxy(105,7);
	cout<<"лл"<<endl;
	gotoxy(42,2);
	cout<<"Kantipur City College"<<endl;
	gotoxy(42,3);
	cout<<"Result Of Sester Main"<<endl;
	gotoxy(10,5);
	cout<<"PROGRAM: "<<program<<endl;
	gotoxy(45,5);
	cout<<"SEMESTER:"<<sem<<endl;
	gotoxy(80,5);
	cout<<"ID:"<<id<<endl;
	gotoxy(10,7);
	cout<<"NAME:"<<name<<endl;
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT"<<setw(22)<<"TOTAL MARKS"<<setw(24)<<"MARKS OBTAINED"<<setw(15)<<"GRADE"<<"\t\t|"<<endl;
	//cout<<"\t"<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT1"<<setw(22)<<100<<setw(24)<<S21<<setw(15)<<gradeS21<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT2"<<setw(22)<<100<<setw(24)<<S22<<setw(15)<<gradeS22<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT3"<<setw(22)<<100<<setw(24)<<S23<<setw(15)<<gradeS23<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT4"<<setw(22)<<100<<setw(24)<<S24<<setw(15)<<gradeS24<<"\t\t|"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"SUBJECT5"<<setw(22)<<100<<setw(24)<<S25<<setw(15)<<gradeS25<<"\t\t|"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<setw(16)<<"TOTAL"<<setw(22)<<500<<setw(24)<<total2<<setw(15)<<grade2<<"\t\t|"<<endl;
	cout<<"\t"<<"_________________________________________________________________________________________"<<endl;
	cout<<"\t"<<setw(16)<<"PERCENTAGE:"<<per2<<endl;
	getch();
}
void display1result(){
	ifstream fin;
    fin.open("Student.dat");
    char tid[15];
    int flag=0;
    cout<<"\n Enter ID to search : ";
    cin>>tid;
    while(fin.read((char*)this,sizeof(student)))
    {
        if(strcmp(tid,id)==0)
         {
              view1Result();
              flag = 1;
          }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\n ID No : "<<tid <<" does not exist.... Try again";
        getch();
}
void display2result(){
	ifstream fin;
    fin.open("Student.dat");
    char tid[15];
    int flag=0;
    cout<<"\n Enter ID to search : ";
    cin>>tid;
    while(fin.read((char*)this,sizeof(student)))
    {
        if(strcmp(tid,id)==0)
         {
              view2Result();
              flag = 1;
          }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\n ID No : "<<tid <<" does not exist.... Try again";
        getch();
}
void display3result(){
	ifstream fin;
    fin.open("Student.dat");
    char tid[15];
    int flag=0;
    cout<<"\n Enter ID to search : ";
    cin>>tid;
    while(fin.read((char*)this,sizeof(student)))
    {
        if(strcmp(tid,id)==0)
         {
              view3Result();
              flag = 1;
          }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\n ID : "<<tid <<" does not exist.... Try again";
        getch();
}
void mainmenu(){
		system("cls");
		int choice;
	while(true)
		{
		system("cls");
		displaytime();
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\tлл\t  _________________________ADMIN PORTAL_________________________\tлл";
		cout << "\n\n\t\t\tлл\t 1: INSERT RECORD                                               \tлл";
		cout << "\n\n\t\t\tлл\t 2: VIEW RECORD                                                 \tлл";
		cout << "\n\n\t\t\tлл\t 3: MODIFY RECORD                                               \tлл";
		cout << "\n\n\t\t\tлл\t 4: SEARCH RECORD                                               \tлл";
		cout << "\n\n\t\t\tлл\t 5: DELETE RECORD                                               \tлл";
		cout << "\n\n\t\t\tлл\t 6: STUDENT's MARKS                                             \tлл";
		cout << "\n\n\t\t\tлл\t 7: Change Admin Password                                       \tлл";
		cout << "\n\n\t\t\tлл\t 8: EXIT                                                        \tлл";
		cout << "\n\n\t\t\tлллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
		cout << "\n\n\t\t\t\t Enter your Choice: ";
		//choice = getch();
		cin>>choice;
	switch(choice){
            case 1:
			    addRecord();		  
				break;
            case 2:
				recordMenu();
            	break;
            case 3:
				modifyRecord();
                break;
            case 4: 
				searchRecord();
                break;
            case 5:
            	delRecord();
                break;
            case 6:
            	marksMenu();
			   break;
			case 7:
				ChangePassword();
				break;
			case 8:
				exit(0);
				break;
            default : 
			  cout<<"\n Wrong Choice.... Try again";
			  
        	}
		}
	}
char* lastid(){
	char lastid[15];
	ifstream fin;
	fin.open("Student.dat");
	while(fin.read((char*)this,sizeof(student))){
		strcpy(lastid,id);
	}
	fin.close();
	return lastid;
}
	
ChangePassword(){
		system("cls");
		int flag=0;
    	string line,old,pass1,pass2;
		ifstream outf;
            outf.open("Password.txt");
            gotoxy(50,10);
            cout<<"Enter the old password :-";
            cin>>old;
            if (outf.is_open())
            {
            	while(!outf.eof())
            	{
             		outf>>line;
             		//temp=line;
            		if(old==line)
            		{
                		outf.close();
                		ofstream outf1;
                		outf1.open("Password.txt");
                		if (outf1.is_open())
             			{
             				gotoxy(50,12);
             				cout<<"enter your new password :-";
		                	cin>>pass1;
		                	gotoxy(50,14);
             				cout<<"enter Confirmation password :-";
             				cin>>pass2;
             				if(pass1==pass2)
             				{
                 				outf1<<pass1;
                 				gotoxy(50,16);
                 				cout<<"password changed succesfully";
                 				flag=1;
             				}
             			}
            		}
            else{
            	char retry;
            	gotoxy(50,16);
            	system("color F4");
              	cout<<"please enter valid password..."<<endl;
              	gotoxy(50,18);
				cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
				cin >> retry;
				if(retry == 'r' || retry == 'R'){
				system("cls");
				system("color F1");
				ChangePassword();
					}
					else
					{
					mainmenu();
					}
           	 	}
        	}
    	}
    ifstream file;
    file.open("Password.txt");
    	if(is_empty(file)){
    		ofstream outf1;
      	  	outf1.open("Password.txt");
       		if (outf1.is_open())
       		{
        	outf1<<line;
    		}
    		outf1.close();
		}
	file.close();
	
	if(flag==0){
		gotoxy(50,16);
        cout<<"Confirmation password didn't matched"<<endl;
        getch();
        //mainmenu();
        gotoxy(50,18);
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		char r;
		cin >> r;
			if(r == 'r' || r == 'R'){
			system("cls");
			system("color F1");
			ChangePassword();
			}
			else{
			mainmenu();
			cout<<"hi";
			}
	}
            gotoxy(50,20);
            cout<<"Press Enter to continue...........";
            getch();
            mainmenu();
	}
};
int main(){
	system("cls");
	system("color F1");
	login();
	student r;
	r.mainmenu();
	return 0;
}

