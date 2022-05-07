#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int readGen (char * genPath);

int main ( int argc , char * argv[] ) {         //


    int index = readGen(argv[1]);

    cout << index << endl;

    return 0;
}


// abre archivo
// lee texto entre origin y //
// devuelve la letra si es actg si no lee la prox hasta encontrar actg

int readGen (char * genPath)   // recibir nombre del archivo txt
{
    ifstream file(genPath);
    file.open(genPath, std::ifstream::in);

    if (!file.is_open())
    {
        perror("Error while opening file ");
        return false;
    }

    string line;
    int i = 0;
    int originIndex = 0;

    while(getline(file, line))
    {
        if(line == "ORIGIN"){
            originIndex = i;
            break;
        }
        i++;
    }

    file.close();

    return originIndex;
}

