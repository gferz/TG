#include <string> 
#include <vector>  
#include <fstream>  
#include <cctype>       

using namespace std;

int main(){
    vector<string> teks;

    ifstream masukan("input.txt");
    
    while(masukan.good()){
        string st;
        masukan >> st;

        for(int i=0; i<st.size(); ++i){
            char& ch = st[i];

            if(ch == '-' || ch == '_'){
                string sb(st,0,i);
                if(sb != "") teks.push_back(sb);
                st.erase(0,i+1);
                i=-1; continue;
            }

            if(!isalpha(ch) && !isdigit(ch)){
                st.erase(st.begin() + i);
                i--;
            }
	        else if(isalpha(ch) && ch <= 90) ch = tolower(ch); 
        }

        if(st != "") teks.push_back(st);
    }
    masukan.close();

    ofstream keluaran("output.json");

    keluaran << "{\n";
    while(teks.size()){
        string _st = teks[0];

        int jumlah = 0;

        keluaran << "\"" << teks[0] << "\": ";

        for(int i=0; i<teks.size(); i++){
            if(_st == teks[i]){
                jumlah++;
                teks.erase(teks.begin()+i);
                i--;
            }
        }
        keluaran << jumlah;

        if(teks.size() != 0) keluaran << ",";
        keluaran << "\n";
    }   
    keluaran << "}";

    keluaran.close();

    return 0;
}
