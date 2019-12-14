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
