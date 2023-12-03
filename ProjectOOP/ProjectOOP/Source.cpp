#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//location(eg: maximum number of seats, number of rows, zones, number / coding of seats per row, etc.)
class Location
{
	string name = "";
	int totalSeatsNo = 1;
	int totalRowsNo = 1;
	int totalZonesNo = 1;
	string* zoneNames = nullptr;
	int* zoneFirstRow = nullptr;
	int* zoneLastRow = nullptr;

public:

	//default constructor:
	Location()
	{

	}

	//constructors:
	Location(string name, int seats, int rows, int zones, string* zoneNames, int* firstRow)
	{
		this->setName(name);
		this->setTotalSeatsNo(seats);
		this->setTotalRowsNo(rows);
		this->setTotalZonesNo(zones);
		this->setZoneNames(zoneNames);
		this->setZoneFirstRow(firstRow);

	}

	//getters:

	string getName()
	{
		return this->name;
	}

	int getTotalSeatNo()
	{
		return this->totalSeatsNo;
	}

	int getTotalRowsNo()
	{
		return this->totalRowsNo;
	}

	int getTotalZonesNo()
	{
		return this->totalZonesNo;
	}

	string* getZoneNames()
	{
		return this->zoneNames;
	}

	int* getZoneFirstRow()
	{
		int* copy = new int[this->totalZonesNo];
		for (int i = 0; i < this->totalZonesNo; i++)
			copy[i] = this->zoneFirstRow[i];
		return copy;
	}

	int* getZoneLastRow()
	{
		int* copy = new int[this->totalZonesNo];
		for (int i = 0; i < this->totalZonesNo; i++)
			copy[i] = this->zoneLastRow[i];
		return copy;
	}

	//setters:

	void setName(string value)
	{
		if (value.size() < 3 || value.size() > 200)
			throw exception("Name too short");
		else
			this->name = value;

	}

	void setTotalSeatsNo(int value)
	{
		if (value < 0)
			throw exception("Wrong total seats number");
		else
			this->totalSeatsNo = value;
	}

	void setTotalRowsNo(int value)
	{
		if (value < 1)
			throw exception("Wrong total rows number");
		else
			this->totalRowsNo = value;
	}

	void setTotalZonesNo(int value)
	{
		if (value < 1)
			throw exception("Wrong total zones number");
		else
			this->totalZonesNo = value;

	}

	void setZoneNames(string* value)
	{
		if (this->zoneNames != nullptr)
			delete[] this->zoneNames;
		else
		{
			this->zoneNames = new string[this->totalZonesNo];
			for (int i = 0; i < this->totalZonesNo; i++)
				this->zoneNames[i] = value[i];
		}
	}

	void setZoneFirstRow(int* array)
	{
		if (this->zoneFirstRow != nullptr)
			delete[] this->zoneFirstRow;
		this->zoneFirstRow = new int[this->totalZonesNo];
		for (int i = 0; i < this->totalZonesNo; i++)
		{
			this->zoneFirstRow[i] = array[i];
		}
		delete[] array;
	}

	void setZoneLastRow(int* array)
	{
		if (this->zoneLastRow != nullptr)
			delete[] this->zoneLastRow;
		else
		{
			this->zoneLastRow = new int[this->totalZonesNo];
			for (int i = 0; i < this->totalZonesNo; i++)
				this->zoneLastRow[i] = array[i];
			delete[] array;
		}
	}
	//methods:
	void printInfoLocation()
	{
		cout << endl << "Total seat number : " << this->getTotalSeatNo();
		cout << endl << "Total rows number : " << this->getTotalRowsNo();
		cout << endl << "Total zones number : " << this->getTotalZonesNo();

		cout << endl << "Zones' names : ";
		for (int i = 0; i < this->totalZonesNo; i++)
			cout << this->zoneNames[i] << " ";

		cout << endl << "Zones' first row : ";
		for (int i = 0; i < this->totalZonesNo; i++)
			cout << this->zoneFirstRow[i] << " ";

		cout << endl << "Zones' last row : ";
		for (int i = 0; i < this->totalZonesNo; i++)
			cout << this->zoneLastRow << " ";
	}

//copy constructor:
	Location(const Location& object)
	{
		this->name = object.name;
		this->totalSeatsNo = object.totalSeatsNo;
		this->totalRowsNo = object.totalRowsNo;
		this->totalZonesNo = object.totalZonesNo;
		
		this->zoneNames = new string[object.totalZonesNo];
		for (int i = 0; i < object.totalZonesNo; i++)
		{
			this->zoneNames[i] = object.zoneNames[i];
		}

		this->zoneFirstRow = new int[object.totalZonesNo];
		for (int i = 0; i < object.totalZonesNo; i++)
		{
			this->zoneFirstRow[i] = object.zoneFirstRow[i];
		}

		this->zoneLastRow = new int[object.totalZonesNo];
		for (int i = 0; i < object.totalZonesNo; i++)
		{
			this->zoneLastRow[i] = object.zoneLastRow[i];
		}
	}

//destructor:	
	~Location()
	{
		delete[] this->zoneFirstRow;
		delete[] this->zoneLastRow;
		delete[] this->zoneNames;
	}



};

