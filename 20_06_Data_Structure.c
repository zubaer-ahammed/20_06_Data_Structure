#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

void showWelcomeMessage();
void showGoodByeMessage();
void displayTitle(char* title);
void printNumbersArray(int numbers[], int n);
int getTheChoice();
int getNumberOfElements();
int getANumber(char *title, bool positive_only);
int getSearchTargetValue();
void enterArrayElements(int n, int *numbers);
void linearSearch(int arr[], int n, int target_value);
void binarySearch(int arr[], int n, int target_value);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
long double factorial(int n);
long long int fibonacchi(int n);
void tower_of_hanoi(int n, char A, char B, char C);

//Stack operations
void stack_operations(int size);
int getTheChoiceForStack();
bool stack_push(int *stack_arr, int data);
int stack_pop(int *stack_arr);
int stack_peek(int *stack_arr);
void stack_print(int *stack_arr);
int stackIsEmpty();
int stackIsFull();
int stack_top = -1;
int stack_maxsize = 10;

//Queue operations
void queue_operations(int size);
int getTheChoiceForQueue();
bool queue_enqueue(int *queue_arr, int data);
int queue_dequeue(int *queue_arr);
int queue_peek(int *queue_arr);
void queue_print(int *queue_arr);
int queueIsFull();
int queueIsEmpty();
int queue_front = -1;
int queue_rear = -1;
int queue_maxsize = 10;


//ANSI escape sequences for text colors
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define RESET_COLOR "\033[0m"
#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"


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
            case 5: {
                displayTitle("Factorial Of a Number");
                int n = getANumber("Please enter a number", true);
                long double fact = factorial(n);

                printf(GREEN_COLOR "\nThe factorial of %d is = %.Lf\n" RESET_COLOR, n, fact);

                break;
            }
            case 6: {
                displayTitle("Fibonacci series print");
                int n = getANumber("Please enter a the number of terms", true);
                printf(GREEN_COLOR "\nFibonacchi series upto %d terms: " RESET_COLOR, n);
                for(int i=0; i<n; i++) {
                    printf("%llu ", fibonacchi(i));
                }

                break;
            }
            case 7: {
                displayTitle("Tower of Hanoi");
                int n = getANumber("Please enter the number of discs", true);
                int num_moves = pow(2, n) - 1;
                printf(BLUE_COLOR "\nPlease perform the following %d disc movements: \n" RESET_COLOR, num_moves);
                tower_of_hanoi(n, 'A', 'B', 'C');

                break;
            }

            case 8: {
                displayTitle("Stack Operations");
                int n = getANumber("Please enter the maximum size of the stack", true);
                printf("Number = %d", n);
                stack_operations(n);

                break;
            }

            case 9: {
                displayTitle("Queue Operations");
                int n = getANumber("Please enter the maximum size of the queue", true);
                queue_operations(n);

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

void printNumbersArray(int numbers[], int n) {
    printf("[ ");
    for(int i=0; i<n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("]");
}

int getTheChoice() {
    int choice;
    printf("\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   Program Options:                                               |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   0. End program      6. Fibonacci series                        |\n");
    printf("|   1. Linear Search    7. Tower of Hanoi                          |\n");
    printf("|   2. Binary Search    8. Stack Operations                        |\n");
    printf("|   3. Bubble Sort      9. Queue Operations                        |\n");
    printf("|   4. Insertion Sort                                              |\n");
    printf("|   5. Factorial                                                   |\n");
    printf("+------------------------------------------------------------------+\n");

    printf(BLUE_COLOR "Enter your choice: " RESET_COLOR);
    scanf("%d", &choice);
    return choice;
}

int getTheChoiceForStack() {
    int choice;
    printf("\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   Stack Options:                                               |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   1. Push         6. Print all elements                          |\n");
    printf("|   2. Pop          7. Quit (Back to the Main Menu)                |\n");
    printf("|   3. Peek                                                        |\n");
    printf("|   4. isEmpty                                                     |\n");
    printf("|   5. isFull                                                      |\n");
    printf("+------------------------------------------------------------------+\n");

    printf(BLUE_COLOR "Enter your choice: " RESET_COLOR);
    scanf("%d", &choice);
    return choice;
}

int getTheChoiceForQueue() {
    int choice;
    printf("\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   Queue Options:                                               |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|   1. Enqueue         6. Print all elements                       |\n");
    printf("|   2. Dequeue         7. Quit (Back to the Main Menu)             |\n");
    printf("|   3. Peek                                                        |\n");
    printf("|   4. isEmpty                                                     |\n");
    printf("|   5. isFull                                                      |\n");
    printf("+------------------------------------------------------------------+\n");

    printf(BLUE_COLOR "Enter your choice: " RESET_COLOR);
    scanf("%d", &choice);
    return choice;
}

int getNumberOfElements() {
    int n;
    printf(BLUE_COLOR "Please enter the number of elements in the array: " RESET_COLOR);
    scanf("%d", &n);
    return n;
}

int getSearchTargetValue() {
    int target_value;
    printf(BLUE_COLOR "Enter the target search value: " RESET_COLOR);
    scanf("%d", &target_value);
    return target_value;
}

int getANumber(char *title, bool positive_only) {
    int n;
    printf(BLUE_COLOR "%s: "RESET_COLOR, title);
    scanf("%d", &n);
    if(positive_only && n<0) {
        printf(RED_COLOR "\nPlease enter a positive number only.\n\n" RESET_COLOR);
        n = getANumber(title, positive_only);
    }
    return n;
}

void enterArrayElements(int n, int *numbers) {
    printf(BLUE_COLOR "Enter the numbers: \n" RESET_COLOR);
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
            printf("%s\nThe target value %d is matched with element having index: %d%s\n", GREEN_COLOR, target_value, i, RESET_COLOR);
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
            printf(GREEN_COLOR "\nElement %d is found at index: %d" RESET_COLOR, target_value, mid);
            found = 1;
            break;
        } else if(arr[mid] < target_value) {
            left = mid+1;
        } else if(arr[mid] > target_value) {
            right = mid -1;
        }

    }

    if(found == 0) {
        printf(RED_COLOR "\nElement %d is not found the array." RESET_COLOR, target_value);
    }

}

