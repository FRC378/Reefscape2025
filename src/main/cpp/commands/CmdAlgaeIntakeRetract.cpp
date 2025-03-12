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
  std::cout<<"CmdAlgaeIntakeRetract"<<std::endl;

  //Drive to limit switch
  g_robotContainer.m_algaeintake.SetSwingMotorPower(-0.95);

  //Set timer as safety
  m_timer.Reset();
  m_timer.Start();

}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeIntakeRetract::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeIntakeRetract::End(bool interrupted) 
{
  g_robotContainer.m_algaeintake.SetSwingMotorPower( 0.0);
  m_timer.Stop();
}

// Returns true when the command should end.
bool CmdAlgaeIntakeRetract::IsFinished() 
{

  //Stop if hit limit switch
  if( g_robotContainer.m_algaeintake.GetUpperLimitSwitch() )
    return true;

  //Safety Timeout!
  if( m_timer.HasElapsed( units::second_t(1.75) ) )
  {
      std::cout<<"*** CmdAlgaeIntakeRetract: Timeout"<<std::endl;
      return true;
  }

  return false;

}
