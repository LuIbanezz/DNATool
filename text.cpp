/**
 * @file text.cpp
 * @authors	Lucía Ibañez, Lucía Ruiz.
 *
 * @brief Input and output manager. Reads genome and prints alignment in another file.
 *
 * @copyright Copyright (c) 2022 ~ EDA ~ ITBA
 *
 */

#include "text.h"

/**
 * @brief Genome reading. Interpretation and conversion to string of 'a','c','g','t' combinations.
 * 
 * @param genPath: receives file name of .txt.
 * @return string: returns genetic sequence by filtering 'a', 'c', 'g', 't' characters only.
 */

string readGen(string genPath)
{
    ifstream fin(genPath, ios::in);

    bool isOpen = fin.is_open();
    if(!isOpen)
    {
        cout << "Error: could not open " << genPath << endl;
    }

    string line1;
    string line2;
    int i = 0;

    while(getline(fin, line1))
    {
        if(line1.find("ORIGIN") != (string::npos))
        {
            while(line1.find("//") == (string::npos))
            {
                getline(fin, line1);
                int j = 1;
                while (line1[i] != 'a' && line1[i] != 'c' && line1[i] != 'g' && 
                        line1[i] != 't' && i < line1.size())
                {
                    i++;
                }

                while (i < line1.size())
                {
                    if((line1[i] != ' ') && (line1[i] != '\r'))
                    {
                        line2 += line1[i]; 
                    }
                    i++;
                }
                i=0;
                j++;
            }
            return line2;
        }
    }
    return "error";
} 

/**
 * @brief Genome printing in out.txt file, intercalating 
 * 
 * @param alignment references string alignment (from main)
 * @param sizeGen size of both genomes and of alignment 
 * @param gen1 refernces string gen1 (from main)
 * @param gen2 references string gen2 (from main)
 */

void printGen (string& alignment, size_t sizeGen, string& gen1, string& gen2)
{ 
    ofstream fout("out.txt");

    bool isOpen = fout.is_open();
    if(!isOpen)
    {
        cout << "Error opening output file" << endl;
    }

    for(int i = 0 ; i <= gen1.size() ; i++)
    {
        for(int j = 10 ; j < SIZE_OF_LINE && j < gen1.size() ; j += 11)
        {
            if(j + (i * SIZE_OF_LINE) < gen1.size()){
                gen1.insert(j + (i * SIZE_OF_LINE) , 1 ,' ');
                alignment.insert(j + (i * SIZE_OF_LINE) , 1 ,' ');
                gen2.insert(j + (i * SIZE_OF_LINE) , 1 ,' ');
            }
        }
    }
    int finalSize = gen1.size();

    for(int k = 0 ; k * SIZE_OF_LINE <= finalSize ; k++)
    {
        string lineGen1 = gen1.substr(k * SIZE_OF_LINE, SIZE_OF_LINE);
        fout << lineGen1 << endl;

        string lineAlignment = alignment.substr(k * SIZE_OF_LINE, SIZE_OF_LINE);
        fout << lineAlignment << endl;

        string lineGen2 = gen2.substr(k * SIZE_OF_LINE, SIZE_OF_LINE);
        fout << lineGen2 << endl;

        fout << endl;
    }
}


