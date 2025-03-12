// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoLeftSide.h"
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
#include "commands/CmdDriveTurnToHeading.h"
#include "commands/CmdLimelightSetPipeline.h"



AutoLeftSide::AutoLeftSide() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoLeftSide ******"),
    CmdDriveClearAll(),


    CmdLimelightSetPipeline(0),   //Pipeline 0 is right, Pileline 1 is left

    //Drive backwards 86 inches
    frc2::WaitCommand(.25_s),
    CmdDriveToAbsolutePoint( -90.0, 0, 0, 0.3, true, 3.0),


    //Now turn 60 degrees to face reef
    CmdDriveTurnToHeading( -60.0, 0.3 ),


    frc2::WaitCommand(0.25_s),

    //Drive to AprilTag
    CmdDriveToAprilTag(-60.0),

    //Elevator UP
    frc2::WaitCommand(0.25_s),
    CmdElevatorSetLevel(ELEVATOR_L2),

    //Wait for Elevator
    frc2::WaitCommand(1.5_s),


    //Score!
    CmdChuteOpen(),
    frc2::WaitCommand(2.0_s),
    //CmdChuteClose(),


    //Back off reef, bring elevator back down
    CmdDriveToRelativePoint( 20.0, -20.0, -60.0, 0.2, true, 0),
    CmdElevatorSetLevel( ELEVATOR_HOME ),

    CmdDriveStop(),  
    CmdPrintText("AutoLeftSide Complete")
  );
}
