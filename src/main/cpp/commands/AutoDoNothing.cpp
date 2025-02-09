// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDoNothing.h"

#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"


AutoDoNothing::AutoDoNothing() 
{

  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoDoNothing ******"),
    CmdDriveClearAll(),





    CmdDriveStop(),  
    CmdPrintText("AutoDoNothing Complete")
  );
}
