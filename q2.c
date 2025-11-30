#include <stdio.h>
#include <string.h>

struct Transaction {
    char type[20];
    float amount;
};

struct BankAccount {
    char name[50];
    int accountNumber;
    char accountType[20];
    float balance;
    struct Transaction history[50];
    int transactionCount;
};

float getMinBalance(char type[]) {
    if(strcmp(type, "Savings") == 0) return 1000;
    if(strcmp(type, "Current") == 0) return 5000;
    if(strcmp(type, "Fixed") == 0) return 10000;
    return 0;
}

float getInterestRate(char type[]) {
    if(strcmp(type, "Savings") == 0) return 4;
    if(strcmp(type, "Current") == 0) return 0;
    if(strcmp(type, "Fixed") == 0) return 7;
    return 0;
}

void deposit(struct BankAccount acc[], int i, float amount) {
    acc[i].balance += amount;
    strcpy(acc[i].history[acc[i].transactionCount].type, "Deposit");
    acc[i].history[acc[i].transactionCount].amount = amount;
    acc[i].transactionCount++;
}

void withdraw(struct BankAccount acc[], int i, float amount) {
    float minBal = getMinBalance(acc[i].accountType);
    if(acc[i].balance - amount < minBal) {
        printf("Withdrawal denied: Minimum balance limit\n");
        return;
    }
    acc[i].balance -= amount;
    strcpy(acc[i].history[acc[i].transactionCount].type, "Withdrawal");
    acc[i].history[acc[i].transactionCount].amount = amount;
    acc[i].transactionCount++;
}

void displayAccount(struct BankAccount acc) {
    printf("Name: %s\n", acc.name);
    printf("Account No: %d\n", acc.accountNumber);
    printf("Type: %s\n", acc.accountType);
    printf("Balance: %.2f\n", acc.balance);
}

void displayHistory(struct BankAccount acc) {
    for(int i = 0; i < acc.transactionCount; i++) {
        printf("%s - %.2f\n", acc.history[i].type, acc.history[i].amount);
    }
}

int main() {
    struct BankAccount acc;

    strcpy(acc.name, "Ahmed");
    acc.accountNumber = 12345;
    strcpy(acc.accountType, "Savings");
    acc.balance = 1500;
    acc.transactionCount = 0;
    deposit(&acc, 0, 500);     
    withdraw(&acc, 0, 200);
    withdraw(&acc, 0, 900);

    displayAccount(acc);
    printf("\nTransaction History:\n");
    displayHistory(acc);

    printf("\nInterest Rate: %.2f%%\n", getInterestRate(acc.accountType));

    return 0;
}
