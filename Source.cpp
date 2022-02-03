#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>

#pragma warning(disable: 4996)

using namespace std;

//CODE WAR
// 
//Huda 
//Sawa
//Banaz
//Ibrahiem 


void ColorForCode() 
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 113);
}


int Choose;
string name, city, name2, origin, destination, food, ticket, SeatClass;
string adminPassword = "admin";

int phone, date, passport, seat, pick, take, take2,price;


void eraseFileLine(std::string path, std::string eraseLine) {
	string line;
	ifstream fin;

	fin.open(path);
		// contents of path must be copied to a temp file then
		// renamed back to the path file
	ofstream temp;
	temp.open("temp.txt");

	while (getline(fin, line)) {
		// write all lines to temp other than the line marked for erasing
		if (line != eraseLine)
			temp << line << std::endl;
	}

	temp.close();
	fin.close();

		// required conversion for remove and rename functions
	const char* p = path.c_str();
	remove(p);
	rename("temp.txt", p);
}
//use vector<struct> name


//https://www.cplusplus.com/reference/ctime/strftime/
//https://www.cplusplus.com/reference/ctime/tm/

char Timee() {

	//I found this
	// I can't find where I C and V it from

	time_t rawtime;			//The time_t datatype is a data type in the ISO C library defined for storing system time values
	struct tm* timeinfo;	//a struct pointer ... idk
	char buffer[80];		//a array of characters 

	time(&rawtime);					//gets the refrence 
	timeinfo = localtime(&rawtime);	//equalizing an entire struct to a function

	strftime(buffer, 80, " %I:%M%p ", timeinfo);	//All i know is that the %M and %p mean to different time formats //I've tested a few and idk why they don't work

	puts(buffer);				//IDK what it does tbh

	return strftime(buffer, 80, " %I:%M%p ", timeinfo);	
	puts(buffer);

}

string TimeFunc2() {

	//Mr.Mohammed Provided this

	time_t current_time;
	struct tm local_time;

	time(&current_time);
	localtime_s(&local_time, &current_time);
	int Year = local_time.tm_year + 1900;
	int Month = local_time.tm_mon + 1;
	int Day = local_time.tm_mday;

	int Hour = local_time.tm_hour;
	int Min = local_time.tm_min;
	int Sec = local_time.tm_sec;
	cout << Year << ":" << Month << ":" << Day << endl;
	cout << Hour % 12 << ":" << Min << ":" << Sec << endl;

	return to_string(Hour % 12) + ":" + to_string(Min) + ":" + to_string(Sec);

}

string tomorrowDate() {
	
	//https://stackoverflow.com/questions/29628665/how-can-i-get-current-date-in-c
	//3rd block down

	

	time_t now = time(0);
	tm* ltm = localtime(&now);			//I think is a pointer in "C" VV						//adds one to the current day
	//cout << "Year: " << 1900 + ltm->tm_year << "\t" << "Month: " << 1 + ltm->tm_mon << "\t" << "Day: " << 1 + ltm->tm_mday << endl;

	
	string dateOfTomrrow = "Year: " + to_string( 1900 + ltm->tm_year ) + "\t Month: " + to_string( 1 + ltm->tm_mon )+ "\t" + "Day: " + to_string( 1 + ltm->tm_mday);

	return dateOfTomrrow;
}



struct TicketInfo
{
	string Firstname;
	string LastName;
	string address;
	string origin, destination, foodType, seatClass, date, time, ticketCode;
	int phoneNumber, passportNumber, no_seats, price;
}TicketStruct;


string randomTicketCode() {
	string first2letters = "HF";
		srand(time(0));
	return first2letters + to_string(rand()%100);
}

string RandomTicketCodeMoreSecurePart2() {

	unsigned seed = time(0);
	srand(seed);
	int a = rand() % 100 + 1;
	char alpha = ('a' + rand() % 26);// lowercase letters
	char alpha1 = ('A' + rand() % 26);//uppercase letters
	//cout << alpha1 << a << alpha << "\t";
	string ticketCodeB =to_string( alpha1 + a + alpha);
	
	return ticketCodeB;
}


