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

  std::cout<<"CmdAlgaeIntakeDeploy"<<std::endl;

  //Don't allow to start unless against limit switch
  if( g_robotContainer.m_algaeintake.GetUpperLimitSwitch() )
  {
    g_robotContainer.m_algaeintake.SetSwingMotorPower(0.9); //Down
    m_abort = false;
  }
  else
  {
    std::cout<<"***ABORT!  Not against Limit Switch!!!!"<<std::endl;
    m_abort = true;
  }

  //Start timer
  m_timer.Reset();
  m_timer.Start();

}

// Called repeatedly when this Command is scheduled to run
void CmdAlgaeIntakeDeploy::Execute() 
{

}

// Called once the command ends or is interrupted.
void CmdAlgaeIntakeDeploy::End(bool interrupted) 
{
   g_robotContainer.m_algaeintake.SetSwingMotorPower(0.0);
   m_timer.Stop();
}

// Returns true when the command should end.
bool CmdAlgaeIntakeDeploy::IsFinished() 
{

  //Run motor for time
  if( m_timer.HasElapsed( units::second_t(1.6) ) )  {
      return true;
  }


   return m_abort;
}
