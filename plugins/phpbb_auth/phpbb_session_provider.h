// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE

#ifndef PLUGINS_PHPBB_AUTH_PHPBB_SESSION_PROVIDER_H_
#define PLUGINS_PHPBB_AUTH_PHPBB_SESSION_PROVIDER_H_

#include <cstdint>

#include "anh/database/database_manager_interface.h"
#include "swganh/connection/providers/session_provider_interface.h"

namespace plugins {
namespace phpbb_auth {

class PhpbbSessionProvider : public swganh::connection::providers::SessionProviderInterface 
{
public:
    PhpbbSessionProvider(anh::database::DatabaseManagerInterface* database_manager,
        std::string table_prefix);

    uint64_t GetPlayerId(uint32_t account_id);

    virtual uint32_t GetAccountId(uint64_t player_id);
    virtual bool CreateGameSession(uint64_t player_id, uint32_t session_id);
	virtual void EndGameSession(uint64_t player_id);

private:
    bool CreatePlayerAccount_(uint64_t account_id);
    uint64_t FindPlayerByReferenceId_(uint64_t account_id);

    anh::database::DatabaseManagerInterface* database_manager_;
    std::string table_prefix_;
};

}}  // namespace plugins::phpbb_auth

#endif  // PLUGINS_PHPBB_AUTH_PHPBB_SESSION_PROVIDER_H_
