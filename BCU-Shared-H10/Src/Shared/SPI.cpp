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

}  // namespace BCU::Shared::Communication
