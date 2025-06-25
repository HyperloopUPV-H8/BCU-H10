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

SPIStackOrder *create_detailed_encoder_order(
    double *position_1, double *velocity_1, double *acceleration_1,
    uint8_t *direction_1, double *position_2, double *velocity_2,
    double *acceleration_2, uint8_t *direction_2) {
    return new SPIStackOrder{
        998,
        *new SPIPacket<0>(),
        *new SPIPacket<(sizeof(double) * 6) + (sizeof(uint8_t) * 2), double,
                       double, double, uint8_t, double, double, double,
                       uint8_t>{position_1, velocity_1, acceleration_1,
                                direction_1, position_2, velocity_2,
                                acceleration_2, direction_2},
    };
}

SPIStackOrder *create_start_precharge_order() {
    return new SPIStackOrder{
        997,
        *new SPIPacket<0>(),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_test_pwm_order(float *duty_u, float *duty_v,
                                     float *duty_w) {
    return new SPIStackOrder{
        996,
        *new SPIPacket<sizeof(float) * 3, float, float, float>(duty_u, duty_v,
                                                               duty_w),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_test_space_vector_order(float *i_mod, float *mod_freq) {
    return new SPIStackOrder{
        995,
        *new SPIPacket<sizeof(float) * 2, float, float>(i_mod, mod_freq),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_enable_current_control_order(float *current_d_ref,
                                                   float *current_q_ref) {
    return new SPIStackOrder{
        994,
        *new SPIPacket<sizeof(float) * 2, float, float>(current_d_ref,
                                                        current_q_ref),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_enable_velocity_control_order(float *velocity_ref) {
    return new SPIStackOrder{
        993,
        *new SPIPacket<sizeof(float)>(velocity_ref),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_encoder_order(double *position, double *velocity,
                                    double *acceleration, uint8_t *direction) {
    return new SPIStackOrder{
        992,
        *new SPIPacket<0>(),
        *new SPIPacket<(sizeof(double) * 3) + sizeof(uint8_t)>(
            position, velocity, acceleration, direction),
    };
}

SPIStackOrder *create_start_control_order() {
    return new SPIStackOrder{
        991,
        *new SPIPacket<0>(),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_stop_control_order() {
    return new SPIStackOrder{
        990,
        *new SPIPacket<0>(),
        *new SPIPacket<0>(),
    };
}

SPIStackOrder *create_disable_order() {
    return new SPIStackOrder{
        989,
        *new SPIPacket<0>(),
        *new SPIPacket<0>(),
    };
}

}  // namespace BCU::Shared::Communication