void bubbleSort(int arr[], int n) {

    printf("\n%sThe numbers before sorting: %s", GREEN_COLOR, RESET_COLOR);
    printNumbersArray(arr, n);

    printf("\n\n%sBelow are the bubble sorting steps: %s\n", BLUE_COLOR, RESET_COLOR);

    int temp;
    /* n-1 because we need to go upto the n-1 th element
    and check with the last elment with j and j+1 */
    for(int i=0; i<n-1; i++) {
        int swapped = 0;
        /* n-i-1 because the last element is sorted with each outer loop completed
        and we don't need to check it for the next iterations */

        printf(BLUE_COLOR "Step %d: Swappings\n" RESET_COLOR, i+1);

        for(int j=0; j<n-i-1; j++) {

            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;

                printf("    Swapping %d with %d\n", arr[j], arr[j+1]);

            }
        }

        /*If no element was swapped in the inner loop then
         no more elements to sort, so break */
        if(swapped == 0) {
            break;
        }
    }

    printf("\n%sThe numbers after sorting(ASC): %s", GREEN_COLOR, RESET_COLOR);
    printNumbersArray(arr, n);
    printf("\n");

}

void insertionSort(int arr[], int n) {

    int temp, key;

    printf(GREEN_COLOR "\nGiven array: " BLUE_COLOR);
    printNumbersArray(arr, n);

    printf(BLUE_COLOR "\n\nInsertion Sorting steps: \n" RESET_COLOR);

    for(int i=1; i<n; i++) {

        key = arr[i];

        // Using coremen book's insertion sort algorithm
        /*
        int j = i-1;
        while(j>=0 && arr[j]>key) {

            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
        */

        //Using my own algorithm
        for(int j=i-1, k=i; j>=0 && arr[j]>key; j--, k--) {
            //Swap elements
            temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
        }

        printf("Step %d: array after i=%d outer loop iteration: ", i, i);
        printNumbersArray(arr, n);
        printf("\n");

    }

    printf(GREEN_COLOR "\nFinal array after insertion sorting: " RESET_COLOR);
    printNumbersArray(arr, n);

}

long double factorial(int n) {

    if( n == 0 ) {

        return 1;

    } else {

        return n * factorial(n-1);
    }
}

long long int fibonacchi(int n) {

    if( n <= 1 ) {
        return n;
    } else {
        return fibonacchi(n-1)+fibonacchi(n-2);
    }

}

void tower_of_hanoi(int n, char A, char B, char C) {

    if(n>0) {

        tower_of_hanoi(n-1, A, C, B);
        printf("Move disc from %c to %c\n", A, C);
        tower_of_hanoi(n-1, B, A, C);

    }
}

//Stack Operations
bool stack_push(int *stack_arr, int data) {
   if(stackIsFull()) {
       printf(RED_COLOR "Stack overflow.\n" RESET_COLOR);
       return false;
   }
   stack_top++;
   stack_arr[stack_top] = data;
   return true;
}

int stack_pop(int *stack_arr) {

   int value;
    if(stackIsEmpty()) {
        printf(RED_COLOR "Stack underflow.\n" RESET_COLOR);
        return -1;
    }

    value = stack_arr[stack_top];
    stack_top--;
    return value;

}

int stackIsEmpty() {
    if(stack_top == -1) {
        return 1;
    } else {
        return 0;
    }

}

int stackIsFull() {

    if(stack_top == stack_maxsize -1) {
        return 1;
    } else {
        return 0;
    }

}

int stack_peek(int *stack_arr) {
    if(stackIsEmpty()) {
        printf(RED_COLOR "Stack underflow.\n" RESET_COLOR);
        return -1;
    }
    return stack_arr[stack_top];
}

void stack_print(int *stack_arr) {

    if(stackIsEmpty()) {
        printf(RED_COLOR "Stack underflow.\n" RESET_COLOR);
    } else {

        printf(GREEN_COLOR "Stack: \n");
        for(int i=stack_top; i>=0; i--) {
            printf("%d ", stack_arr[i]);
        }
        printf("\n" RESET_COLOR);
    }

}

