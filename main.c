#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.14159

void mainMenu(bool *state);
void math();
void pythagoreanTheorem();
void circleArea();
void physics();
void showHelp();
double volumeSphere(double radius);
double newtonsSecondLaw(double mass, double acceleration);
double ohmsLaw(double voltage, double current);
int qq();

char getInput(const char *prompt) {
    char result;
    printf("%s", prompt);
    scanf(" %c", &result);
    while (getchar() != '\n');
    return result;
}



bool state = true;

int main() {
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*              Welcome to Mathiphy             *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    while (state) {
        mainMenu(&state);
    }
    return 0;
}

void mainMenu(bool *state) {
    bool a = true;
    while (a) {
        printf("***************   -Main Menu-    ***************\n");
        printf("*************** Select an option ***************\n");
        printf("*        1- Important functions in Math        *\n");
        printf("*        2- Important functions in Physics     *\n");
        printf("*        3- Help                               *\n");
        char choice = getInput("Select: ");
        switch (choice) {
            case '1':
                math();
                a = false;
                break;
            case '2':
                physics();
                a = false;
                break;
            case '3':
                showHelp();
                break;
            default:
                printf("Please choose a valid option\n");
                continue;
        }
    }
    *state = false;
}

void math() {
    bool b = true;
    while (b) {
        printf("\n*************** -Math Functions- ***************\n");
        printf("*************** Select an option ***************\n");
        printf("*        1- The Pythagorean Theorem            *\n");
        printf("*        2- Circle Area                        *\n");
        printf("*        3- Volume of a Sphere                 *\n");
        printf("*        4- Main Menu                          *\n");
        char choice = getInput("Select:");
        if (choice == '1') {
            pythagoreanTheorem();
            b = false;
            qq();
        } else if (choice == '2') {
            circleArea();
            b = false;
            qq();
        } else if (choice == '3') {
            double rad;
            printf("Enter the radius of the sphere: ");
            scanf("%lf", &rad);
            double volume = volumeSphere(rad);
            printf("Volume of the sphere: %.2f\n", volume);
            b = false;
            qq();
        } else if (choice == '4') {
            mainMenu(&state);
            b=false;
        } else {
            printf("Please enter a valid function");
        }
    }
}

void pythagoreanTheorem() {
    double side1, side2, hypotenuse;

    printf("Enter the lengths of the two sides of the right triangle:\n");
    printf("Side 1: ");
    scanf("%lf", &side1);
    printf("Side 2: ");
    scanf("%lf", &side2);

    hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));

    printf("Length of the hypotenuse: %.2f\n", hypotenuse);
}

void circleArea() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    double area = PI * pow(radius, 2);

    printf("Area of the circle: %.2f\n", area);
}

double volumeSphere(double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3);
}

void physics() {
    bool b = true;
    while (b) {
        printf("\n************** -Physics Functions- ***************\n");
        printf("**************  Select an option   ***************\n");
        printf("*        1- Newton's Second Law of Motion    *\n");
        printf("*        2- Ohm's Law                        *\n");
        printf("*        3- Back to Main Menu                 *\n");
        char choice = getInput("Select:");
        int option = choice - '0'; 
        switch (option) {
            case 1:
                printf("\n***** Newton's Second Law of Motion *****\n");
                double mass, acceleration;
                printf("Enter the mass (in kg): ");
                scanf("%lf", &mass);
                printf("Enter the acceleration (in m/s^2): ");
                scanf("%lf", &acceleration);
                printf("Force (N) = %.2f\n", newtonsSecondLaw(mass, acceleration));
                b = false;
                qq();
                break;
            case 2:
                printf("\n***** Ohm's Law *****\n");
                double voltage, current;
                printf("Enter the voltage (in volts): ");
                scanf("%lf", &voltage);
                printf("Enter the current (in amperes): ");
                scanf("%lf", &current);
                printf("Resistance (Ω) = %.2f\n", ohmsLaw(voltage, current));
                b = false;
                qq();
                break;
            case 3:
                mainMenu(&state);
                break;
            default:
                printf("Please choose a valid option\n");
                continue;
        }
    }
}

double newtonsSecondLaw(double mass, double acceleration) {
    return mass * acceleration;
}

double ohmsLaw(double voltage, double current) {
    if (current == 0) {
        printf("Error: Cannot divide by zero (current is zero)\n");
        return NAN; 
    }
    return voltage / current;
}

void showHelp() {
    void showHelp() {
        printf("***********************************************\n");
        printf("*                 Help Section                *\n");
        printf("***********************************************\n");
        printf("Mathiphy is a versatile application designed to assist users with mathematical and physics-related tasks. Below is an overview of the available functions:\n\n");

        printf("Math Functions:\n");
        printf("1. The Pythagorean Theorem: Calculate the length of the hypotenuse of a right triangle given the lengths of the two other sides.\n");
        printf("2. Circle Area: Calculate the area of a circle based on its radius.\n");
        printf("3. Volume of a Sphere: Compute the volume of a sphere based on its radius.\n\n");

        printf("Physics Functions:\n");
        printf("1. Newton's Second Law of Motion: Calculate the force exerted on an object based on its mass and acceleration.\n");
        printf("2. Ohm's Law: Determine the resistance of a circuit component based on the voltage across it and the current flowing through it.\n\n");

        printf("To use Mathiphy, select an option from the main menu and follow the prompts to input necessary data and view the results.\n\n");
        printf("1. Choose '1' for important math functions.\n");
        printf("2. Choose '2' for important physics functions.\n");
        printf("3. Choose '3' to display this help section.\n\n");

        printf("Enjoy using Mathiphy to streamline your calculations and enhance your understanding of mathematical and physical concepts!\n");
        printf("\n");
    }

}

int qq() {
    bool c = true;
    while (c) {
        printf("\nDo you want to continue?\n");
        printf("1- Yes      2- No\n");
        getchar();
        char choice = getInput("Select: ");
        if (choice == '1') {
            c = false;
            mainMenu(&state);
        } else if (choice == '2') {
            c = false;
            printf("Thank you for using our application\n");
            return 0;
        } else {
            printf("Please choose a valid option\n");
        }
    }
}
