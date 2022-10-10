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


#ifndef TEST_CARD_H
#define TEST_CARD_H

#include <QtTest>
#include <QCoreApplication>
#include <QObject>
// add necessary includes here
#include "card.h"

class TEST_CARD : public QObject
{
    Q_OBJECT
    card c;

private slots:
    void test_card_properties();
    void test_random_card();
    void cleanupTestCase();
};

#endif // TST_TEST_H
