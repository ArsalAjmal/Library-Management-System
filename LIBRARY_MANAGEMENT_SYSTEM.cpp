#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

//Prototype Functions.
void Admin_panel();
void User_panel();
void add_book();
void modify_record();
void delete_book();
void search_book();
void search_user_book();
void borrow_book();
void borrow_user_book();
void display_Records();
void display_user_Records();
void returnBook();
void admin_login();
void user_login();
void login_panel();
void signUp();
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------ADMIN LOGIN---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

 
//Login Panel for admin
void admin_login()
{
	system("cls");
	
	int userName , username;
	string password, pass;
	bool found=false;

	cout<<"\t\t\t\t\t--------------------------\t\t\t"<<endl;
	cout<<"\t\t\t\t\t  LOG IN TO YOUR ACCOUNT\t\t\t"<<endl;
	cout<<"\t\t\t\t\t--------------------------\t\t\t\n"<<endl;
	cout<<"\t\t\t\t\tEnter Your Username = ";
	cin>>username;
	cout<<"\t\t\t\t\tEnter Password = ";
	cin>>pass;
	fstream adminFile("AdminRecord.txt");
		if (!adminFile.is_open() ) {
                cout << "Error opening file!" << endl;
                return;}
                
	while(adminFile>>userName){
		getline(adminFile >> ws, password);
		
		if(userName == username && password== pass)
		{
			Admin_panel();
			found=true;
		}
	
	}
	if(found)
        {
        Admin_panel();
         }
		else
     	{
		system("cls");
		cout<<"Invalid Password or username...Please Try again"<<endl;
		system("pause");
		login_panel();
    	}
		adminFile.close();
 }
 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------USER LOGIN---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

 
 //login panel for user
