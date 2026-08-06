// all questions + score tracking

#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <Arduino.h>

// Question Structure

struct Question {

    String question;

    String choices[6];

};

// Total Questions

const int QUESTION_COUNT = 12;

// Questions

static const Question questions[QUESTION_COUNT] = {

{
"Your biggest\nstrength?",

{
"Kindness",
"Humor",
"Confidence",
"Creativity",
"Loyalty",
"Ambition"
}
},

{
"Dream first\ndate?",

{
"Arcade",
"Beach",
"Cafe",
"Soccer Match",
"Movie",
"Picnic"
}
},

{
"Friends say\nyou are...",

{
"Funny",
"Calm",
"Caring",
"Competitive",
"Quiet",
"Outgoing"
}
},

{
"Favorite\ncolor?",

{
"Blue",
"Red",
"Black",
"Pink",
"Green",
"Purple"
}
},

{
"Weekend\nplans?",

{
"Watch Soccer",
"Gaming",
"Shopping",
"Travel",
"Sleep",
"Cooking"
}
},

{
"Green flag?",

{
"Kind",
"Funny",
"Loyal",
"Confident",
"Patient",
"Honest"
}
},

// The Adafruit GFX default font is 8-bit CP437 and has no
// emoji glyphs, so these are words. Order matches the
// trait order used everywhere else: kindness, humor,
// confidence, creativity, loyalty, ambition.
{
"Pick a\nvibe.",

{
"Heart",
"Laugh",
"Sunglasses",
"Sparkle",
"Soccer Ball",
"Fire"
}
},

{
"Love\nlanguage?",

{
"Quality Time",
"Words",
"Gifts",
"Acts",
"Touch",
"Support"
}
},

{
"Favorite\nanimal?",

{
"Dog",
"Cat",
"Wolf",
"Fox",
"Penguin",
"Rabbit"
}
},

{
"Dream\nvacation?",

{
"Japan",
"Italy",
"Brazil",
"Greece",
"Iceland",
"Paris"
}
},

{
"Biggest\nturn-on?",

{
"Confidence",
"Humor",
"Kindness",
"Intelligence",
"Loyalty",
"Passion"
}
},

{
"Lucky\nnumber?",

{
"7",
"9",
"10",
"11",
"21",
"99"
}
}

};

#endif