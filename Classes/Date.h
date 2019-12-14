/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: declare the auxiliary class for the project named date
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#ifndef OOP_2ND_COURSE_1LAB_DATE_H
#define OOP_2ND_COURSE_1LAB_DATE_H

/**
 * This structure used to show and save the Date. Used in Book structure. Variables are public for the comfort access.
 */
class Date {
public:

    Date();

    int year;
    int month;
    long int day;

    /**
     * This function calculates the distance between two dates
     *
     * @param in the date to calculate the distance between
     * @return the distance between the dates in days
     */
    long int days_passed(Date in);

    /**
     * This function sets data to the current time
     */
    void to_current_date();

    /**
     * This function just print the year, month and day of the Date
     */
    void print();

    /**
     * This function return all time spent in days
     *
     * @return all time spent
     */
    long int to_days();
};

#endif //OOP_2ND_COURSE_1LAB_DATE_H
