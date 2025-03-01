//Robot ID constants
#pragma once

//** CAN IDs **
//#define PIGEON_CAN_ID                    10
//#define CLIMBER_MOTOR_CAN_ID             52
#define CLIMBER_MOTOR_CAN_ID             22
#define ALGAEINTAKE_INTAKE_MOTOR_CAN_ID  53
//#define ALGAEINTAKE_SWING_MOTOR_CAN_ID   54
#define ALGAEINTAKE_SWING_MOTOR_CAN_ID   32
// #define CHUTE_PIN_MOTOR_CAN_ID           55
#define CHUTE_PIN_MOTOR_CAN_ID           31
#define ALGAE_DISLODGER_MOTOR_CAN_ID     56
// #define ELEVATOR_MOTOR_CAN_ID            57
#define ELEVATOR_MOTOR_CAN_ID            21



//********** DRIVETRAIN CONSTANTS **********

#define DRIVEBASE_WIDTH    27.0       //inches, Left to Right
#define DRIVEBASE_HEIGHT   27.0       //inches, Front to Rear

//-------------------------------------------
#define FRONTLEFT_DRIVE_CAN_ID      11 
#define FRONTLEFT_TURN_CAN_ID       12 
#define FRONTLEFT_ENCODER_ID        0 
#define FRONTLEFT_ENCODER_OFFSET    (299.2)
//-------------------------------------------
//#define FRONTRIGHT_DRIVE_CAN_ID     21
//#define FRONTRIGHT_TURN_CAN_ID      22
#define FRONTRIGHT_ENCODER_ID       1
#define FRONTRIGHT_ENCODER_OFFSET   (310.5)
//-------------------------------------------
#define BACKLEFT_DRIVE_CAN_ID       14
#define BACKLEFT_TURN_CAN_ID        24
#define BACKLEFT_ENCODER_ID         3
#define BACKLEFT_ENCODER_OFFSET     (316.5)
//-------------------------------------------
//#define BACKRIGHT_DRIVE_CAN_ID      31
//#define BACKRIGHT_TURN_CAN_ID       32
#define BACKRIGHT_ENCODER_ID        2
#define BACKRIGHT_ENCODER_OFFSET    (112.6)
//-------------------------------------------
