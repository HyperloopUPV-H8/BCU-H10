#include "Shared/SPI.hpp"

namespace BCU::Shared::Communication {

SPIStackOrder *create_state_order(StateMachine::state_id *master_general_state,
                                  StateMachine::state_id *master_nested_state,
                                  StateMachine::state_id *slave_general_state,
                                  StateMachine::state_id *slave_nested_state) {
    return new SPIStackOrder{
        999,
        *new SPIPacket<sizeof(StateMachine::state_id) * 2,
                       StateMachine::state_id, StateMachine::state_id>{
            master_general_state, master_nested_state},
        *new SPIPacket<sizeof(StateMachine::state_id) * 2,
                       StateMachine::state_id, StateMachine::state_id>{
            slave_general_state, slave_nested_state}};
}

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
    float *w_duty_cycle, float *angular_velocity) {
    return new SPIStackOrder{
        998, *new SPIPacket<0>(),
        *new SPIPacket<sizeof(float) * 25, float, float, float, float, float,
                       float, float, float, float, float, float, float, float,
                       float, float, float, float, float, float, float, float,
                       float, float, float, float>(
            velocity_reference, velocity_error, u_current_measurement,
            v_current_measurement, w_current_measurement, electrical_angle,
            d_current_reference, d_current_measurement, d_current_error,
            q_current_reference, q_current_measurement, q_current_error,
            three_phase_unbalance, d_target_voltage, q_target_voltage,
            u_target_voltage, v_target_voltage, w_target_voltage,
            u_output_voltage, v_output_voltage, w_output_voltage, u_duty_cycle,
            v_duty_cycle, w_duty_cycle, angular_velocity)};
};

SPIStackOrder *create_start_velocity_control_order(float *velocity_reference) {
    return new SPIStackOrder{
        997, *new SPIPacket<sizeof(float), float>{velocity_reference},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_start_current_control_order(float *d_current_reference,
                                                  float *q_current_reference) {
    return new SPIStackOrder{996,
                             *new SPIPacket<sizeof(float) * 2, float, float>{
                                 d_current_reference, q_current_reference},
                             *new SPIPacket<0>()};
}

SPIStackOrder *create_start_emulated_movement_order(float *d_current_reference,
                                                    float *q_current_reference,
                                                    float *angular_velocity) {
    return new SPIStackOrder{
        995,
        *new SPIPacket<sizeof(float) * 3, float, float, float>{
            d_current_reference, q_current_reference, angular_velocity},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_start_test_pwm_order(float *duty_cycle_u,
                                           float *duty_cycle_v,
                                           float *duty_cycle_w) {
    return new SPIStackOrder{
        994,
        *new SPIPacket<sizeof(float) * 3, float, float, float>{
            duty_cycle_u, duty_cycle_v, duty_cycle_w},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_stop_control_order() {
    return new SPIStackOrder{993, *new SPIPacket<0>(), *new SPIPacket<0>()};
}

SPIStackOrder *create_enable_booster_order() {
    return new SPIStackOrder{992, *new SPIPacket<0>(), *new SPIPacket<0>()};
}

SPIStackOrder *create_position_encoder_order(
    std::array<float *, 3> position, std::array<float *, 3> velocity,
    std::array<float *, 3> acceleration, std::array<Direction *, 3> direction,
    float *average_position, float *max_velocity, bool *is_detecting) {
    return new SPIStackOrder{
        991, *new SPIPacket<0>(),
        *new SPIPacket<
            sizeof(float) * 12 + sizeof(Direction) * 3 + sizeof(bool), float,
            float, float, float, float, float, float, float, float, Direction,
            Direction, Direction, float, float, bool>(
            position[0], position[1], position[2], velocity[0], velocity[1],
            velocity[2], acceleration[0], acceleration[1], acceleration[2],
            direction[0], direction[1], direction[2], average_position,
            max_velocity, is_detecting)};
}

SPIStackOrder *create_force_dc_link_order(float *dc_link_voltage) {
    return new SPIStackOrder{
        990, *new SPIPacket<sizeof(float), float>{dc_link_voltage},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_unlock_dc_link_order() {
    return new SPIStackOrder{989, *new SPIPacket<0>(), *new SPIPacket<0>()};
}

SPIStackOrder *create_commutation_settings_order(uint32_t *frequency_hz,
                                                 uint32_t *dead_time_ns) {
    return new SPIStackOrder{
        988,
        *new SPIPacket<sizeof(uint32_t) * 2, uint32_t, uint32_t>{frequency_hz,
                                                                 dead_time_ns},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_motor_driver_order(
    std::array<float *, 4> dc_link_voltage,
    std::array<std::array<float *, 3>, 4> motor_phase_current,
    std::array<PinState *, 4> gate_driver_fault,
    std::array<PinState *, 4> gate_driver_ready) {
    return new SPIStackOrder{
        987, *new SPIPacket<0>(),
        *new SPIPacket<
            sizeof(float) * 4 + sizeof(PinState) * 8 + sizeof(float) * 12,
            float, float, float, float, PinState, PinState, PinState, PinState,
            PinState, PinState, PinState, PinState, float, float, float, float,
            float, float, float, float, float, float, float, float>(
            dc_link_voltage[0], dc_link_voltage[1], dc_link_voltage[2],
            dc_link_voltage[3], gate_driver_fault[0], gate_driver_fault[1],
            gate_driver_fault[2], gate_driver_fault[3], gate_driver_ready[0],
            gate_driver_ready[1], gate_driver_ready[2], gate_driver_ready[3],
            motor_phase_current[0][0], motor_phase_current[0][1],
            motor_phase_current[0][2], motor_phase_current[1][0],
            motor_phase_current[1][1], motor_phase_current[1][2],
            motor_phase_current[2][0], motor_phase_current[2][1],
            motor_phase_current[2][2], motor_phase_current[3][0],
            motor_phase_current[3][1], motor_phase_current[3][2])};
}

}  // namespace BCU::Shared::Communication
