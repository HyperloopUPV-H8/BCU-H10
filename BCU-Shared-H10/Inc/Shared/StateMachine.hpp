#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::State {

struct SharedStateMachine {
    enum GeneralState : uint8_t { Connecting = 0, Operational = 1, Fault = 2 };

    enum NestedState : uint8_t {
        Idle = 0,
        Precharge = 1,
        Ready = 2,
        Boosting = 3,
        Testing = 4
    };

    StateMachine general;
    StateMachine nested;

    SharedStateMachine();
};

}  // namespace BCU::Shared::State
