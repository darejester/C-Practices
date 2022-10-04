// Determine the speed of using 4 byte integers and 4 byte floats in doing adds and multiplies on your machine.


#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    int x = 0;
    int x1 = 512300;
    float y = 0;
    float y1 = 512300.0f;




    cout << "int addition" << endl;
    // set start_time equal to the time when the for loop is about to start
    auto start_time = chrono::high_resolution_clock::now();

    // 2,000,000,000
    for (int i = 0; i < 2'000'000'000; i++)
    {
        x = x1 + 96600;
    }
    // set end_time equal to the time when the for loop finished
    auto end_time = chrono::high_resolution_clock::now();

    // subtracts start_time with end_time to get run time as if it started at 0
    auto diff = end_time - start_time;

    // displays diff
    // "." at the end of 1,000,000,000 is needed to get a decimal
    cout << "Elapsed time = " << diff / chrono::nanoseconds(1) / 1000000000. << "Seconds.\n" << endl;




    cout << "int multiplication" << endl;
    // reset x
    x = 1;

    // set start_time equal to the time when the for loop is about to start
    start_time = chrono::high_resolution_clock::now();

    // 2,000,000,000
    for (int i = 0; i < 2'000'000'000; i++)
    {
        x = x1 * 96600;
    }
    // set end_time equal to the time when the for loop finished
    end_time = chrono::high_resolution_clock::now();

    // subtracts start_time with end_time to get run time as if it started at 0
    diff = end_time - start_time;

    // displays diff
    // "." at the end of 1,000,000,000 is needed to get a decimal
    cout << "Elapsed time = " << diff / chrono::nanoseconds(1) / 1000000000. << "Seconds.\n" << endl;




    cout << "float addition" << endl;
    // set start_time equal to the time when the for loop is about to start
    start_time = chrono::high_resolution_clock::now();

    // 2,000,000,000
    for (int i = 0; i < 2'000'000'000; i++)
    {
        y = y1 + 96600.0f;
    }

    // set end_time equal to the time when the for loop finished
    end_time = chrono::high_resolution_clock::now();

    // subtracts start_time with end_time to get run time as if it started at 0
    diff = end_time - start_time;

    // displays diff
    // "." at the end of 1,000,000,000 is needed to get a decimal
    cout << "Elapsed time = " << diff / chrono::nanoseconds(1) / 1000000000. << "Seconds.\n" << endl;




    cout << "float multiplication" << endl;
    // reset y
    y = 1;

    // set start_time equal to the time when the for loop is about to start
    start_time = chrono::high_resolution_clock::now();

    // 2,000,000,000
    for (int i = 0; i < 2'000'000'000; i++)
    {
        y = y1 * 96600.0f;
    }

    // set end_time equal to the time when the for loop finished
    end_time = chrono::high_resolution_clock::now();

    // subtracts start_time with end_time to get run time as if it started at 0
    diff = end_time - start_time;

    // displays diff
    // "." at the end of 1,000,000,000 is needed to get a decimal
    cout << "Elapsed time = " << diff / chrono::nanoseconds(1) / 1000000000. << "Seconds.\n" << endl;

    cout << x << " " << y << endl;

    return 0;
}
