/*
   Maximum Profit on App

   You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.
   You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.
   Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :
   m * x
   where m is total number of buyers whose budget is greater than or equal to x.
 */

#include <algorithm>
#include <iostream>
using namespace std;

void Print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int maximumProfit(int budget[], int n) {
    sort(budget, budget + n);
    //Print(budget,n);
    int max = 0;
    int num = n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s = budget[i] * num;
        num--;
        if (s > max) {
            max = s;
        }
    }
    return max;
}

int main() {
    int bud[] = {34, 78, 90, 15, 67};
    int n = sizeof(bud) / sizeof(bud[0]);
    cout << maximumProfit(bud, n);
}
