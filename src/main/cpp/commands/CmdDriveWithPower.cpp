// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithPower.h"
#include "Robot.h"

CmdDriveWithPower::CmdDriveWithPower(double power,  double distance,   double timeout) 
{

  m_power    = power;
  m_distance = distance;
  m_timeout  = timeout;

  AddRequirements( &g_robotContainer.m_drivetrain );
}

void CmdDriveWithPower::Initialize() 
{

  //Start Timer if Timeout is set
  if( m_timeout > 0.0 )
  {
      m_timer.Reset();
      m_timer.Start();
  }
}

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithPower::Execute() 
{
  g_robotContainer.m_drivetrain.DriveWithPower( m_power );
}

// Called once the command ends or is interrupted.
void CmdDriveWithPower::End(bool interrupted) 
{
  g_robotContainer.m_drivetrain.Stop();
}

// Returns true when the command should end.
bool CmdDriveWithPower::IsFinished() 
{
  if( g_robotContainer.m_drivetrain.GetOdometryX() >= m_distance )
  {
    return true;
  }

  if( m_timeout > 0  && m_timer.HasElapsed( units::second_t( m_timeout) ) )
  {
    m_timer.Stop();
    std::cout<<"CmdDriveWithPower: Timeout"<<std::endl;
    return true;
  }


  return false;
}
