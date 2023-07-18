#include <iostream>
#include <conio.h>
#include <string>
#include<time.h>
#include <fstream>
#include<windows.h> 
using namespace std;

int order=0, order2=0, quantity=0, quantity2=0;
string orderName, orderName2, firstName;
double totalAvail, total, total2, totalSale, price, price2, grandTotal;

void cursorPosition(int x, int y) 
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition (output, pos);

	COORD coord;
	coord.X = x;
	coord.Y = y;
}

//ALL FUNCTIONS

void stocks();
void supplierRecords();
void welcome();
bool logIn();
void form();
int t();

void stockHome();
void medicine();
void bill();
void about();

void add();
void list();

void purchase();
void customerInfo();
void sale();
void view();
void help();

void medTray();
void check();

int main()
{
	form();
	welcome();
	medicine();
	bill();
	about();
	help();

	_getch();
	return 0;
}

bool logIn()
{
	system("cls");
		
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<"\t \t \t \t \t ============================"<<endl;
	cout<<"\t \t \t \t \t \t LOG IN FORM"<<endl;
	cout<<"\t \t \t \t \t ============================"<<endl;

	string username, password, un, pw;

		cout <<endl<<endl<<"\t \t \t \t \t   Username: ";
		cin >> username;
		cout << "\t \t \t \t \t   Password: ";
		cin >> password;

		ifstream read (username + ".txt" );
		getline(read, un);
		getline(read,pw);

		if (un== username && pw == password)
		{
			cout<<endl<<endl<<"\t \t \t \t \t _____________________________";
			cout<<endl<<endl<<"\t \t \t \t \t     You are now logged in. \n";
			cout<<"\t \t \t \t \t _____________________________";
			cout<<"\n \n \n \t \t \t \t \t";
			system("pause");
			welcome();
			return true;
		}
		else
		{
			cout<<endl<<"\t \t \t \t \t  Invalid username/password.\n";
			cout<<"\n \n \n \t \t \t \t \t";
			system ("pause");
			logIn();
			return false;
		}
}

void form ()
{
	char res=0;

	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<"\t \t \t \t \t ============================"<<endl;
	cout<<"\t \t \t \t \t \t LOG IN FORM"<<endl;
	cout<<"\t \t \t \t \t ============================"<<endl;
	cout<<" \n \t \t \t \t     Do you have an account already? Y/N: ";
	cin>>res;
		if (res=='N' || res=='n')
		{
			string username, password;
			cout<<"\n \t \t \t \t \t  Select a username: ";
			cin>>username;
			cout<<"\t \t \t \t \t  Select a password: ";
			cin>>password;

			ofstream file;
			file.open(username + ".txt");
			file<<username<<endl<<password;
			file.close();
			
			system("cls");
			logIn();
		}
		else if (res=='Y' || res=='y')
		{
			bool status= logIn();
			
			if (!status)
			{
				cout<<endl<<"\t \t \t \t \t  Invalid username/password.\n";
				cout<<"\n \n \n \t \t \t \t \t";
				system ("pause");
				logIn();
			}
			else
			{
			cout<<endl<<endl<<"\t \t \t \t \t _____________________________";
			cout<<endl<<endl<<"\t \t \t \t \t     You are now logged in. \n";
			cout<<"\t \t \t \t \t _____________________________";
			system("pause");
			}
		}
		else 
			cout<<"\t \t \t \t \t Invalid Operation. Try again.";
			Sleep(1000);
			form();
}

