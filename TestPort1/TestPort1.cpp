#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;




void Banner()
{
    system("title SCANNER PORT EMULATOR");
    cout << "+++++++++++++++++++++++++" << endl;
    cout << "  SCANNER PORT EMULATOR  " << endl;
    cout << "+++++++++++++++++++++++++" << endl;
    cout << endl;
}




int CalcolaVelocita(string scelta)
{
    if (scelta == "T1") return 200;
    if (scelta == "T2") return 400;
    if (scelta == "T3") return 600;
    return 100;
}







int main(int argc, char* argv[])
{
    ofstream File;
    
    Banner();
 
    
    
    vector<int> ports = {22, 55, 80, 8080, 28746, 9224, 18333, 19002};
    int x = 0;
    vector<int> allert;
    
    int sleep;
    
    string scelta_velocita;
    cout << "Scegli la velocita' di scanning" << endl;
    cout << "SCELTA T1 - T2 - T3: " << endl;
    cin >> scelta_velocita;
    sleep = CalcolaVelocita(scelta_velocita);
    
    string salva;
    cout << "SALVARE: [Y/y] or [N/n]: " << endl;
    cin >> salva;    
   
       
    
    if (salva == "Y" || salva == "y")
    {
        File.open("file.txt");
    }

    
    for (int i = 0; i < ports.size(); i++)
    {
        if (ports[i] <= 8080)
        {
            Sleep(sleep);
            cout << "PORTS: " << ports[i] << endl;
            if (File.is_open()) File << "PORTS: " << ports[i] << endl;
        } else if (ports[i] > 8080)
        {
            Sleep(sleep);
            cout << "SCONOSCIUTA: " << ports[i] << endl;
            if (File.is_open()) File << "SCONOSCIUTA: " << ports[i] << endl;
            allert.push_back(ports[i]);
        }
    }
    
    cout << "========================" << endl;
    
    for (int i = 0; i < allert.size(); i++)
    {
        Sleep(sleep);
        cout << "SCONOSCIUTA: " << allert[i] << endl;
    }
    
    if (File.is_open()) File.close();
    
    system("pause");
    
    
    return 0;
}
