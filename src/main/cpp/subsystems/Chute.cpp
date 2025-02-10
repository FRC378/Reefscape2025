// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chute.h"
#include  <rev/config/SparkMaxConfig.h>

Chute::Chute()
{
    
  //SparkMaxConfigurator
  rev::spark::SparkMaxConfig motorConfig;
 
  motorConfig
        .SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
        .SmartCurrentLimit(50)
        .Inverted(false)
        .OpenLoopRampRate(0.3);
//      .ClosedLoopRampRate(0.3);

  motorConfig.encoder
        .PositionConversionFactor(1.0)        //Stick with Rotations as a position
        .VelocityConversionFactor(1.0);       //Stick with RPM as a velocity

//   motorConfig.closedLoop
//         .SetFeedbackSensor(rev::spark::ClosedLoopConfig::FeedbackSensor::kPrimaryEncoder)
//         .Pid(0.05, 0, 0)
//         .OutputRange(-.09, 0.1);


  m_pinMotor.Configure( motorConfig,
                    rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                    rev::spark::SparkMax::PersistMode::kPersistParameters);

}

// This method will be called once per scheduler run
void Chute::Periodic() 
{

}
//bool   Chute::GetLimitSwitch(void)
//{
 
//}
void   Chute::StopMotor(void)
{
  m_pinMotor.Set(0.0);
}
void   Chute::SetPinMotorPower(double power)
{
  m_pinMotor.Set(power);
}
double Chute::GetPinMotorEncoder(void)
{
  return m_pinMotorEncoder.GetPosition();
}
bool   Chute::GetCoralDetectSensor(void)
{
  return false; //fix later
}



