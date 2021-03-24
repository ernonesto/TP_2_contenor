#include <stdio.h>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Datapoint.hpp"
 
using namespace std;

vector<Datapoint> donnesAmericain;

void LireDonnesAmericain(string nomFichierAmericain)
{
        ifstream fichier(nomFichierAmericain, ios::in);  // on ouvre en lecture

        if(fichier)  // si l'ouverture a fonctionné
        {
            string ligne;
            while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
            {
                string donnes[5];
                int i = 0;
                stringstream ssin(ligne);
                
                while (ssin.good() && i < 5){
                    ssin >> donnes[i];
                    ++i;
                }
                try{
                    if(donnes[3] == "") throw std::out_of_range("Ligne incomplete : " + ligne);

                    Datapoint data((stod(donnes[0])), stod(donnes[1]),donnes[2],donnes[4], stoi(donnes[3]));
                    donnesAmericain.push_back(data);
                    }catch(const std::out_of_range& ex){ std::cout << ex.what()<< std::endl;}
                
                
            }
           fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void EcrireDonnesCanadien()
{
        ofstream fichier("candata.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
        if(fichier)
        {
            for (const Datapoint data : donnesAmericain)
            {
                double tempCelcius  = 5 * (double(data.getTemperature()) - 32) / 9;
                fichier << data.getTimestamp() <<"  "<< data.getLatitude() <<"  "<< data.getLongitude() << "  " << tempCelcius << endl;            
            }
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void TrierListe()
{
  Datapoint oneDatapoint ;
  int counter = 0;
  do
    {
      for (int i = 0; i < donnesAmericain.size ()-1; i++)
	{
	  for (int j = i + 1; j < donnesAmericain.size (); j++)
	    {
	      if ((donnesAmericain[i].getLatitude() == donnesAmericain[j].getLatitude()
		   && donnesAmericain[i].getLongitude() > donnesAmericain[j].getLongitude ())
		  || (donnesAmericain[i].getLatitude () <
		      donnesAmericain[j].getLatitude ()))
		{
		  oneDatapoint = donnesAmericain[i];
		  donnesAmericain[i] = donnesAmericain[j];
		  donnesAmericain[j] = oneDatapoint;
		}
	    }
	}
      counter++;
    }
  while (counter < 2);
}
int main(int argc, char **argv)
{ 
    string nomFichierAmericain = "rawdata.txt";
    LireDonnesAmericain(nomFichierAmericain);
    TrierListe();
    EcrireDonnesCanadien();
        return 0;
}
