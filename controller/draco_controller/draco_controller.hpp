#pragma once

class PinocchioRobotSystem;
class DracoTCIContainer;
class DracoStateProvider;
class IHWBC;

class DracoController {
public:
  DracoController(DracoTCIContainer *tci_container,
                  PinocchioRobotSystem *robot);
  virtual ~DracoController();

  void GetCommand(void *command);

private:
  PinocchioRobotSystem *robot_;
  DracoTCIContainer *tci_container_;
  DracoStateProvider *sp_;

  IHWBC ihwbc_;
};
