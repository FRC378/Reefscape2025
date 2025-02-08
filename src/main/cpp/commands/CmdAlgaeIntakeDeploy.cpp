// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAlgaeIntakeDeploy.h"
#include "Robot.h"
CmdAlgaeIntakeDeploy::CmdAlgaeIntakeDeploy() 
{
  AddRequirements(&g_robotContainer.m_algaeintake);
}

// Called when the command is initially scheduled.
void CmdAlgaeIntakeDeploy::Initialize() 
{
  g_robotContainer.m_algaeintake.SetSwingMotorPower(0.3);   //fix later
  g_robotContainer.m_algaeintake.SetIntakeMotorPower(0.3);  //fix later
}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeIntakeDeploy::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeIntakeDeploy::End(bool interrupted) 
{
   g_robotContainer.m_algaeintake.SetSwingMotorPower(0.0);
}

// Returns true when the command should end.
bool CmdAlgaeIntakeDeploy::IsFinished() 
{
   return g_robotContainer.m_algaeintake.GetLowerLimitSwitch();
}
