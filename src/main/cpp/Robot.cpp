// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

//Global Objects
RobotContainer g_robotContainer;  


//Prototypes
void WriteToSmartDashboard(void);


Robot::Robot()
{
  //*************************** INIT ******************************
  cout<<"RobotInit"<<endl;
  cout<<"FRC2025: ~~~ Blinky ~~~"<<endl;
  cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<endl<<endl; 

  //Robot Initialization
  g_robotContainer.m_elevator.Stop();
  g_robotContainer.m_elevator.ZeroEncoder();

}

void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();

  WriteToSmartDashboard();
}

void Robot::DisabledInit() 
{
    cout<<"DisabledInit"<<endl;
}

void Robot::DisabledPeriodic() {}

void Robot::DisabledExit() {}

void Robot::AutonomousInit() 
{
  cout<<"AutonomousInit"<<endl;
  m_autonomousCommand = g_robotContainer.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }

}

void Robot::AutonomousPeriodic() {}

void Robot::AutonomousExit() {}

void Robot::TeleopInit() 
{
  cout<<"TeleopInit"<<endl;
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TeleopExit() {}

void Robot::TestInit() {
  frc2::CommandScheduler::GetInstance().CancelAll();
}

void Robot::TestPeriodic() {}

void Robot::TestExit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif


// WriteToSmartDashboard
void WriteToSmartDashboard(void)
{


}


