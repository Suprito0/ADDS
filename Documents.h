#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

class Documents{
    private:
        string name;
        int docid;
        int numOfPatronsWithAccess;
        int limitOfPatrons;
        vector<int> listOfPatronWithAccess;

        Documents();
        Documents(string name, int id, int license_limit);

        friend class DocumentManager;
};

#endif