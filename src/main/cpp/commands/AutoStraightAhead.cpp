// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoStraightAhead.h"

#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToRelativePoint.h"
#include "commands/CmdDriveToAbsolutePoint.h"
#include <frc2/command/WaitCommand.h>

#include "commands/CmdElevatorSetLevel.h"
#include "commands/CmdChuteOpen.h"
#include "commands/CmdChuteClose.h"



AutoStraightAhead::AutoStraightAhead() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoStraightAhead ******"),
    CmdDriveClearAll(),


    //Drive backwards 88 inches, in 2 steps to allow for elevator to come up
    frc2::WaitCommand(2_s),
    CmdDriveToRelativePoint( -44.0, 0, 0, 0.3, false, 0),
    CmdElevatorSetLevel( ELEVATOR_L3 ),
    CmdDriveToAbsolutePoint( -88.0, 0, 0, 0.3, true, 3.0),


    //Score!
    CmdChuteOpen(),
    frc2::WaitCommand(2_s),
    CmdChuteClose(),

    //Back off reef, bring elevator back down
    CmdDriveToRelativePoint( 20.0, 0, 0, 0.2, true, 0),
    frc2::WaitCommand(0.5_s),
    CmdElevatorSetLevel( ELEVATOR_HOME ),

    CmdDriveStop(),  
    CmdPrintText("AutoStraightAhead Complete")
  );
}
