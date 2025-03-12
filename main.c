// Monthly Budget Planner

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} List;

List allExpenses[MAX_ITEMS];
int itemCount = 0;

void addExpense(char *name, float price) {
    if (itemCount < MAX_ITEMS) {
        strcpy(allExpenses[itemCount].name, name);
        allExpenses[itemCount].price = price;
        itemCount++;
    } else printf("List is full");
}

int calculateNetEarnings(float income) {
    float totalSpending;
    if (itemCount == 0) printf("Please add an expense first.");
    else {
        for (int i = 0; i < itemCount; i++) {
            totalSpending += allExpenses[itemCount].price;
        }
        printf("Net Earnings: %f", income - totalSpending);
    }
}

int main() {
    int choice;
    float income;
    char name[50];
    float price;

    printf("Enter income for the month: ");
    scanf("%f", &income);

    do {
        printf("\n1. Add Expense");
        printf("\n2. Calculate Net Earnings");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        while (choice != 3) {
            if (choice == 1) {
                printf("\nEnter name of item/expense: ");
                scanf("%d", &name);
                printf("\nEnter price of item/expense: ");
                scanf("%f", &price);
                break;
            }
            if (choice == 2) {
                calculateNetEarnings(income);
                break;
            }
        }
    } while (income > 0);
    return 0;
}