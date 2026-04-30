#include <stdio.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};

int getDaysInMonth(int month, int year) {

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
        return 31;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        else
            return 28;
    }

    return 30;
}

struct Date calculateAge(struct Date dob) {

    struct Date currentDate;
    struct Date age;

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    currentDate.day = tm_info->tm_mday;
    currentDate.month = tm_info->tm_mon + 1;
    currentDate.year = tm_info->tm_year + 1900;

    age.day = currentDate.day - dob.day;
    age.month = currentDate.month - dob.month;
    age.year = currentDate.year - dob.year;

    if (age.day < 0) {

        currentDate.month = currentDate.month - 1;

        if (currentDate.month == 0) {
            currentDate.month = 12;
            currentDate.year = currentDate.year - 1;
        }

        int daysInPrevMonth = getDaysInMonth(currentDate.month, currentDate.year);

        age.day = age.day + daysInPrevMonth;
        age.month = age.month - 1;
    }

    if (age.month < 0) {
        age.month = age.month + 12;
        age.year = age.year - 1;
    }

    return age;
}

int main() {

    struct Date dob;
    struct Date age;

    printf("Enter day of birth: ");
    scanf("%d", &dob.day);

    printf("Enter month of birth: ");
    scanf("%d", &dob.month);

    printf("Enter year of birth: ");
    scanf("%d", &dob.year);

    age = calculateAge(dob);

    printf("Age: %d years, %d months, %d days\n", age.year, age.month, age.day);

    return 0;
}