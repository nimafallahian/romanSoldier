#ifndef FUEL_H
#define FUEL_H
#include <QProgressBar>
class Fuel : public QProgressBar
{
public:
    int decSpeed;
    int stnDecSpeed;
    Fuel();
};

#endif // FUEL_H
