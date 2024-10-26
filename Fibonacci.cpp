//
// Created by Shahd Elnassag on 10/20/2024.
//
#include <bits/stdc++.h>

using namespace std;

template<typename T>
T Fibonacci(T num){
    if (num== 0 || num == 1){
        return num;
    }
    return Fibonacci(num-1) + Fibonacci(num-2);
}
#include <vector>

template <typename T>
T fibonacciD(T n) {
    std::vector<T> fib(n + 1);  

    fib[0] = 0;
    fib[1] = 1;

    for (T i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}


void Menu(){
    cout<<"Welcome to Fibonacci Series\n"
          "1.Fibonacci series using recursion\n"
          "2.Fibonacci series using divide and conquer\n"
          "3.Fibonacci series using dynamic programming\n"
          "4.Terminate Program\n";
}

int ChoiceFunction() {
    bool status = true;
    while (status) {
        int choice;
        Menu();
        cout << "Enter Your Choice From above Menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "You are now testing Fibonacci function using recursion.\n";
                            int n;
                            cout << "Please enter a number: ";
                            cin >> n;
                            cout << "Fibonacci of number " << n << " = " << Fibonacci(n) << "\n";
                            cout<<"-------------------------------------------\n";
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;
                    }
                    if (choice == 2) break;
                }
                break;

            case 2:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "Not added yet, See You Later ^_^\n";
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;
                    }
                    if (choice == 2) break;
                }
                break;

            case 3:
                while (true) {
                    cout << "1. Continue\n2. Return\nPlease Enter choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "You are now testing Fibonacci function using dynamic programming.\n";
                            int n;
                            cout << "Please enter a number: ";
                            cin >> n;
                            cout << "Fibonacci of number " << n << " = " << FibonacciD(n) << "\n";
                            cout<<"-------------------------------------------\n";
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;
                    }
                    if (choice == 2) break;
                }
                break;

            case 4:
                cout << "Thank You, See You Later ^_^\n";
                return 0;

            default:
                cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;

        }
    }
}

int main(){
    ChoiceFunction();
}

