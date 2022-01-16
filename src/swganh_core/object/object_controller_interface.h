// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE
#pragma once

#include <exception>
#include <functional>
#include <memory>
#include <unordered_map>

#include <boost/noncopyable.hpp>

#ifdef WIN32
#include <concurrent_unordered_map.h>
#else
#include <tbb/concurrent_unordered_map.h>

namespace Concurrency
{
using ::tbb::concurrent_unordered_map;
}

#endif

#include "swganh/observer/observer_interface.h"
#include "swganh_core/messages/obj_controller_message.h"
#include "swganh_core/messages/controllers/show_fly_text.h"

namespace swganh
{
namespace connection
{
class ConnectionClientInterface;
}
}

namespace swganh
{
namespace messages
{
class OutOfBand;
}
}

namespace swganh
{
namespace object
{

class Object;

class ObjectControllerInterface : public swganh::observer::ObserverInterface, public std::enable_shared_from_this<ObjectControllerInterface>
{
public:
    typedef std::runtime_error InvalidControllerMessage;

public:
    ObjectControllerInterface(
        std::shared_ptr<Object> object,
        std::shared_ptr<swganh::connection::ConnectionClientInterface> client);

    ~ObjectControllerInterface();

    uint64_t GetId() const;

    /**
     * @return Handle to the object this controller manages.
     */
    std::shared_ptr<Object> GetObject() const;

    /**
     * @return Handle to the remote client controlling the object.
     */
    std::shared_ptr<swganh::connection::ConnectionClientInterface> GetRemoteClient();

    /**
     * Sets handle to the remote client controlling the object.
     *
     * @param remote_client the new remote client for this controller.
     */
    void SetRemoteClient(std::shared_ptr<swganh::connection::ConnectionClientInterface> remote_client);

    using swganh::observer::ObserverInterface::Notify;

    /**
     * Notifies the controller when the object has been updated.
     *
     * @param message The message to be delivered to the remote client.
     */
    void Notify(swganh::messages::BaseSwgMessage* message);

private:

    ObjectControllerInterface();

    std::shared_ptr<Object> object_;
    std::shared_ptr<swganh::connection::ConnectionClientInterface> client_;
};

}
}  // namespace swganh::object