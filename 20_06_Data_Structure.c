#include<stdio.h>
#include<string.h>

void showWelcomeMessage();
void displayTitle(char* title);
void showGoodByeMessage();
int getTheChoice();
int getNumberOfElements();
int getSearchTargetValue();
void enterArrayElements(int n, int *numbers);
void linearSearch(int arr[], int n, int target_value);
void binarySearch(int arr[], int n, int target_value);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);

//ANSI escape sequences for text colors
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define RESET_COLOR "\033[0m"

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

                linearSearch(numbers, n, target_value);
                break;
            }
            case 2: {
                displayTitle("Binary Search Program");
                int n = getNumberOfElements();
                int numbers[n];
                printf(YELLOW_COLOR "Numbers must be entered in either Ascending or Descending order.\n" RESET_COLOR);
                enterArrayElements(n, numbers);
                int target_value = getSearchTargetValue();

                binarySearch(numbers, n, target_value);
                break;
            }
            case 3: {
                displayTitle("Bubble Sort Program");
                int n = getNumberOfElements();
                int numbers[n];
                enterArrayElements(n, numbers);

                bubbleSort(numbers, n);
                break;
            }
            case 4: {
                displayTitle("Insertion Sort Program");
                int n = getNumberOfElements();
                int numbers[n];
                enterArrayElements(n, numbers);

                insertionSort(numbers, n);
                break;
            }

            default:
                printf(RED_COLOR "\nInvalid choice. Please select a valid choice from the menu.\a\n" RESET_COLOR);
                break;

        }


        printf("\n");


    } while(choice != 0);



    return 0;
}

void showWelcomeMessage() {
    printf(GREEN_COLOR);
    printf("********************************************************************\n");
    printf("*            Welcome to Data Structure Programs Menu               *\n");
    printf("*                Student Name: Md. Zubaer Ahammed                  *\n");
    printf("*                    Student ID: 20052801006                       *\n");
    printf("********************************************************************\n");
    printf(RESET_COLOR);
}

void showGoodByeMessage() {
    printf(BLUE_COLOR);
    printf("+------------------------------------------------------------------+\n");
    printf("|                                                                  |\n");
    printf("|                           [0]  Good Bye!                         |\n");
    printf("|                                                                  |\n");
    printf("+------------------------------------------------------------------+\n");
    printf(RESET_COLOR);
}

int getTheChoice() {
    int choice;
    printf("\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   Program Options:                                               |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   0. End program                                                 |\n");
    printf("|   1. Linear Search                                               |\n");
    printf("|   2. Binary Search                                               |\n");
    printf("|   3. Bubble Sort                                                 |\n");
    printf("|   4. Insertion Sort                                              |\n");
    printf("+------------------------------------------------------------------+\n");

    printf(BLUE_COLOR "Enter your choice: " RESET_COLOR);
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

    printf("|  %s%s%s  |\n", BLUE_COLOR, title, RESET_COLOR);

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

void linearSearch(int arr[], int n, int target_value) {

    int match_found = 0;
    for(int i=0; i<n; i++) {
        //We are retruning all matches. So, we are not using break after first match is found.
        if(arr[i] == target_value) {
            match_found = 1;
            printf("%sThe target value %d is matched with element having index: %d%s\n", GREEN_COLOR, target_value, i, RESET_COLOR);
        }
    }

    if(!match_found) {
        printf("%s\nNo match found for search value: %d.%s\n", RED_COLOR, target_value, RESET_COLOR);
    }

}

void binarySearch(int arr[], int n, int target_value) {

    int left = 0;
    int right = n - 1;
    int found = 0;

    while(left <= right) {

        //int mid = left + (right - left) / 2; //preferred
        /* This will also work but the above is preferred because the above mid = left + (right - left) / 2 prefents integer overflow issues.
        In some programming language, if left and right are large integers adding them might exceed the maximum representable integer value causing overlow
        and unexpected behaviour. Both above and below equation are the same but in case of mid = (left+right)/2 the program
        calculates (left+right) first and then devide by 2 hence there is a possibility of overflow. But if we do mid = left + (right - left)/2
        then we are doing (right - left) first; device by 2 and then adding with left hence the possibility of overflow is less.*/

        int mid = (left + right) / 2; //Not preferred

        if(arr[mid] == target_value) {
            printf(GREEN_COLOR "Element %d is found at index: %d" RESET_COLOR, target_value, mid);
            found = 1;
            break;
        } else if(arr[mid] < target_value) {
            left = mid+1;
        } else if(arr[mid] > target_value) {
            right = mid -1;
        }

    }

    if(found == 0) {
        printf(RED_COLOR "Element %d is not found the array." RESET_COLOR, target_value);
    }

}

void bubbleSort(int arr[], int n) {

    printf("\n%sThe numbers before sorting: %s", GREEN_COLOR, RESET_COLOR);
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n%sBelow are the bubble sorting steps: %s\n", BLUE_COLOR, RESET_COLOR);

    int temp;
    /* n-1 because we need to go upto the n-1 th element
    and check with the last elment with j and j+1 */
    for(int i=0; i<n-1; i++) {
        int swapped = 0;
        /* n-i-1 because the last element is sorted with each outer loop completed
        and we don't need to check it for the next iterations */
        for(int j=0; j<n-i-1; j++) {

            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;

                printf("Swapping %d with %d\n", arr[j], arr[j+1]);

            }
        }

        /*If no element was swapped in the inner loop then
         no more elements to sort, so break */
        if(swapped == 0) {
            break;
        }
    }

    printf("\n%sThe numbers after sorting(ASC): %s", GREEN_COLOR, RESET_COLOR);
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void insertionSort(int arr[], int n) {
    //Do insertionSort
    printf("Program is yet to be implemented.");

}
