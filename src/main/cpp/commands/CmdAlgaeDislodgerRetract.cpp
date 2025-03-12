// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAlgaeDislodgerRetract.h"
#include "Robot.h"
CmdAlgaeDislodgerRetract::CmdAlgaeDislodgerRetract() 
{
  AddRequirements(&g_robotContainer.m_algaedislodger);
}

// Called when the command is initially scheduled.
void CmdAlgaeDislodgerRetract::Initialize() 
{
  g_robotContainer.m_algaedislodger.SetAlgaeDislodgerMotorPower(0.5);

  //Start timer
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeDislodgerRetract::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeDislodgerRetract::End(bool interrupted) 
{
  g_robotContainer.m_algaedislodger.StopMotor();
  m_timer.Stop();
}

// Returns true when the command should end.
bool CmdAlgaeDislodgerRetract::IsFinished() 
{

  if( m_timer.HasElapsed( 1.0_s))
    return true;

  return false;

}
