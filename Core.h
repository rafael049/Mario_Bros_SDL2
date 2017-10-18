#ifndef CORE_H
#define CORE_H


class Core
{
public:
    Core(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    void printUniversal();
    void printStandard();

    void show () const;

private:
    int hour;
    int minute;
    int second;
};

#endif // CORE_H
