// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE

#pragma once

#include <memory>

namespace swganh {

    class ByteBuffer;

namespace network {

    class Session;
	
    struct CrcOutFilter {
    public:    
        void operator()(Session* session, ByteBuffer* message);
    };

}} // namespace swganh::network
