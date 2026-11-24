#include <stdio.h>
struct Expense {
    char name[50];
    float price;
};
void showStatus(float budget, float remaining) {
    float percentage;
    percentage = (remaining / budget) * 100;
    printf("\n----------- BUDGET STATUS ---------\n");

    if (remaining < 0) {
        printf("Budget berry loww!\n");
        printf("You overspent by Rs. %.2f\n", -remaining);
    }
    else if (remaining == 0) {
        printf("Budget finished!\n");
        printf("No money is left for this month.\n");
    }
    else if (percentage <= 25) {
        printf("WARNING..Your budget is ending!\n");
        printf("Spend your remaining money carefully.\n");
    }
    else if (percentage <= 50) {
        printf("CAUTION..Your budget is getting low.\n");
        printf("Keep an eye on your expenses.\n");
    }
    else {
        printf("GOOD: Your budget is under control.\n");
        printf("You are managing your money well.\n");
    }
}

void showExpenses(struct Expense e[], int n) {
    int i;

    printf("\n============================================\n");
    printf("               EXPENSE TABLE\n");
    printf("============================================\n");

    printf("%-5s %-20s %-12s\n",
           "No.", "Expense Name", "Price");

    printf("--------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-20s Rs. %-8.2f\n",
               i + 1,
               e[i].name,
               e[i].price);
    }

    printf("--------------------------------------------\n");
}

int main() {
    struct Expense expenses[100];

    float budget;
    float total = 0;
    float remaining;

    int numberOfExpenses;
    int i;

    printf("============================================\n");
    printf("          PERSONAL EXPENSE TRACKER\n");
    printf("============================================\n");


    printf("\nEnter your monthly budget: Rs. ");
    scanf("%f", &budget);

    while (budget <= 0) {
        printf("Budget must be greater than 0.\n");
        printf("Enter your monthly budget again: Rs. ");
        scanf("%f", &budget);
    }

    printf("\nEnter number of expenses: ");
    scanf("%d", &numberOfExpenses);

    while (numberOfExpenses <= 0 ||
           numberOfExpenses > 100) {

        printf("Enter expenses between 1 and 100.\n");
        printf("Enter number of expenses again: ");
        scanf("%d", &numberOfExpenses);
    }

    for (i = 0; i < numberOfExpenses; i++) {

        printf("\n========== EXPENSE %d ==========\n",
               i + 1);

        printf("Enter expense name: ");
        scanf(" %[^\n]", expenses[i].name);

        printf("Enter expense price: Rs. ");
        scanf("%f", &expenses[i].price);

        while (expenses[i].price < 0) {
            printf("Price cannot be negative.\n");
            printf("Enter price again: Rs. ");
            scanf("%f", &expenses[i].price);
        }

        total = total + expenses[i].price;

        printf("Expense added successfully!\n");
    }


    remaining = budget - total;

    showExpenses(expenses, numberOfExpenses);


    printf("\n============================================\n");
    printf("               MONTHLY REPORT\n");
    printf("============================================\n");

    printf("Monthly Budget   : Rs. %.2f\n",
           budget);

    printf("Total Expenses   : Rs. %.2f\n",
           total);

    printf("Budget Remaining : Rs. %.2f\n",
           remaining);

    printf("Number Expenses  : %d\n",
           numberOfExpenses);


    showStatus(budget, remaining);

    printf("\n============================================\n");
    printf("             END OF REPORT\n");
    printf("============================================\n");

    return 0;
}