void welcome()
{
	char ch;
	do {
	system("cls"); 

	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(42,2);
	cout<<"A MEDICAL STORE MANAGEMENT SYSTEM";
	cursorPosition(17,3);
	cout<<"================================================================================ \n \n";
	cout<<"\t \t \t Stocks and Supplies"<<"\t  Medicines"<<"\t Bill"<<"\t    About"<<"\t Exit"<<endl;
	cursorPosition(45,11);
	cout<<"Welcome to Pharmacy Express!";
	cursorPosition(36,12);
	cout<<"We go beyond, because we care for your health.";
	cursorPosition(35,14);
	printf("NOTE: Please use the FIRST letter of each menu");
	cursorPosition(30,15);
	printf("to further navigate and to avoid TERMINATION of the program.");

	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(33,23);
	printf("|Press First Character for further Menu:| S/M/B/A/E: ");
	cin>>ch;

		switch(ch)
		{
			case 'S':
			case 's':
				stocks();
				 break;
			case 'M':
			case 'm':
				medicine();
				break;
			case 'B':
			case 'b':
				bill();
				break;
			case 'A':
			case 'a':
				about();
				break;
			case 'E':
			case 'e':
				cursorPosition(45,17);
				printf("Do you want to exit now? Y/N :");
				Sleep(100);
				ch=(_getch());
				ch=toupper(ch);
					if(ch=='Y'|| ch=='y')
					{
						system("cls");
						cursorPosition(35,20);
						printf(" Please wait.....");
						exit(0);
					}
					else (ch=='N'||ch=='n');
						welcome();
			default: 
			cursorPosition(33,24);
			printf("Please enter right character ONLY (S,M,B,A,E).");
			_getch();
		}

	} while (ch!='E');
}

