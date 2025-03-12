// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoStraightWithAlgae.h"

#include <frc2/command/WaitCommand.h>
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToRelativePoint.h"
#include "commands/CmdDriveToAbsolutePoint.h"
#include "commands/CmdDriveToAprilTag.h"
#include "commands/CmdElevatorSetLevel.h"
#include "commands/CmdChuteOpen.h"
#include "commands/CmdChuteClose.h"
#include "commands/CmdLimelightSetPipeline.h"
#include "commands/CmdAlgaeDislodgerDeploy.h"
#include "commands/CmdAlgaeDislodgerRetract.h"

#include "frc2/command/ParallelCommandGroup.h"



AutoStraightWithAlgae::AutoStraightWithAlgae() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoStraightWithAlgae ******"),
    CmdDriveClearAll(),

    CmdLimelightSetPipeline(0), //pipeline 0 is Right


    //Drive halfway
    CmdDriveToAbsolutePoint( -44.0, 0, 0, 0.4, true, 0),

    //Elevator up
    CmdElevatorSetLevel(ELEVATOR_L2),

    //Wait for Elevator
    frc2::WaitCommand(1.0_s),

    //Deploy Extractor
    CmdAlgaeDislodgerDeploy(),

    //Drive into reef straight ahead
    CmdDriveToAbsolutePoint( -94.0, 0, 0, 0.3, true, 2.0),

    frc2::WaitCommand(0.5_s),

    //Backup and get Algae out!!!!
    CmdElevatorSetLevel(ELEVATOR_L3),    
    frc2::ParallelCommandGroup(   
      CmdAlgaeDislodgerRetract(),

      CmdDriveToAbsolutePoint( -40.0, 0, 0, 0.2, true, 0)
    ),


    //Elevator down to Use AprilTag
    CmdElevatorSetLevel(ELEVATOR_HOME),
    frc2::WaitCommand(2.5_s),



    //Drive to AprilTag
    CmdDriveToAprilTag(0),

    //Elevator UP
    frc2::WaitCommand(0.25_s),
    CmdElevatorSetLevel(ELEVATOR_L3),

    //Wait for Elevator
    frc2::WaitCommand(2.25_s),


    //Score!
    CmdChuteOpen(),
    frc2::WaitCommand(2.0_s),
    //CmdChuteClose(),


    //Back off reef, bring elevator back down
    CmdDriveToRelativePoint( 20.0, 0, 0, 0.2, true, 0),
    CmdElevatorSetLevel( ELEVATOR_HOME ),

    //Done!
    CmdDriveStop(),  
    CmdPrintText("AutoStraightWithAlgae Complete")
  );
}
