/****************************************
	Topic A Project 

	CS M20

	soundtrack.cpp

**************************************/

#define XCODE
//#define VSTUDIO

#include "Soundtrack.h"


bool soundtrack::operator == (const soundtrack & right) const
{
    if ( (label == right.label) && (cat_num == right.cat_num) )
        return true;
    else
        return false;
}

bool soundtrack::operator>(const soundtrack& right) const
{
    if (     (label >  right.label)
        || ( (label == right.label) && (cat_num >  right.cat_num) ) )
        return true;
    else
        return false;
}

bool soundtrack::operator<(const soundtrack& right) const
{
    if (     (label <  right.label)
        || ( (label == right.label) && (cat_num <  right.cat_num) ) )
        return true;
    else
        return false;
}


ostream &operator << (ostream & out, const soundtrack & val)
{
	out << val.getComposer() << "  " << val.getTitle() << "  " << val.getLabel() << "  "
		<< val.getCat_Num() << "  " << val.getRecorded() << "  " << val.getReleased() << endl;

	return out;
}

istream &operator >> (istream &in, soundtrack &val)
{
    string buff;
    string delim = " \t";
    
#ifdef XCODE
    getline(in, buff, '\r');
#endif
#ifdef VSTUDIO
    getline(in, buff, '\n');
#endif
    
    string tempComposer;
    tempComposer = buff.substr(0, 24);
    string composer = tempComposer.substr(0, tempComposer.find_last_not_of(delim) + 1);
    val.setComposer(composer);
    
    string tempTitle;
    tempTitle = buff.substr(24, 40);
    string title = tempTitle.substr(0, tempTitle.find_last_not_of(delim) + 1);
    val.setTitle(title);
    
    string tempLabel;
    tempLabel = buff.substr(64, 16);
    string label = tempLabel.substr(0, tempLabel.find_last_not_of(delim) + 1);
    val.setLabel(label);
    
    string tempCatalogNumber;
    tempCatalogNumber = buff.substr(80, 24);
    string catalogNumber = tempCatalogNumber.substr(0, tempCatalogNumber.find_last_not_of(delim) + 1);
    val.setCat_Num(catalogNumber);
    
    string tempDateRecorded;
    tempDateRecorded = buff.substr(104, 8);
    string dateRecorded = tempDateRecorded.substr(0, tempDateRecorded.find_last_not_of(delim) + 1);
    val.setRecorded(dateRecorded);
    
    try
    {
        int intBuff = stoi(buff.substr(112, 4));
        val.setReleased(intBuff);
    }
    catch (std::exception)
    {
        cout << endl << endl << buff.substr(112, 4) << " is not a numeric value.  This input ignored:\n";
        cout << val << "   " << buff.substr(112, 4) << endl;
        val.setReleased(1900);
    }

	return in;
}