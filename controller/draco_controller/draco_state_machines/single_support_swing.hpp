#pragma once

#include "controller/state_machine.hpp"

class PinocchioRobotSystem;
class DracoControlArchitecture;
class DracoStateProvider;

class SingleSupportSwing : public StateMachine {
public:
  SingleSupportSwing(StateId state_id, PinocchioRobotSystem *robot,
                     DracoControlArchitecture *ctrl_arch);
  ~SingleSupportSwing() = default;

  void FirstVisit() override;
  void OneStep() override;
  void LastVisit() override;
  bool EndOfState() override;
  StateId GetNextState() override;

  void SetParameters(const YAML::Node &node) override;

private:
  DracoControlArchitecture *ctrl_arch_;
  DracoStateProvider *sp_;

  double swing_height_;
};
