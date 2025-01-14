#pragma once
#include "controller/state_machine.hpp"

class PinocchioRobotSystem;
class DracoControlArchitecture;
class DracoStateProvider;

class DoubleSupportBalance : public StateMachine {
public:
  DoubleSupportBalance(const StateId state_id, PinocchioRobotSystem *robot,
                       DracoControlArchitecture *ctrl_arch);
  ~DoubleSupportBalance() = default;

  void FirstVisit() override;
  void OneStep() override;
  void LastVisit() override;
  bool EndOfState() override;

  StateId GetNextState() override;

  void SetParameters(const YAML::Node &node) override;

  // boolean setter
  void DoComSwaying() { b_com_swaying_ = true; }
  void DoComSwayingWithLMPC() { b_lmpc_swaying_ = true; }
  void DoComSwayingWithNMPC() { b_nmpc_swaying_ = true; }

  void DoDcmWalking() { b_dcm_walking_ = true; }
  void DoDcmWalkingWithLMPC() { b_lmpc_walking_ = true; }
  void DoDcmWalkingWithNMPC() { b_nmpc_walking_ = true; }

  void DoStaticWalking() { b_static_walking_ = true; }

private:
  DracoControlArchitecture *ctrl_arch_;

  DracoStateProvider *sp_;

  bool b_com_swaying_;
  bool b_lmpc_swaying_;
  bool b_nmpc_swaying_;

  bool b_dcm_walking_;
  bool b_lmpc_walking_;
  bool b_nmpc_walking_;

  bool b_static_walking_;
};
