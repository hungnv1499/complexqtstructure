#ifndef MYAPP_H
#define MYAPP_H

#include <QObject>

class MyApp : public QObject {
    Q_OBJECT

public:
    explicit MyApp(QObject *parent = nullptr);

    Q_INVOKABLE QString getMessage();  // Callable from QML

signals:
    void messageChanged();

private:
    QString message;
};

#endif // MYAPP_H
