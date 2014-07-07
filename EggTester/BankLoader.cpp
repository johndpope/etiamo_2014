//
//  BankLoader.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/4/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "BankLoader.h"

BankLoader::BankLoader(string  path)
{
    synthRoot = path;
}


void BankLoader::load(string name)
{
    string fullPath = synthRoot + name;
    printf("\nloading bank %s", fullPath.c_str());
    
    streampos size;
    char * memblock;
    
    ifstream file (fullPath, ios::in|ios::binary|ios::ate);
    
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();
        
        // check signature
        if(memblock[0]=='e' && memblock[1]=='t' && memblock[2]=='i' && memblock[3]=='a' )
        {
            cout << "\nhave magic number etia";
            int version = (memblock[BANK_VERSION+1] << 8) | (memblock[BANK_VERSION]);
            program  = memblock[BANK_PROGRAMLAST];
            
             cout << "loadin " << program;
            memcpy(&param[0], &memblock[BANK_PATCHDATA], 129 * 128);
        }
        else
        {
             cout << "not an etiamo file";
        }
        delete[] memblock;
    }
}

string BankLoader::find()
{
    return "";
}

void BankLoader::loadPatch()
{
    memcpy(&param[0], &param[128 + 128 * program], 128);
    cout << "load patch";
}

void BankLoader::savePatch()
{
    memcpy(&param[128 + 128 * program], &param[0], 128);
}

void BankLoader::save(string name)
{
    
    memcpy(&param[128 + 128 * program], &param[0], 128);
    
    string fullPath = synthRoot + name;
    ofstream myfile;
    myfile.open (fullPath, ios::out | ios::trunc | ios::binary);
    
    // 0 magic
    myfile << "etia";
    
    // 4 version
    myfile.write((char*)&version,2);
    
    // 6 type
    char type = 1;
    myfile.write((char*)&type,1); //4
    
    // 7 program
     myfile << program;
    
    cout << "saving " << program;

    // license
    myfile.write((char*)&program, 4);
    
    // compression
    myfile.write((char*)&program, 4);
    
    // lenth
    myfile.write((char*)&program, 4);
    
    // checksum
    myfile.write((char*)&program,4);
    
    // patchdata
    myfile.write((char*)&param[0], 129 * 128);
    myfile.close();
}
