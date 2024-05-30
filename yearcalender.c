  #include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31; // January
        case 2: return isLeapYear(year) ? 29 : 28; // February
        case 3: return 31; // March
        case 4: return 30; // April
        case 5: return 31; // May
        case 6: return 30; // June
        case 7: return 31; // July
        case 8: return 31; // August
        case 9: return 30; // September
        case 10: return 31; // October
        case 11: return 30; // November
        case 12: return 31; // December
        default: return 0;
    }
}

// Function to get the day of the week for the first day of the year
int getFirstDayOfYear(int year) {
    int day = 1;
    int month = 1;
    int k = year % 100;
    int j = year / 100;
    int h = day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    return (h + 5) % 7; // Adjusting to get Sunday as 0
}

// Function to print the calendar for a given year
void printCalendar(int year) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInWeek[] = {0, 1, 2, 3, 4, 5, 6}; // Sunday to Saturday
    int firstDay = getFirstDayOfYear(year);
    int daysInMonth;

    for (int month = 1; month <= 12; month++) {
        daysInMonth = getDaysInMonth(month, year);
        printf("\n  ------------%s-------------\n", months[month - 1]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces
        for (int k = 0; k < firstDay; k++) {
            printf("     ");
        }

        // Print all days of the month
        for (int day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            if (++firstDay > 6) {
                firstDay = 0;
                printf("\n");
            }
        }

        if (firstDay != 0) {
            printf("\n");
        }
    }
}

int main() {
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    printCalendar(year);
    return 0;
}
