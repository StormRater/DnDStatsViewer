#ifndef CHARACTER_H
#define CHARACTER_H

#include "NRJ_String.h"

class Character {
        int passivePerception,
                passiveInsight,
                armorClass,
                level;
        String CharName, PlayerName, Class, Race, Status;
        Character();
        public:
        explicit        Character( const char[], const char[], const char[], const char[], const char[], const int, const int, const int, const int );
        explicit        Character( const String &, const String &, const String &, const String &, const String &, const int, const int, const int, const int );
                        ~Character();
                        void setCharName        ( const char[] );
                        void setCharName        ( const String & );
                        void setPlayerName      ( const char[] );
                        void setPlayerName      ( const String & );
                        void setClass           ( const char[] );
                        void setClass           ( const String & );
                        void setRace            ( const char[] );
                        void setRace            ( const String & );
                        void setStatus          ( const char[] );
                        void setStatus          ( const String & );
                        void setPP              ( const int );
                        void setPI              ( const int );
                        void setAC              ( const int );
                        void setLevel           ( const int );


};

Character::Character() {

}


#endif
