#include<stdio.h>
#include<string.h>

void showWelcomeMessage();
void displayTitle(char* title);
void showGoodByeMessage();
int getTheChoice();
int getNumberOfElements();
int getSearchTargetValue();
void enterArrayElements(int n, int *numbers);
void linearSearch(int arr[], int target_value);
void binarySearch(int arr[], int target_value);
void bubbleSort(int arr[]);
void insertionSort(int arr[]);

int main() {

    int choice;

    showWelcomeMessage();

    do {

        choice = getTheChoice();

        switch(choice) {

            case 0:
                showGoodByeMessage();
                break;

            case 1: {
                displayTitle("Linear Search Program");
                int n = getNumberOfElements();
                int numbers[n];
                enterArrayElements(n, numbers);
                int target_value = getSearchTargetValue();

                linearSearch(numbers, target_value);
                break;
            }
            case 2: {
                displayTitle("Binary Search Program");
                int n = getNumberOfElements();
                int numbers[n];
                enterArrayElements(n, numbers);
                int target_value = getSearchTargetValue();

                binarySearch(numbers, target_value);
                break;
            }
            case 3: {
                displayTitle("Bubble Sort Program");
                int n = getNumberOfElements();
                int numbers[n];
                enterArrayElements(n, numbers);
                int target_value = getSearchTargetValue();

                bubbleSort(numbers);
                break;
            }
            case 4: {
                displayTitle("Insertion Sort Program");
                int n = getNumberOfElements();
                int numbers[n];
                enterArrayElements(n, numbers);
                int target_value = getSearchTargetValue();

                insertionSort(numbers);
                break;
            }

            default:
                printf("\nInvalid choice. Please select a valid choice from the menu.\n");
                break;

        }


        printf("\n");


    } while(choice != 0);



    return 0;
}

void showWelcomeMessage() {
    printf("********************************************************************\n");
    printf("*            Welcome to Data Structure Programs Menu               *\n");
    printf("*                Student Name: Md. Zubaer Ahammed                  *\n");
    printf("*                    Student ID: 20052801006                       *\n");
    printf("********************************************************************\n");
}

void showGoodByeMessage() {
    printf("+------------------------------------------------------------------+\n");
    printf("|                                                                  |\n");
    printf("|                           [0]  Good Bye!                         |\n");
    printf("|                                                                  |\n");
    printf("+------------------------------------------------------------------+\n");
}

int getTheChoice() {
    int choice;
    printf("+------------------------------------------------------------------+\n");
    printf("|   Program Options:                                               |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   0. End program                                                 |\n");
    printf("|   1. Linear Search                                               |\n");
    printf("|   2. Binary Search                                               |\n");
    printf("|   3. Bubble Sort                                                 |\n");
    printf("|   4. Insertion Sort                                              |\n");
    printf("+------------------------------------------------------------------+\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void displayTitle(char* title) {
    int titleLength = strlen(title);

    printf("+");
    for (int i = 0; i < titleLength + 4; ++i) {
        printf("-");
    }
    printf("+\n");

    printf("|  %s  |\n", title);

    printf("+");
    for (int i = 0; i < titleLength + 4; ++i) {
        printf("-");
    }
    printf("+\n");
}

int getNumberOfElements() {
    int n;
    printf("Please enter the number of elements in the array: ");
    scanf("%d", &n);
    return n;
}

int getSearchTargetValue() {
    int target_value;
    printf("Enter the target search value: ");
    scanf("%d", &target_value);
    return target_value;
}

void enterArrayElements(int n, int *numbers) {
    printf("Enter the numbers: \n");
    for(int i=0; i<n; i++) {
        printf("Index[%d]: ", i);
        scanf("%d", &numbers[i]);
    }
}

void linearSearch(int arr[], int target_value) {
    //Do linearSearch
}

void binarySearch(int arr[], int target_value) {
    //Do binarySearch
}

void bubbleSort(int arr[]) {
    //Do bubbleSort
}

void insertionSort(int arr[]) {
    //Do insertionSort
}
