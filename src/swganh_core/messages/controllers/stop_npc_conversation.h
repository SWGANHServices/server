// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE
#pragma once

#include <cstdint>
#include <string>
#include "swganh/byte_buffer.h"

#include "swganh_core/messages/obj_controller_message.h"

namespace swganh
{
namespace messages
{
namespace controllers
{

class StopNPCConversation : public ObjControllerMessage
{
public:
    explicit StopNPCConversation(uint32_t controller_type = 0x0000000B)
        : ObjControllerMessage(controller_type, message_type())
        , npc_id(0)
    {}

    StopNPCConversation(const ObjControllerMessage& base)
        : ObjControllerMessage(base)
    {
    }

    static uint32_t message_type()
    {
        return 0x000000DE;
    }

    uint64_t npc_id;


    void OnControllerSerialize(swganh::ByteBuffer& buffer) const
    {
        buffer.write(npc_id);
        // @TODO Unknown
        buffer.write<uint32_t>(0);
        buffer.write<uint16_t>(0);
        buffer.write<uint8_t>(0);
    }

    void OnControllerDeserialize(swganh::ByteBuffer& buffer)
    {
        npc_id = buffer.read<uint64_t>();
    }
};

}
}
}  // namespace swganh::messages::controllers
