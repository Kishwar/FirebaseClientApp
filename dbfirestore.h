//
// Class: dbfirestore (firebase -> firestore)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

#ifndef DBFIRESTORE_H
#define DBFIRESTORE_H

#include "firebase/firestore.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class dbfirestore
{
public:
    dbfirestore();
    ~dbfirestore();
    int storedata_async(std::string id, std::map<std::string, std::vector<std::string>> &data);
    void getnextid_async(void);
    void getSetList_async(void);
    virtual void nextid(std::string &) = 0;
    virtual void result(std::string &) = 0;
    virtual void vlist(std::vector<std::string> &) = 0;
};

#endif // DBFIRESTORE_H
