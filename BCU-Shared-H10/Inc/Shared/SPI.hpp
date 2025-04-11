#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::Communication {

SPIStackOrder *create_state_order(StateMachine::state_id *master_general_state,
                                  StateMachine::state_id *master_nested_state,
                                  StateMachine::state_id *slave_general_state,
                                  StateMachine::state_id *slave_nested_state);

SPIStackOrder *create_control_parameters_order(
    float *velocity_reference, float *velocity_error,
    float *u_current_measurement, float *v_current_measurement,
    float *w_current_measurement, float *electrical_angle,
    float *d_current_reference, float *d_current_measurement,
    float *d_current_error, float *q_current_reference,
    float *q_current_measurement, float *q_current_error,
    float *three_phase_unbalance, float *d_target_voltage,
    float *q_target_voltage, float *u_target_voltage, float *v_target_voltage,
    float *w_target_voltage, float *u_output_voltage, float *v_output_voltage,
    float *w_output_voltage, float *u_duty_cycle, float *v_duty_cycle,
    float *w_duty_cycle, float *angular_velocity);

SPIStackOrder *create_start_velocity_control_order(float *velocity_reference);
SPIStackOrder *create_start_current_control_order(float *d_current_reference,
                                                  float *q_current_reference);
SPIStackOrder *create_start_emulated_movement_order(float *d_current_reference,
                                                    float *q_current_reference,
                                                    float *angular_velocity);
SPIStackOrder *create_start_test_pwm_order(float *duty_cycle_u,
                                           float *duty_cycle_v,
                                           float *duty_cycle_w);

SPIStackOrder *create_stop_control_order();

SPIStackOrder *create_enable_booster_order();

enum Direction : uint8_t {
    FORWARD = 0,
    BACKWARD = 1,
};

SPIStackOrder *create_position_encoder_order(
    std::array<float *, 3> position, std::array<float *, 3> velocity,
    std::array<float *, 3> acceleration, std::array<Direction *, 3> direction,
    float *average_position, float *max_velocity, bool *is_detecting);

SPIStackOrder *create_force_dc_link_order(float *dc_link_voltage);
SPIStackOrder *create_unlock_dc_link_order();

SPIStackOrder *create_commutation_settings_order(uint32_t *frequency_hz,
                                                 uint32_t *dead_time_ns);

SPIStackOrder *create_motor_driver_order(
    std::array<float *, 4> dc_link_voltage,
    std::array<std::array<float *, 3>, 4> motor_phase_current,
    std::array<PinState *, 4> gate_driver_fault,
    std::array<PinState *, 4> gate_driver_ready);

}  // namespace BCU::Shared::Communication