void user_login()
{
	system("cls");
	cout<<"\t\t\t\t\t--------------------------\t\t\t"<<endl;
	cout<<"\t\t\t\t\t  LOG IN TO YOUR ACCOUNT\t\t\t"<<endl;
	cout<<"\t\t\t\t\t--------------------------\t\t\t\n"<<endl;
	int userName , enteredId;
	string password, entPassword;
	bool found=false;
	cout<<"\t\t\t\t\tEnter Your Username = ";
	cin>>enteredId;
	cout<<"\t\t\t\t\tEnter Password = ";
	cin>>entPassword;
		fstream userFile("UserRecord.txt");
		if (!userFile.is_open() ) {
                cout << "Error opening file!" << endl;
                return;}
                
	while(userFile>>userName){
		getline(userFile >> ws, password);
		
		if(userName == enteredId && password== entPassword)
		{
			User_panel();
			found=true;
		}
	    
	}      
		if(found)
        {
        User_panel();
         }
		else
     	{
		system("cls");
		cout<<"Invalid Password or username...Please Try again"<<endl;
		system("pause");
		login_panel();
    	}
		
	userFile.close();
	
	
	
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------LOGIN PANEL---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void login_panel()
{
	system("cls");
	cout<<"\t\t\t\t\t--------------------------\t\t\t"<<endl;
	cout<<"\t\t\t\t\t  LOG IN TO YOUR ACCOUNT\t\t\t"<<endl;
	cout<<"\t\t\t\t\t--------------------------\t\t\t\n"<<endl;
	cout<<"\t\t\t\t\t    1.Admin Panel\t\t\t"<<endl;
	cout<<"\t\t\t\t\t    2.User Panel\t\t\t\n"<<endl;
		int n;
	cout<<"\t\t\t\t\t    Your Choice = ";
	cin>>n;	
	switch(n)
	{
		case 1:
		{
		admin_login();	
		break;	
		}
		
	case 2:
		{
		user_login();
		break;
		}
		default:
			{
				cout<<"INVALID ENTRY"<<endl;
				break;
			}
	
}
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------ADMIN PANEL---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/	 
 //Admin Panel	 
void Admin_panel()
{
	system("cls");
	cout<<"---------------------------------------------------------------"<<endl<<endl<<endl;
	cout<<"       Welcome to our libary management system                 "<<endl<<endl<<endl;
	cout<<"---------------------------------------------------------------"<<endl<<endl<<endl;
	cout<<"1.Add a New Book."<<endl;
	cout<<"2.Display all Record "<<endl;
	cout<<"3.Search a Specific Book"<<endl;
	cout<<"4.Update Record of a Book."<<endl;
	cout<<"5.Delete a book."<<endl;
	cout<<"6.Borrow a Book."<<endl;
	cout<<"7.Return a Book."<<endl;
	cout<<"0.Exit System"<<endl;
	
	int num;
	cout<<"Your choice = ";
	cin>>num;
	switch(num){
		case 1:
			{
			   system("cls");
			   add_book();
				break;		
			}
		case 2:
			{ 
			    system("cls");
			    display_Records();
				break;
			}
		case 3:
			{	
				system("cls");
				search_book();
				break;
			}
		case 4:
			{ 
			    system("cls");
			    modify_record();
				break;
			}
		case 5:
			{
				system("cls");
				delete_book();
				break;
			}
		case 6:
			{
				system("cls");
				borrow_book();
				break;
			}
		case 7:
			{
				system("cls");
				returnBook();
				break;
			}
	
		case 0:
			{
				system("cls");
		    	cout<<"SYSTEM EXIT."<<endl;
		    	exit(0);
				break;
			}
		default:
			{
				cout<<"Error"<<endl;
				break;
			}		
				}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------USER PANEL---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

		//User panel
void User_panel()
{
		system("cls");
	cout<<"---------------------------------------------------------------"<<endl<<endl<<endl;
	cout<<"       Welcome to our libary management system                 "<<endl<<endl<<endl;
	cout<<"---------------------------------------------------------------"<<endl<<endl<<endl;
	cout<<"1.Display all Record "<<endl;
	cout<<"2.Search a Specific Book"<<endl;
	cout<<"3.Borrow a Book"<<endl;
	cout<<"0.Exit System"<<endl;
	int num;
	cout<<"Your choice = ";
	cin>>num;
	switch(num){
		case 1:
			{
			    system("cls");
			    display_user_Records();	
				break;		
			}
		case 2:
			{
				system("cls");
				search_user_book();
				break;
			}
		case 3:
			{
				system("cls");
				borrow_user_book();
				break;
			}
		case 0:
			{
				system("cls");
		    	cout<<"SYSTEM EXIT."<<endl;
		    	exit(0);
				break;
			}
		default:
			{
				cout<<"Error"<<endl;
				break;
			}		
				}
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------ADD A RECORD---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void add_book()
{
	char choice;
	
	string bookAuthor, bookId, book_Id;
	string bookTitle;
	int copiesAvailable;
	int category;
           
	cout<<"     Categories   " << endl;
	cout<<"--------------------" <<endl;
    cout<<"1- Computer Science" << endl;
    cout<<"2- English" << endl;
    cout<<"3- History" << endl;
    cout<<"4- Islamiat" << endl;
    cout<<"5- Mathematics" << endl;
    cout<<"6- Exit" << endl << endl;
    
    cout<<"Enter the category/genre of the book: ";
    cin>> category;
    switch(category)
	{
		case 1: // for computer science
	       	{ //scope for case 1 (cs books)
	       	do 
	       	{
	       		ifstream fin("ComputerScienceRecord.txt");
	       		ofstream CS("ComputerScienceRecord.txt", ios::app);
				
					
	            cout<<"Add a new Book : "<<endl;
	            cout<<"------------------"<<endl;
	            cout << "Enter the new book Id: ";
	            cin>>bookId;
	
	             if(fin.is_open() && CS.is_open())
				{
	
	            while(fin >>book_Id >> ws)
	            {
	            	if(bookId == book_Id)
	            	{
						cout << "Error! Record already existing." << endl;
	            	    cout<<"Enter the New book Id : ";
	            	    cin.ignore();
	            	    getline(cin, bookId);
	            	} 
					}
					
				}
			    else
				{
					cout << "error";
				}
	            cout<<"Enter name of the book : ";
	            cin.ignore();
	            getline(cin,bookTitle);
	
	            cout<<"Enter the name of the author of the book : ";
	            getline(cin,bookAuthor);
	          
	            cout<<"Enter the copies available of this book : ";
	            cin>>copiesAvailable;
	
	            CS<<bookId<<endl;
				CS<<bookTitle<<endl;
	            CS<<bookAuthor<<endl;
	            CS<<copiesAvailable<<endl;
	            CS<<endl;
	
	            CS.close();
	              cout << "Do you want to add another book? (y/n): ";
      cin >> choice;
	        }
	         while (choice=='y' || choice =='Y');
        
             if (choice=='n' || choice=='N')
            {
        	    Admin_panel();
		    }
	            break;
	           }
        case 2: // for English
           
                { //scope for case 2 (english books)
            do
            {
                ifstream fin("EnglishRecord.txt");
                ofstream english("EnglishRecord.txt", ios::app);
	       		cout<<"Add a new Book :   "<<endl;
	            cout<<"------------------"<<endl;
	            cout<<"Enter the new book Id : ";
	            cin>>bookId;
	            
	            if(fin.is_open() && english.is_open())
				{
				
	            while(fin >> book_Id  >> ws)
	            {
	            	if(bookId == book_Id)
	            	{
	            		cout << "Error! Record already existing." << endl;
	            	    cout<<"Enter the New book Id : ";
	            	    cin.ignore();
	            	    getline(cin, book_Id);
					}	
				}
				}
				else
				{
					cout << "error";
				}
	            
	            cout<<"Enter name of the book : ";
	            cin.ignore();
	            getline(cin,bookTitle);
	
	            cout<<"Enter the name of the author of the book : ";
	            getline(cin,bookAuthor);
	            
	            cout<<"Enter the copies available of this book : ";
	            
	            cin>>copiesAvailable;
				   
	       		
                english<<bookId<<endl;
	            english<<bookTitle<<endl;
	            english<<bookAuthor<<endl;
	            english<<copiesAvailable<<endl;
	            
	
	            english.close();
	              cout << "Do you want to add another book? (y/n): ";
    		 cin >> choice;
	        }
	         while (choice=='y' || choice =='Y');
        
             if (choice=='n' || choice=='N')
            {
        	   Admin_panel();
		    }
	            break;
	            }
	    case 3: // for History
          
          	{ //scope for case 3 (history books)
          	do
			{
			 ifstream fin("HistoryRecord.txt");
          	 ofstream history("HistoryRecord.txt", ios::out |ios::app);
          	 cout<<"Add a new Book : "<<endl;
	         cout<<"------------------"<<endl;
	         cout<<"Enter the new book Id : ";
	         cin>>bookId;
	         if(fin.is_open() && history.is_open())
				{
				
	            while(fin >> book_Id  >> ws)
	            {
	            	if(bookId == book_Id)
	            	{
	            		cout << "Error! Record already existing." << endl;
	            	    cout<<"Enter the New book Id : ";
	            	    cin.ignore();
	            	    getline(cin, book_Id);
					}	
				}
				}
				else
				{
					cout << "error";
				}
	            
	         cout<<"Enter name of the book : ";
	         cin.ignore();
	         getline(cin,bookTitle);
	
	         cout<<"Enter the name of the author of the book : ";
	         getline(cin,bookAuthor);
	         
	         cout<<"Enter the copies available of this book : ";
	            
	         cin>>copiesAvailable;
				   
	       		
             history<<bookId<<endl;
	         history<<bookTitle<<endl;
	         history<<bookAuthor<<endl;
	         history<<copiesAvailable<<endl;
	            
	
	         history.close();
	           cout << "Do you want to add another book? (y/n): ";
      cin >> choice;
	     }
	         while (choice=='y' || choice =='Y');
        
             if (choice=='n' || choice=='N')
            {
        	   Admin_panel();
		    }
	         break;
	        }
        case 4 :// for Islamiat
          
          	{ //scope for case 4 (islamiat books)
          	do
          	{
		    ifstream fin("IslamicRecord.txt");
          	ofstream isl("IslamicRecord.txt", ios::out |ios::app);
          	cout<<"Add a new Book : "<<endl;
	        cout<<"------------------"<<endl;
	        cout<<"Enter the new book Id : ";
	        cin>>bookId;
	        if(fin.is_open() && isl.is_open())
				{
				
	            while(fin >> book_Id  >> ws)
	            {
	            	if(bookId == book_Id)
	            	{
	            		cout << "Error! Record already existing." << endl;
	            	    cout<<"Enter the New book Id : ";
	            	    cin.ignore();
	            	    getline(cin, book_Id);
					}	
				}
				}
				else
				{
					cout << "error";
				}
	        cout<<"Enter name of the book : ";
	        cin.ignore();
	        getline(cin,bookTitle);
	
	        cout<<"Enter the name of the author of the book : ";
	        getline(cin,bookAuthor);
	        
	        cout<<"Enter the copies available of this book : ";
	            
	        cin>>copiesAvailable;
				   
	       		
            isl<<bookId<<endl;
	        isl<<bookTitle<<endl;
	        isl<<bookAuthor<<endl;
	        isl<<copiesAvailable<<endl;
	            
	
	        isl.close();
	          cout << "Do you want to add another book? (y/n): ";
      cin >> choice;
	    }
	        while (choice=='y' || choice =='Y');
        
            if (choice=='n' || choice=='N')
         {
        	   Admin_panel();
		 }
	        break;
	        }
        case 5 : // for Mathematics
           
           	{ //scope for case 5 (maths books)
		    do
		    {
			ifstream fin("MathematicsRecord.txt");
           	ofstream maths("MathematicsRecord.txt",ios::app);
            cout<<"Add a new Book : "<<endl;
	        cout<<"------------------"<<endl;
	        cout<<"Enter the new book Id : ";
	        cin>>bookId;
	        if(fin.is_open() && maths.is_open())
				{
				
	            while(fin >> book_Id  >> ws)
	            {
	            	if(bookId == book_Id)
	            	{
	            		cout << "Error! Record already existing." << endl;
	            	    cout<<"Enter the New book Id : ";
	            	    cin.ignore();
	            	    getline(cin, book_Id);
					}	
				}
				}
				else
				{
					cout << "Error opening the file.";
				}
	        cout<<"Enter name of the book : ";
	        cin.ignore();
	        getline(cin,bookTitle);
	
	        cout<<"Enter the name of the author of the book : ";
	        getline(cin,bookAuthor);
	        
	        cout<<"Enter the copies available of this book : ";
	            
	        cin>>copiesAvailable;
				   
	       		
            maths<<bookId<<endl;
	        maths<<bookTitle<<endl;
	        maths<<bookAuthor<<endl;
	        maths<<copiesAvailable<<endl;
	            
	
	        maths.close();
	          cout << "Do you want to add another book? (y/n): ";
      cin >> choice;
	    }
	      while (choice=='y' || choice =='Y');
        
            if (choice=='n' || choice=='N')
          {
        	   Admin_panel();
		  }
			break;
	        }
        case 6: // for exit
          
            {  // //scope for case 6 (exit)	
            cout<<"exiting the function......";
          	
          	Admin_panel();
          	
          	break;
            }
        default :
        	{
        		cout<<"Invalid entry.";
			}
		          
      } //scope for switch
    
    
   } //scope for do
   
//Addition of books

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------DISPLAY RECORD---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void displayComputerScienceRecords()
 {
    ifstream file("ComputerScienceRecord.txt");

    if (!file.is_open()) {
        cout << "Error opening file: ComputerScienceRecord.txt" << endl;
        return;
    }

    // Display records...
    
    int  copiesAvailable;
    string bookTitle, bookAuthor,bookId;
    
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout << "                                   Computer Science Record :                                                          " << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout <<left<< setw(10) << "Book Id" <<  setw(40) <<"Book Name" <<right << setw(32) << "Author" << setw(32) << "Copies Available" << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;

    while (getline(file>>ws,bookId)) {
    
        getline(file>>ws, bookTitle);
        getline(file>>ws, bookAuthor);
        file >> copiesAvailable;
        file.ignore();
        

        cout <<left<< setw(10) << bookId << setw(60) <<left<< bookTitle << setw(30) << bookAuthor << setw(20) << copiesAvailable << endl;
         cout << "______________________________________________________________________________________________________________________" << endl;

    }
    file.close();
}

void displayEnglishRecords() 
{
    ifstream file("EnglishRecord.txt");

    if (!file.is_open()) {
        cout << "Error opening file: EnglishRecord.txt" << endl;
        return;
    }

    // Display records...
    
    int  copiesAvailable;
    string bookTitle, bookAuthor,bookId;
    
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout << "                                        English Record  :                                                             " << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout <<left<< setw(10) << "Book Id" <<  setw(40) <<"Book Name" <<right << setw(32) << "Author" << setw(32) << "Copies Available" << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;

    while (getline(file>>ws,bookId)) {
    
        getline(file>>ws, bookTitle);
        getline(file>>ws, bookAuthor);
        file >> copiesAvailable;
        file.ignore();
        

        cout <<left<< setw(10) << bookId << setw(60) <<left<< bookTitle << setw(30) << bookAuthor << setw(20) << copiesAvailable << endl;
         cout << "______________________________________________________________________________________________________________________" << endl;

    }
    file.close();
}

	void displayHistroyRecords()
	 {
    ifstream file("HistoryRecord.txt");

    if (!file.is_open()) {
        cout << "Error opening file: HistroyRecord.txt" << endl;
        return;
    }

    // Display records...
    
    int  copiesAvailable;
    string bookTitle, bookAuthor,bookId;
    
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout << "                                        Histroy Record :                                                              " << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout <<left<< setw(10) << "Book Id" <<  setw(40) <<"Book Name" <<right << setw(32) << "Author" << setw(32) << "Copies Available" << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;

    while (getline(file>>ws,bookId)) {
    
        getline(file>>ws, bookTitle);
        getline(file>>ws, bookAuthor);
        file >> copiesAvailable;
        file.ignore();
        

        cout <<left<< setw(10) << bookId << setw(60) <<left<< bookTitle << setw(30) << bookAuthor << setw(20) << copiesAvailable << endl;
         cout << "______________________________________________________________________________________________________________________" << endl;

    }
    file.close();
}

	void displayIslamicRecords()
	 {
    ifstream file("IslamicRecord.txt");

    if (!file.is_open()) {
        cout << "Error opening file: IslamicRecord.txt" << endl;
        return;
    }

    // Display records...
    
    int  copiesAvailable;
    string bookTitle, bookAuthor,bookId;
    
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout << "                                        Islamic Record :                                                              " << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout <<left<< setw(10) << "Book Id" <<  setw(40) <<"Book Name" <<right << setw(32) << "Author" << setw(32) << "Copies Available" << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;

    while (getline(file>>ws,bookId)) {
    
        getline(file>>ws, bookTitle);
        getline(file>>ws, bookAuthor);
        file >> copiesAvailable;
        file.ignore();
        

        cout <<left<< setw(10) << bookId << setw(60) <<left<< bookTitle << setw(30) << bookAuthor << setw(20) << copiesAvailable << endl;
         cout << "______________________________________________________________________________________________________________________" << endl;

    }
    file.close();
}

	void displayMathematicsRecords() 
	{
    ifstream file("MathematicsRecord.txt");

    if (!file.is_open()) {
        cout << "Error opening file: MathematicsRecord.txt" << endl;
        return;
    }

    // Display records...
    
    int  copiesAvailable;
    string bookTitle, bookAuthor,bookId;
    
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout << "                                        Mathematics Record :                                                          " << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;
    cout <<left<< setw(10) << "Book Id" <<  setw(40) <<"Book Name" <<right << setw(32) << "Author" << setw(32) << "Copies Available" << endl;
    cout << "______________________________________________________________________________________________________________________" << endl;

    while (getline(file>>ws,bookId)) {
    
        getline(file>>ws, bookTitle);
        getline(file>>ws, bookAuthor);
        file >> copiesAvailable;
        file.ignore();
        

        cout <<left<< setw(10) << bookId << setw(60) <<left<< bookTitle << setw(30) << bookAuthor << setw(20) << copiesAvailable << endl;
         cout << "______________________________________________________________________________________________________________________" << endl;

    }
    file.close();
}

	

void displayAllCategories()
 {
    displayComputerScienceRecords();
    displayEnglishRecords();
    displayHistroyRecords();
    displayIslamicRecords();
    displayMathematicsRecords();
    
}

void display_Records() 
{  char choice;

 
	cout << "     Categories   " << endl;
    cout << "--------------------" << endl;
	cout << "1- Computer Science" << endl;
    cout << "2- English" << endl;
    cout << "3- History" << endl;
    cout << "4- Islamiat" << endl;
    cout << "5- Mathematics" << endl;
    cout << "6- All Book Data" << endl;
    cout << "7- Exit" << endl << endl;


int Number;

cout<<" Enter the your Choice: ";
cin>>Number;

switch(Number)
{
case 1:
	{
		do{
		
		displayComputerScienceRecords();
		 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        
 		if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
		break;
}
	 
	 case 2:
	 {
	 	do{
		 
	 	displayEnglishRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        
 		if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
		break;
}
	
	 
	 case 3:
	 {
	 	do{
		 
	 	displayHistroyRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        
 		if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
		break;
}
	
	 
	 case 4:
	 {   
	 	do{
		 
	 	displayIslamicRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        
 		if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
		break;
}

	 
	 case 5:
	 {  
	    do{
		
	 	displayMathematicsRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        
 		if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
		break;
}
	
	 
	 case 6:
	 { do{
	 
	 	displayAllCategories();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        
 		if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
		break;
}
	 case 7:
	 {
	 	Admin_panel();
		break;
}

     default :
     {
     cout<<"INVALID CHOICE "<<endl;
	 break;	
}
                    }  
                    
   
   
}



/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------SEARCH A SPECIFIC BOOK-------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void search_book() {

  int copiesAvailable;
  string bookTitle, bookAuthor, bookId, enteredBookId;
  int category;
  char choice;


    cout << "     Categories   " << endl;
    cout << "--------------------" << endl;
    cout << "1- Computer Science" << endl;
    cout << "2- English" << endl;
    cout << "3- History" << endl;
    cout << "4- Islamiat" << endl;
    cout << "5- Mathematics" << endl;
    cout << "6- Exit" << endl << endl;

    cout << "Enter the category/genre of the book: ";
    cin >> category;

    switch (category) {

    case 1: // for computer science

    { //scope for case 1 (cs books)
    do{
	

      ifstream CS("ComputerScienceRecord.txt");

      if (!CS.is_open()) { //.is_open() is member function of iftsream (used to check if file is opened or not --> returns true if opens or false if doesnt
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (CS >> bookId) //reads string from the file  (which is bookId) (we have given string datatype to bookId)
      {
        CS.ignore(); //used to skip over a newline character after reading the book ID.
        getline(CS, bookTitle); //this line reads a line of text from the input stream  and stores it in the bookTitle variable.
        getline(CS, bookAuthor); //this reads the book author from the file and stores it in the bookAuthor variable.
        CS >> copiesAvailable; //This line reads an integer ( from the input stream amd shows the number of copies available.
        CS.ignore();

        if (bookId == enteredBookId) //this is executed if the bookiD  from the file  is equal to the entered book ID 
        {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;


          break; // used to exit the loop early as the book is found and no need is there to continue searching

        }
      }
      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      CS.close();
      cout << "Do you want to search for another book? (y/n): ";
    cin >> choice;
    system("cls");

  } // scope for do 

  while (choice == 'y' || choice == 'Y');

  if (choice == 'n' || choice == 'N') {
    cout << "Returning to main menu......";
    Sleep(2000);
    Admin_panel();
  }

      break;

    } //scope for case 1 (cs books)

    case 2: // for English

    { //scope for case 2 (english books)
    do{
	

      ifstream english("EnglishRecord.txt");

      if (!english.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (english >> bookId) {
        english.ignore();
        getline(english, bookTitle);
        getline(english, bookAuthor);
        english >> copiesAvailable;
        english.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

         
          break;

        }
      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      english.close();
      
      cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    	system("cls");

  	}	 // scope for do 

  	while (choice == 'y' || choice == 'Y');

  	if (choice == 'n' || choice == 'N') {
    cout << "Returning to main menu......";
    Sleep(2000);
    Admin_panel();
  }

      break;
    } //scope for case 2 (english books)

    case 3: // for History

    { //scope for case 3 (history books)
    
    do{
	

      ifstream history("HistoryRecord.txt");

      if (!history.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (history >> bookId) {
        history.ignore();
        getline(history, bookTitle);
        getline(history, bookAuthor);
        history >> copiesAvailable;
        history.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

         
          break;

        }

      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      history.close();
      
        
      cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    	system("cls");

  	}	 // scope for do 

  	while (choice == 'y' || choice == 'Y');

  	if (choice == 'n' || choice == 'N') {
    cout << "Returning to main menu......";
    Sleep(2000);
    Admin_panel();
  }
      break;
    } //scope for case 3 (history books)

    case 4: // for Islamiat

    { //scope for case 4 (islamiat books)
    do{
	

      ifstream isl("IslamicRecord.txt");

      if (!isl.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (isl >> bookId) {
        isl.ignore();
        getline(isl, bookTitle);
        getline(isl, bookAuthor);
        isl >> copiesAvailable;
        isl.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

          break;

        }

      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      isl.close();
        
      cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    	system("cls");

  	}	 // scope for do 

  	while (choice == 'y' || choice == 'Y');

  	if (choice == 'n' || choice == 'N') {
    cout << "Returning to main menu......";
    Sleep(2000);
    Admin_panel();
  }
      break;
    } //scope for case 4 (islamiat books)

    case 5: // for Mathematics

    { //scope for case 5 (maths books)
    
    do{

      ifstream maths("MathematicsRecord.txt");

      if (!maths.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (maths >> bookId) {
        maths.ignore();
        getline(maths, bookTitle);
        getline(maths, bookAuthor);
        maths >> copiesAvailable;
        maths.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

          break;

        }

      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      maths.close();
        
      cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    	system("cls");

  	}	 // scope for do 

  	while (choice == 'y' || choice == 'Y');

  	if (choice == 'n' || choice == 'N') {
    cout << "Returning to main menu......";
    Sleep(2000);
    Admin_panel();
  }
      break;
    } //scope for case 5 (maths books)

    case 6: // for exit

    { // //scope for case 6 (exit)

      cout << "exiting the function......";
      Sleep(2000);

      Admin_panel();

      break;

    }

    default:

    { //scope for default

      cout << "Enter a valid option from the menu." << endl;

      break;

    } //scope for default

    } //scope for switch 

    

} //scope of void search_book


/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------MODIFY A RECORD--------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void modifyMenu()                              // Menu function for different options for madification.
{
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << "\n";
    cout << "      Modification of Book Record         " << "\n";
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << "\n";
    cout << endl;
    cout << "1. For Modifying a Specific Book Detail " << endl;
    cout << "2. Adding the Number of Copies " << endl;
    cout << "3. Removing the Number of Copies " << endl;
    cout << "0. To Exit " << endl;
}
void Modify_ComputerScience()          
{
    char choice;
    do {
        int copiesAvailable;
        string bookTitle, bookAuthor, bookId, input;

        modifyMenu();

        ifstream fin("ComputerScienceRecord.txt");
        ofstream fout("TempFile.txt");
		
		cout << endl;
        cout << "Enter the Book Id: ";
        cin >> input;

        if (fin.is_open() && fout.is_open()) 
		{
            bool found = false;

            while (fin >> bookId >> ws) 
			{
                getline(fin, bookTitle);
                getline(fin, bookAuthor);
                fin >> copiesAvailable;

                if (bookId == input) 
				{
                    int option;
                    cout << endl;
                    cout << "Enter your choice: ";
                    cin >> option;

                    if (option == 1) 
					{
						cout << endl;
                        cout << " _ _ _ _ MODIFYING THE BOOK DETAILS _ _ _ _ " << endl;
                        cout << endl;
                        cout << "Enter the Book name to be Modified: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        cout << "Enter the name of the Author to be Modified: ";
                        getline(cin, bookAuthor);
                        cout << "Enter the number of Copies: ";
                        cin >> copiesAvailable;
                        cin.ignore();                       
                        found = true;
                    } 
					else if (option == 2) 
					{
						cout << endl;
                        cout << " _ _ _ _ ADDING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int new_copies;
                        cout << "Enter the number of copies you want to add: ";
                        cin >> new_copies;
                        copiesAvailable += new_copies;
                        found = true;
                    } 
					else if (option == 3) 
					{
						cout << endl;
                        cout << " _ _ _ _ REMOVING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int remove_copies;
                        cout << "Enter the numbers of copies you want to remove: ";
                        cin >> remove_copies;
                        copiesAvailable -= remove_copies;
                        found = true;
                    } 
					else if (option == 0) 
					{
                        cout << "Exit" << endl;
                        system("cls");
                        modify_record();
                        found = true;
                    }
                }

                fout << bookId << endl << bookTitle << endl << bookAuthor << endl << copiesAvailable << endl;
            }

            fin.close();
            fout.close();

            remove("ComputerScienceRecord.txt");
            rename("TempFile.txt", "ComputerScienceRecord.txt");

            if (found) 
			{
                cout << "Record updated successfully." << endl;
            } 
			else 
			{
                cout << "Book ID not found." << endl;
            }
        } 
		else 
		{
            cout << "Error opening the file." << endl;
        }

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void Modify_Mathematics()
{
	char choice;
    do {
        int copiesAvailable;
        string bookTitle, bookAuthor, bookId, input;

        modifyMenu();

        ifstream fin("MathematicsRecord.txt");
        ofstream fout("TempFile.txt");
		
		cout << endl;
        cout << "Enter the Book Id: ";
        cin >> input;

        if (fin.is_open() && fout.is_open()) 
		{
            bool found = false;

            while (fin >> bookId >> ws) 
			{
                getline(fin, bookTitle);
                getline(fin, bookAuthor);
                fin >> copiesAvailable;

                if (bookId == input) 
				{
                    int option;
                    cout << endl;
                    cout << "Enter your choice: ";
                    cin >> option;

                    if (option == 1) 
					{
						cout << endl;
                        cout << " _ _ _ _ MODIFYING THE BOOK DETAILS _ _ _ _ " << endl;
                        cout << endl;
                        cout << "Enter the Book name to be Modified: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        cout << "Enter the name of the Author to be Modified: ";
                        getline(cin, bookAuthor);
                        cout << "Enter the number of Copies: ";
                        cin >> copiesAvailable;
                        cin.ignore();                       
                        found = true;
                    } 
					else if (option == 2) 
					{
						cout << endl;
                        cout << " _ _ _ _ ADDING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int new_copies;
                        cout << "Enter the number of copies you want to add: ";
                        cin >> new_copies;
                        copiesAvailable += new_copies;
                        found = true;
                    } 
					else if (option == 3) 
					{
						cout << endl;
                        cout << " _ _ _ _ REMOVING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int remove_copies;
                        cout << "Enter the numbers of copies you want to remove: ";
                        cin >> remove_copies;
                        copiesAvailable -= remove_copies;
                        found = true;
                    } 
					else if (option == 0) 
					{
                        cout << "Exit" << endl;
                        system("cls");
                        modify_record();
                        found = true;
                    }
                }

                fout << bookId << endl << bookTitle << endl << bookAuthor << endl << copiesAvailable << endl;
            }

            fin.close();
            fout.close();

            remove("MathematicsRecord.txt");
            rename("TempFile.txt", "MathematicsRecord.txt"); 

            if (found) 
			{
                cout << "Record updated successfully." << endl;
            } 
			else 
			{
                cout << "Book ID not found." << endl;
            }
        } 
		else 
		{
            cout << "Error opening the file." << endl;
        }

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void Modify_Islamiat()
{
	char choice;
    do {
        int copiesAvailable;
        string bookTitle, bookAuthor, bookId, input;

        modifyMenu();

        ifstream fin("IslamicRecord.txt");
        ofstream fout("TempFile.txt");
		
		cout << endl;
        cout << "Enter the Book Id: ";
        cin >> input;

        if (fin.is_open() && fout.is_open()) 
		{
            bool found = false;

            while (fin >> bookId >> ws) 
			{
                getline(fin, bookTitle);
                getline(fin, bookAuthor);
                fin >> copiesAvailable;

                if (bookId == input) 
				{
                    int option;
                    cout << endl;
                    cout << "Enter your choice: ";
                    cin >> option;

                    if (option == 1) 
					{
						cout << endl;
                        cout << " _ _ _ _ MODIFYING THE BOOK DETAILS _ _ _ _ " << endl;
                        cout << endl;
                        cout << "Enter the Book name to be Modified: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        cout << "Enter the name of the Author to be Modified: ";
                        getline(cin, bookAuthor);
                        cout << "Enter the number of Copies: ";
                        cin >> copiesAvailable;
                        cin.ignore();                       
                        found = true;
                    } 
					else if (option == 2) 
					{
						cout << endl;
                        cout << " _ _ _ _ ADDING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int new_copies;
                        cout << "Enter the number of copies you want to add: ";
                        cin >> new_copies;
                        copiesAvailable += new_copies;
                        found = true;
                    } 
					else if (option == 3) 
					{
						cout << endl;
                        cout << " _ _ _ _ REMOVING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int remove_copies;
                        cout << "Enter the numbers of copies you want to remove: ";
                        cin >> remove_copies;
                        copiesAvailable -= remove_copies;
                        found = true;
                    } 
					else if (option == 0) 
					{
                        cout << "Exit" << endl;
                        system("cls");
                        modify_record();
                        found = true;
                    }
                }

                fout << bookId << endl << bookTitle << endl << bookAuthor << endl << copiesAvailable << endl;
            }

            fin.close();
            fout.close();

            remove("IslamicRecord.txt");
            rename("TempFile.txt", "IslamicRecord.txt"); 

            if (found) 
			{
                cout << "Record updated successfully." << endl;
            } 
			else 
			{
                cout << "Book ID not found." << endl;
            }
        } 
		else 
		{
            cout << "Error opening the file." << endl;
        }

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void Modify_History()
{
	char choice;
    do {
        int copiesAvailable;
        string bookTitle, bookAuthor, bookId, input;

        modifyMenu();

        ifstream fin("HistoryRecord.txt");
        ofstream fout("TempFile.txt");
		
		cout << endl;
        cout << "Enter the Book Id: ";
        cin >> input;

        if (fin.is_open() && fout.is_open()) 
		{
            bool found = false;

            while (fin >> bookId >> ws) 
			{
                getline(fin, bookTitle);
                getline(fin, bookAuthor);
                fin >> copiesAvailable;

                if (bookId == input) 
				{
                    int option;
                    cout << endl;
                    cout << "Enter your choice: ";
                    cin >> option;

                    if (option == 1) 
					{
						cout << endl;
                        cout << " _ _ _ _ MODIFYING THE BOOK DETAILS _ _ _ _ " << endl;
                        cout << endl;
                        cout << "Enter the Book name to be Modified: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        cout << "Enter the name of the Author to be Modified: ";
                        getline(cin, bookAuthor);
                        cout << "Enter the number of Copies: ";
                        cin >> copiesAvailable;
                        cin.ignore();                       
                        found = true;
                    } 
					else if (option == 2) 
					{
						cout << endl;
                        cout << " _ _ _ _ ADDING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int new_copies;
                        cout << "Enter the number of copies you want to add: ";
                        cin >> new_copies;
                        copiesAvailable += new_copies;
                        found = true;
                    } 
					else if (option == 3) 
					{
						cout << endl;
                        cout << " _ _ _ _ REMOVING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int remove_copies;
                        cout << "Enter the numbers of copies you want to remove: ";
                        cin >> remove_copies;
                        copiesAvailable -= remove_copies;
                        found = true;
                    } 
					else if (option == 0) 
					{
                        cout << "Exit" << endl;
                        system("cls");
                        modify_record();
                        found = true;
                    }
                }

                fout << bookId << endl << bookTitle << endl << bookAuthor << endl << copiesAvailable << endl;
            }

            fin.close();
            fout.close();

            remove("HistoryRecord.txt");
            rename("TempFile.txt", "HistoryRecord.txt"); 

            if (found) 
			{
                cout << "Record updated successfully." << endl;
            } 
			else 
			{
                cout << "Book ID not found." << endl;
            }
        } 
		else 
		{
            cout << "Error opening the file." << endl;
        }

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void Modify_English()
{
	char choice;
    do {
        int copiesAvailable;
        string bookTitle, bookAuthor, bookId, input;

        modifyMenu();

        ifstream fin("EnglishRecord.txt");
        ofstream fout("TempFile.txt");
		
		cout << endl;
        cout << "Enter the Book Id: ";
        cin >> input;

        if (fin.is_open() && fout.is_open()) 
		{
            bool found = false;

            while (fin >> bookId >> ws) 
			{
                getline(fin, bookTitle);
                getline(fin, bookAuthor);
                fin >> copiesAvailable;

                if (bookId == input) 
				{
                    int option;
                    cout << endl;
                    cout << "Enter your choice: ";
                    cin >> option;

                    if (option == 1) 
					{
						cout << endl;
                        cout << " _ _ _ _ MODIFYING THE BOOK DETAILS _ _ _ _ " << endl;
                        cout << endl;
                        cout << "Enter the Book name to be Modified: ";
                        cin.ignore();
                        getline(cin, bookTitle);
                        cout << "Enter the name of the Author to be Modified: ";
                        getline(cin, bookAuthor);
                        cout << "Enter the number of Copies: ";
                        cin >> copiesAvailable;
                        cin.ignore();                       
                        found = true;
                    } 
					else if (option == 2) 
					{
						cout << endl;
                        cout << " _ _ _ _ ADDING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int new_copies;
                        cout << "Enter the number of copies you want to add: ";
                        cin >> new_copies;
                        copiesAvailable += new_copies;
                        found = true;
                    } 
					else if (option == 3) 
					{
						cout << endl;
                        cout << " _ _ _ _ REMOVING THE NUMBERS OF COPIES _ _ _ _ " << endl;
                        cout << endl;
                        int remove_copies;
                        cout << "Enter the numbers of copies you want to remove: ";
                        cin >> remove_copies;
                        copiesAvailable -= remove_copies;
                        found = true;
                    } 
					else if (option == 0) 
					{
                        cout << "Exit" << endl;
                        system("cls");
                        modify_record();
                        found = true;
                    }
                }

                fout << bookId << endl << bookTitle << endl << bookAuthor << endl << copiesAvailable << endl;
            }

            fin.close();
            fout.close();

            remove("EnglishRecord.txt");
            rename("TempFile.txt", "EnglishRecord.txt"); 

            if (found) 
			{
                cout << "Record updated successfully." << endl;
            } 
			else 
			{
                cout << "Book ID not found." << endl;
            }
        } 
		else 
		{
            cout << "Error opening the file." << endl;
        }

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void modify_record()                    // Menu fuction for the Categories you want to modify.
{
    cout << "     Categories   " << endl;
    cout << "--------------------" << endl;
    cout << "1. Computer Science" << endl;
    cout << "2. English" << endl;
    cout << "3. History" << endl;
    cout << "4. Islamiat" << endl;
    cout << "5. Mathematics" << endl;
    cout << "6. Exit" << endl << endl;	
    
    int category;                        // Choose the category you want to modify. Throught interger number.
    cout << "Enter the category you want to modify: ";
    cin >> category;
    cout << endl;
    
    switch(category)                    // In this switch case is used to call modification functions to perform their specific function.
    {
    	case 1:
    		Modify_ComputerScience();
    		break;
    	case 2:
			Modify_English();
			break;
		case 3:
			Modify_History();
			break;
		case 4:
			Modify_Islamiat();
			break;
		case 5:
			Modify_Mathematics();
			break;
		case 6:
			system("cls");
			Admin_panel();
			break;
		default:
			cout << "Invalid Choice!" << endl ;
			break;
	}
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------DELETE A RECORD--------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void delete_book(){ // function for book delete

	int select;
	string choice;
	
	system ("cls");	
	cout<<"\t\t\t\t\t---------------------------\t\t\t"<<endl;
	cout<<"\t\t\t\t\t BOOK REMOVAL \t\t\t"<<endl;
	cout<<"\t\t\t\t\t---------------------------\t\t\t"<<endl;
	cout<<"Select the category of the books from which"<<endl;
	cout<<"you want to remove the book"<<endl;
	cout<<"1. English"<<endl;
	cout<<"2. History"<<endl;
	cout<<"3. Mathematics"<<endl;
	cout<<"4. Computer Science"<<endl;
	cout<<"5. Islamic"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"Press the number related to your category"<<endl;
	cin>>select; // Selection of book category
	switch (select)
	{
		case 1 : // Case for delete of English book
			{
				do{
				int copiesAvailable , found1 = 0;
	            string bookId ,bookAuthor ,bookTitle ,deleteId_1;
	
	            cout<<"Enter the Id of the book you want to remove"<<endl;
	            cin>>deleteId_1; // Id of English book we want to delete
	            ifstream eng_file("EnglishRecord.txt");
	            ofstream temp_file("tempEng.txt");
	
	            while(!eng_file.eof()) // this loop will run till the end of file of English books
	            {
		            getline(eng_file>>ws,bookId);
		            getline(eng_file>>ws,bookTitle);
		            getline(eng_file>>ws,bookAuthor);
		            eng_file>>copiesAvailable;
		            eng_file.ignore();
		
		            if(deleteId_1 != bookId) // this will add all books to temporary file except the book we want to delete
		            {
			            temp_file<<" "<<bookId<<endl;
			            temp_file<<" "<<bookTitle<<endl;
			            temp_file<<" "<<bookAuthor<<endl;
			            temp_file<<" "<<copiesAvailable<<endl;
			
		            }
		            else 
		            {
			            found1++;
		            }
		
	            }
	            eng_file.close();
	            temp_file.close();
	            remove("EnglishRecord.txt");
	            rename("tempEng.txt","EnglishRecord.txt");
	
	            if (found1 == 0)
	            {
		            cout<<"Book with Id "<<deleteId_1<<" is not found"<<endl;
	            }
	            else 
	            {
		            cout<<"Book with Id "<<deleteId_1<<" successfully deleted"<<endl;
                }
                cout<<"Do you again want to remove the book (y/n)"<<endl;
				cin>>choice;
					if (choice == "n" || choice == "N")
						{
						Admin_panel();
						}
    				}while(choice == "y" || choice == "Y");   
                break;
			}
			
		case 2 : // Case for delete of History book
			{
				do{
				
				int copiesAvailable , found2 = 0;
	            string bookId ,bookAuthor ,bookTitle ,deleteId_2;
	
	            cout<<"Enter the Id of the book you want to remove"<<endl;
	            cin>>deleteId_2;// Id of History book we want to delete
	            ifstream his_file("HistoryRecord.txt");
	            ofstream temp_file2("tempHis.txt");
	
	            while(!his_file.eof())// this loop will run till the end of file of History books
	            {
		           getline(his_file>>ws,bookId);
		           getline(his_file>>ws,bookTitle);
		           getline(his_file>>ws,bookAuthor);
		           his_file>>copiesAvailable;
		           his_file.ignore();
		
		           if(deleteId_2 != bookId)// this will add all books to temporary file except the book we want to delete
		           {
			          temp_file2<<" "<<bookId<<endl;
			          temp_file2<<" "<<bookTitle<<endl;
			          temp_file2<<" "<<bookAuthor<<endl;
			          temp_file2<<" "<<copiesAvailable<<endl;
			
		           }
		           else
		           {
			          found2++;
		           }
		
	            }
	            his_file.close();
	            temp_file2.close();
	            remove("HistoryRecord.txt");
	            rename("tempHis.txt","HistoryRecord.txt");
	
	            if (found2 == 0)
	            {
		            cout<<"Book with Id "<<deleteId_2<<" is not found"<<endl;
	            }
	            else 
	            {
		            cout<<"Book with Id "<<deleteId_2<<" successfully deleted"<<endl;
                }
                cout<<"Do you again want to remove the book (y/n)"<<endl;
				cin>>choice;
					if (choice == "n" || choice == "N")
						{
						Admin_panel();
						}
    				}while(choice == "y" || choice == "Y");   
                break;
			}
			
		
		case 3 : // Case for delete of Mathematics book
			{
				do{
				
				int copiesAvailable , found3 = 0;
	            string bookId ,bookAuthor ,bookTitle ,deleteId_3;
	
	            cout<<"Enter the Id of the book you want to remove"<<endl;
	            cin>>deleteId_3;// Id of Mathematics book we want to delete
	            ifstream math_file("MathematicsRecord.txt");
            	ofstream temp_file3("tempMath.txt");
	
	        while(!math_file.eof())// this loop will run till the end of file of Mathematics books
	        {
		        getline(math_file>>ws,bookId);
	        	getline(math_file>>ws,bookTitle);
	        	getline(math_file>>ws,bookAuthor);
	    	    math_file>>copiesAvailable;
	        	math_file.ignore();
		
		        if(deleteId_3 != bookId)// this will add all books to temporary file except the book we want to delete
	    	    {
	    		    temp_file3<<" "<<bookId<<endl;
		        	temp_file3<<" "<<bookTitle<<endl;
		        	temp_file3<<" "<<bookAuthor<<endl;
			        temp_file3<<" "<<copiesAvailable<<endl;
			
		        }
		        else
	    	    {
		    	    found3++;
		        }
		
	        }
	        math_file.close();
	        temp_file3.close();
	        remove("MathematicsRecord.txt");
	        rename("tempMath.txt","MathematicsRecord.txt");
	
	        if (found3 == 0)
	        {
		        cout<<"Book with Id "<<deleteId_3<<" is not found"<<endl;
	        }
	        else 
	        {
		    cout<<"Book with Id "<<deleteId_3<<" successfully deleted"<<endl;
            }
            cout<<"Do you again want to remove the book (y/n)"<<endl;
				cin>>choice;
					if (choice == "n" || choice == "N")
						{
						Admin_panel();
						}
    				}while(choice == "y" || choice == "Y");   
            break;
			}
			
		
		case 4 : // Case for delete of Computer Science book
			{
				do{
				
				int copiesAvailable , found4 = 0;
	            string bookId ,bookAuthor ,bookTitle ,deleteId_4;
	
	            cout<<"Enter the Id of the book you want to remove"<<endl;
	            cin>>deleteId_4;// Id of Computer Science book we want to delete
	            ifstream cs_file("ComputerScienceRecord.txt");
	            ofstream temp_file4("tempCS.txt");
	
	            while(!cs_file.eof())// this loop will run till the end of file of Computer Science books
	            {
		            getline(cs_file>>ws,bookId);
	            	getline(cs_file>>ws,bookTitle);
		            getline(cs_file>>ws,bookAuthor);
		            cs_file>>copiesAvailable;
		            cs_file.ignore();
		
		            if(deleteId_4 != bookId)// this will add all books to temporary file except the book we want to delete
		            {
			            temp_file4<<" "<<bookId<<endl;
			            temp_file4<<" "<<bookTitle<<endl;
		            	temp_file4<<" "<<bookAuthor<<endl;
	             		temp_file4<<" "<<copiesAvailable<<endl;
			
		            }
		             else
		            {
           		    	found4++;
	        	    }
		
            	}
	            cs_file.close();
	            temp_file4.close();
	            remove("ComputerScienceRecord.txt");
	            rename("tempCS.txt","ComputerScienceRecord.txt");
	
             	if (found4 == 0)
	            {
		            cout<<"Book with Id "<<deleteId_4<<" is not found"<<endl;
	            }
	            else 
	            {
		            cout<<"Book with Id "<<deleteId_4<<" successfully deleted"<<endl;
                }
                cout<<"Do you again want to remove the book (y/n)"<<endl;
				cin>>choice;
					if (choice == "n" || choice == "N")
						{
						Admin_panel();
						}
    				}while(choice == "y" || choice == "Y");   
                break;
			}
			
			
		case 5 : // Case for delete of Islamic book
			{
			  do{
			  
			    int copiesAvailable , found5 = 0;
	            string bookId ,bookAuthor ,bookTitle ,deleteId_5;
	
	            cout<<"Enter the Id of the book you want to remove"<<endl;
	            cin>>deleteId_5;// Id of Islamic book we want to delete
            	ifstream islamic_file("IslamicRecord.txt");
            	ofstream temp_file5("tempIslamic.txt");
	
	            while(!islamic_file.eof())// this loop will run till the end of file of Islamic books
	            {
		            getline(islamic_file>>ws,bookId);
		            getline(islamic_file>>ws,bookTitle);
		            getline(islamic_file>>ws,bookAuthor);
		            islamic_file>>copiesAvailable;
		            islamic_file.ignore();
		
		            if(deleteId_5 != bookId)// this will add all books to temporary file except the book we want to delete
	            	{
		            	temp_file5<<" "<<bookId<<endl;
		            	temp_file5<<" "<<bookTitle<<endl;
		            	temp_file5<<" "<<bookAuthor<<endl;
	             		temp_file5<<" "<<copiesAvailable<<endl;
			
	              	}
		            else
		            {
			            found5++;
		            }
		
	            }
	            islamic_file.close();
	            temp_file5.close();
	            remove("IslamicRecord.txt");
	            rename("tempIslamic.txt","IslamicRecord.txt");
	
	            if (found5 == 0)
	            {
		            cout<<"Book with Id "<<deleteId_5<<" is not found"<<endl;
	            }
	            else 
	            {
		            cout<<"Book with Id "<<deleteId_5<<" successfully deleted"<<endl;
                }
            	cout<<"Do you again want to remove the book (y/n)"<<endl;
				cin>>choice;
					if (choice == "n" || choice == "N")
						{
						Admin_panel();
						}
    				}while(choice == "y" || choice == "Y");    
                break;
			}
			
			case 6 :// case for exit of book delete and it will reach to Admin menu
				{
				Admin_panel();
				break;
			    }
			
		default :
			{
			cout<<"error";
			break;
			}
	

}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------BORROW A BOOK----------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void borrow_book()
{
     system("cls");
    char choice;
    
    
     int copiesAvailable, userName , borrower; 
    string bookTitle, bookAuthor, bookId, enteredBookId,password ;  
    
	cout<<"     Categories   " << endl;
	cout<<"--------------------" <<endl;
    cout<<"1- Computer Science" << endl;
    cout<<"2- English" << endl;
    cout<<"3- History" << endl;
    cout<<"4- Islamiat" << endl;
    cout<<"5- Mathematics" << endl;
    cout<<"6- Exit" << endl << endl;
    
    int category;
    cout<<"Enter the category/genre of the book: ";                                    // Selecting book category
    cin>> category;
    
    
    bool found=false;                                                                  // setting bool found to 'FALSE' as a flag to indicate if the input book ID is valid or not
    bool userFound=false;                                                              // setting bool userFound to 'FALSE' as a flag to indicate if the username is valid or not
    
    switch(category)                                                                   // switch to determine cases in each category
	{
	       	case 1:                                                                    // case 1: Computer Science
        {    	
		 do {  
   			cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream CS("ComputerScienceRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!CS.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
                 
			userFile.close();                                                           // user file close
      
       		while  (CS >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(CS>> ws, bookTitle);
            	getline(CS>> ws, bookAuthor);
        		CS >> copiesAvailable;
        		CS.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
            }
        
           }
         CS.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    		system("cls");	
			if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again: "<<endl<<endl;
        		remove("temp.txt");
        		borrow_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("ComputerScienceRecord.txt");                                            // Removing the original file
            rename("temp.txt", "ComputerScienceRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
            
        cout << "Do you want to borrow another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    	 
    			break;
    
    	
    }                                                                                    //scope for case 1 (Computer Science)
    
        case 2 :                                                                         // case 2 for English
    {                                                                                    //scope start for case 2
    
    do{
	
    	 	cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream eng("EnglishRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!eng.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
            
			userFile.close();                                                           // user file close
      
       		while  (eng >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(eng>> ws, bookTitle);
            	getline(eng>> ws, bookAuthor);
        		eng >> copiesAvailable;
        		eng.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
            }
        
           }
         eng.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    	    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        	    cout<<"Enyer your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("EnglishRecord.txt");                                            // Removing the original file
            rename("temp.txt", "EnglishRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
            
            cout << "Do you want to borrow another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    	 
    			break;
	}                                                                                     //scope end for case 2 (English)
	
		case 3 :                                                                         //case 3 for History
	{                                                                                     //scope start for case 3 (History)
	do{
	
			cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream his("HistoryRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!his.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
            
			userFile.close();                                                           // user file close
      
       		while  (his >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(his>> ws, bookTitle);
            	getline(his>> ws, bookAuthor);
        		his >> copiesAvailable;
        		his.ignore();

        	if (bookId == enteredBookId && userFound)                                   // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
            }
        
           }
         his.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	 if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    	    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("HistoryRecord.txt");                                            // Removing the original file
            rename("temp.txt", "HistoryRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
    	cout << "Do you want to borrow another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N'); 
    			break;
	}                                                                                      //scope end for case 3 (History)
	
		case 4 :                                                                           // case 4 for Islamiat
	{                                                                                     // scope start for case 4
	do{
	
			cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream isl("IslamicRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!isl.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
			
			userFile.close();                                                           // user file close
      
       		while  (isl >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(isl>> ws, bookTitle);
            	getline(isl>> ws, bookAuthor);
        		isl >> copiesAvailable;
        		isl.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
                
            }
        
           }
         isl.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    	    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("IslamicRecord.txt");                                            // Removing the original file
            rename("temp.txt", "IslamicRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
    	 
    	 cout << "Do you want to borrow another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    			break;
    		
	}                                                                              // scope end for case 4 ( islamiat)
		
		case 5 :                                                                   // case 5 for Mathematics
	{                                                                             //scope start for case 5
	
	do{
	
		cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream math("MathematicsRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!math.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
            userFile.close();                                                           // user file close
                 
        	
			
      
       		while  (math >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(math>> ws, bookTitle);
            	getline(math>> ws, bookAuthor);
        		math >> copiesAvailable;
        		math.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id mathches book id in record and user is identified or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
                
            }
        
           }
         math.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	
		 
		if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
		    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("MathematicsRecord.txt");                                            // Removing the original file
            rename("temp.txt", "MathematicsRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
		cout << "Do you want to borrow another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    			break;
	}                                                                                   //scope end for case 5 (Mathematics)	
	case 6:                                                                             // case 6 for exit to main panel
		{   
		    Admin_panel();                                                              // calling main panel in case of exit
			break;
		}
	       
        default :                                                                        // default case for switch
        {
		Admin_panel();
		exit(0);
        break;
    	}
        
    }                                                                                   // scope for switch
     
        
}                                                                                       // scope for function end of borrow book

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------RETURN A BOOK----------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void returnBook()
{
	system("cls");
	 cout<<"     Categories   " << endl;
	cout<<"--------------------" <<endl;
    cout<<"1- Computer Science" << endl;
    cout<<"2- English" << endl;
    cout<<"3- History" << endl;
    cout<<"4- Islamiat" << endl;
    cout<<"5- Mathematics" << endl;
    cout<<"6- Exit" << endl << endl;
    
    int category;
    cout << "Enter the category/genre of the book: ";
    cin >> category;
    
	string enteredBookId,bookTitle ,returnedBookId,bookId,borrower,name, line;
    bool found = false;
    char choice;
    
    switch(category)
    {
	case 1 :
		{
			do{
			
			system("cls");
		
    cout << "Enter the ID of the book you want to return: ";
    cin >> enteredBookId;

    cout << "Enter your name: ";
    cin >> name;

    ifstream borrowedBooks("BorrowedBooks.txt");
    ofstream temp("temp.txt", ios::out);

    if (!borrowedBooks.is_open() || !temp.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(borrowedBooks>>ws, bookId)) {
        
        getline(borrowedBooks>>ws, bookTitle); 
        getline(borrowedBooks>>ws,borrower); 

        if (bookId == enteredBookId && borrower == name) {
            found = true;
            cout << "Book Found!" << endl;

           
            ifstream categoryFile("ComputerScienceRecord.txt");
            ofstream categoryTemp("tempCategory.txt", ios::out);

            if (!categoryFile.is_open() || !categoryTemp.is_open()) {
                cout << "Error opening category file!" << endl;
                return;
            }

            string bookId, bookTitle, bookAuthor;
            int copiesAvailable;

            while (categoryFile >> bookId >> ws) {
                getline(categoryFile >> ws, bookTitle);
                getline(categoryFile >> ws, bookAuthor);
                categoryFile >> copiesAvailable;
                categoryFile.ignore();

                if (bookId == enteredBookId) {
                    copiesAvailable += 1;
	 				cout<<"BOOK DETAILS:"<<endl;                                            
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                } else {
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                }
            }

            categoryFile.close();
            categoryTemp.close();

            remove("ComputerScienceRecord.txt");
            rename("tempCategory.txt", "ComputerScienceRecord.txt");

            cout << "Book Returned Successfully!" << endl;
        } else {
            temp<<bookId<<endl;
            temp<<bookTitle<<endl;
            temp<<borrower<<endl;
            temp<<endl;
        }
    }

    borrowedBooks.close();
    temp.close();

    if (!found) {
        cout << "Book or Borrower not found or match!" << endl;
        remove("temp.txt");
    } else {
        remove("BorrowedBooks.txt");
        rename("temp.txt", "BorrowedBooks.txt");
    }
    system("pause");
    cout << "Do you want to return another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    break;
       }
       case 2 :
		{
			do{
			
			system("cls");
		
    cout << "Enter the ID of the book you want to return: ";
    cin >> enteredBookId;

    cout << "Enter your name: ";
    cin >> name;

    ifstream borrowedBooks("BorrowedBooks.txt");
    ofstream temp("temp.txt", ios::out);

    if (!borrowedBooks.is_open() || !temp.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(borrowedBooks>>ws, bookId)) {
        
        getline(borrowedBooks>>ws, bookTitle); 
        getline(borrowedBooks>>ws,borrower); 

        if (bookId == enteredBookId && borrower == name) {
            found = true;
            cout << "Book Found!" << endl;

            ifstream categoryFile("EnglishRecord.txt");
            ofstream categoryTemp("tempCategory.txt", ios::out);

            if (!categoryFile.is_open() || !categoryTemp.is_open()) {
                cout << "Error opening category file!" << endl;
                return;
            }

            string bookId, bookTitle, bookAuthor;
            int copiesAvailable;

            while (categoryFile >> bookId >> ws) {
                getline(categoryFile >> ws, bookTitle);
                getline(categoryFile >> ws, bookAuthor);
                categoryFile >> copiesAvailable;
                categoryFile.ignore();

                if (bookId == enteredBookId) {
                    copiesAvailable += 1; 
                    cout<<"BOOK DETAILS:"<<endl;                                            
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                } else {
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                }
            }

            categoryFile.close();
            categoryTemp.close();

            remove("EnglishRecord.txt");
            rename("tempCategory.txt", "EnglishRecordtxt");

            cout << "Book Returned Successfully!" << endl;
        } else {
            temp<<bookId<<endl;
            temp<<bookTitle<<endl;
            temp<<borrower<<endl;
            temp<<endl;
        }
    }

    borrowedBooks.close();
    temp.close();

    if (!found) {
        cout << "Book or Borrower not found or match!" << endl;
        remove("temp.txt");
    } else {
        remove("BorrowedBooks.txt");
        rename("temp.txt", "BorrowedBooks.txt");
    }
    system("pause");
    	cout << "Do you want to return another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    break;
       }
       case 3 :
		{
			do{
			
			system("cls");
		
    cout << "Enter the ID of the book you want to return: ";
    cin >> enteredBookId;

    cout << "Enter your name: ";
    cin >> name;

    ifstream borrowedBooks("BorrowedBooks.txt");
    ofstream temp("temp.txt", ios::out);

    if (!borrowedBooks.is_open() || !temp.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(borrowedBooks>>ws, bookId)) {
        
        getline(borrowedBooks>>ws, bookTitle); 
        getline(borrowedBooks>>ws,borrower); 

        if (bookId == enteredBookId && borrower == name) {
            found = true;
            cout << "Book Found!" << endl;


            ifstream categoryFile("HistoryRecord.txt");
            ofstream categoryTemp("tempCategory.txt", ios::out);

            if (!categoryFile.is_open() || !categoryTemp.is_open()) {
                cout << "Error opening category file!" << endl;
                return;
            }

            string bookId, bookTitle, bookAuthor;
            int copiesAvailable;

            while (categoryFile >> bookId >> ws) {
                getline(categoryFile >> ws, bookTitle);
                getline(categoryFile >> ws, bookAuthor);
                categoryFile >> copiesAvailable;
                categoryFile.ignore();

                if (bookId == enteredBookId) {
                    copiesAvailable += 1;
                    cout<<"BOOK DETAILS:"<<endl;                                            
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                } else {
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                }
            }

            categoryFile.close();
            categoryTemp.close();

            remove("HistoryRecord.txt");
            rename("tempCategory.txt", "HistoryRecord.txt");

            cout << "Book Returned Successfully!" << endl;
        } else {
            temp<<bookId<<endl;
            temp<<bookTitle<<endl;
            temp<<borrower<<endl;
            temp<<endl;
        }
    }

    borrowedBooks.close();
    temp.close();

    if (!found) {
        cout << "Book or Borrower not found or match!" << endl;
        remove("temp.txt");
    } else {
        remove("BorrowedBooks.txt");
        rename("temp.txt", "BorrowedBooks.txt");
    }
    system("pause");
    cout << "Do you want to return another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    break;
       }
       case 4 :
		{
			do{
			
			system("cls");
		
    cout << "Enter the ID of the book you want to return: ";
    cin >> enteredBookId;

    cout << "Enter your name: ";
    cin >> name;

    ifstream borrowedBooks("BorrowedBooks.txt");
    ofstream temp("temp.txt", ios::out);

    if (!borrowedBooks.is_open() || !temp.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(borrowedBooks>>ws, bookId)) {
        
        getline(borrowedBooks>>ws, bookTitle); 
        getline(borrowedBooks>>ws,borrower);

        if (bookId == enteredBookId && borrower == name) {
            found = true;
            cout << "Book Found!" << endl;

            
            ifstream categoryFile("IslamicRecordtxt");
            ofstream categoryTemp("tempCategory.txt", ios::out);

            if (!categoryFile.is_open() || !categoryTemp.is_open()) {
                cout << "Error opening category file!" << endl;
                return;
            }

            string bookId, bookTitle, bookAuthor;
            int copiesAvailable;

            while (categoryFile >> bookId >> ws) {
                getline(categoryFile >> ws, bookTitle);
                getline(categoryFile >> ws, bookAuthor);
                categoryFile >> copiesAvailable;
                categoryFile.ignore();

                if (bookId == enteredBookId) {
                    copiesAvailable += 1; 
                    cout<<"BOOK DETAILS:"<<endl;                                            
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                } else {
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                }
            }

            categoryFile.close();
            categoryTemp.close();

            remove("IslamicRecord.txt");
            rename("tempCategory.txt", "IslamicRecord.txt");

            cout << "Book Returned Successfully!" << endl;
        } else {
            temp<<bookId<<endl;
            temp<<bookTitle<<endl;
            temp<<borrower<<endl;
            temp<<endl;
        }
    }

    borrowedBooks.close();
    temp.close();

    if (!found) {
        cout << "Book or Borrower not found or match!" << endl;
        remove("temp.txt");
    } else {
        remove("BorrowedBooks.txt");
        rename("temp.txt", "BorrowedBooks.txt");
    }
    system("pause");
    cout << "Do you want to return another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    break;
       }
       case 5 :
		{
			do{
			
			system("cls");
		
    cout << "Enter the ID of the book you want to return: ";
    cin >> enteredBookId;

    cout << "Enter your name: ";
    cin >> name;

    ifstream borrowedBooks("BorrowedBooks.txt");
    ofstream temp("temp.txt", ios::out);

    if (!borrowedBooks.is_open() || !temp.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(borrowedBooks>>ws, bookId)) {
        
        getline(borrowedBooks>>ws, bookTitle); 
        getline(borrowedBooks>>ws,borrower); 

        if (bookId == enteredBookId && borrower == name) {
            found = true;
            cout << "Book Found!" << endl;

            
            ifstream categoryFile("MathematicsRecord.txt");
            ofstream categoryTemp("tempCategory.txt", ios::out);

            if (!categoryFile.is_open() || !categoryTemp.is_open()) {
                cout << "Error opening category file!" << endl;
                return;
            }

            string bookId, bookTitle, bookAuthor;
            int copiesAvailable;

            while (categoryFile >> bookId >> ws) {
                getline(categoryFile >> ws, bookTitle);
                getline(categoryFile >> ws, bookAuthor);
                categoryFile >> copiesAvailable;
                categoryFile.ignore();

                if (bookId == enteredBookId) {
                    copiesAvailable += 1; 
                    cout<<"BOOK DETAILS:"<<endl;                                            
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                } else {
                    categoryTemp << bookId << endl;
                    categoryTemp << bookTitle << endl;
                    categoryTemp << bookAuthor << endl;
                    categoryTemp << copiesAvailable << endl;
                    categoryTemp << endl;
                }
            }

            categoryFile.close();
            categoryTemp.close();

            remove("MathematicsRecord.txt");
            rename("tempCategory.txt", "MathematicsRecord.txt");

            cout << "Book Returned Successfully!" << endl;
        } else {
            temp<<bookId<<endl;
            temp<<bookTitle<<endl;
            temp<<borrower<<endl;
            temp<<endl;
        }
    }

    borrowedBooks.close();
    temp.close();

    if (!found) {
        cout << "Book or Borrower not found or match!" << endl;
        remove("temp.txt");
    } else {
        remove("BorrowedBooks.txt");
        rename("temp.txt", "BorrowedBooks.txt");
    }
    system("pause");
    cout << "Do you want to return another book? (Y/N): ";
        cin >> choice;
        

        if (choice == 'Y' || choice == 'y') {
            system("cls");
            borrow_book();
        }
        if (choice == 'N' || choice == 'n') {
            system("cls");
            Admin_panel();
        }
        
    } while (choice != 'N');
    break;
    
       }
       
       default:
       {
			system("cls");
       	cout << "INVALID";
       	system("pause");
            break;   }
    
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------SEARCH A SPECIFIC BOOK(USER PANEL)-------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void search_user_book() {

  int copiesAvailable;
  string bookTitle, bookAuthor, bookId, enteredBookId;
  int category;
  char choice;



    cout << "     Categories   " << endl;
    cout << "--------------------" << endl;
    cout << "1- Computer Science" << endl;
    cout << "2- English" << endl;
    cout << "3- History" << endl;
    cout << "4- Islamiat" << endl;
    cout << "5- Mathematics" << endl;
    cout << "6- Exit" << endl << endl;

    cout << "Enter the category/genre of the book: ";
    cin >> category;

    switch (category) {

    case 1: // for computer science

    { //scope for case 1 (cs books)
     
     	do{
		 

      ifstream CS("ComputerScienceRecord.txt");

      if (!CS.is_open()) { //.is_open() is member function of iftsream (used to check if file is opened or not --> returns true if opens or false if doesnt
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (CS >> bookId) //reads string from the file  (which is bookId) (we have given string datatype to bookId)
      {
        CS.ignore(); //used to skip over a newline character after reading the book ID.
        getline(CS, bookTitle); //this line reads a line of text from the input stream  and stores it in the bookTitle variable.
        getline(CS, bookAuthor); //this reads the book author from the file and stores it in the bookAuthor variable.
        CS >> copiesAvailable; //This line reads an integer ( from the input stream amd shows the number of copies available.
        CS.ignore();

        if (bookId == enteredBookId) //this is executed if the bookiD  from the file  is equal to the entered book ID 
        {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;


          break; // used to exit the loop early as the book is found and no need is there to continue searching

        }
      }
      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      CS.close();
      
       cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    		system("cls");

  		}			 // scope for do 

  		while (choice == 'y' || choice == 'Y');

  		if (choice == 'n' || choice == 'N') {
    	cout << "Returning to main menu......";
    	Sleep(2000);
    	User_panel();
			}

      break;

    } //scope for case 1 (cs books)

    case 2: // for English

    { //scope for case 2 (english books)
    
    do{

      ifstream english("EnglishRecord.txt");

      if (!english.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (english >> bookId) {
        english.ignore();
        getline(english, bookTitle);
        getline(english, bookAuthor);
        english >> copiesAvailable;
        english.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

         
          break;

        }
      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      english.close();
      
  		cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    		system("cls");

  		}			 // scope for do 

  		while (choice == 'y' || choice == 'Y');

  		if (choice == 'n' || choice == 'N') {
    	cout << "Returning to main menu......";
    	Sleep(2000);
    	User_panel();
			}
      break;
    } //scope for case 2 (english books)

    case 3: // for History

    { //scope for case 3 (history books)
    do{
	
      ifstream history("HistoryRecord.txt");

      if (!history.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (history >> bookId) {
        history.ignore();
        getline(history, bookTitle);
        getline(history, bookAuthor);
        history >> copiesAvailable;
        history.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

         
          break;

        }

      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      history.close();
      cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    		system("cls");

  		}			 // scope for do 

  		while (choice == 'y' || choice == 'Y');

  		if (choice == 'n' || choice == 'N') {
    	cout << "Returning to main menu......";
    	Sleep(2000);
    	User_panel();
			}
      break;
    } //scope for case 3 (history books)

    case 4: // for Islamiat

    { //scope for case 4 (islamiat books)
    do{
	

      ifstream isl("IslamicRecord.txt");

      if (!isl.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (isl >> bookId) {
        isl.ignore();
        getline(isl, bookTitle);
        getline(isl, bookAuthor);
        isl >> copiesAvailable;
        isl.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

          break;

        }

      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      isl.close();
      
  		cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    		system("cls");

  		}			 // scope for do 

  		while (choice == 'y' || choice == 'Y');

  		if (choice == 'n' || choice == 'N') {
    	cout << "Returning to main menu......";
    	Sleep(2000);
    	User_panel();
			}
      break;
    } //scope for case 4 (islamiat books)

    case 5: // for Mathematics

    { //scope for case 5 (maths books)
    
	do{
	
      ifstream maths("MathematicsRecord.txt");

      if (!maths.is_open()) {
        cout << "Error opening file!" << endl;
        return;
      }

      cout << "Enter book id: ";
      cin >> enteredBookId;

      while (maths >> bookId) {
        maths.ignore();
        getline(maths, bookTitle);
        getline(maths, bookAuthor);
        maths >> copiesAvailable;
        maths.ignore();

        if (bookId == enteredBookId) {

          cout << "-------------------------------------------------------------------------" << endl;
          cout << "BookId        |" << bookId << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Title         |" << bookTitle << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "Author        |" << bookAuthor << endl;
          cout << "-------------------------------------------------------------------------" << endl;
          cout << "No. of copies |" << copiesAvailable << endl;
          cout << "-------------------------------------------------------------------------" << endl;

          break;

        }

      }

      if (bookId != enteredBookId) {
        cout << "Book with ID " << enteredBookId << " not found." << endl;
      }

      maths.close();
      cout << "Do you want to search for another book? (y/n): ";
    	cin >> choice;
    		system("cls");

  		}			 // scope for do 

  		while (choice == 'y' || choice == 'Y');

  		if (choice == 'n' || choice == 'N') {
    	cout << "Returning to main menu......";
    	Sleep(2000);
    	User_panel();
			}
      break;
    } //scope for case 5 (maths books)

    case 6: // for exit

    { // //scope for case 6 (exit)

      cout << "exiting the function......";
      Sleep(2000);

      User_panel();

      break;

    }

    default:

    { //scope for default

      cout << "Enter a valid option from the menu." << endl;

      break;

    } //scope for default

    } //scope for switch 

   
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------BORROW A BOOK(user panel)----------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void borrow_user_book()
{
    system("cls");
 
   
    
     int copiesAvailable, userName , borrower; 
    string bookTitle, bookAuthor, bookId, enteredBookId,password ;  
    
	cout<<"     Categories   " << endl;
	cout<<"--------------------" <<endl;
    cout<<"1- Computer Science" << endl;
    cout<<"2- English" << endl;
    cout<<"3- History" << endl;
    cout<<"4- Islamiat" << endl;
    cout<<"5- Mathematics" << endl;
    cout<<"6- Exit" << endl << endl;
    
    int category;
    cout<<"Enter the category/genre of the book: ";                                    // Selecting book category
    cin>> category;
    
    
    bool found=false;                                                                  // setting bool found to 'FALSE' as a flag to indicate if the input book ID is valid or not
    bool userFound=false;                                                              // setting bool userFound to 'FALSE' as a flag to indicate if the username is valid or not
    
    switch(category)                                                                   // switch to determine cases in each category
	{
	       	case 1:                                                                    // case 1: Computer Science
        {    	  
   			cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream CS("ComputerScienceRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!CS.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
                 
			userFile.close();                                                           // user file close
      
       		while  (CS >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(CS>> ws, bookTitle);
            	getline(CS>> ws, bookAuthor);
        		CS >> copiesAvailable;
        		CS.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
            }
        
           }
         CS.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    		system("cls");	
			if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again: "<<endl<<endl;
        		remove("temp.txt");
        		borrow_user_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("ComputerScienceRecord.txt");                                            // Removing the original file
            rename("temp.txt", "ComputerScienceRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
             cout << "exiting the function......";
      		Sleep(2000);

      		User_panel();
    	 
    			break;
    
    }                                                                                    //scope for case 1 (Computer Science)
    
        case 2 :                                                                         // case 2 for English
    {                                                                                    //scope start for case 2
    	 	cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream eng("EnglishRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!eng.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
            
			userFile.close();                                                           // user file close
      
       		while  (eng >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(eng>> ws, bookTitle);
            	getline(eng>> ws, bookAuthor);
        		eng >> copiesAvailable;
        		eng.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
            }
        
           }
         eng.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    	    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        	    cout<<"Enyer your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_user_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("EnglishRecord.txt");                                            // Removing the original file
            rename("temp.txt", "EnglishRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
             cout << "exiting the function......";
      		Sleep(2000);

      		User_panel();
    	 
    			break;
	}                                                                                     //scope end for case 2 (English)
	
		case 3 :                                                                         //case 3 for History
	{                                                                                     //scope start for case 3 (History)
			cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream his("HistoryRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!his.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
            
			userFile.close();                                                           // user file close
      
       		while  (his >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(his>> ws, bookTitle);
            	getline(his>> ws, bookAuthor);
        		his >> copiesAvailable;
        		his.ignore();

        	if (bookId == enteredBookId && userFound)                                   // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
            }
        
           }
         his.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	 if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    	    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_user_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("HistoryRecord.txt");                                            // Removing the original file
            rename("temp.txt", "HistoryRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
            cout << "exiting the function......";
      		Sleep(2000);

      		User_panel();
    	 
    			break;
	}                                                                                      //scope end for case 3 (History)
	
		case 4 :                                                                           // case 4 for Islamiat
	{                                                                                     // scope start for case 4
			cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream isl("IslamicRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!isl.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
			
			userFile.close();                                                           // user file close
      
       		while  (isl >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(isl>> ws, bookTitle);
            	getline(isl>> ws, bookAuthor);
        		isl >> copiesAvailable;
        		isl.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id and username is in the record or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
                
            }
        
           }
         isl.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	 
    	if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
    	    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_user_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("IslamicRecord.txt");                                            // Removing the original file
            rename("temp.txt", "IslamicRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
            cout << "exiting the function......";
      		Sleep(2000);

      		User_panel();
    	 
    			break;
    		
	}                                                                              // scope end for case 4 ( islamiat)
		
		case 5 :                                                                   // case 5 for Mathematics
	{                                                                             //scope start for case 5
		cout << "Enter the ID of the book you want to borrow: ";
    		cin >> enteredBookId;

    		cout << "Enter userName: ";
    		cin >> borrower;
				
          	ifstream math("MathematicsRecord.txt");                            // opening required files 
          	ofstream temp("temp.txt", ios::out);
          	ofstream borrowedBooks("BorrowedBooks.txt", ios::app);
          	ifstream userFile("UserRecord.txt");
          	

   			 if (!math.is_open() || !temp.is_open() || !borrowedBooks.is_open() || !userFile.is_open()) 
			{
        	cout << "Error opening file!" << endl;                                      // using condition to determine if tehre is any error in opening one or more file
        	return ;
    		}
    		
    		while (userFile >>  userName)                                               // using while loop to read usernames from userRecord for identification of user
			{ 
			getline(userFile >> ws, password);
            	if (userName == borrower)                                               // if username matches the entered username then proceed with the process
		           {
           			 userFound = true;
           			 break;
         		   }
            }
            userFile.close();                                                           // user file close
                 
        	
			
      
       		while  (math >> bookId)                                                       // reading data from the category file 
	    	{ 
       			getline(math>> ws, bookTitle);
            	getline(math>> ws, bookAuthor);
        		math >> copiesAvailable;
        		math.ignore();

        	if (bookId == enteredBookId && userFound)                                    // checking the condition if the entered book id mathches book id in record and user is identified or not
			{
            	 found=true;                                                            // if the entered id matches in the record then set found to true
            	 if(copiesAvailable>0)                                                  // checking the condition id the book has enough copies
            	{
            	system("cls");	
				cout<<endl<<endl;
            	cout<<"BOOK DETAILS:"<<endl;                                            // displaying the book details of the book
         		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "BookId        |" << bookId << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Title         |" << bookTitle << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "Author        |" << bookAuthor << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
          		cout << "No. of copies |" << copiesAvailable << endl;
          		cout << "-------------------------------------------------------------------------" << endl;
            
                copiesAvailable-=1;                                                     // removing one copy from the orignal file to keep record
                
                 		temp << bookId << endl;                                         // transferring the modified data to a temporary file
                        temp << bookTitle << endl;
                        temp << bookAuthor << endl;
                        temp << copiesAvailable << endl;
                        temp << endl;
                
           
        		borrowedBooks << bookId<<endl;                                          // transferring data to the borrowedBook file to keep record of borrowed books
				borrowedBooks << bookTitle<<endl;
        		borrowedBooks << borrower << endl;
        		
				cout<<endl<<endl;  
        	  	cout<<"STATUS:"<<endl;                                                  // showing status if the the book is borrwed
        	  	cout<<"Book Borrowed Successfully."<<endl;
                }
                else
                {   cout<<"STATUS:"<<endl;                                              // if the copies>0 condition is not met, then displaying status
                	cout<<"Book not Available..No Copies left"<<endl;
				}
            
        	}
            else
			{
		
                temp << bookId << endl;                                                 // if the enteredId matches in the record, then transfer all the data to temporary file
                temp << bookTitle << endl;
                temp << bookAuthor << endl;
                temp << copiesAvailable << endl;
                temp << endl;
                
            }
        
           }
         math.close();                                                                    // all files close
         temp.close();  
    	 borrowedBooks.close();
    	
		 
		if (!userFound || !found) {                                                     // checking condition if user enters invalid username or book id or both 
		    system("cls");
    		if (!userFound) {
            cout << "Invalid User Name...Access Denied.." << endl;                        // invalid user name is entered
       						 }
        	if (!found) {
            cout << "Invalid Book ID or Book not Available" << endl;                      // if invalid book id is entered
        				}
        		cout<<"Enter your choice again : "<<endl<<endl;
        		remove("temp.txt");
        		borrow_user_book();                                                           // if one of then or both are invalid
		}							 
		else {
      		remove("MathematicsRecord.txt");                                            // Removing the original file
            rename("temp.txt", "MathematicsRecord.txt");                                // and renaming the temporary file, containing the modified data, with orignal file name
            }
            
            cout << "exiting the function......";
      		Sleep(2000);

      		User_panel();

    			break;
	}                                                                                   //scope end for case 5 (Mathematics)	
	case 6:                                                                             // case 6 for exit to main panel
		{   
		    User_panel();                                                              // calling main panel in case of exit
			break;
		}
	       
        default :                                                                        // default case for switch
        {
	
		User_panel();
		exit(0);
        break;
    	}
        
    }                                                                                   // scope for switch
            
}                                                                                       // scope for function end of borrow book
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------DISPLAY RECORD(user oanel)---------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void display_user_Records() 
{  char choice;
 
 
	cout << "     Categories   " << endl;
    cout << "--------------------" << endl;
	cout << "1- Computer Science" << endl;
    cout << "2- English" << endl;
    cout << "3- History" << endl;
    cout << "4- Islamiat" << endl;
    cout << "5- Mathematics" << endl;
    cout << "6- All Book Data" << endl;
    cout << "7- Exit" << endl << endl;


int Number;

cout<<" Enter the your Choice: ";
cin>>Number;

switch(Number)
{
case 1:
	{
		do{
		
		displayComputerScienceRecords();
		 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        

        if (choice == 'N' || choice == 'n') {
            system("cls");
            User_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
    
		break;
}
	 
	 case 2:
	 {
	 	do{
		 
	 	displayEnglishRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        

        if (choice == 'N' || choice == 'n') {
            system("cls");
            User_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
    
		break;
}
	
	 
	 case 3:
	 {
	 	do{
		 
	 	displayHistroyRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        

        if (choice == 'N' || choice == 'n') {
            system("cls");
            User_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
    
		break;
}
	
	 
	 case 4:
	 {
	 	do{
		 
	 	displayIslamicRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        

        if (choice == 'N' || choice == 'n') {
            system("cls");
            User_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
    
		break;
}

	 
	 case 5:
	 {
	 	do{
		 
	 	displayMathematicsRecords();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        

        if (choice == 'N' || choice == 'n') {
            system("cls");
            User_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
    
		break;
}
	
	 
	 case 6:
	 {
	 	do{
		 
	 	displayAllCategories();
	 	 cout << "Do you want to see another book record? (Y/N): ";
        cin >> choice;
        

        if (choice == 'N' || choice == 'n') {
            system("cls");
            User_panel();
            break;
        }
        
    } while (choice != 'n' || choice=='y');
    
		break;
}
	 case 7:
	 {
	 	User_panel();
		break;
}

     default :
     {
     cout<<"INVALID CHOICE "<<endl;
	 break;	
}
                    }     
}

//Starting of main function.
int main()
{
	
	login_panel();
	
}
