/************************************************
** Author: Andrea Hayes
** Date: May 9, 2020
** Purpose: Match lottery ticket numbers
** Input: Array's for numbers played and lottery number
** Processing: Binary Search
** Output: Display if any numbers match
*************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int binarySearch(int[], int, int);
int main() {

    int lottery, user[] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
    int results;

    cout << "Enter the lottery numbers(no spaces): ";
    cin >> lottery;

    results = binarySearch(user, 10, lottery);

    if (results == -1) {
        cout << "You did not match this week.";
    }
    else {
        cout << "You matched!";
    }
    return 0;
}
int binarySearch(int user[], int numElems, int value) {
    int first = 0,
    last = numElems -1,
    middle,
    position = -1;
    bool found = false;

    while (!found&& first <=last) {
        middle = (first + last) / 2;
        if (user[middle] == value) {
            found = true;
            position = middle;
        }
        else if (user[middle] > value) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return position;
}