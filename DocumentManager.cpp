#include "DocumentManager.h"
#include <utility>

void DocumentManager::addDocument(string name, int id, int license_limit) {
    auto& doc = docsById[id];
    doc.id = id;
    doc.license_limit = license_limit;
    nameIndex.insert(name, id);
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID); 
}

int DocumentManager::search(string name) {
    return nameIndex.find(name);
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) return false;

    auto it = docsById.find(docid);
    if (it == docsById.end()) return false;
    Document& foundDoc = it->second;

    if (foundDoc.borrowers.find(patronID) != foundDoc.borrowers.end()) return false;

    if ((int)foundDoc.borrowers.size() >= foundDoc.license_limit) return false;

    foundDoc.borrowers.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto it = docsById.find(docid);
    if (it == docsById.end()) return;
    it->second.borrowers.erase(patronID);
}