int t(void) 
{
	char currentDate[30];

		time_t t = time(NULL); 
		struct tm tm = *localtime (&t);
		sprintf_s(currentDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon+1, tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
		cout<<currentDate;
		return 0;
}

void supplierRecords () 
{

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(48,2);
	cout<<"STOCKS AND SUPPLIES";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(27,5);
	cout<<"Add New Stocks";
	cursorPosition(52,5);
	cout<<"List of Stocks";
	cursorPosition(80,5);
	cout<<"Go Back";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();
	
	char name1[100], city1[100], con1[100], email1[100];
	char resp=0;
	char ch=0;

		ifstream obj(".txt");
		cin.getline(name1,100);
		obj.getline(city1,100);
		obj.getline(con1,100);
		obj.getline(email1,100);
		cursorPosition(45,8);
		cout<<"Supplier's Information List:";
		cursorPosition(15,10);
		cout<<name1;
		cout<<city1;
		cout<<con1;
		cout<<email1;
		obj.close();

		cursorPosition(51,22);
		cout<<"List updated.";
		cursorPosition(45,23);
		cout<<"Do you want to continue? Y/N: ";
		cin>>resp;
			if (resp=='y'||resp=='Y')
			{
				stockHome();
			}
			else if (resp=='n'||resp=='N')
			{
				cursorPosition(45,23);
				system("pause");
				welcome();
			}
			else 
			{
				cursorPosition(45,24);
				cout<<"Invalid operation. Try again.";
				Sleep(500);
				supplierRecords();
			}
}

void stocks()
{
	char ch=0;
	char name[100], city[100], con[100], email[100];

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(48,2);
	cout<<"STOCKS AND SUPPLIES";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(27,5);
	cout<<"Add New Stocks";
	cursorPosition(52,5);
	cout<<"List of Stocks";
	cursorPosition(80,5);
	cout<<"Go Back";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

		cursorPosition(48,8);
		cout<<"Supplier's Information:";
		cursorPosition(48,9);
		cout<<"_______________________";
	
		cursorPosition(45,11);
		cout<<"Supplier Name: ";
		cin.ignore();
		cin.getline(name,100);
		cursorPosition(45,12);
		cout<<"City: ";
		cin.getline(city,100);
		cursorPosition(45,13);
		cout<<"Contact No: ";
		cin.getline(con,100);
		cursorPosition(45,14);
		cout<<"Email: ";
		cin.getline(email,100);
		cursorPosition(47,16);
		cout<<"|   Save   |";
		cursorPosition(62,16);
		cout<<"|   Cancel  |";

		inputAgain:
		cursorPosition(39,18);
		cout<<"Press First character for the operation : S/C: ";
		cin>>ch;

		if (ch=='s' || ch=='S') 
		{
			ofstream file(".txt");
			file<<endl;
			file<<name<<"\t \t ";
			file<<city<<"\t \t ";
			file<<con<<"\t \t ";
			file<<email<<"\t \t";
			file.close();

			cursorPosition(45,20);
			cout<<"Supplier added successfully!";
			cursorPosition(43,21);
			system("pause");
			supplierRecords();
		}
		else if (ch=='c' || ch=='C') 
		{
			cursorPosition(55,20);
			cout<<"Cancelled.";
			cursorPosition(45,21);
			system ("pause");
			welcome();
		}
		else 
		{
			cursorPosition(45,20);
			cout<<"Invalid operation. Try again.";
			cursorPosition(42,21);
			system("pause");
			goto inputAgain;
		}
}

void stockHome()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(48,2);
	cout<<"STOCKS AND SUPPLIES";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(27,5);
	cout<<"Add New Stocks";
	cursorPosition(52,5);
	cout<<"List of Stocks";
	cursorPosition(80,5);
	cout<<"Go Back";
	cursorPosition(42,9);
	cout<<"Welcome to our Stocks and Supplies!";
	cursorPosition(32,11);
	cout<<"This is where suppliers can access our list of stocks.";
	cursorPosition(26,12);
	cout<<"They can update this list upon their delivery in the physical stores.";
	cursorPosition(25,13);
	cout<<"Upon entering, an information is being obtained for monitoring purposes,";
	cursorPosition(32,14);
	cout<<"but we would make sure that it would be confidential.";
	cursorPosition(26,15);
	cout<<"The suppliers can add and update the list of stocks that we have,";
	cursorPosition(26,16);
	cout<<"all they need is to strictly follow the instructions written below.";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| A/L/G: ");
	cin>>ch;

		switch(ch)
				{
					case'A':
					case'a':
						add();
					case'L':
					case'l':
						list();
						break;
					case'G':
					case'g':
						welcome();
						break;
					default:
						cursorPosition(45,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						stockHome();
				}
}

void add()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(39,2);
	cout<<"STOCKS AND SUPPLIES // ADD NEW STOCKS ";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(37,5);
	cout<<"List of Stocks";
	cursorPosition(65,5);
	cout<<"Go Back";
	cursorPosition(47,8);
	cout<<"ADDING NEW STOCKS:";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();
	
	char stockId[25], name[25], quantity[25], unitCost[25], saleCost[25], mfg[25], exp[25];

	fstream stocks;
	stocks.open("stocks.txt", ios::app);
	cursorPosition(47,10);
	cout<<"Stock ID:";
	cin.ignore();
	cin.getline(stockId,25);
	cursorPosition(47,11);
	cout<<"Name of Medicine:";
	cin.getline(name,25);
	cursorPosition(47,12);
	cout<<"Quantity:";
	cin.getline(quantity,25);
	cursorPosition(47,13);
	cout<<"Unit Cost:";
	cin.getline(unitCost, 25);
	cursorPosition(47,14);
	cout<<"Sale Cost:";
	cin.getline(saleCost,25);
	cursorPosition(47,15);
	cout<<"MFG.DATE(dd-mm-yyyy):";
	cin.getline(mfg,25);
	cursorPosition(47,16);
	cout<<"EXP.DATE(dd-mm-yyyy):";
	cin.getline(exp,25);

	stocks<<"\t \t "<<"ID NO. "<<stockId<<'|'<<"NAME: "<<name<<'|'<<"QTY: "<<quantity<<'|'<<"UC:P "<<unitCost<<'|'<<"SC:P "<<saleCost<<'|'<<"MFG: "<<mfg<<'|'<<"EXP: "<<exp<<endl;
	cursorPosition(47,19);
	cout<<"Successfully Added."<<endl;

	inputAgain:
	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| L/G: ");
	cin>>ch;

		switch(ch)
				{
					case'L':
					case'l':
						list();
						break;
					case'G':
					case'g':
						stockHome();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						cursorPosition(42,24);
						system("pause");
						goto inputAgain;
				}
}

void list()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(39,2);
	cout<<"STOCKS AND SUPPLIES //LIST OF STOCKS";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(37,5);
	cout<<"Add New Stocks";
	cursorPosition(65,5);
	cout<<"Go Back";
	cursorPosition(45,7);
	cout<<"UPDATED LIST OF STOCKS: ";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(0,9);
	cout<<ifstream("stocks.txt").rdbuf();

	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| A/G: ");
	cin>>ch;

		switch(ch)
				{
					case'A':
					case'a':
						add();
						break;
					case'G':
					case'g':
						stockHome();
						break;
					default:
						cursorPosition(45,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						list();
				}
}

