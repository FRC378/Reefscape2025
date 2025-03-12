// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoStraightAhead.h"

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



AutoStraightAhead::AutoStraightAhead() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoStraightAhead ******"),
    CmdDriveClearAll(),

    CmdLimelightSetPipeline(0), //pipeline 0 is Right

    frc2::WaitCommand(0.25_s),

    //Drive to AprilTag
    CmdDriveToAprilTag(0),

    //Elevator UP
    frc2::WaitCommand(0.25_s),
    CmdElevatorSetLevel(ELEVATOR_L2),

    //Wait for Elevator
    frc2::WaitCommand(1.5_s),


    //Score!
    CmdChuteOpen(),
    frc2::WaitCommand(2.0_s),
    CmdChuteClose(),


    //Back off reef, bring elevator back down
    CmdDriveToRelativePoint( 20.0, 0, 0, 0.2, true, 0),
    CmdElevatorSetLevel( ELEVATOR_HOME ),

    //Done!
    CmdDriveStop(),  
    CmdPrintText("AutoStraightAhead Complete")
  );
}
