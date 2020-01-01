
#include "raylib.h"

static void InitGame(void); // Initialize game
static void UpdateGame(void); // UpdateGame (one frame)
static void DrawGame(void); // Draw game (one frame)
static const int screenWidth = 800;
static const int screenHeight = 450;

typedef struct Player
{
  Rectangle rect;
  Vector2 speed;
  Color color;
} Player;

// Player
static Player player;


// Bullets
typedef struct Shoot
{
  Rectangle rect;
  Vector2 speed;
  bool active;
  Color color;
} Shoot;

// Max bullets
/* static const int NUM_SHOOTS = 50; */
#define NUM_SHOOTS 50


// Array of bullets to reuse
static Shoot shoot[NUM_SHOOTS];

// Rate of fire
static int shootRate;


void InitGame(void){
  player.rect.x = screenWidth / 2.0f;
  player.rect.y = screenHeight - 20;
  player.rect.width = 20;
  player.rect.height = 20;
  player.speed.x = 5;
  player.speed.y = 5;
  player.color = BLACK;

  shootRate = 0;
  // initialize shots
  for(int i = 0; i < NUM_SHOOTS; ++i) {
    shoot[i].rect.x = player.rect.x;
    shoot[i].rect.y = player.rect.y + player.rect.height /4;
    shoot[i].rect.width = 5;
    shoot[i].rect.height = 10;
    shoot[i].speed.x = 0;
    shoot[i].speed.y = -10;
    shoot[i].active = false;
    shoot[i].color = MAROON;
  }

}


void UpdateGame(void){
  // Player movement
  if (IsKeyDown(KEY_RIGHT)){
    player.rect.x += player.speed.x;
  }
  if (IsKeyDown(KEY_LEFT)){
    player.rect.x -= player.speed.x;
  }

  // Wall Behaviour
  if (player.rect.x <= 0){
    player.rect.x = 0;
  }
  if (player.rect.x + player.rect.width >= screenWidth){
    player.rect.x = screenWidth - player.rect.width;
  }

  // Shoot on space key down
  if (IsKeyDown(KEY_SPACE))
  {
    shootRate += 5;
    for(int i =0; i< NUM_SHOOTS; ++i){
      if(!shoot[i].active && shootRate %40 == 0){
        shoot[i].rect.x = player.rect.x;
        shoot[i].rect.y = player.rect.y + player.rect.height / 4;
        shoot[i].active = true;
        break;
      }
    }
  }

  // Update shoot movement and hide over boundary
  for(int i =0; i< NUM_SHOOTS; ++i){
    if (shoot[i].active){
      // Movement
      shoot[i].rect.y += shoot[i].speed.y;

      if (shoot[i].rect.y <= 0) // goes above the screen
      {
        shoot[i].active = false;
        shootRate = 0;
      }
    }
  }

}

void DrawGame(void){
  BeginDrawing();

  ClearBackground(RAYWHITE);
  DrawText("Space Invaders! ", 0, 0, 20, LIGHTGRAY);

  // draw player
  DrawRectangleRec(player.rect, player.color);


  // draw bullets
  for (int i = 0; i < NUM_SHOOTS; i++)
  {
    if (shoot[i].active)
      DrawRectangleRec(shoot[i].rect, shoot[i].color);
  }


  EndDrawing();

}


int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    InitGame();
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
      UpdateGame();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
      DrawGame();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

/* (compile "mkdir build && CXX=clang++ CC=clang cmake ..") */
/* (compile "cd build && cmake ..") */
/* (compile "cd build && \"C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe\" example.sln  /clp:ErrorsOnly -m" ) */
/* (send-to-shell "\"C:\\Users\\anma04\\aller_training\\new-m\\multiLangFun\\c-lang\\raylib-invader\\build\\Debug\\example.exe\"") */
/* (send-to-shell "/mnt/c/sdev_machine/personal/projects/multiLangFun/c-lang/raylib-invader/build/example") */

/* (compile "cd build && \"/mnt/c/Program Files (x86)/CMake/bin/cmake.exe\" -G \"Visual Studio 16 2019\" -A Win32 .. ") */
/* (send-to-shell "cd build && \"/mnt/c/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe\" example.sln  /clp:ErrorsOnly -m" ) */
/* "/mnt/c/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" example.sln  /clp:ErrorsOnly -m */
