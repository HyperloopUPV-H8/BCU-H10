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

SPIStackOrder *create_start_test_pwm_order(float *duty_cycle_u,
                                           float *duty_cycle_v,
                                           float *duty_cycle_w) {
    return new SPIStackOrder{
        998,
        *new SPIPacket<sizeof(float) * 3, float, float, float>{
            duty_cycle_u, duty_cycle_v, duty_cycle_w},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_stop_control_order() {
    return new SPIStackOrder{997, *new SPIPacket<0>(), *new SPIPacket<0>()};
}

SPIStackOrder *create_configure_commutation_parameters_order(
    uint32_t *frequency_hz, uint32_t *dead_time_ns) {
    return new SPIStackOrder{
        996,
        *new SPIPacket<sizeof(uint32_t) * 2, uint32_t, uint32_t>{frequency_hz,
                                                                 dead_time_ns},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_control_parameters_order(float *duty_cycle_u,
                                               float *duty_cycle_v,
                                               float *duty_cycle_w) {
    return new SPIStackOrder{
        995, *new SPIPacket<0>(),
        *new SPIPacket<sizeof(float) * 3, float, float, float>{
            duty_cycle_u, duty_cycle_v, duty_cycle_w}};
}

SPIStackOrder *create_start_space_vector_order(float *modulation_index,
                                               float *modulation_frequency_hz) {
    return new SPIStackOrder{994,
                             *new SPIPacket<sizeof(float) * 2, float, float>{
                                 modulation_index, modulation_frequency_hz},
                             *new SPIPacket<0>()};
}

SPIStackOrder *create_fix_dc_link_voltage_order(float *dc_link_voltage) {
    return new SPIStackOrder{
        993, *new SPIPacket<sizeof(float), float>{dc_link_voltage},
        *new SPIPacket<0>()};
}

SPIStackOrder *create_unfix_dc_link_voltage_order() {
    return new SPIStackOrder{992, *new SPIPacket<0>(), *new SPIPacket<0>()};
}

SPIStackOrder *create_dc_link_order(float *average_dc_link_voltage,
                                    float *dc_link_voltage_1,
                                    float *dc_link_voltage_2,
                                    float *dc_link_voltage_3,
                                    float *dc_link_voltage_4) {
    return new SPIStackOrder{
        991, *new SPIPacket<0>(),
        *new SPIPacket<sizeof(float) * 5, float, float, float, float, float>{
            average_dc_link_voltage, dc_link_voltage_1, dc_link_voltage_2,
            dc_link_voltage_3, dc_link_voltage_4}};
}

}  // namespace BCU::Shared::Communication
