// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAlgaeIntakeRetract.h"
#include "Robot.h"
CmdAlgaeIntakeRetract::CmdAlgaeIntakeRetract() 
{
  AddRequirements(&g_robotContainer.m_algaeintake);
}

// Called when the command is initially scheduled.
void CmdAlgaeIntakeRetract::Initialize() 
{
  g_robotContainer.m_algaeintake.SetSwingMotorPower(-0.3);
}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeIntakeRetract::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeIntakeRetract::End(bool interrupted) 
{
  g_robotContainer.m_algaeintake.StopMotors();
}

// Returns true when the command should end.
bool CmdAlgaeIntakeRetract::IsFinished() 
{
  return g_robotContainer.m_algaeintake.GetUpperLimitSwitch();
}
