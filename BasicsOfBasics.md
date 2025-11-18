### 1. Star Printing Patterns in C++
---
## Pattern 1: Square
```cpp
// Square pattern
int n = 5;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}
```
## Pattern 2: Right-angled Triangle
```cpp
// Right-angled triangle
int n = 5;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}
```
## Pattern 3: Inverted Right-angled Triangle
```cpp
// Inverted triangle
int n = 5;
for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}
```
## Pattern 4: Pyramid
```cpp
// Pyramid pattern
int n = 5;
for(int i=1; i<=n; i++) {
    for(int j=1; j<=n-i; j++) std::cout << " ";
    for(int j=1; j<=2*i-1; j++) std::cout << "*";
    std::cout << std::endl;
}
```
## Pattern 5: Diamond
```cpp
// Diamond pattern
int n = 5;
for(int i=1; i<=n; i++) {
    for(int j=1; j<=n-i; j++) std::cout << " ";
    for(int j=1; j<=2*i-1; j++) std::cout << "*";
    std::cout << std::endl;
}
for(int i=n-1; i>=1; i--) {
    for(int j=1; j<=n-i; j++) std::cout << " ";
    for(int j=1; j<=2*i-1; j++) std::cout << "*";
    std::cout << std::endl;
}
```
---
### 2. Basic Maths Questions in C++
## Count Digits
```cpp
int countDigits(int n) {
    int count = 0;
    while(n != 0){
        n /= 10;
        ++count;
    }
    return count;
}
```
## Reverse a Number
```cpp
int reverseNumber(int n) {
    int rev = 0;
    while(n != 0){
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
```
## Check Palindrome
```cpp
bool isPalindrome(int n) {
    return n == reverseNumber(n);
}
```
## GCD / HCF
```cpp
int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
```
## Armstrong Number
```cpp
bool isArmstrong(int n) {
    int sum = 0, original = n;
    int digits = countDigits(n);
    while(n != 0){
        int d = n%10;
        sum += pow(d, digits);
        n /= 10;
    }
    return sum == original;
}
```
## Print All Divisors
```cpp
void printDivisors(int n) {
    for(int i = 1; i <= n; i++){
        if(n % i == 0)
            std::cout << i << " ";
    }
}
```
## Check for Prime
```cpp
bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
```
