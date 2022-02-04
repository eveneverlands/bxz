#include <iostream>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

        map<int, string> m = { 
                {0x00, "~"},
                {0x01, "0"},
                {0x02, "1"},
                {0x03, "2"},
                {0x04, "3"},
                {0x05, "4"},
                {0x06, "5"},
                {0x07, "6"},
                {0x08, "7"},
                {0x09, "8"},
                {0x0a, "9"},
                {0x0b, "a"},
                {0x0c, "b"},
                {0x0d, "c"},
                {0x0e, "d"},
                {0x0f, "e"},
                {0x10, "f"},
                {0x11, "g"},
                {0x12, "h"},
                {0x13, "i"},
                {0x14, "j"},
                {0x15, "k"},
                {0x16, "l"},
                {0x17, "m"},
                {0x18, "n"},
                {0x19, "o"},
                {0x1a, "p"},
                {0x1b, "q"},
                {0x1c, "r"},
                {0x1d, "s"},
                {0x1e, "t"},
                {0x1f, "u"},
                {0x20, "v"},
                {0x21, "w"},
                {0x22, "x"},
                {0x23, "y"},
                {0x24, "z"},
                {0x25, "A"},
                {0x26, "B"},
                {0x27, "C"},
                {0x28, "D"},
                {0x29, "E"},
                {0x2a, "F"},
                {0x2b, "G"},
                {0x2c, "H"},
                {0x2d, "I"},
                {0x2e, "J"},
                {0x2f, "K"},
                {0x30, "L"},
                {0x31, "M"},
                {0x32, "N"},
                {0x33, "O"},
                {0x34, "P"},
                {0x35, "Q"},
                {0x36, "R"},
                {0x37, "S"},
                {0x38, "T"},
                {0x39, "U"},
                {0x3a, "V"},
                {0x3b, "W"},
                {0x3c, "X"},
                {0x3d, "Y"},
                {0x3e, "Z"},
                {0x3f, "!"},
                {0x40, "'"},
                {0x41, "#"},
                {0x42, "$"},
                {0x43, "%"},
                {0x44, "&"},
                {0x45, "("},
                {0x46, ")"},
                {0x47, "*"},
                {0x48, "+"},
                {0x49, ","},
                {0x4a, "-"},
                {0x4b, "."},
                {0x4c, "/"},
                {0x4d, ":"},
                {0x4e, ";"},
                {0x4f, "<"},
                {0x50, "="},
                {0x51, ">"},
                {0x52, "?"},
                {0x53, "@"},
                {0x54, "["},
                {0x55, "]"},
                {0x56, "^"},
                {0x57, "_"},
                {0x58, "`"},
                {0x59, "{"},
                {0x5a, "|"},
                {0x5b, "}"}

        };// ! ' # $ % & ( ) * + , - . / : ; < = > ? @ [ ] ^ _ ` { | } ~

        /*fline, sline, tline*/
        string fline = "", sline = "", tline = "", lnkr = "";
        //at 5b, b6, ff
       
	fstream f("/tmp/hd");
	stringstream b;
	b << f.rdbuf();
	vector<string> s; string c;
	while (b >> c){
		s.push_back(c);
		c = "";
	}

        for(int i = 0; i < s.size(); i++) {
		int x = stoi(s[i], nullptr, 16);
                if(strcmp(s[i].c_str(),"5b") <= 0) {
                        fline += m[x];
                        lnkr += "0";
                }
                else if(strcmp(s[i].c_str(), "b6") <= 0) {
                        sline += m[x % 0x5c];
                        lnkr += "1";
                }
                else {
                        tline += m[x % 0x5c];
                        lnkr += "2";
                }
		system(": > /dev/null");
        }

	system(": > /tmp/hd");
	f.seekp(0);
	f << fline << "\n\n"  << sline << "\n\n"  << tline << "\n\n"  << lnkr << endl;
	f.close();

}
