#include "Shared/SPI.hpp"

namespace BCU::Shared::Communication {

SPIStackOrder create_state_order(StateMachine::state_id *master_general_state,
                                 StateMachine::state_id *master_nested_state,
                                 StateMachine::state_id *slave_general_state,
                                 StateMachine::state_id *slave_nested_state) {
    static SPIPacket<sizeof(StateMachine::state_id) * 2, StateMachine::state_id,
                     StateMachine::state_id>
        master_packet{master_general_state, master_nested_state};

    static SPIPacket<sizeof(StateMachine::state_id) * 2, StateMachine::state_id,
                     StateMachine::state_id>
        slave_packet{slave_general_state, slave_nested_state};

    return SPIStackOrder{0, slave_packet, master_packet};
}

SPIStackOrder create_control_order(std::array<PhaseCurrents, 4> phase_currents,
                                   std::array<float *, 4> dc_link_voltages,
                                   std::array<float *, 4> inverter_temperatures,
                                   float *position, float *speed,
                                   float *acceleration) {
    static SPIPacket<sizeof(float) * 4, float, float, float, float>
        master_packet{inverter_temperatures[0], inverter_temperatures[1],
                      inverter_temperatures[2], inverter_temperatures[3]};

    static SPIPacket<sizeof(float) * 19, float, float, float, float, float,
                     float, float, float, float, float, float, float, float,
                     float, float, float, float, float, float>
        slave_packet{phase_currents[0].u,
                     phase_currents[0].v,
                     phase_currents[0].w,
                     phase_currents[1].u,
                     phase_currents[1].v,
                     phase_currents[1].w,
                     phase_currents[2].u,
                     phase_currents[2].v,
                     phase_currents[2].w,
                     phase_currents[3].u,
                     phase_currents[3].v,
                     phase_currents[3].w,
                     dc_link_voltages[0],
                     dc_link_voltages[1],
                     dc_link_voltages[2],
                     dc_link_voltages[3],
                     position,
                     speed,
                     acceleration};

    return SPIStackOrder{1, slave_packet, master_packet};
}

SPIStackOrder create_sync_order(bool *lcu_ready, bool *slave_ready) {
    static SPIPacket<sizeof(bool), bool> master_packet{lcu_ready};

    static SPIPacket<sizeof(bool), bool> slave_packet{slave_ready};

    return SPIStackOrder{2, slave_packet, master_packet};
}

};  // namespace BCU::Shared::Communication