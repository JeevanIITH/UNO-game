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



#include <QApplication>
#include "soundclass.h"
#include "test_card.h"
#include "test_users.h"
#include "test_game.h"
#include "test_sound.h"

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    TEST_CARD a;
    test_users b;
    test_game c;
    QTest::qExec(&a);
    QTest::qExec(&b);
    QTest::qExec(&c);

    TEST_SOUND sd;
    QTest::qExec(&sd);

    return 0;
}
