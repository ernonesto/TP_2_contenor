#ifndef DATAPOINT_HPP
#define DATAPOINT_HPP

#include <string>
 
using namespace std;

class Datapoint
{
private:
double latitude;
double longitude;
string identifiant;
string timestamp;
int temperature;
    
public:
    Datapoint();
    Datapoint(double platitude, double plongitude, string pidentifiant, string ptimestamp, int ptemperature);
    
    ~Datapoint();
    double getLatitude() const;
    double getLongitude() const;
    string getIdentifiant() const;
    string getTimestamp() const;
    int getTemperature() const;
};

#endif // DATAPOINT_HPP
