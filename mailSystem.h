#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include<string.h>
#include "heading.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
COORD CursorPosition; 

struct notice{
	string noticeText;
	notice* next;
	notice* prev;
};

struct announcement{
	string announceText;
	announcement* next;
	announcement* prev;
};

struct employeeLogin{
	string employeeUsername;
	string employeePassword;
	employeeLogin* next;
};

struct managerLogin{
	string managerUsername;
	string managerPassword;
	managerLogin* next;
};

struct mail{
	string senderID;
	string recieverID;
	string subject;
	string text;
	int isPriority;
	int isRead;
	mail* next;
};


void menu();
void employeeMenu();
void adminMenu();
void managerMenu();
void gotoXY();
void adminLogin();
void employeelogin();
void managerlogin();
void accountManagementMenu();
void editManager();
void editEmployee();
void addManager();
void addEmployee();
void listEmployee();
void listManager();
void titleScreen();
void sendMail(string ID);
void checkInbox(string ID);
void sendPriorityMail(string ID);
void checkPriorityInbox(string ID);
void mailMenu(struct mail *currMail);
void replyMail(string recID);
void forwardMail(string mailText, string sendID, string subject);
void viewMail(struct mail *currMail);
void searchMail(string ID,string searchID);
void updateNotice();
void updateAnnounce();
void viewNotice();
void viewAnnounce();

employeeLogin* employeeHead=NULL;
managerLogin* managerHead=NULL;
mail* mailHead=NULL;
notice* noticeHead=NULL;
announcement* announceHead=NULL;
string currentID;

void titleScreen(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("MAIL SYSTEM");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\t\t\t\t\tPress any key to continue.....";
	getch();
}
void addManager(){
	string newUsername, newPassword;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter new manager Username: ";
	cin>>newUsername;
	cout<<"\t\t\t\t\tEnter new manager Password: ";
	cin>>newPassword;
	cout<<"\n\n\t\t\t\t\tNew Manager Account Registered\n\n\t\t\t\t\tUsername: "<<newUsername<<"\n\t\t\t\t\tPassword: "<<newPassword<<"\n\t\t\t\t\tPress any key to continue....";
	managerLogin* temp;
	managerLogin* temp2;
	temp= new managerLogin;
	if(managerHead==NULL){
		temp->managerUsername=newUsername;
		temp->managerPassword=newPassword;
		temp->next=NULL;
		managerHead=temp;
	}
	else{
		temp->managerUsername=newUsername;
		temp->managerPassword=newPassword;
		temp2=managerHead;
		while(temp2->next!=NULL){
			temp2=temp2->next;
		}
		temp2->next=temp;
	}
	getch();
	system("CLS");
	}

void addEmployee(){
	string newUsername, newPassword;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter new employee Username: ";
	cin>>newUsername;
	cout<<"\t\t\t\t\tEnter new employee Password: ";
	cin>>newPassword;
	cout<<"\n\n\t\t\t\t\tNew Employee Account Registered\n\n\t\t\t\t\tUsername: "<<newUsername<<"\n\t\t\t\t\tPassword: "<<newPassword<<"\n\t\t\t\t\tPress any key to continue....";
	employeeLogin* temp;
	employeeLogin* temp2;
	temp= new employeeLogin;
	temp->employeeUsername=newUsername;
	temp->employeePassword=newPassword;
	temp->next=NULL;
	if(employeeHead==NULL){
		employeeHead=temp;
	}
	else{
		temp2=employeeHead;
		while(temp2->next!=NULL){
			temp2=temp2->next;
		}
		temp2->next=temp;
	}
	getch();
	system("CLS");
	accountManagementMenu();
}

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}


void menu(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Log-In");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";


int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); 
	gotoXY(18,7); cout << ">";
	
	while(running)
	{
        gotoXY(20,7);  cout << "1) Admin Log-in";
		gotoXY(20,8);  cout << "2) Manager Log-in";
		gotoXY(20,9);  cout << "3) Employee Log-in";
		gotoXY(20,10); cout << "4) Exit Program";


		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 10) 
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << ">";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << ">";
				menu_item--;
				continue;
			}
			
		else if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					system("CLS");
					adminLogin();
					break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					managerlogin();
					 break;
				}
					
				case 2: {
					system("CLS");
					employeelogin();
					break;
				}
					
				case 3:{
					gotoXY(20,16);
					cout << "Exiting....";
					running=false;
					break;
				}
				
			}


}
}
}

