#ifndef __DEFINE_H__
#define __DEFINE_H__

// Spash Screen Specific

#define Splash_Length 3.0 // Defines the length of splash screen.
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

// Ball
#define Ball_Acceleration 0.01
#define Ball_Top_Speed 1.25
#define Ball_Smaller 0.25
#define Ball_Larger 0.25

//Blocks
#define Brick_Debug 0.00005
#define Brick_Distance 0
#define Left_Max 0
#define Right_Max 0
#define Down_Max 0
#define Up_Max 0

//Level One		//May be best refracted if time. 
#define L1_Brick_NO 8
#define L1_Brick_Lines 6
#define L1_Brick_Pow 4
//Note to self add Colour blocks etc

//Level Two
#define L2_Brick_NO 64
#define L2_Brick_Lines 6
#define L2_Brick_Pow 4

//Level Three
#define L3_Brick_NO 64
#define L3_Brick_Lines 6
#define L3_Brick_Pow 4

//Level Four
#define L4_Brick_NO 64
#define L4_Brick_Lines 6
#define L4_Brick_Pow 4

//Level Five
#define L5_Brick_NO 64
#define L5_Brick_Lines 6
#define L5_Brick_Pow 4
#endif // __GAMEMAIN_SCENE_H__
