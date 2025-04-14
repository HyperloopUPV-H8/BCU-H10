#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::Communication {

SPIStackOrder *create_state_order(StateMachine::state_id *master_general_state,
                                  StateMachine::state_id *master_nested_state,
                                  StateMachine::state_id *slave_general_state,
                                  StateMachine::state_id *slave_nested_state);

SPIStackOrder *create_start_test_pwm_order(float *duty_cycle_u,
                                           float *duty_cycle_v,
                                           float *duty_cycle_w);

SPIStackOrder *create_configure_commutation_parameters_order(
    uint32_t *commutation_frequency_hz, uint32_t *dead_time_ns);

SPIStackOrder *create_stop_control_order();

SPIStackOrder *create_control_parameters_order(float *duty_cycle_u,
                                               float *duty_cycle_v,
                                               float *duty_cycle_w);

SPIStackOrder *create_start_space_vector_order(float *modulation_index,
                                               float *modulation_frequency_hz);

}  // namespace BCU::Shared::Communication