ostream& operator<<(ostream& console, Location& l)
{
	console << endl << "Location's name : " << l.getName();
	console << endl << "Total seat number : " << l.getTotalSeatNo();
	console << endl << "Total rows number : " << l.getTotalRowsNo();
	console << endl << "Total zones number : " << l.getTotalZonesNo();

	console << endl << "Zones' names : ";
	for (int i = 0; i < l.getTotalZonesNo(); i++)
		cout << l.getZoneNames()[i] << " ";

	console << endl << "Zones' first row : ";
	for (int i = 0; i < l.getTotalZonesNo(); i++)
		cout << l.getZoneFirstRow()[i] << " ";

	console << endl << "Zones' last row : ";
	for (int i = 0; i < l.getTotalZonesNo(); i++)
		cout << l.getZoneLastRow()[i] << " ";
	return console;
}

void operator>>(istream& console, Location& l)
{
	cout << "Enter location's name : ";
	char buffer[2000];
	console.getline(buffer, 2000);
	console.clear();
	l.setName(buffer);

	int x;
	cout << endl << "Enter the total number of seats in the location : ";
	console >> x;
	l.setTotalSeatsNo(x);
	cout << endl << "Enter the total number of rows in the location : ";
	console>> x;
	l.setTotalRowsNo(x);
	cout << endl << "Enter the total number of zones in the location : ";
	console>> x;
	l.setTotalZonesNo(x);

	cout << endl << "Enter the names of the zones : ";
	string* s = new string[l.getTotalZonesNo()];
	for (int i = 0; i < l.getTotalZonesNo(); i++)
	{
		console >> s[i];
	}
	l.setZoneNames(s);
	if (s != nullptr)
		delete[] s;

	cout << endl << "Enter the first row of each zone : ";
	int* array = new int[l.getTotalZonesNo()];
	for (int i = 0; i < l.getTotalZonesNo(); i++)
		console >> array[i];
	l.setZoneFirstRow(array);
	/*if (array != nullptr)
		delete[] array;*/

	cout << endl << "Enter the last row of each zone : ";
	int* array2 = new int[l.getTotalZonesNo()];
	for (int i = 0; i < l.getTotalZonesNo(); i++)
		console >> array2[i];
	l.setZoneLastRow(array);
	/*if (array2 != nullptr)
		delete[] array2;*/
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------
enum Months {January = 1,February,March,April,May,June,July,August,September,October,November,December};

class Date
{
	int day;
	Months month;		
	int year;

public:

	static int MAX_DAY;

	//default constructor
	Date()
	{

	}
	//constructor
	Date(int day, Months month, int year)
	{
		this->setDay(day);
		this->setMonth(month);
		this->setYear(year);
	}

	//getters:
	int getDay()
	{
		return this->day;
	}

	int getMonth()
	{
		return this->month;
	}

	int getYear()
	{
		return this->year;
	}
	//setters:
	void setMonth(Months value)
	{
		if (value < 1 || value>12)
			throw exception("wrong month");
		else
		{
			this->month = value;
			switch (value) {
			case Months::April:
			case Months::June:
			case Months::September:
			case Months::November:
				MAX_DAY = 30;
			case Months::February:
			{if (this->year % 400 == 0)
				MAX_DAY = 29;
			else
			{
				if (this->year % 100 == 0)
					MAX_DAY = 28;
				else
				{
					if (this->year % 4 == 0)
						MAX_DAY = 29;
					else
						MAX_DAY = 28;
				}
			}
			default:
				MAX_DAY = 31;
			}
			}
			if (this->day > Date::MAX_DAY)
				throw exception("wrong day");
		}
		
	}

	void setDay(int value)
	{
		switch (this->month) {
		case Months::April:
		case Months::June:
		case Months::September:
		case Months::November:
			MAX_DAY = 30;
		case Months::February:
			if (this->year % 400 == 0)
				MAX_DAY = 29;
			else
			{
				if (this->year % 100 == 0)
					MAX_DAY = 28;
				else
				{
					if (this->year % 4 == 0)
						MAX_DAY = 29;
					else
						MAX_DAY = 28;
				}
			}
		default:
			MAX_DAY = 31;
		}

		if (value < 1 || value > MAX_DAY)
			throw exception("wrong day");
		else
			this->day = value;
	}

	void setYear(int value)
	{
		if (value < 2000 || value>2150)
			throw exception("Wrong year");
		else
			this->year = value;
	}

public:
	//methods

	void printDate()
	{
		cout << this->day << "/" << this->month << "/" << this->year ;
	}

	//overloading:

	void operator=(Date newDate)
	{
		this->day = newDate.day;
		this->month = newDate.month;
		this->year = newDate.year;
	}

	bool operator>(Date newDate)
	{
		if ((newDate.year > this->year) || (newDate.year == this->year && newDate.month>this->month) || (newDate.year == this->year && newDate.month == this->month && newDate.day>this->day))
			return 0;
		else
			return 1;
			
	}
};
int Date::MAX_DAY = 31;

//overload cout for Date
ostream& operator<<(ostream& console, Date& d)
{
	console <<endl<<"Date : "<< d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
	return console;
}
//overload cin for Date
void operator>>(istream& console, Date&d)
{
	//cout << endl << "---------Event Date---------";
	int day;
	cout << endl << "Event day:";
	console >> day;
	d.setDay(day);
	int m;
	cout << endl << "Event month:";
	console >> m;
	d.setMonth(static_cast<Months>(m));
	int y;
	cout << endl << "Event year:";
	console >> y;
	d.setYear(y);
	
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Time
{
	int hour;
	int minute;

public:

	//default constructot
	Time()
	{

	}
	//constructor
	Time(int hour, int minute)
	{
		this->setHour(hour);
		this->setMinute(minute);
	}

	//getters:
	int getHour()
	{
		return this->hour;
	}

	int getMinute()
	{
		return this->minute;
	}


	//setters:
	void setHour(int value)
	{
		if (value < 0 || value>24)
			throw exception("wrong hour");
		else
			this->hour = value;
	}
	void setMinute(int value)
	{
		if (value < 0 || value>59)
			throw exception("wrong hour");
		else
			this->minute = value;
	}


	void printTime()
	{
		cout << this->hour << ":" << this->minute;
	}
};

//overload cout
ostream& operator<<(ostream& console, Time& t)
{
	console <<endl<<"time : " << t.getHour() << ":" << t.getMinute();
	return console;
}
//overload cin
void operator>>(istream& console, Time& t) {
	//cout << endl << "------------Event Time-----------";
	cout << endl << "Event hour is : ";
	int h;
	console >> h;
	t.setHour(h);
	cout << endl << "Event minute is : ";
	int m;
	console >> m; 
	t.setMinute(m);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//reading the characteristics of the event
//(eg: date, time, name, etc.)

class Event
{
	string name = "";
	string details = "";
	Date eventDate;
	Time eventTime;

public:

	//default constructor
	Event()
	{

	}
	//constructor
	Event(string name, string details, Date date, Time time)
	{
		this->setName(name);
		this->setDetails(details);
		this->eventDate = date;
		this->eventTime = time;
	}

	//getters:

	string getName()
	{
		return this->name;
	}

	string getDetails()
	{
		return this->details;
	}

	Date getDate()
	{
		return this->eventDate;
	}

	Time getTime()
	{
		return this->eventTime;
	}

	//setters:

	void setName(string newName) {
		if (newName.size() <= 3 || newName.size()>=100) {
			throw exception("Name too short");
		}
		this->name = newName;
	}

	void setDetails(string newDetails) {
		if (newDetails.size() <= 3 || newDetails.size() >= 100) {
			throw exception("Details too short");
		}
		this->details = newDetails;
	}

	void setDate(Date newDate)
	{
		this->eventDate = newDate;
	}

	void setTime(Time newTime)
	{
		this->eventTime = newTime;
	}

	//methods:
public:
	void printEvent()
	{
		cout << endl << "-------------EVENT--------------------";
		cout << endl << "Event name is : " << this->name;
		cout << endl << "Event details : " << this->details;
		cout << endl << "Event date : ";
		this->eventDate.printDate();
		cout << endl << "Event time : ";
		this->eventTime.printTime();
	}

	/*bool operator==(Event x)
	{
		if(this->getName() == x.getName() || && this->get
	}*/

};
//overload cout:
ostream& operator<<(ostream& console, Event& e)
{
	console << endl << "-------------EVENT--------------------";
	console << endl << "Event name is : " << e.getName();
	console << endl << "Event details : " << e.getDetails();
	console << endl << "Event date : " << e.getDate().getDay() << "/" << e.getDate().getMonth() << "/" << e.getDate().getYear();
	console << endl << "Event time : "<<e.getTime().getHour()<<":"<<e.getTime().getMinute();
	return console;
}
//overload cin:
void operator>>(istream& console, Event& e)
{
	cout << endl << "Event name : ";
	char buffer[2000];
	console.getline(buffer, 2000);
	console.clear();
	e.setName(buffer);

	cout << endl << "Event detailes : ";
	console.getline(buffer, 2000);
	console.clear();
	e.setDetails(buffer);

	cout << endl << "Event date : ";
	Date d;
	cin >> d;
	e.setDate(d);

	cout << endl << "Event time : ";
	Time t;
	cin >> t;
	e.setTime(t);

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//nominal tickets according to the desired characteristics
//(eg: VIP, lawn, tribune, boxes, etc.)

class Ticket
{
	const int id=1;
	string zoneName = "";
	int rowNo = 0;
	int seatNo = 0;
	double price = 0;
	string eventName = "";

public:
//getters:

	string getZoneName()
	{
		return this->zoneName;
	}

	int getRowNo()
	{
		return this->rowNo;
	}

	int getSeatNo()
	{
		return this->seatNo;
	}
	double getPrice()
	{
		return this->price;
	}
	string getEventName()
	{
		return this->eventName;
	}

//setters:
	void setZoneName(string s)
	{
		if (s.size() < 3 || s.size() > 50)
			throw exception("Wrong zone name");
		this->zoneName = s;
	}
	void setRowNo(int value)
	{
		if (value < 1)
			throw exception("Wrong row number");
		this->rowNo = value;
	}
	void setSeatNo(int value)
	{
		if (value < 1)
			throw exception("Wrong seat number");
		this->seatNo = value;
	}
	void setPrice(int value)
	{
		if(value<1)
			throw exception("Wrong price");
		this->price = value;
	}
	void setEventName(string s)
	{
		if (s.size() < 3 || s.size() > 200)
			throw exception("Wrong event name");
		this->eventName = s;
	}

	
};

ostream& operator<<(ostream& console, Ticket& e)
{
	console << endl << "--------------TICKET-----------------";
	console << endl << "Event name is : " << e.getEventName();
	console << endl << "Zone name is : " << e.getZoneName();
	console << endl << "Price : " << e.getPrice();
	console << endl << "Seat : " << e.getSeatNo();
	console << endl << "Row : " << e.getRowNo();
	return console;
}
//overload cin:
void operator>>(istream& console, Ticket& e)
{
	cout << endl << "Event name : ";
	char buffer[2000];
	console.getline(buffer, 2000);
	console.clear();
	e.setEventName(buffer);

	cout << endl << "Zone name : ";
	console.getline(buffer, 2000);
	console.clear();
	e.setZoneName(buffer);

	cout << endl << "Price : ";
	int p;
	cin >> p;
	e.setPrice(p);

	cout << endl << "Seat : ";
	int s;
	cin >> s;
	e.setSeatNo(s);

	cout << endl << "Row : ";
	int r;
	cin >> r;
	e.setRowNo(r);

}




int main()
{
	//Date date1(29, February, 2001);
	//Date date1(15, February, 2001);
	//Date date1(34, January, 2001);
	//date1.printDate();

	//Time time1(14, 54);
	//Time time1(78, 12);
	/*Date date1(15, February, 2001);
	Time time1(16, 15);*/
	//Event event1("Concert Delia", "concert blablabla", date1, time1);
	//cout << event1 << date1 << time1;
	/*Time t1;
	cin >> t1;
	cout << t1;*/

	/*Date date1;
	cin >> date1;
	cout << date1;
	Date date2;
	cin >> date2;
	cout << date2;*/
	/*Date date1(15, February, 2024);
	Time time1(16, 15);
	Event event1("Concert Delia", "concert blablabla", date1, time1);
	cout << event1;*/

	//Event e;
	//cin >> e;
	//cout << e;

	string names[] = { "VIP","LOJA","normal" };
	/*names[0] = "VIP";
	names[1] = "LOJA";
	names[2] = "normal";*/

	int rows[] = { 1,11,31 };

	/*int* rows = new int[10];
	rows[0] = 1;
	rows[1] = 11;
	rows[2] = 31;*/

	/*Location l1("Stadion Dinamo", 360, 60, 3, names, rows);
	l1.printInfoLocation();*/

	Location l1;
	cin >> l1;
	cout << l1;

	Ticket t1;
	cin >> t1;
	cout << t1;

	Event e;
	cin >> e;
	cout << e;

	
}
