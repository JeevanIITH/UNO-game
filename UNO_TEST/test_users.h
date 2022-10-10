/*    Copyright (C) 2021  Srivatsan-T,jatin-tarachandani,JeevanIITH,shashank-anirudh-rachapalle

    This file is part of You Know UNO?.

    You Know UNO? is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    You Know UNO? is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef TEST_USERS_H
#define TEST_USERS_H

#include <QObject>
#include "users.h"
#include <QtTest/QTest>

class test_users : public QObject
{
    Q_OBJECT
    users h;

private slots:
    void test_users_object();
    void test_minutes();
};

#endif // TEST_USERS_H
