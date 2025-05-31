#include "Shared/StateMachine.hpp"

namespace BCU::Shared::State {

SharedStateMachine::SharedStateMachine()
    : general(GeneralState::Connecting), nested(NestedState::Idle) {
    general.add_state(GeneralState::Operational);
    general.add_state(GeneralState::Fault);

    nested.add_state(NestedState::Ready);
    nested.add_state(NestedState::Boosting);
    nested.add_state(NestedState::Testing);

    general.add_state_machine(nested, GeneralState::Operational);
}

};  // namespace BCU::Shared::State

// 0x2404fdc9 ""