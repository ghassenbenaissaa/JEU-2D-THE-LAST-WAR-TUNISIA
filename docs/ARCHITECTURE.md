# Technical Architecture

## Overview

The game is built in **C** using the **SDL 1.2** library ecosystem. It follows a modular architecture where each game system (rendering, input, collision, AI, UI) is implemented in its own source file, with shared state passed through structs defined in header files.

## Build System

The project uses a `Makefile` in `game/`:

```bash
cd game
make          # Compiles all .c files from src/ into build/*.o, links into ./prog
make clean    # Removes build/ directory and binary
```

All object files are placed in `game/build/`. The final binary is `game/prog`.

## Source Organization

```
game/src/
├── header.h                 # Main header: all structs + function prototypes (single-player)
├── headerpartage.h          # Multiplayer header: simplified structs (no enemies/health)
├── mainmenu.c               # Entry point (main()), menu system, settings, audio init
├── main.c / main2.c / main3.c   # Game loops for levels 1, 2, 3
├── background.c             # Map initialization, rendering, door/owl sprite loading
├── evan.c                   # Hero sprite sheet initialization and rendering
├── mouvment.c               # Keyboard input → movement state machine
├── scrolling.c              # Camera scrolling logic based on collision results
├── collisionPP.c            # Pixel-perfect collision via color-coded mask
├── animation.c              # Hero sprite frame cycling
├── minimap.c                # Minimap display, timer, scoring, save/load, leaderboard
├── enigme.c                 # Puzzle system: question loading, UI, timer, verification
├── ennemie.c                # Enemy AI: patrol, detection, chase, attack
├── gestionvie.c             # Health management and heart icon display
├── annimation.c             # Menu intro animation sequence
├── backgroundmenu.c         # Menu background rendering
├── text.c                   # TTF text rendering utilities
├── fullscreen.c             # Fullscreen/windowed toggle
├── partage.c                # Split-screen multiplayer main loop
├── p.c                      # Multiplayer helper functions
├── animationpartage.c       # Multiplayer hero animation
├── collisionPPpartage.c     # Multiplayer collision detection
├── evanpartage.c            # Multiplayer hero initialization
├── mouvementpartage.c       # Multiplayer input handling
├── scrollingpartage.c       # Multiplayer camera scrolling
├── manette.c                # Gamepad/controller support (experimental)
└── source.c                 # Utility/test code
```

## Core Data Structures

Defined in `header.h`:

### `hero`
Represents the player character. Contains per-level fields (suffixed `2`/`3`):
- `pos_hero[9]` / `afficher_hero[9]` — sprite positions and surfaces (9 frames)
- `afficher_herod[9]` — left-facing sprite set
- `pos_hero2` — current screen position
- `mouvment` — current movement state (0=idle, 1=right, 2=left, 3=up, 4=down)
- `farm` — current animation frame index
- `vie` — remaining health (0–3)
- `hit` — damage flag

### `background`
Map/level rendering data:
- `afficher_background` — main map surface
- `calque_background` — collision mask surface
- `pos_background` / `pos_background2` — camera and map positions
- `porte[14]` / `owl[14]` — door and owl animated sprite arrays

### `Enemy`
Enemy entity with three independent instances (fields suffixed `2`/`3`):
- `image[3]` / `image2[3]` — walk animation frames (right/left)
- `Hit` — attack sprite
- `position` / `positionO` — current position and origin (patrol center)
- `direction` — 0=left, 1=right
- `died` — death state flag

### `Enigme`
Puzzle system state:
- `background[2]` — puzzle screen backgrounds
- `boutons[5]` / `reponses[5]` — answer button surfaces
- `question` — current question surface
- `choix_question` — randomly selected question index
- `positionVraiReponse` — position where the correct answer was placed (1–4)

### `minimap`
Per-level minimap data:
- `minimap` / `petit` — minimap image and player indicator surfaces
- `posminijoueur` / `posminimap` — positions on screen
- `nbmoved` — movement accumulator for smooth tracking

