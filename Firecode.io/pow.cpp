/*
   Write a function - power(x,n) that returns the value of x raised to the power
   of n (xn). n can be negative!

   Example:
   power(2,3) ==> 8.0
 */

double power(double x, int n) {
    if (n >= 0) {
        if (n == 0) {
            return 1;
        }
        return x * power(x, n - 1);
    } else {
        return 1 / x * power(x, n + 1);
    }
}
