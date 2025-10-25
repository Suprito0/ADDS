#include "Documents.h"

Documents::Documents(){
}

Documents::Documents(string name, int id, int license_limit){
    this->docid = id;
    this->limitOfPatrons = license_limit;
    this->name = name;
    this->numOfPatronsWithAccess = 0;
}

