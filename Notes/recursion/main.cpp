#include <iostream>

using namespace std;

void hello(int counter);
int fib(int num);

void triangle(int num);
string rvrsString(string thing, int begin, int end)

int main(int argc, char* argv[])
{
    hello(10);
    int num;
    string thing;
    cout <<"nth fib number: ";
    cin >> num;

    cout << fib(num) << endl;

    triangle(num);

    cout << "Enter a string you wish you reverse: " << endl;
    cin >> thing;
    
    return 0;
}

string rvrsString(string thing, int beg, int end)
{
    /*string rerversedStr = "";
    for(auto it = thing.rbegin(); it != thing.rend(); it++)
    {
        rerversedStr =+ *it;
    }
    return rerversedStr;*/
    if(beg >= end) "";
    return 
    return thing + rvrsString(thing);
}

long factorial(int n)
{
    if(n == 1) return 1;
    return n * factorial(n - 1);
}

void triangle(int n)
{
    if(n == 0) return;
    printStars(n);
    cout << endl;
    triangle(n-1);
    
    
}

void printStars(int n)
{
    if(n == 0) return;
    {
        cout << endl;
        return;
    }
    printStars(n-1);
    cout << "* ";
   

}

int fib(int num)
{
    if (num == 0 || num == 1) return num;
    return fib(num - 2) + fib(num - 1);
}

void hello(int counter)
{
    if(counter <= 0) return;    
    cout << "Hello" << endl;
    hello(counter-1);
}