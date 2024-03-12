#include <iostream>
#include <cmath>

using namespace std;


// Task 1
// determine whether a year is a leap year
bool is_leap_year(int year)
{
   if (year % 4 == 0)
        return true;

   else 
        return false;

}

// Task 2 
// return number of days in a month
int get_num_month_days(int year, int month)
{
    //check for feb
    if (month == 2 )
    {
        if((year%400 == 0 ) || ((year%4 == 0) && (year%100!=0)))
            return 29;
        else
            return 28;
    }

    ///checking other months
    //checking for months that are odd

    else if(month ==1 || month == 3 || month == 5 || month == 7 || month == 8 ||  month == 10 || month == 12)
    {
        return 31;
    }

    //checking for months that are even 
    else
    {
        return 30;

    }


}

// Task 3
// return the anchor day of a century
//assuming player enters only a positive value over 
int get_anchor_century(int year)
{
    int anchor[4]{2,0,5,3};
    int c = year /100;
    int x = c % 4; 

    return anchor[x];
}

// Task 4
// return the weekday after offset
int offset_weekday(int weekday, int offset)
{

}

// Task 5
// return the anchor day of a year (the weekday of doomsdays)
int get_anchor_year(int year, int anchor_century)
{
    int anchor[4]{2,0,5,3};
    int y = year % 100;
    int y12 = y / 12;
    int yr = y % 12;
    int yr4 = yr % 4;
    int yrly = yr / 4;

    return (y12 + yr)
}

// Task 6
// return the doomsday in a month
int get_doomsday(int year, int month)
{

}

// Task 7
// return the weekday of a date
int get_weekday(int year, int month, int day)
{
    int y = year % 100;
    int y12 = y / 12;
    int yr = y % 12;
    int yr4 = yr % 4;

    return (y12 + yr + yr4 + get_anchor_century(year)) % 7 -1;

}

// print the calendar of the month containing the date
void print_calendar(int year, int month, int day)
{
    // print title
    cout << "==========================================================" << endl;
    cout << "Doomsday Calendar, in memorial of John Conway (1937-2020)." << endl;
    cout << "==========================================================" << endl;
    cout << "\t\t\t" <<year << "-" << month << endl;
    cout << "Sun\tMon\tTus\tWed\tThu\tFri\tSat" << endl;
    // print blank spaces
    int weekday = get_weekday(year, month, 1);
    for (int i = 0; i < weekday; i++) {
        cout << "\t";
    }
    // print dates
    int num_month_days = get_num_month_days(year, month);
    for (int date = 1; date <= num_month_days; date++) {
        // print date
        cout << date;
        if (date == day) cout << "*";
        // formating
        if (date < num_month_days) {
            if (weekday == 6) cout << endl;
            else cout << "\t";
        }
        else cout << endl;
        // update weekday
        weekday = offset_weekday(weekday, 1);
    }
    cout << "==========================================================" << endl;
}

int main()
{
    int year, month, day;
    cout << "Please input the date ('year month day'): ";
    cin >> year >> month >> day;
    print_calendar(year, month, day);

    /// Leap Year or Non-Leap Year
    if(is_leap_year(year))
        cout<<year <<" is a leap year! "<<endl;

    else 
        cout<<year <<" is not a leap year!"<<endl;

    ///How many days in said month?
    cout<<(get_num_month_days(year,month))<<endl;


    ///Returned Number for that century:
    //2 for Tuesdays
    //0 Sundays 
    //5 Fridays
    //3 Wednesdays 

    cout<<get_anchor_century(year)<<endl;

    cout<<get_weekday(year,month,day)<<endl;

 




    return 0;
}