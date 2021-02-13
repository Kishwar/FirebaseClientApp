//
// Class: authenticate (firebase -> Authentication)
//
// Auther: Kishwar Kumar
// Date:   08.02.2021
//
//

#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include "firebase/app.h"
#include "firebase/auth.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

class authenticate
{
    std::string app_id{<<mobilesdk_app_id from your google-services.json>>};
    std::string api_ky{<<current_key from your google-services.json>>};
    std::string pro_id{<<project_id from your google-services.json>>};
    firebase::auth::Auth* auth = NULL;
public:
    firebase::AppOptions *AppOp = NULL;
    firebase::App* app = NULL;
    authenticate();
    ~authenticate();
    int sign_in_sync(std::string email, std::string password, std::string &error);
    void sign_out();
};

#endif // AUTHENTICATE_H
