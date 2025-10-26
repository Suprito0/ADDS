#include "DocumentManager.h"
#include <utility>

void DocumentManager::addDocument(string name, int id, int license_limit) {
    // Upsert by id.
    auto& doc = docsById[id];
    doc.id = id;
    doc.license_limit = license_limit;
    // Bind name -> id via Trie (RB-tree children)
    nameIndex.insert(name, id);
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID); // no-op if already present
}

int DocumentManager::search(string name) {
    // Trie exact lookup; returns 0 if not found (per spec)
    return nameIndex.find(name);
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    // Validate patron exists.
    if (patrons.find(patronID) == patrons.end()) return false;

    // Validate document exists.
    auto it = docsById.find(docid);
    if (it == docsById.end()) return false;
    Document& d = it->second;

    // Already holding it? (Disallow double-borrow by same patron.)
    if (d.borrowers.find(patronID) != d.borrowers.end()) return false;

    // Respect license limit
    if ((int)d.borrowers.size() >= d.license_limit) return false;

    d.borrowers.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto it = docsById.find(docid);
    if (it == docsById.end()) return; // unknown doc => nothing to do
    it->second.borrowers.erase(patronID);
}