void medicine()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(51,2);
	cout<<"MEDICINE MENU";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(20,5);
	cout<<"View Available";
	cursorPosition(56,5);
	cout<<"Help Tips";
	cursorPosition(87,5);
	cout<<"Go Back";
	cursorPosition(17,25);
	cout<<"================================================================================";

	cursorPosition(43,9);
	cout<<"This is the medicine section.";
	cursorPosition(30,10);
	cout<<"We can help you advance your orders, and at the same time";
	cursorPosition(31,11);
	cout<<" show you the list of our available items in stores.";
	cursorPosition(45,13);
	cout<<"______________________________";

	cursorPosition(45,16);
	cout<<"WAIT SAFELY. KEEP YOUR DISTANCE. ";
	cursorPosition(34,17);
	cout<<"Keep your health by keeping distance from others and ";
	cursorPosition(36,18);
	cout<<"it is best to order in the safety of your homes. ";

	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| V/H/G: ");
	cin>>ch;

		switch(ch)
				{
					case'V':
					case'v':
						view();
						break;
					case'H':
					case'h':
						help();
						break;
					case'G':
					case'g':
						welcome();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						medicine();
				}
}

void view()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(41,2);
	cout<<"MEDICINE MENU // VIEW AVAILABLE";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(23,5);
	cout<<"Purchase";
	cursorPosition(42,5);
	cout<<"Sale Medicine";
	cursorPosition(67,5);
	cout<<"Help Tips";
	cursorPosition(84,5);
	cout<<"Go Back";
	cursorPosition(17,25);
	cout<<"================================================================================";

	cursorPosition(44,7);
	cout<<"List of Available Items:\n"; // This available items can only be read by the customers and updated by the programmer.
	cursorPosition(32,9); cout<<"Generic Name: ";
	cursorPosition(54,9); cout<<"Dosage: ";
	cursorPosition(71,9); cout<<"Price: ";
	cout<<endl;
	cout<<ifstream("menu.txt").rdbuf();
	
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(31,22);
	printf("|Press First Character for further Menu:| P/S/H/G: ");
	cin>>ch;

		switch(ch)
				{
					case'P':
					case'p':
						customerInfo();
						break;
					case'S':
					case's':
						sale();
						break;
					case'H':
					case'h':
						help();
						break;
					case'G':
					case'g':
						medicine();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						view();
				}
}

void customerInfo()
{
	string lastName, age, address, contact, mode, emailAdd;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(41,2);
	cout<<"MEDICINE MENU // PURCHASE MEDICINE";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(30,5);
	cout<<"Sale Medicine";
	cursorPosition(55,5);
	cout<<"Help Tips";
	cursorPosition(82,5);
	cout<<"Go Back";
	cursorPosition(41,7);
	cout<<"------------------------------------";
	cursorPosition(44,8);
	cout<<"CUSTOMER'S INFORMATION RECORD: ";
	cursorPosition(41,9);
	cout<<"------------------------------------";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(43,11);
	cout<<"First Name: ";
	cin.ignore();
	getline(cin, firstName);
	cursorPosition(43,12);
	cout<<"Last Name: ";
	getline(cin, lastName);
	cursorPosition(43,13);
	cout<<"Age: ";
	getline(cin, age);
	cursorPosition(43,14);
	cout<<"Address: ";
	getline(cin, address);
	cursorPosition(43,15);
	cout<<"Contact Number: ";
	getline(cin, contact);
	cursorPosition(43,16);
	cout<<"Email address: ";
	getline(cin, emailAdd);
	cursorPosition(43,17);
	cout<<"Mode of Payment (COD/Online Payment): \n";
	cursorPosition(43,18);
	getline(cin, mode);

	ofstream myfile;
	myfile.open (firstName + "'sInfo.txt");
	myfile <<firstName<<endl<<lastName<<endl<<age<<endl<<address<<endl<<contact<<endl<<mode<<endl<<emailAdd;
	myfile.close();

	cursorPosition(46,24);
	system("pause");
	purchase();
}

