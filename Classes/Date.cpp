/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: define the auxiliary class for the project named date
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#include <iostream>
#include <windows.h>
#include "Date.h"

using namespace std;

Date :: Date() {
    year = 2000;
    month = 1;
    day = 1;
}

Date :: Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

/**
 * This function calculates the distance between two dates
 *
 * @param in the date to calculate the distance between
 * @return the distance between the dates in days
 */
long int Date::days_passed(Date in) {

    Date temp;
    temp.day = to_days();
    in.day = in.to_days();
    if (in.to_days() >= to_days())
        return in.to_days() - to_days();
    else
        return to_days() - in.to_days();

}

/**
 * This function sets data to the current time
 */
void Date::to_current_date() {

    SYSTEMTIME st;
    GetSystemTime(&st);
    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;
}

/**
 * This function just print the year, month and day of the Date
 */
void Date::print() {

    cout << "Year: " << year << " Month: " << month << " Day: " << day << endl;
}

/**
 * This function return all time spent in days
 *
 * @return all time spent
 */
long int Date::to_days() {

    long int temp = year * 365 + month * 30.5 + year / 4;
    return temp;
}

/**
 * This function converts date to the string
 *
 * @return the string format of the date
 */
string Date::tostr()
{
    string out;
    out = std::to_string(year);
    string temp = std::to_string(month);
    out = out + "/" + temp;
    temp = std::to_string(day);
    out = out+ "/" + temp;
    return out;
}

/**
* Overloading of the operator ">="
*
* @param left The parameter that would be passed on the left of the ">="
* @param right The parameter that would be passed on the right of the ">="
* @return The bool value that define the answer of the operator ">="
 */
bool operator >= (Date left, Date right){
    if (left.year != right.year)
        return left.year >= right.year;

    if(left.month != right.month)
        return left.month >= right.month;

    return left.day >= right.day;
}
