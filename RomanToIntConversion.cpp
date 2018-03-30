#include <iostream>
#include <string>
using namespace std;

int getIntValues(char c){
    switch(c){
        case 'i':
        case 'I':
        return 1;
        case 'v':
        case 'V':
        return 5;
        case 'x':
        case 'X':
        return 10;
        case 'l':
        case 'L':
        return 50;
        case 'c':
        case 'C':
        return 100;
        case 'd':
        case 'D':
        return 500;
        case 'm':
        case 'M':
        return 1000;
        default:
        return 0;
    }
}

string getRomVal(int i){
    switch(i){
        case 1: return "I";
        case 4: return "IV";
        case 5: return "V";
        case 9: return "IX";
        case 10: return "X";
        case 40: return "XL";
        case 50: return "L";
        case 90: return "XC";
        case 100: return "C";
        case 400: return "CD";
        case 500: return "D";
        case 900: return "CM";
        case 1000: return "M";
        default: return "";
    }
}

int RomToInt(string rnum){
    int num = 0;
    int i = 0;
    int cv;
    int nv;
    while(rnum[i] != '\0'){
        cv = getIntValues(rnum[i]);
        nv = getIntValues(rnum[i+1]);
        if(cv < nv){
            num += (nv-cv);
            i++;
        }
        else{
            num += cv;
        }
        i++;
    }
    return num;
}

string IntToRom(int num){
    string romNum = "";
    int i = 1;
    int n;
    while(num)
    {
        n = num%10;
        
        if(n){
            if(getRomVal(n*i) != ""){
                romNum =  getRomVal(n*i) + romNum;
            }
            else{
                for(int j = 1; j <= n; j++){
                    romNum =  getRomVal(i) + romNum;    
                }
            }
        }
        
        num = num/10;
        i *= 10;
    }
    
    return romNum;
    
}



int main() {
    cout << RomToInt("CLIV") << endl;
    cout << IntToRom(144) << endl;
    return 0;
}