void IntroInterface() {

	cout << "\nWelcome to Tishk Airlines \n\n";

	cout << "Please choose an action \n\n";

	cout << "Press 1 for Booking\n";

	cout << "Press 2 for Routes\n";

	cout << "Press 3 for Complaints\n";

	cout << "Press 4 for About\n";

	cout << "Press 5 for Management\n";

	cout << "Press 0 for Exit\n\n";


}


void Booking()
{

	if (Choose == 1) //Booking
	{
		cout << " Enter Your First Name: ";
		cin >> name;
		cout << " Enter Your last Name: ";
		cin >> name2;
		cout << "\n";
		cout << " Enter Your city:";
		cin >> city;
		cout << endl;
		cout << " Enter Your Phone Number (without -):";
		cin >> phone;
		cout << "\n";
		cout << " Enter Date of Departure (D.M.Y):  ";
		cout << "\n";
		cin >> date;

		cout << endl;
		//system("CLS");

		cout << "\n   Enter one of the options below \n";

		cout << "\n 1 Local Destination";
		cout << "\n 2 International Destination";
		cout << "\n 3 Back";
		cout << "\n 4 Exit\n";
		
		cin >> pick;
		cin.ignore();
	    //BookingTickting();
	}


}

void BookingTickting()
{
	//
	if (pick == 1)
	{
		cout << "These are the local destinations where we are flying:\n"
			 << "Duhok" << endl
			 << "Kirkuk" << endl
			 << "Sulaymaniyah" << endl
			 << "Zakho" << endl
			 << "Erbil" << endl
			 << "Baghdad" << endl
			 << "Enter your origin\n";
		cin >> origin;
		cout << "Enter your destination\n";
		cin >> destination;

		price = (rand() % 3200) + 300;
			

		cout << "Price: " << price << endl;

		cout << "1.Business Class\n"
			 << "2.Economy Class\n"; 
	
		cin >> take;

		if (take == 1)
		{
			cout << "Business Class \n";
			SeatClass = "Business Class";
			cout << "Enter the number of seats:";
			cin >> seat;
			cout << "seat is availabe\n";
			cout << "Available meal types:\n"
				 << "1.Vegetarian\n"
				 << "2.Non - Vegetarian\n"
				 << "Enter the number of which food would you like\n";

			cin >> take2;
			if (take2 == 1)
			{
				food = "vegetarian";
				ticket = RandomTicketCodeMoreSecurePart2();

				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name : " << name << "  " << name2 << endl;
				cout << " Phone : " << phone << endl;
				cout << " Address : " << city << endl;
				cout << " Passport Number : " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Price : " << price << endl;
				cout << " Class : Business " << endl;
				cout << " Date : " << date << endl;
				cout << " Time : " << TimeFunc2() << endl;  //  <----- HERE 
				cout << " Ticket : " << ticket<< endl;

				

				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;

				TicketStruct.origin = origin;
				TicketStruct.address = city;

				TicketStruct.passportNumber = passport;
				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;
				TicketStruct.price = price;
				//Mr.Mohammed's Function
				TicketStruct.time = TimeFunc2();

				//TicketStruct.time = Timee();
				
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			}
			
			else if (take2 == 2)
			{
				food = "Non - Vegetarian";
				ticket = RandomTicketCodeMoreSecurePart2();


				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : " << food << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Class : Business " << endl;
				cout << " Price : " << price << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" << TimeFunc2() << endl;  //timing?? am,pm??
				cout << " Ticket : " << ticket << endl;  //ticket??
		
				
				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;

				TicketStruct.origin = origin;
				TicketStruct.address = city;

				TicketStruct.passportNumber = passport;
				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;
				TicketStruct.price = price;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			}
		}
		//was take
		if (take == 2)
		{
			cout << "Economy Class \n";
			SeatClass = "Economy Class";

			cout << "Enter the number of seats:";
			cin >> seat;
			cout << "seat is availabe\n";
			cout << "Available meal types:\n\n"
				<< "1.Vegetarian\n"
				<< "2.Non - Vegetarian\n"
				<< "type in which food would you like\n";

			cin >> take2;
			if (take2 == 1)
			{
				food = "Non - Vegetarian";
				ticket = RandomTicketCodeMoreSecurePart2();

				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : Non - Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Price : " << price << endl;
				cout << " Class : Economy " << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" <<TimeFunc2()<< endl;  //timing?? am,pm??
				cout << " Ticket : " << ticket << endl;  //ticket??


				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;

				TicketStruct.origin = origin;
				TicketStruct.address = city;

				TicketStruct.passportNumber = passport;
				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;
				TicketStruct.price = price;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			}
			else if (take2 == 2)
			{
				food = "Non - Vegetarian";
				ticket = RandomTicketCodeMoreSecurePart2();


				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : Non - Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Class : Economy " << endl;
				cout << " Price : " << price << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" << TimeFunc2() << endl;  
				cout << " Ticket : " << ticket << endl; 


				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;
				
				TicketStruct.origin = origin;
				TicketStruct.address = city;

				TicketStruct.passportNumber = passport;
				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;
				TicketStruct.price = price;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			}
		}
		char decide;
		cout << "Do you wish to confirm your ticket ? (y/n):";
		cin >> decide;

		if (decide == 'y')
		{
			cout << "|STATUS CONFIRMED| \n Thanks for Flying With Us";
			
			ofstream intoTicketInfo("TicketInfomation.txt", ios::app);

			intoTicketInfo << "Ticket Code: " << TicketStruct.ticketCode << endl;
			intoTicketInfo << "First name: " << TicketStruct.Firstname << endl;
			intoTicketInfo << "Last name: " << TicketStruct.LastName << endl;
			intoTicketInfo << "Address: " << TicketStruct.address << endl;
			intoTicketInfo << "Departure: " << TicketStruct.date << endl;
			intoTicketInfo << "Destination: " << TicketStruct.destination << endl;
			intoTicketInfo << "FoodType: " << TicketStruct.foodType << endl;
			intoTicketInfo << "Number of seats: " << TicketStruct.no_seats << endl;
			intoTicketInfo << "Origin: " << TicketStruct.origin << endl;
			intoTicketInfo << "Price: " << TicketStruct.price;
			intoTicketInfo << "PassportNumber: " << TicketStruct.passportNumber << endl;
			intoTicketInfo << "PhoneNumber: " << TicketStruct.phoneNumber << endl;
			intoTicketInfo << "SeatClass: " << TicketStruct.seatClass << endl;

			intoTicketInfo << "Time: " << TicketStruct.time << endl;

			intoTicketInfo << endl;

			intoTicketInfo.close();

			exit(0);

			//exit(0);
		}
		else 
		{

			cout << "BOOKING CANCELLED^";
			//system("cls");
			
			IntroInterface();
			cin >> Choose;
			//main();
		}

	}
	else if (pick == 2)//
		{
		cout << "Enter your passport Number: ";
		cin >> passport;
		cout << "\nTurkey \nSyria \nJordan \nSaudi Arabia \nKuwait \nIran \n";
		cout << "\n";
		cout << "Enter your origin(using BLOCK letters):";
		cin >> origin;
		cout << "Enter your destination(using BLOCK letters):";
		cin >> destination;


		cout << "1.Business Class\n"
			<< "2.Economy Class\n";
		cin >> take;
		

		/*
		
		if(take == 1)
		{
			price=(300*1.2)*seats
			we need to move the location of the "seats cin"
		}

		*/

		cout << "Price:\n";

		if (take == 1)
		{
			cout << "Business Class \n";
			cout << "Enter the number of seats:";
			cin >> seat;
			cout << "seat is availabe\n";
			cout << "Available meal types:\n"

				<< "1.Vegetarian\n"
				<< "2.Non - Vegetarian\n";



			cin >> take2;

			if (take2 == 1)
			{
				ticket = RandomTicketCodeMoreSecurePart2();
				food = "Vegetarian";

				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin: " << origin << endl;
				cout << " Destination: " << destination << endl;
				cout << " Food: Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Class : Business " << endl;
				cout << " Price : " << price << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" << TimeFunc2() << endl;  //timing?? am,pm??
				cout << " Ticket : " << ticket << endl;  //ticket??
			

				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;
				TicketStruct.passportNumber = passport;

				TicketStruct.origin = origin;
				TicketStruct.address = city;

				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.price = price;
				TicketStruct.seatClass = SeatClass;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			}
			else if (take2 == 2)
			{
				ticket = RandomTicketCodeMoreSecurePart2();
				food = "Non - Vegetarian";

				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : Non - Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Class : Business " << endl;
				cout << " Price : " << price << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" <<TimeFunc2()<< endl;  //timing?? am,pm??
				cout << " Ticket : "<< ticket << endl;  //ticket??
		

				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;

				TicketStruct.address = city;
				TicketStruct.origin = origin;

				TicketStruct.passportNumber = passport;
				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;

				TicketStruct.price = price;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			}

		}
		if (take == 2)
		{
			cout << "Economy Class \n";
			cout << "Enter the number of seats:";
			cin >> seat;
			cout << "seat is availabe\n";
			cout << "Available meal types:\n\n"
				<< "1.Vegetarian\n"
				<< "2.Non - Vegetarian\n";
			cin >> take2;
			if (take2 == 1)
			{
				ticket = RandomTicketCodeMoreSecurePart2();
				food = "Vegetarian";

				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Class : Economy " << endl;
				cout << " Price : " << price << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" <<TimeFunc2()<< endl;  //timing?? am,pm??
				cout << " Ticket : "<< ticket << endl;  //ticket??


				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;
				TicketStruct.phoneNumber = phone;
				TicketStruct.passportNumber = passport;

				TicketStruct.origin = origin;
				TicketStruct.address = city;

				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;

				TicketStruct.price = price;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode =ticket;

			}
			else if (take2 == 2)
			{
				ticket = RandomTicketCodeMoreSecurePart2();
				food = "Non - Vegetarian";

				cout << "\n\n";
				cout << " YOUR TICKET INFORMATION:\n";
				cout << " Name: " << name << "  " << name2 << endl;
				cout << " Phone: " << phone << endl;
				cout << " Address: " << city << endl;
				cout << " Passport Number: " << passport << endl;
				cout << " Origin : " << origin << endl;
				cout << " Destination :" << destination << endl;
				cout << " Food : Non - Vegetarian" << endl;
				cout << " Number of seat : " << seat << endl;
				cout << " Class : Economy " << endl;
				cout << " Price : " << price << endl;
				cout << " Date : " << date << endl;
				cout << " Time :" << endl;  //timing?? am,pm??
				cout << " Ticket : "<< ticket << endl;  //ticket??

				TicketStruct.Firstname = name;
				TicketStruct.LastName = name2;

				TicketStruct.address = city;
				TicketStruct.origin = origin;


				TicketStruct.phoneNumber = phone;
				TicketStruct.passportNumber = passport;
				TicketStruct.destination = destination;
				TicketStruct.foodType = food;
				TicketStruct.no_seats = seat;
				TicketStruct.seatClass = SeatClass;

				TicketStruct.price = price;
				TicketStruct.time = TimeFunc2();
				TicketStruct.date = tomorrowDate();
				TicketStruct.ticketCode = ticket;

			
			}
		}
		char decide;
		cout << "Do you wish to confirm your ticket ? (y/n):";
		cin.ignore();	//thank you holan :)
		cin >> decide;

		if (decide == 'y')
		{
			cout << "|STATUS CONFIRMED| \n Thanks for Flying With Us";

			ofstream intoTicketInfo("TicketInfomation.txt" , ios::app);

			intoTicketInfo << "Ticket Code: " << TicketStruct.ticketCode << endl;
			intoTicketInfo << "First name: " << TicketStruct.Firstname << endl;
			intoTicketInfo << "Last name: " << TicketStruct.LastName << endl;
			intoTicketInfo << "Address: " << TicketStruct.address << endl;
			intoTicketInfo << "Departure: " << TicketStruct.date << endl;
			intoTicketInfo << "Destination: " << TicketStruct.destination << endl;
			intoTicketInfo << "FoodType: " << TicketStruct.foodType << endl;
			intoTicketInfo << "Number of seats: " << TicketStruct.no_seats << endl;
			intoTicketInfo << "Origin: " << TicketStruct.origin << endl;
			intoTicketInfo << "Price: " << TicketStruct.price;
			intoTicketInfo << "PassportNumber: " << TicketStruct.passportNumber << endl;
			intoTicketInfo << "PhoneNumber: " << TicketStruct.phoneNumber << endl;
			intoTicketInfo << "SeatClass: " << TicketStruct.seatClass << endl;

			intoTicketInfo << "Time: " << TicketStruct.time << endl;
			intoTicketInfo << endl;

			intoTicketInfo.close();

			exit(0);
		}
		else if (decide == 'n' || decide == 'N')
		{
			cout << "BOOKING CANCELLED_";
			IntroInterface();
			cin >> Choose;
			

			
		}
	}
		else if (pick == 3)
		{

		IntroInterface();

		cin >> Choose;

		}
		else if (pick == 4)
		{
		exit(0);
		}

}


