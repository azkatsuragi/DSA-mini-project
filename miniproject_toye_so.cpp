#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

struct Book
{
  string data;
  Book *next;
};

class linkedList
{
private:
    Book *head,*tail;
public:
  linkedList()
  {
      head = NULL;
      tail = NULL;
  }
  void addBook();
  void displayList();
  void displayList1();
  void listSize();
  void deleteList();
  void deleteLast();
};

void displayMenu();
int getChoice(int & choice1);
int endProgram(bool & start2);
void clear();

void displayMenu()
{
  cout << setw(35) << "Main Menu" << endl << endl;
  cout << "[1]  Add Book\n"
       << "[2]  Size Of List\n"
       << "[3]  Display List\n"
       << "[4]  Remove Last Book\n"
       << "[5]  Delete List\n"
       << "[6]  Quit Program\n"
       << "Enter Choice:  ";
}
int getChoice(int & choice1)
{
  cin >> choice1;   
    while (choice1 < 1 || choice1 > 6) {
      cout << endl;
      cout << "Invalid Entry!!" << endl;
      cout << "Enter Choice:  ";
      cin >> choice1; 
    }
  return choice1;
}
int endProgram(bool & start2)
{
  start2 = false;
  cout << "\n\n\t\tThank you for using this system!!\n\n";
  return start2;
}

void linkedList::addBook()
{
  Book *ptr;
  bool quit = false;
  string temp = "";
  
  cout << "Instruction:" << endl;
      cout << "1. Please press enter twice if you want to insert new book!" << endl << endl;
  while (!quit)
    {	
      cin.ignore();
       cout << "Enter the book name (enter quit to stop): ";
      getline(cin, temp);
	  	  
	  if (temp == "quit")
	  {
	    quit = true;
	    system("CLS");
	    break;
	  }
	  
	  ptr = new Book;
      ptr->data = temp;
	  ptr->next = NULL;
	  if(head == NULL)
	  {
	    head = ptr;
	    tail = ptr;
	  }
	  else
	  {
	    tail->next = ptr;
	    tail = tail->next;
	  }
	}

    
}

void linkedList::displayList()
{
  Book *ptr;
  ptr = head;
  int i = 1;
  cout <<"-------------Latest list of Books In The System-------------" <<endl<<endl;
  cout << "Current available books" << endl << endl;
  while (ptr!= NULL)
  {
  	sleep_for(5ns);
    sleep_until(system_clock::now() + 1s);
    cout << i << ". " << ptr->data << endl;
    ptr = ptr->next;
    i++;
  }
  system("pause");
  system("cls");
}

void linkedList::displayList1() {
  Book *ptr;
  ptr = head;
  int i = 1;
  cout <<"-------------Latest list of Books In The System-------------" <<endl<<endl;
  cout << "Current available books" << endl << endl;
  while (ptr != NULL) {
	sleep_for(5ns);
    sleep_until(system_clock::now() + 1s);
    cout << i << ". " << ptr->data << endl;
    ptr = ptr->next;
    i++;
  }
  system("pause");
  system("cls");
}

void linkedList::listSize()
{
  Book *ptr;
  int counter = 0;
  ptr = head;
  while (ptr)
  {
    ptr = ptr->next;
    counter++;
  }
  cout << "Number of books in the list: " << counter << endl;
  system("pause");
  system("cls");
}

void linkedList::deleteLast()
{
  if (head == NULL)
    return;

  if (head->next == NULL) 
  {
    delete head;
    head = NULL;
    return;
  }

  // Find the second last node
  Book* ptr = head;
  while (ptr->next->next != NULL)
    ptr = ptr->next;
  // Delete last node
  delete (ptr->next);
  // Change next of second last
  ptr->next = NULL;
  if(ptr == NULL)
    cout << "Last book is cleared!" << endl;
    
    cout << "Removing the last book";
    int i = 0;
    while (i<5)
    {
    	sleep_for(7ns);
    	sleep_until(system_clock::now() + 1s);
    	cout << ".";
		i++;	
	}
    
    sleep_for(10ns);
    sleep_until(system_clock::now() + 1s);
    cout << "." << endl;
	
	system("pause");
  system("cls");
}

void linkedList::deleteList()
{
  Book *ptr;
  while (head != NULL)
  {
    ptr = head->next;
    delete head;
    head = ptr;
  }
 
  if(head == NULL)
  cout <<"List is cleared!" << endl; 
}

int main() {
  int choice = 0;
  bool start = true;
  linkedList a;
  
     cout << "------------Welcome to UTM Book Management System------------" <<endl;
	 cout << "|" << setw(60) <<"|" << endl;
	 cout << "|" << setw(60) <<"|" << endl;
	 cout << "|" << setw(42) << "We Are From Group Toye So" << setw(18) << "|" << endl;
	 cout << "|" << setw(60) <<"|" << endl;
	 cout << "|" << setw(60) <<"|" << endl;
	 cout << "=============================================================" << endl;
	 system("pause");
	 system("CLS");
  
  while(start != false) 
  {
    while(choice != 6)
    {
      displayMenu();
      getChoice(choice);
      if(choice == 1)
      {
      	system("CLS");
        a.addBook();
         cout << endl;
      }
      else if(choice == 2)
      {
      	system("CLS");
        a.listSize();
         cout << endl;
      }
     else  if(choice == 3)
      {
        system("CLS");
        a.displayList();
        cout << endl;
      } 
      else if(choice == 4)
      {
        system("CLS");
        a.deleteLast();
        a.displayList1();
         cout << endl;
      }
      else if(choice == 5)
      {
        system("CLS");
        a.deleteList();
         cout << endl;
      }
      else if(choice == 6)
      {
        system("CLS");
        endProgram(start);
      }
    }
  }
}

