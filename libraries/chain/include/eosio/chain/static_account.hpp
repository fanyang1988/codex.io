#pragma once

#include <vector>

#include <eosio/chain/multi_index_includes.hpp>
#include <eosio/chain/types.hpp>

namespace eosio {
namespace chain {

class static_account_object
   : public chainbase::object<static_account_object_type, static_account_object> {
   OBJECT_CTOR( static_account_object );

   id_type id;
   account_name name;
   std::vector<action_name> actnames;
};

struct by_contract_account;

using static_account_object_index = chainbase::shared_multi_index_container<
   static_account_object,
   indexed_by<
      ordered_unique<
         tag<by_id>,
         BOOST_MULTI_INDEX_MEMBER( static_account_object, static_account_object::id_type, id )>,
      ordered_non_unique<tag<by_contract_account>,
                         BOOST_MULTI_INDEX_MEMBER( static_account_object, account_name, name )>>>;
} // namespace chain
} // namespace eosio

FC_REFLECT( eosio::chain::static_account_object, ( id )( name )( actnames ) )
CHAINBASE_SET_INDEX_TYPE( eosio::chain::static_account_object,
                          eosio::chain::static_account_object_index )
