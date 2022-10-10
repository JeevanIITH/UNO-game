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


#include "test_game.h"


void test_game::test_win()
{
    QVERIFY2(g == nullptr,"Init case not working");
    g = new game(2,true);
    for(unsigned i=0;i<g->h.get_num_user();i++)
    {
        QVERIFY2(g->win_list[i] == false,"Win value true at beginning");
    }
}

void test_game::test_start()
{
     //QVERIFY2(g == nullptr,"Cleanup case not working");
     g = new game(4,true);
     g->start_game();
     QCOMPARE(g->deck_back[0]->text(),g->h.get_game_deck().back().get_color_string()+"-"+g->h.get_game_deck().back().get_number_string());

}

void test_game::move_available()
{
    g = new game(2,true);
    g->start_game();
    g->h.get_game_deck().back() = card(color_t::GREEN,number_t::FOUR);
    for(unsigned i=0;i<10;i++)
    {
        if(g->h.get_player(1)[i].get_color() ==color_t::GREEN || g->h.get_player(1)[i].get_number() == number_t::FOUR || g->h.get_player(1)[i].get_number() == number_t::DRAW_FOUR_WILD || g->h.get_player(1)[i].get_number() == number_t::WILD|| g->h.get_player(1)[i].get_number() == number_t::COLOR_DROP )
        {
            g->h.get_player(1)[i] = card(color_t::BLUE,number_t::EIGHT);
        }
    }
    QVERIFY2(g->is_move_available(1) == false,"is-move-available not working");
    bool value = false;
    unsigned drop_count = 0;
    for(unsigned i=0;i<10;i++)
    {
        g->h.get_player(1)[i] = card(color_t::NO_COLOR,number_t::DRAW_FOUR_WILD);
    }
    for(unsigned i=1;i<11;i++)
    {
        value = g->card_drop(1,i);
        if(value)
        {
            drop_count++;
        }
    }
    QVERIFY2(drop_count == 10,"Card drop not working properly");
}

void test_game::test_add_card()
{
    g = new game(2,false);
    g->start_game();
    card back = g->h.get_game_deck()[0];
    g->player_add(1);
    card added = g->h.get_player(1)[10];
    QVERIFY2(back == added,"Player add not perfect");
}


void test_game::initTestCase()
{
    g = nullptr;
}

void test_game::cleanupTestCase()
{
    g = nullptr;
}
