#ifndef Temperature_h
#define Temperature_h

#include <math.h>

double read_raw_temp(int pin) {
    int RawADC = analogRead(pin);
    double Temp;
    Temp = log(10000.0*((1024.0/RawADC-1)));
    //         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
    Temp = Temp - 273.15;            // Convert Kelvin to Celcius
    // Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
    return Temp;
}


double ReadThermistor(int pin, int iteration)
{
    double total = 0;
    for (size_t i = 0; i < iteration; i++) {
        total += read_raw_temp(pin);
    }
    total /= (double)iteration;
    return total;
}

#endif
