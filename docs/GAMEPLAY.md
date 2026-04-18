# Gameplay Guide

## Overview

The Last War: Tunisia is a side-scrolling 2D adventure where you travel from **Tozeur** to **Djerba**, crossing three distinct regions of Tunisia. Each level ends with a timed puzzle that you must solve to unlock the passage to the next area.

## Levels

### Level 1 — The Desert of Tozeur
The journey begins in the Saharan landscape near Tozeur, home to the iconic Star Wars filming locations. Navigate through desert terrain filled with obstacles and enemies guarding the ancient path.

### Level 2 — The Crossing
The middle section of the journey takes you through Tunisia's heartland. New enemies and more complex terrain challenge your progress as you move closer to the coast.

### Level 3 — Arrival at Djerba
The final stretch leads to the island of Djerba. The most dangerous enemies patrol this area, and the last enigma stands between you and completing the mission.

## Game Systems

### Movement & Scrolling
- The hero moves through a large scrolling map that extends well beyond the visible screen (1920×1080 viewport)
- The camera follows the player, scrolling the background to keep the hero visible
- Collision with the environment determines whether the hero can move, gets pushed back, takes damage, or triggers a level transition

### Collision System
Each level uses a **collision mask** — an invisible image layered over the map where specific pixel colors encode terrain behavior:
- **Walkable zones** — the hero moves freely
- **Solid walls** — movement is blocked
- **Damage zones** — the hero takes damage and is pushed back
- **Level-end triggers** — reaching a specific point launches the enigma puzzle

### Combat & Enemies
Each level features enemies with autonomous AI:
- **Patrol mode** — enemies walk back and forth within a 200-pixel zone around their spawn point
- **Detection** — when the hero enters a 200-pixel radius, the enemy switches to chase mode
- **Chase mode** — the enemy pursues the hero at 4px/frame speed
- **Attack** — within 50 pixels, the enemy attacks, dealing damage to the hero

### Health System
- The hero starts with **3 lives**, displayed as heart icons on screen
- Taking damage (from enemies or hazard zones) reduces health
- Losing all lives triggers a **Game Over** — the level restarts from the beginning
- Health icons update in real-time: `vie3.png` → `vie2.png` → `vie1.png` → `vie0.png`

### Enigma Puzzles
At the end of each level, the hero reaches a door that triggers a puzzle sequence:
1. A **random question** about Tunisian history/culture is displayed
2. **Four answer choices** appear — one correct, three decoys
3. The correct answer is **randomly shuffled** among the four positions each time
4. You have **60 seconds** to answer using arrow keys or mouse click
5. **Correct answer** → door opens with animation, proceed to next level
6. **Wrong answer or timeout** → failure animation, must retry

**Example questions:**
- "How many population in Tunisia?" → 12 million
- "Who is the first doctor in Tunisia?" → Tewhide
- "What's the date of Tunisian independence?" → 20 mars 1956

### Minimap
- A minimap in the top-right corner shows the current level layout
- A small indicator tracks the hero's real-time position
- Helps orient the player within the larger scrolling map

### Scoring & Timer
- An in-game timer tracks elapsed time (displayed as `MM:SS`)
- Score is calculated based on completion time: faster = higher score
- Formula: `seconds + (tens_of_seconds × 10) + (minutes × 100)`

### Save & Load
- The game saves progress automatically when completing an enigma
- Save data includes: hero position, enemy position, camera position, health, elapsed time, score
- Saves are stored per level (`sauvegarde.txt`, `sauvegarde_lev2.txt`, `sauvegarde_lev3.txt`)
- Load from the main menu to resume a previous session

### Leaderboard
- After completing a level, you're prompted to enter your name
- Your score is recorded and compared against the best score
- The top score and player name are displayed on the leaderboard screen

## Multiplayer Mode

### Split-Screen (2 Players)
- The screen is divided vertically — **Player 1** on the left, **Player 2** on the right
- Each player has independent movement, camera scrolling, and collision detection
- Both players share the same keyboard for input
- Currently features the movement and exploration mechanics (no enemy/enigma system in multiplayer)

## Menu System

### Main Menu
- **Play** → New Game / Load Game / Best Score
- **Settings** → Volume control (0%, 25%, 50%, 75%, 100%) + Fullscreen toggle
- **Credits** → Project credits
- **Exit** → Quit confirmation dialog (Yes/No)

### Audio
- Each level has its own background music track
- Menu has a separate music theme
- Sound effects for: enigma win, enigma fail, cursor navigation
- Volume adjustable in 25% increments from the settings menu
