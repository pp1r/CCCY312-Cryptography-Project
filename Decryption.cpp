#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


string plaintext;


string dectobin(int d)
{
	string bin;
	while (d != 0) {
		if (d % 2 == 0)
			bin = "0" +bin ;
		else
			bin = "1" +bin;
		d /= 2;
	}
	while (bin.length() < 4) {
		bin = "0" + bin;
	}
	return bin;
}

int bintodec(string b)
{
	int x = 0;
	int dec = 0;
	int size = b.length();
	for (int i = size - 1; i >= 0; i--)
	{
		if (b[i] == '1') {
			dec += pow(2,x);
		}
		x++;
	}
	return dec;
}


void table(unordered_map<string, char> *um)
{
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}
 


string HexToBin(string hd)
{
    long int i = 0;
    string bin = "";
    while (hd[i]) {
 
        switch (hd[i]) {
        case '0':
            bin.append("0000");
            break;
        case '1':
            bin.append("0001");
            break;
        case '2':
            bin.append("0010");
            break;
        case '3':
            bin.append("0011") ;
            break;
        case '4':
            bin.append("0100");
            break;
        case '5':
            bin.append("0101");
            break;
        case '6':
            bin.append("0110");
            break;
        case '7':
            bin.append("0111");
            break;
        case '8':
            bin.append("1000");
            break;
        case '9':
            bin.append("1001");
            break;
        case 'A':
        case 'a':
            bin.append("1010");
            break;
        case 'B':
        case 'b':
            bin.append("1011");
            break;
        case 'C':
        case 'c':
            bin.append("1100");
            break;
        case 'D':
        case 'd':
            bin.append("1101");
            break;
        case 'E':
        case 'e':
            bin.append("1110");
            break;
        case 'F':
        case 'f':
            bin.append("1111");
            break;
        }
        i++;
    }
    return bin;
}

int index(int t){
    int i;
    switch(t){
        case '0':
            i= 0;
            break;
        case '1':
            i= 1;
            break;
        case '2':
            i= 2;
            break;
        case '3':
            i= 3 ;
            break;
        case '4':
            i= 4;
            break;
        case '5':
            i= 5;
            break;
        case '6':
            i= 6;
            break;
        case '7':
            i= 7;
            break;
        case '8':
            i= 8;
            break;
        case '9':
            i= 9;
            break;
        case 'A':
        case 'a':
            i= 10;
            break;
        case 'B':
        case 'b':
            i= 11;
            break;
        case 'C':
        case 'c':
            i= 12;
            break;
        case 'D':
        case 'd':
            i= 13;
            break;
        case 'E':
        case 'e':
            i= 14;
            break;
        case 'F':
        case 'f':
            i= 15;
            break;
    }
    return i;
}


string bintohex(string bin)
{
    int l = bin.size();
    int t = bin.find_first_of('.');
     
    
    int len_left = t != -1 ? t : l;
     
    
    for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
        bin = '0' + bin;
     
      
    if (t != -1)   
    {
        
        int len_right = l - len_left - 1;
         
        
        for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
            bin = bin + '0';
    }
     
    
    unordered_map<string, char> bin_hex_map;
    table(&bin_hex_map);
     
    int i = 0;
    string hex = "";
     
    while (1)
    {
        
        hex += bin_hex_map[bin.substr(i, 4)];
        i += 4;
        if (i == bin.size())
            break;
             
        
        if (bin.at(i) == '.')   
        {
            hex += '.';
            i++;
        }
    }
     
    
    return hex;   
}



