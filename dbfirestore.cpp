//
// Class: dbfirestore (firebase -> firestore)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

#include "dbfirestore.h"
#include "defines.h"

dbfirestore::dbfirestore() {

    std::map<std::string, std::vector<std::string>> pdata;
    std::vector<std::string> xdata{"100"};
    std::vector<std::string> ydata{"200"};
    std::vector<std::string> zdata{"300"};

    pdata["name"] = xdata;
    pdata["job"] = ydata;
    pdata["city"] = zdata;

    storedata("a00002", pdata);
}


dbfirestore::~dbfirestore() {

}


int dbfirestore::storedata(std::string id, std::map<std::string, std::vector<std::string>> &data) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    firebase::firestore::Firestore* db = firebase::firestore::Firestore::GetInstance();
    firebase::firestore::CollectionReference odata = db->Collection("data");
    firebase::firestore::MapFieldValue firedata;

    for (std::map<std::string, std::vector<std::string>>::iterator it=data.begin(); it!=data.end(); ++it) {
        firedata.insert(std::make_pair(it->first, firebase::firestore::FieldValue::String(it->second[0])));
    }

    odata.Document(id).Set(firedata);

    return FIREBASE_NO_ERROR;
}


/*
    odata.Document(id).Set({
        {"name", firebase::firestore::FieldValue::String("San Francisco")},
        {"state", firebase::firestore::FieldValue::String("CA")},
        {"country", firebase::firestore::FieldValue::String("USA")},
        {"capital", firebase::firestore::FieldValue::Boolean(false)},
        {"population", firebase::firestore::FieldValue::Integer(860000)},
        {"regions", firebase::firestore::FieldValue::Array({firebase::firestore::FieldValue::String("west_coast"),
                                       firebase::firestore::FieldValue::String("norcal")})},
    });
*/
