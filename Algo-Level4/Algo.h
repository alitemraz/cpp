#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

struct Period {
	Date from;
	Date to;
};

enum DatesComparison {
	EQUAL = 0,
	BEFORE = -1,
	AFTER = 1
};

namespace StringManip{
	string replaceWordInString(string s1, string stringToReplace,
		string sRepalceTo)
	{
		short pos = s1.find(stringToReplace);
		while (pos != std::string::npos)
		{
			s1 = s1.replace(pos, stringToReplace.length(),
				sRepalceTo);
			pos = s1.find(stringToReplace);
		}
		return s1;
	}
}

namespace Dates {
	using namespace StringManip;
	string numberToText(int number) {
		if (number == 0)
		{
			return "";
		}
		if (number >= 1 && number <= 19)
		{
			string arr[] = { "",
			"One","Two","Three","Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[number] + " ";
		}
		if (number >= 20 && number <= 99)
		{
			string arr[] = {
			"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
			,"Ninety" };
			return arr[number / 10] + " " + numberToText(number % 10);
		}
		if (number >= 100 && number <= 199)
		{
			return "One Hundred " + numberToText(number % 100);
		}
		if (number >= 200 && number <= 999)
		{
			return numberToText(number / 100) + "Hundreds " +
				numberToText(number % 100);
		}
		if (number >= 1000 && number <= 1999)
		{
			return "One Thousand " + numberToText(number % 1000);
		}
			if (number >= 2000 && number <= 999999)
			{
				return numberToText(number / 1000) + "Thousands " +
					numberToText(number % 1000);
			}
		if (number >= 1000000 && number <= 1999999)
		{
			return "One Million " + numberToText(number % 1000000);
		}
		if (number >= 2000000 && number <= 999999999)
		{
			return numberToText(number / 1000000) + "Millions " +
				numberToText(number % 1000000);
		}
		if (number >= 1000000000 && number <= 1999999999)
		{
			return "One Billion " + numberToText(number %
				1000000000);
		}
		else
		{
			return numberToText(number / 1000000000) + "Billions " +
				numberToText(number % 1000000000);
		}
	}

	Date readDate() {
		Date date;
		int year, month, day;

		cout << "Enter a Day: ";
		cin >> day;

		cout << "Enter a Month: ";
		cin >> month;

		cout << "Enter a Year: ";
		cin >> year;

		date.year = year;
		date.month = month;
		date.day = day;
		return date;

	}

	string readStringDate(string date)
	{
		string dateString;
		cout << date;
		getline(cin >> ws, dateString);
		return dateString;
	}

	Date extractDateFromString(string date) {
		Date d1;
		int counter = 1,day = 1,month = 1,year=1;
		int pos = date.find("/");
		while (pos != date.npos) {
			if (counter == 1) {
				day = stoi(date.substr(0, pos));
				counter++;
				date = date.substr(pos + 1, -1);
				pos = date.find("/");
			}
			else if (counter == 2) {
				month = stoi(date.substr(0, pos));
				counter++;
				date = date.substr(pos + 1, -1);
				pos = date.find("/");
			}
			else
				break;
			
		}

		d1.day = day;
		d1.month = month;
		d1.year = stoi(date);
		return d1;

	}

	string convertDateToString(Date d1) {
		return to_string(d1.day) + "/" + to_string(d1.month) + "/" + to_string(d1.year);
	}

	string formatDate(Date date, string dateFormat = "dd/mm/yyyy")
	{
		string formattedDateString = "";
		formattedDateString = replaceWordInString(dateFormat, "dd",
			to_string(date.day));
		formattedDateString = replaceWordInString(formattedDateString,
			"mm", to_string(date.month));
		formattedDateString = replaceWordInString(formattedDateString,
			"yyyy", to_string(date.year));
		return formattedDateString;
	}

	bool isLeap(int year) {

		//if (year % 400 == 0)
		//	return true;
		//else if (year % 4 == 0 && year % 100 != 0)
		//	return true;
		//return false;

		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

	}

	int nbOfDaysInAYear(int year) {
		return isLeap(year) ? 366 : 365;
	}

	int nbOfHoursInAYear(int year) {
		return nbOfDaysInAYear(year) * 24;
	}

	int nbOfMinutesInAYear(int year) {
		return nbOfHoursInAYear(year) * 60;
	}

	int nbOfSecondsInAYear(int year) {
		return nbOfMinutesInAYear(year) * 60;
	}

	void printYearDetails(int year) {

		int nbOfDays = nbOfDaysInAYear(year);
		int nbOfHours =nbOfHoursInAYear(year);
		int nbOfMinutes = nbOfMinutesInAYear(year);
		int nbOfSeconds = nbOfSecondsInAYear(year);

		cout << "Number of Days in Year \'" << year << "\' is " << nbOfDays << endl;
		cout << "Number of Hours in Year \'" << year << "\' is " << nbOfHours << endl;
		cout << "Number of Minutes in Year \'" << year << "\' is " << nbOfMinutes << endl;
		cout << "Number of Seconds in Year \'" << year << "\' is " << nbOfSeconds << endl;

	}

	int getMonthDays(int year,int month) {

		if (month <= 0 || month > 12)
			return 0;

		int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return month == 2 ? (isLeap(year) ? 29 : 28) : monthDays[month - 1];

	}

	int nbOfDaysInAMonth(int year, int month) {
		return getMonthDays(year, month);
	}

	int nbOfHoursInAMonth(int year, int month) {
		return nbOfDaysInAMonth(year, month) * 24;
	}

	int nbOfMinutesInAMonth(int year, int  month) {
		return nbOfHoursInAMonth(year, month) * 60;
	}

	int nbOfSecondsInAMonth(int year, int month) {
		return nbOfMinutesInAMonth(year, month) * 60;
	}

	void printMonthDetails(int year, int month) {
		int nbOfDays = nbOfDaysInAMonth(year,month);
		int nbOfHours = nbOfHoursInAMonth(year,month);
		int nbOfMinutes = nbOfMinutesInAMonth(year,month);
		int nbOfSeconds = nbOfSecondsInAMonth(year,month);

		cout << "Number of Days in Month \'" << month << "\' is " << nbOfDays << endl;
		cout << "Number of Hours in Month \'" << month << "\' is " << nbOfHours << endl;
		cout << "Number of Minutes in Month \'" << month << "\' is " << nbOfMinutes << endl;
		cout << "Number of Seconds in Month \'" << month << "\' is " << nbOfSeconds << endl;
	}

	int getDayOrder(int year,int month,int day) {

		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	}

	string getDayName(int dayOrder) {
		string weekDays[] = { "Sunday","Monday","Tuesday","Wednsday","Thursday","Friday","Saturday","Sunday" };

		return weekDays[dayOrder];
	}

	void printDate(int year, int month, int day) {

		cout << "Date: " << day << "/" << month << "/" << year << endl;

		int dayOrder = getDayOrder(year, month, day);

		cout << "Day Order: " << dayOrder<<endl;

		cout << "Day Name: " << getDayName(dayOrder) << endl;

	}

	string getMonthName(int month) {
		string months[] = { "January","Febuary","March","April","May",
							"June","July","Aughust","September","October",
							"November","December"
		};
		return months[month - 1];
	}

	void printMonthCalender(int year, int month) {
		printf("\n____________________%s________________________\n\n",
			getMonthName(month).substr(0,3).c_str());

		cout << left;
		for (string d : {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"})
			cout << setw(7) << d;
		cout << endl;

		int dayOrder = getDayOrder(year, month, 1);
		int counter = dayOrder;

		for (int i = 0; i < dayOrder; i++)
			cout << setw(7) << "";

		for (int i = 1; i <= getMonthDays(year, month); i++) {
			if (counter == 7) {
				cout << endl;
				counter = 0;
			}
			cout << setw(7) << i;
			counter++;
		}
		cout << endl;
		printf("_______________________________________________\n");
	}

	void printYearCalender(int year) {
		printf("\n\t _________________________________\n\n");
		printf("\t\t Calendar - %d\n", year);
		printf("\t _________________________________\n");
		for (int i = 1;i <= 12;i++) {
			printMonthCalender(year, i);
		}
	}

	int getDaysFromBeginingOfTheYear(int year, int month, int day) {


		int nbOfDays = day;

		for (int i = 1; i < month;i++) {
			nbOfDays += nbOfDaysInAMonth(year, i);
		}

		return nbOfDays;

	}

	string printDateFromBeginingOfTheYear(int year,int days) {

		int month = 1;
		
		for (int i = 1;i <= 12;i++) {
			int monthDays = nbOfDaysInAMonth(year, i);
			if (days < monthDays)
				break;
			days -= monthDays;
			month++;
		}
		return to_string(days) + "/"+to_string(month)+"/"+to_string(year);
	}

	string addingDaysToDate(int year, int month, int day, int daysAdded) {
		int dayOfYear = getDaysFromBeginingOfTheYear(year, month, day) + daysAdded;

		while (dayOfYear > nbOfDaysInAYear(year)) {
			dayOfYear -= nbOfDaysInAYear(year);
			year++;
		}

		month = 1;
		while (dayOfYear > nbOfDaysInAMonth(year, month)) {
			dayOfYear -= nbOfDaysInAMonth(year, month);
			month++;
		}

		return to_string(dayOfYear) + "/" + to_string(month) + "/" + to_string(year);
	}

	bool isDate1BeforeDate2(Date d1, Date d2) {

		return (d1.year < d2.year) ? true : ((d1.year ==
			d2.year) ? (d1.month < d2.month ? true : (d1.month ==
				d2.month ? d1.day < d2.day : false)) : false);
	}

	bool isDate1EqualsDate2(Date d1, Date d2) {

		return d1.year == d2.year ? ((d1.month == d2.month) ? (d1.day == d2.day) : false) : false;
	}

	bool isDate1AfterDate2(Date d1, Date d2) {

		return (!isDate1BeforeDate2(d1,d2)) && (!isDate1EqualsDate2(d1,d2));
	}

	DatesComparison compareDates(Date d1,Date d2) {

		if (isDate1BeforeDate2(d1, d2))
			return DatesComparison::BEFORE;
		else if (isDate1AfterDate2(d1, d2))
			return DatesComparison::AFTER;
		return DatesComparison::EQUAL;
	}

	bool isLastDayInMonth(int year,int month,int day) {

		return day == nbOfDaysInAMonth(year, month);
	}

	bool isLastMonthInAYear(int month) {
		return month == 12;
	}

	Date addDayOnDate(int year,int month,int day) {

		if (isLastDayInMonth(year, month, day)) {
			day = 1;
			if (isLastMonthInAYear(month)){
				month = 1;
				year++;
			}
			else month++;
		}
		else {
			day++;
		}

		Date result;
		result.year = year;
		result.month = month;
		result.day = day;

		return result;

	}

	Date minusDayOnDate(int year, int month, int day) {

		Date date;
		date.year = year;
		date.month = month;
		date.day = day;

		if (day > 1) {
			date.day--;
		}
		else if (month > 1) {
			date.month--;
			date.day = nbOfDaysInAMonth(year, date.month);
		}
		else {
			date.year--;
			date.month = 12;
			date.day = 31;
		}

		return date;
	}

	int diffInDays(Date d1,Date d2,bool includeEndDay = false) {

		int days = 0;
		int isNegative = 1;
		if (!isDate1BeforeDate2(d1, d2)) {
			Date temp = d2;
			d2 = d1;
			d1 = temp;
			isNegative = -1;
		}


		while (isDate1BeforeDate2(d1, d2)) {
			days++;
			d1 = addDayOnDate(d1.year,d1.month,d1.day);
		}


		return includeEndDay ? ++days * isNegative : days * isNegative;
	}

	Date GetSystemDate()
	{
		Date date;
		time_t t = time(0);
		tm* now = localtime(&t);
		date.year = now->tm_year + 1900;
		date.month = now->tm_mon + 1;
		date.day = now->tm_mday;
		return date;
	}

	int yourAgeInDays(Date d1) {

		Date d2 = GetSystemDate();

		return diffInDays(d1, d2,true);
	}

	bool isValidDate(Date d1) {

		if (d1.year < 0)
			return false;
		if (d1.month < 1 || d1.month > 12)
			return false;
		if (d1.day < 1 || d1.day > nbOfDaysInAMonth(d1.year, d1.month))
			return false;
		return true;
	}

}

namespace IncreaseDates {

	using namespace Dates;

	Date increaseDateByOne(Date d1) {
		return addDayOnDate(d1.year, d1.month, d1.day);
	}

	Date increaseDateByXDays(Date d1, int days) {

		Date date = d1;

		for (int i = 1;i <= days;i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByOneWeek(Date d1) {

		Date date = d1;

		for (int i = 1;i <= 7;i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByXWeeks(Date d1,int weeks) {

		Date date = d1;

		for (int i = 1;i <= weeks * 7;i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByOneMonth(Date d1) {

		Date date = d1;

		int monthDays = nbOfDaysInAMonth(d1.year, d1.month);

		for (int i = 1;i <= monthDays;i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByXMonths(Date d1,int months) {

		Date date = d1;
		int month = d1.month;
		int monthDays = 0;
		for (int i = 0;i < months;i++) {
			monthDays += nbOfDaysInAMonth(d1.year,month);
			if (month == 12)
				month = 1;
			month++;

		}


		for (int i = 1;i <= monthDays;i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByOneYear(Date d1) {

		Date date = d1;



		for (int i = 1;i <= nbOfDaysInAYear(d1.year);i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByXYears(Date d1,int years) {

		Date date = d1;

		int year = d1.year;
		int yearDays = 0;
		for (int i = 0;i < years;i++) {
			yearDays += nbOfDaysInAYear(++year);

		}

		for (int i = 1;i <=yearDays;i++) {
			date = addDayOnDate(date.year, date.month, date.day);
		}

		return date;

	}

	Date increaseDateByOneDecade(Date d1) {
		return increaseDateByXYears(d1, 10);
	}

	Date increaseDateByXDecades(Date d1,int decades) {
		return increaseDateByXYears(d1, 10 * decades);
	}

	Date increaseDateByOneCentury(Date d1) {
		return increaseDateByXYears(d1, 100);
	}

	Date increaseDateByOneMillenium(Date d1) {
		return increaseDateByXYears(d1, 1000);
	}


}

namespace DecreaseDates {

	using namespace Dates;

	Date decreaseDateByXMonths(Date d1, int months);
	Date decreaseDateByXYears(Date d1, int years);
	

	Date decreaseDateByOne(Date d1) {
		return minusDayOnDate(d1.year, d1.month, d1.day);
	}

	Date decreaseDateByXDays(Date d1, int days) {

		Date date = d1;

		for (int i = 1; i <= days; i++) {
			date = minusDayOnDate(date.year, date.month, date.day);
		}

		return date;
	}

	Date decreaseDateByOneWeek(Date d1) {
		return decreaseDateByXDays(d1, 7);
	}

	Date decreaseDateByXWeeks(Date d1, int weeks) {
		return decreaseDateByXDays(d1, weeks * 7);
	}

	Date decreaseDateByOneMonth(Date d1) {
		return decreaseDateByXMonths(d1, 1);
	}

	Date decreaseDateByXMonths(Date d1, int months) {

		int month = d1.month;
		int year = d1.year;
		int monthDays = 0;

		for (int i = 0; i < months; i++) {
			month--;
			if (month == 0) {
				month = 12;
				year--;
			}
			monthDays += nbOfDaysInAMonth(year, month);
		}

		return decreaseDateByXDays(d1, monthDays);
	}

	Date decreaseDateByOneYear(Date d1) {
		return decreaseDateByXYears(d1, 1);
	}

	Date decreaseDateByXYears(Date d1, int years) {

		Date date = d1;
		date.year -= years;

		int maxDay = nbOfDaysInAMonth(date.year, date.month);
		if (date.day > maxDay)
			date.day = maxDay;

		return date;
	}

	Date decreaseDateByOneDecade(Date d1) {
		return decreaseDateByXYears(d1, 10);
	}

	Date decreaseDateByXDecades(Date d1, int decades) {
		return decreaseDateByXYears(d1, 10 * decades);
	}

	Date decreaseDateByOneCentury(Date d1) {
		return decreaseDateByXYears(d1, 100);
	}

	Date decreaseDateByOneMillenium(Date d1) {
		return decreaseDateByXYears(d1, 1000);
	}

}

namespace DateDetails {
	using namespace Dates;

	bool isEndOfWeek(Date date) {

		int dayOrder = getDayOrder(date.year, date.month, date.day);

		return dayOrder == 0;
	}

	bool isWeekEnd(Date date) {

		int dayOrder = getDayOrder(date.year, date.month, date.day);

		return dayOrder == 0 || dayOrder == 6;
	}

	bool isBusinessDay(Date date) {

		return !isWeekEnd(date);
	}

	int daysUntilEndOfWeek(Date date) {
		return 6 - getDayOrder(date.year, date.month, date.day);
	}

	int daysUntilEndOfMonth(Date date) {
		return nbOfDaysInAMonth(date.year,date.month) - date.day;
	}

	int daysUntilEndOfYear(Date date) {
		return nbOfDaysInAYear(date.year) - getDaysFromBeginingOfTheYear(date.year,date.month,date.day);
	}

	int calculateVacationDays(Date from,Date to) {

		int daysCount = 0;
		Date temp1 = from;

		while (!isDate1EqualsDate2(from, to)) {
			if (!isWeekEnd(from))
				daysCount++;
			from = addDayOnDate(from.year, from.month, from.day);
		}

		return daysCount;

	}

	Date calculateVacationRetuenDate(Date from, int days) {

		int counter = 0;

		while (counter != days) {
			from = addDayOnDate(from.year, from.month, from.day);
			if (!isWeekEnd(from)) 
				counter++;
		}

		return from;

	}
}

namespace Periods {
	using namespace Dates;

	Period readPeriod() {

		Period p1;
		cout << "Enter Period Start" << endl;
		Date d1 = readDate();

		cout << "Enter Period End" << endl;
		Date d2 = readDate();

		p1.from = d1;
		p1.to = d2;
		return p1;
	}

	bool isOverlap(Period p1, Period p2) {
		if ((compareDates(p2.to, p1.from) == DatesComparison::BEFORE) || compareDates(p2.from, p1.to) == DatesComparison::AFTER)
			return false;
		return true;

	}

	int getPeriodDiffInDays(Period p1, bool includingEndDay = false) {

		return diffInDays(p1.from, p1.to, includingEndDay);

	}

	bool isDateInPeriod(Period p1, Date d1) {
		Period p2;
		p2.from = d1;
		p2.to = d1;
		return isOverlap(p1, p2);
	}

	int getOverLapDaysCount(Period p1, Period p2) {
		int overlapDays = 0;

		while (isOverlap(p1, p2)) {
			if (compareDates(p1.to, p2.from) == DatesComparison::BEFORE)
				p1.to = addDayOnDate(p1.to.year, p1.to.month, p1.to.day);
			else if (compareDates(p2.from, p1.to) == DatesComparison::BEFORE)
				p2.from = addDayOnDate(p2.from.year, p2.from.month, p2.from.day);
			else if (compareDates(p1.to, p2.from) == DatesComparison::EQUAL)
				break;
			overlapDays++;
		}
		return overlapDays;
	}
}