void purchase()
{

	char ch=0;
	char orderMore;
	double A1=0, A2=0, A3=0, A4=0, A5=0, A6=0, A7=0, A8=0, A9=0, A10=0, A11=0;
	double S1=0, S2=0, S3=0, S4=0, S5=0, S6=0, S7=0, S8=0, S9=0, S10=0, S11=0;
	
	startOrder:
	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(41,2);
	cout<<"MEDICINE MENU // PURCHASE MEDICINE";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(30,5);
	cout<<"Sale Medicine";
	cursorPosition(57,5);
	cout<<"Help Tips";
	cursorPosition(82,5);
	cout<<"Go Back";
	cursorPosition(17,26);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

		cursorPosition(27, 7);
		cout<<"Feel free to choose your order below from our Available Items: ";
		
			cursorPosition(0, 9);
			cout<<ifstream("menu.txt").rdbuf();

			cursorPosition(32, 21);
			cout<<"Please select the number of your order (1-11): "<<'\b';
			cin>>order;

			cursorPosition(25, 22);
			cout<<"How many would you like to order? (Please enter a positive number): "<<'\b';
			cin>>quantity;

				switch(order)
				{
					case 1: 
						orderName="Paracetamol";
						price = 4.50;
						A1 = 4.50 * quantity;
						total = A1;
						break;
					case 2:
						orderName="Metformin";
						price = 6.50;
						A2 = 6.50 * quantity;
						total = A2;
						break;
					case 3:
						orderName="Albuterol";
						price = 75.00;
						A3 = 75.00 * quantity;
						total = A3;
						break;
					case 4: 
						orderName="Antihistamines";
						price = 8.50;
						A4 = 8.50 * quantity;
						total = A4;
						break;
					case 5: 
						orderName="Vitamins";
						price = 299.50;
						A5 = 299.50 * quantity;
						total = A5;
						break;
					case 6:
						orderName="Amoxicillin";
						price = 15.00;
						A6 = 15.00 * quantity;
						total = A6;
						break;
					case 7: 
						orderName="Neozep";
						price = 5.75;
						A7 = 5.75 * quantity;
						total = A7;
						break;
					case 8: 
						orderName="Sinecod Forte";
						price = 157.50;
						A8 = 157.50 * quantity;
						total = A8;
						break;
					case 9: 
						orderName="Potencee";
						price = 7.00;
						A9 = price * quantity;
						total = A9;
						break;
					case 10: 
						orderName="Bioflu";
						price = 7.40;
						A10 = 7.40 * quantity;
						total = A10;
						break;
					case 11: 
						orderName="Mefenamic Acid";
						price = 2.50;
						A11 = 2.50 * quantity;
						total = A11;
						break;
					default:
						cursorPosition(31,23);
						cout<<"Please check your inputs. Invalid operation occured.";
						Sleep(1000);
						purchase();
					}
			
			if (quantity <= 0)
			{
				cursorPosition(31,23);
				cout<<"Please check your inputs. Invalid operation occured.";
				Sleep(1000);
				purchase();
			}

			again:
			cursorPosition(31, 23);
			cout<<"Would you like to order anything else here? Y / N: ";
			cin>>orderMore;

			totalAvail = A1 + A2 + A3 + A4 + A5 + A6 + A7 + A8 + A9 + A10 + A11;

			ofstream orderFile;
			orderFile.open(firstName + " available.txt", ios::app);
			orderFile<<"\t \t \t \t \t     "<<quantity<<"pc/s."<<orderName<<" x P"<<price<<" = P"<<total<<endl;
			orderFile.close();

				if (orderMore=='Y' || orderMore=='y')
					goto startOrder;
				else if (orderMore=='N' || orderMore=='n')
				{	
					cursorPosition(39, 24);
					cout<<"Your order/s are succesfully added.";
					cursorPosition(39, 25);
					system("pause");
					goto sale;
				}
				else
				{
					cursorPosition(44,24);
					cout<<"Invalid operation. Try again.";
					Sleep(600);
					goto again;
				}

			sale:
			system ("cls");
			cursorPosition(17,1);
			cout<<"================================================================================";
			cursorPosition(41,2);
			cout<<"MEDICINE MENU // PURCHASE MEDICINE";
			cursorPosition(17,3);
			cout<<"================================================================================";
			cursorPosition(30,5);
			cout<<"Sale Medicine";
			cursorPosition(57,5);
			cout<<"Help Tips";
			cursorPosition(82,5);
			cout<<"Go Back";
			cursorPosition(17,26);
			cout<<"================================================================================";
			cursorPosition(42,27);
			cout<<"Date and Time: \n";
			cursorPosition(57,27);
			t();

			cursorPosition(32, 7);
			cout<<"Now, you can order and head over to our SALE ITEMS: ";

			cursorPosition(0, 9);
			cout<<ifstream("sale.txt").rdbuf();

			cursorPosition(32, 21);
			cout<<"Please select the number of your order (1-11): "<<'\b';
			cin>>order2;

			cursorPosition(25, 22);
			cout<<"How many would you like to order? (Please enter a positive number): "<<'\b';
			cin>>quantity2;

				switch(order2)
				{
					case 1: 
						orderName2="Calcium Lactate";
						price2 = 1.00;
						S1 = 1.00 * quantity2;
						total2 = S1;
						break;
					case 2:
						orderName2="Rexidol";
						price2 = 4.50;
						S2 = 4.50 * quantity2;
						total2 = S2;
						break;
					case 3:
						orderName2="Decolgen";
						price2 = 3.50;
						S3 = 3.50 * quantity2;
						total2 = S3;
						break;
					case 4: 
						orderName2="Plemex";
						price2 = 4.50;
						S4 = 4.50 * quantity2;
						total2 = S4;
						break;						
					case 5: 
						orderName2="Kremil-S";
						price2 = 4.00;
						S5 = 4.00 * quantity2;
						total2 = S5;
						break;
					case 6:
						orderName2="Biotin";
						price2 = 5.00;
						S6 = 5.00 * quantity2;
						total2 = S6;
						break;
					case 7: 
						orderName2="Symdex";	
						price2 = 2.75;
						S7 = 2.75 * quantity2;
						total2 = S7;
						break;
					case 8: 
						orderName2="Saridon";
						price2 = 3.00;
						S8 = 3.00 * quantity2;
						total2 = S8;
						break;
					case 9: 
						orderName2="Loperamide";
						price2 = 3.75;
						S9 = 3.75 * quantity2;
						total2 = S9;
						break;
					case 10: 
						orderName2="Advil";
						price2 = 4.40;
						S10 = 4.40 * quantity2;
						total2 = S10;
						break;
					case 11: 
						orderName2="Dizitab";
						price2 = 5.50;
						S11 = 5.50 * quantity2;
						total2 = S11;
						break;	
					default:
						cursorPosition(31,23);
						cout<<"Please check your inputs. Invalid operation occured.";
						Sleep(1000);
						goto sale;
				}

				if (quantity2 <= 0)
				{
					cursorPosition(31,23);
					cout<<"Please check your inputs. Invalid operation occured.";
					Sleep(1000);
					purchase();
				}

				again2:
				cursorPosition(31, 23);
				cout<<"Would you like to order anything else here? Y / N: ";
				cin>>orderMore;

				totalSale = S1 + S2 + S3 + S4 + S5 + S6 + S7 + S8 + S9 + S10 + S11;

				ofstream orderFile2;
				orderFile2.open(firstName + " sale.txt", ios::app);
				orderFile2<<"\t \t \t \t \t     "<<quantity2<<"pc/s."<<orderName2<<" x P"<<price2<<" = P"<<total2<<endl;

				if (orderMore=='Y' || orderMore=='y')
					goto sale;
				else if (orderMore=='N' || orderMore=='n')
				{
					cursorPosition(39, 24);
					cout<<"Your order/s are succesfully added.";
					cursorPosition(39, 25);
					system("pause");
					medicine();
				}
				else
				{
					cursorPosition(44,24);
					cout<<"Invalid operation. Try again.";
					Sleep(600);
					goto again2;
				}
}

