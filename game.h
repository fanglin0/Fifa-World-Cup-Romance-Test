#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

// Game States

enum GameState {

    TITLE,
    INTRO,
    QUESTION,
    LOADING,
    RESULT,
    PROFILE,
    ENDING

};

// Current Game State

extern GameState gameState;

// Quiz Settings

const int TOTAL_QUESTIONS = 12;
const int CHOICES_PER_QUESTION = 6;

// Current Progress

extern int currentQuestion;
extern int currentChoice;

// Stores the player's answers
extern int answers[TOTAL_QUESTIONS];

// Compatibility Results

extern int compatibilityScore;
extern int matchedPlayer;

// Loading Screen

extern int loadingProgress;
extern unsigned long loadingTimer;

// Title Screen Animation

extern bool heartVisible;
extern unsigned long heartTimer;

// Functions

// Initialize everything
void initGame();

// Update game every frame
void updateGame();

// Reset entire game
void resetGame();

// Button Input

void pressLeft();

void pressRight();

void pressOK();

// Quiz

void nextQuestion();

void calculateCompatibility();

// Drawing

void drawCurrentScreen(Adafruit_SSD1306 &display);

// Loading Screen

void updateLoading();

#endif