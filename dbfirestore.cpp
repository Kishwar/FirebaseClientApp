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
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;
}


dbfirestore::~dbfirestore() {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;
}


int dbfirestore::storedata(std::string id, std::map<std::string, std::vector<std::string>> &data) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    firebase::firestore::Firestore *db = firebase::firestore::Firestore::GetInstance();
    firebase::firestore::CollectionReference odata = db->Collection("data");
    firebase::firestore::MapFieldValue firedata;
    std::vector<firebase::firestore::FieldValue> load;

    for (std::map<std::string, std::vector<std::string>>::iterator it=data.begin(); it!=data.end(); ++it) {

        for(auto &d : it->second) {
            load.push_back(firebase::firestore::FieldValue::String(d));
        }

        firedata.insert(std::make_pair(it->first, firebase::firestore::FieldValue::Array(load)));
        load.clear();
    }

    odata.Document(id).Set(firedata);

    return FIREBASE_NO_ERROR;
}

void dbfirestore::getnextid_async(void) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    firebase::firestore::Firestore *db = firebase::firestore::Firestore::GetInstance();

    db->Collection("data").Get().OnCompletion(
        [this](const firebase::Future<firebase::firestore::QuerySnapshot>& future) mutable {
            if (future.error() == firebase::firestore::Error::kErrorOk) {
                std::string nextid = "a00000000000000000000000000000000";
                char buf[34];
                int val = 0;

                nextid = (*--future.result()->documents().cend()).id();
                val = std::stoi(nextid.substr(1));
                ++val;

                sprintf(buf, "a%032d", val);
                nextid = buf;

                this->nextid(nextid);
            }
        });
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

    std::map<std::string, std::vector<std::string>> pdata;
    std::vector<std::string> xdata{"100"};
    std::vector<std::string> ydata{"200"};
    std::vector<std::string> zdata{"300","400","500"};

    pdata["name"] = xdata;
    pdata["job"] = ydata;
    pdata["city"] = zdata;

    storedata("a00003", pdata);
*/
