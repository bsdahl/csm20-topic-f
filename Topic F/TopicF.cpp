//
//  main.cpp
//  Topic F
//
//  Created by user on 11/11/15.
//  Copyright (c) 2015 CSM20. All rights reserved.
//
// Status: Working in Xcode and VStudio 13
// Note that Windows uses CRLF, on Mac/Unix I use /r as delim, this will cause visual studio to crash, so instead we use /n.
// There is a #define in soundtrack.cpp to handle the differences between the two compilers


#pragma warning (disable: 4290)

#include <iostream>
#include <vector>
#include "AVL.h"
#include "Soundtrack.h"

bool readInputAVL(AvlTree<soundtrack>  &obj, const string & filename);

template<class ItemType>
void display(ItemType& entries);

void displayFifties(soundtrack& entry);

int main() {
    AvlTree<soundtrack> avlTree;
    string fileName = "Topic F Soundtrack.txt";
    cout << "Create and populate AVL tree\n\n";
    
    readInputAVL(avlTree, fileName);
    
    cin.ignore( cin.rdbuf()->in_avail() );
    cout << "\n\n************************************* Press Enter to continue  -->  ";
    cin.ignore();
    
    cout << "Get item with key \"FSMBox 03 Disc 8\":\n\n";
    soundtrack FSM;
    FSM.setLabel("FSM");
    FSM.setCat_Num("Box 03 Disc 8");
    if ( !avlTree.get(FSM) )
        cout << "No items found with key \"FSMBox 03 Disc 8\"\n\n";
    cout << "\n\nGet item with key \"FSMBox 07 Disc 8\":\n\n";
    soundtrack FSM2;
    FSM2.setLabel("FSM");
    FSM2.setCat_Num("Box 07 Disc 8");
    if (!avlTree.get(FSM2))
        cout << "No items found with key \"FSMBox 07 Disc 8\"\n";
    
    cin.ignore( cin.rdbuf()->in_avail() );
    cout << "\n\n************************************* Press Enter to continue  -->  ";
    cin.ignore();
    
    cout << "Listing of all items in the tree: (There are " << avlTree.getNumberOfNodes() << " items in the tree)\n\n";
    avlTree.inorderTraverse(display);
    
    cin.ignore( cin.rdbuf()->in_avail() );
    cout << "\n\n************************************* Press Enter to continue  -->  ";
    cin.ignore();
    
    cout << "\n\nList all soundtracks recorded in the 1950s:\n\n";
    avlTree.inorderTraverse(displayFifties);
    
    cin.ignore( cin.rdbuf()->in_avail() );
    cout << "\n\n************************************* Press Enter to continue  -->  ";
    cin.ignore();
    
    cout << "\n\nDelete all items with key \"FSM V8N11\":";
    soundtrack dltFSM;
    dltFSM.setLabel("FSM");
    dltFSM.setCat_Num("V8N11");
    if (avlTree.get(dltFSM))
    {
        avlTree.remove(dltFSM);
        cout << dltFSM << "\nhas been deleted\n\n";
    }
    cout << "Again delete all items with key \"FSM V8N11\":\n";
    if (avlTree.get(dltFSM))
    {
        avlTree.remove(dltFSM);
        cout << dltFSM << "\nhas been deleted\n\n";
    }
    else
        cout << "NO items for \"FSM V8N11\"";
    
    cin.ignore( cin.rdbuf()->in_avail() );
    cout << "\n\n************************************* Press Enter to continue  -->  ";
    cin.ignore();
    
    cout << "\nListing of all items in the tree: (There are " << avlTree.getNumberOfNodes() << " items in the tree)\n";
    avlTree.inorderTraverse(display);
    
    cin.ignore( cin.rdbuf()->in_avail() );
    cout << "\n\nProgram Ending\n\n";
    cout << "Press Enter to end -->  ";
    cin.ignore();
    
    return 0;
}


bool readInputAVL(AvlTree<soundtrack> &obj, const string & filename)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "\nInput file" << filename << " cannot be found" << endl;
        return false;
    }
    
    soundtrack sound;
    bool ableToAdd;
    
    while (!in.eof())
    {
        ableToAdd = true;
        in >> sound;
        if (!(sound.getReleased() == 1900))
            ableToAdd = obj.add(sound);
        if (!ableToAdd)
            cout << sound << " is a duplicate" << endl;
    }
    
    in.close();
    return true;
}


template<class ItemType>
void display(ItemType& entries)
{
    cout << entries;
}

void displayFifties(soundtrack& entry)
{
    vector<string> years = { "50", "51", "52", "53", "54", "55", "56", "57", "58", "59" };
    for (unsigned int i = 0; i < years.size(); i++)
    {
        if (entry.getRecorded().substr(2, 2) == years[i])
            cout << entry;
    }
}