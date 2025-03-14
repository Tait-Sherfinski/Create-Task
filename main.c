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

void removeExpense(char *name) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(allExpenses[i].name, name) == 0) {
            for  (int j = i; j < itemCount; j++) {
                allExpenses[j] = allExpenses[j + 1];
            }
            itemCount--;
            printf("%s has been removed", name);
            return;
        }
    } printf("Item not found");
}

void showList() {
    for (int i = 0; i < itemCount; i++) {
        printf("\n%s %.2f\n", allExpenses[i].name, allExpenses[i].price);
    }
}

void calculateNetEarnings(float income) {
    float totalSpending;
    for (int i = 0; i < itemCount; i++) {
        totalSpending += allExpenses[i].price;
    } 
    float net = income - totalSpending;
    printf("\nNet Earnings: $%.2f\n", net);
}

int main() {
    int choice;
    float income;
    char name[50];
    float price;

    printf("Enter income for the month: ");
    scanf("%f", &income);

    while (income > 0) {
        printf("\n1: Add Expense");
        printf("\n2: Remove Expense");
        printf("\n3: Show list of expenses");
        printf("\n4: Show Net Earnings");
        printf("\n5: Exit");
        printf("\nEnter choice(number): ");
        scanf("%d", &choice);

        while (choice != 5) {
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
                printf("\nName of expense: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                removeExpense(name);
                break;
            }
            if (choice == 3) {
                showList();
                break;
            }
            if (choice == 4) {
                calculateNetEarnings(income);
                break;
            }
        }
        if (choice == 5) {
            printf("Program closed");
            break;
        }
    } 
}