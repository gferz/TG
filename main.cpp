#include <string> 
#include <vector>   
#include <fstream>  
#include <cctype>

using namespace std;

int main()
{
    vector<string> text;
    vector<int> jumlah;

    ifstream masukan("input.txt");
    ofstream keluaran("output.json");
    
    while(masukan.good())
    {
        string temp;
        bool TF = true;

        masukan >> temp;

        for(auto &i : temp) i = tolower(i);

        for(int i=0; i<temp.size(); ++i)
        {
            char ch = temp[i];
            if(!(((ch>=97) && (ch<=122)) || ((ch>=65) && (ch<=90)))) 
            {
                temp.erase(temp.begin() + i);
                i--;
            }
        }
        
        for(int i=0; i<text.size(); i++)
            if(text[i] == temp)
            {
                jumlah[i]++;
                TF = false;
                break;                
            }
        
        if(TF)
        {
            text.push_back(temp);
            jumlah.push_back(1);
        }
    }

    keluaran << "{\n";
    
    for(int i=0; i<text.size(); i++)
    {   
        keluaran << "\"" << text[i] << "\"" << ": " << jumlah[i];

        if(i != text.size()-1) keluaran << ",";

        keluaran << "\n";
    }

    keluaran << "}";

    keluaran.close();

    return 0;
}