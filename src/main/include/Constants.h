//Robot ID constants
#pragma once

//** CAN IDs **
#define PIGEON_CAN_ID                    10
#define CLIMBER_MOTOR_CAN_ID             8
#define ALGAEINTAKE_INTAKE_MOTOR_CAN_ID  9  //(Rollers)
#define ALGAEINTAKE_SWING_MOTOR_CAN_ID   7  //(Swing)
#define CHUTE_PIN_MOTOR_CAN_ID           11
#define ALGAE_DISLODGER_MOTOR_CAN_ID     12
#define ELEVATOR_MOTOR_CAN_ID            6



//********** DRIVETRAIN CONSTANTS **********

#define DRIVEBASE_WIDTH    21.2       //inches, Left to Right
#define DRIVEBASE_HEIGHT   21.5       //inches, Front to Rear


//-------------------------------------------
#define FRONTLEFT_DRIVE_CAN_ID      32
#define FRONTLEFT_TURN_CAN_ID       31 
#define FRONTLEFT_ENCODER_ID        2 
#define FRONTLEFT_ENCODER_OFFSET    (220.2)
//-------------------------------------------
#define FRONTRIGHT_DRIVE_CAN_ID     33
#define FRONTRIGHT_TURN_CAN_ID      34
#define FRONTRIGHT_ENCODER_ID       0
#define FRONTRIGHT_ENCODER_OFFSET   (28.9)
//-------------------------------------------
#define BACKLEFT_DRIVE_CAN_ID       24
#define BACKLEFT_TURN_CAN_ID        23
#define BACKLEFT_ENCODER_ID         3
#define BACKLEFT_ENCODER_OFFSET     (319.4)
//-------------------------------------------
#define BACKRIGHT_DRIVE_CAN_ID      21
#define BACKRIGHT_TURN_CAN_ID       22
#define BACKRIGHT_ENCODER_ID        1
#define BACKRIGHT_ENCODER_OFFSET    (114.4)
//-------------------------------------------
