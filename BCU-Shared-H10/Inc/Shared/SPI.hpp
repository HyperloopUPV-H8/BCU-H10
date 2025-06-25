#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::Communication {

SPIStackOrder *create_state_order(StateMachine::state_id *master_general_state,
                                  StateMachine::state_id *master_nested_state,
                                  StateMachine::state_id *slave_general_state,
                                  StateMachine::state_id *slave_nested_state);

SPIStackOrder *create_detailed_encoder_order(
    double *position_1, double *velocity_1, double *acceleration_1,
    uint8_t *direction_1, double *position_2, double *velocity_2,
    double *acceleration_2, uint8_t *direction_2);

SPIStackOrder *create_start_precharge_order();

SPIStackOrder *create_test_pwm_order(float *duty_u, float *duty_v,
                                     float *duty_w);
SPIStackOrder *create_test_space_vector_order(float *i_mod, float *mod_freq);

SPIStackOrder *create_enable_current_control_order(float *current_d_ref,
                                                   float *current_q_ref);
SPIStackOrder *create_enable_velocity_control_order(float *velocity_ref);

SPIStackOrder *create_encoder_order(double *position, double *velocity,
                                    double *acceleration, uint8_t *direction);

SPIStackOrder *create_start_control_order();
SPIStackOrder *create_stop_control_order();

SPIStackOrder *create_disable_order();

}  // namespace BCU::Shared::Communication
