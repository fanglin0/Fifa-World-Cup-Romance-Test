// pplayer data for results you can get

#ifndef PLAYERS_H
#define PLAYERS_H

#include <Arduino.h>

// Player Structure

struct Player {

    String name;

    int kindness;
    int humor;
    int confidence;
    int creativity;
    int loyalty;
    int ambition;

    String title;
    String description;
    String warning;

};

// Total Players

const int PLAYER_COUNT = 12;

// Player Database

static const Player players[PLAYER_COUNT] = {

{
"Lionel Messi",
5,3,4,4,5,4,
"Soulmates",
"You value loyalty, kindness, and teamwork. Together, you'd make a calm but unstoppable couple.",
"Both of you avoid arguments... until soccer is involved."
},

{
"Cristiano Ronaldo",
2,2,5,3,4,5,
"Power Couple",
"You both dream big and push each other to succeed.",
"Two stubborn people can be a challenge!"
},

{
"Neymar Jr.",
3,5,4,5,3,3,
"Fun & Flirty",
"Life with Neymar is full of laughter, adventure, and unforgettable dates.",
"You might spend too much money together."
},

{
"Kylian Mbappe",
3,3,5,3,3,5,
"Adventure Duo",
"You love excitement and always chase your goals together.",
"Slow days may feel boring."
},

{
"Son Heung-min",
5,4,4,3,5,4,
"Golden Match",
"You both care deeply about family and always support each other.",
"You'll both apologize at the same time."
},

{
"Luka Modric",
5,2,3,4,5,3,
"Best Friends",
"Your relationship is built on patience and trust.",
"Someone eventually has to choose the restaurant."
},

{
"Erling Haaland",
3,2,5,2,3,5,
"Dynamic Duo",
"You both have huge energy and confidence.",
"Neither of you likes losing."
},

{
"Jude Bellingham",
4,4,4,4,4,4,
"Perfect Balance",
"You complement each other in almost every way.",
"Your biggest problem is deciding what to do on dates."
},

{
"Vinicius Jr.",
3,5,4,5,3,4,
"Spark",
"You keep each other's lives exciting and unpredictable.",
"You'll probably laugh during serious conversations."
},

{
"Harry Kane",
4,2,3,2,5,5,
"Reliable Romance",
"Your relationship grows stronger over time.",
"You both overthink everything."
},

{
"Kevin De Bruyne",
5,3,4,5,5,4,
"Dream Team",
"You communicate well and solve problems together.",
"Neither of you remembers where you parked."
},

{
"Pedri",
5,4,3,5,4,3,
"Slow Burn",
"The friendship comes first, then romance follows naturally.",
"It may take a while before someone makes the first move."
}

};

#endif