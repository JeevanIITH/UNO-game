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


#ifndef BOT_PLAYER_H
#define BOT_PLAYER_H


#include"card.h"
#include"game.h"
#include"users.h"
#include<QVector>
#include<QString>
class bot_player
{

    QVector<card> legal_set;
    card last_card;
public:

    bot_player();
    int botMove(game* g, users* h, QVector<card>* current_hand, int player_id);
    int checkForcingMoves(QVector<card>* current_hand);//check legal_set and last_card for any forcing moves, like a draw 2/4, returns the index of the card to be played, -1 if no forces
    int checkForUno(QVector<card>* current_hand, int player_id, int number_players, users* h, game* g);//checks to see if the next player has one card, and looks for the strongest special card to play
    int nonSpecialMove();
    int lookForSpecial();
    void generateLegalSet(QVector<card>* current_hand);//legal_set cleared everytime botMove() is called
};


#endif // BOT_PLAYER_H
