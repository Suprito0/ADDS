#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit){
    this->docList.push_back(new Documents(name, id, license_limit));
}
void DocumentManager::addPatron(int patronID){
    this->listOfPatronID.push_back(patronID);
}
int DocumentManager::search(string name){
    for(Documents* doc : this->docList){
        if(doc->name == name){
            return doc->docid;
        }
    }
    return 0;
} // returns docid if name is in the document collection or 0 if the name is not in the collection
bool DocumentManager::borrowDocument(int docid, int patronID){
    bool found = false;
    Documents* pickedDoc;
    for(Documents* doc : this->docList){
        if(doc->docid == docid){
            pickedDoc = doc;
            found = true;
            break;
        }
    }
    if(!found || pickedDoc->numOfPatronsWithAccess >= pickedDoc->limitOfPatrons){
        return false;
    }
    pickedDoc->listOfPatronWithAccess.push_back(patronID);
    pickedDoc->numOfPatronsWithAccess++;
    return true;
}  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
void DocumentManager::returnDocument(int docid, int patronID){
    bool found = false;
    Documents* pickedDoc;
    for(Documents* doc : this->docList){
        if(doc->docid == docid){
            pickedDoc = doc;
            found = true;
            break;
        }
    }
    if(!found){
        return;
    }
    found = false;
    int index = 0;
    for(int pID : pickedDoc->listOfPatronWithAccess){
        if(pID == patronID){
            found = true;
            break;
        }
        index++;
    }
    if(!found){
        return;
    }
    pickedDoc->listOfPatronWithAccess.erase(pickedDoc->listOfPatronWithAccess.begin() + index);
    pickedDoc->numOfPatronsWithAccess--;
}