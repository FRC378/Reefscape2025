// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAlgaeDislodgerDeploy.h"
#include "Robot.h"
CmdAlgaeDislodgerDeploy::CmdAlgaeDislodgerDeploy() 
{
  AddRequirements(&g_robotContainer.m_algaedislodger);
}

// Called when the command is initially scheduled.
void CmdAlgaeDislodgerDeploy::Initialize() 
{
  g_robotContainer.m_algaedislodger.SetAlgaeDislodgerMotorPower(0.1);

}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeDislodgerDeploy::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeDislodgerDeploy::End(bool interrupted) 
{
  g_robotContainer.m_algaedislodger.StopMotor();
}

// Returns true when the command should end.
bool CmdAlgaeDislodgerDeploy::IsFinished() 
{

  return g_robotContainer.m_algaedislodger.GetLowerLimitSwitch();
 
}
