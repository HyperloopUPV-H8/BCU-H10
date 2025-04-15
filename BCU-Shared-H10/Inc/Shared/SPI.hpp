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

SPIStackOrder *create_fix_dc_link_voltage_order(float *dc_link_voltage);
SPIStackOrder *create_unfix_dc_link_voltage_order();
SPIStackOrder *create_dc_link_order(float *average_dc_link_voltage,
                                    float *dc_link_voltage_1,
                                    float *dc_link_voltage_2,
                                    float *dc_link_voltage_3,
                                    float *dc_link_voltage_4);

}  // namespace BCU::Shared::Communication