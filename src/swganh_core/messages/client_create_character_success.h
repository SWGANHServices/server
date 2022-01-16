// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE
#pragma once

#include <cstdint>
#include "swganh/byte_buffer.h"
#include "base_swg_message.h"

namespace swganh
{
namespace messages
{

struct ClientCreateCharacterSuccess : public BaseSwgMessage
{
    uint16_t Opcount() const
    {
        return 2;
    }
    uint32_t Opcode() const
    {
        return 0x1DB575CC;
    }

    uint64_t character_id;

    void OnSerialize(swganh::ByteBuffer& buffer) const
    {
        buffer.write(character_id);
    }

    void OnDeserialize(swganh::ByteBuffer& buffer)
    {
        character_id = buffer.read<uint64_t>();
    }
};

}
}  // namespace swganh::messages
