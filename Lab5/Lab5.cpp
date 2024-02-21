// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

char cipher(string response, vector<char>& ciphers, int i)
{

    char w;

        if (response[i] >= 65 && response[i] <= 90) {
            
            return ciphers[response[i] - 65];

        }

        else if (response[i] >= 97 && response[i] <= 122) {

            response[i] = response[i] - 32;
            w = ciphers[response[i] - 65];

            return w + 32;

        }
        else {

            return response[i];

        }

}

vector<char> loop(string response, vector<char>& ciphers, int i)
{

    vector<char> final;

    for (int i = 0; i < response.size(); i++) 
    {
    
        final.push_back(cipher(response, ciphers, i));

    }

    return final;
    
}

int main()
{
   int i = 0;
   vector<char> ciphers({'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E'});
   string response;
   cout << "Input text to cypher: ";
   getline(cin, response);

   cout << endl << "Encoded message: ";
   vector<char> finished;

   finished = loop(response, ciphers, i);

   for (int i = 0; i < response.size(); i++) 
   {

       cout << finished[i];

   }
   
   return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
