#pragma once

#include <cstdint>
#include <initializer_list>
#include <map>
#include "contrib.hpp"

namespace CryptoNote {
namespace parameters {

#define CRYPTONOTE_MAX_BLOCK_NUMBER                   	500000000
#define CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                	500000000
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX         0x29d0 // addresses start with "br"
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            10 
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               30
#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_v0            11  //jagerman's patch 

#define COIN                                            UINT64_C(100000000) // pow(10, 6)
#define MONEY_SUPPLY                                    UINT64_C(2100000000) * COIN

#define CRYPTONOTE_COIN_VERSION                         1
#define MIN_MIXIN                          	        0

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE       1000000 //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_v0        100000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_v1        1000000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE              600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                    8

// COIN - number of smallest units in one coin
#define POINT                                           UINT64_C(1000) // pow(10, 3)
#define TAIL_EMISSION_REWARD                            UINT64_C(10000000000)
#define PRE_BLOCK_REWARD	                        UINT64_C(84100000000000000) // premine first block
#define MINIMUM_FEE                                     UINT64_C(1000000) // pow(10, 5)
#define DEFAULT_DUST_THRESHOLD                          UINT64_C(1000000) // pow(10, 5)
#define EMISSION_SPEED_FACTOR 			        20

#define DIFFICULTY_TARGET                               120 // LWMA-2
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60 * 60 * 2
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_v0           3 * DIFFICULTY_TARGET  //LWMA
#define EXPECTED_NUMBER_OF_BLOCKS_PER_DAY               24 * 60 * 60 / DIFFICULTY_TARGET
#define DIFFICULTY_WINDOW                               EXPECTED_NUMBER_OF_BLOCKS_PER_DAY // blocks
#define DIFFICULTY_WINDOW_v0                            17  // blocks
#define DIFFICULTY_WINDOW_v1                            60 + 1  // blocks
#define DIFFICULTY_CUT                                  30  // timestamps to cut after sorting

#define DEPOSIT_MIN_AMOUNT                              1000000 * COIN
#define DEPOSIT_MIN_TERM                                22000 // ~1 month [this block of 1 mo]
#define DEPOSIT_MAX_TERM                                1 * 12 * 22000 // ~1 year
#define DEPOSIT_MIN_TOTAL_RATE_FACTOR                   0 // rate is constant
#define DEPOSIT_MAX_TOTAL_RATE                          31 // Apr % per year

#define MULTIPLIER_FACTOR                                             15 // early depositor multiplier
#define END_MULTIPLIER_BLOCK                                          25000 // block at which the multiplier ceases to be applied

#define MAX_BLOCK_SIZE_INITIAL                          1000000
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR           100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR         365 * 24 * 60 * 60 / DIFFICULTY_TARGET

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS      DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS

#define CRYPTONOTE_MAX_TX_SIZE_LIMIT                    (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                                (60 * 60 * 14) // seconds, 14 hours
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME                 (60 * 60 * 24) // seconds, one day
#define CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL   7 // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

#define FUSION_TX_MAX_SIZE                              CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100
#define FUSION_TX_MIN_INPUT_COUNT                       12
#define FUSION_TX_MIN_IN_OUT_COUNT_RATIO                4

#define UPGRADE_HEIGHT_v0                               136212
#define UPGRADE_HEIGHT_v1                               317950
#define UPGRADE_HEIGHT_v2                               338000
#define UPGRADE_HEIGHT_v3                               668946  //June 25 12AM UTC
#define UPGRADE_VOTING_THRESHOLD                        90 // percent
#define UPGRADE_VOTING_WINDOW                           EXPECTED_NUMBER_OF_BLOCKS_PER_DAY // blocks
#define UPGRADE_WINDOW                                  EXPECTED_NUMBER_OF_BLOCKS_PER_DAY // blocks

#define CRYPTONOTE_BLOCKS_FILENAME                      "blocks.dat"
#define CRYPTONOTE_BLOCKINDEXES_FILENAME                "blockindexes.dat"
#define CRYPTONOTE_BLOCKSCACHE_FILENAME                 "blockscache.dat"
#define CRYPTONOTE_POOLDATA_FILENAME                    "poolstate.bin"
#define P2P_NET_DATA_FILENAME                           "p2pstate.bin"
#define CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME          "blockchainindices.dat"
#define MINER_CONFIG_FILE_NAME                          "miner_conf.json"

} // parameters

#define CRYPTONOTE_NAME "brominer"
#define GENESIS_COINBASE_TX_HEX                       "010a01ff0001ade5f888ea05029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121019a374d00ffe1018ff4d035bc7a3f5f30e20c979226f1c91b828d329a39aa1223"

#define GENESIS_NONCE                                   70
#define GENESIS_TIMESTAMP                               1529201466

#define CURRENT_TRANSACTION_VERSION                     1
#define CURRENT_BLOCK_MAJOR                             1 //if put current 2 then next is 3 and soon....
#define NEXT_BLOCK_MAJOR_LIMIT                          5 //this Maximum layer block
#define BLOCK_MINOR_VERSION_0                           0
#define BLOCK_MINOR_VERSION_1                           1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000 // by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              128 // by default, blocks count in blocks downloading
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_DEFAULT_PORT                             			2793
#define RPC_DEFAULT_PORT		                                2794

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE            64 * 1024 * 1024 // 64 MB
#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60 // seconds
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000 // 50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000 // 5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000 // 2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60 * 2 * 1000 // 2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000 // 5 seconds
#define P2P_STAT_TRUSTED_PUB_KEY                        "FF9507CA55455F37A3B783EE2C5123B8B6A34A0C5CAAE050922C6254161480C1"

const std::initializer_list<const char*> SEED_NODES = {
  "35.204.21.243:2793",
  "5.206.195.104:2793",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  {10000,	"469d59599a69f582a151d941548f6534c4f72db73b548d28058b4fa038348dd9" },
  {20000,	"9c7d564d73f0060caba205a125dd591041974fd2a8829a77bdf17d25ff48a261" },
  {21000,	"be16a6bda1487b94ea12decd5dac1c708f8cd0505769064074dff9181f936fc0" },
  {22000,	"6a15bfdd7bc5fce1c05167ebffce9fc51f5ed084b417aa47038d869bf1a6185a" },
  {23000,	"eed82e63b7199f6014441007e694ba1aba1fd4ddf2541fd9c61e971a51aab1c7" },
  {24000,	"5f0533b44a39469965d60563688d6793890a4bd2162902c80f9f3a3779a0f7bb" },
  {25000,	"87e1b1ad7fe3d8951468c86bc9abb99b8df51b442bb55bf80b523922c5c95188" },
  {26000,	"49f557d0b1069f2d4515fc7f3ca65166a85bbb3ef36245d065a3e914d7a05e8a" },
  {27000,	"2c7958f7afa8229719367eb0b32ec6f19ea9d10f4f9ac2dd98fe9b4e86764242" },
};

const std::map<const uint32_t, const uint8_t> Version = {
	// {BlockIndex , Version}
	{ 2500000, 1 }
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS


