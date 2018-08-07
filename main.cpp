#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
using namespace std;

int main()
{
    srand (time(NULL));
    cout << "Ceci donne un mot au pseudo hasard." << endl;
    cout << "C\'est lisible, donc c\'est plus facile de le retenir ou de le recopier." << endl;
    cout << "C\'est utile pour un mot de passe, un captcha..." << endl;
    cout << "Certaines lettres ne seront pas inscrites, volontairement, " << endl;
    cout << "pour limiter les incertitudes." << endl << endl;
    string tentativeString = "";
    bool inputOk = true;
    int longueur = 0;
    string mot = "";
    int valLettreVoyelle = 0;
    int valLettreConsonne = 0;
    int minVoyelle = 0;
    int minConsonne = 0;

    char voyelles[5] = {'A', 'E', 'I', 'O','U'};
    int maxVoyelle = 5;

    char consonnes[15] = {'B', 'D', 'F', 'G', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'S', 'T', 'V','Z'};
    int maxConsonne = 15;

    do
    {
        inputOk = true; // Pour autre demande éventuelle.
        try
        {
            cout << "Quelle longueur voulez-vous, svp ? ";
            // cin >> longueur;
            getline(cin, tentativeString); // Pour éviter des bugs de non nombre.
            longueur = stoi(tentativeString);
        }
        catch (const std::invalid_argument& e)
        {
            cerr << "Un nombre, svp !" << endl;
            inputOk = false;
        }
    }
    while (inputOk == false);
    for (int a = 0; a < longueur; a++)
    {
        valLettreConsonne = rand() % maxConsonne + minConsonne;
        mot = mot + consonnes[valLettreConsonne];
        a++; // Deux lettres par boucle.
        if (a < longueur) // Pour éviter les dépassements.
        {
            valLettreVoyelle = rand() % maxVoyelle + minVoyelle;
            mot = mot + voyelles[valLettreVoyelle];
        }
    }
    cout << mot << endl;
    string nomFichier = "";
    cout << endl;
    cout << "Si vous voulez sauvegarger cette signature, donnez un nom de fichier, " << endl;
    cout << "avec son extension." << endl;
    cout << "Si vous donnez le nom d'un fichier existant, il sera mis sur la ligne suivante." << endl;
    cout << "Si vous annulez, il n\'y aura aucune sauvegarde !" << endl;
    getline(cin, nomFichier);
    if (nomFichier !="")
    {
        ofstream myFile(nomFichier.c_str(), ios::app); // Open to append, ".niv" included.
        if (!myFile)
        {
            cerr << "Erreur de fichier !";
        }
        else
        {
            myFile << mot << endl;// append file.
        }
        myFile.close();
    }
    cout << "OK." << endl;
    return 0;
}
