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

#include"test_card.h"

void TEST_CARD::test_card_properties()
{
    QCOMPARE(c.get_color(),color_t::NO_COLOR);
    QCOMPARE(c.get_number(), number_t::NO_NUMBER);
    QCOMPARE(c.get_power(),true);
    QCOMPARE(c.get_color_string(),"BLACK");
    QCOMPARE(c.get_number_string(),"NO-NUMBER");
    QPushButton* card_button = c.show_card();
    QCOMPARE(card_button->text(),"BLACK-NO-NUMBER");
}

void TEST_CARD::test_random_card()
{
    c = card(color_t::GREEN,number_t::DRAW_FOUR_WILD); //impossible card
    QCOMPARE(c.get_color(),color_t::GREEN);
    QCOMPARE(c.get_number(), number_t::DRAW_FOUR_WILD);
    QCOMPARE(c.get_power(),true);
    QCOMPARE(c.get_color_string(),"GREEN");
    QCOMPARE(c.get_number_string(),"DRAW-FOUR-WILD");
}


void TEST_CARD::cleanupTestCase()
{
    c = card(color_t::NO_COLOR,number_t::NO_NUMBER);
}