void adminMenu(){
	currentID="AM0001";
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Admin");
	SetConsoleTextAttribute(color, 15);
	gotoXY(1,28); cout<<"<-\nBackspace";
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;

int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); 
	gotoXY(18,7); cout << ">";
	
	while(running)
	{

        gotoXY(20,7);  cout << "1) Send Mail";
		gotoXY(20,8);  cout << "2) Check Inbox";
		gotoXY(20,9);  cout << "3) Account Management";
		gotoXY(20,10); cout << "4) Send Priority Mail";
		gotoXY(20,11); cout <<  "5) Update Announcements";
		gotoXY(20,12); cout <<  "6) Log Out";
		if(GetAsyncKeyState(VK_BACK)){
			HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
		SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Admin");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\n\n\t\t\t\t\tPress BACKSPACE again to exit\n\n\n\t\t\t\t\tPress any key to continue.....";
		getch();
		if(GetAsyncKeyState(VK_BACK)){
			system("CLS");
			menu();
		}
		else{
			adminMenu();
		}
			}

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << ">";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << ">";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					system("CLS");
					sendMail(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Admin");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
					
				}
					
					
				case 1: {
					gotoXY(20,16);
					system("CLS");
					checkInbox(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Admin");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
					
				case 2: {
					gotoXY(20,16);
					system("CLS");
					accountManagementMenu();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Admin");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
					
				case 3:{
					gotoXY(20,16);
					system("CLS");
					sendPriorityMail(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Admin");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
					 }
				case 4: {
					gotoXY(20,16);
					system("CLS");
					updateAnnounce();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Admin");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
				case 5: {
					gotoXY(20,16);
					system("CLS");
					menu();
				}
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
}

void employeeMenu(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Employee");
	SetConsoleTextAttribute(color, 15);
	gotoXY(1,28); cout<<"<-\nBackspace";
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;

int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); 
	gotoXY(18,7); cout << ">";
	
	while(running)
	{
        gotoXY(20,7);  cout << "1) Send Mail";
		gotoXY(20,8);  cout << "2) Check Inbox";
		gotoXY(20,9);  cout << "3) Check Priority Mail";
		gotoXY(20,10); cout << "4) View Announcements";
		gotoXY(20,11); cout <<  "5) View Notice Board";
		gotoXY(20,12); cout <<  "6) Log Out";
		if(GetAsyncKeyState(VK_BACK)){
			HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
		SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Employee");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\n\n\t\t\t\t\tPress BACKSPACE again to exit\n\n\n\t\t\t\t\tPress any key to continue.....";
		getch();
		if(GetAsyncKeyState(VK_BACK)){
			system("CLS");
			menu();
		}
		else{
			employeeMenu();
		}
			}


		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << ">";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << ">";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					sendMail(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Employee");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					checkInbox(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Employee");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
				}
					
				case 2: {
					gotoXY(20,16);
					checkPriorityInbox(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Employee");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
					
				case 3:{
					
					gotoXY(20,16);
					viewAnnounce();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Employee");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
				case 4: {
					gotoXY(20,16);
					viewNotice();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Employee");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					 break;
				}
				case 5: {
					gotoXY(20,16);
					cout << "Logging out....";
					running = false;
					system("CLS");
					menu();
					break;
				}
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
}

void managerMenu(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Manager");
	SetConsoleTextAttribute(color, 15);
	gotoXY(1,28); cout<<"<-\nBackspace";
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	

int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); 
	gotoXY(18,7); cout << ">";
	
	while(running)
	{
        gotoXY(20,7);  cout << "1) Send Mail";
		gotoXY(20,8);  cout << "2) Check Inbox";
		gotoXY(20,9);  cout << "3) Check Priority Mail";
		gotoXY(20,10); cout << "4) View Announcements";
		gotoXY(20,11); cout <<  "5) View Notice Board";
		gotoXY(20,12); cout <<  "6) Update Announcements";
		gotoXY(20,13); cout <<  "7) Update Notice Board";
		gotoXY(20,14); cout <<  "8) Log Out";
		if(GetAsyncKeyState(VK_BACK)){
			HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
		SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Manager");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\n\n\t\t\t\t\tPress BACKSPACE again to exit\n\n\n\t\t\t\t\tPress any key to continue.....";
		getch();
		if(GetAsyncKeyState(VK_BACK)){
			system("CLS");
			menu();
		}
		else{
			managerMenu();
		}
			}


		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 14) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << ">";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << ">";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				case 0:
					{
					
					system("CLS");
					sendMail(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
					}
				case 1:{
					
				
					system("CLS");
					checkInbox(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
					}
				case 2:
					{
					
					system("CLS");
					checkPriorityInbox(currentID);
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
				}
				case 3:{
					system("CLS");
					viewAnnounce();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
				}
				case 4:{
					system("CLS");
					viewNotice();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
				}
				case 5:{
								
					system("CLS");
					updateAnnounce();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;}
				case 6:{
					system("CLS");
					updateNotice();
					system("CLS");
					HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Manager");
					SetConsoleTextAttribute(color, 15);
					gotoXY(1,28); cout<<"<-\nBackspace";
					break;
				}
				case 7:{
					gotoXY(20,16);
					running=false;
					system("CLS");
					menu();
					break;
					}				
							
			}
				
		}		
		
	}
	
	gotoXY(20,21);
}




void accountManagementMenu(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	gotoXY(1,28); cout<<"<-\nBackspace";
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	

int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); 
	gotoXY(18,7); cout << ">";
	
	while(running)
	{
        gotoXY(20,7);  cout << "1) Add new Employee";
		gotoXY(20,8);  cout << "2) Edit current Employee";
		gotoXY(20,9);  cout << "3) Add new Manager";
		gotoXY(20,10); cout << "4) Edit current Manager";
		gotoXY(20,11); cout << "5) List all Employees";
		gotoXY(20,12); cout << "6) List all Managers";


		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << ">";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << ">";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_BACK)){
		HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
		SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Accounts");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\n\n\t\t\t\t\tPress BACKSPACE again to exit\n\n\n\t\t\t\t\tPress any key to continue.....";
		getch();
		if(GetAsyncKeyState(VK_BACK)){
			system("CLS");
			adminMenu();
		}
		else{
			system("CLS");
			accountManagementMenu();
		}
			}
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					addEmployee();
					system("CLS");
					adminMenu();
					 break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					editEmployee();
					system("CLS");
					adminMenu();
					 break;
				}
					
				case 2: {
					gotoXY(20,16);
					addManager();
					system("CLS");
					adminMenu();
					break;
				}
					
				case 3:{
					gotoXY(20,16);
					system("CLS");
					editManager();
					system("CLS");
					adminMenu();
					 break;
				}
				case 4:{
								
					gotoXY(20,16);
					system("CLS");
					listEmployee();
					system("CLS");
					adminMenu();
					 break;
				}
				case 5:{
								
					gotoXY(20,16);
					listManager();
					system("CLS");
					adminMenu();
					break;
				}
				
			}
				
		}	
			gotoXY(20,21);	
		
	}
}

	
void adminLogin(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	string adminUsername;
	string adminPassword;
	string ch;
	system("CLS");
	SetConsoleTextAttribute(color, 10);
	heading("LOG IN");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\t\t\t\t\tEnter Username: ";
	cin>>adminUsername;
	cout<<"\n\t\t\t\t\tEnter Password: ";
	for(int i=0;i<9;i++){
		ch=getch();
		adminPassword+=ch;
		cout<<"*";
	}
	if(adminUsername=="AM0001" && adminPassword=="password1"){
		cout<<"\n\n\n\t\t\t\t\tPlease Wait...";
		system("CLS");
		adminMenu();
		
	}
	else{
		system("CLS");
		SetConsoleTextAttribute(color, 10);
		heading("Log in");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\t\t\t\t\tIncorrect Username or Password.....\n\t\t\t\t\tPress any key to continue.....";
		getch();
		menu();
		
	}
}

