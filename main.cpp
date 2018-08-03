#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>      

using namespace std;

int main()
{
    srand (time(NULL));
    cout << "Ceci donne un mot au pseudo hasard (lisible, donc plus facile à retenir)." << endl;
    cout << "Cela peut être utile pour un mot de passe, un captcha..." << endl;
    cout << "Certaines lettres ne seront pas inscrites, volontairement, " << endl;
    cout << "pour limiter les incertitudes." << endl << endl;
    string tentativeString = "";
    bool inputOk = true;
    int longueur = 0;
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
        valLettreConsonne = rand() % maxConsonne + minConsonne; // -1 ?
        cout << consonnes[valLettreConsonne];

        a++; // Deux lettres par boucle.
if (a < longueur) // Pour éviter les dépassements.
{

        valLettreVoyelle = rand() % maxVoyelle + minVoyelle; // -1 ?
        cout << voyelles[valLettreVoyelle];
}

    }

    return 0;
}
