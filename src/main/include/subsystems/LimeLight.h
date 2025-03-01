// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class LimeLight : public frc2::SubsystemBase {
 public:
  LimeLight(std::string llname);

 
  int    GetTargetId(void);
  bool   IsTargetValid(void);

  double GetTargetHAngle(void);
  double GetTargetVAngle(void);
  double GetTargetDistance(void);
  void   SetPipeline(int value);
  int    GetPipeline(void);


  void    RunLimeLight(void);

  void Periodic() override;

 private:
  int    m_targetId;  
  bool   m_targetValid;
  double m_targetYaw;
  double m_targetDistance;
   std::string m_LLName;
};
