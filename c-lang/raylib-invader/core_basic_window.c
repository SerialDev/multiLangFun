
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

void InitGame(void){
  player.rect.x = screenWidth / 2.0f;
  player.rect.y = screenHeight - 20;
  player.rect.width = 20;
  player.rect.height = 20;
  player.speed.x = 5;
  player.speed.y = 5;
  player.color = BLACK;

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

}

void DrawGame(void){
  BeginDrawing();

  ClearBackground(RAYWHITE);
  DrawText("Space Invaders! ", 0, 0, 20, LIGHTGRAY);

  // draw player
  DrawRectangleRec(player.rect, player.color);

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
