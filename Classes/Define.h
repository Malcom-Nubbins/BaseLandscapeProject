#ifndef __DEFINE_H__
#define __DEFINE_H__

// Spash Screen Specific

#define Splash_Length 0.5 // Defines the length of splash screen. Temporarily reduced splash screen time for ease of debugging
#define Transition_Length 0.8 // Defines the length of transitions.
#define Load_MaxTime 8 // Used to prevent infinte loading.

// GameMain Specific 

#define GameTransition_Length 2 // Defines the length of transitions.
#define Game_Load_MaxTime 50 // Used to prevent infinte loading.
// Paddle
#define Paddle_Acceleration 0.33
#define Paddle_Top_Speed 1
#define Paddle_Smaller 0.4
#define Paddle_Larger 0.4
#define Paddle_Bitmask 1
#define Paddle_Bitmask_2 0x11

// Ball
#define Ball_Acceleration 0.02
#define Ball_Top_Speed 1.25
#define Ball_Smaller 0.25
#define Ball_Larger 0.25
#define Ball_Bitmask 3
#define Ball_Bitmask_2 0x21

//Blocks
#define Brick_Debug 44
#define Brick_Distance 0
#define Brick_Bitmask 3
#define Brick_Bitmask_2 0x31
#define Brick_Line_Distance 0
#define Brick_Size 60
#define Left_Max 0
#define Right_Max 0
#define Down_Max 0
#define Up_Max 0
#define L1_Brick_NO 96

//PowerUp
#define PowerUp_Bitmask 4

#endif // __GAMEMAIN_SCENE_H__