#include <iostream>
#include <math.h>
#include <cctype>
#include <string>

double chislo() {
    double proxod;
    bool isNumber = false;

    while (!isNumber) {
        std::string userInput;
        std::cout << "Enter a number: ";
        std::cin >> userInput;

        isNumber = true;

        if (userInput[0] == '-') {
            for (int i = 1; i < userInput.length(); i++) {
                if (!std::isdigit(userInput[i])) {
                    isNumber = false;
                    break;
                }
            }
        }
        else {
            for (char c : userInput) {
                if (!std::isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
        }

        if (isNumber) {
            proxod = std::stod(userInput);
        }
        else {
            std::cerr << "Not a number. Try to enter a number again." << std::endl;
        }
    }

    return proxod;
}

void enterRange(double& a, double& b, double& c) {
    std::string scolco;

    while (true) {
        std::cout << "If you want to calculate a single value, enter 'single'. "
            << "If you want to calculate a range of values, enter 'range': ";
        std::cin >> scolco;

        if (scolco == "single") {
            std::cout << "Input value x: ";
            a = chislo();
            b = a;
            c = 9999;
            break;
        }
        else if (scolco == "range") {
            bool VseOk = false;

            while (!VseOk) {
                std::cout << "Input minimum range value a: ";
                a = chislo();

                std::cout << "Input maximal range value b: ";
                b = chislo();

                if (a > b) {
                    std::string Input1;
                    while (true) {
                        std::cout << "Minimum value is bigger than maximal. "
                            << "If you want to swap values, type 'swap'. "
                            << "If you want to reenter values, type 'reenter': ";
                        std::cin >> Input1;

                        if (Input1 == "swap") {
                            double swaping = a;
                            a = b;
                            b = swaping;
                            VseOk = true;
                            break;
                        }
                        else if (Input1 == "reenter") {
                            VseOk = false;
                            break;
                        }
                        else {
                            std::cout << "Invalid value. Please try again." << std::endl;
                        }
                    }
                }
                else {
                    VseOk = true;
                }
            }

            bool VseOk2 = false;
            while (!VseOk2) {
                std::cout << "Input step of range value c: ";
                c = chislo();
                if (c > b - a) {
                    std::string Input2;
                    while (true) {
                        std::cout << "The step is too big, the calculation will be done only fore one value " << a
                            << "If you want to continue, type 'continue'. "
                            << "If you want to enter values ​​again, type 'reenter': ";
                        std::cin >> Input2;

                        if (Input2 == "continue") {
                            VseOk2 = true;
                            break;
                        }
                        else if (Input2 == "reenter") {
                            break;
                        }
                        else {
                            std::cout << "Invalid value. Please try again." << std::endl;
                        }
                    }
                }
                else {
                    VseOk2 = true;
                }
            }
            break;
        }
        else {
            std::cout << "Invalid value. Please try again." << std::endl;
        }
    }
}

int main() {
    double y = 0, p = 0, sum = 0, a, b, c, n;
    int d = 0;
    bool rabotaem = true;
    while (rabotaem)
    {
        std::cout << "Input n > 1: ";
        while (true) {
            n = chislo();
            if (n > 1) {
                break;
            }
            else {
                std::cout << "n less than 1. Try to input n again: ";
            }
        }

        enterRange(a, b, c);

        while (a <= b) {
            d++;
            if (a < 0) {
                for (int i = 0; i <= n + 3; i++) {
                    y += sum;
                    for (int j = 0; j <= n; j++) {
                        sum += std::pow((i + a - j), 2);
                    }
                }
            }
            else {
                for (int i = 1; i <= n; i++) {
                    p += 7 * a - i;
                }
                for (int j = 0; j <= n; j++) {
                    sum += j + 2;
                }
                y = p - (6 * a * sum);
            }
            std::cout << "x" << d << ": " << a << ";  y" << d << ": " << y << '\n';
            a += c;
        }

            std::cout << "If you wont calculate again print 'again' "
                << "If you wont stop program print 'stop' ";

        while (true) {
            std::string Input3;
            std::cin >> Input3;
            if (Input3 == "again") {
                break;
            }
            else if (Input3 == "stop") {
                rabotaem = false;
                break;
            }
            else {
                std::cout << "Invalid value.Please try again.";
            }
        }
    }
    return 0;
}
