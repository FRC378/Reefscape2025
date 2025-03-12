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
  g_robotContainer.m_algaedislodger.SetAlgaeDislodgerMotorPower(-0.4);

  //Start timer
  m_timer.Reset();
  m_timer.Start();

}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeDislodgerDeploy::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeDislodgerDeploy::End(bool interrupted) 
{
  g_robotContainer.m_algaedislodger.StopMotor();
  m_timer.Stop();
}

// Returns true when the command should end.
bool CmdAlgaeDislodgerDeploy::IsFinished() 
{

  if( m_timer.HasElapsed( 0.75_s ) )
    return true;

  return false;

 
}
