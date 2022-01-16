// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE
#pragma once

#include <cstdint>
#include "swganh/byte_buffer.h"
#include "swganh_core/messages/base_swg_message.h"

namespace swganh
{
namespace messages
{

struct ChatOnUninviteAvatar : public BaseSwgMessage
{
    uint16_t Opcount() const
    {
        return 0;
    }
    uint32_t Opcode() const
    {
        return 0xbe33c7e8;
    }

    void OnSerialize(swganh::ByteBuffer& buffer) const
    {
    }

    void OnDeserialize(swganh::ByteBuffer& buffer)
    {
    }
};

}
} // namespace swganh::messages
