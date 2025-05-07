#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream file;
	int  num_of_books, copiesAvailable ;
	string bookTitle , bookAuthor , bookId;
	
	cout << "For how many books want to add: ";
	cin >> num_of_books;
	
	file.open("ComputerScienceRecord.txt");
	
	for(int count=1; count<=num_of_books; count++)
	{
		 cin.ignore();
		cout << "Enter the Id of book "<< count << ": ";
			getline(cin , bookId);
		cout << "Enter the name of book "<< count << ": ";
			getline(cin , bookTitle);
			cout << "Enter the name of book author " << count << ": ";
		
			getline(cin ,bookAuthor );
		cout << "Enter the number of Copies Available "<< count << ": ";
			 cin >>copiesAvailable;
			 
		 cout<<endl<<endl;
	
		file << bookId<< endl;
		file << bookTitle << endl;	
		file << bookAuthor << endl;	
		file << copiesAvailable << endl;
		file <<endl;	 
	}
	
	file.close();
	cout<< "Data is written.";
	return 0;
}
