// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoRightSide.h"

#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToRelativePoint.h"
#include "commands/CmdDriveToAbsolutePoint.h"
#include <frc2/command/WaitCommand.h>

#include "commands/CmdElevatorSetLevel.h"
#include "commands/CmdChuteOpen.h"
#include "commands/CmdChuteClose.h"
#include "commands/CmdDriveTurnToHeading.h"



AutoRightSide::AutoRightSide() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoRightSide ******"),
    CmdDriveClearAll(),


    //Drive backwards 86 inches
    frc2::WaitCommand(2_s),
    CmdDriveToAbsolutePoint( -86.0, 0, 0, 0.3, true, 3.0),


    //Now turn -60 degrees to face reef
    CmdDriveTurnToHeading( -60.0, -0.3 ),

    //straff to align to april tag
    // A command to control swerve to straff to apriltag while maintaining angle

    //Move offset to align to reef pipe
    CmdDriveToRelativePoint( 0.0, 6.0, -60, 0.3, true, 3.0),

    //Raise Elevator
    CmdElevatorSetLevel( ELEVATOR_L2 ),

    //Move to reef 
    //  How do we know where to drive?
    CmdDriveToAbsolutePoint( -999, -999, -60.0, 0.3, true, 3.0),

    //Score!
    CmdChuteOpen(),
    frc2::WaitCommand(2_s),
    CmdChuteClose(),

    //Back off reef, bring elevator back down
    CmdDriveToRelativePoint( 20.0, 0, -60.0, 0.2, true, 0),
    frc2::WaitCommand(0.5_s),
    CmdElevatorSetLevel( ELEVATOR_HOME ),

    CmdDriveStop(),  
    CmdPrintText("AutoRightSide Complete")
  );
}
