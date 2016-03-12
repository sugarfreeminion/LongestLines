/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            12 March 2016
 * Description:     Write a program which reads a file and prints to
 *                  stdout the specified number of the longest lines that
 *                  are sorted based on their length in descending order
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool comparison(string one, string two);

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;
        vector<string> lines;
        int numberOfLines = 0;
        int index = 0;

        stringstream ss;

        getline(inputFile,line);

        ss << line;
        ss >> numberOfLines;

        while(getline(inputFile,line))
        {
            lines.push_back(line);
        }

        sort(lines.begin(),lines.end(),comparison);

        for(vector<string>::reverse_iterator it = lines.rbegin();
            it != lines.rend();
            ++it)
        {
            if(index < numberOfLines)
            {
                cout << *it << endl;
            }
            else
            {
                break;
            }

            ++index;
        }

        inputFile.close();
    }

    return 0;
}

bool comparison(string one, string two)
{
    return(one.size() < two.size());
}
