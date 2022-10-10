#ifndef TEST_SOUND_H
#define TEST_SOUND_H

#include <QObject>
#include <QtTest>
#include <QCoreApplication>

#include "soundclass.h"


class TEST_SOUND : public QObject
{
    Q_OBJECT
public:
    TEST_SOUND();
    ~TEST_SOUND();
private slots:
    void initilisation_1();
    void delete_sounds();
    void check_lists();

};

#endif // TEST_SOUNDS_H