void Routes()
{
	if (Choose == 2)
	{
		char exitingChoice;
		string word;

		ifstream routeFileRead("routes.txt");

		if (!routeFileRead.fail())
		{

			while (!routeFileRead.eof())
			{
				getline(routeFileRead, word);
				cout << word << endl;
			}

			cout << "Would you like to return to the main menu?\n";
			cout << "hit 'y' if yes hit 'n' if you want to exit\n";
			cin >> exitingChoice;
			if (exitingChoice == 'y' || exitingChoice == 'Y')
			{
				system("cls");
				IntroInterface();
				//cin >> Choose;
			}
			else if (exitingChoice == 'n' || exitingChoice == 'N')
			{
				exit(0);
			}
			
		}
		else
		{
			cout << "File not found ERROR! \n";
			system("cls");
			IntroInterface();
			cin >> Choose;
		}
	}

}

void Complaints() {

	if (Choose == 3)
	{

		int user;
		string fname;
		string lname;
		int phone;
		int choice;
		string comp;

		int repeat = 0;

		bool True = 1;
		bool False = 0;



		cout << "Enter your first name: ";
		cin >> fname;

		cout << "Enter Your Last Name: ";
		cin >> lname;

		cout << "Enter Your Phone Number: ";
		cin >> phone;
		

		cout << "Enter The Type Of Complain: " << endl << endl;
		cout << "1. Airport Handling" << endl;
		cout << "2. Baggage Delivery" << endl;
		cout << "3. Booking and ticketing" << endl;
		cout << "4. others" << endl;

		

		cout << "Enter one of the choices of above.\n";

		cin >> user;

		// cin >> comp;

		if (user == 1)
		{
			cin.ignore();	//To prevent the coding skiping the getline
			cout << "Airport Handling" << endl << endl;
			cout << "Enter your complaint:" << endl;
			getline(cin, comp);
			//ofstream ofile("AirportHandling.txt" , ios :: app);
			//ofile.close();

		}
		else if (user == 2)
		{
			cin.ignore();
			cout << "Baggage Delivery\n" << endl;
			cout << "Enter your complaint:" << endl;
			getline(cin, comp);
			//ofstream ofile("BaggageDelivery.txt" , ios :: app);
			//ofile.close();

		}
		else if (user == 3)
		{
			cin.ignore();
			cout << "Booking and ticketing\n" << endl;
			cout << "Enter your complaint:" << endl;
			getline(cin, comp);
			//ofstream ofile("BookingAndTicketing.txt" , ios :: app);
			//ofile.close();

		}
		else if (user == 4)
		{
			cin.ignore();
			cout << "Other\n\n";
			cout << "Enter your complaint:" << endl;
			getline(cin, comp);
			//ofstream ofile("Other.txt" , ios :: app);
			//ofile.close();

		}

		cout << "\n Do you want to edit your complain: \n" ;
		cout << "0. No" << endl;
		cout << "1. Yes" << endl;

		cin >> choice;
		if (choice != 1 && choice != 0)
		{
			cout << "please enter either '1' for yes or '0' for no\n ";
			cin >> choice;
		}
		else if (choice == 1)
		{
			cout << "Enter your complaint again	\n";
			getline(cin, comp);

		}
		else if (choice == 0)
		{
			cout << "Complaint noted. Thank you very much";
		}
		system("cls");
		IntroInterface();
		//cin >> Choose;

		switch (user)
		{
		case 1:
		{
			ofstream AirPortHandle;
			AirPortHandle.open("AirPortHandlingComplaints", ios::app);
			AirPortHandle << endl << comp << endl;
			AirPortHandle.close();
		}
		break;
		case 2:
		{
			ofstream BagDeliv;
			BagDeliv.open("BagDeliveryComplaints", ios::app);
			BagDeliv << endl << comp << endl;
			BagDeliv.close();
		}
		break;
		case 3:
		{
			ofstream BookAndTick;
			BookAndTick.open("BookingAndTicktingComplaints", ios::app);
			BookAndTick << endl << comp << endl;
			BookAndTick.close();
		}
		break;
		case 4:
		{
			ofstream Othr;
			Othr.open("OtherComplaints", ios::app);
			Othr << endl << comp << endl;
			Othr.close();

		}
		break;
		}
	
	}
}