void stack_operations(int size) {

    stack_maxsize = size;
    int stack_arr[stack_maxsize];
    int choice, data;

    while(1) {

        choice = getTheChoiceForStack();

        switch(choice) {

            case 1: {
                printf("Enter element to be pushed: ");
                scanf("%d", &data);
                bool is_pushed = stack_push(stack_arr, data);
                if(is_pushed) {
                    printf(GREEN_COLOR "Element is added in the stack successfully.\n" RESET_COLOR);
                }

                break;
            }

            case 2:
                data = stack_pop(stack_arr);
                if(data != -1) {
                    printf(RED_COLOR "Deleted element is: %d\n" RESET_COLOR, data);
                }

                break;

            case 3:
                printf(BLUE_COLOR "The topmost element of the stack is: %d\n" RESET_COLOR, stack_peek(stack_arr));
                break;

            case 4: {

                int is_empty = stackIsEmpty();
                if(is_empty == 1) {
                    printf(YELLOW_COLOR "Stack is empty.\n" RESET_COLOR);
                } else {
                    printf(RED_COLOR "Stack is not empty.\n" RESET_COLOR);
                }

                break;
            }

            case 5: {
                int is_full = stackIsFull();
                if(is_full == 1) {
                    printf(RED_COLOR "Stack is full.\n" RESET_COLOR);
                } else {
                    printf(GREEN_COLOR "Stack is not full.\n" RESET_COLOR);
                }
                break;
            }

            case 6:
                stack_print(stack_arr);
                break;

            case 7:
                return;

            default:
                printf(RED_COLOR "Wrong choice.\n" RESET_COLOR);

        }

    }

}


//Queue Operations
bool queue_enqueue(int *queue_arr, int data) {
   if(queueIsFull()) {
       printf(RED_COLOR "Queue overflow.\n" RESET_COLOR);
       return false;
   }

   if(queue_front == -1) {
       queue_front = 0;
   }
   queue_rear++;
   queue_arr[queue_rear] = data;
   return true;
}

int queue_dequeue(int *queue_arr) {

   int value;
    if(queueIsEmpty()) {
        printf(RED_COLOR "Queue underflow.\n" RESET_COLOR);
        return -1;
    }

    value = queue_arr[queue_front];
    queue_front++;
    return value;

}

int queueIsEmpty() {
    if(queue_front == -1 || queue_front == queue_rear + 1) {
        //Reset front and rear when quue is empty.
        queue_front = queue_rear = -1;
        return 1;
    } else {
        return 0;
    }

}

int queueIsFull() {

    if(queue_rear == queue_maxsize -1) {
        return 1;
    } else {
        return 0;
    }

}

int queue_peek(int *queue_arr) {
    if(queueIsEmpty()) {
        printf(RED_COLOR "Queue underflow.\n" RESET_COLOR);
        return -1;
    }
    return queue_arr[queue_front];
}

void queue_print(int *queue_arr) {

    if(queueIsEmpty()) {
        printf(RED_COLOR "Queue underflow.\n" RESET_COLOR);
    } else {

        printf(GREEN_COLOR "Queue: \n");
        for(int i=queue_front; i<=queue_rear; i++) {
            printf("%d ", queue_arr[i]);
        }
        printf("\n" RESET_COLOR);
    }

}

void queue_operations(int size) {

    queue_maxsize = size;
    int queue_arr[queue_maxsize];
    int choice, data;


    while(1) {

        choice = getTheChoiceForQueue();

        switch(choice) {

            case 1: {
                printf("Enter element to be added to the queue: ");
                scanf("%d", &data);
                bool is_enqueued = queue_enqueue(queue_arr, data);
                if(is_enqueued) {
                    printf(GREEN_COLOR "Element is added/enqueued in the queue successfully.\n" RESET_COLOR);
                }

                break;
            }

            case 2:
                data = queue_dequeue(queue_arr);
                if(data != -1) {
                    printf(RED_COLOR "Deleted/Dequeued element is: %d\n" RESET_COLOR, data);
                }

                break;

            case 3:
                printf(BLUE_COLOR "The first element of the queue is: %d\n" RESET_COLOR, queue_peek(queue_arr));
                break;

            case 4: {

                int is_empty = queueIsEmpty();
                if(is_empty == 1) {
                    printf(YELLOW_COLOR "Queue is empty.\n" RESET_COLOR);
                } else {
                    printf(RED_COLOR "Queue is not empty.\n" RESET_COLOR);
                }

                break;
            }

            case 5: {
                int is_full = queueIsFull(queue_arr);
                if(is_full == 1) {
                    printf(RED_COLOR "Queue is full.\n" RESET_COLOR);
                } else {
                    printf(GREEN_COLOR "Queue is not full.\n" RESET_COLOR);
                }
                break;
            }

            case 6:
                queue_print(queue_arr);
                break;

            case 7:
                return;

            default:
                printf(RED_COLOR "Wrong choice.\n" RESET_COLOR);

        }

    }


}