void sale()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(41,2);
	cout<<"MEDICINE MENU // SALE MEDICINE";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(30,5);
	cout<<"Purchase";
	cursorPosition(57,5);
	cout<<"Help Tips";
	cursorPosition(84,5);
	cout<<"Go Back";
	cursorPosition(17,25);
	cout<<"================================================================================";

	cursorPosition(51,7);
	cout<<"SALE Items:\n"; 
	cursorPosition(32,9); cout<<"Generic Name: ";
	cursorPosition(54,9); cout<<"Dosage: ";
	cursorPosition(71,9); cout<<"Price: ";
	cout<<endl;
	cout<<ifstream("sale.txt").rdbuf();
	
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(31,22);
	printf("|Press First Character for further Menu:| P/H/G: ");
	cin>>ch;

		switch(ch)
				{
					case'P':
					case'p':
						purchase();
						break;
					case'H':
					case'h':
						help();
						break;
					case'G':
					case'g':
						view();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						sale();
				}
}

void help()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(41,2);
	cout<<"MEDICINE MENU // HELP TIPS";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(40,5);
	cout<<"View Available";
	cursorPosition(67,5);
	cout<<"Go Back";
	cursorPosition(17,25);
	cout<<"================================================================================";

	cursorPosition(29,7);
	cout<<"PROTECT YOURSELF AND THE OTHERS FROM SPREADING COVID-19.";
	cursorPosition(29,9);
	cout<<"1. Regularly and thoroughly clean your hands with an";
	cursorPosition(29,10);
	cout<<"alcohol-based hand rub or wash them with soap and water.";
	cursorPosition(29,11);
	cout<<"2. Maintain at least 1m distance between yourself and others. ";
	cursorPosition(29,12);
	cout<<"3. Avoid going to crowded places.";
	cursorPosition(29,13);
	cout<<"4. Avoid touching eyes, nose and mouth.";
	cursorPosition(29,14);
	cout<<"5. If you have a fever, cough and difficulty breathing, ";
	cursorPosition(29,15);
	cout<<"seek medical attention.";
	cursorPosition(29,16);
	cout<<"6. Keep up to date on the latest information from trusted sources.";
	cursorPosition(29,17);
	cout<<"7. Strengthen your immune system.";
	cursorPosition(29,18);
	cout<<"8. Avoid close contact.";
	cursorPosition(29,19);
	cout<<"9. Avoid going out of your houses.";
	cursorPosition(29,20);
	cout<<"10. Always pray and ask for guidance.";

	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| V/G: ");
	cin>>ch;

		switch(ch)
				{
					case'V':
					case'v':
						view();
						break;
					case'G':
					case'g':
						medicine();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						help();
				}
}