void About() {

	if (Choose == 4)
	{
		cout << "The height of skies was first touched by our airline in 2021.\n Since then, Tishk Airlines is the world's leading airline with 4 biggest airplanes.\n We are at the customers high service in cuisine, comfort, and care.\n So make a plan and fly high with Tishk Airlines.\n\n";
		system("pause");
		//system("CLS");
		IntroInterface();
		
	}

}

void Mangement() {

	if (Choose == 5)
	{
		cout << ">>>>>>>>>>MANAGE<<<<<<<<<<" << endl;

		string Ticket;
		string wordFromFile;
		string word2;
		int optionChoices;
		char DateChoice;
		int count = 0;


		ifstream InFromBanaz;
		InFromBanaz.open("TicketInfomation.txt");

		if (InFromBanaz.fail())
		{
			cout << "The file you are looking through does not exist or there is no booking\n";
		}
		else
		{
			if (!InFromBanaz.eof() == false)
			{
				exit(0);
			}
			cout << "Enter your Ticket Number" << endl;
			cout << "Ticket Number" << endl;
			cin >> Ticket;

			while (!InFromBanaz.eof())
			{
				InFromBanaz >> wordFromFile;
				if (wordFromFile == Ticket)//from the struct
				{
					cout << "File has been found.\n";
					while (count <= 12)
					{
						//Thank you holan

						getline(InFromBanaz, word2);
						cout << word2 << endl;
						
						count++;

					}
					cout << "options\n";
					cout << "1.Change Date\n"
						 << "2.Cancel Ticket (WIP)\n"
						 << "3.go back to main menu\n";

					cin >> optionChoices;
		

					if (optionChoices == 1)
					{
						string date;

						cout << "enter the line of choice word for word\n";
						cin >> date;

						eraseFileLine("TicketInfomation.txt", "date");
					}
					else if (optionChoices == 2)
					{
						cout << "sorry currently in progress\n";
					}
					else if (optionChoices == 3)
					{
						system("cls");
						IntroInterface();
						cin >> Choose;
					}
					else
					{
						cout << "1-3 please\n";
						cin >> optionChoices;
					}
					

				}


			}


		}


	}


}

