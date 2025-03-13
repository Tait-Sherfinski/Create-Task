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

void calculateNetEarnings(float income) {
    float totalSpending;
    for (int i = 0; i < itemCount; i++) {
        totalSpending += allExpenses[i].price;
    } 
    float net = income - totalSpending;
    printf("\nNet Earnings: %.2f\n", net);
}

int main() {
    int choice;
    float income;
    char name[50];
    float price;

    printf("Enter income for the month: ");
    scanf("%f", &income);

    while (income > 0) {
        printf("\n1. Add Expense");
        printf("\n2. Show Net Earnings");
        printf("\n3. Exit");
        printf("\nEnter choice(number): ");
        scanf("%d", &choice);

        while (choice != 3) {
            if (choice == 1) {
                printf("\nEnter name of item/expense: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("\nEnter price of item/expense: ");
                if (scanf("%f", &price) != 1) {
                    printf("Invalid price\n");
                    while (getchar() != '\n');
                    break;
                }
                addExpense(name, price);
                break;
            }
            if (choice == 2) {
                calculateNetEarnings(income);
                break;
            }
        }
    } 
}