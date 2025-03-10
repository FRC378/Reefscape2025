// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Elevator.h"
#include <rev/config/SparkMaxConfig.h>
#include <iostream>
#include <cmath>
#include <frc/smartdashboard/SmartDashboard.h>



#define ELEVATOR_HOME_DEFAULT 0.0
#define ELEVATOR_L2_DEFAULT   110.0
#define ELEVATOR_L3_DEFAULT   250.0
#define ELEVATOR_AUX_DEFAULT  50.0



Elevator::Elevator()
{

  //SparkMaxConfigurator
  rev::spark::SparkMaxConfig motorConfig;
 
  motorConfig
        .SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
        .SmartCurrentLimit(40)
        .Inverted(true)
        .OpenLoopRampRate(0.25);
//      .ClosedLoopRampRate(0.3);

  motorConfig.encoder
        .PositionConversionFactor(1.0)        //Stick with Rotations as a position
        .VelocityConversionFactor(1.0);       //Stick with RPM as a velocity

  motorConfig.closedLoop
        .SetFeedbackSensor(rev::spark::ClosedLoopConfig::FeedbackSensor::kPrimaryEncoder)
        .Pid(0.2, 0, 0)
        .OutputRange(-.95, 0.95);

  motorConfig.closedLoop.maxMotion
        .MaxVelocity( 1000.0 )
        .MaxAcceleration ( 1500.0 )
        .AllowedClosedLoopError( 0.1 );


  m_elevator.Configure( motorConfig,
                    rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                    rev::spark::SparkMax::PersistMode::kPersistParameters);


  //set Position Defaults
  frc::SmartDashboard::PutNumber( "ElevatorLevelHome", ELEVATOR_HOME_DEFAULT );
  frc::SmartDashboard::PutNumber( "ElevatorLevelL2",   ELEVATOR_L2_DEFAULT   );
  frc::SmartDashboard::PutNumber( "ElevatorLevelL3",   ELEVATOR_L3_DEFAULT   );
  frc::SmartDashboard::PutNumber( "ElevatorLevelAux",  ELEVATOR_AUX_DEFAULT  );

}

// This method will be called once per scheduler run
void Elevator::Periodic() 
{

  //Elevator Debugging
  frc::SmartDashboard::PutNumber( "ElevatorPosition", GetPosition() );
  frc::SmartDashboard::PutBoolean("ElevatorUpperSw",  GetUpperLimitSwitch() );
  frc::SmartDashboard::PutBoolean("ElevatorLowerSw",  GetLowerLimitSwitch() );
  frc::SmartDashboard::PutNumber( "ElevatorVelocity", m_motorEncoder.GetVelocity() );

  //Check Lower limit switch for Home
  if( GetLowerLimitSwitch() && ( fabs(GetPosition()) > 0.2 ))
  {
    ZeroEncoder();
  }

}



  void Elevator::Stop(void)
  {
    m_elevator.Set(0.0);
  }
  
  bool Elevator::GetLowerLimitSwitch(void)
  {
    return m_elevator.GetReverseLimitSwitch().Get();
  }
  bool Elevator::GetUpperLimitSwitch(void)
  {
    return m_elevator.GetForwardLimitSwitch().Get();
  }

  double Elevator::GetPosition(void)
  {
    return m_motorEncoder.GetPosition();
  }
  void Elevator::SetPosition(double position)
  {
    m_motorPID.SetReference( position, rev::spark::SparkMax::ControlType::kPosition );  //Default PID

    //m_motorPID.SetReference( position, rev::spark::SparkMax::ControlType::kMAXMotionPositionControl );  //MaxMotion

    //m_motorPID.SetReference( position, rev::spark::SparkMax::ControlType::kPosition, rev::spark::kSlot0, 0.01 );  //Arbitrary feed forward

  }

  void   Elevator::SetLevel(elevator_level_t level)
  {

    switch(level)
    {
      case ELEVATOR_HOME:
        SetPosition( frc::SmartDashboard::GetNumber( "ElevatorLevelHome", ELEVATOR_HOME_DEFAULT ) );
        break;

      case ELEVATOR_L2:
        SetPosition( frc::SmartDashboard::GetNumber( "ElevatorLevelL2", ELEVATOR_L2_DEFAULT ) );
        break;

     case ELEVATOR_L3:
        SetPosition( frc::SmartDashboard::GetNumber( "ElevatorLevelL3", ELEVATOR_L3_DEFAULT ) );
        break;

     case ELEVATOR_AUX:
        SetPosition( frc::SmartDashboard::GetNumber( "ElevatorLevelAux", ELEVATOR_AUX_DEFAULT ) );
        break;
    }
  }


  void Elevator::SetPower(double power)
  {
    //std::cout<<"SetPower"<<std::endl;
    m_elevator.Set(power);
  }

 void   Elevator::ZeroEncoder(void)
 {
    m_motorEncoder.SetPosition(0.0);
    std::cout << "ZeroElevator" << std::endl;
 }