void adminControls(string adminPassword)
{
	string line;
	ofstream routesFile("routes.txt" , ios::app);

	if (!routesFile.fail())
	{

		while (!routesFile.eof())
		{
			
			//writing into the func
			
		}

	}
	else
	{
		cout << "Error no file found;\n";
		exit(0);
	}
	routesFile.close();
}


void group()
{
	ColorForCode();
	Booking();
	BookingTickting();
	Routes();
	Complaints();
	About();
	Mangement();
}

int main()
{
	ColorForCode();
	system("CLS");

	cout << "\n";
	cout << "COMPUTER PROGRAMMING LAB PROJECT\n";
	cout << "\n\t\t\t\t\t\t" << " FLIGHT MANAGEMENT SYSTEM \n";
	system("pause");
	//system("CLS");
	cout << "\n\n\n";
	IntroInterface();

	// SOMEONE CAN"T PUT IN THE SMAE LOACTION TWICE
	// Seats and class should determine the price of the ticket
	// FileStream for the ticket infomation I think we need structures
	// InternationalDestination >> BorderOfIraq >> Consulates of iraq

/*
	vector<string> OurNames;
	OurNames.push_back("Banaz\n");
	OurNames.push_back("Sawa\n");
	OurNames.push_back("Huda\n");
	OurNames.push_back("Ibo\n");
	
	for (int i = 0; i < OurNames.size(); i++)
	{
		cout << OurNames.at(i);
	}
	*/

	while (true)
	{
		group();

		cin >> Choose;
		//	system("CLS");

		if (Choose == 0)
		{
			break;
		}
	}

	return 0;
};


