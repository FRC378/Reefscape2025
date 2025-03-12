// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoCrossLine.h"

#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToRelativePoint.h"
#include <frc2/command/WaitCommand.h>


AutoCrossLine::AutoCrossLine() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoCrossLine ******"),
    CmdDriveClearAll(),


    //Just drive backwards the length of the robot with bumpers
    frc2::WaitCommand(2_s),
    CmdDriveToRelativePoint( -40.0, 0, 0, 0.2, true, 0),



    CmdDriveStop(),  
    CmdPrintText("AutoCrossLine Complete")
  );
}
