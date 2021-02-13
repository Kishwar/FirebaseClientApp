//
// Class: authenticate (firebase -> Authentication)
//
// Auther: Kishwar Kumar
// Date:   08.02.2021
//
//

#include "authenticate.h"
#include <iostream>

authenticate::authenticate() {
    std::cout << "LOG: " << __FUNCTION__ << std::endl;

    AppOp = new firebase::AppOptions();
    AppOp->set_app_id(app_id.c_str());
    AppOp->set_api_key(api_ky.c_str());
    AppOp->set_project_id(pro_id.c_str());

}

authenticate::~authenticate() {
    std::cout << "LOG: " << __FUNCTION__ << std::endl;
    delete AppOp;
    delete auth;
    AppOp = nullptr;
    auth = nullptr;
}

int authenticate::sign_in_sync(std::string email, std::string password, std::string &error) {
    std::cout << "LOG: " << __FUNCTION__ << std::endl;

    app = firebase::App::Create(*AppOp);
    auth = firebase::auth::Auth::GetAuth(app);

    firebase::Future<firebase::auth::User*> result =
        auth->SignInWithEmailAndPassword(email.c_str(), password.c_str());

    //while(result.status() == firebase::kFutureStatusPending) {
    //    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //}

    if(result.error() == firebase::auth::kAuthErrorNone) {
        std::cout << "LOG: " << __FUNCTION__  << "SUCCESSFULL SIGNED IN" << std::endl;
        return 0;
    } else {
        error = result.error_message();
        delete auth;
        delete app;
        app = nullptr;
        auth = nullptr;
        return 1;
    }
}

void authenticate::sign_out(void) {
    std::cout << "LOG: " << __FUNCTION__ << std::endl;

    if(auth != NULL) {
        auth->SignOut();
    }
}
