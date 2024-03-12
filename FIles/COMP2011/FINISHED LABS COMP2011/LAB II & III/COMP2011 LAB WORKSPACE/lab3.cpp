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
int get_anchor_century(int year)
{
    int anchor[4]{2,0,5,3};
    int c = year /100;
    int x = c % 4; 
    
    int anchor_century = anchor[x];

    return anchor_century;

}

// Task 4
// return the weekday after offset
int offset_weekday(int a, int b)
{
    int temporary = (a + b)%7;

    return temporary;

}

// Task 5
// return the anchor day of a year (the weekday of doomsdays)
int get_anchor_year(int year, int anchor_century)
{
    int cad = get_anchor_century(year);
    int y1 = year%100;
    int y2 = y1%12;
    int y3 = y1/12;
    int y4 = y2/4;

    int anchor_day_of_year = (cad + y2 + y3 + y4)%7;
    return anchor_day_of_year;

}   

// Task 6
// return the doomsday in a month
int get_doomsday(int year, int month)
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

    else if( month == 4 )
    {
        return 4;
    }
    else if( month == 6 )
    {
        return 6;
    }
    else if( month == 8 )
    {
        return 8;
    }
    else if( month == 10 )
    {
        return 10;
    }
    else if( month == 12 )
    {
        return 12;
    }
    else if( month == 5 )
    {
        return 9;
    }
    else if( month == 9 )
    {
        return 5;
    }
    else if( month == 7 )
    {
        return 11;
    }
    else if( month == 11 )
    {
        return 7;
    }
    else if(month == 1)
    {
        if((year%400 == 0 ) || ((year%4 == 0) && (year%100!=0)))
            return 4;

        else
        {
            return 3;
        }
        
    }
    else
    {
        if((year%400 == 0 ) || ((year%4 == 0) && (year%100!=0)))
            return 29;

        else
        {
            return 28;
        }
    }

}

// Task 7
// return the weekday of a date
int get_weekday(int year, int month, int day)
{

    int a1 = get_anchor_century(year);
    int a2 = get_anchor_year(year,a1);
    int doomsday = get_doomsday(year,month);
    return offset_weekday(a2,(day-doomsday));
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
    for (int i = 0; i < weekday; ++i) {
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

     if(is_leap_year(year))
        cout<<year <<" is a leap year! "<<endl;

    else 
        cout<<year <<" is not a leap year!"<<endl;


    
    cout<<"The no of days in said month is: "<<get_num_month_days(year,month)<<endl;

    cout<<"The anchor day of the century based on the input year is: "<< get_anchor_century(year)<<endl;

    cout<<"The anchor day of the year in the century based on input year is: "<<get_anchor_year(year,get_anchor_century(year))<<endl;

    cout<<"The doomsday of the month is: "<<get_doomsday(year, month)<<endl;

    cout<<"The weekday of the date is: "<<get_weekday(year,month,day)<<endl;






    return 0;
}