void bill()
{
	char ch=0; 

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(51,2);
	cout<<"BILLING SECTION";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(24,5);
	cout<<"My Medicine Tray";
	cursorPosition(56,5);
	cout<<"Checkout";
	cursorPosition(87,5);
	cout<<"Go Back";
	cursorPosition(44,8);
	cout<<"Welcome to the BILLING SECTION!";
	cursorPosition(36,10);
	cout<<"This is where you can access all your purchases";
	cursorPosition(31,11);
	cout<<"done in the MEDICINE STATION. This could let the customers";
	cursorPosition(34,12);
	cout<<"review their orders and monitor their amount of total.";
	cursorPosition(32,13);
	cout<<"This part also lets the customers to finalize everything";
	cursorPosition(31,14);
	cout<<"and submit them through the checkout section written above.";
	cursorPosition(31,16);
	cout<<"NOTE: You only need to follow the instructions written below.";
	cursorPosition(34,17);
	cout<<"Any incorrect and invalid inputs would automatically";
	cursorPosition(50,18);
	cout<<"terminate the program.";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| M/C/G: ");
	cin>>ch;

		switch(ch)
				{
					case'M':
					case'm':
						medTray();
						break;
					case'C':
					case'c':
						check();
						break;
					case'G':
					case'g':
						welcome();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						bill();
				}
}

void medTray()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(36,2);
	cout<<"BILLING SECTION // MY MEDICINE TRAY ORDERS";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(40,5);
	cout<<"Checkout";
	cursorPosition(68,5);
	cout<<"Go Back";
	cursorPosition(53,7);
	cout<<"YOUR ORDERS: ";
	cursorPosition(44,9);
	cout<<"Orders from Available Items & Total: ";
	cursorPosition(44,15);
	cout<<"Orders from Sale Items & Total: ";
	cursorPosition(17,25);
	cout<<"================================================================================";
	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	fstream fa(firstName + " available.txt");
	fa.is_open();
	cursorPosition(0,10);
	cout<<fa.rdbuf();
	fa.close();

	fstream fs(firstName + " sale.txt");
	fs.is_open();
	cursorPosition(0,16);
	cout<<fs.rdbuf();
	fs.close();
	
	cursorPosition(29,21);
	cout<<"Please head to Checkout if you're done with your order/s.";

	cursorPosition(33,22);
	printf("|Press First Character for further Menu:| C/G: ");
	cin>>ch;

		switch(ch)
				{
					case'C':
					case'c':
						check();
						break;
					case'G':
					case'g':
						bill();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						medTray();
				}
}

