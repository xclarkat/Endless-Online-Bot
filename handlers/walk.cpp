// Endless Online Bot v0.0.1

#include "handlers.hpp"
#include "../singleton.hpp"

void Walk_Player(PacketReader reader)
{
    S &s = S::GetInstance();

    short gameworld_id = reader.GetShort();

    int i = s.map.GetCharacterIndex(gameworld_id);
    if(i == -1) return;

    s.map.characters[i].direction = static_cast<Direction>(reader.GetChar());
    s.map.characters[i].x = reader.GetChar();
    s.map.characters[i].y = reader.GetChar();

    if(s.eprocessor.sex_act.get())
    {
        if(gameworld_id ==  s.eprocessor.sex_act->victim_gameworld_id)
        {
            if(s.map.characters[i].x == s.character.x && s.map.characters[i].y == s.character.y)
            {
                s.eprocessor.sex_act->fuck = true;
            }
            else
            {
                s.eprocessor.sex_act->fuck = false;
            }
        }
    }
}