void employeelogin(){
	
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	employeeLogin *temp;
	string empUsername;
	string empPassword;
	string ch;
	system("CLS");
	SetConsoleTextAttribute(color, 10);
	heading("LOG IN");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\t\t\t\t\tEnter Username: ";
	cin>>empUsername;
	cout<<"\n\n\t\t\t\t\tEnter Password: ";
	cin>>empPassword;
	temp=employeeHead;
	if(employeeHead==NULL){
		system("CLS");
		SetConsoleTextAttribute(color, 10);
		heading("LOG IN");
		SetConsoleTextAttribute(color, 15);
		cout<<"Register some employees first.....";
		getch();
		menu();
	}
	else{
	while(temp->next!=NULL){
		if(empUsername==temp->employeeUsername&&empPassword==temp->employeePassword){
				cout<<"\n\n\n\t\t\t\t\tPlease Wait...";
				sleep(4);
				system("CLS");
				currentID=temp->employeeUsername;
				employeeMenu();
			}
		else{
			temp=temp->next;
		}
	}
		if(empUsername==temp->employeeUsername&&empPassword==temp->employeePassword){
				currentID=temp->employeeUsername;
				cout<<"\n\n\n\t\t\t\t\tPlease Wait...";
				sleep(4);
				system("CLS");
				employeeMenu();
			}
	
		system("CLS");
				SetConsoleTextAttribute(color, 10);
				heading("Log in");
				SetConsoleTextAttribute(color, 15);
				cout<<"\n\t\t\t\t\tIncorrect Password.....\n\t\t\t\t\tPress any key to continue.....";
				getch();
				system("CLS");
				menu();
	}	
}

void managerlogin(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	managerLogin *temp;
	string mgrUsername;
	string mgrPassword;
	string ch;
	system("CLS");
	SetConsoleTextAttribute(color, 10);
	heading("LOG IN");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\t\t\t\t\tEnter Username: ";
	cin>>mgrUsername;
	cout<<"\n\n\t\t\t\t\tEnter Password: ";
	cin>>mgrPassword;
	temp=managerHead;
	if(managerHead==NULL){
		system("CLS");
		SetConsoleTextAttribute(color, 10);
		heading("LOG IN");
		SetConsoleTextAttribute(color, 15);
		cout<<"Register some managers first.....";
		getch();
		menu();
	}
	else{
	while(temp->next!=NULL){

		if(mgrUsername==temp->managerUsername&&mgrPassword==temp->managerPassword){
				cout<<"\n\n\n\t\t\t\t\tPlease Wait...";
				currentID=temp->managerUsername;
				sleep(4);
				system("CLS");
				managerMenu();
			}
		else{
			temp=temp->next;
		}
	}
	if(mgrUsername==temp->managerUsername&&mgrPassword==temp->managerPassword){
				currentID=temp->managerUsername;
				cout<<"\n\n\n\t\t\t\t\tPlease Wait...";
				sleep(4);
				system("CLS");
				managerMenu();
			}
		system("CLS");
				SetConsoleTextAttribute(color, 10);
				heading("Log in");
				SetConsoleTextAttribute(color, 15);
				cout<<"\n\t\t\t\t\tIncorrect Password.....\n\t\t\t\t\tPress any key to continue.....";
				getch();
				system("CLS");
				menu();
	}	
}
void editEmployee(){
	string keyUsername;
	string newUser,newPass;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter employee Username: ";
	cin>>keyUsername;
	employeeLogin* temp;
	temp=employeeHead;	
	if(employeeHead==NULL){
		system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\t\t\t\t\tRegister some Employees first....";
	getch();
	adminMenu();
	}
	else{
	while(temp->next!=NULL){
		if(temp->employeeUsername==keyUsername){
			SetConsoleTextAttribute(color, 10);
			system("CLS");
			heading("Accounts");
			SetConsoleTextAttribute(color, 10);
			SetConsoleTextAttribute(color, 15);
			cout<<"\n\n\n";
			cout<<"\t\t\t\t\tEnter new Username: ";
			cin>>newUser;
			cout<<"\t\t\t\t\tEnter new Password: ";
			cin>>newPass;
			cout<<"\n\n\t\t\t\t\tOld Username: "<<temp->employeeUsername<<"\n\t\t\t\t\tOld Password: "<<temp->employeePassword<<"\n\n";
			cout<<"\n\t\t\t\t\tNew Username: "<<newUser<<"\n\t\t\t\t\tNew Password: "<<newPass<<"\n\t\t\t\t\tPress any key to confirm....";
			getch();
			temp->employeePassword=newPass;
			temp->employeeUsername=newUser;
			system("CLS");
			adminMenu();
			
		}
		else{
			temp=temp->next;
		}
				if(temp->employeeUsername==keyUsername){
			SetConsoleTextAttribute(color, 10);
			system("CLS");
			heading("Accounts");
			SetConsoleTextAttribute(color, 10);
			SetConsoleTextAttribute(color, 15);
			cout<<"\n\n\n";
			cout<<"\t\t\t\t\tEnter new Username: ";
			cin>>newUser;
			cout<<"\t\t\t\t\tEnter new Password: ";
			cin>>newPass;
			cout<<"\n\n\t\t\t\t\tOld Username: "<<temp->employeeUsername<<"\n\t\t\t\t\tOld Password: "<<temp->employeePassword<<"\n\n";
			cout<<"\n\t\t\t\t\tNew Username: "<<newUser<<"\n\t\t\t\t\tNew Password: "<<newPass<<"\n\t\t\t\t\tPress any key to confirm....";
			getch();
			temp->employeePassword=newPass;
			temp->employeeUsername=newUser;
			system("CLS");
			adminMenu();
			
		}
		else{
		
			system("CLS");
			SetConsoleTextAttribute(color, 10);
			heading("Accounts");
			SetConsoleTextAttribute(color, 15);
			cout<<"\n\t\t\t\t\tInvalid ID, Employee does not exist....";
			getch();
			system("CLS");
			accountManagementMenu();
	}
	}
}
}

