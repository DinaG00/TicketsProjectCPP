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
	string* zoneNames = new string[totalZonesNo];
	int* zoneFirstRow = new int[totalZonesNo];
	int* zoneLastRow = new int[totalZonesNo];

	//overload =, !=	

};


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
	cout << endl << "---------Event Date---------";
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

ostream& operator<<(ostream& console, Time& t)
{
	console <<endl<<"time : " << t.getHour() << ":" << t.getMinute();
	return console;
}

void operator>>(istream& console, Time& t) {
	cout << endl << "------------Event Time-----------";
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

};

ostream& operator<<(ostream& console, Event& e)
{
	console << endl << "-------------EVENT--------------------";
	console << endl << "Event name is : " << e.getName();
	console << endl << "Event details : " << e.getDetails();
	console << endl << "Event date : " << e.getDate().getDay() << "/" << e.getDate().getMonth() << "/" << e.getDate().getYear();
	console << endl << "Event time : "<<e.getTime().getHour()<<":"<<e.getTime().getMinute();
	return console;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//nominal tickets according to the desired characteristics
//(eg: VIP, lawn, tribune, boxes, etc.)


/*row number, seat number, price, event, const id
class Ticket
{
	const id=1;
	string zoneName;
	int rowNo;
	int seatNo;
	double price;
	string eventName;


};
*/



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
	
}
