#include "Shared/StateMachine.hpp"

namespace BCU::Shared::State {

SharedStateMachine::SharedStateMachine()
    : general_state_machine(GeneralState::Connecting),
      nested_state_machine(NestedState::Idle) {
    general_state_machine.add_state(GeneralState::Operational);
    general_state_machine.add_state(GeneralState::Fault);

    nested_state_machine.add_state(NestedState::Ready);
    nested_state_machine.add_state(NestedState::Boosting);
    nested_state_machine.add_state(NestedState::Testing);

    general_state_machine.add_state_machine(nested_state_machine,
                                            GeneralState::Operational);
}

};  // namespace BCU::Shared::State

// 0x2404fdc9 ""