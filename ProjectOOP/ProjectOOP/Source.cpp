#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------
//reading the characteristics of the event location 
//(eg: maximum number of seats, number of rows , zones, number/coding of seats per row, etc.)
//class Location
//{
//	int totalSeatsNo = 0;
//	int totalRowsNo = 0;
//	int totalZonesNo = 0;
//
//
//};



enum Months {January = 1,February,March,April,May,June,July};
class Date
{
	int day;
	Months month;		
	int year;

public:

	static int MAX_DAY;

	Date(int day, Months month, int year)
	{
		this->setDay(day);
		this->setMonth(month);
		this->setYear(year);
	}
private:
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
			case 4:
			case 6:
			case 9:
			case 11:
				MAX_DAY = 30;
			case 2:
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
			if (this->day > Date::MAX_DAY)
				throw exception("wrong day");
		}
		
	}

	void setDay(int value)
	{
		switch (this->month) {
		case 4:
		case 6:
		case 9:
		case 11:
			Date::MAX_DAY = 30;
		case 2:
			Date::MAX_DAY = 28;
		default:
			Date::MAX_DAY = 31;
		}
		if (value < 1 || value > MAX_DAY)
			throw exception("wrong day");
		else
			this->day = value;
	}

	void setYear(int value)
	{
		if (year < 2000 || year>2150)
			throw exception("Wrong year");
		else
			this->year = value;
	}
};
int Date::MAX_DAY = 31;

//----------------------------------------------------------------------------------------------------------------------------------------------------------
class Time
{
	int hour;
	int minute;

public:
	Time(int hour, int minute)
	{
		this->setHour(hour);
		this->setMinute(minute);
	}
private:
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
};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//reading the characteristics of the event
//(eg: date, time, name, etc.)
class Event
{
	string name;
	string details;
	Date eventDate;
	int hour;							
	int minute;



};

//----------------------------------------------------------------------------------------------------------------------
//nominal tickets according to the desired characteristics
//(eg: VIP, lawn, tribune, boxes, etc.)

//class seatType
//{
//	string name = "";
//	int totalRowNo = 0;
//	int firstRow = 0;
//
//};


//row number, seat number, price, event, const id
//class Ticket
//{
//
//};



int main()
{
	//Date date1(29, February, 2001);
	Date date1(25, February, 2001);
	//Date date1(45, January, 2001);
	//Time time1(14, 54);
	//Time time1(78, 12);
	
	
}
