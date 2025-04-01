#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::State {

struct SharedStateMachine {
    enum GeneralState : uint8_t { Connecting = 0, Operational = 1, Fault = 2 };

    enum NestedState : uint8_t { Idle = 0, Ready = 1, Boosting = 2 };

    StateMachine general_state_machine;
    StateMachine nested_state_machine;

    SharedStateMachine();
};

}  // namespace BCU::Shared::State