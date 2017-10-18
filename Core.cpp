#include "Core.h"

#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
using std::setfill;
using std::endl;

Core::Core(int hr, int mi, int sc)
{
    sc = time(NULL) % 59;
    mi = (time(NULL) % 6000) / 100;
    hr = (time( NULL ) % 2300)/ 1000000;

    setTime(hr, mi, sc);
}

void Core::setTime(int h, int m, int s)
{
    hour = (h < 23)? h : 0;
    minute = (m < 59)? m : 0;
    second = (s < 59)? s : 0;
}

void Core::printUniversal()
{
    cout << setfill ('0') << setw( 2 ) << hour << ":"
         << setw( 2 ) << minute << ":" <<setw ( 2 ) << second <<endl;
}

void Core::printStandard()
{
    cout << "larga mao disso";
}

void Core::show() const
{
    cout << "XAlAlALALALALALlaLALALLALALA";
}
