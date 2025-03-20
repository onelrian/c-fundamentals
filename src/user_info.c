#include <stdio.h>

struct stats {
    char surname[50];
    char firstname[50];
    char address[100];
};

struct birth {
    int year;
    int month;
    int day;
};

int main() {
    int user = 2;

    struct stats users[user];
    struct birth dates[user];

    for (int i = 0; i < user; i++) {
        printf("\nEnter details for user %d:\n", i + 1);

        printf("Enter your surname: ");
        scanf("%s", users[i].surname);

        printf("Enter your firstname: ");
        scanf("%s", users[i].firstname);

        printf("Enter your birth year: ");
        scanf("%d", &dates[i].year);

        printf("Enter your birth month: ");
        scanf("%d", &dates[i].month);

        printf("Enter your birth day: ");
        scanf("%d", &dates[i].day);

        printf("Enter your address: ");
        scanf(" %[^\n]", users[i].address); // Allows spaces in address
    }

    printf("\nThere are %d users. These are their stats:\n", user);
    printf("Surname\t\tFirstname\tBirth Date\tAddress\n");

    for (int i = 0; i < user; i++) {
        printf("%s\t\t%s\t\t%d-%02d-%02d\t%s\n",
               users[i].surname, users[i].firstname,
               dates[i].year, dates[i].month, dates[i].day,
               users[i].address);
    }

    for (int i = 0; i < user - 1; i++) {
        if (dates[i].year < dates[i + 1].year ||
            (dates[i].year == dates[i + 1].year && dates[i].month < dates[i + 1].month) ||
            (dates[i].year == dates[i + 1].year && dates[i].month == dates[i + 1].month && dates[i].day < dates[i + 1].day)) {
            printf("\n%s is older than %s.\n", users[i].firstname, users[i + 1].firstname);
        } else {
            printf("\n%s is older than %s.\n", users[i + 1].firstname, users[i].firstname);
        }
    }

    return 0;
}
