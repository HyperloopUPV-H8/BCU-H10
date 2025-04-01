#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::Communication {

struct PhaseCurrents {
    float *u;
    float *v;
    float *w;
};

SPIStackOrder create_state_order(StateMachine::state_id *master_general_state,
                                 StateMachine::state_id *master_nested_state,
                                 StateMachine::state_id *slave_general_state,
                                 StateMachine::state_id *slave_nested_state);

SPIStackOrder create_control_order(std::array<PhaseCurrents, 4> phase_currents,
                                   std::array<float *, 4> dc_link_voltages,
                                   std::array<float *, 4> inverter_temperatures,
                                   float *position, float *speed,
                                   float *acceleration);

SPIStackOrder create_sync_order(bool *lcu_ready, bool *slave_ready);

}  // namespace BCU::Shared::Communication