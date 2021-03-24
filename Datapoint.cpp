#include <string>
#include "Datapoint.hpp"
 
using namespace std;

Datapoint::Datapoint()
{
}

Datapoint::~Datapoint()
{
}
Datapoint::Datapoint(double platitude, double plongitude, string pidentifiant, string ptimestamp, int ptemperature)
: latitude(platitude), longitude(plongitude), identifiant(pidentifiant), timestamp(ptimestamp), temperature(ptemperature)
{
}


double Datapoint::getLatitude() const { return latitude; };
double Datapoint::getLongitude() const { return longitude; };
string Datapoint::getIdentifiant() const { return identifiant; };
string Datapoint::getTimestamp() const { return timestamp; };
int Datapoint::getTemperature() const { return temperature; };


