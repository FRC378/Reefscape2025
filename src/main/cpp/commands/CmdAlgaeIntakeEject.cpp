// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAlgaeIntakeEject.h"
#include "Robot.h"
CmdAlgaeIntakeEject::CmdAlgaeIntakeEject() 
{
  AddRequirements(&g_robotContainer.m_algaeintake);
}

// Called when the command is initially scheduled.
void CmdAlgaeIntakeEject::Initialize() 
{
  g_robotContainer.m_algaeintake.SetIntakeMotorPower(-0.3); 
}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeIntakeEject::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeIntakeEject::End(bool interrupted) 
{
  g_robotContainer.m_algaeintake.SetIntakeMotorPower(0.0);
}

// Returns true when the command should end.
bool CmdAlgaeIntakeEject::IsFinished() 
{
  return !g_robotContainer.m_algaeintake.GetAlgaeDetect();   //fix later, add safety stop
}
