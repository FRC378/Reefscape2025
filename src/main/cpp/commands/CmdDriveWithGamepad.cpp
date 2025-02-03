// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithGamepad.h"
#include "Robot.h"

CmdDriveWithGamepad::CmdDriveWithGamepad() 
{
  AddRequirements( &g_robotContainer.m_drivetrain );
}

// Called when the command is initially scheduled.
void CmdDriveWithGamepad::Initialize() 
{

}


// Called repeatedly when this Command is scheduled to run
void CmdDriveWithGamepad::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}

// Returns true when the command should end.
bool CmdDriveWithGamepad::IsFinished() 
{
  return false;
}
