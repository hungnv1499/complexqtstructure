#include "myapp.h"

MyApp::MyApp(QObject *parent) : QObject(parent), message("Hello from C++!") {
}

QString MyApp::getMessage() {
    return message;
}
