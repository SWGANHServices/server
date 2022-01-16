// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE
#pragma once

#include "swganh_core/object/object_factory.h"
#include <unordered_map>

namespace swganh
{
namespace database
{
class DatabaseManagerInterface;
}
} // swganh::database

namespace swganh
{
namespace object
{

class Intangible;

class IntangibleFactory : public swganh::object::ObjectFactory
{
public:
    IntangibleFactory(swganh::app::SwganhKernel* kernel);
    virtual ~IntangibleFactory() {}

    virtual void LoadFromStorage(const std::shared_ptr<sql::Connection>& connection, const std::shared_ptr<Object>& object, boost::unique_lock<boost::mutex>& lock);

    virtual uint32_t PersistObject(const std::shared_ptr<swganh::object::Object>& object, boost::unique_lock<boost::mutex>& lock, bool persist_inherited = false);

    void DeleteObjectFromStorage(const std::shared_ptr<swganh::object::Object>& object);
    virtual void PersistChangedObjects() {}

    std::shared_ptr<swganh::object::Object> CreateObject();

    virtual void RegisterEventHandlers() {}
private:
};

}
}  // namespace swganh::object