void editManager(){
	string keyUsername;
	string newUser,newPass;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter manager Username: ";
	cin>>keyUsername;
	managerLogin* temp;
	temp=managerHead;	
	if(managerHead==NULL){
		system("CLS");
	SetConsoleTextAttribute(color, 10);	
	heading("Accounts");
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\t\t\t\t\tRegister some Managers first....";
	getch();
	adminMenu();
	}
	else{
	
	while(temp->next!=NULL){
		if(temp->managerUsername==keyUsername){
			SetConsoleTextAttribute(color, 10);
			system("CLS");
			heading("Accounts");
			SetConsoleTextAttribute(color, 10);
			SetConsoleTextAttribute(color, 15);
			cout<<"\n\n\n";
			cout<<"\t\t\t\t\tEnter new Username: ";
			cin>>newUser;
			cout<<"\t\t\t\t\tEnter new Password: ";
			cin>>newPass;
			cout<<"\n\n\t\t\t\t\tOld Username: "<<temp->managerUsername<<"\n\t\t\t\t\tOld Password: "<<temp->managerPassword<<"\n\n";
			cout<<"\n\t\t\t\t\tNew Username: "<<newUser<<"\n\t\t\t\t\tNew Password: "<<newPass<<"\n\t\t\t\t\tPress any key to confirm....";
			getch();
			temp->managerPassword=newPass;
			temp->managerUsername=newUser;
			system("CLS");
			adminMenu();
			
		}
		else{
			temp=temp->next;
		}
		if(temp->managerUsername==keyUsername){
			SetConsoleTextAttribute(color, 10);
			system("CLS");
			heading("Accounts");
			SetConsoleTextAttribute(color, 10);
			SetConsoleTextAttribute(color, 15);
			cout<<"\n\n\n";
			cout<<"\t\t\t\t\tEnter new Username: ";
			cin>>newUser;
			cout<<"\t\t\t\t\tEnter new Password: ";
			cin>>newPass;
			cout<<"\n\n\t\t\t\t\tOld Username: "<<temp->managerUsername<<"\n\t\t\t\t\tOld Password: "<<temp->managerPassword<<"\n\n";
			cout<<"\n\t\t\t\t\tNew Username: "<<newUser<<"\n\t\t\t\t\tNew Password: "<<newPass<<"\n\t\t\t\t\tPress any key to confirm....";
			getch();
			temp->managerPassword=newPass;
			temp->managerUsername=newUser;
			system("CLS");
			adminMenu();
			
		}
			SetConsoleTextAttribute(color, 10);
			system("CLS");
			heading("Accounts");
			SetConsoleTextAttribute(color, 10);
			SetConsoleTextAttribute(color, 15);
			cout<<"\n\t\t\t\t\tInvalid ID, Manager does not exist....";
			getch();
			system("CLS");
			accountManagementMenu();
	}
}
}

void listEmployee(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	employeeLogin* temp;
	temp=employeeHead;
	int counter=1;
	if(employeeHead==NULL){
		cout<<"\n\t\t\t\t\tNo Employees registered currently....";
		getch();
		system("CLS");
		accountManagementMenu();
		}
	else{
		cout<<"\n\t\t\t\t\tEmployees\n";
		for(int i=0;i<120;i++){
			cout<<"_";
		}
		while(temp->next!=NULL){
			cout<<"\n\n\t\t\t\t\t"<<counter<<") "<<temp->employeeUsername<<"\n";
			temp=temp->next;
			counter++;
		}
			cout<<"\n\n\t\t\t\t\t"<<counter<<") "<<temp->employeeUsername<<"\n";
			temp=temp->next;
			counter++;
	}
	getch();
	system("CLS");
	accountManagementMenu();
}

void listManager(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Accounts");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	managerLogin* temp;
	temp=managerHead;
	int counter=1;
	if(managerHead==NULL){
		cout<<"\n\t\t\t\t\tNo Managers registered currently....";
		getch();
		system("CLS");
		accountManagementMenu();
		}
	else{
		cout<<"\n\t\t\t\t\tManagers\n";
		for(int i=0;i<120;i++){
			cout<<"_";
		}
		while(temp->next!=NULL){
			cout<<"\n\n\t\t\t\t\t"<<counter<<") "<<temp->managerUsername<<"\n";
			temp=temp->next;
			counter++;
		}
			cout<<"\n\n\t\t\t\t\t"<<counter<<") "<<temp->managerUsername<<"\n";
			temp=temp->next;
			counter++;
	}
	getch();
	system("CLS");
	accountManagementMenu();
}

void sendMail(string ID){

	mail* newMail= new mail;
	mail* mailTemp;
	employeeLogin* empTemp;
	empTemp=employeeHead;
	managerLogin* mgrTemp;
	mgrTemp=managerHead;
	string recID,mailSubj,mailText;
	int flag=0;
	mailTemp=mailHead;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Compose Mail");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter reciever ID: ";
	getline(cin, recID);
	for(int i=0;i<120;i++){
		cout<<"_";
	}
	if(recID=="AM0001"){
		flag=1;
		goto A;
	}
	if(flag==0){
		if(employeeHead==NULL){
			flag=0;
		}
		else{
			while(empTemp->next!=NULL){
				if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
				else{
					empTemp=empTemp->next;
				}
			}
			if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
		}
		if(flag==0){
			if(managerHead==NULL){
			flag=0;
			}
		else{
			while(mgrTemp->next!=NULL){
				if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
				else{
					mgrTemp=mgrTemp->next;
				}
			}
			if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
		}
	}
	}
	A:
	if(flag==1){
		cout<<"\n\nEnter Subject: ";
		getline(cin, mailSubj);
		for(int i=0;i<120;i++){
		cout<<"_";
		}
		cout<<"\n\nEnter Mail Text: ";
		getline(cin, mailText);
		for(int i=0;i<120;i++){
		cout<<"_";
		}
		newMail->isPriority=0	;
		newMail->isRead=0;
		newMail->senderID=currentID;
		newMail->subject=mailSubj;
		newMail->text=mailText;
		newMail->recieverID=recID;
		newMail->next=NULL;
		if(mailHead==NULL){
			mailHead=newMail;
		}
		else{
			while(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
		}
			mailTemp->next=newMail;
		}
	}
	else{
		cout<<"Invalid ID...";
		getch();
		sendMail(currentID);
		
	}
	
	
	}

