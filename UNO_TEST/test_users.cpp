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


#include "test_users.h"

void test_users::test_users_object()
{
    h = users(2,true); //implies the card deck has 108 regular cards and 2 color_drop cards
    h.generate_deck();
    QCOMPARE(h.deck.size(),110);
    h.fill_up_players(h.get_num_user());
    QCOMPARE(h.get_player_list().size(),h.get_num_user());
    QCOMPARE(h.get_player_list()[0].size(),10);
}


void test_users::test_minutes()
{
    h = users(4,true);
    QCOMPARE(h.get_player_list().size(),4);
    h.generate_deck();
    h.fill_up_players(h.get_num_user());
    unsigned color_drop_count = 0;
    for(unsigned i = 1;i<4;i++)
    {
        for(unsigned j=0;j<10;j++)
        {
            if(h.get_player(i)[j].get_number() == number_t::COLOR_DROP)
            {
                color_drop_count++;
            }
        }

    }

    QVERIFY2(color_drop_count<=4,"Color drop produced more than intended");

    for(unsigned i=0;i<h.get_game_deck().size();i++)
    {
        if(h.get_game_deck()[i].get_number() == number_t::COLOR_DROP)
        {
            color_drop_count++;
        }
    }

    QVERIFY2(color_drop_count == 4,"Wrong Color Drop Count");

}