### `bg`
Main menu state — contains all menu surfaces, button positions, and UI element coordinates.

## Key Algorithms

### Pixel-Perfect Collision (`collisionPP.c`)

The collision system reads pixel colors from a **mask image** (`masque.png`) at the hero's current position:

```
1. Get hero's bounding box position on the map
2. Read the pixel color at that position on the mask surface
3. Map the RGB value to a collision code:
   - Code 0: Free movement
   - Code 1: Blocked (wall)
   - Code 2: Scroll trigger
   - Code 3: Damage zone
   - Other codes: Level-specific triggers
4. Return the code to scrolling() which adjusts camera/position accordingly
```

`GetPixel()` extracts RGB values by directly accessing the SDL surface's pixel buffer, handling different bits-per-pixel formats.

### Enemy AI (`ennemie.c`)

Each enemy runs a simple state machine per frame:

```
1. Calculate distance to player (hero.pos_hero2.x - enemy.position.x)
2. If distance < 200px → CHASE: move toward player at 4px/frame
3. If distance < 50px  → ATTACK: set stat=1, display Hit sprite
4. If distance > 200px → PATROL: move within ±200px of origin position
5. Reverse direction at patrol boundaries
6. Adjust position when camera scrolls (mouvment parameter)
```

### Scrolling System (`scrolling.c`)

Camera movement is driven by collision results:
```
1. Receive collision code from collisionPP()
2. If code allows movement → shift background position opposite to hero direction
3. If code blocks → prevent hero position update
4. If code is damage → push hero back and trigger hit flag
5. Update all entity positions relative to new camera offset
```

### Enigma Flow (`enigme.c`)

```
1. Load questions from file, select random question (rand() % 4)
2. Load 3 decoy answers + 1 correct answer
3. Shuffle correct answer to random position (1–4)
4. Start 60-second countdown
5. Player selects answer via keyboard/mouse
6. Compare selection against positionVraiReponse
7. Win → play win.wav, animate door opening, proceed
8. Lose → play fail.wav, animate door closing
```

## Rendering Pipeline

Each frame in the game loop:
```
1. Update timer display
2. Render background map (afficherBack)
3. Render hero sprite (afficher_evan)
4. Update hero animation frame
5. Update minimap player position
6. Move and animate enemies
7. Render enemies
8. Check collision (collisionPP)
9. Apply scrolling
10. Check/apply damage (gestionvie)
11. Render health icons
12. SDL_Flip(ecran)  — swap buffers
13. Process input events (mouvment)
14. Check game-over / level-end conditions
```

## Multiplayer Architecture

The split-screen mode (`partage.c` + `headerpartage.h`) uses a simplified version of the single-player systems:

- **Separate header** (`headerpartage.h`) with stripped-down `hero` and `background` structs (no health, no enemies)
- **Vertical split** at x=960, with a dividing line image (`trait.png`)
- **Two independent instances** of: hero, background, camera, collision, animation
- **Shared SDL event loop** dispatching inputs to both players
- **Single `SDL_Flip()`** renders both halves per frame

## File I/O

| Operation | Format | Files |
|-----------|--------|-------|
| Save game | Binary (fwrite/fread of `save` struct) | `sauvegarde*.txt` |
| Questions | Plain text, one per line | `questions.txt` |
| Answers | Plain text, one per line | `reponses.txt`, `vraireponses.txt` |
| Scores | Text append (`fprintf`) | `score.txt` |

## Dependencies

| Library | Version | Purpose |
|---------|---------|---------|
| SDL | 1.2 | Core: window, events, surfaces, rendering |
| SDL_image | 1.2 | PNG and JPG image loading |
| SDL_ttf | 2.0 | TrueType font rendering |
| SDL_mixer | 1.2 | MP3 and WAV audio playback |

## Display Configuration

- Resolution: **1920×1080** (hardcoded)
- Color depth: **32-bit**
- Flags: `SDL_HWSURFACE | SDL_DOUBLEBUF`
- Rendering: Software blitting via `SDL_BlitSurface` + `SDL_Flip`
