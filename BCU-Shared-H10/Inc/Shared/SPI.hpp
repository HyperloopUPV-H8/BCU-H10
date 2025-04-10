#pragma once

#include "ST-LIB.hpp"

namespace BCU::Shared::Communication {

SPIStackOrder *create_state_order(StateMachine::state_id *master_general_state,
                                  StateMachine::state_id *master_nested_state,
                                  StateMachine::state_id *slave_general_state,
                                  StateMachine::state_id *slave_nested_state);

SPIStackOrder *create_control_parameters_order(
    double *velocity_reference, double *velocity_error,
    double *u_current_measurement, double *v_current_measurement,
    double *w_current_measurement, double *electrical_angle,
    double *d_current_reference, double *d_current_measurement,
    double *d_current_error, double *q_current_reference,
    double *q_current_measurement, double *q_current_error,
    double *three_phase_unbalance, double *d_target_voltage,
    double *q_target_voltage, double *u_target_voltage,
    double *v_target_voltage, double *w_target_voltage,
    double *u_output_voltage, double *v_output_voltage,
    double *w_output_voltage, double *u_duty_cycle, double *v_duty_cycle,
    double *w_duty_cycle, double *angular_velocity);

SPIStackOrder *create_start_velocity_control_order(double *velocity_reference);
SPIStackOrder *create_start_current_control_order(double *d_current_reference,
                                                  double *q_current_reference);
SPIStackOrder *create_start_emulated_movement_order(double *d_current_reference,
                                                    double *q_current_reference,
                                                    double *angular_velocity);
SPIStackOrder *create_start_test_pwm_order(double *duty_cycle_u,
                                           double *duty_cycle_v,
                                           double *duty_cycle_w);

SPIStackOrder *create_stop_control_order();

SPIStackOrder *create_enable_booster_order();

enum Direction : uint8_t {
    FORWARD = 0,
    BACKWARD = 1,
};

SPIStackOrder *create_position_encoder_order(
    std::array<double *, 3> position, std::array<double *, 3> velocity,
    std::array<double *, 3> acceleration, std::array<Direction *, 3> direction,
    double *average_position, double *max_velocity, bool *is_detecting);

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