#ifndef HEADER_BF
#define HEADER_BF

#include "disk_manager.h"
#include "block.h"
#include "lru_k_replacer.h"
#include <unordered_map>
#include <list>
#include <mutex>
#include <utility>
#include <memory>

namespace riverrain{
    class MemoryManager{
            public:
                MemoryManager(size_t pool_size_bytes, DiskManager * disk_manager);
               ~ MemoryManager();
               Block *blocks_;
               auto FetchBlock(block_id_t b_id) -> Block *;
               auto FlushBlock(block_id_t b_id) -> bool; 
               private:
                
                std::unordered_map<block_id_t, frame_id_t> block_table_;
                std::list<frame_id_t> free_list_;
                const size_t mem_pool_size_;
                DiskManager *disk_manager_;
                std::mutex latch_;
                std::unique_ptr<LRUKReplacer> replacer_;
                // this is for memory alignment req for direc io
                Block* allocate(size_t pz);


    };
}

#endif