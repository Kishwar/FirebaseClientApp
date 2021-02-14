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

    odata.Document(id).Set(firedata).OnCompletion(
        [this](const firebase::Future<void> &future) {
            if (future.error() == firebase::firestore::Error::kErrorOk) {
                this->result("Data stored successfully.");
            } else {
               this->result("Failed to store data.");
            }
    });

    return FIREBASE_NO_ERROR;
}

void dbfirestore::getnextid_async(void) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    firebase::firestore::Firestore *db = firebase::firestore::Firestore::GetInstance();

    db->Collection("data").Get().OnCompletion(
        [this](const firebase::Future<firebase::firestore::QuerySnapshot> &future) mutable {
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