string s_box(string p) {
    
    string sbox[16][16] = {
      
      {"63", "7c", "77", "7b", "f2", "6b", "6f", "c5", 
      "30", "01", "67", "2b", "fe", "d7", "ab", "76"}, 
      {"ca", "82", "c9", "7d", "fa", "59", "47", "f0", 
      "ad", "d4", "a2", "af", "9c", "a4", "72", "c0"}, 
      {"b7", "fd", "93", "26", "36", "3f", "f7", "cc", 
      "34", "a5", "e5", "f1", "71", "d8", "31", "15" },
      {"04", "c7", "23", "c3", "18", "96", "05", "9a", 
      "07", "12", "80", "e2", "eb", "27", "b2", "75" },
      {"09", "83", "2c", "1a", "1b", "6e", "5a", "a0", 
      "52", "3b", "d6", "b3", "29", "e3", "2f", "84" },
      {"53", "d1", "00", "ed", "20", "fc", "b1", "5b", 
      "6a", "cb", "be", "39", "4a", "4c", "58", "cf" },
      {"d0", "ef", "aa", "fb", "43", "4d", "33", "85", 
      "45", "f9", "02", "7f", "50", "3c", "9f", "a8" },
      {"51", "a3", "40", "8f", "92", "9d", "38", "f5", 
      "bc", "b6", "da", "21", "10", "ff", "f3", "d2" },
      {"cd", "0c", "13", "ec", "5f", "97", "44", "17", 
      "c4", "a7", "7e", "3d", "64", "5d", "19", "73" },
      {"60", "81", "4f", "dc", "22", "2a", "90", "88", 
      "46", "ee", "b8", "14", "de", "5e", "0b", "db" },
      {"e0", "32", "3a", "0a", "49", "06", "24", "5c", 
      "c2", "d3", "ac", "62", "91", "95", "e4", "79" },
      {"e7", "c8", "37", "6d", "8d", "d5", "4e", "a9", 
      "6c", "56", "f4", "ea", "65", "7a", "ae", "08" },
      {"ba", "78", "25", "2e", "1c", "a6", "b4", "c6", 
      "e8", "dd", "74", "1f", "4b", "bd", "8b", "8a" },
      {"70", "3e", "b5", "66", "48", "03", "f6", "0e", 
      "61", "35", "57", "b9", "86", "c1", "1d", "9e" },
      {"e1", "f8", "98", "11", "69", "d9", "8e", "94", 
      "9b", "1e", "87", "e9", "ce", "55", "28", "df" },
      {"8c", "a1", "89", "0d", "bf", "e6", "42", "68", 
      "41", "99", "2d", "0f", "b0", "54", "bb", "16" }
    }; 
      
    string t = "";
    int row=0, col=0;
    for(int i = 0; i < 8; i+=2){   
        
        row = index(p[i]);
        col = index(p[i+1]);
        
        t.append(sbox[row][col]);
        
    }
   return t;
}


string s_boxkey(string p)
{
    
    int s[] = {7, 10, 13, 0, 3, 6, 9, 12, 15, 2, 5, 8, 11, 14, 1, 4};
    string sp;
    for(int i = 0; i < 8; i++)
    {
        string r = p.substr(i * 4, 4);
        int num = s[bintodec(r)];
        sp += dectobin(num);
    }
    
    return sp;
}

string ip_keys(string key){
    
	int initial_permutation[32] = { 
	26,18,10,2,28,20,12,4, 
	30,22,14,6,32,24,16,8, 
	25,17,9,1,27,19,11,3, 
	29,21,13,5,31,23,15,7 
	}; 
	
	
  	string p = ""; 
	for(int i = 0; i < 32; i++){ 
		p += key[initial_permutation[i]-1];
	} 
	
	string k = s_boxkey(p);
	return k;
}


string Xor(string a, string b){ 
	string r = ""; 
	int size = b.size();
	for(int i = 0; i < size; i++){ 
		if(a[i] != b[i]){ 
			r += "1"; 
		}
		else{ 
			r += "0"; 
		} 
	} 
	return r; 
}


string encrypt(string k){ 
    
    string sub = s_box(plaintext);
    plaintext = HexToBin(sub);
    
    string xored = Xor(k, plaintext);

	string ciphertext =""; 
	
	ciphertext = xored;
	
	return ciphertext; 
}


int main(){ 
    
	
	string key= ""; 
	string plain="";
	
    ifstream keyfile ("key.txt");
    getline (keyfile, key);
    keyfile.close ();
    
    
    ifstream ptfile ("plain.txt");
    getline (ptfile, plain);
    ptfile.close ();
    
	
  	string generatedKey = ip_keys(HexToBin(key)); 
  	
  	plaintext=plain;
    
	
    string cipehrtext= encrypt(generatedKey); 
    
    ofstream file("cipher.txt");
    file <<bintohex(cipehrtext)<<" ";
    file.close();
    
    cout<<endl<<"Plaintext: "<<plain;
    cout<<endl<<"Key: "<<key;
    cout<<endl<<"Encrypted Ciphertext: "<<bintohex(cipehrtext)<<" ";
}   
