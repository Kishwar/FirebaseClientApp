#ifndef DEFINES_H
#define DEFINES_H

enum error_codes {
    FIREBASE_NO_ERROR = 0,
    FIREBASE_AUTH_ERROR_NOT_VALID_USER,
    FIREBASE_FIRESTORE_DB_FAILED
};

inline void PARAMETER_NOT_USED(void *param) {
    param = (void *)param;
}

#endif // DEFINES_H