void check()
{
	char response=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(46,2);
	cout<<"BILLING SECTION // CHECKOUT";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(40,5);
	cout<<"My Medicine Tray";
	cursorPosition(70,5);
	cout<<"Go Back";
	cursorPosition(44,7);
	cout<<"Hi "<<firstName<<"!"<<" Here is your Checkout Bill: ";
	cursorPosition(45,8);
	cout<<"------------------------------------";
	cursorPosition(45,9);
	cout<<"Total Bill from Available Items: P"<<totalAvail;
	cursorPosition(45,10);
	cout<<"------------------------------------";
	cursorPosition(45,15);
	cout<<"------------------------------------";
	cursorPosition(47,16);
	cout<<"Total Bill from Sale Items: P"<<totalSale;
	cursorPosition(45,17);
	cout<<"------------------------------------";
	
	grandTotal= totalAvail + totalSale;
	cursorPosition(49,23);
	cout<<"Your TOTAL AMOUNT is: P"<<grandTotal;
	cursorPosition(22,24);
	cout<<"Thank you! We'll get in touch with you as soon as your orders are ready.";
	cursorPosition(17,27);
	cout<<"================================================================================";
	cursorPosition(42,28);
	cout<<"Date and Time: \n";
	cursorPosition(57,28);
	t();

	fstream fa(firstName + " available.txt");
	fa.is_open();
	if (fa.fail())
	{
		cursorPosition(55,11);
		cout<<"No Orders.";
	}
	cursorPosition(0,11);
	cout<<fa.rdbuf();
	fa.close();
	
	fstream fs(firstName + " sale.txt");
	fs.is_open();
	if (fs.fail())
	{
		cursorPosition(55,18);
		cout<<"No Orders.";
	}
	cursorPosition(0,18);
	cout<<fs.rdbuf();
	fs.close();

	cursorPosition(37,25);
	printf("|Press First Character for further Menu:| M/G: ");
	cin.ignore();
	cin>>response;

		switch(response)
				{
					case'M':
					case'm':
						medTray();
						break;
					case'G':
					case'g':
						bill();
					default:
						cursorPosition(44,26);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						check();
				}
}

void about()
{
	char ch=0;

	system ("cls");
	cursorPosition(17,1);
	cout<<"================================================================================";
	cursorPosition(51,2);
	cout<<"ABOUT THIS PROGRAM";
	cursorPosition(17,3);
	cout<<"================================================================================";
	cursorPosition(57,5);
	cout<<"Go Back";
	cursorPosition(50,7);
	cout<<"WHAT ABOUT THIS PROGRAM?";
	cursorPosition(20,9);
	cout<<"Pharmacy Express is a medical store management system that is open for all,";
	cursorPosition(20,10);
	cout<<"both the customers and suppliers. This is made for everyone's accessibility";
	cursorPosition(26,11);
	cout<<"due to the current pandemic that we are experiencing right now.";
	cursorPosition(18,12);
	cout<<"We are more than just a pharmacy system, we care about your health and wellness.";
	cursorPosition(20,13);
	cout<<"This is created for us to access our neccessities at the safety of our homes";
	cursorPosition(22,14);
	cout<<"without having to go to any physical drugstores and implement distancing.";
	cursorPosition(22,16);
	cout<<"In this program, suppliers can update the stocks and supplies available by";
	cursorPosition(19,17);
	cout<<"adding, deleting and showing to everyone the list of stocks that our pharmacy have.";
	cursorPosition(16,18);
	cout<<"We also offer our customers our medicine menus for their everyday needs that they can buy";
	cursorPosition(17,19);
	cout<<"through any way to keep themselves healthy and better amidst the situation right now.";
	cursorPosition(17,25);
	cout<<"================================================================================";

	cursorPosition(42,27);
	cout<<"Date and Time: \n";
	cursorPosition(57,27);
	t();

	cursorPosition(36,22);
	printf("|Press First Character for further Menu:| G: ");
	cin>>ch;

		switch(ch)
				{
					case'G':
					case'g':
						welcome();
						break;
					default:
						cursorPosition(44,23);
						cout<<"Invalid operation. Try again.";
						Sleep(600);
						about();
				}
}


