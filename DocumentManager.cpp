#include "DocumentManager.h"

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    if (license_limit < 0) license_limit = 0;

    if (docs.find(id) != docs.end()) return;
    if (nameToID.find(name) != nameToID.end()) return;

    Document doc;
    doc.name = name;
    doc.id = id;
    doc.license_limit = license_limit;

    docs.emplace(id, move(doc));
    nameToID.emplace(name, id);
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(string name) {
    auto it = nameToID.find(name);
    return (it == nameToID.end()) ? 0 : it->second;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    auto dit = docs.find(docid);
    if (dit == docs.end()) return false;         
    if (patrons.find(patronID) == patrons.end()) return false; 

    Document& d = dit->second;
    if (d.borrowers.find(patronID) != d.borrowers.end()) return false;

    if (static_cast<int>(d.borrowers.size()) >= d.license_limit) return false;

    d.borrowers.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto dit = docs.find(docid);
    if (dit == docs.end()) return; 
    dit->second.borrowers.erase(patronID);
}