void checkInbox(string ID){
	mail* mailTemp;
	mailTemp=mailHead;
	employeeLogin* empTemp;
	managerLogin* mgrTemp;
	int mailCount=0;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Inbox");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(1,28);cout<<"Press TAB to search Mail";
	gotoXY(1,7);
	int xCord=0,yCord=8;
	for(int i=0;i<120;i++){
		gotoXY(xCord,yCord);
		cout<<"_";
		xCord++;
	}
	gotoXY(3,7);cout<<"| Sender ID";
	gotoXY(3,8);cout<<"|";gotoXY(25,8);cout<<"|";gotoXY(70,8);cout<<"|";
	gotoXY(25,7);cout<<"| Subject";
	gotoXY(70,7);cout<<"| E-mail";
	gotoXY(2,28);
		xCord=3;yCord=7;
	for(int i=0;i<20;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}
	xCord=25,yCord=8;
	for(int i=0;i<19;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}	
	xCord=70,yCord=8;
	for(int i=0;i<19;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}
	gotoXY(18,5); 
	gotoXY(1,9); cout << ">";
	//(const, var)
	int pMail=0;
	if(mailHead==NULL){
		cout<<"\n\t\t\t\t\tInbox Empty";
		getch();
		system("CLS");
	}
	//else if(){
	//	cout<<"\n\t\t\t\t\tInbox Empty";
	//}
	else{
		mailTemp=mailHead;
		while(mailTemp->next!=NULL){
			mailCount+=1;
			mailTemp=mailTemp->next;
		}
		mailCount+=1;
		
	int temp=9;
	int textLen;
	int subjLen;
	mailTemp=mailHead;
		gotoXY(20,20);cout<<"MAIL COUNT: "<<mailCount<<"\n";
		for(int i=0;i<=mailCount;i++){
			textLen=mailTemp->text.length();
			subjLen=mailTemp->subject.length();
			gotoXY(9,temp);
			if(mailTemp->recieverID==currentID&&mailTemp->isPriority==0){
				pMail++;
				if(mailTemp->isRead==0){
					SetConsoleTextAttribute(color,12);
						cout<<mailTemp->senderID;gotoXY(26,temp);if(subjLen>40){
				for(int i=0;i<35;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->subject;
			gotoXY(71,temp);if(textLen>50){
				for(int i=0;i<40;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->text;
			SetConsoleTextAttribute(color,15);
			}
			else{
				if(mailTemp->isRead==1){
					
				cout<<mailTemp->senderID;gotoXY(26,temp);if(subjLen>40){
				for(int i=0;i<35;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->subject;
			gotoXY(71,temp);if(textLen>50){
				for(int i=0;i<40;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->text;
			SetConsoleTextAttribute(color,15);
			}
			
				}
		
			if(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
			}
			else{
				break;
			}
			temp=temp+2;
		}
		else{
			mailTemp=mailTemp->next;
		}
	}
	int Mcount=9+mailCount, x=9,test=0;
	int a;
				managerLogin* mgrTemp1;
				employeeLogin* empTemp1;
				mgrTemp1=managerHead;
				empTemp1=employeeHead;
	bool running = true;	
	while(running)
	{
		
		system("pause>nul"); // the >nul bit causes it the print no message
	
		if(GetAsyncKeyState(VK_DOWN) && x != Mcount) //down button pressed
			{
				test++;
				gotoXY(1,x); cout << "  ";
				x=x+2;
				gotoXY(1,x); cout << ">";
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 9) //up button pressed
			{
				test--;
				gotoXY(1,x); cout << "  ";
				x=x-2;
				gotoXY(1,x); cout << ">";
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			mailTemp=mailHead;
			for(int i=0;i<test;i++){
				mailTemp=mailTemp->next;
			}
			mailMenu(mailTemp);
			system("CLS");
			checkInbox(currentID);
			break;
			}
		if(GetAsyncKeyState(VK_BACK)){
			running=false;
			if(currentID=="AM0001"){
				adminMenu();
			}
			else{
				if(managerHead==NULL){
					a=0;
				}
				else{
					while(mgrTemp1->next!=NULL){
						if(mgrTemp1->managerUsername==currentID){
							a=1;
							managerMenu();
							break;
						}
						mgrTemp1=mgrTemp1->next;
					}
				}
				if(employeeHead==NULL){
					a=0;
				}
				else{
					while(empTemp1->next!=NULL){
						if(empTemp1->employeeUsername==currentID){
							a=1;
							employeeMenu();
							break;
							}
							empTemp1=empTemp1->next;
					}
				}
			}
			
		}
			if(GetAsyncKeyState(VK_TAB)){
			int flag=0;
			string recID;
			B:
			system("CLS");
			SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Inbox");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\t\t\t\t\tEnter ID to search: ";
		cin>>recID;
		if(recID=="AM0001"){
		flag=1;
		goto A;
	}
	if(flag==0){
		if(employeeHead==NULL){
			flag=0;
		}
		else{
			while(empTemp->next!=NULL){
				if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
				else{
					empTemp=empTemp->next;
				}
			}
			if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
		}
		if(flag==0){
			if(managerHead==NULL){
			flag=0;
			}
		else{
			while(mgrTemp->next!=NULL){
				if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
				else{
					mgrTemp=mgrTemp->next;
				}
			}
			if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
		}
	}
	}
	A:
	if(flag==1){
	searchMail(currentID,recID);
	}
	else{
		cout<<"Invalid ID...";
		getch();
		goto B;
		
	}
		}		
		}
	}
	}

	
void mailMenu(struct mail *currMail){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Inbox");
	SetConsoleTextAttribute(color, 15);
	gotoXY(1,28); cout<<"<-\nBackspace";
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;



int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); 
	gotoXY(18,7); cout << ">";
	
	while(running)
	{
        gotoXY(20,7);  cout << "View Mail";
		gotoXY(20,8);  cout << "Reply";
		gotoXY(20,9);  cout << "Forward Mail";
		gotoXY(20,10); cout << "<-Back";


		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 10) 
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << ">";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << ">";
				menu_item--;
				continue;
			}
		if(GetAsyncKeyState(VK_BACK)){
			system("CLS");
			checkInbox(currentID);
		}
			
		else if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					system("CLS");
					viewMail(currMail);
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Inbox");
					SetConsoleTextAttribute(color, 15);
					break;
				}
					
					
				case 1: {
					system("CLS");
					replyMail(currMail->senderID);
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Inbox");
					SetConsoleTextAttribute(color, 15);
					break;
					
				}
					
				case 2: {
					system("CLS");
					forwardMail(currMail->subject,currMail->text,currMail->senderID);
					SetConsoleTextAttribute(color, 10);
					system("CLS");
					heading("Inbox");
					SetConsoleTextAttribute(color, 15);
					break;
				}
					
				case 3:{
					system("CLS");
					checkInbox(currentID);				
					break;
				}
				
			}


}
}
}


void viewMail(struct mail *currMail){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Inbox");
	SetConsoleTextAttribute(color, 15);
	gotoXY(1,28); cout<<"<-\nBackspace";
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(9,9);cout<<"\n\t\t\t\t\tSender ID: "<<currMail->senderID;
	cout<<"\n\t\t\t\t\tRecepient ID: "<<currMail->recieverID;
	cout<<"\n";
	for(int i=0;i<120;i++){
		cout<<"_";
	}
	cout<<"\nSubject: "<<currMail->subject;
	cout<<"\n\n\n";
	for(int i=0;i<120;i++){
		cout<<"_";
	}
	cout<<"\nMail: "<<currMail->text;
	currMail->isRead=1;
	getch();
	system("CLS");
}	
	
void replyMail(string recID){
	
	mail* newMail= new mail;
	mail* mailTemp;
	employeeLogin* empTemp;
	empTemp=employeeHead;
	managerLogin* mgrTemp;
	mgrTemp=managerHead;
	string mailSubj,mailText;
	int flag=0;
	mailTemp=mailHead;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Reply Mail");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	
		cout<<"\n\nEnter Subject: ";
		getline(cin, mailSubj);
		for(int i=0;i<120;i++){
		cout<<"_";
		}
		cout<<"\n\nEnter Mail Text: ";
		getline(cin, mailText);
		for(int i=0;i<120;i++){
		cout<<"_";
		}
		newMail->isPriority=0	;
		newMail->isRead=0;
		newMail->senderID=currentID;
		newMail->subject="REPLY: "+ mailSubj;
		newMail->text=mailText;
		newMail->recieverID=recID;
		newMail->next=NULL;
		if(mailHead==NULL){
			mailHead=newMail;
		}
		else{
			while(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
		}
			mailTemp->next=newMail;
		}
	}

void forwardMail(string mailSubj, string mailText, string sendID){
	mail* newMail= new mail;
	mail* mailTemp;
	employeeLogin* empTemp;
	empTemp=employeeHead;
	managerLogin* mgrTemp;
	mgrTemp=managerHead;
	string recID;
	int flag=0;
	mailTemp=mailHead;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Compose Mail");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter reciever ID: ";
	getline(cin, recID);
	for(int i=0;i<120;i++){
		cout<<"_";
	}
	if(recID=="AM0001"){
		flag=1;
		goto A;
	}
	if(flag==0){
		if(employeeHead==NULL){
			flag=0;
		}
		else{
			while(empTemp->next!=NULL){
				if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
				else{
					empTemp=empTemp->next;
				}
			}
			if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
		}
		if(flag==0){
			if(managerHead==NULL){
			flag=0;
			}
		else{
			while(mgrTemp->next!=NULL){
				if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
				else{
					mgrTemp=mgrTemp->next;
				}
			}
			if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
		}
	}
	}
	A:
	if(flag==1){
		
		newMail->isPriority=0	;
		newMail->isRead=0;
		newMail->senderID=currentID;
		newMail->subject="FORWARDED: "+mailSubj;
		newMail->text=mailText;
		newMail->recieverID=recID;
		newMail->next=NULL;
		if(mailHead==NULL){
			mailHead=newMail;
		}
		else{
			while(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
		}
			mailTemp->next=newMail;
		}
	}
	else{
		cout<<"Invalid ID...";
		getch();
		forwardMail(mailSubj,mailText,sendID);
	
	} 
	
}


void searchMail(string ID,string searchID){
mail* mailTemp;
	mailTemp=mailHead;
	int mailCount=0;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Inbox");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(1,7);
	int xCord=0,yCord=8;
	for(int i=0;i<120;i++){
		gotoXY(xCord,yCord);
		cout<<"_";
		xCord++;
	}
	gotoXY(3,7);cout<<"| Sender ID";
	gotoXY(3,8);cout<<"|";gotoXY(25,8);cout<<"|";gotoXY(70,8);cout<<"|";
	gotoXY(25,7);cout<<"| Subject";
	gotoXY(70,7);cout<<"| E-mail";
	gotoXY(2,28);
		xCord=3;yCord=7;
	for(int i=0;i<20;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}
	xCord=25,yCord=8;
	for(int i=0;i<19;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}	
	xCord=70,yCord=8;
	for(int i=0;i<19;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}
	gotoXY(18,5); 
	gotoXY(1,9); cout << ">";
	//(const, var)
	if(mailHead==NULL){
		cout<<"\n\t\t\t\t\tInbox Empty";
		getch();
		system("CLS");
	}
	//else if(){
	//	cout<<"\n\t\t\t\t\tInbox Empty";
	//}
	else{
		mailTemp=mailHead;
		while(mailTemp->next!=NULL){
			mailCount+=1;
			mailTemp=mailTemp->next;
		}
		mailCount+=1;
		
	int temp=9;
	int textLen;
	int subjLen;
	mailTemp=mailHead;
		gotoXY(20,20);cout<<"MAIL COUNT: "<<mailCount<<"\n";
		for(int i=0;i<mailCount;i++){
			textLen=mailTemp->text.length();
			subjLen=mailTemp->subject.length();
			gotoXY(9,temp);
			if(mailTemp->recieverID==currentID&&mailTemp->senderID==searchID){
				if(mailTemp->isRead==0){
					SetConsoleTextAttribute(color,12);
						cout<<mailTemp->senderID;gotoXY(26,temp);if(subjLen>40){
				for(int i=0;i<35;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->subject;
			gotoXY(71,temp);if(textLen>50){
				for(int i=0;i<40;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->text;
			SetConsoleTextAttribute(color,15);
			}
			else{
				if(mailTemp->isRead==1){
					
				cout<<mailTemp->senderID;gotoXY(26,temp);if(subjLen>40){
				for(int i=0;i<35;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->subject;
			gotoXY(71,temp);if(textLen>50){
				for(int i=0;i<40;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->text;
			SetConsoleTextAttribute(color,15);
			}
			
				}
		
			if(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
			}
			else{
				break;
			}
			temp=temp+2;
		}
	}
	int Mcount=9+mailCount, x=9,test=0;
	bool running = true;	
	while(running)
	{
		if(GetAsyncKeyState(VK_BACK)){
		SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Inbox");
		SetConsoleTextAttribute(color, 15);
		}
		
		
		system("pause>nul"); // the >nul bit causes it the print no message
	
		if(GetAsyncKeyState(VK_DOWN) && x != Mcount) //down button pressed
			{
				test++;
				gotoXY(1,x); cout << "  ";
				x=x+2;
				gotoXY(1,x); cout << ">";
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 9) //up button pressed
			{
				test--;
				gotoXY(1,x); cout << "  ";
				x=x-2;
				gotoXY(1,x); cout << ">";
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			mailTemp=mailHead;
			for(int i=0;i<test;i++){
				mailTemp=mailTemp->next;
			}
			mailMenu(mailTemp);
			break;
			}
				
		}			
	getch();
	}
}
void updateNotice(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Notice");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(1,7);
	notice* noticeTemp;
	notice* newNotice= new notice;
	string a;
	cout<<"\n\t\t\t\t\tEnter new Notice: ";
	getline(cin,newNotice->noticeText);
	newNotice->next=NULL;
	newNotice->prev=NULL;
	if(noticeHead==NULL){
		noticeHead=newNotice;
		cout<<"\t\t\t\t\tNew notice updated.....";
		getch();
	}
	else{
		noticeTemp=noticeHead;
		while(noticeTemp->next!=NULL){
			noticeTemp=noticeTemp->next;
		}
		noticeTemp->next=newNotice;
		newNotice->prev=noticeTemp;
		newNotice->next=NULL;
		cout<<"\t\t\t\t\tNew notice updated.....";
		getch();
			}
}

void updateAnnounce(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Announce");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(1,7);
	announcement* announceTemp;
	announcement* newAnnounce= new announcement;
	string a;
	cout<<"\n\t\t\t\t\tEnter new Announcement: ";
	getline(cin,newAnnounce->announceText);
	newAnnounce->next=NULL;
	newAnnounce->prev=NULL;
	if(announceHead==NULL){
		announceHead=newAnnounce;
		cout<<"\t\t\t\t\tNew announcement updated.....";
		getch();
		system("CLS");
	}
	else{
		announceTemp=announceHead;
		while(announceTemp->next!=NULL){
			announceTemp=announceTemp->next;
		}
		announceTemp->next=newAnnounce;
		newAnnounce->prev=announceTemp;
		newAnnounce->next=NULL;
		cout<<"\t\t\t\t\tNew announcement updated.....";
		getch();
		system("CLS");
			}
}

void viewNotice(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Notice");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(0,7);
	notice* noticeTemp;
	noticeTemp=noticeHead;
	if(noticeHead==NULL){
		cout<<"\n\t\t\t\t\tNo active Notices...";
		getch();
	}
	else{
		int x=1;
		while(noticeTemp->next!=NULL){
			cout<<x<<" ) "<<noticeTemp->noticeText;
			cout<<"\n\n";
			for(int i=0;i<120;i++){
				cout<<"=";
			}
				noticeTemp=noticeTemp->next;
				x++;
		}
		cout<<x<<" ) "<<noticeTemp->noticeText;
		cout<<"\n\n";
		for(int i=0;i<120;i++){
				cout<<"=";
			}
		
		getch();
	}
}

void viewAnnounce(){
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Announcement");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(1,14);
	announcement* announceTemp;
	announceTemp=announceHead;
	if(announceHead==NULL){
		cout<<"\n\t\t\t\t\tNo active Announcements...";
		getch();
	}
	else{
		int x=1;
		while(announceTemp->next!=NULL){
			cout<<x<<" ) "<<announceTemp->announceText;
			cout<<"\n\n";
			for(int i=0;i<120;i++){
				cout<<"=";
			}
				announceTemp=announceTemp->next;
				x++;
		}
		cout<<x<<" ) "<<announceTemp->announceText;
		cout<<"\n\n";
		for(int i=0;i<120;i++){
				cout<<"=";
			}
		
		getch();
	}
}

void sendPriorityMail(string ID){
	
	mail* newMail= new mail;
	mail* mailTemp;
	employeeLogin* empTemp;
	empTemp=employeeHead;
	managerLogin* mgrTemp;
	mgrTemp=managerHead;
	string recID,mailSubj,mailText;
	int flag=0;
	mailTemp=mailHead;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Compose Mail");
	SetConsoleTextAttribute(color, 10);
	SetConsoleTextAttribute(color, 15);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tEnter reciever ID: ";
	getline(cin, recID);
	for(int i=0;i<120;i++){
		cout<<"_";
	}
	if(recID=="AM0001"){
		flag=1;
		goto A;
	}
	if(flag==0){
		if(employeeHead==NULL){
			flag=0;
		}
		else{
			while(empTemp->next!=NULL){
				if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
				else{
					empTemp=empTemp->next;
				}
			}
			if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
		}
		if(flag==0){
			if(managerHead==NULL){
			flag=0;
			}
		else{
			while(mgrTemp->next!=NULL){
				if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
				else{
					mgrTemp=mgrTemp->next;
				}
			}
			if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
		}
	}
	}
	A:
	if(flag==1){
		cout<<"\n\nEnter Subject: ";
		getline(cin, mailSubj);
		for(int i=0;i<120;i++){
		cout<<"_";
		}
		cout<<"\n\nEnter Mail Text: ";
		getline(cin, mailText);
		for(int i=0;i<120;i++){
		cout<<"_";
		}
		newMail->isPriority=1	;
		newMail->isRead=0;
		newMail->senderID=currentID;
		newMail->subject=mailSubj;
		newMail->text=mailText;
		newMail->recieverID=recID;
		newMail->next=NULL;
		if(mailHead==NULL){
			mailHead=newMail;
		}
		else{
			while(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
		}
			mailTemp->next=newMail;
		}
	}
	else{
		cout<<"Invalid ID...";
		getch();
		sendMail(currentID);
		
	}
	
	
	
	
	
}
void checkPriorityInbox(string ID){
	
	mail* mailTemp;
	mailTemp=mailHead;
	employeeLogin* empTemp;
	managerLogin* mgrTemp;
	int mailCount=0;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	SetConsoleTextAttribute(color, 10);
	system("CLS");
	heading("Inbox");
	SetConsoleTextAttribute(color, 15);
	gotoXY(0,26); for(int i=0;i<120;i++){
		cout<<"_";
	}
	gotoXY(1,28);cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLogged in as:  "<<currentID;
	gotoXY(1,28);cout<<"Press TAB to search Mail";
	gotoXY(1,7);
	int xCord=0,yCord=8;
	for(int i=0;i<120;i++){
		gotoXY(xCord,yCord);
		cout<<"_";
		xCord++;
	}
	gotoXY(3,7);cout<<"| Sender ID";
	gotoXY(3,8);cout<<"|";gotoXY(25,8);cout<<"|";gotoXY(70,8);cout<<"|";
	gotoXY(25,7);cout<<"| Subject";
	gotoXY(70,7);cout<<"| E-mail";
	gotoXY(2,28);
		xCord=3;yCord=7;
	for(int i=0;i<20;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}
	xCord=25,yCord=8;
	for(int i=0;i<19;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}	
	xCord=70,yCord=8;
	for(int i=0;i<19;i++){
		gotoXY(xCord,yCord);
		cout<<"|";
		yCord++;
	}
	gotoXY(18,5); 
	gotoXY(1,9); cout << ">";
	//(const, var)
	int pMail=0;
	if(mailHead==NULL){
		cout<<"\n\t\t\t\t\tInbox Empty";
		getch();
		system("CLS");
	}
	//else if(){
	//	cout<<"\n\t\t\t\t\tInbox Empty";
	//}
	else{
		mailTemp=mailHead;
		while(mailTemp->next!=NULL){
			mailCount+=1;
			mailTemp=mailTemp->next;
		}
		mailCount+=1;
		
	int temp=9;
	int textLen;
	int subjLen;
	mailTemp=mailHead;
		for(int i=0;i<=mailCount;i++){
			textLen=mailTemp->text.length();
			subjLen=mailTemp->subject.length();
			gotoXY(9,temp);
			if(mailTemp->recieverID==currentID&&mailTemp->isPriority==1){
				pMail++;
				if(mailTemp->isRead==0){
					SetConsoleTextAttribute(color,12);
						cout<<mailTemp->senderID;gotoXY(26,temp);if(subjLen>40){
				for(int i=0;i<35;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->subject;
			gotoXY(71,temp);if(textLen>50){
				for(int i=0;i<40;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->text;
			SetConsoleTextAttribute(color,15);
			}
			else{
				if(mailTemp->isRead==1){
					
				cout<<mailTemp->senderID;gotoXY(26,temp);if(subjLen>40){
				for(int i=0;i<35;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->subject;
			gotoXY(71,temp);if(textLen>50){
				for(int i=0;i<40;i++){
					cout<<mailTemp->text[i];
				}
					cout<<"....";
			}
			else cout<<mailTemp->text;
			SetConsoleTextAttribute(color,15);
			}
			
				}
		
			if(mailTemp->next!=NULL){
				mailTemp=mailTemp->next;
			}
			else{
				break;
			}
			temp=temp+2;
		}
		else{
			mailTemp=mailTemp->next;
		}
	}
	int Mcount=9+mailCount, x=9,test=0;
	int a;
				managerLogin* mgrTemp1;
				employeeLogin* empTemp1;
				mgrTemp1=managerHead;
				empTemp1=employeeHead;
	bool running = true;	
	while(running)
	{
		
		system("pause>nul"); // the >nul bit causes it the print no message
	
		if(GetAsyncKeyState(VK_DOWN) && x != Mcount) //down button pressed
			{
				test++;
				gotoXY(1,x); cout << "  ";
				x=x+2;
				gotoXY(1,x); cout << ">";
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 9) //up button pressed
			{
				test--;
				gotoXY(1,x); cout << "  ";
				x=x-2;
				gotoXY(1,x); cout << ">";
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			mailTemp=mailHead;
			for(int i=0;i<test;i++){
				mailTemp=mailTemp->next;
			}
			mailMenu(mailTemp);
			system("CLS");
			checkInbox(currentID);
			break;
			}
		if(GetAsyncKeyState(VK_BACK)){
			running=false;
			if(currentID=="AM0001"){
				adminMenu();
			}
			else{
				if(managerHead==NULL){
					a=0;
				}
				else{
					while(mgrTemp1->next!=NULL){
						if(mgrTemp1->managerUsername==currentID){
							a=1;
							managerMenu();
							break;
						}
						mgrTemp1=mgrTemp1->next;
					}
				}
				if(employeeHead==NULL){
					a=0;
				}
				else{
					while(empTemp1->next!=NULL){
						if(empTemp1->employeeUsername==currentID){
							a=1;
							employeeMenu();
							break;
							}
							empTemp1=empTemp1->next;
					}
				}
			}
			
		}
			if(GetAsyncKeyState(VK_TAB)){
			int flag=0;
			string recID;
			B:
			system("CLS");
			SetConsoleTextAttribute(color, 10);
		system("CLS");
		heading("Inbox");
		SetConsoleTextAttribute(color, 15);
		cout<<"\n\t\t\t\t\tEnter ID to search: ";
		cin>>recID;
		if(recID=="AM0001"){
		flag=1;
		goto A;
	}
	if(flag==0){
		if(employeeHead==NULL){
			flag=0;
		}
		else{
			while(empTemp->next!=NULL){
				if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
				else{
					empTemp=empTemp->next;
				}
			}
			if(recID==empTemp->employeeUsername){
					flag=1;
					goto A;
				}
		}
		if(flag==0){
			if(managerHead==NULL){
			flag=0;
			}
		else{
			while(mgrTemp->next!=NULL){
				if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
				else{
					mgrTemp=mgrTemp->next;
				}
			}
			if(recID==mgrTemp->managerUsername){
					flag=1;
					goto A;
				}
		}
	}
	}
	A:
	if(flag==1){
	searchMail(currentID,recID);
	}
	else{
		cout<<"Invalid ID...";
		getch();
		goto B;
		
	}
		}		
		}
	}
	
}

